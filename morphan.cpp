#include "logger.h"
#include "morphan.h"
#include "morphan_result.h"
#include "query_result.h"
#include "db_factory.h"

morphan *morphan::singleton_instance=NULL;

morphan::morphan(const std::string& lid){
	db *sqlite=NULL;
	std::string fstname;
	query_result *fsts=NULL;
	unsigned int fstname_length=0;

	lid_=lid;
	sqlite=db_factory::get_instance();
	fsts=sqlite->exec_sql("SELECT FST FROM LANGUAGES WHERE LID = '"+lid+"';");
	if(fsts==NULL){
		throw std::runtime_error("No entry found for language id "+lid+" in LANGUAGES db table.");
	}
	fstname=*fsts->field_value_at_row_position(0,"fst");
	#if defined(__EMSCRIPTEN__) && FS==NODEJS
		fstname="/virtual/"+fstname;
	#else
		std::string path;
		std::string db_uri=sqlite->db_uri();
		auto path_end=db_uri.find_last_of('/');
		if(path_end!=std::string::npos)	path=db_uri.substr(0,path_end+1);//path_end+1 is ok as db already used db_uri as filename
		fstname=path+fstname;
	#endif
	logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"opening fst: "+fstname);
	fstname_length=fstname.length();
	pfstname=new char[fstname_length+1];
	fstname_length=fstname.copy(pfstname,fstname_length+1);
	pfstname[fstname_length]='\0';
	morphan::fst=fsm_read_binary_file(pfstname);
	if(morphan::fst==NULL){
		logger::singleton()==NULL?(void)0:logger::singleton()->log(2,"failed to read binary fst "+fstname);
		throw std::runtime_error("Failed to read binary fst "+fstname);
	}
	morphan::morphan_handle=apply_init(morphan::fst);
	if(morphan::morphan_handle==NULL){
		logger::singleton()==NULL?(void)0:logger::singleton()->log(2,"fst apply_init failed");
		throw std::runtime_error("Fst initialization failed for "+fstname);
	}
	delete fsts;
	logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"stemmer started");
}

morphan::~morphan(){
    logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"destructing morphan");
    apply_clear(morphan::morphan_handle);
	fsm_destroy(morphan::fst);
	morphan::singleton_instance=NULL;
	if(pfstname!=NULL) delete []pfstname;
}

std::vector<morphan_result> *morphan::analyze(const std::string& word,const bool with_cons){
	char *result=NULL;
	std::vector<char> c_word;
	std::vector<std::string> morphemes_vector;
	size_t separator_position=0, length=0, start_position=0;
	std::string morphemes;
	morphan_result *analysis=NULL;
	std::vector<morphan_result> *analyses=NULL,cons;

	logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"analyzing word "+word);
	c_word.assign(word.begin(),word.end());
	c_word.push_back('\0');
	analyses=new std::vector<morphan_result>();
	result=apply_up(morphan::morphan_handle, &c_word[0]);
	if(result!=NULL){
		while(result!=NULL){//result==NULL means that it cannot be analyzed -> treat it as constant. However, one thing left as
			//TODO: think over, what should happen the other way around i.e. when a constant appears which can be analysed???
			morphemes=std::string((const char *)result);
			logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"morphan:"+morphemes);
			separator_position=morphemes.find('+');
			while(separator_position!=std::string::npos){
				length=separator_position-start_position;
				if(morphemes[start_position]!='+'&&length>0||morphemes[start_position]=='+'&&length>1){
					morphemes_vector.push_back(morphemes.substr(start_position,length));
					logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"morpheme:"+morphemes_vector.back());
				}
				start_position=separator_position+1;
				separator_position=morphemes.find('+',start_position);
			}
			morphemes_vector.push_back(morphemes.substr(start_position,std::string::npos));//This will throw if no substr can be returned
			if(morphemes_vector.empty()==true) throw morphan_error();
			logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"morpheme:"+morphemes_vector.back());
			analysis=new morphan_result(word,morphemes_vector,lid_);
			if(analysis->is_erroneous()==false){
				if(with_cons==true){
					logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"morphan pushed:"+morphemes);
					analyses->push_back(*analysis);
				}
				else if(analysis->gcat()=="CON"&&with_cons==false){
					cons.push_back(*analysis);
				}
			}
			else{
				logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"dropping this morphan");
				delete analysis;
			}
			morphemes_vector.clear();
			start_position=0;
			result=apply_up(morphan::morphan_handle, NULL);
		}
		if(with_cons==false&&analyses->empty()==true){//Add only cons if no other analysis is found
			for(auto&& con:cons){
				analyses->push_back(con);
			}
			logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"cons pushed");
		}
	}
	else{
        analysis=new morphan_result(word,lid_,"");
		if(analysis->is_erroneous()==false){
			logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"morphan pushed without analysis");
			analyses->push_back(*analysis);
		}
		else{
			logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"dropping this morphan");
			delete analysis;
		}
	}
	return analyses;
}

std::string morphan::lid(){
	return lid_;
}

std::vector<std::string> morphan::generate(const std::string& analysis){
	char *result=NULL;
	std::vector<char> c_analysis;
	std::vector<std::string> words;

	logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"generating word form for "+analysis);
	c_analysis.assign(analysis.begin(),analysis.end());
	c_analysis.push_back('\0');
	result=apply_down(morphan::morphan_handle, &c_analysis[0]);
	while(result!=NULL){
		words.push_back(std::string((const char *)result));
		result=apply_down(morphan::morphan_handle, NULL);
	}
	return words;
}
