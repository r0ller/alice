#include "morphan.h"
#include "morphan_result.h"

morphan *morphan::singleton_instance=NULL;

morphan::morphan(const std::string& lid){
	db *sqlite=NULL;
	std::string fstname;
	query_result *fsts=NULL;
	unsigned int fstname_length=0;

	sqlite=db_factory::get_instance();
	fsts=sqlite->exec_sql("SELECT FST FROM LANGUAGES WHERE LID = '"+lid+"';");
	if(fsts==NULL){
		//TODO: throw exception
		exit(EXIT_FAILURE);
	}
	fstname=*fsts->field_value_at_row_position(0,"fst");
	#ifdef __ANDROID__
		__android_log_print(ANDROID_LOG_INFO, "hi", "fst used: %s", fstname.c_str());
		fstname="/data/data/hi.pkg/"+fstname;//TODO: get cwd on android
	#endif
	fstname_length=fstname.length();
	pfstname=new char[fstname_length+1];
	fstname_length=fstname.copy(pfstname,fstname_length+1);
	pfstname[fstname_length]='\0';
	morphan::fst=fsm_read_binary_file(pfstname);
	if(morphan::fst==NULL){
		#ifdef __ANDROID__
			__android_log_print(ANDROID_LOG_INFO, "hi", "failed to read binary fst %s",pfstname);
		#endif
		//TODO: throw exception
		exit(EXIT_FAILURE);
	}
	morphan::morphan_handle=apply_init(morphan::fst);
	if(morphan::morphan_handle==NULL){
		#ifdef __ANDROID__
			__android_log_print(ANDROID_LOG_INFO, "hi", "fst apply_init failed");
		#endif
		//TODO: throw exception
		exit(EXIT_FAILURE);
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
	std::string morphemes;
	morphan_result *analysis=NULL;
	std::vector<morphan_result> *analyses=NULL;

//	std::cout<<"analyzing word "<<word<<std::endl;
	#ifdef __ANDROID__
		__android_log_print(ANDROID_LOG_INFO, "hi", "analyzing word %s", word.c_str());
	#endif
	c_word.assign(word.begin(),word.end());
	c_word.push_back('\0');
	result=apply_up(morphan::morphan_handle, &c_word[0]);
//	std::cout<<"result:"<<result<<std::endl;
	if(result!=NULL) analyses=new std::vector<morphan_result>();
	while(result!=NULL){//result==NULL means that it cannot be analyzed -> treat it as constant. However, one thing TODO is:
		//think over, what should happen the other way around i.e. when a constant appears which can be analysed???
		morphemes=std::string((const char *)result);
		separator_position=morphemes.find('+');
		while(separator_position!=std::string::npos){
			length=separator_position-start_position;
			if(length>0){
				morphemes_vector.push_back(morphemes.substr(start_position,length));
				start_position=separator_position+1;
			}
			separator_position=morphemes.find('+',start_position);
		}
		morphemes_vector.push_back(morphemes.substr(start_position,std::string::npos));
		analysis=new morphan_result(word,morphemes_vector);
		analyses->push_back(*analysis);
		morphemes_vector.clear();
		start_position=0;
		result=apply_up(morphan::morphan_handle, NULL);
	}
	return analyses;
}
