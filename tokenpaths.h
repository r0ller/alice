#ifndef TOKENPATHS_H
	#define TOKENPATHS_H

	#include <vector>
	#include <string>
	#include <map>
	#include "lexer.h"
	#include "sp.h"
	#include "transgraph.h"

	typedef std::string token_symbol;
	typedef std::pair<token_symbol,unsigned int> p_m1_token_symbol_m2_counter;
	typedef std::tuple<std::string,std::string,std::string> t_m0_parent_symbol_m1_head_symbol_m2_non_head_symbol;

	class lexer;

	class tokenpaths{
		private:
			//Using vector for words instead of set to preserve word order esp. as one word
			//can appear more than once in a sentence.
			std::vector<lexicon> words;
			std::vector<std::vector<node_info> > valid_parse_trees;
			std::vector<std::vector<node_info> > invalid_parse_trees;
			std::vector<std::vector<lexicon> > valid_paths;
			std::vector<std::vector<lexicon> > invalid_paths;
			std::vector<const transgraph *> valid_graphs;
			std::vector<std::string> invalid_path_errors;
			bool is_any_path_left;
			void find_rhs_up(const std::string&, const unsigned int, const std::string&, std::multimap<p_m1_token_symbol_m2_counter,token_symbol>&, std::set<t_m0_parent_symbol_m1_head_symbol_m2_non_head_symbol>&, std::set<t_m0_parent_symbol_m1_head_symbol_m2_non_head_symbol>&);
			void find_lhs_down(const std::string&, const unsigned int, const std::string&, std::multimap<p_m1_token_symbol_m2_counter,token_symbol>&, std::set<t_m0_parent_symbol_m1_head_symbol_m2_non_head_symbol>&);
			void add_internal_invalid_path(const std::vector<lexicon>&);
			void reset();
			std::string semantics(std::vector<lexicon>&, std::map<std::string,std::string>&,unsigned int&,const std::string&);
            std::string morphology(std::vector<lexicon>&,unsigned int&);
            void morphology_wo_cons(const std::vector<lexicon>&,std::vector<lexicon>&);
            std::string yyerror;
			std::string functors(const std::map<std::string,std::map<std::string,std::string> >&,const std::map<std::string,std::vector<lexicon> >&,const unsigned int&,std::string&);
			std::string dependencies(query_result&,std::map<std::pair<std::string,std::string>,std::string>&);
			std::string syntax(const std::vector<node_info>&);
			std::string traverse_nodes_lr(const node_info&, const std::vector<node_info>&);
			lexer *lex;
			unsigned int path_nr_to_start_at;
			unsigned int path_nr_to_stop_at;
			unsigned int current_path_nr;
			std::vector<unsigned short int> path_indices;
			std::vector<unsigned short int> path_nr_to_indices(const unsigned int);
            void build_dependency_semantics(interpreter *,std::vector<lexicon>&,std::set<unsigned int>&,const lexicon&,unsigned int&);
            std::vector<lexicon> find_main_verb(const std::vector<lexicon>&);
            void combine_nodes(interpreter*,std::vector<lexicon>&,std::set<unsigned int>&,const lexicon&,const lexicon&,unsigned int&);
            lexicon find_word_by_lexeme(const std::vector<lexicon>&,const std::string&);
            lexicon find_word_by_gcat(const std::vector<lexicon>&,const std::string&);
        public:
			tokenpaths();
			tokenpaths(const unsigned int,const unsigned int);
			~tokenpaths();
			bool is_any_left();
			lexicon next_word(const std::vector<lexicon>&);
			void validate_path(const std::vector<lexicon>&, const transgraph *, const bool store);
			void invalidate_path(const std::vector<lexicon>&, const std::string&, std::exception *);
			std::multimap<p_m1_token_symbol_m2_counter,token_symbol> followup_token(const unsigned int);
            std::string create_analysis(const unsigned char&,const std::string&,const std::string&,const std::time_t&,const std::string&);
			void log_yyerror(const std::string&);
			void validate_parse_tree(const std::vector<node_info>&);
			void invalidate_parse_tree(const std::vector<node_info>&);
			void assign_lexer(lexer *);
	};

	class invalid_token_path:public std::exception{
		public:
			virtual const char *what() const throw(){
				return "Invalid token path found.\n";
			}
	};

#endif
