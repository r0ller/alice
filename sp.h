#ifndef SP_H
	#define SP_H

	#include <string>
	#include <vector>

	typedef struct node_info{
		unsigned int node_id;
		std::string symbol;
		std::string expression;/*lexeme or constant*/
		unsigned int left_child;
		unsigned int right_child;/*argument node*/
	}node_info;

	typedef struct ev_name_value_pair{
		std::string name;
		std::string value;
	}ev_name_value_pair;

		class interpreter{
		private:
			db *is_valid_expression_of_type(const std::string&, const std::string&);
			bool is_valid_combination(const node_info&, const node_info&);
			std::vector<std::string> find_ev_occurence_in(const std::string&);
			void set_command(const std::string&, const std::string&, const std::string&);
			void set_options(const std::string&);
			void find_ev_definitions(const std::string&, std::vector<std::string>&);
			void find_ev_definitions(const std::string&, std::vector<ev_name_value_pair>&);
			void delete_ev_redefinitions(const std::string&, std::string&);
			std::string resolve_ev_redefinitions(const std::string&, const std::string&);
			void destroy_node_infos();
			std::vector<node_info> node_infos;
			unsigned int nr_of_nodes;
			std::string command;
			std::string options;
		public:
			interpreter();
			~interpreter();
			int set_node_info(const std::string&, const std::string&, const node_info&);
			const node_info& get_node_info(unsigned int);
			int combine_nodes(const std::string&, const node_info&, const node_info&);
			unsigned int get_object_node(const node_info&);
			unsigned int get_head_node(const node_info&);
			std::string get_command();
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
