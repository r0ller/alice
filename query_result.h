#ifndef QUERY_RESULT_H
	#define QUERY_RESULT_H
	#include <utility>
	#include <map>
	#include <string>
	#include <set>
	#include <algorithm>

	typedef struct{
		std::string field_name;
		std::string field_value;
	}field;

	class query_result{
		private:
			std::multimap<unsigned int,field> raw_result_set;
			unsigned int nr_of_columns;
			std::set<std::string> fields;
			std::multimap<unsigned int,field> row_buffer;
			std::set<std::set<std::pair<std::string,std::string> > > row_set;
		public:
			query_result();
			~query_result();
			std::multimap<unsigned int,field>::const_iterator row_at_position(const unsigned int) const;
			const std::string* field_value_at_row_position(const unsigned int, const std::string&) const;
			const std::multimap<unsigned int,field>& result_set() const;
			unsigned int nr_of_result_rows() const;
            void insert(const std::pair<unsigned int, field>&);
            void append(const std::pair<unsigned int, field>&);
			const std::pair<const unsigned int,field>* first_value_for_field_name_found(const std::string&, const std::string&) const;
			const std::pair<const unsigned int,field>* value_for_field_name_found_after_row_position(const unsigned int, const std::string&, const std::string&) const;
			void keep(const std::set<unsigned int>&);
			void append(const query_result&);
			void set_metadata(const unsigned int, const char**);
	};
#endif
