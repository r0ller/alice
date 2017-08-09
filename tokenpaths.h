#ifndef TOKENPATHS_H
	#define TOKENPATHS_H

	#include <vector>
	#include <string>

	typedef std::string token_symbol;
	typedef std::pair<token_symbol,unsigned int> p_m1_token_symbol_m2_counter;
	typedef std::tuple<std::string,std::string,std::string> t_m0_parent_symbol_m1_head_symbol_m2_non_head_symbol;

	class tokenpaths{
		private:
			//Using vector for words instead of set to preserve word order esp. as one word
			//can appear more than once in a sentence.
			std::vector<lexicon> words;
			std::vector<std::vector<lexicon> > valid_paths;
			std::vector<std::vector<lexicon> > invalid_paths;
			std::vector<std::vector<lexicon> > internal_valid_paths;
			std::vector<std::vector<lexicon> > internal_invalid_paths;
			bool is_any_path_left;
			void find_rhs_up(const std::string&, const unsigned int, const std::string&, std::multimap<p_m1_token_symbol_m2_counter,token_symbol>&, std::set<t_m0_parent_symbol_m1_head_symbol_m2_non_head_symbol>&, std::set<t_m0_parent_symbol_m1_head_symbol_m2_non_head_symbol>&);
			void find_lhs_down(const std::string&, const unsigned int, const std::string&, std::multimap<p_m1_token_symbol_m2_counter,token_symbol>&, std::set<t_m0_parent_symbol_m1_head_symbol_m2_non_head_symbol>&);
			void add_internal_valid_path(const std::vector<lexicon>&);
			void add_internal_invalid_path(const std::vector<lexicon>&);
			void reset();
		public:
			tokenpaths();
			~tokenpaths();
			bool is_any_left();
			lexicon next_word(const std::vector<lexicon>&);
			void validate_path(const std::vector<lexicon>&);
			void invalidate_path(const std::vector<lexicon>&);
			std::multimap<p_m1_token_symbol_m2_counter,token_symbol> followup_token(const unsigned int);
	};

	class invalid_token_path:public std::exception{
		public:
			virtual const char *what() const throw(){
				return "Invalid token path found.\n";
			}
	};

#endif
