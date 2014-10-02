#include "morphan_result.h"

/*PUBLIC*/
morphan_result::morphan_result(const std::string& word, const std::vector<std::string>& morphemes){
	unsigned int nr_of_morphemes=0,i,hit=0;
	std::string morpheme;

	word_form=word;
	word_morphemes=new std::vector<std::string>(morphemes);
	nr_of_morphemes=morphemes.size();
	for(i=0;i<nr_of_morphemes;++i){
		if(word_gcat.empty()==true){
			hit=morphemes[i].find("[gcat]");
			if(hit!=std::string::npos){
				word_gcat=morphemes[i].substr(0,hit-1);//the algorithm is based on the assumption that [...] tags are added as suffixes
			}
		}
		else if(word_gcat.empty()==false&&morphemes[i].find("[gcat]")!=std::string::npos){
			//TODO: throw exception
			exit(EXIT_FAILURE);
		}
		if(word_stem.empty()==true){
			hit=morphemes[i].find("[stem]");
			if(hit!=std::string::npos){
				word_stem=morphemes[i].substr(0,hit-1);//the algorithm is based on the assumption that [...] tags are added as suffixes
			}
		}
		else if(word_stem.empty()==false&&morphemes[i].find("[stem]")!=std::string::npos){
			//TODO: throw exception
			exit(EXIT_FAILURE);
		}
	}
}

morphan_result::~morphan_result(){
}

const std::string& morphan_result::stem(){
	return word_stem;
}

const std::string& morphan_result::gcat(){
	return word_gcat;
}

const std::vector<std::string>& morphan_result::morphemes(){
	return word_morphemes;
}
