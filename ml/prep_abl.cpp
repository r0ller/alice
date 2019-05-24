#include <iostream>
#include <fstream>
#include "logger.h"
#include "hilib.h"
#include "db_factory.h"
#include "lexer.h"
#include "sp.h"
#include "tokenpaths.h"
#include "query_result.h"
#include "morphan_result.h"
#include "morphan.h"
#include "transgraph.h"
#include <algorithm>
morphan *stemmer=NULL;
lexer *lex=NULL;
interpreter *sparser=NULL;
tokenpaths *token_paths=NULL;
db *db_factory::singleton_instance=NULL;
std::map<std::string,unsigned int> symbol_token_map;
std::map<unsigned int,std::string> token_symbol_map;

int main(int argc, char* argv[]){

	db *sqlite=NULL;
	std::map<std::pair<std::string,std::string>,std::string> lexicon_entries;
	std::string db_file,lid,corpus_file,output,sentence;
	int token=0;
	std::locale locale;
	std::ifstream *filestream=NULL;
	std::ofstream *output_file=NULL;
	std::multimap<unsigned int,std::tuple<unsigned int,std::vector<lexicon>,std::string> > token_paths_ranked_by_cons;
	bool pun=false,lexicalize=false;
	char delimiter='\n';

	logger::singleton("console",0,"LE");
	if(argc<5){
		std::cerr<<"Usage: prep_abl /path/to/dbfile.db /path/to/abl/training/corpus <language id> /path/to/output/file/name pun|nopun -d<delimiter> lex|nolex"<<std::endl;
		exit(EXIT_FAILURE);
	}
	db_file=argv[1];
	corpus_file=argv[2];
	lid=argv[3];
	output=argv[4];
	if(argc>5){
		std::string pun_option=std::string(argv[5]);
		if(pun_option=="pun") pun=true;
		else if(pun_option=="nopun") pun=false;
		else{
			std::cerr<<"error: \""<<pun_option<<"\" is unknown option for punctuation"<<std::endl;
			exit(EXIT_FAILURE);
		}
	}
	if(argc>6){
		std::string delimiter_option=std::string(argv[6]);
		if(delimiter_option.length()==3&&delimiter_option.substr(0,2)=="-d"){
			delimiter=delimiter_option[2];
		}
		else if(delimiter_option=="-d"){
			delimiter='\n';//Nothing is passed in, set new line as default
		}
		else{
			std::cerr<<"error: \""<<delimiter_option<<"\" is unknown option for delimiter"<<std::endl;
			exit(EXIT_FAILURE);
		}
	}
	if(argc>7){
		std::string lex_option=std::string(argv[7]);
		if(lex_option=="lex") lexicalize=true;
		else if(lex_option=="nolex") lexicalize=false;
		else{
			std::cerr<<"error: \""<<lex_option<<"\" is unknown option for lexicalization"<<std::endl;
			exit(EXIT_FAILURE);
		}
	}
	filestream=new std::ifstream(corpus_file);
	if(filestream==NULL){
		exit(EXIT_FAILURE);
	}
	sqlite=db_factory::get_instance();
	sqlite->open(db_file);
	output_file=new std::ofstream(output);
	while(std::getline(*filestream,sentence,delimiter)){
		if(pun==true){
			if(std::ispunct(delimiter,std::locale())==true) sentence+=delimiter;
			locale=std::locale();
			auto i=sentence.begin();
			while(i!=sentence.end()){
				if(ispunct(*i,locale)==true){
					if(i!=sentence.begin()&&isspace(*(i-1),locale)==false){
						i=sentence.insert(i,' ');
						++i;
					}
					if(i!=sentence.end()&&i!=sentence.rbegin().base()&&isspace(*(i+1),locale)==false){
						++i;
						i=sentence.insert(i,' ');
					}
				}
				++i;
			}
		}
		else{
			auto new_end=remove_if(sentence.begin(),sentence.end(),[](char x){return std::ispunct(x,std::locale());});
			sentence.erase(new_end,sentence.end());
		}
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
					else if(lexicalize==true&&word.lexicon_entry==false){
						std::string lexeme=word.morphalytics->stem()+"_"+lid+"_"+word.gcat;
						lexicon_entries.insert(std::make_pair(std::make_pair(word.morphalytics->stem(),word.gcat),lexeme));
					}
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
				std::cout<<"nr_of_symbols:"<<nr_of_words<<" nr_of_cons:"<<min_cons_entry->first<<std::endl;
				if(min_cons_entry->first>0){
					std::cout<<"Constant/concealed words:"<<std::endl;
					for(auto&& word:std::get<1>(min_cons_entry->second)){
						if(word.gcat=="CON") std::cout<<word.word<<" ";
					}
					std::cout<<std::endl;
				}
				std::cout<<"Symbols:"<<std::endl;
				std::cout<<std::get<2>(min_cons_entry->second)<<std::endl;
				*output_file<<std::get<2>(min_cons_entry->second)<<std::endl;
			}
		}
		token_paths_ranked_by_cons.clear();
		lexer::delete_cache();
		delete token_paths;
		token_paths=NULL;
	}
	if(lexicalize==true&&lexicon_entries.empty()==false){
		std::cout<<"\nAdding new words and lexemes...";
		for(auto i:lexicon_entries){
			sqlite->exec_sql("INSERT OR IGNORE INTO FUNCTORS (FUNCTOR,D_KEY) VALUES ('"+i.second+"','1');");
			sqlite->exec_sql("INSERT OR IGNORE INTO LEXICON (WORD,LID,GCAT,LEXEME) VALUES ('"+i.first.first+"','"+lid+"','"+i.first.second+"','"+i.second+"');");
		}
		std::cout<<"Done."<<std::endl;
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
