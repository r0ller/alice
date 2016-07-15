#ifndef LEXER_H
	#define LEXER_H

	#include "db.h"
	#include "morphan.h"
	#include <vector>
	#include <deque>
//	#include <algorithm>

	class lexer{
		private:
			std::string lid;
			std::vector<lexicon> words;
			std::string human_input;
			std::string::iterator human_input_iterator;
			morphan *stemmer;
			std::vector<morphan_result> *morphalytics;
			std::deque<unsigned int> token_deque;
			lexicon tokenize_word(morphan_result&);
			void destroy_words();
			query_result* dependencies_read_for_functor(const std::string&);
			void read_dependencies_by_key(const std::string&, const std::string&, query_result*);
		public:
			lexer(const char *,const char *);
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
