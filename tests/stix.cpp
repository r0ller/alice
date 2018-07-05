#include <iostream>
#include <fstream>
#include <sstream>
#include "logger.cpp"
#include "db.h"
#include "query_result.cpp"
#include "morphan_result.cpp"
#include "morphan.cpp"

int main(int argc, char* argv[]){

	db *sqlite=NULL;
	query_result *lexicon=NULL,*gcats_features=NULL;
	std::string db_file, path, base, lid, stax, words, gcats, terminal, feature, gcat, staxline, word, analysis;
	std::map<std::string,std::pair<std::string,std::string> > terminals_gcat_feature;
	std::multimap<std::string,std::string> gcats_words;
	std::set<std::string> gcat_set;
	unsigned int result_size;
	morphan *stemmer=NULL;
	std::map<std::string,std::vector<morphan_result> > word_analyses;

	if(argc<5){
		std::cerr<<"Usage: stix /path/to/dbfile.db /path/to/stax_output_file list,of,words <language id>"<<std::endl;
		exit(EXIT_FAILURE);
	}
	else{
		db_file=argv[1];
		if(db_file.empty()==true) exit(EXIT_FAILURE);
		else{
			std::size_t base_end=db_file.find_last_of("/");
			if(base_end==std::string::npos) exit(EXIT_FAILURE);
			path=db_file.substr(0,base_end);
			std::size_t base_start=path.find_last_of("/");
			base=path.substr(base_start+1);
			if(path.empty()==true||base.empty()==true) exit(EXIT_FAILURE);
		}
		words=argv[3];
		std::string::size_type comma_pos=words.find(',',0);
		while(comma_pos!=std::string::npos){
			words.replace(comma_pos,1,"','");
			comma_pos=words.find(',',comma_pos+3);
		}
		lid=argv[4];
	}
	logger::singleton("console",0,"LE");
	sqlite=db_factory::get_instance();
	sqlite->open(db_file);
	lexicon=sqlite->exec_sql("SELECT WORD, GCAT FROM LEXICON WHERE LID = '"+lid+"' AND WORD IN ('"+words+"');");
	if(lexicon==NULL){
		std::cerr<<"Words not found in lexicon db table."<<std::endl;
		exit(EXIT_FAILURE);
	}
	result_size=lexicon->nr_of_result_rows();
	stemmer=morphan::get_instance(lid);
	for(unsigned int i=0;i<result_size;++i){
		gcat=*lexicon->field_value_at_row_position(i,"gcat");
		if(gcat_set.find(gcat)==gcat_set.end()){
			gcats+="'"+gcat+"',";
			gcat_set.insert(gcat);
		}
		word=*lexicon->field_value_at_row_position(i,"word");
//		std::cout<<"word found in lexicon:"<<word<<std::endl;
		gcats_words.insert(std::make_pair(gcat,word));
		std::vector<morphan_result> *word_analysis=stemmer->analyze(word);
		word_analyses.insert(std::make_pair(word,*word_analysis));
	}
	gcats.pop_back();
	gcats_features=sqlite->exec_sql("SELECT GCAT, FEATURE FROM GCAT WHERE LID = '"+lid+"' AND GCAT IN ("+gcats+");");
	if(gcats_features==NULL){
		std::cerr<<"No gcats found for words in gcats db table."<<std::endl;
		exit(EXIT_FAILURE);
	}
	result_size=gcats_features->nr_of_result_rows();
	for(unsigned int i=0;i<result_size;++i){
		gcat=*gcats_features->field_value_at_row_position(i,"gcat");
		feature=*gcats_features->field_value_at_row_position(i,"feature");
		if(feature.empty()==false){
			terminal="t_"+lid+"_"+gcat+"_"+feature;
		}
		else{
			terminal="t_"+lid+"_"+gcat;
		}
//		std::cout<<"generating terminal symbol:"<<terminal<<std::endl;
		terminals_gcat_feature.insert(std::make_pair(terminal,std::make_pair(gcat,feature)));
	}
	std::ifstream filestream(argv[2]);
	if(filestream.is_open()==false){
		std::cerr<<"Error opening file "<<argv[2]<<std::endl;
		exit(EXIT_FAILURE);
	}
	while(std::getline(filestream,staxline)){
		std::stringstream splitstream(staxline);
		std::vector<std::pair<std::string,std::string> > gcat_feature_queries;
		std::string features;
		while(std::getline(splitstream,terminal,' ')){
			auto&& terminal_gcat_feature=terminals_gcat_feature.find(terminal);
			if(terminal_gcat_feature!=terminals_gcat_feature.end()){
//				std::cout<<"terminal:"<<terminal<<std::endl;
				std::string feature_tolower=terminal_gcat_feature->second.second;
//				std::cout<<"feature:"<<feature_lcase<<std::endl;
				if(feature_tolower.empty()==false){
					std::transform(feature_tolower.begin(),feature_tolower.end(),feature_tolower.begin(),[](unsigned char c) -> unsigned char { return std::tolower(c); });
				}
				if(feature_tolower.empty()==true||feature_tolower=="stem"){
					if(features.empty()==false){
						gcat_feature_queries.push_back(std::make_pair(gcat,features));
					}
					gcat=terminal_gcat_feature->second.first;
					features="[stem]+"+gcat;
				}
				else{
					features+="+"+terminal_gcat_feature->second.second;
				}
			}
			else{
				gcat_feature_queries.clear();
				features.clear();
				break;
			}
		}
		if(features.empty()==false){
			gcat_feature_queries.push_back(std::make_pair(gcat,features));
		}
		if(gcat_feature_queries.empty()==false){
			std::vector<std::vector<std::string> > generated_sentences;
			for(auto&& i:gcat_feature_queries){
				std::vector<std::string> generated_words;
				for(auto&& j=gcats_words.lower_bound(i.first);j!=gcats_words.upper_bound(i.first);++j){
					auto word_analysis=word_analyses.find(j->second);
					for(auto&& k:word_analysis->second){
						if(k.gcat()==i.first){
							analysis=k.stem()+i.second;
							break;
						}
					}
					word=stemmer->generate(analysis);
//					std::cout<<analysis<<":"<<word<<std::endl;
					if(word.empty()==false){
						generated_words.push_back(word);
					}
				}
				if(generated_words.empty()==false){
					generated_sentences.push_back(generated_words);
				}
				else{//no word form could be generated for this word position->stop: no sentence can be generated either
					generated_sentences.clear();
					break;
				}
			}
//			std::cout<<staxline<<":"<<std::endl;
			if(generated_sentences.empty()==false){
				//printing generated sentences
				std::vector<unsigned int> word_dimensions;
				for(unsigned int i=0;i<generated_sentences.size();++i){
					word_dimensions.push_back(generated_sentences.at(i).size());
//					std::cout<<"word position "<<i<<" has "<<generated_sentences.at(i).size()<<" word forms"<<std::endl;
				}
//				std::cout<<"word_dimensions size:"<<word_dimensions.size()<<std::endl;
				unsigned int word_position_covered=0;
				while(word_position_covered<word_dimensions.size()){
//					std::cout<<"word_position_covered:"<<word_position_covered<<std::endl;
					std::string sentence;
					for(unsigned int i=0;i<word_dimensions.size();++i){
//						std::cout<<"reading word position "<<i<<" with word form at place "<<word_dimensions.at(i)-1<<std::endl;
						sentence+=generated_sentences.at(i).at(word_dimensions.at(i)-1)+" ";
						if(word_position_covered==i){
							if(word_dimensions.at(i)>1){
								word_dimensions.at(i)=word_dimensions.at(i)-1;
							}
							else{
								word_dimensions.at(i)=generated_sentences.at(i).size();
								++word_position_covered;
							}
						}
					}
					sentence.pop_back();
					std::cout<<sentence<<std::endl;
				}
			}
		}
	}
	filestream.close();
	delete stemmer;
	sqlite->close();
	db_factory::delete_instance();
	sqlite=NULL;
	return 0;
}
