#ifndef LEXER_H
	#define LEXER_H

	#include "db.h"
	#include "morphan.h"
	#include <vector>
	#include <deque>
	#include <map>

	class lexer{
		private:
			std::string lid;
			std::vector<lexicon> words;
			std::string human_input;
			std::vector<std::string>::iterator word_form_iterator;
			static morphan *stemmer;
			std::deque<unsigned int> token_deque;
			static std::vector<std::string> word_forms_;
			lexicon tokenize_word(morphan_result&);
			void destroy_words();
			static void read_dependencies_by_key(const std::string&, const std::string&, query_result*);
			unsigned int token;
			std::locale locale;
			static std::map<std::string,std::vector<lexicon> > cache;
			std::vector<std::string>::iterator analyze_and_cache(std::string&);
			std::string next_word();
		public:
			lexer(const char *,const char *,std::locale&);
			~lexer();
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
			static query_result* dependencies_read_for_functor(const std::string&);
			static std::vector<std::string>& word_forms(){
				return word_forms_;
			}
			static std::map<std::string,std::vector<lexicon> >& words_analyses(){
				return cache;
			}
			static void delete_cache(){
				cache.clear();
				//TODO: consider providing a release() function for the library.
				//Not freeing the stemmer is a huge performance gain as fst load
				//can take seconds depending on file size.
				//For the time being, trust the OS to delete all objects when the calling program exits.
				//delete stemmer;
				return;
			}
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
