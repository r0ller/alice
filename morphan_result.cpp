#include "morphan_result.h"

/*PUBLIC*/
morphan_result::morphan_result(const std::string& word, const std::vector<std::string>& morphemes){
	unsigned int nr_of_morphemes=0,i,hit=0;
	std::string morpheme;
	bool tag_found=false;

	word_form=word;
	word_morphemes=morphemes;
	nr_of_morphemes=morphemes.size();
	for(i=0;i<nr_of_morphemes;++i){
		tag_found=false;
		if(word_gcat.empty()==true){
			hit=morphemes[i].find("[gcat]");
			if(hit!=std::string::npos){
				word_gcat=morphemes[i].substr(0,hit);//the algorithm is based on the assumption that [...] tags are added as suffixes
				tag_found=true;
			}
		}
		else if(word_gcat.empty()==false&&morphemes[i].find("[gcat]")!=std::string::npos){
			//TODO: throw exception
			exit(EXIT_FAILURE);
		}
		if(tag_found==false){
			if(word_stem.empty()==true){
				hit=morphemes[i].find("[stem]");
				if(hit!=std::string::npos){
					word_stem=morphemes[i].substr(0,hit);//the algorithm is based on the assumption that [...] tags are added as suffixes
					tag_found=true;
				}
			}
			else if(word_stem.empty()==false&&morphemes[i].find("[stem]")!=std::string::npos){
				//TODO: throw exception
				exit(EXIT_FAILURE);
			}
		}
		if(tag_found==false){
			hit=morphemes[i].find("[lfea]");
			if(hit!=std::string::npos){
				features.insert(morphemes[i].substr(0,hit));
				tag_found=true;
			}
		}
	}
}

morphan_result::~morphan_result(){
}

const std::string& morphan_result::stem() const{
	return word_stem;
}

const std::string& morphan_result::gcat() const{
	return word_gcat;
}

const std::vector<std::string>& morphan_result::morphemes() const{
	return word_morphemes;
}

bool morphan_result::has_feature(const std::string feature) const{
	return features.find(feature)==features.end()?false:true;
}

void morphan_result::add_feature(const std::string& feature){
	//TODO: verify feature in gcat db table to see if the feature belongs indeed to the gcat in question
	features.insert(feature);
}

const std::set<std::string>& morphan_result::lfeas() const{
	return features;
}
