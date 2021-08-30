#ifndef MORPHAN_RESULT_H
	#define MORPHAN_RESULT_H

	#include <string>
	#include <vector>
	#include <set>

	class morphan_result{
		private:
			std::string word_stem;
			std::string word_gcat;
			std::vector<std::string> word_morphemes;
			std::string word_form;
			std::set<std::string> features;
			bool erroneous=false;
			static unsigned int global_id;//TODO:figure out when to reset or change it to instance level
			unsigned int my_id;
			std::string lid;
		public:
			morphan_result(const std::string&, const std::vector<std::string>&, const std::string&);
            morphan_result(const std::string&, const std::string&, const std::string&);
			~morphan_result();
			const unsigned int& id() const;
			const std::string& word() const;
			const std::string& stem() const;
			const std::string& gcat() const;
			const std::vector<std::string>& morphemes() const;
			bool has_feature(const std::string) const;
			void add_feature(const std::string&);
			const std::set<std::string>& lfeas() const;
			bool is_erroneous() const;
			bool is_mocked() const;
			//prefix();
			//suffix();
			//infix();
	};

	class morphan_error:public std::exception{
		public:
			virtual const char *what() const throw(){
				return "Error while processing morphological analysis\n";
			}
	};
#endif
