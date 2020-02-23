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
#include <thread>
morphan *stemmer=NULL;
interpreter *sparser=NULL;
db *db_factory::singleton_instance=NULL;
std::map<std::string,unsigned int> symbol_token_map;
std::map<unsigned int,std::string> token_symbol_map;

void calculate_token_paths(tokenpaths *token_paths, const std::string& sentence, const std::string& lid, const bool lexicalize, const std::string& output, const unsigned int id){
	lexer *lex=NULL;
	unsigned int token=0;
	std::locale locale;
	std::ofstream *terminals_file=NULL,*lexicon_file=NULL,*cons_file=NULL;

//	std::cout<<"id="<<id<<std::endl;
	if(id==0){
		terminals_file=new std::ofstream(output,std::ios::out|std::ios::app);
		if(lexicalize==true) lexicon_file=new std::ofstream(output+"_lexicon",std::ios::out|std::ios::app);
		cons_file=new std::ofstream(output+"_cons",std::ios::out|std::ios::app);
	}
	else{
		terminals_file=new std::ofstream(output+std::to_string(id),std::ios::out|std::ios::app);
		if(lexicalize==true) lexicon_file=new std::ofstream(output+"_lexicon"+std::to_string(id),std::ios::out|std::ios::app);
		cons_file=new std::ofstream(output+"_cons"+std::to_string(id),std::ios::out|std::ios::app);
	}
	while(token_paths->is_any_left()==true){
		try{
			locale=std::locale();
			lex=new lexer(sentence.c_str(),lid.c_str(),locale,true,token_paths);
			token_paths->assign_lexer(lex);
			std::vector<lexicon> words;
			unsigned int nr_of_symbols=0;
			while(lex->is_end_of_input()==false){
				if(nr_of_symbols>0){
					//std::cout<<" ";
					*terminals_file<<" ";
				}
				token=lex->next_token();
				std::string symbol=token_symbol_map.find(token)->second;
				*terminals_file<<symbol;
				//std::cout<<symbol;
				++nr_of_symbols;
			}
			//std::cout<<std::endl;
			*terminals_file<<std::endl;
			words=lex->word_entries();
			unsigned int nr_of_cons=0;
			for(auto&& word:words){
				if(word.gcat=="CON"){
					++nr_of_cons;
					*cons_file<<word.word<<std::endl;
				}
				else if(lexicalize==true&&word.lexicon_entry==false){
					std::string lexeme=word.morphalytics->stem()+"_"+lid+"_"+word.gcat;
					*lexicon_file<<word.morphalytics->stem()<<","<<word.gcat<<","<<lexeme<<std::endl;
				}
			}
			//std::cout<<"nr_of_symbols:"<<nr_of_symbols<<" nr_of_cons:"<<nr_of_cons<<std::endl;
			token_paths->validate_path(words,NULL,false);
			delete lex;
			lex=NULL;
		}
//		Leave it here as a guard but it should not happen any more as now only valid paths are taken into account.
		catch(invalid_token_path& exception){
			std::cout<<"Quitting: bumped into an invalid token path. This should not have happened."<<std::endl;
			exit(EXIT_FAILURE);
		}
	}
	terminals_file->close();
	delete terminals_file;
	cons_file->close();
	delete cons_file;
	if(lexicalize==true){
		lexicon_file->close();
		delete lexicon_file;
	}
}

void assign_token_paths(const std::string& sentence, const std::string& lid, const bool lexicalize, const std::string& output,const unsigned int& thread_cap){
	tokenpaths *token_paths=NULL;
	std::thread *threads=NULL;

	unsigned int nr_of_threads=thread_cap;
	std::locale locale=std::locale();
	//trigger morphan and caching to avoid concurrency in case of multithreading
	lexer *lex=new lexer(sentence.c_str(),lid.c_str(),locale,true,NULL);//no tokenpath needed
	delete lex;//cache filled, no token path can be assigned here->delete
	//std::cout<<"analysing sentence:"<<std::endl<<sentence<<std::endl;
	std::vector<tokenpaths *> all_token_paths;
	unsigned int nr_of_paths=lexer::nr_of_paths(sentence);
	if(nr_of_paths<nr_of_threads){
		nr_of_threads=nr_of_paths;
	}
	unsigned int paths_per_thread=nr_of_paths/nr_of_threads;
	unsigned int remainder=nr_of_paths-(paths_per_thread*nr_of_threads);
	//std::cout<<"nr_of_threads:"<<nr_of_threads<<" nr_of_paths:"<<nr_of_paths<<" paths_per_thread:"<<paths_per_thread<<" remainder:"<<remainder<<std::endl;
	unsigned int start=0, end=paths_per_thread+remainder;
	if(nr_of_threads>1) threads=new std::thread[nr_of_threads];
	for(unsigned int i=1;i<nr_of_threads;++i){
//		std::cout<<"i="<<i<<std::endl;
		token_paths=new tokenpaths(start,end);
		all_token_paths.push_back(token_paths);
		threads[i]=std::thread([=]()->void {calculate_token_paths(token_paths,sentence,lid,lexicalize,output,i);});
		start=end;
		end+=paths_per_thread;
	}
	//Get some job done on the main thread
	token_paths=new tokenpaths(start,end);
	calculate_token_paths(token_paths,sentence,lid,lexicalize,output,0);
	delete token_paths;
	for(unsigned int i=1;i<nr_of_threads;++i){
		threads[i].join();
	}
	for(auto i:all_token_paths){
		delete i;
	}
}

int main(int argc, char* argv[]){

	db *sqlite=NULL;
	std::string db_file,lid,corpus_file,output,sentence;
	std::locale locale;
	std::ifstream *filestream=NULL;
	std::ofstream *output_file=NULL;
	bool pun=false,lexicalize=false;
	char delimiter='\n';
	unsigned int nr_of_threads=1;

	logger::singleton("console",0,"LE");
	if(argc<5){
		std::cerr<<"Usage: prep_abl /path/to/dbfile.db /path/to/abl/training/corpus <language id> /path/to/output/file/name pun|nopun -d<delimiter> lex|nolex thread_cap"<<std::endl;
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
	if(argc>8){
		nr_of_threads=std::atoi(argv[8]);
		if(nr_of_threads<1||nr_of_threads>std::thread::hardware_concurrency()) nr_of_threads=1;
	}
	filestream=new std::ifstream(corpus_file);
	if(filestream==NULL){
		exit(EXIT_FAILURE);
	}
	sqlite=db_factory::get_instance();
	sqlite->open(db_file);
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
		assign_token_paths(sentence,lid,lexicalize,output,nr_of_threads);
		lexer::delete_cache();
	}
	std::ifstream *terminals_file=NULL;
	if(nr_of_threads>1){
		output_file=new std::ofstream(output,std::ios::out|std::ios::app);
		for(unsigned int i=1;i<nr_of_threads;++i){
			terminals_file=new std::ifstream(output+std::to_string(i));
			if(terminals_file->is_open()==true){
				std::string terminals;
				while(std::getline(*terminals_file,terminals)){
					*output_file<<terminals<<std::endl;
				}
				terminals_file->close();
				delete terminals_file;
			}
		}
	}
	std::ifstream *lexicon_file=NULL;
	if(lexicalize==true){
		//std::cout<<"\nAdding new words and lexemes...";
		for(unsigned int i=0;i<nr_of_threads;++i){
			if(i==0) lexicon_file=new std::ifstream(output+"_lexicon");
			else lexicon_file=new std::ifstream(output+"_lexicon"+std::to_string(i));
			if(lexicon_file->is_open()==true){
				std::string lexicon_entry;
				while(std::getline(*lexicon_file,lexicon_entry)){
					size_t start_pos=0;
					if(lexicon_entry[start_pos]==',') ++start_pos;//in case the comma itself is to be handled
					size_t end_pos=lexicon_entry.find(',',start_pos);
					std::string stem=sqlite->escape(lexicon_entry.substr(start_pos,end_pos));
					start_pos=end_pos+1;
					end_pos=lexicon_entry.find(',',start_pos);
					std::string gcat=lexicon_entry.substr(start_pos,end_pos-start_pos);
					start_pos=end_pos+1;
					std::string lexeme=sqlite->escape(lexicon_entry.substr(start_pos,std::string::npos));
					sqlite->exec_sql("INSERT OR IGNORE INTO FUNCTORS (FUNCTOR,D_KEY) VALUES ('"+lexeme+"','1');");
					sqlite->exec_sql("INSERT OR IGNORE INTO LEXICON (WORD,LID,GCAT,LEXEME) VALUES ('"+stem+"','"+lid+"','"+gcat+"','"+lexeme+"');");
				}
				lexicon_file->close();
				delete lexicon_file;
			}
		}
	}
	sqlite->close();
	db_factory::delete_instance();
	sqlite=NULL;
	filestream->close();
	delete filestream;
	if(nr_of_threads>1){
		output_file->close();
		delete output_file;
	}
	std::cout<<"Done."<<std::endl;
	return 0;
}
