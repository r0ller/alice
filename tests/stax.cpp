#include <iostream>
#include <Python.h>
#include "logger.cpp"
#include "db.h"
#include "query_result.cpp"

int main(int argc, char* argv[]){

	db *sqlite=NULL;
	query_result *grammar_rules=NULL;
	std::string db_file, path, base, grammar, lid, prev_parent_symbol, start_rule, arglimit, nltk_import_grammar, nltk_generate_sentence;
	int limit=0;

	if(argc<4){
		std::cerr<<"Usage: stax /path/to/dbfile.db <language id> <sentence nr limit>n|<tree_depth>d"<<std::endl;
		exit(EXIT_FAILURE);
	}
	else{
		db_file=argv[1];
		if(db_file.empty()==true) exit(EXIT_FAILURE);
		else{
			std::size_t base_end=db_file.find_last_of("/");
			if(base_end==std::string::npos) exit(EXIT_FAILURE);
			path=db_file.substr(0,base_end);
			std::size_t base_start=path.find_last_of("/");
			base=path.substr(base_start+1);
			if(path.empty()==true||base.empty()==true) exit(EXIT_FAILURE);
		}
		lid=argv[2];
		arglimit=argv[3];
		if(arglimit.back()!='n'&&arglimit.back()!='d') exit(EXIT_FAILURE);
		limit=std::atoi(arglimit.c_str());
		if(limit<=0) exit(EXIT_FAILURE);
	}
	logger::singleton("console",0,"LE");
	sqlite=db_factory::get_instance();
	sqlite->open(db_file);
	grammar_rules=sqlite->exec_sql("SELECT PARENT_SYMBOL, HEAD_SYMBOL, NON_HEAD_SYMBOL FROM GRAMMAR WHERE LID = '"+lid+"' ORDER BY PARENT_SYMBOL;");
	if(grammar_rules==NULL){
		std::cerr<<"No syntax rules found in grammar db table."<<std::endl;
		exit(EXIT_FAILURE);
	}
	unsigned int nr_of_rules=grammar_rules->nr_of_result_rows();
	for(unsigned int i=0;i<nr_of_rules;++i){
		std::string parent_symbol=*grammar_rules->field_value_at_row_position(i,"parent_symbol");
		std::string head_symbol=*grammar_rules->field_value_at_row_position(i,"head_symbol");
		if(head_symbol.find("t_")==0)head_symbol="\""+head_symbol+"\"";
		std::string non_head_symbol=*grammar_rules->field_value_at_row_position(i,"non_head_symbol");
		if(head_symbol.find("t_")==0)non_head_symbol="\""+non_head_symbol+"\"";
		if(parent_symbol=="S"){
			if(non_head_symbol.empty()==false){
				if(parent_symbol!=prev_parent_symbol){
					if(prev_parent_symbol.empty()==true){
						start_rule+=parent_symbol+" -> "+head_symbol+" "+non_head_symbol;
					}
					else{
						start_rule+="\n"+parent_symbol+" -> "+head_symbol+" "+non_head_symbol;
					}
				}
				else{
					start_rule+=" | "+head_symbol+" "+non_head_symbol;
				}
			}
			else{
				if(parent_symbol!=prev_parent_symbol){
					if(prev_parent_symbol.empty()==true){
						start_rule+=parent_symbol+" -> "+head_symbol;
					}
					else{
						start_rule+="\n"+parent_symbol+" -> "+head_symbol;
					}
				}
				else{
					start_rule+=" | "+head_symbol;
				}
			}
		}
		else{
			if(non_head_symbol.empty()==false){
				if(parent_symbol!=prev_parent_symbol){
					if(prev_parent_symbol.empty()==true){
						grammar+=parent_symbol+" -> "+head_symbol+" "+non_head_symbol;
					}
					else{
						grammar+="\n"+parent_symbol+" -> "+head_symbol+" "+non_head_symbol;
					}
				}
				else{
					grammar+=" | "+head_symbol+" "+non_head_symbol;
				}
			}
			else{
				if(parent_symbol!=prev_parent_symbol){
					if(prev_parent_symbol.empty()==true){
						grammar+=parent_symbol+" -> "+head_symbol;
					}
					else{
						grammar+="\n"+parent_symbol+" -> "+head_symbol;
					}
				}
				else{
					grammar+=" | "+head_symbol;
				}
			}
		}
		prev_parent_symbol=parent_symbol;
	}
	grammar=start_rule+"\n"+grammar+"\n";
//	std::cout<<grammar<<std::endl;
	Py_SetProgramName(argv[0]);
	Py_Initialize();
    PyRun_SimpleString("from nltk.parse.generate import generate\n");
	PyRun_SimpleString("from nltk import CFG\n");
	nltk_import_grammar="grammar = CFG.fromstring(\"\"\""+grammar+"\"\"\")\n";
	PyRun_SimpleString(nltk_import_grammar.c_str());
//	PyRun_SimpleString("print(grammar)\n");
	if(arglimit.back()=='n'){
		nltk_generate_sentence="for sentence in generate(grammar, n="+std::to_string(limit)+"): print(' '.join(sentence))\n";
	}
	else if(arglimit.back()=='d'){
		nltk_generate_sentence="for sentence in generate(grammar, depth="+std::to_string(limit)+"): print(' '.join(sentence))\n";
	}
	else exit(EXIT_FAILURE);
	PyRun_SimpleString(nltk_generate_sentence.c_str());
	Py_Finalize();
	sqlite->close();
	db_factory::delete_instance();
	sqlite=NULL;
	return 0;
}
