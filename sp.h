#ifndef SP_H
	#define SP_H

	#include <map>
	#include <string>
	#include <vector>
	#include <stack>
	#include <utility>
	#include <tuple>
	#include <set>
	#include "db_factory.h"
	#include "transgraph.h"
	#include "rapidjson/document.h"
	#include "logger.h"
	#include "preprocessor.h"

	typedef struct functor_data{
		std::string functor;
		unsigned int d_key;
		unsigned int functor_id;
	}functor_data;

	typedef struct node_info{
		unsigned int node_id;
		std::set<unsigned int> ref_node_ids;//node ids of referenced nodes;
		bool ref_to_context=false;
		std::string symbol;
		lexicon expression;/*lexeme or constant*/
		unsigned int left_child;
		unsigned int right_child;/*argument node*/
		std::map<unsigned int,unsigned int> node_links;//uint1:node_id,uint2:seq.nr.;historical sequence of semantically validated nodes (syntactic validation is carried out by bison and is recorded in the tree)
		std::multimap<unsigned int,unsigned int> dependency_validation_matrix;//uint1:row_index of dependency entry in expression.dependencies, uint2: dependent node id
	}node_info;


	typedef struct ev_name_value_pair{
		std::string name;
		std::string value;
	}ev_name_value_pair;

//Best practice for renaming first and second in pairs (for later reference):
//	typedef map<Vertex, Edge> AdjacencyList;
//	struct adjacency
//	{
//	    adjacency(AdjacencyList::iterator& it)
//	      : vertex(it->first), edge(it->second) {}
//	    Vertex& vertex;
//	    Edge& edge;
//	};
//
//	And then:
//	Vertex v = adjacency(it).vertex;

	typedef std::pair<unsigned int,unsigned int> p_m1_node_id_m2_d_key;
//	typedef std::pair<unsigned int,unsigned int> p_m1_nr_of_deps_m2_nr_of_deps_to_find;
	typedef std::tuple<std::string,unsigned int,unsigned int,unsigned int,unsigned int> t_m0_parent_node_m1_nr_of_deps_m2_nr_of_deps_to_find_m3_parent_dkey_m4_parent_dcounter;
	typedef std::pair<unsigned int,p_m1_node_id_m2_d_key> p_m1_tree_level_m2_p_m1_node_id_m2_d_key;
	typedef std::map<p_m1_node_id_m2_d_key,t_m0_parent_node_m1_nr_of_deps_m2_nr_of_deps_to_find_m3_parent_dkey_m4_parent_dcounter> t_map_of_node_ids_and_d_keys_to_nr_of_deps;
	struct t_pair_of_node_id_and_d_key_with_nr_of_deps{
		t_pair_of_node_id_and_d_key_with_nr_of_deps(t_map_of_node_ids_and_d_keys_to_nr_of_deps::const_iterator& i) : node_id_and_d_key(i->first), nr_of_deps(i->second) {}
		const p_m1_node_id_m2_d_key& node_id_and_d_key;
		const t_m0_parent_node_m1_nr_of_deps_m2_nr_of_deps_to_find_m3_parent_dkey_m4_parent_dcounter& nr_of_deps;
	};
	typedef std::map<p_m1_node_id_m2_d_key,t_map_of_node_ids_and_d_keys_to_nr_of_deps> t_node_dependency_traversals;
	struct t_node_dependency_traversal{
		t_node_dependency_traversal(t_node_dependency_traversals::const_iterator& i) : node_id_and_d_key(i->first), map_of_node_ids_and_d_keys_to_nr_of_deps(i->second) {}
		const p_m1_node_id_m2_d_key& node_id_and_d_key;
		const t_map_of_node_ids_and_d_keys_to_nr_of_deps& map_of_node_ids_and_d_keys_to_nr_of_deps;
	};

	class lexer;
	class tokenpaths;

	class interpreter{
		private:
			unsigned char toa_;
			node_info& get_private_node_info(unsigned int);
			unsigned int get_head_node(const node_info&);
			std::multimap<std::pair<std::string,std::string>,std::pair<unsigned int,std::string> >* is_valid_expression(node_info&, node_info&);
			unsigned int is_valid_combination(const std::string&, const node_info&, const node_info&);
			void find_functors_for_dependency(const std::string&, const std::string&, const query_result*, std::multimap<std::pair<std::string,std::string>, std::pair<unsigned int,std::string> >&, std::vector<std::pair<unsigned int,std::string> >&);
			std::multimap<std::pair<std::string,std::string>,std::pair<unsigned int,std::string> >* functors_found_for_dependencies(const node_info&, node_info&);
			void find_dependencies_for_node(const unsigned int, t_map_of_node_ids_and_d_keys_to_nr_of_deps&, std::multimap<std::pair<std::string,unsigned int>,std::tuple<std::string,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int> >&);
			void find_dependencies_for_functor(const std::string&, const std::string&, const unsigned int, const unsigned int, const std::string&, t_map_of_node_ids_and_d_keys_to_nr_of_deps&,std::multimap<std::pair<std::string,unsigned int>,std::tuple<std::string,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int> >&, std::multimap<unsigned int,std::tuple<unsigned int,unsigned int,unsigned int,unsigned int> >&);
			void find_dependencies_for_functor(const std::string&, const std::string&, const unsigned int, const unsigned int, const std::string&, const std::string&, const std::string&, t_map_of_node_ids_and_d_keys_to_nr_of_deps&, std::multimap<std::pair<std::string,unsigned int>,std::tuple<std::string,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int> >&,std::multimap<unsigned int,std::tuple<unsigned int,unsigned int,unsigned int,unsigned int> >&);
			const std::pair<const unsigned int,field>* followup_dependency(const unsigned int, const std::string&, const std::string&, const bool, const query_result&);
			std::pair<p_m1_node_id_m2_d_key,t_m0_parent_node_m1_nr_of_deps_m2_nr_of_deps_to_find_m3_parent_dkey_m4_parent_dcounter> calculate_longest_matching_dependency_route(std::map<p_m1_node_id_m2_d_key,std::pair<t_m0_parent_node_m1_nr_of_deps_m2_nr_of_deps_to_find_m3_parent_dkey_m4_parent_dcounter,std::map<unsigned int,std::pair<t_m0_parent_node_m1_nr_of_deps_m2_nr_of_deps_to_find_m3_parent_dkey_m4_parent_dcounter,unsigned int> > > >&);
			void calculate_longest_matching_dependency_route(const unsigned int, const p_m1_node_id_m2_d_key&, std::map<unsigned int,std::pair<t_m0_parent_node_m1_nr_of_deps_m2_nr_of_deps_to_find_m3_parent_dkey_m4_parent_dcounter,unsigned int> >&);
			unsigned int nr_of_dependencies_to_be_found();
			transgraph* build_transgraph(const p_m1_node_id_m2_d_key&, const std::pair<std::string,unsigned int>&,
					std::map<p_m1_node_id_m2_d_key,std::pair<t_m0_parent_node_m1_nr_of_deps_m2_nr_of_deps_to_find_m3_parent_dkey_m4_parent_dcounter,std::map<unsigned int,std::pair<t_m0_parent_node_m1_nr_of_deps_m2_nr_of_deps_to_find_m3_parent_dkey_m4_parent_dcounter,unsigned int> > > >&,
					const unsigned int = 1, const unsigned int = 0);
			unsigned int direct_descendant_of(const node_info&);
			void destroy_node_infos();
			std::vector<unsigned int> validated_nodes;
			std::vector<node_info> node_infos;
			unsigned int nr_of_nodes_;
			//std::string command;
			//std::string options;
			std::stack<p_m1_node_id_m2_d_key> node_dependency_traversal_stack;
			std::map<p_m1_tree_level_m2_p_m1_node_id_m2_d_key,std::vector<p_m1_node_id_m2_d_key> > node_dependency_traversal_stack_tree;
			t_node_dependency_traversals  node_dependency_traversals;
			std::map<std::pair<unsigned int,unsigned int>,std::multimap<std::pair<std::string,unsigned int>,std::tuple<std::string,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int> > >  node_odependency_traversals;
			void get_leafs_of_node_lr(const node_info&, std::vector<unsigned int>&);
			unsigned int check_prerequisite_symbols(const node_info&, const node_info&);
			std::pair<std::string,unsigned int> find_child_for_parent_bottom_up_via_optional_path(const unsigned int, const std::string&, const unsigned int, const unsigned int,
			std::multimap<std::pair<std::string,unsigned int>,std::tuple<std::string,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int> >&,
			std::map<unsigned int,std::pair<t_m0_parent_node_m1_nr_of_deps_m2_nr_of_deps_to_find_m3_parent_dkey_m4_parent_dcounter,unsigned int> >&);
			void combine_sets(const unsigned int&, const std::map<unsigned int,std::vector<unsigned int>>&, std::map<unsigned int,std::vector<unsigned int>>&);
			void insert_in_main_dvm_and_dep_node_links(std::multimap<unsigned int,std::pair<unsigned int,unsigned int> >&);
			void build_dependency_semantics(std::vector<lexicon>&,std::set<unsigned int>&,std::map<unsigned int,unsigned int>&,const unsigned int&,const std::string&,std::set<std::pair<unsigned int,unsigned int>>&,std::set<std::pair<unsigned int,unsigned int>>&,lexer *);
			unsigned int combine_nodes(std::vector<lexicon>&,std::set<unsigned int>&,std::map<unsigned int,unsigned int>&,const unsigned int&,const unsigned int&,const unsigned int&,std::set<std::pair<unsigned int,unsigned int>>&,const std::string&);
			void process_depolex_by_row_nr(const std::pair<const unsigned int,field>*, const std::string&,const std::string&,const std::set<unsigned int>&, const lexicon&, const unsigned int&, const unsigned int&, const std::string&,
					const unsigned int&,std::vector<lexicon>&, std::set<unsigned int>&, std::map<unsigned int,unsigned int>&, std::set<std::pair<unsigned int,unsigned int>>&, std::set<std::pair<unsigned int,unsigned int>>&, lexer*);
			std::set<unsigned int> find_context_reference_node(const unsigned int);
			std::string find_morpheme_id_for_syntax_node(const std::string&,rapidjson::Value::Object&);
			//find_dependency_nodes_with_tag_value: 2nd and 3rd params (key, value) are pass by value to avoid passing in something from a node instance which may be invalidated during set_node_info() calls inside
			void find_dependency_nodes_with_tag_value(rapidjson::Document::AllocatorType&,const std::string,const std::string,const rapidjson::Value&,std::vector<rapidjson::Value>&);
			//find_dependency_chain_with_tag_value: lid (fist param) is pass by value to avoid passing in something from a node instance which may be invalidated during set_node_info() calls inside
			void find_dependency_chain_with_tag_value(const std::string,const std::string&,const std::string&,const unsigned int&,const std::string&,const rapidjson::Value::Object&,const rapidjson::Value::Object&,std::set<unsigned int>&,std::map<unsigned int,unsigned int>&);
			unsigned int create_node(const std::string&,const std::string&,const rapidjson::Value::Object&);
			unsigned int create_node_for_syntax_node(const std::string&,const std::string&,const rapidjson::Value::Object&);
			unsigned int find_context_node_ids_for_syntax_node(const std::string&,const rapidjson::Value::Object&,const rapidjson::Value::Object&,std::map<unsigned int,unsigned int>&);
			std::set<unsigned int> context_node_ids;
			std::string timestamp_;
			const preprocessor *pp_;
			rapidjson::Value::Object find_syntax_node(const rapidjson::Value::Object&,const std::string&);
			std::string ref_symbol;
			std::string ref_stem;
			std::string ref_tag;
		public:
			interpreter(const unsigned char toa,const std::string&,const preprocessor*);
			~interpreter();
			int set_node_info(const std::string&, const lexicon&);
			int set_node_info(const std::string&, const node_info&);
			int set_node_info_left(const std::string&, const node_info&);
			const node_info& get_node_info(unsigned int);
			int combine_nodes(const std::string&, const node_info&, const node_info&);
			transgraph* longest_match_for_semantic_rules_found();
			unsigned int add_feature_to_leaf(const node_info&,const std::string&, const bool& = false, const unsigned int& = 0);
			unsigned int add_feature_to_leaf(const node_info&, const std::string&, const std::string&, const bool& = false, const unsigned int& = 0);
			unsigned int add_feature_to_leaf(const node_info&, const std::string&, const std::string&, const std::string&, const bool& = false, const unsigned int& = 0);
			std::set<unsigned int> validated_terminals();
			std::vector<node_info> nodes();
			bool is_valid_combination(const unsigned int&,const unsigned int&);
			void build_dependency_semantics(lexer*,tokenpaths*,lexicon&);
			void get_nodes_by_symbol(const node_info&, const std::string, const std::string, std::map<unsigned int,bool>&, std::vector<unsigned int>&);
			void find_functors_for_dependency_with_gcat_in_db(const std::vector<lexicon>&, const std::string&,const std::string&,const std::string&,const std::string&,std::set<std::pair<std::string,unsigned int>>&,std::set<std::pair<std::string,unsigned int>>&);
			std::set<std::pair<std::string,unsigned int>> find_functors_with_matching_nr_of_deps(const std::vector<lexicon>& all_words,const std::vector<lexicon>& words,const std::string& main_verb_symbols);
			std::vector<node_info> context_nodes();
			unsigned int add_feature_to_leaf_with_value(const node_info&, const std::string&, const std::string&);
			unsigned int add_feature_to_leaf_with_value(const node_info&, const std::string&, const std::string&, const std::string&);
			unsigned int add_feature_to_leaf_with_value(const node_info&, const std::string&, const std::string&, const std::string&, const std::string&);
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
			std::string message;
		public:
			object_node_missing(std::string left, std::string right){
				left_node=left;
				right_node=right;
				message="Object node missing, cannot interpret: "+left_node+right_node;
			}
			~object_node_missing() throw() {};
			virtual const char *what() const throw(){
				return message.c_str();
			}
	};

	class head_node_missing:public semper_error{
		private:
			std::string left_node;
			std::string right_node;
			std::string message;
		public:
			head_node_missing(std::string left, std::string right){
				left_node=left;
				right_node=right;
				message="Head node missing, cannot interpret: "+left_node+right_node;
			}
			~head_node_missing() throw() {};
			virtual const char *what() const throw(){
				return message.c_str();
			}
	};

	class invalid_combination:public semper_error{
		private:
			std::string left_node;
			std::string right_node;
			std::string message;
		public:
			invalid_combination(std::string left, std::string right){
				left_node=left;
				right_node=right;
				message="Cannot interpret the invalid combination of "+left_node+" and "+right_node;
			}
			~invalid_combination() throw() {};
			std::string get_left(){
				return left_node;
			}
			std::string get_right(){
				return right_node;
			}
			virtual const char *what() const throw(){
				return message.c_str();
			}
	};

	class missing_prerequisite_symbol:public semper_error{
		private:
			std::string parent_symbol;
			std::string child_symbol;
			std::string message;
		public:
			missing_prerequisite_symbol(std::string parent,std::string child){
				parent_symbol=parent;
				child_symbol=child;
				message="Prerequisite symbol check failed for rule "+parent_symbol+"->"+child_symbol;
			}
			~missing_prerequisite_symbol() throw() {};
			virtual const char *what() const throw(){
				return message.c_str();
			}
	};

	class dependency_counter_manner_validation_failed:public semper_error{
		private:
			std::string functor;
			std::string message;
		public:
			dependency_counter_manner_validation_failed(std::string functor){
				this->functor=functor;
				message="Dependency check failed for functor "+functor+" when validating dependency counter and manner.";
			}
			~dependency_counter_manner_validation_failed() throw() {};
			virtual const char *what() const throw(){
				return message.c_str();
			}
	};

#endif
