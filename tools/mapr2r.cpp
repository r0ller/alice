#include <iostream>
#include <fstream>
#include "logger.h"
#include "hilib.h"
#include "db_factory.h"
#include <algorithm>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "query_result.h"
#include "sp.h"
#include "lexer.h"

void map_rule_to_rule(std::string& sentence, std::string& lid, std::string& db_file, unsigned int toa){
	const char *analyses=hi(sentence.c_str(),lid.c_str(),toa,"js",db_file.c_str(),"test",0);
	if(analyses!=NULL){
		rapidjson::Document jsondoc;
		jsondoc.Parse(analyses);
		if(jsondoc.HasMember("analyses")==true){
			rapidjson::Value& analysesArray = jsondoc["analyses"];
			if(analysesArray.IsArray()==true&&analysesArray.Size()>0){
				rapidjson::StringBuffer buffer;
				rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
				analysesArray[0].Accept(writer);
				auto analysis=analysesArray[0].GetObject();//analyses are ranked, the first is the best
				std::cout<<"analysis:\n"<<buffer.GetString()<<std::endl;
				rapidjson::Value& morphology=analysis["morphology"];
				if(analysis.HasMember("syntax")==true){
					rapidjson::Value& syntax=analysis["syntax"];
					auto rootSyntaxObject=syntax[0].GetObject();
					db *sqlite=NULL;
					sqlite=db_factory::get_instance();
					sqlite->open(db_file);
					//TODO:
					//-loop over the words in morphology (warn in the end about words entered in lexicon but not having been processed; warn only as they and their dependencies may have the same gcat which may have already been covered)
					//-find a corresponding entry in depolex via lexeme
					//-take the dependencies of the entry
					//-loop over the dependencies and check if a dependency exists in the morphological analysis
					//-if yes, find a root node in the syntax tree for the dependency and the main lexeme
					//-create a rule_to_rule_map entry (checks need to be set up like if it already exists, etc.)
					time_t timestamp=time(nullptr);
					interpreter *sparser=new interpreter(toa,std::to_string(timestamp),NULL);
					std::map<unsigned int,unsigned int> context_node_id_to_new_node_id_map;
					std::set<std::string> lexemes_checked;
					unsigned int root_node_id=sparser->find_context_node_ids_for_syntax_node(lid,analysis,rootSyntaxObject,context_node_id_to_new_node_id_map);
					for(auto& word:morphology.GetArray()){
						query_result *lexicon_entries=NULL;
						std::string stem=word["stem"].GetString();
						std::string gcat=word["gcat"].GetString();
						lexicon_entries=sqlite->exec_sql("SELECT * FROM LEXICON WHERE word='"+stem+"' AND lid='"+lid+"' AND gcat='"+gcat+"';");
						std::string lexeme=gcat;//handle gcat based functors if no entry found for the word in lexicon
						if(lexicon_entries!=NULL){
							lexeme=*lexicon_entries->field_value_at_row_position(0,"lexeme");
							delete lexicon_entries;
						}
						//if a lexeme and its dependencies have already been checked in the parse tree, don't do it again
						if(lexemes_checked.find(lexeme)==lexemes_checked.end()){
							lexemes_checked.insert(lexeme);
							query_result *dependencies=NULL;
							dependencies=lexer::dependencies_read_for_functor(lexeme,true);
							if(dependencies!=NULL){
								unsigned int nr_of_dependencies=dependencies->nr_of_result_rows();
								for(unsigned int i=0;i<nr_of_dependencies;++i){
									std::string dependency=*dependencies->field_value_at_row_position(i,"semantic_dependency");
									if(dependency.empty()==false){
										auto subtree_roots=sparser->find_subtree_root_of(root_node_id,lexeme,dependency);
										for(auto subtree_root:subtree_roots){
											auto [lexeme_node_id,dependency_node_id]=subtree_root.first;
											auto [node_id,node_level,left_root_type,right_root_type]=subtree_root.second;
											node_info lexeme_node=sparser->get_node_info(lexeme_node_id);
											node_info dependency_node=sparser->get_node_info(dependency_node_id);
											node_info parent_node=sparser->get_node_info(node_id);
											node_info left_child=sparser->get_node_info(parent_node.left_child);
											node_info right_child=sparser->get_node_info(parent_node.right_child);
											//check (and don't insert) if the entry to be inserted already exists with the same content
											query_result *r2r_map_entries=sqlite->exec_sql("SELECT * FROM RULE_TO_RULE_MAP WHERE parent_symbol='"+parent_node.symbol+"' AND head_root_symbol='"+left_child.symbol+"' AND non_head_root_symbol='"+right_child.symbol+"' AND main_node_symbol='"+lexeme_node.expression.gcat+"' AND main_lookup_root='"+left_root_type+"' AND dependent_node_symbol='"+dependency_node.expression.gcat+"' AND dependency_lookup_root='"+right_root_type+"';");
											if(r2r_map_entries==NULL){
												query_result *r2r_map_entries=sqlite->exec_sql("SELECT * FROM RULE_TO_RULE_MAP WHERE parent_symbol='"+parent_node.symbol+"' AND head_root_symbol='"+left_child.symbol+"' AND non_head_root_symbol='"+right_child.symbol+"' ORDER BY step;");
												if(r2r_map_entries!=NULL){
													unsigned int nr_of_rows=r2r_map_entries->nr_of_result_rows();
													sqlite->exec_sql("UPDATE RULE_TO_RULE_MAP SET failover="+std::to_string(nr_of_rows+1)+", successor="+std::to_string(nr_of_rows+1)+" WHERE parent_symbol='"+parent_node.symbol+"' AND head_root_symbol='"+left_child.symbol+"' AND non_head_root_symbol='"+right_child.symbol+"' AND step="+std::to_string(nr_of_rows)+";");
													std::string insert_cmd="INSERT INTO RULE_TO_RULE_MAP VALUES('"+parent_node.symbol+"','"+left_child.symbol+"','"+right_child.symbol+"',"+std::to_string(nr_of_rows+1)+","+std::to_string(nr_of_rows+1)+",NULL,'"+lexeme_node.expression.gcat+"',NULL,'"+left_root_type+"',NULL,NULL,NULL,'"+dependency_node.expression.gcat+"',NULL,'"+right_root_type+"',NULL,NULL,NULL,'"+lid+"');";
													std::cout<<"For main lexeme "+lexeme+" and dependency "+dependency+", inserting semantic rule:"+insert_cmd+"\n";
													sqlite->exec_sql(insert_cmd);
													delete r2r_map_entries;
												}
												else{
													std::string insert_cmd="INSERT INTO RULE_TO_RULE_MAP VALUES('"+parent_node.symbol+"','"+left_child.symbol+"','"+right_child.symbol+"',1,1,NULL,'"+lexeme_node.expression.gcat+"',NULL,'"+left_root_type+"',NULL,NULL,NULL,'"+dependency_node.expression.gcat+"',NULL,'"+right_root_type+"',NULL,NULL,NULL,'"+lid+"');";
													std::cout<<"For main lexeme "+lexeme+" and dependency "+dependency+", inserting semantic rule:"+insert_cmd+"\n";
													sqlite->exec_sql(insert_cmd);
												}
											}
											else delete r2r_map_entries;
										}
									}
								}
								delete dependencies;
							}
						}
					}
					delete sparser;
					sparser=NULL;
					sqlite->close();
					db_factory::delete_instance();
					sqlite=NULL;
				}
			}
		}
	}
}

int main(int argc, char* argv[]){
	std::string db_file,lid,corpus_file,sentence;
	std::locale locale;
	std::ifstream *filestream=NULL;
	bool pun=false;
	char delimiter='\n';
	std::string nopun_list;

	logger::singleton("console",0,"LE");
	if(argc<6){
		std::cerr<<"Usage: mapr2r /path/to/dbfile.db /path/to/corpus <language id> pun|nopun -d<delimiter>"<<std::endl;
		exit(EXIT_FAILURE);
	}
	db_file=argv[1];
	corpus_file=argv[2];
	lid=argv[3];
	std::string pun_option=std::string(argv[4]);
	if(pun_option.substr(0,3)=="pun"){
		pun=true;
		if(pun_option.length()>3) nopun_list=pun_option.substr(3);
	}
	else if(pun_option=="nopun") pun=false;
	else{
		std::cerr<<"error: \""<<pun_option<<"\" is unknown option for punctuation"<<std::endl;
		exit(EXIT_FAILURE);
	}
	std::string delimiter_option=std::string(argv[5]);
	if(delimiter_option.length()==3&&delimiter_option.substr(0,2)=="-d"){
		delimiter=delimiter_option[2];
	}
	else if(delimiter_option=="-d"){
		delimiter='\n';//Nothing is passed in, set new line as default
	}
	else{
		std::cerr<<"error: \""<<delimiter_option<<"\" is unknown option for delimiter"<<std::endl;
		exit(EXIT_FAILURE);
	}
	filestream=new std::ifstream(corpus_file);
	if(filestream==NULL){
		exit(EXIT_FAILURE);
	}
	while(std::getline(*filestream,sentence,delimiter)){
		if(pun==true){
			if(std::ispunct(delimiter,std::locale())==true) sentence+=delimiter;
			locale=std::locale();
			auto i=sentence.begin();
			while(i!=sentence.end()){
				if(ispunct(*i,locale)==true&&nopun_list.find(*i)==std::string::npos){
					if(i!=sentence.begin()&&isspace(*(i-1),locale)==false){
						i=sentence.insert(i,' ');
						++i;
					}
					if(i!=sentence.end()&&i!=sentence.rbegin().base()&&isspace(*(i+1),locale)==false){
						++i;
						i=sentence.insert(i,' ');
					}
				}
				++i;
			}
		}
		else{
			auto new_end=remove_if(sentence.begin(),sentence.end(),[](char x){return std::ispunct(x,std::locale());});
			sentence.erase(new_end,sentence.end());
		}
		std::cout<<"analysing:"<<sentence<<std::endl;
		map_rule_to_rule(sentence,lid,db_file,HI_MORPHOLOGY|HI_SYNTAX|HI_LEO_SYNTAX);//TODO: make toa a cli option
	}
	filestream->close();
	delete filestream;
	std::cout<<"Done."<<std::endl;
	return 0;
}