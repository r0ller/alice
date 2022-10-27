#ifndef MORPHAN_RESULT_H
	#define MORPHAN_RESULT_H

	#include <string>
	#include <vector>
	#include <set>
    #include <map>

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
            static std::map<unsigned int,std::string> global_features_;
            std::map<unsigned int,std::string> global_features_copy_;
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
            static void add_global_feature(const unsigned int node_id,const std::string& feature){
                global_features_.insert(std::make_pair(node_id,feature));
            }
            std::map<unsigned int,std::string> global_features_copy();
            static std::map<unsigned int,std::string> global_features(){
                return global_features_;
            }
            static void clear_global_features(){
                global_features_.clear();
            }
            void copy_global_features();
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
