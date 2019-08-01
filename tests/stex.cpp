#include <iostream>
#include <Python.h>
#include "logger.h"
#include "db_factory.h"
#include "query_result.h"
#include "morphan_result.h"
#include "morphan.h"
db *db_factory::singleton_instance=NULL;

int main(int argc, char* argv[]){

	db *sqlite=NULL;
	query_result *grammar_rules=NULL,*gcats_features=NULL,*lexicon=NULL;
	std::string db_file, path, base, grammar, lid, prev_parent_symbol, start_rule, arglimit, nltk_import_grammar,
	nltk_generate_sentence, words, gcats, terminal, feature, gcat, word, terminal_symbols;
	int limit=0;
	std::map<std::string,std::pair<std::string,std::string> > terminals_gcat_feature;
	std::multimap<std::string,std::string> gcats_words;
	std::set<std::string> word_set;
	unsigned int result_size;
	morphan *stemmer=NULL;
	std::map<std::string,std::vector<morphan_result> > word_analyses;
	std::set<std::pair<std::string,std::string> > gcat_lfeas;

	logger::singleton("console",0,"LE");
	if(argc<5){
		std::cerr<<"Usage: stex /path/to/dbfile.db <language id> <sentence nr limit>n|<tree_depth>d list,of,all,wordforms,to,be,generated"<<std::endl;
		exit(EXIT_FAILURE);
	}
	else{
		db_file=argv[1];
		if(db_file.empty()==true) exit(EXIT_FAILURE);
//		else{
//			std::size_t base_end=db_file.find_last_of("/");
//			if(base_end==std::string::npos) exit(EXIT_FAILURE);
//			path=db_file.substr(0,base_end);
//			std::size_t base_start=path.find_last_of("/");
//			base=path.substr(base_start+1);
//			if(path.empty()==true||base.empty()==true) exit(EXIT_FAILURE);
//		}
		lid=argv[2];
		arglimit=argv[3];
		if(arglimit.back()!='n'&&arglimit.back()!='d') exit(EXIT_FAILURE);
		limit=std::atoi(arglimit.c_str());
		if(limit<=0) exit(EXIT_FAILURE);
		words=argv[4];
		if(words.empty()==false){
			std::string::size_type comma_pos=words.find(',',0);
			if(comma_pos!=std::string::npos){
				std::string::size_type start_pos=0;
				while(comma_pos!=std::string::npos){
					std::string word_cut=words.substr(start_pos,comma_pos-start_pos);
					if(word_cut.empty()==false) word_set.insert(word_cut);
					start_pos=++comma_pos;
					comma_pos=words.find(',',comma_pos);
					if(comma_pos==std::string::npos){
						std::string word_cut=words.substr(start_pos,words.length()-start_pos);
						if(word_cut.empty()==false) word_set.insert(word_cut);
					}
				}
			}
			else{
				word_set.insert(words);
			}
		}
		else{
			exit(EXIT_FAILURE);
		}
	}
	logger::singleton("console",0,"LE");
	sqlite=db_factory::get_instance();
	sqlite->open(db_file);

	stemmer=morphan::get_instance(lid);
	for(auto&& i:word_set){
		std::vector<morphan_result> *word_analysis=stemmer->analyze(i,false);
		//word_analyses.insert(std::make_pair(word,*word_analysis));
		for(auto&& j:*word_analysis){
			gcat_lfeas.insert(std::make_pair(j.gcat(),"Stem"));
			gcat_lfeas.insert(std::make_pair(j.gcat(),""));
			if(gcats.find("'"+j.gcat()+"'")==std::string::npos) gcats+="'"+j.gcat()+"',";
//			std::cout<<"word: "<<i<<" gcat: "<<j.gcat()<<" feature: Stem/NULL"<<std::endl;
			for(auto&& k:j.lfeas()){
				gcat_lfeas.insert(std::make_pair(j.gcat(),k));
//				std::cout<<"word: "<<i<<" gcat: "<<j.gcat()<<" feature: "<<k<<std::endl;
			}
		}
		delete word_analysis;
	}
	gcats.pop_back();
	gcats_features=sqlite->exec_sql("SELECT GCAT, FEATURE FROM GCAT WHERE LID = '"+lid+"' AND GCAT IN ("+gcats+");");
	if(gcats_features==NULL){
		std::cerr<<"No gcats found for words in gcats db table."<<std::endl;
		exit(EXIT_FAILURE);
	}
	result_size=gcats_features->nr_of_result_rows();
	for(unsigned int i=0;i<result_size;++i){
		gcat=*gcats_features->field_value_at_row_position(i,"gcat");
		feature=*gcats_features->field_value_at_row_position(i,"feature");
		if(gcat_lfeas.find(std::make_pair(gcat,feature))!=gcat_lfeas.end()){
			if(feature.empty()==false){
				terminal="t_"+lid+"_"+gcat+"_"+feature;
			}
			else{
				terminal="t_"+lid+"_"+gcat;
			}
//			std::cout<<"generating terminal symbol:"<<terminal<<std::endl;
			terminals_gcat_feature.insert(std::make_pair(terminal,std::make_pair(gcat,feature)));
			terminal_symbols+="'"+terminal+"',";
		}
	}
	if(terminal_symbols.back()==',') terminal_symbols.pop_back();
	grammar_rules=sqlite->exec_sql("SELECT PARENT_SYMBOL, HEAD_SYMBOL, NON_HEAD_SYMBOL FROM GRAMMAR WHERE LID = '"+lid
			+"' AND  ( HEAD_SYMBOL NOT LIKE 't_%' OR HEAD_SYMBOL LIKE 't_%' AND HEAD_SYMBOL IN ("+terminal_symbols+") )"
			+" AND ( NON_HEAD_SYMBOL IS NULL OR NON_HEAD_SYMBOL NOT LIKE 't_%' OR NON_HEAD_SYMBOL LIKE 't_%' AND NON_HEAD_SYMBOL IN ("+terminal_symbols+") )"
			+" ORDER BY PARENT_SYMBOL;");
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
	wchar_t *program=Py_DecodeLocale(argv[0],NULL);
	Py_SetProgramName(program);
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
//	std::cout<<"executing python script:\n"<<nltk_generate_sentence<<std::endl;
//	std::string nltk_command=("command = \"\"\""+nltk_generate_sentence+"\"\"\"\n");
//	PyRun_SimpleString(nltk_command.c_str());
//	PyRun_SimpleString("print(command)\n");
	std::cout<<db_file<<std::endl;
	std::cout<<lid<<std::endl;
	std::cout<<words<<std::endl;
	std::cout<<"stex output:"<<std::endl;
	//printing grammar only so that it can be redirected into a file
	//stax must make sure that the generated structures are unique
	PyRun_SimpleString(nltk_generate_sentence.c_str());
	Py_Finalize();
	delete stemmer;
	sqlite->close();
	db_factory::delete_instance();
	sqlite=NULL;
	return 0;
}
