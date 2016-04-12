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
		public:
			morphan_result(const std::string&, const std::vector<std::string>&);
			~morphan_result();
			const std::string& word() const;
			const std::string& stem() const;
			const std::string& gcat() const;
			const std::vector<std::string>& morphemes() const;
			bool has_feature(const std::string) const;
			void add_feature(const std::string&);
			const std::set<std::string>& lfeas() const;
			//prefix();
			//suffix();
			//infix();
	};
#endif
