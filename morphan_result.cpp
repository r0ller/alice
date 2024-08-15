#include "logger.h"
#include "morphan_result.h"
#include "query_result.h"
#include "db_factory.h"

unsigned int morphan_result::global_id=0;
std::map<unsigned int,std::string> morphan_result::global_features_;
std::map<unsigned int,std::pair<unsigned int,std::string>> morphan_result::features_to_inherit_;

/*PUBLIC*/
morphan_result::morphan_result(const std::string& word, const std::string& lid, const std::string& gcat=""){

	this->lid=lid;
	my_id=++morphan_result::global_id;
	word_form=word;
	word_stem=word;
	if(gcat.empty()==true) word_gcat="CON";
	else word_gcat=gcat;
	node_id_=0;
}

morphan_result::morphan_result(const morphan_result& source){
	word_stem=source.word_stem;
	word_gcat=source.word_gcat;
	word_morphemes=source.word_morphemes;
	word_form=source.word_form;
	features=source.features;
	erroneous=source.erroneous;
	my_id=source.my_id;
	lid=source.lid;
	global_features_copy_=source.global_features_copy_;
	features_to_inherit_copy_=source.features_to_inherit_copy_;
	node_id_=0;
}

morphan_result::morphan_result(const std::string& word, const std::vector<std::string>& morphemes, const std::string& lid){
	unsigned int nr_of_morphemes=0,i;
	size_t hit=0;
	query_result *gcat_with_lingfeas=NULL,*gcats=NULL;
	db *sqlite=NULL;
	const std::pair<const unsigned int,field> *field;

	this->lid=lid;
	my_id=++morphan_result::global_id;
	word_form=word;
	word_morphemes=morphemes;
	nr_of_morphemes=morphemes.size();
	node_id_=0;
	sqlite=db_factory::get_instance();
	gcats=sqlite->exec_sql("SELECT DISTINCT GCAT FROM GCAT WHERE LID = '"+lid+"';");
	if(gcats==NULL){
		throw std::runtime_error("GCAT db table is empty.");
	}
	for(i=0;i<nr_of_morphemes;++i){
		hit=morphemes[i].find("[stem]");
		if(hit!=std::string::npos&&word_stem.empty()==true){
			word_stem=morphemes[i].substr(0,hit);//the algorithm is based on the assumption that [...] tags are added as suffixes
		}
		else if(hit!=std::string::npos&&word_stem.empty()==false){
			logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"erroneous morphan: more than one [stem] tag found");
			erroneous=true;
		}
		else{
			if(gcats->first_value_for_field_name_found("gcat",morphemes[i])!=NULL){
				if(gcat_with_lingfeas!=NULL){
					logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"erroneous morphan: more than one gcat found");
					erroneous=true;
				}
				else{
					gcat_with_lingfeas=sqlite->exec_sql("SELECT * FROM GCAT WHERE GCAT = '"+morphemes[i]+"' AND LID = '"+lid+"';");
					if(gcat_with_lingfeas==NULL){
						logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"erroneous morphan: no gcat entries found for "+morphemes[i]);
						erroneous=true;
					}
					word_gcat=morphemes[i];
				}
			}
			else{
				features.insert(morphemes[i]);
			}
		}
	}
	if(gcat_with_lingfeas!=NULL){
		if(word_stem.empty()==false){
			field=gcat_with_lingfeas->first_value_for_field_name_found("feature","Stem");
			if(field==NULL){
				field=gcat_with_lingfeas->first_value_for_field_name_found("feature","");//Will SQLite3 find the empty string as value???
					if(field==NULL){
						logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"erroneous morphan: no Stem is defined for gcat "+word_gcat+" in GCAT db table.");
						erroneous=true;
					}
			}
		}
		else{
			logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"erroneous morphan: no stem found");
			erroneous=true;
		}
		for(auto feature=features.begin();feature!=features.end();){
			if(gcat_with_lingfeas->first_value_for_field_name_found("feature",*feature)!=NULL){
				++feature;
			}
			else{
				feature=features.erase(feature);
			}
		}
	}
	else{
		logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"erroneous morphan: no gcat entries found");
		erroneous=true;
	}
	delete gcats;
	delete gcat_with_lingfeas;
}

morphan_result::~morphan_result(){
	logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"destructing morphan result");
}

const unsigned int& morphan_result::id() const{
	return my_id;
}

const std::string& morphan_result::word() const{
	return word_form;
}

const std::string& morphan_result::stem() const{
	return word_stem;
}

const std::string& morphan_result::gcat() const{
	return word_gcat;
}

const std::vector<std::string>& morphan_result::morphemes() const{
	return word_morphemes;
}

bool morphan_result::has_feature(const std::string feature) const{
	return features.find(feature)==features.end()?false:true;
}

void morphan_result::add_feature(const std::string& feature){
	//TODO: verify feature in gcat db table to see if the feature belongs indeed to the gcat in question
	features.insert(feature);
}

const std::set<std::string>& morphan_result::lfeas() const{
	return features;
}

bool morphan_result::is_erroneous() const{
	return erroneous;
}

bool morphan_result::is_mocked() const{
	return word_morphemes.empty();
}

void morphan_result::copy_global_features(){
	global_features_copy_=global_features_;
}

std::map<unsigned int,std::string> morphan_result::global_features_copy(){
	return global_features_copy_;
}

void morphan_result::set_node_id(const unsigned int node_id){
	if(node_id_==0) node_id_=node_id;
}

unsigned int morphan_result::node_id(){
	return node_id_;
}

std::pair<unsigned int,std::string> morphan_result::find_feature_to_inherit(const unsigned int node_id){
	std::pair<unsigned int,std::string> parent_node_feature={0,""};

	auto&& i_parent_node_feature=features_to_inherit_copy_.find(node_id);
	if(i_parent_node_feature!=features_to_inherit_copy_.end()) parent_node_feature=i_parent_node_feature->second;
	return parent_node_feature;
}

void morphan_result::copy_features_to_inherit(){
	features_to_inherit_copy_=features_to_inherit_;
}

std::string morphan_result::suffixed_id() const{
	return std::to_string(my_id)+"_"+std::to_string(node_id_);
}