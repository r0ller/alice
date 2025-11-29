#ifndef LEXER_H
	#define LEXER_H

	#include "hi.y.hpp"
	#include "hi_constants.h"
	#include <locale>
	#include "logger.h"
	#include "db_factory.h"
	#include "morphan.h"
	#include "tokenpaths.h"
	#include <vector>
	#include <deque>
	#include <map>

	class tokenpaths;

	class lexer{
		private:
			std::string lid;
			std::vector<lexicon> words;
			std::string human_input;
			std::vector<std::string>::iterator word_form_iterator;
			static morphan *stemmer;
			std::deque<unsigned int> token_deque;
			static std::map<std::string,std::vector<std::string>> sentences_word_forms;
			std::vector<std::string> word_forms_;
			void destroy_words();
			static void read_dependencies_by_key(const std::string&, const std::string&, query_result*, const bool=false);
			unsigned int token;
			std::locale locale;
			static std::map<std::string,std::vector<lexicon> > cache;
			bool generate_tokens_;
			tokenpaths *token_paths;
			bool end_token_returned;
		public:
			lexer(const char *,const char *,std::locale&,const bool,tokenpaths *);
			~lexer();
			std::string next_word();
			unsigned int next_token();
			lexicon last_word_scanned();
			lexicon last_word_scanned(const unsigned int);
			lexicon get_word_by_lexeme(const std::string);
			unsigned int nr_of_words();
			std::string language();
			bool is_end_of_input();
			std::string validated_words();
			std::vector<lexicon> word_entries();
			unsigned int last_token_returned();
			static query_result* dependencies_read_for_functor(const std::string&,const bool=false);
			std::vector<std::string> word_forms();
			std::string work_string();
			static std::vector<std::string> word_forms(const std::string& sentence){
				std::vector<std::string> word_forms_found;

				auto iterator=sentences_word_forms.find(sentence);
				if(iterator!=sentences_word_forms.end()) word_forms_found=iterator->second;
				return word_forms_found;
			}
			static std::map<std::string,std::vector<lexicon> >& words_analyses(){
				return cache;
			}
			static void delete_cache(){
				cache.clear();
				sentences_word_forms.clear();
				//TODO: consider providing a release() function for the library.
				//Not freeing the stemmer is a huge performance gain as fst load
				//can take seconds depending on file size.
				//For the time being, trust the OS to delete all objects when the calling program exits.
				//delete stemmer;
				return;
			}
			static unsigned int nr_of_paths(const std::string& sentence){
				unsigned int paths=0;

				auto sentence_hit=sentences_word_forms.find(sentence);
				if(sentence_hit!=sentences_word_forms.end()){
					for(auto word_form:sentence_hit->second){
						//std::cout<<"looking for word form:"<<word_form<<std::endl;
						auto cache_hit=cache.find(word_form);
						if(cache_hit!=cache.end()){
							//std::cout<<"nr of words found for word form:"<<cache_hit->second.size()<<std::endl;
							if(paths==0) paths=cache_hit->second.size();
							else paths*=cache_hit->second.size();
						}
					}
					logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"nr of paths:"+std::to_string(paths));
				}
				return paths;
			}
			std::map<unsigned int,lexicon> find_main_verb(const std::vector<lexicon>&) const;
			std::map<unsigned int,lexicon> find_word_by_lexeme(const std::vector<lexicon>&,const std::set<unsigned int>&,const std::string&);
			std::map<unsigned int,lexicon> find_word_by_gcat(const std::vector<lexicon>&,const std::set<unsigned int>&,const std::string&);
			std::vector<std::string> analyze_and_cache(std::string&);
			std::vector<lexicon> cached_word_entries();
			std::pair<std::string,std::vector<lexicon>> copy_word_from_cache(std::string&);
			static lexicon tokenize_word(morphan_result&,const std::string&,const bool=false);
			bool is_end_token_returned();
			void end_reached();
	};

	class lexer_error:public std::exception{
		public:
			virtual const char *what() const throw(){
				return "Error during lexical scanning\n";
			}
	};

	class lexicon_type_and_db_table_schema_mismatch:public lexer_error{
		public:
			virtual const char *what() const throw(){
				return "The fields of type 'lexicon' and that of the database table do not match\n";
			}
	};

	class more_than_one_token_found:public lexer_error{
		public:
			virtual const char *what() const throw(){
				return "More than one token were found for a word in the lexicon\n";//TODO: insert which word!
			}
	};
#endif
