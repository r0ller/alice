#ifndef TOKENPATHS_H
	#define TOKENPATHS_H

	#include <vector>
	#include <map>

	struct t_word_count{
		t_word_count(std::map<std::string,unsigned int>::iterator& i) : word(i->first), count(i->second) {}
		const std::string& word;
		unsigned int& count;
	};

	class tokenpaths{
		private:
			std::vector<lexicon> words;
			std::vector<lexicon> words_with_token_errors;
			std::vector<std::vector<lexicon> > valid_paths;
			std::vector<std::vector<lexicon> > invalid_paths;
			std::map<std::string,unsigned int> wordtoken_counter;
		public:
			tokenpaths();
			~tokenpaths();
			bool is_any_left();
			void add_word(const lexicon&);
			lexicon next_word(const std::string&);
			void mark_syntax_error(const lexicon&);
			void add_valid_path(const std::vector<lexicon>&);
			void add_invalid_path(const std::vector<lexicon>&);
	};

#endif
