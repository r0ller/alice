#ifndef LEXER_H
	#define LEXER_H

	#include "db.h"
	#include <vector>

	class lexer{
		private:
			int store_word(const std::string&);
			std::string prepare_query(const std::string&);
			void destroy_words();
			std::vector<lexicon> words;	//consider if needs to be changed to map
			unsigned int nr_of_words;
			std::string human_input;
			std::string::iterator human_input_iterator;
			std::string last_word;
		public:
			lexer(const char *);
			~lexer();
			int next_token();
			lexicon get_word_by_token(unsigned int);
			const std::string& last_word_scanned();
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
