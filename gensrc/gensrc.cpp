#include <fstream>
#include <sstream>
#include <iostream>
#include "query_result.cpp"
#include "db.cpp"

int main(){

	std::string C_declarations, bison_declarations, grammar, C_code, parent_symbol, head_symbol, non_head_symbol, action;
	std::string gcat, feature, lid, token, prev_parent_symbol, combine_nodes, set_node, bison_source;
	std::stringstream *stringstream=NULL;
	std::ifstream *filestream=NULL;
	db *sqlite=NULL;
	query_result *grammar_rules=NULL, *tokens=NULL, *symbols=NULL;

	filestream=new std::ifstream("C_declarations.cpp");
	if(filestream!=NULL){
		stringstream=new std::stringstream();
		*stringstream<<filestream->rdbuf();
		C_declarations=stringstream->str();
		//std::cout<<C_declarations<<std::endl;
		filestream->close();
		delete filestream;
		delete stringstream;
	}
	filestream=new std::ifstream("bison_declarations.cpp");
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
	filestream=new std::ifstream("C_code.cpp");
	if(filestream!=NULL){
		stringstream=new std::stringstream();
		*stringstream<<filestream->rdbuf();
		C_code=stringstream->str();
		//std::cout<<C_code<<std::endl;
		filestream->close();
		delete filestream;
		delete stringstream;
	}
	filestream=new std::ifstream("C_code.cpp");
	if(filestream!=NULL){
		stringstream=new std::stringstream();
		*stringstream<<filestream->rdbuf();
		C_code=stringstream->str();
		//std::cout<<C_code<<std::endl;
		filestream->close();
		delete filestream;
		delete stringstream;
	}
	filestream=new std::ifstream("combine_nodes.cpp");
	if(filestream!=NULL){
		stringstream=new std::stringstream();
		*stringstream<<filestream->rdbuf();
		combine_nodes=stringstream->str();
		//std::cout<<combine_nodes<<std::endl;
		filestream->close();
		delete filestream;
		delete stringstream;
	}
	filestream=new std::ifstream("set_node.cpp");
	if(filestream!=NULL){
		stringstream=new std::stringstream();
		*stringstream<<filestream->rdbuf();
		set_node=stringstream->str();
		//std::cout<<set_node<<std::endl;
		filestream->close();
		delete filestream;
		delete stringstream;
	}
	sqlite=db::get_instance();
	sqlite->open("hi.db");
	tokens=sqlite->exec_sql("SELECT * FROM GCAT WHERE TOKEN IS NOT NULL ORDER BY LID, TOKEN;");
	for(unsigned int i=0;i<tokens->nr_of_result_rows();++i){
		//TODO: -increase token value by 1 in the bison source
		//-figure out what to do with "CON", currently t_ENG_CON is generated
		gcat=*tokens->field_value_at_row_position(i,"gcat");
		feature=*tokens->field_value_at_row_position(i,"feature");
		lid=*tokens->field_value_at_row_position(i,"lid");
		token=*tokens->field_value_at_row_position(i,"token");
		if(feature.empty()==true){
			bison_declarations+="%token\tt_"+lid+"_"+gcat+" "+token+"\n";
		}
		else{
			bison_declarations+="%token\tt_"+lid+"_"+gcat+"_"+feature+" "+token+"\n";
		}
	}
	grammar_rules=sqlite->exec_sql("SELECT * FROM GRAMMAR ORDER BY PARENT_SYMBOL;");
	grammar="%%";
	for(unsigned int i=0;i<grammar_rules->nr_of_result_rows();++i){
		parent_symbol=*grammar_rules->field_value_at_row_position(i,"parent_symbol");
		head_symbol=*grammar_rules->field_value_at_row_position(i,"head_symbol");
		non_head_symbol=*grammar_rules->field_value_at_row_position(i,"non_head_symbol");
		action=*grammar_rules->field_value_at_row_position(i,"action");
		if(action.empty()==true){
			if(head_symbol.empty()==false&&non_head_symbol.empty()==false){
				action="\t\t\t\tconst node_info& "+head_symbol+"=sparser->get_node_info($1);\n"
				"\t\t\t\tconst node_info& "+non_head_symbol+"=sparser->get_node_info($2);\n"
				"\t\t\t\t$$=sparser->combine_nodes(\""+parent_symbol+"\","+head_symbol+","+non_head_symbol+");\n"
				"\t\t\t\tstd::cout<<\""+parent_symbol+"->"+head_symbol+" "+non_head_symbol+"\"<<std::endl;\n";
			}
			else if(head_symbol.empty()==false&&non_head_symbol.empty()==true){
				symbols=sqlite->exec_sql("SELECT * FROM SYMBOLS WHERE SYMBOL = '"+head_symbol+"';");
				if(symbols!=NULL){//non-terminal
					//TODO: figure out what shall be generated in case of the last rule leading to S
					delete symbols;
					action="\t\t\t\tlexicon word;\n"
					"\t\t\t\tconst node_info& "+head_symbol+"=sparser->get_node_info($1);\n"
					"\t\t\t\tword.gcat=\""+head_symbol+"\";\n"
					"\t\t\t\t$$=sparser->set_node_info(word,"+head_symbol+");\n"
					"\t\t\t\tstd::cout<<\""+parent_symbol+"->"+head_symbol+"\"<<std::endl;\n";
				}
				else{//terminal
					action="\t\t\t\tlexicon word;\n"
					"\t\t\t\tconst node_info& empty_node_info={};\n"
					"\t\t\t\tword=lex->last_word_scanned("+head_symbol+");\n"
					"\t\t\t\t$$=sparser->set_node_info(word,empty_node_info);\n"
					"\t\t\t\tstd::cout<<word.gcat<<\"->\"<<word.lexeme<<std::endl;\n";
				}
			}
			else{
				exit(EXIT_FAILURE);
			}
		}
		else{
			if(action.front()!='\"'){
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
				grammar+="\n"+parent_symbol+"\t:\t"+head_symbol+" "+non_head_symbol+"\n{\n"+action+"\n}";
			}
			else{
				grammar+=";\n"+parent_symbol+"\t:\t"+head_symbol+" "+non_head_symbol+"\n{\n"+action+"\n}";
			}
			prev_parent_symbol=parent_symbol;
		}
		else{
			grammar+="\n\t|\t"+head_symbol+" "+non_head_symbol+"\n{\n"+action+"\n}";
		}
	}
	grammar+=";\n%%\n";
	delete tokens;
	delete grammar_rules;
	sqlite->close();
	delete sqlite;
	bison_source=C_declarations+bison_declarations+grammar+C_code;
	std::cout<<bison_source<<std::endl;
	return 0;
}
