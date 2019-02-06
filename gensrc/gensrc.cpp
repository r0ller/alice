#include <fstream>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <utility>
#include "logger.cpp"
#include "db.h"
#include "query_result.cpp"

int main(int argc, char* argv[]){

	std::string C_declarations, bison_declarations, grammar, C_code, parent_symbol, head_symbol, non_head_symbol,
	action, definition, functor_id, tlid, imp_counter, terminal;
	std::string gcat, feature, lid, token, prev_parent_symbol, combine_nodes, set_node, bison_source, db_file,
	path, base, lid_list, snippetsdir, output, functor_defs_dir, precedence_level, precedence, tokenmapcode, symbolmapcode;
	std::stringstream *stringstream=NULL;
	std::ifstream *filestream=NULL;
	std::ofstream *bison_file=NULL,*tokensymbol_file=NULL;
	db *sqlite=NULL;
	query_result *grammar_rules=NULL, *tokens=NULL, *functor_defs=NULL, *precedences=NULL;
	std::set<std::string> lids,terminals;
	std::multimap<std::pair<std::string,unsigned int>,std::string> precedence_order;

	try{
		logger::singleton("console",0,"LE");
		//TODO: as 3-4 are optional it may happen that in case of having only 3 args, the 3rd is either the output file path or the funtcor path
		//In such a case check if the 3rd arg is an existing path, if yes then it's meant to be functor path, otherwise take it as output file path
		if(argc<3){
			std::cerr<<"Usage: gensrc /path/to/dbfile.db /path/to/bison/files/and/grammar/action/snippets [/path/with/output/file/name] [/path/to/functor/definitions]"<<std::endl;
			exit(EXIT_FAILURE);
		}
		else{
			db_file=argv[1];
			snippetsdir=argv[2];
			if(snippetsdir.back()!='/') snippetsdir+='/';
			if(argc>3){
				output=argv[3];
				if(db_file.empty()==true||output.empty()==true||snippetsdir.empty()==true) return 1;
			}
//			else{
				std::size_t base_end=db_file.find_last_of("/");
				if(base_end==std::string::npos) return 1;
				path=db_file.substr(0,base_end);
				std::size_t base_start=path.find_last_of("/");
				base=path.substr(base_start+1);
				if(db_file.empty()==true||path.empty()==true||base.empty()==true||snippetsdir.empty()==true) return 1;
//			}
			if(argc>4){
				functor_defs_dir=argv[4];
				if(functor_defs_dir.back()!='/') functor_defs_dir+='/';
			}
		}
		filestream=new std::ifstream(snippetsdir+"C_declarations.cpp");
		if(filestream!=NULL){
			stringstream=new std::stringstream();
			*stringstream<<filestream->rdbuf();
			C_declarations=stringstream->str();
			//std::cout<<C_declarations<<std::endl;
			filestream->close();
			delete filestream;
			delete stringstream;
		}
		filestream=new std::ifstream(snippetsdir+"bison_declarations.cpp");
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
		filestream=new std::ifstream(snippetsdir+"C_code.cpp");
		if(filestream!=NULL){
			stringstream=new std::stringstream();
			*stringstream<<filestream->rdbuf();
			C_code=stringstream->str();
			//std::cout<<C_code<<std::endl;
			filestream->close();
			delete filestream;
			delete stringstream;
		}
		filestream=new std::ifstream(snippetsdir+"combine_nodes.cpp");
		if(filestream!=NULL){
			stringstream=new std::stringstream();
			*stringstream<<filestream->rdbuf();
			combine_nodes=stringstream->str();
			//std::cout<<combine_nodes<<std::endl;
			filestream->close();
			delete filestream;
			delete stringstream;
		}
		filestream=new std::ifstream(snippetsdir+"set_node.cpp");
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
		precedences=sqlite->exec_sql("SELECT * FROM PRECEDENCES;");
		tokenmapcode="#include <map>\n#include <string>\nstd::map<std::string, unsigned int> symbol_token_map={";
		symbolmapcode="\nstd::map<unsigned int,std::string> token_symbol_map={";
		for(unsigned int i=0;i<tokens->nr_of_result_rows();++i){
			gcat=*tokens->field_value_at_row_position(i,"gcat");
			feature=*tokens->field_value_at_row_position(i,"feature");
			lid=*tokens->field_value_at_row_position(i,"lid");
			lids.insert(lid);
			token=*tokens->field_value_at_row_position(i,"token");
			if(tokens->field_value_at_row_position(i,"precedence")->empty()==false){
				precedence_level=*tokens->field_value_at_row_position(i,"precedence_level");
				if(precedence_level.empty()==true) precedence_level="0";
				auto precedence_field=*precedences->first_value_for_field_name_found("precedence",*tokens->field_value_at_row_position(i,"precedence"));
				precedence=*precedences->field_value_at_row_position(precedence_field.first,"declaration");
			}
			else precedence.clear();
			unsigned int itoken=std::atoi(token.c_str());
			if(itoken>0){
				if(feature.empty()==true){
					terminal="t_"+lid+"_"+gcat;
					bison_declarations+="%token\tt_"+lid+"_"+gcat+"\n";
					terminals.insert(terminal);
				}
				else{
					terminal="t_"+lid+"_"+gcat+"_"+feature;
					bison_declarations+="%token\tt_"+lid+"_"+gcat+"_"+feature+"\n";
					terminals.insert(terminal);
				}
				if(precedence.empty()==false) precedence_order.insert(std::make_pair(std::make_pair(precedence,std::atoi(precedence_level.c_str())),terminal));
				tokenmapcode+="\n{\""+terminal+"\",yy::parser::token::"+terminal+"},";
				symbolmapcode+="\n{yy::parser::token::"+terminal+",\""+terminal+"\"},";
			}
		}
		if(tokenmapcode.back()==',') tokenmapcode.pop_back();
		tokenmapcode+="\n};\n";
		if(symbolmapcode.back()==',') symbolmapcode.pop_back();
		symbolmapcode+="\n};\n";
		precedence.clear();
		precedence_level.clear();
		std::set<std::string> precedences_declared;
		for(auto&& precedence_entry:precedence_order){
			if(precedences_declared.find(precedence_entry.second)==precedences_declared.end()){
				if(precedence_entry.first.first==precedence){
					if(std::to_string(precedence_entry.first.second)==precedence_level){
						bison_declarations+=" "+precedence_entry.second;
						precedences_declared.insert(precedence_entry.second);
					}
					else{
						bison_declarations+="\n"+precedence_entry.first.first+" "+precedence_entry.second;
						precedence_level=std::to_string(precedence_entry.first.second);
						precedences_declared.insert(precedence_entry.second);
					}
				}
				else{
					bison_declarations+="\n"+precedence_entry.first.first+" "+precedence_entry.second;
					precedence=precedence_entry.first.first;
					precedence_level=std::to_string(precedence_entry.first.second);
					precedences_declared.insert(precedence_entry.second);
				}
			}
		}
		if(precedence_order.empty()==false) bison_declarations+="\n";
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
			precedence=*grammar_rules->field_value_at_row_position(i,"precedence");
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
					"logger::singleton()==NULL?(void)0:logger::singleton()->log(0,\""+parent_symbol+"->"+head_symbol+" "+non_head_symbol+"\");\n"
					"$$=sparser->combine_nodes(\""+parent_symbol+"\","+head_symbol_var+","+non_head_symbol_var+");\n";
				}
				else if(head_symbol.empty()==false&&non_head_symbol.empty()==true){
					if(terminals.find(head_symbol)==terminals.end()){//non-terminal
						action="const node_info& "+head_symbol+"=sparser->get_node_info($1);\n"
						"logger::singleton()==NULL?(void)0:logger::singleton()->log(0,\""+parent_symbol+"->"+head_symbol+"\");\n"
						"$$=sparser->set_node_info(\""+parent_symbol+"\","+head_symbol+");\n";
					}
					else{//terminal
						action="lexicon word;\n"
						"word=lex->last_word_scanned(token::"+head_symbol+");\n"
						"logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+\"->\"+word.lexeme);\n"
						"$$=sparser->set_node_info(\""+parent_symbol+"\",word);\n";
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
					filestream=new std::ifstream(snippetsdir+action);
					if(filestream!=NULL){
						stringstream=new std::stringstream();
						*stringstream<<filestream->rdbuf();
						action=stringstream->str();
						filestream->close();
						delete filestream;
						delete stringstream;
						std::string::size_type pos=action.find('\'');
						while(pos!=std::string::npos){
							action.insert(pos,1,'\'');
							pos=pos+2;
							pos=action.find('\'',pos);
						}
					}
					else{
						logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"Could not read file "+action);
					}
				}
			}
			if(prev_parent_symbol!=parent_symbol){
				if(prev_parent_symbol.empty()==true){
					if(precedence.empty()==true) grammar+="\n"+parent_symbol+":\n"+head_symbol+" "+non_head_symbol+"\n{\n"+action+"\n}";
					else grammar+="\n"+parent_symbol+":\n"+head_symbol+" "+non_head_symbol+" %prec "+precedence+"\n{\n"+action+"\n}";
				}
				else{
					if(precedence.empty()==true) grammar+=";\n"+parent_symbol+":\n"+head_symbol+" "+non_head_symbol+"\n{\n"+action+"\n}";
					else grammar+=";\n"+parent_symbol+":\n"+head_symbol+" "+non_head_symbol+" %prec "+precedence+"\n{\n"+action+"\n}";
				}
				prev_parent_symbol=parent_symbol;
			}
			else{
				if(precedence.empty()==true) grammar+="\n|"+head_symbol+" "+non_head_symbol+"\n{\n"+action+"\n}";
				else grammar+="\n|"+head_symbol+" "+non_head_symbol+" %prec "+precedence+"\n{\n"+action+"\n}";
			}
		}
		grammar+=";\n%%\n";
		delete tokens;
		delete grammar_rules;
		if(functor_defs_dir.empty()==false){
			functor_defs=sqlite->exec_sql("SELECT * FROM FUNCTOR_DEFS;");
			for(unsigned int i=0;i<functor_defs->nr_of_result_rows();++i){
				functor_id=*functor_defs->field_value_at_row_position(i,"functor_id");
				tlid=*functor_defs->field_value_at_row_position(i,"tlid");
				imp_counter=*functor_defs->field_value_at_row_position(i,"imp_counter");
				definition=*functor_defs->field_value_at_row_position(i,"definition");
				if(definition.empty()==false&&definition.front()=='\"'){
					definition.erase(definition.begin());
					if(definition.back()=='\"') definition.pop_back();
					sqlite->exec_sql("UPDATE FUNCTOR_DEFS SET DEFINITION = '"+definition+"' WHERE FUNCTOR_ID = '"+functor_id+"' AND TLID = '"+tlid+"' AND IMP_COUNTER = '"+imp_counter+"';");
				}
				else if(definition.empty()==false&&definition.front()!='\"'){
					filestream=new std::ifstream(functor_defs_dir+definition);
					logger::singleton()==NULL?(void)0:logger::singleton()->log(2,"reading file "+functor_defs_dir+definition);
					if(filestream!=NULL){
						stringstream=new std::stringstream();
						*stringstream<<filestream->rdbuf();
						definition=stringstream->str();
						filestream->close();
						delete filestream;
						delete stringstream;
						std::string::size_type pos=definition.find('\'');
						while(pos!=std::string::npos){
							definition.insert(pos,1,'\'');
							pos=pos+2;
							pos=definition.find('\'',pos);
						}
						sqlite->exec_sql("UPDATE FUNCTOR_DEFS SET DEFINITION = '"+definition+"' WHERE FUNCTOR_ID = '"+functor_id+"' AND TLID = '"+tlid+"' AND IMP_COUNTER = '"+imp_counter+"';");
					}
					else{
						logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"Could not read file "+functor_defs_dir+definition);
					}
				}
			}

		}
		sqlite->close();
		db_factory::delete_instance();
		sqlite=NULL;
		if(tokenmapcode.empty()==false&&symbolmapcode.empty()==false){
			tokensymbol_file=new std::ofstream(path+"/tokensymbols.h");
			*tokensymbol_file << tokenmapcode << symbolmapcode;
			tokensymbol_file->close();
			delete tokensymbol_file;
		}
		bison_source="%code{\n#include \"tokensymbols.h\"\n}\n"+C_declarations+bison_declarations+grammar+C_code;
		if(output.empty()==false){
			bison_file=new std::ofstream(output);
		}
		else{
			bison_file=new std::ofstream(path+"/"+base+".y");
		}
		*bison_file << bison_source;
		bison_file->close();
		delete bison_file;
		//std::cout<<bison_source<<std::endl;
	}
	catch (std::exception& exception){
		logger::singleton()==NULL?(void)0:logger::singleton()->log(2,"runtime error:"+std::string(exception.what()));
		exit(EXIT_FAILURE);
	}
	catch (...){
		logger::singleton()==NULL?(void)0:logger::singleton()->log(2,"unexpected error ...");
		exit(EXIT_FAILURE);
	}
	return 0;
}
