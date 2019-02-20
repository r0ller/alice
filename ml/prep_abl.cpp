#include <iostream>
#include <fstream>
#include "logger.cpp"
#include "hilib.h"
#include "db.h"
#include "lexer.h"
#include "sp.h"
std::map<std::string,unsigned int> symbol_token_map;
std::map<unsigned int,std::string> token_symbol_map;
morphan *stemmer=NULL;
lexer *lex=NULL;
interpreter *sparser=NULL;
#include "tokenpaths.cpp"
tokenpaths *token_paths=NULL;
#include "query_result.cpp"
#include "morphan_result.cpp"
#include "morphan.cpp"
#include "lexer.cpp"
#include "sp.cpp"
#include "transgraph.cpp"

int main(int argc, char* argv[]){

	db *sqlite=NULL;
	//query_result *lexicon=NULL;
	std::string db_file,lid,corpus_file,output,sentence;
	int token=0;
	std::locale locale;
	std::ifstream *filestream=NULL;
	std::ofstream *output_file=NULL;
	std::multimap<unsigned int,std::tuple<unsigned int,std::vector<lexicon>,std::string> > token_paths_ranked_by_cons;

	logger::singleton("console",0,"LE");
	if(argc<5){
		std::cerr<<"Usage: prep_abl /path/to/dbfile.db /path/to/abl/training/corpus <language id> /path/to/output/file/name"<<std::endl;
		exit(EXIT_FAILURE);
	}
	db_file=argv[1];
	corpus_file=argv[2];
	lid=argv[3];
	output=argv[4];
	filestream=new std::ifstream(corpus_file);
	if(filestream==NULL){
		exit(EXIT_FAILURE);
	}
	sqlite=db_factory::get_instance();
	sqlite->open(db_file);
	output_file=new std::ofstream(output);
	while(std::getline(*filestream,sentence)){
		std::cout<<"analysing sentence:"<<std::endl<<sentence<<std::endl;
		token_paths=new tokenpaths;
		while(token_paths->is_any_left()==true){
			try{
				locale=std::locale();
				lex=new lexer(sentence.c_str(),lid.c_str(),locale,true);
				std::vector<lexicon> words;
				std::string symbols;
				unsigned int nr_of_symbols=0;
				while(lex->is_end_of_input()==false){
					token=lex->next_token();
					++nr_of_symbols;
					symbols+=token_symbol_map.find(token)->second;
					symbols+=" ";
				}
				if(symbols.back()==' ') symbols.pop_back();
				//std::cout<<symbols<<std::endl;
				words=lex->word_entries();
				unsigned int nr_of_cons=0;
				for(auto&& word:words){
					if(word.gcat=="CON")++nr_of_cons;
				}
				//std::cout<<"nr_of_symbols:"<<nr_of_symbols<<" nr_of_cons:"<<nr_of_cons<<std::endl;
				token_paths_ranked_by_cons.insert(std::make_pair(nr_of_cons,std::make_tuple(nr_of_symbols,words,symbols)));
				token_paths->validate_path(words,NULL);
				//std::cout<<std::endl<<std::endl;
				delete lex;
				lex=NULL;
			}
			catch(invalid_token_path& exception){
				//std::cout<<std::endl<<std::endl;
				delete lex;
				lex=NULL;
			}
		}
		//find the entry in token_paths_ranked_by_cons having the least nr of cons but highest nr of symbols
		unsigned int nr_of_words=0;
		for(auto min_cons_entry=token_paths_ranked_by_cons.lower_bound(token_paths_ranked_by_cons.begin()->first);
				min_cons_entry!=token_paths_ranked_by_cons.upper_bound(token_paths_ranked_by_cons.begin()->first);
				++min_cons_entry){
			if(std::get<0>(min_cons_entry->second)>nr_of_words){
				nr_of_words=std::get<0>(min_cons_entry->second);
			}
		}
		for(auto min_cons_entry=token_paths_ranked_by_cons.lower_bound(token_paths_ranked_by_cons.begin()->first);
				min_cons_entry!=token_paths_ranked_by_cons.upper_bound(token_paths_ranked_by_cons.begin()->first);
				++min_cons_entry){
			if(std::get<0>(min_cons_entry->second)==nr_of_words){
				//TODO: if there are CONs, print which words could not be analyzed
				std::cout<<"nr_of_symbols:"<<nr_of_words<<" nr_of_cons:"<<min_cons_entry->first<<std::endl;
				std::cout<<std::get<2>(min_cons_entry->second)<<std::endl;
				*output_file<<std::get<2>(min_cons_entry->second)<<std::endl;
			}
		}
		token_paths_ranked_by_cons.clear();
		lexer::delete_cache();
		delete token_paths;
		token_paths=NULL;
	}
	sqlite->close();
	db_factory::delete_instance();
	sqlite=NULL;
	filestream->close();
	delete filestream;
	output_file->close();
	delete output_file;
	return 0;
}
