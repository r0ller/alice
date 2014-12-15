#ifndef SP_H
	#define SP_H

	#include <map>
	#include <string>
	#include <vector>
	#include <stack>

	typedef struct functor_data{
		std::string functor;
		unsigned int d_key;
		unsigned int functor_id;
	}functor_data;

	typedef struct node_info{
		unsigned int node_id;
		std::string symbol;
		lexicon expression;/*lexeme or constant*/
		unsigned int left_child;
		unsigned int right_child;/*argument node*/
		std::map<unsigned int,unsigned int> node_links;//uint1:node_id,uint2:seq.nr.;historical sequence of semantically validated nodes (syntactic validation is carried out by bison and is recorded in the tree)
		std::multimap<unsigned int,unsigned int> dependency_validation_matrix;//uint1:row_index of dependency entry in expression.dependencies, uint2: dependent node id
		functor_data functor_attributes;
	}node_info;


	typedef struct ev_name_value_pair{
		std::string name;
		std::string value;
	}ev_name_value_pair;

	class interpreter{
		private:
			node_info& get_private_node_info(unsigned int);
			unsigned int get_head_node(const node_info&);
			void get_nodes_by_symbol(const node_info&, const std::string, std::vector<unsigned int>&);
			std::multimap<std::pair<std::string,std::string>,std::pair<unsigned int,std::string> >* is_valid_expression(node_info&, node_info&);
			bool is_valid_combination(const std::string&, const node_info&, const node_info&);
			bool find_functors_for_dependency(const std::string&, const query_result&, std::multimap<std::pair<std::string,std::string>, std::pair<unsigned int,std::string> >&, std::vector<std::pair<unsigned int,std::string> >&);
			std::multimap<std::pair<std::string,std::string>,std::pair<unsigned int,std::string> >* functors_found_for_dependencies(const node_info&, node_info&);
			void find_dependencies_for_node(const unsigned int, std::map<std::pair<unsigned int,unsigned int>,unsigned int>&, std::map<std::pair<std::string,unsigned int>,unsigned int>&);
			void find_dependencies_for_functor(const unsigned int, const std::string&, std::map<std::pair<unsigned int,unsigned int>,unsigned int>&,std::map<std::pair<std::string,unsigned int>,unsigned int>&);
			void find_dependencies_for_functor(const unsigned int, const std::string&, const std::string&, const std::string&, std::map<std::pair<unsigned int,unsigned int>,unsigned int>&, std::map<std::pair<std::string,unsigned int>,unsigned int>&);
			const std::pair<const unsigned int,field>* followup_dependency(const unsigned int, const std::string&, const std::string&, const bool, const query_result&);
			//std::vector<std::string> find_ev_occurence_in(const std::string&);
			//void set_command(const std::string&, const std::string&, const std::string&);
			//void set_options(const std::string&);
			//void find_ev_definitions(const std::string&, std::vector<std::string>&);
			//void find_ev_definitions(const std::string&, std::vector<ev_name_value_pair>&);
			//void delete_ev_redefinitions(const std::string&, std::string&);
			//std::string resolve_ev_redefinitions(const std::string&, const std::string&);
			void destroy_node_infos();
			std::vector<node_info> node_infos;
			unsigned int nr_of_nodes;
			std::string command;
			std::string options;
			std::stack<unsigned int> node_dependency_traversal_stack;
			std::map<std::pair<unsigned int,unsigned int>,std::map<std::pair<unsigned int,unsigned int>,unsigned int> >  node_dependency_traversals;
		public:
			interpreter();
			~interpreter();
			int set_node_info(const lexicon&, const node_info&);
			const node_info& get_node_info(unsigned int);
			int combine_nodes(const std::string&, const node_info&, const node_info&);
			bool is_longest_match_for_semantic_rules_found();
			//std::string get_command();
	};

	class semper_error:public std::exception{
		public:
			virtual const char *what() const throw(){
				return "Error during semantic parsing\n";
			}
	};

	class object_node_missing:public semper_error{
		private:
			std::string left_node;
			std::string right_node;
		public:
			object_node_missing(std::string, std::string);
			~object_node_missing() throw() {};
			virtual const char *what() const throw(){
				std::string message;

				message="Object node missing, cannot interpret: "+left_node+right_node;
				return message.c_str();
			}
	};

	object_node_missing::object_node_missing(std::string left, std::string right){
		left_node=left;
		right_node=right;
	}

	class head_node_missing:public semper_error{
		private:
			std::string left_node;
			std::string right_node;
		public:
			head_node_missing(std::string, std::string);
			~head_node_missing() throw() {};
			virtual const char *what() const throw(){
				std::string message;

				message="Head node missing, cannot interpret: "+left_node+right_node;
				return message.c_str();
			}
	};

	head_node_missing::head_node_missing(std::string left, std::string right){
		left_node=left;
		right_node=right;
	}

	class invalid_combination:public semper_error{
		private:
			std::string left_node;
			std::string right_node;
		public:
			invalid_combination(std::string, std::string);
			~invalid_combination() throw() {};
			virtual const char *what() const throw(){
				std::string message;

				message="Invalid combination, cannot interpret: "+left_node+right_node;
				return message.c_str();
			}
	};

	invalid_combination::invalid_combination(std::string left, std::string right){
		left_node=left;
		right_node=right;
	}
#endif
