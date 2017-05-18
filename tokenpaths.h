#ifndef TOKENPATHS_H
	#define TOKENPATHS_H

	#include <vector>
	#include <map>
	#include <string>
	#include <set>

	typedef std::string token_symbol;
	typedef std::pair<token_symbol,unsigned int> p_m1_token_symbol_m2_counter;
	typedef std::tuple<std::string,std::string,std::string> t_m0_parent_symbol_m1_head_symbol_m2_non_head_symbol;

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
			void find_rhs_up(const std::string&, const unsigned int, const std::string&, std::multimap<p_m1_token_symbol_m2_counter,token_symbol>&, std::set<t_m0_parent_symbol_m1_head_symbol_m2_non_head_symbol>&, std::set<t_m0_parent_symbol_m1_head_symbol_m2_non_head_symbol>&);
			void find_lhs_down(const std::string&, const unsigned int, const std::string&, std::multimap<p_m1_token_symbol_m2_counter,token_symbol>&, std::set<t_m0_parent_symbol_m1_head_symbol_m2_non_head_symbol>&);
		public:
			tokenpaths();
			~tokenpaths();
			bool is_any_left();
			void add_word(const lexicon&);
			lexicon next_word(const std::string&);
			void mark_syntax_error(const lexicon&);
			void add_valid_path(const std::vector<lexicon>&);
			void add_invalid_path(const std::vector<lexicon>&);
			std::multimap<p_m1_token_symbol_m2_counter,token_symbol> followup_token(const unsigned int);
	};

#endif
