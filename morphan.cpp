#include "morphan.h"
#include "morphan_result.h"

morphan *morphan::singleton_instance=NULL;

morphan::morphan(){
	//TODO: Instead of hardcoding, check how to load a morphan for the current language
	#ifdef __ANDROID__
		morphan::fst=fsm_read_binary_file("/data/data/hi.pkg/english.fst");//TODO: get cwd on android
	#else
		morphan::fst=fsm_read_binary_file("english.fst");
	#endif
	if(morphan::fst == NULL){
		//TODO: throw exception
		exit(EXIT_FAILURE);
	}
	morphan::morphan_handle=apply_init(morphan::fst);
	if(morphan::morphan_handle == NULL){
		//TODO: throw exception
		exit(EXIT_FAILURE);
	}
}

morphan::~morphan(){
	apply_clear(morphan::morphan_handle);
	fsm_destroy(morphan::fst);
	morphan::singleton_instance=NULL;
}

morphan_result *morphan::analyze(const std::string& word){
	char *result=NULL;
	std::vector<char> c_word;
	std::vector<std::string> morphemes_vector;
	unsigned int separator_position=0, length, start_position=0;
	std::string morphemes;
	morphan_result *analysis=NULL;

//	std::cout<<"analyzing word "<<word<<std::endl;
	c_word.assign(word.begin(),word.end());
	c_word.push_back('\0');
	result=apply_up(morphan::morphan_handle, &c_word[0]);
	if(result!=NULL){//result==NULL means that it cannot be analyzed -> treat it as constant. However, one thing TODO is:
		//think over, what should happen the other way around i.e. when a constant appears which can be analysed???
		morphemes=std::string((const char *)result);
		result=apply_up(morphan::morphan_handle, NULL);
		if(result!=NULL){//TODO: this means that there are >1 possible analyses for the same word form! Think over if rollback can be done in yyerror()
			//and a new syntactic analysis carried out for the other result of the morphological analysis.
			//TODO: throw exception
			exit(EXIT_FAILURE);
		}
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
	}
	return analysis;
}
