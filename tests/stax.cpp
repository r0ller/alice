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
	std::string db_file, path, base, lid, stex_file, words, gcats, terminal, feature, gcat, stexline, word, combine="any";
	std::map<std::string,std::pair<std::string,std::string> > terminals_gcat_feature;
	std::multimap<std::string,std::string> gcats_words;
	std::set<std::string> gcat_set,word_set;
	unsigned int result_size;
	morphan *stemmer=NULL;
	std::map<std::string,std::vector<morphan_result> > word_analyses;

	if(argc<2){
		//TODO:add new option to filter combinations of terminal symbols: ANY or ALL (extra: ANY only once, ALL only once)
		std::cerr<<"Usage: stax /path/to/stex_output_file"<<std::endl;
		exit(EXIT_FAILURE);
	}
	else{
		stex_file=argv[1];
		unsigned int line_counter=0;
		std::ifstream filestream(stex_file);
		if(filestream.is_open()==false){
			std::cerr<<"Error opening file "<<argv[2]<<std::endl;
			exit(EXIT_FAILURE);
		}
		while(std::getline(filestream,stexline)){
			switch(line_counter){
				case 0: db_file=stexline;
						++line_counter;
						break;
				case 1: lid=stexline;
						++line_counter;
						break;
				case 2: words=stexline;
						++line_counter;
						break;
			}
			if(db_file.empty()==false&&lid.empty()==false&&words.empty()==false) break;
		}
		filestream.close();
		if(db_file.empty()==true||lid.empty()==true||words.empty()==true) exit(EXIT_FAILURE);
		if(db_file.empty()==true) exit(EXIT_FAILURE);
		else{
			std::size_t base_end=db_file.find_last_of("/");
			if(base_end==std::string::npos) exit(EXIT_FAILURE);
			path=db_file.substr(0,base_end);
			std::size_t base_start=path.find_last_of("/");
			base=path.substr(base_start+1);
			if(path.empty()==true||base.empty()==true) exit(EXIT_FAILURE);
		}
		if(words.empty()==false){
			std::string::size_type comma_pos=words.find(',',0);
			if(comma_pos!=std::string::npos){
				std::string::size_type start_pos=0;
				while(comma_pos!=std::string::npos){
					std::string word_cut=words.substr(start_pos,comma_pos-start_pos);
					if(word_cut.empty()==false) word_set.insert(word_cut);
					words.replace(comma_pos,1,"','");
					start_pos=comma_pos+3;
					comma_pos=words.find(',',start_pos);
					if(comma_pos==std::string::npos){
						std::string word_cut=words.substr(start_pos,words.length()-start_pos);
						if(word_cut.empty()==false) word_set.insert(word_cut);
					}
				}
			}
			else{
				word_set.insert(words);
			}
		}
		else{
			exit(EXIT_FAILURE);
		}
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
	for(auto&& i:word_set){
		std::vector<morphan_result> *word_analysis=stemmer->analyze(i);
		word_analyses.insert(std::make_pair(i,*word_analysis));
		for(auto&& j:*word_analysis){
			gcat_set.insert(j.gcat());
			if(gcats.find("'"+j.gcat()+"'")==std::string::npos) gcats+="'"+j.gcat()+"',";
			gcats_words.insert(std::make_pair(j.gcat(),i));
		}
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
		if(gcat=="CON"){
			terminal="t_Con";
		}
		else{
			if(feature.empty()==false){
				terminal="t_"+lid+"_"+gcat+"_"+feature;
			}
			else{
				terminal="t_"+lid+"_"+gcat;
			}
		}
//		std::cout<<"generating terminal symbol:"<<terminal<<std::endl;
		terminals_gcat_feature.insert(std::make_pair(terminal,std::make_pair(gcat,feature)));
	}
	std::ifstream filestream(stex_file);
	if(filestream.is_open()==false){
		std::cerr<<"Error opening file "<<argv[2]<<std::endl;
		exit(EXIT_FAILURE);
	}
	bool header_read=false;
	while(std::getline(filestream,stexline)){
		if(header_read==false){
			if(stexline=="stex output:") header_read=true;
			continue;
		}
		std::stringstream splitstream(stexline);
		std::vector<std::pair<std::string,std::vector<std::string> > > gcat_feature_queries;
		std::vector<std::string> features;
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
					features.clear();
					features.push_back("[stem]");
				}
				else{
					features.push_back(terminal_gcat_feature->second.second);
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
		if(combine=="any"){
			//nothing to check, any combination of symbols is allowed
		}
		else if(combine=="each"){
			//check if one terminal symbol per word in word_analyses appears in gcat_feature_queries as well
		}
		else exit(EXIT_FAILURE);
		if(gcat_feature_queries.empty()==false){
			std::vector<std::vector<std::string> > generated_sentences;
			for(auto&& i:gcat_feature_queries){
				std::vector<std::string> generated_words;
				for(auto&& j=gcats_words.lower_bound(i.first);j!=gcats_words.upper_bound(i.first);++j){
					auto word_analysis=word_analyses.find(j->second);
					for(auto&& k:word_analysis->second){
						if(k.gcat()==i.first){
							if(k.gcat()=="CON"){
								std::cout<<"constant/concealed:"<<k.word()<<std::endl;
								generated_words.push_back(k.word());
							}
							else{
								std::string analysis;
								for(auto&& feature_requested:i.second){
									if(analysis.empty()==true){
										analysis=k.stem()+feature_requested+"+"+k.gcat()+"+";
									}
									else analysis+=feature_requested+"+";
								}
								analysis.pop_back();
								word=stemmer->generate(analysis);
								std::cout<<analysis<<":"<<word<<std::endl;
								if(word.empty()==false){
									generated_words.push_back(word);
								}
//								Attempting to generate wordform in cases where not all morphemes of the morphological
//								analysis of a word were used in the syntax as tokens. The commented part below is not
//								capabale of doing that and it may not make even sense to do that as the morphemes
//								that were not used in the grammar are unknown to the program logic and as a result
//								such wordforms may be generated that significantly differ from the wordform expected.
//								unsigned int match_count=0;
//								for(auto&& feature_requested:i.second){
//									if(feature_requested=="[stem]"){
//										if(k.stem().empty()==false) ++match_count;
//									}
//									else{
//										if(k.has_feature(feature_requested)==true) ++match_count;
//									}
//								}
//								if(match_count==i.second.size()&&match_count==k.lfeas().size()+1){
//									std::string analysis;
//									for(auto&& l:k.morphemes()){
//										if(l.find("[stem]")!=std::string::npos){
//											if(analysis.empty()==true){
//												analysis=k.stem()+"[stem]";
//											}
//											else{
//												analysis+="+"+k.stem()+"[stem]";
//											}
//										}
//										else{
//											analysis+="+"+l;
//										}
//									}
//									word=stemmer->generate(analysis);
//									std::cout<<analysis<<":"<<word<<std::endl;
//									if(word.empty()==false){
//										generated_words.push_back(word);
//									}
//								}
							}
						}
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
			std::cout<<stexline<<":"<<std::endl;
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
				if(word_position_covered>0) std::cout<<std::endl;
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
