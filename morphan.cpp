#include "morphan.h"
#include "morphan_result.h"

morphan *morphan::singleton_instance=NULL;
std::map<std::pair<std::string,std::string>,std::vector<morphan_result>* > morphan::cache;

morphan::morphan(const std::string& lid){
	db *sqlite=NULL;
	std::string fstname;
	query_result *fsts=NULL;
	unsigned int fstname_length=0;

	this->lid=lid;
	sqlite=db_factory::get_instance();
	fsts=sqlite->exec_sql("SELECT FST FROM LANGUAGES WHERE LID = '"+lid+"';");
	if(fsts==NULL){
		throw std::runtime_error("No entry found for language id "+lid+" in LANGUAGES db table.");
	}
	fstname=*fsts->field_value_at_row_position(0,"fst");
	#ifdef __ANDROID__
		__android_log_print(ANDROID_LOG_INFO, "hi", "fst used: %s", fstname.c_str());
		fstname="/data/data/com.bitroller.hi/"+fstname;//TODO: get cwd on android
	#elif defined(__EMSCRIPTEN__) && FS==NODEJS
		fstname="/virtual/"+fstname;
	#endif
	fstname_length=fstname.length();
	pfstname=new char[fstname_length+1];
	fstname_length=fstname.copy(pfstname,fstname_length+1);
	pfstname[fstname_length]='\0';
	//std::cout<<"opening fst: "<<fstname<<std::endl;
	morphan::fst=fsm_read_binary_file(pfstname);
	if(morphan::fst==NULL){
		#ifdef __ANDROID__
			__android_log_print(ANDROID_LOG_INFO, "hi", "failed to read binary fst %s",pfstname);
		#endif
		throw std::runtime_error("Failed to read binary fst "+fstname);
	}
	morphan::morphan_handle=apply_init(morphan::fst);
	if(morphan::morphan_handle==NULL){
		#ifdef __ANDROID__
			__android_log_print(ANDROID_LOG_INFO, "hi", "fst apply_init failed");
		#endif
		throw std::runtime_error("Fst initialization failed for "+fstname);
	}
	delete fsts;
	#ifdef __ANDROID__
		__android_log_print(ANDROID_LOG_INFO, "hi", "stemmer started");
	#endif
}

morphan::~morphan(){
	apply_clear(morphan::morphan_handle);
	fsm_destroy(morphan::fst);
	morphan::singleton_instance=NULL;
	if(pfstname!=NULL) delete []pfstname;
}

std::vector<morphan_result> *morphan::analyze(const std::string& word){
	char *result=NULL;
	std::vector<char> c_word;
	std::vector<std::string> morphemes_vector;
	size_t separator_position=0, length=0, start_position=0;
	std::string morphemes,con_morphemes;
	morphan_result *analysis=NULL, *con_morphan=NULL;
	std::vector<morphan_result> *analyses=NULL;

	std::cout<<"analyzing word "<<word<<std::endl;
	#ifdef __ANDROID__
		__android_log_print(ANDROID_LOG_INFO, "hi", "analyzing word %s", word.c_str());
	#endif
	auto cache_hit=morphan::cache.find(std::make_pair(lid,word));
	if(cache_hit!=cache.end()){
		analyses=cache_hit->second;
	}
	else{
		c_word.assign(word.begin(),word.end());
		c_word.push_back('\0');
		result=apply_up(morphan::morphan_handle, &c_word[0]);
		if(result!=NULL) analyses=new std::vector<morphan_result>();
		while(result!=NULL){//result==NULL means that it cannot be analyzed -> treat it as constant. However, one thing TODO is:
			//think over, what should happen the other way around i.e. when a constant appears which can be analysed???
			morphemes=std::string((const char *)result);
	//		logger::singleton()->log(0,"morphan:"+morphemes);
			separator_position=morphemes.find('+');
			while(separator_position!=std::string::npos){
				length=separator_position-start_position;
				if(morphemes[start_position]!='+'&&length>0||morphemes[start_position]=='+'&&length>1){
					morphemes_vector.push_back(morphemes.substr(start_position,length));
	//				logger::singleton()->log(0,"morpheme:"+morphemes_vector.back());
				}
				start_position=separator_position+1;
				separator_position=morphemes.find('+',start_position);
			}
			morphemes_vector.push_back(morphemes.substr(start_position,std::string::npos));
	//		logger::singleton()->log(0,"morpheme:"+morphemes_vector.back());
			analysis=new morphan_result(word,morphemes_vector);
			if(analysis->is_erroneous()==false){
				if(analysis->gcat()=="CON"){
					//quick fix for having >1 meaningful interpretation by putting analysis for a constant at the end
					//TODO: implement evaluation of multiple interpretations in hi() which would make the sequence irrelevant
					con_morphan=analysis;
					con_morphemes=morphemes;
				}
				else{
					logger::singleton()->log(0,"morphan pushed:"+morphemes);
					analyses->push_back(*analysis);
				}
			}
			else{
	//			logger::singleton()->log(0,"dropping this morphan");
				delete analysis;
			}
			morphemes_vector.clear();
			start_position=0;
			result=apply_up(morphan::morphan_handle, NULL);
		}
		if(con_morphan!=NULL){
			logger::singleton()->log(0,"morphan pushed:"+con_morphemes);
			analyses->push_back(*con_morphan);
		}
		morphan::cache.insert(std::make_pair(std::make_pair(lid,word),analyses));
	}
	return analyses;
}
