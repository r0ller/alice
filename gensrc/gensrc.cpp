#include <fstream>
#include <sstream>
#include <iostream>
#include <set>
#include "db.h"
#include "query_result.cpp"

int main(int argc, char* argv[]){

	std::string C_declarations, bison_declarations, grammar, C_code, parent_symbol, head_symbol, non_head_symbol, action;
	std::string gcat, feature, lid, token, prev_parent_symbol, combine_nodes, set_node, bison_source, db_file, path, base, lid_list, snippetsdir, output;
	std::stringstream *stringstream=NULL;
	std::ifstream *filestream=NULL;
	std::ofstream *bison_file=NULL;
	db *sqlite=NULL;
	query_result *grammar_rules=NULL, *tokens=NULL, *symbols=NULL;
	std::set<std::string> lids;

	if(argc<3){
		std::cerr<<"Usage: gensrc /path/to/dbfile.db /path/to/snippets [/path/with/output/file/name]"<<std::endl;
		return 1;
	}
	else{
		db_file=argv[1];
		snippetsdir=argv[2];
		if(snippetsdir.back()=='/') snippetsdir.pop_back();
		if(argc==4){
			output=argv[3];
			if(db_file.empty()==true||output.empty()==true||snippetsdir.empty()==true) return 1;
		}
		else{
			std::size_t base_end=db_file.find_last_of("/");
			if(base_end==std::string::npos) return 1;
			path=db_file.substr(0,base_end);
			std::size_t base_start=path.find_last_of("/");
			base=path.substr(base_start+1);
			if(db_file.empty()==true||path.empty()==true||base.empty()==true||snippetsdir.empty()==true) return 1;
		}
	}
	filestream=new std::ifstream(snippetsdir+"/C_declarations.cpp");
	if(filestream!=NULL){
		stringstream=new std::stringstream();
		*stringstream<<filestream->rdbuf();
		C_declarations=stringstream->str();
		//std::cout<<C_declarations<<std::endl;
		filestream->close();
		delete filestream;
		delete stringstream;
	}
	filestream=new std::ifstream(snippetsdir+"/bison_declarations.cpp");
	if(filestream!=NULL){
		stringstream=new std::stringstream();
		*stringstream<<filestream->rdbuf();
		bison_declarations=stringstream->str();
		if(bison_declarations.back()!='\n') bison_declarations+="\n";
		//std::cout<<bison_declarations<<std::endl;
		filestream->close();
		delete filestream;
		delete stringstream;
	}
	filestream=new std::ifstream(snippetsdir+"/C_code.cpp");
	if(filestream!=NULL){
		stringstream=new std::stringstream();
		*stringstream<<filestream->rdbuf();
		C_code=stringstream->str();
		//std::cout<<C_code<<std::endl;
		filestream->close();
		delete filestream;
		delete stringstream;
	}
	filestream=new std::ifstream(snippetsdir+"/combine_nodes.cpp");
	if(filestream!=NULL){
		stringstream=new std::stringstream();
		*stringstream<<filestream->rdbuf();
		combine_nodes=stringstream->str();
		//std::cout<<combine_nodes<<std::endl;
		filestream->close();
		delete filestream;
		delete stringstream;
	}
	filestream=new std::ifstream(snippetsdir+"/set_node.cpp");
	if(filestream!=NULL){
		stringstream=new std::stringstream();
		*stringstream<<filestream->rdbuf();
		set_node=stringstream->str();
		//std::cout<<set_node<<std::endl;
		filestream->close();
		delete filestream;
		delete stringstream;
	}
	sqlite=db_factory::get_instance();
	sqlite->open(db_file);
	tokens=sqlite->exec_sql("SELECT * FROM GCAT ORDER BY LID, TOKEN;");
	for(unsigned int i=0;i<tokens->nr_of_result_rows();++i){
		gcat=*tokens->field_value_at_row_position(i,"gcat");
		feature=*tokens->field_value_at_row_position(i,"feature");
		lid=*tokens->field_value_at_row_position(i,"lid");
		lids.insert(lid);
		token=*tokens->field_value_at_row_position(i,"token");
		unsigned int itoken=std::atoi(token.c_str());
		if(itoken>0){
			//TODO: figure out what to do with "CON", with the current solution not t_Con but e.g. t_ENG_CON would be generated
			//Currently, "%token t_Con 1" is declared directly in bison_declarations.cpp
			token=std::to_string(itoken+1);
			if(feature.empty()==true){
				bison_declarations+="%token\tt_"+lid+"_"+gcat+" "+token+"\n";
			}
			else{
				bison_declarations+="%token\tt_"+lid+"_"+gcat+"_"+feature+" "+token+"\n";
			}
		}
	}
	lid_list="(";
	for(auto&& i:lids){
		lid_list+="'"+i+"',";
	}
	lid_list.pop_back();//remove last ','
	lid_list+=")";
	grammar_rules=sqlite->exec_sql("SELECT * FROM GRAMMAR WHERE LID IN "+lid_list+" ORDER BY PARENT_SYMBOL;");
	grammar="%%";
	for(unsigned int i=0;i<grammar_rules->nr_of_result_rows();++i){
		parent_symbol=*grammar_rules->field_value_at_row_position(i,"parent_symbol");
		head_symbol=*grammar_rules->field_value_at_row_position(i,"head_symbol");
		non_head_symbol=*grammar_rules->field_value_at_row_position(i,"non_head_symbol");
		action=*grammar_rules->field_value_at_row_position(i,"action");
		if(action.empty()==true){
			if(head_symbol.empty()==false&&non_head_symbol.empty()==false){
				std::string head_symbol_var;
				std::string non_head_symbol_var;
				if(head_symbol==non_head_symbol){
					head_symbol_var=head_symbol+"1";
					non_head_symbol_var=non_head_symbol+"2";
				}
				else{
					head_symbol_var=head_symbol;
					non_head_symbol_var=non_head_symbol;
				}
				action="const node_info& "+head_symbol_var+"=sparser->get_node_info($1);\n"
				"const node_info& "+non_head_symbol_var+"=sparser->get_node_info($2);\n"
				"$$=sparser->combine_nodes(\""+parent_symbol+"\","+head_symbol_var+","+non_head_symbol_var+");\n"
				//"std::cout<<\""+parent_symbol+"->"+head_symbol+" "+non_head_symbol+"\"<<std::endl;\n";
				"logger::singleton()->log(0,\""+parent_symbol+"->"+head_symbol+" "+non_head_symbol+"\");\n";
			}
			else if(head_symbol.empty()==false&&non_head_symbol.empty()==true){
				symbols=sqlite->exec_sql("SELECT * FROM SYMBOLS WHERE SYMBOL = '"+head_symbol+"';");
				if(symbols!=NULL){//non-terminal
					//TODO: figure out what shall be generated in case of the last rule leading to S
					//as currently it seems I always combine everything into a single VP node
					//and that VP leads to S but nothing happens in that rule.
					//Hopefully, I don't rely on that anywhere. Let's give it a try and check
					//if the interpeter is written well enough so that a properly generated code
					//won't blow it up:D
					//If yes, then the framework needs to be fixed, not the source generator here!
					delete symbols;
					action="lexicon word;\n"
					"const node_info& "+head_symbol+"=sparser->get_node_info($1);\n"
					"word.gcat=\""+parent_symbol+"\";\n"
					"$$=sparser->set_node_info(word,"+head_symbol+");\n"
					//"std::cout<<\""+parent_symbol+"->"+head_symbol+"\"<<std::endl;\n";
					"logger::singleton()->log(0,\""+parent_symbol+"->"+head_symbol+"\");\n";
				}
				else{//terminal
					action="lexicon word;\n"
					"const node_info& empty_node_info={};\n"
					"word=lex->last_word_scanned("+head_symbol+");\n"
					"$$=sparser->set_node_info(word,empty_node_info);\n"
					//"std::cout<<word.gcat<<\"->\"<<word.lexeme<<std::endl;\n";
					"logger::singleton()->log(0,word.gcat+\"->\"+word.lexeme);\n";
				}
			}
			else{
				exit(EXIT_FAILURE);
			}
		}
		else{
			if(action.front()=='\"'){
				action.erase(action.begin());
				if(action.back()=='\"') action.pop_back();
			}
			else{
				filestream=new std::ifstream(action);
				if(filestream!=NULL){
					stringstream=new std::stringstream();
					*stringstream<<filestream->rdbuf();
					action=stringstream->str();
					std::cout<<action<<std::endl;
					filestream->close();
					delete filestream;
					delete stringstream;
				}
				else{
					exit(EXIT_FAILURE);
				}
			}
		}
		if(prev_parent_symbol!=parent_symbol){
			if(prev_parent_symbol.empty()==true){
				grammar+="\n"+parent_symbol+":\n"+head_symbol+" "+non_head_symbol+"\n{\n"+action+"\n}";
			}
			else{
				grammar+=";\n"+parent_symbol+":\n"+head_symbol+" "+non_head_symbol+"\n{\n"+action+"\n}";
			}
			prev_parent_symbol=parent_symbol;
		}
		else{
			grammar+="\n|"+head_symbol+" "+non_head_symbol+"\n{\n"+action+"\n}";
		}
	}
	grammar+=";\n%%\n";
	delete tokens;
	delete grammar_rules;
	sqlite->close();
	db_factory::delete_instance();
	sqlite=NULL;
	bison_source=C_declarations+bison_declarations+grammar+C_code;
	if(output.empty()==false){
		bison_file=new std::ofstream(output);
	}
	else{
		bison_file=new std::ofstream(path+"/"+base+".y");
	}
	*bison_file << bison_source;
	bison_file->close();
	delete bison_file;
//	std::cout<<bison_source<<std::endl;
	return 0;
}
