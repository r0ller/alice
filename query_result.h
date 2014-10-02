#ifndef QUERY_RESULT_H
	#define QUERY_RESULT_H
	#include <utility>
	#include <map>
	#include <string>

	typedef struct{
		std::string field_name;
		std::string field_value;
	}field;

	class query_result{
		private:
			std::multimap<unsigned int,field> raw_result_set;
		public:
			query_result();
			~query_result();
			std::multimap<unsigned int,field>::const_iterator get_row(const unsigned int);
			const std::string& get_field_value(const unsigned int, const std::string&);
			const std::multimap<unsigned int,field>& result_set();
			unsigned int result_rows();
			void insert(const std::pair<unsigned int, field>&);
			const std::pair<unsigned int,field>& find_field_value(const std::string&, const std::string&);
			void keep(const std::set<unsigned int>&);
	};
#endif
