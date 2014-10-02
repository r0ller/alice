#include "sp.h"
#include <iterator>
#include <algorithm>
#include <functional>
#include <sstream>

/*PUBLIC*/
interpreter::interpreter(){
	nr_of_nodes=0;
}

interpreter::~interpreter(){
	destroy_node_infos();
}

int interpreter::set_node_info(const lexicon& word, const node_info& node){
	node_info nodeinfo;
	std::string functor_table_name,shell_function_call,functor_result;
	const std::string *io_type=NULL,*functor_definition=NULL;
	char functor_result_block[1024]="";
	db *sqlite=NULL;
	query_result *functors=NULL,*io_type_functors=NULL;
	unsigned int number_of_functors,number_of_io_type_functors;
	FILE *functor_process=NULL;
	lexicon constant_word;

	nodeinfo.node_id=++nr_of_nodes;
	if(word.gcat.empty()==true) exit(EXIT_FAILURE);//TODO: throw exception
	nodeinfo.symbol=word.gcat;
	if(word.lexeme.empty()==true){
//		if(node.symbol=="CON"){//TODO: This is an inefficient (bruteforce) way of determining what the constant is. Later another logic should be introduced
//			//that marks somewhere that a constant is lingering without having any classification as in case of 'Delete abc.' Once e.g. the verb is available,
//			//it could be used to get all entries from the RELATION_FUNCTORS and just scan the functors of the IO_TYPEs found there.
//			if(word.gcat=="V"){
//				functor_table_name="RELATION_FUNCTORS";
//			}
//			else if(word.gcat=="N"){
//				functor_table_name="ENTITY_FUNCTORS";
//			}
//			else if(word.gcat=="ADJ"){
//				functor_table_name="ENTITY_FUNCTORS";
//			}
//			else if(word.gcat=="ADV"){
//				functor_table_name="RELATION_FUNCTORS";
//			}
//			else exit(EXIT_FAILURE);//TODO: throw exception
//			sqlite=db::get_instance();
//			functors=sqlite->exec_sql("SELECT * FROM "+functor_table_name+";");
//			if(functors==NULL) exit(EXIT_FAILURE);
//			number_of_functors=functors->result_rows();
//			for(unsigned int i=0;i<number_of_functors;++i){
//				io_type=functors->get_field_value(i,"io_type");
//				if(io_type==NULL) exit(EXIT_FAILURE);
//				io_type_functors=sqlite->exec_sql("SELECT * FROM ENTITY_FUNCTORS WHERE FUNCTOR = '"+*io_type+"' AND IO_TYPE = '"+*io_type+"' AND ARGUMENT = '"+*io_type+"';");
//				if(io_type_functors==NULL) exit(EXIT_FAILURE);
//				number_of_io_type_functors=io_type_functors->result_rows();
//				if(number_of_io_type_functors==1){
//					functor_definition=io_type_functors->get_field_value(0,"definition");
//					if(functor_definition==NULL) exit(EXIT_FAILURE);
//					//TODO: Figure out how to execute the shell scripts, as invoking a shell function is language
//					//specific (bash, ksh, etc.) which might be impossible to implement in a POSIX shell manner...
//					shell_function_call=*functor_definition;
//					shell_function_call+="io_array[0]=\""+node.expression.lexeme+"\";"
//						+"argument[0]=\""+node.expression.lexeme+"\";"+*io_type+" io_array argument;echo $?;";
//					//executing shell_function_call
//					functor_process=popen(shell_function_call.c_str(),"r");
//					while(fgets(functor_result_block,sizeof functor_result_block,functor_process)) functor_result+=functor_result_block;
//					pclose(functor_process);
//					//if functor returns the same output what the input was
//					if(functor_result==node.expression.lexeme){
//						//insert the word of the functor in the parent node of the constant as expression
//						constant_word=lex->get_word_by_lexeme(*(io_type_functors->get_field_value(0,"functor")));
//						nodeinfo.expression=constant_word;
//						break;
//					}
//				}
//				else exit(EXIT_FAILURE);//TODO: throw exception
//			}
//		}
//		else;//Not an error: Phrase nodes like NP usually don't have anything in the expression field
	}
	else nodeinfo.expression=word;
	nodeinfo.left_child=0;
	nodeinfo.right_child=node.node_id;
	node_infos.push_back(nodeinfo);
	/*printf("set node id:%d\n",node_infos[nr_of_nodes-1].node_id);
	printf("symbol:%s\n",node_infos[nr_of_nodes-1].symbol.c_str());
	printf("expression:%s\n",node_infos[nr_of_nodes-1].expression.c_str());
	printf("left_child:%d\n",node_infos[nr_of_nodes-1].left_child);
	printf("right_child:%d\n",node_infos[nr_of_nodes-1].right_child);*/
	delete functors;
	delete io_type_functors;
	return nodeinfo.node_id;
}

const node_info& interpreter::get_node_info(unsigned int node_id){
	/*printf("node info:\nnode id:%d\n",node_infos.at(node_id-1).node_id);
	printf("symbol:%s\n",node_infos.at(node_id-1).symbol.c_str());
	printf("expression:%s\n",node_infos.at(node_id-1).expression.c_str());
	printf("left_child:%d\n",node_infos.at(node_id-1).left_child);
	printf("right_child:%d\n",node_infos.at(node_id-1).right_child);*/
	if(node_id>0) return node_infos.at(node_id-1);//Make use of out_of_range exception
}

node_info& interpreter::get_private_node_info(unsigned int node_id){
	/*printf("node info:\nnode id:%d\n",node_infos.at(node_id-1).node_id);
	printf("symbol:%s\n",node_infos.at(node_id-1).symbol.c_str());
	printf("expression:%s\n",node_infos.at(node_id-1).expression.c_str());
	printf("left_child:%d\n",node_infos.at(node_id-1).left_child);
	printf("right_child:%d\n",node_infos.at(node_id-1).right_child);*/
	if(node_id>0) return node_infos.at(node_id-1);//Make use of out_of_range exception
}

int interpreter::combine_nodes(const std::string& symbol, const node_info& left_node, const node_info& right_node){
	node_info nodeinfo, new_phrase_head_root, new_phrase_non_head_root;
	db *sqlite=NULL;
	query_result *functors=NULL, *rule_to_rule_map_result=NULL;

	/*TODO:valamit kezdeni kell azzal ha a left_node->symbol='QPro' ill. ha az object_node-nak van gyereke*/
	nodeinfo.node_id=++nr_of_nodes;
	/*printf("combined node id:%d\n",(*this->private.node_info[this->private.nr_of_nodes-1]).node_id);*/
	nodeinfo.symbol=symbol;
	/*printf("symbol:%s\n",(*this->private.node_info[this->private.nr_of_nodes-1]).symbol);*/
	//TODO: Head first - head last determination
	if(true){//If language is head first
		new_phrase_head_root=left_node;
		new_phrase_non_head_root=right_node;
	}
	else if(false){//If language is head last
		new_phrase_head_root=right_node;
		new_phrase_non_head_root=left_node;
	}
	else ;//TODO: What if none of them -like a programming language?
	if(new_phrase_head_root.node_id!=0&&new_phrase_non_head_root.node_id!=0){
		sqlite=db::get_instance();
		rule_to_rule_map_result=sqlite->exec_sql("SELECT * FROM RULE_TO_RULE_MAP WHERE PARENT_SYMBOL = '"+symbol+"' AND HEAD_ROOT_SYMBOL = '"+new_phrase_head_root.symbol+"' AND NON_HEAD_ROOT_SYMBOL = '"+new_phrase_non_head_root.symbol+"';");
		//TODO:Check how to find out CON iotype so that CONs can be part of a combination
		if(rule_to_rule_map_result!=NULL){//&&new_phrase_head_root.symbol!="CON"&&new_phrase_non_head_root.symbol!="CON"){
		/* TODO: Instead of the current validation, the head node needs to be validated against
		 * all child nodes of the right_node having a non-empty expression. This would ensure that
		 * all constituents are checked against each other and not only the new head of the phrase and
		 * the object of the phrase. E.g. 'list big small files!' is contradictory but now only
		 * big<->files, small<->files and list<->files are validated and not small<->files, big<->small,
		 * big<->files, list<->files.*/
			if(is_valid_combination(symbol,new_phrase_head_root,new_phrase_non_head_root)==false){
				throw invalid_combination(left_node.expression.word,right_node.expression.word);
			}
		/*printf("valid combination:%s %s\n",head_node->expression,((node_info *)object_node)->expression);*/
		}
	}
	nodeinfo.left_child=left_node.node_id;
	nodeinfo.right_child=right_node.node_id;
	node_infos.push_back(nodeinfo);
	/*printf("combined node id:%d\n",node_infos[nr_of_nodes-1].node_id);
	printf("symbol:%s\n",node_infos[nr_of_nodes-1].symbol.c_str());
	printf("expression:%s\n",node_infos[nr_of_nodes-1].expression.c_str());
	printf("left_child:%d\n",node_infos[nr_of_nodes-1].left_child);
	printf("right_child:%d\n",node_infos[nr_of_nodes-1].right_child);*/
	return nodeinfo.node_id;
}

//unsigned int interpreter::get_head_node(const node_info& node){
//	unsigned int head_node_id=0;
//
//	if(node.expression.lexeme.empty()==false){
//		std::cout<<"head_node:"<<node.node_id<<std::endl;
//		return node.node_id;
//	}
//	if(node.left_child!=0)head_node_id=get_head_node(get_node_info(node.left_child));
//	/* Stop if head_node is already found on the left since English is a 'head first' language
//	 * with a left-to-right word order!*/
//	if(node.right_child!=0&&head_node_id==0)head_node_id=get_head_node(get_node_info(node.right_child));
//	return head_node_id;
//}


//std::string interpreter::get_command(){
//	std::string command,environment_variable;
//	std::vector<std::string> environment_variables;
//
//	 TODO: Check options and command attributes for environment variable redefinitions
//	 and resolve them using some logic.
//	if(this->command.empty()==false){
//		command=this->command;
//		if(options.empty()==false){
//			find_ev_definitions(options,environment_variables);
//			for(unsigned int i=0;i<environment_variables.size();++i){
//				environment_variable=environment_variables[i];
//				//Look up redefinitions for the environment variable in command
//				delete_ev_redefinitions(environment_variable,command);
//			}
//			command=options+command;
//		}
//	}
//	return command;
//}


/*PRIVATE*/
/*
void interpreter::find_ev_definitions(const std::string& script, std::vector<std::string>& environment_variables){
	std::string environment_variable;
	std::istringstream stream_to_tokenize(script);
	size_t variable_start;

	while(std::getline(stream_to_tokenize,environment_variable,'=')){
		variable_start=environment_variable.find_last_of(" ;");
		if(variable_start!=std::string::npos) environment_variable=environment_variable.substr(++variable_start);
		environment_variable+="=";
		environment_variables.push_back(environment_variable);
	}
	environment_variables.pop_back();//Remove last tokenized part, it's an R-value we don't need
}
*/

/*
void interpreter::find_ev_definitions(const std::string& script, std::vector<ev_name_value_pair>& environment_variables){
	std::string environment_variable;
	std::istringstream stream_to_tokenize(script);
	size_t variable_start,value_end;
	ev_name_value_pair ev_definition;

	while(std::getline(stream_to_tokenize,environment_variable,'=')){
		variable_start=environment_variable.find_last_of(" ;");
		if(variable_start!=std::string::npos) ev_definition.name=environment_variable.substr(++variable_start);
		else ev_definition.name=environment_variable;
		ev_definition.name+="=";
		if(environment_variables.empty()==true){
			ev_definition.value.clear();
		}
		else{
			value_end=environment_variable.find_first_of(" ;");
			if(value_end!=std::string::npos) ev_definition.value=environment_variable.substr(0,value_end);
			else ev_definition.value.clear();
			environment_variables[environment_variables.size()-1].value=ev_definition.value;
		}
		environment_variables.push_back(ev_definition);
	}
	environment_variables.pop_back();//Remove last tokenized part, it's an R-value we don't need
}
*/

/*
void interpreter::delete_ev_redefinitions(const std::string& environment_variable, std::string& script){
	size_t variable_start,variable_end;

	variable_start=script.find(environment_variable);
	while(variable_start!=std::string::npos){
		if(script.at(variable_start+environment_variable.length())=='\''){
			variable_end=script.find('\'',variable_start+environment_variable.length()+1);
			++variable_end;
			if(script.at(variable_end)==';')++variable_end;
		}
		else{
			variable_end=script.find_first_of(" ;",variable_start);
			if(variable_end==std::string::npos) variable_end=script.length();
			else ++variable_end;
			}
		script=script.substr(0,variable_start)+script.substr(variable_end);
		variable_start=script.find(environment_variable,variable_end);
	}
}
*/

/*
std::string interpreter::resolve_ev_redefinitions(const std::string& in, const std::string& from){
	std::string command,ev_string;
	ev_name_value_pair environment_variable;
	char *old_ev_cstring=NULL, *new_ev_cstring=NULL;
	std::vector<ev_name_value_pair> environment_variables;

	 TODO: Check options and command attributes for environment variable redefinitions
	 * and resolve them using some logic.
	if(in.empty()==false){
		command=in;
		if(from.empty()==false){
			find_ev_definitions(from,environment_variables);
			for(unsigned int i=0;i<environment_variables.size();++i){
				environment_variable=environment_variables[i];
				Look up redefinitions for the environment variable in command
				delete_ev_redefinitions(environment_variable.name,command);
				old_ev_cstring=std::getenv(environment_variable.name.substr(0,environment_variable.name.length()-1).c_str());//Cut '=' sign and check environment variable value
				//It either exists with a different value or not at all and in both cases ev needs to be updated
				if(environment_variable.name.substr(0,3)=="HI_"
						&&(old_ev_cstring==NULL&&environment_variable.value.empty()==false
						||old_ev_cstring!=NULL&&old_ev_cstring!=environment_variable.value)){
					ev_string=environment_variable.name+environment_variable.value;
					new_ev_cstring=(char*)std::malloc(ev_string.length()+1);
					ev_string.copy(new_ev_cstring,ev_string.length(),0);
					new_ev_cstring[ev_string.length()]=0;
					//FIXME: Absolute path should be stored in ev!!!
					putenv(new_ev_cstring);
					if(new_ev_cstring!=old_ev_cstring) free(old_ev_cstring);
				}
				old_ev_cstring=NULL;
				new_ev_cstring=NULL;
			}
			command=from+command;
		}
	}
	return command;
}
*/

query_result *interpreter::is_valid_expression(node_info& main_node, node_info& dependent_node){
	unsigned int rowid=0;
	query_result *functors=NULL;

	if(main_node.expression.lexeme.empty()==false){//testing for leaves being leaves indeed
		if(dependent_node.node_id!=0){
			functors=functors_found_for_dependencies(dependent_node,main_node);
			if(functors!=NULL){
				if(functors->nr_of_result_rows()==1){
					rowid=functors->result_set().begin()->first;
					if(functors->field_value_at_row_position(rowid,"functor")!=NULL){
						if(main_node.functor_attributes.functor.empty()==true){
							main_node.functor_attributes.functor=*functors->field_value_at_row_position(rowid,"functor");
							main_node.functor_attributes.d_key=std::atoi(functors->field_value_at_row_position(rowid,"d_key")->c_str());
							main_node.functor_attributes.functor_id=std::atoi(functors->field_value_at_row_position(rowid,"functor_id")->c_str());
						}
						else if(main_node.functor_attributes.functor!=*functors->field_value_at_row_position(rowid,"functor")
								&&main_node.functor_attributes.d_key!=std::atoi(functors->field_value_at_row_position(rowid,"d_key")->c_str())){
							exit(EXIT_FAILURE);//TODO:Throw exception
						}
					}
					else if(functors->field_value_at_row_position(rowid,"lexeme")==NULL) exit(EXIT_FAILURE);//TODO:Throw exception
				}
				else if(functors->nr_of_result_rows()>1){//More than one functor is acceptable as an intermediate result
				}
				else{
					exit(EXIT_FAILURE);//TODO:Throw exception
				}
				dependent_node.node_links.insert(std::make_pair(main_node.node_id,0));//TODO:get rid of second member in node_links
			}
		}
	}
	return functors;
}

query_result* interpreter::functors_found_for_dependencies(const node_info& dependent_node, node_info& main_node){
	std::multimap<std::pair<std::string,std::string>,std::pair<unsigned int,std::string> > functors_found;
	std::string d_key_list,functor;
	query_result *functors=NULL,*ncat_functors=NULL;
	std::vector<std::pair<unsigned int,std::string> > dependency_stack;
	db *sqlite=NULL;
	field field;
	std::ostringstream out;

	functor=main_node.expression.lexeme;
	std::cout<<"functor to be found for dependencies: "<<functor<<std::endl;
	find_functors_for_dependency(dependent_node.expression.lexeme,*main_node.expression.dependencies,functors_found,dependency_stack);
	if(functors_found.empty()==true){
		return functors;
	}
	//generate d_key_list string which lists the d_keys of functors_found like: ('1', '2', ..., '3')
	d_key_list="(";
	for(std::multimap<std::pair<std::string,std::string>,std::pair<unsigned int,std::string> >::const_iterator j=functors_found.begin();
			j!=functors_found.end();++j){
		if(j->first.first==functor&&d_key_list.find("'"+j->first.second+"'")==std::string::npos){
			d_key_list+="'"+j->first.second+"',";
		}
	}
	d_key_list.resize(d_key_list.length()-1);//remove last ','
	d_key_list+=")";
	sqlite=db::get_instance();
	functors=sqlite->exec_sql("SELECT * FROM FUNCTORS WHERE FUNCTOR = '"+functor+"' AND D_KEY IN "+d_key_list+";");
	if(functors==NULL) exit(EXIT_FAILURE);
	for(std::multimap<std::pair<std::string,std::string>,std::pair<unsigned int,std::string> >::const_iterator i=functors_found.begin();
			i!=functors_found.end();++i){
		main_node.dependency_validation_matrix.insert(std::make_pair(i->second.first,dependent_node.node_id));
		out.str(std::string());
		out.clear();
		out<<dependent_node.node_id;
		std::cout<<"dependency "<<i->second.second<<" with node id "<<out.str();
		out.str(std::string());
		out.clear();
		out<<i->second.first;
		std::cout<<" and depolex row id "<<out.str();
		out.str(std::string());
		out.clear();
		out<<main_node.node_id;
		std::cout<<" for functor "<<i->first.first<<" with node id "<<out.str()<<" found"<<std::endl;
	}
	return functors;
}

bool interpreter::find_functors_for_dependency(const std::string& dependency, const query_result& dependencies,
		std::multimap<std::pair<std::string,std::string>,std::pair<unsigned int,std::string> >& functors_found,
		std::vector<std::pair<unsigned int,std::string> >& dependency_stack){
	const std::pair<const unsigned int,field> *depolex_entry=NULL;
	std::string lexeme,d_key;
	std::ostringstream out;

	depolex_entry=dependencies.first_value_for_field_name_found("semantic_dependency",dependency);
	if(depolex_entry==NULL) return true;
	while(depolex_entry!=NULL){
		std::cout<<"looking for functor with dependency "<<dependency<<std::endl;
		lexeme=*dependencies.field_value_at_row_position(depolex_entry->first,"lexeme");
		d_key=*dependencies.field_value_at_row_position(depolex_entry->first,"d_key");
		dependency_stack.push_back(std::make_pair(depolex_entry->first,depolex_entry->second.field_value));
		if(find_functors_for_dependency(lexeme,dependencies,functors_found,dependency_stack)==true){
			out.str(std::string());
			out.clear();
			out<<dependency_stack.begin()->first;
			std::cout<<"inserting in functors_found an entry with row id "<<out.str()<<", functor="<<lexeme<<" d_key="<<d_key<<std::endl;
			functors_found.insert(std::make_pair(std::make_pair(lexeme,d_key),*dependency_stack.begin()));
		}
		dependency_stack.pop_back();
		depolex_entry=dependencies.value_for_field_name_found_after_row_position(depolex_entry->first,"semantic_dependency",dependency);
	}
}

void interpreter::get_nodes_by_symbol(const node_info& root_node, const std::string symbol, std::vector<unsigned int>& nodes_found){
	//root_node: root node of the subtree in which the node should be found by the symbol
	//symbol: symbol of the node by which the node should be found
	//nodes_found: node ids of the nodes found
	if(symbol.empty()==false){
		if(root_node.symbol==symbol){
			std::cout<<"node_found_by_symbol '"<<symbol<<"':"<<root_node.node_id<<std::endl;
			nodes_found.push_back(root_node.node_id);
		}
		if(root_node.left_child!=0)get_nodes_by_symbol(get_node_info(root_node.left_child),symbol,nodes_found);
		if(root_node.right_child!=0)get_nodes_by_symbol(get_node_info(root_node.right_child),symbol,nodes_found);
	}
	else exit(EXIT_FAILURE);//TODO: throw exception, symbol cannot be empty
}

void interpreter::find_dependencies_for_node(const unsigned int node_id, std::map<std::pair<unsigned int,unsigned int>,std::pair<unsigned int,unsigned int> >& dependencies_found){
	std::pair<unsigned int,unsigned int> dependency_for_d_key_found;
	std::string d_key="0";
	const std::pair<const unsigned int,field> *depolex_entry=NULL;

	const node_info& node=get_node_info(node_id);
	depolex_entry=node.expression.dependencies->first_value_for_field_name_found("lexeme",node.expression.lexeme);
	while(depolex_entry!=NULL&&node.expression.lexeme==*node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"lexeme")
			&&d_key!=*node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"d_key")){
		d_key=*node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"d_key");
		std::cout<<"checking top level entry for functor "<<node.expression.lexeme<<" d_key "<<d_key<<std::endl;
		find_dependencies_for_functor(node.node_id,d_key,dependencies_found);
		while(depolex_entry!=NULL&&*node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"d_key")==d_key){
			depolex_entry=node.expression.dependencies->value_for_field_name_found_after_row_position(depolex_entry->first,"lexeme",node.expression.lexeme);
		}
	}
}

bool interpreter::find_dependencies_for_functor(const unsigned int node_id, const std::string& d_key,
		std::map<std::pair<unsigned int,unsigned int>,std::pair<unsigned int,unsigned int> >& dependencies_found){
	const std::pair<const unsigned int,field> *depolex_entry=NULL;
	std::string semantic_dependency,ref_d_key,d_counter="0",manner;
	std::multimap<unsigned int,unsigned int>::const_iterator dependency_matrix_entry;
	std::ostringstream out;
	std::map<unsigned int,unsigned int>::const_iterator j;
	std::map<std::pair<unsigned int,unsigned int>,std::pair<unsigned int,unsigned int> >::iterator dependencies_found_entry;
	std::set<unsigned int> validated_dependencies;

	const node_info& node=get_node_info(node_id);
	std::cout<<"checking dependency for functor "<<node.expression.lexeme<<" d_key "<<d_key<<std::endl;
	depolex_entry=node.expression.dependencies->first_value_for_field_name_found("lexeme",node.expression.lexeme);
	if(depolex_entry==NULL){
		std::cout<<"exiting, no dependency entry found for functor "<<node.expression.lexeme<<std::endl;
		//TODO: throw exception as for each functor there must be one entry with at least NULL dependency
		exit(EXIT_FAILURE);
	}
	while(depolex_entry!=NULL&&*node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"d_key")!=d_key){
		depolex_entry=node.expression.dependencies->value_for_field_name_found_after_row_position(depolex_entry->first,"lexeme",node.expression.lexeme);
	}
	while(depolex_entry!=NULL&&*node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"d_key")==d_key
			&&std::atoi(node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"d_counter")->c_str())>std::atoi(d_counter.c_str())){
		d_counter=*node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"d_counter");
		semantic_dependency=*node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"semantic_dependency");
		ref_d_key=*node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"ref_d_key");
		manner=*node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"manner");
		std::cout<<"checking dependency entry "<<semantic_dependency<<" ref_d_key "<<ref_d_key<<" for functor "<<node.expression.lexeme<<" d_key "<<d_key<<" d_counter "<<d_counter<<std::endl;
		if(semantic_dependency.empty()==false&&ref_d_key.empty()==false&&(manner=="1"||manner=="2"||manner=="3"||manner=="4"||manner=="5"||manner=="6")){
			out.str(std::string());
			out.clear();
			out<<depolex_entry->first;
			std::cout<<"looking up depolex entry with row id "<<out.str()<<" in dep.val.matrix"<<std::endl;
			validated_dependencies.clear();
			for(dependency_matrix_entry=node.dependency_validation_matrix.lower_bound(depolex_entry->first);
					dependency_matrix_entry!=node.dependency_validation_matrix.upper_bound(depolex_entry->first);
					++dependency_matrix_entry){
				//If the row_id of the depolex_entry is found among the row_ids stored in the dep.vld.matrix
				//then the field values match as well since both row_ids refer to the corresponding
				//field in the node.expression.dependencies attribute.
				validated_dependencies.insert(dependency_matrix_entry->second);
				//Insert the corresponding entry into dependencies_found to indicate that the node id is already being checked
				dependencies_found.insert(std::make_pair(std::make_pair(node_id,std::atoi(d_key.c_str())),std::make_pair(0,0)));
				std::cout<<"dependency "<<semantic_dependency<<" checked for functor "<<node.expression.lexeme<<std::endl;
				if(find_dependencies_for_functor(get_node_info(dependency_matrix_entry->second).node_id,ref_d_key,dependencies_found)==false){
					std::cout<<"dependency check for "<<semantic_dependency<<" returned FALSE for functor "<<node.expression.lexeme<<std::endl;
					return false;
				}
			}
			if(manner=="1"&&validated_dependencies.size()==1
					||manner=="2"&&validated_dependencies.size()==1
					||manner=="3"&&validated_dependencies.size()>=1
					||manner=="4"&&validated_dependencies.size()>=1
					||manner=="5"&&validated_dependencies.size()>1
					||manner=="6"&&validated_dependencies.size()>1){
				dependencies_found_entry=dependencies_found.find(std::make_pair(node_id,std::atoi(d_key.c_str())));
				if(dependencies_found_entry!=dependencies_found.end()){
					++dependencies_found_entry->second.first;
					++dependencies_found_entry->second.second;
				}
				else{
					dependencies_found.insert(std::make_pair(std::make_pair(node_id,std::atoi(d_key.c_str())),std::make_pair(1,1)));
				}
			}
			else if(manner=="1"&&validated_dependencies.size()!=1
					||manner=="2"&&validated_dependencies.size()>1
					||manner=="3"&&validated_dependencies.size()<1
					||manner=="5"&&validated_dependencies.size()<=1
					||manner=="6"&&validated_dependencies.size()==1){
				dependencies_found_entry=dependencies_found.find(std::make_pair(node_id,std::atoi(d_key.c_str())));
				if(dependencies_found_entry!=dependencies_found.end()){
					//No manner condition was fulfilled, nothing to add
				}
				else{
					dependencies_found.insert(std::make_pair(std::make_pair(node_id,std::atoi(d_key.c_str())),std::make_pair(0,0)));
				}
				return false;
			}
		}
		else if(semantic_dependency.empty()==false&&ref_d_key.empty()==false&&manner=="0"){
			//What TODO here?
		}
		else if(semantic_dependency.empty()==true&&ref_d_key.empty()==true){
			//A leaf in the dependency tree is found so the semantic dependency is empty. As such, there's no
			//functor-dependency pair to be checked in the dep.vld.matrix so let's go on with the next dependency.
			std::cout<<"dependency "<<semantic_dependency<<" checked for functor "<<node.expression.lexeme<<" but has no further dependency"<<std::endl;
			dependencies_found_entry=dependencies_found.find(std::make_pair(node_id,std::atoi(d_key.c_str())));
			if(dependencies_found_entry!=dependencies_found.end()){
				//Don't increase the number of dependencies, NULL dependency is considered as found but not counted
				//++dependencies_found_entry->second.first;
				//++dependencies_found_entry->second.second;
			}
			else{
				dependencies_found.insert(std::make_pair(std::make_pair(node_id,std::atoi(d_key.c_str())),std::make_pair(0,0)));
			}
		}
		else{
			//TODO: throw exception
			exit(EXIT_FAILURE);
		}
		depolex_entry=node.expression.dependencies->value_for_field_name_found_after_row_position(depolex_entry->first,"lexeme",node.expression.lexeme);
	}
	for(j=node.node_links.begin();j!=node.node_links.end();++j){
		for(dependencies_found_entry=dependencies_found.begin();dependencies_found_entry!=dependencies_found.end();++dependencies_found_entry){
			if(dependencies_found_entry->first.first==j->first) break;
		}
		if(dependencies_found_entry==dependencies_found.end()){
			find_dependencies_for_node(j->first,dependencies_found);
		}
	}
	return true;//All d_counters for the lexeme (functor) and d_key pair have been checked and should have returned with false by now if
	//a dependency was not found for that. So theoretically, all deps have been found at this level, so return true.
}

bool interpreter::is_longest_match_for_semantic_rules_found(){
	//uint1:node id, uint2:d_key, uint3:nr_of_dependencies_found, uint4:nr_of_dependencies
	std::map<std::pair<unsigned int,unsigned int>,std::pair<unsigned int,unsigned int> > dependencies_found;
	std::ostringstream out;
	std::vector<unsigned int> verbs_found;
	std::map<unsigned int,unsigned int> node_ids_with_longest_match;
	std::map<unsigned int,unsigned int>::iterator node_id_with_longest_match;
	std::set<unsigned int> nodes_to_be_validated;

	const node_info& root_node=get_node_info(nr_of_nodes);
	get_nodes_by_symbol(root_node,"V",verbs_found);
	if(verbs_found.size()!=1) exit(EXIT_FAILURE);//TODO: throw exception
	const node_info& node=get_node_info(*verbs_found.begin());
	find_dependencies_for_node(node.node_id,dependencies_found);
	for(std::map<std::pair<unsigned int,unsigned int>,std::pair<unsigned int,unsigned int> >::const_iterator i=dependencies_found.begin();
			i!=dependencies_found.end();++i){
		out.str(std::string());
		out.clear();
		out<<i->first.first;
		std::cout<<"for node id "<<out.str();
		out.str(std::string());
		out.clear();
		out<<i->first.second;
		std::cout<<" with functor "<<get_node_info(i->first.first).expression.lexeme<<" and d_key "<<out.str();
		out.str(std::string());
		out.clear();
		out<<i->second.first;
		std::cout<<" the nr_of_dependencies_found/nr_of_dependencies is: "<<out.str();
		out.str(std::string());
		out.clear();
		out<<i->second.second;
		std::cout<<"/"<<out.str()<<std::endl;
		node_id_with_longest_match=node_ids_with_longest_match.find(i->first.first);
		if(node_id_with_longest_match!=node_ids_with_longest_match.end()){
			if(i->second.first==i->second.second&&node_id_with_longest_match->second<i->second.first){
				node_id_with_longest_match->second=i->second.first;
			}
			else if(i->second.first==i->second.second&&node_id_with_longest_match->second>0&&node_id_with_longest_match->second==i->second.first) return false;
		}
		else if(i->second.first==i->second.second){
			node_ids_with_longest_match.insert(std::make_pair(i->first.first,i->second.first));
			nodes_to_be_validated.erase(i->first.first);
		}
		else{
			nodes_to_be_validated.insert(i->first.first);
		}
	}
	if(nodes_to_be_validated.empty()==true) return true;
	else return false;
}

bool interpreter::is_valid_combination(const std::string& symbol, const node_info& new_phrase_head_root, const node_info& new_phrase_non_head_root){
	bool valid_combination=false;
	db *sqlite=NULL;
	query_result *functors=NULL, *rule_to_rule_map=NULL;
	std::multimap<unsigned int,unsigned int>::const_iterator l;
	std::vector<unsigned int>::const_iterator j,k;
	std::vector<unsigned int> main_nodes_found_by_symbol,dependent_nodes_found_by_symbol;
	std::set<unsigned int> valid_iterations;
	unsigned int nr_of_optional_rules=0;

	sqlite=db::get_instance();
	rule_to_rule_map=sqlite->exec_sql("SELECT * FROM RULE_TO_RULE_MAP WHERE PARENT_SYMBOL = '"+symbol+"' AND HEAD_ROOT_SYMBOL = '"+new_phrase_head_root.symbol+"' AND NON_HEAD_ROOT_SYMBOL = '"+new_phrase_non_head_root.symbol+"';");
	if(rule_to_rule_map==NULL) exit(EXIT_FAILURE);//TODO: throw exception
	for(unsigned int i=0, n=rule_to_rule_map->nr_of_result_rows();i<n;++i){
		main_nodes_found_by_symbol.clear();
		dependent_nodes_found_by_symbol.clear();
		if(*rule_to_rule_map->field_value_at_row_position(i,"head_root_symbol")==new_phrase_head_root.symbol&&*rule_to_rule_map->field_value_at_row_position(i,"non_head_root_symbol")==new_phrase_non_head_root.symbol){
			if(rule_to_rule_map->field_value_at_row_position(i,"main_node_symbol")->empty()==false){
				if(*rule_to_rule_map->field_value_at_row_position(i,"main_lookup_root")=="H")
					get_nodes_by_symbol(new_phrase_head_root,*rule_to_rule_map->field_value_at_row_position(i,"main_node_symbol"),main_nodes_found_by_symbol);
				else if(*rule_to_rule_map->field_value_at_row_position(i,"main_lookup_root")=="N")
					get_nodes_by_symbol(new_phrase_non_head_root,*rule_to_rule_map->field_value_at_row_position(i,"main_node_symbol"),main_nodes_found_by_symbol);
				else{
					get_nodes_by_symbol(new_phrase_head_root,*rule_to_rule_map->field_value_at_row_position(i,"main_node_symbol"),main_nodes_found_by_symbol);
					get_nodes_by_symbol(new_phrase_non_head_root,*rule_to_rule_map->field_value_at_row_position(i,"main_node_symbol"),main_nodes_found_by_symbol);
				}
			}
			if(rule_to_rule_map->field_value_at_row_position(i,"dependent_node_symbol")->empty()==false){
				if(*rule_to_rule_map->field_value_at_row_position(i,"dependency_lookup_root")=="H")
					get_nodes_by_symbol(new_phrase_head_root,*rule_to_rule_map->field_value_at_row_position(i,"dependent_node_symbol"),dependent_nodes_found_by_symbol);
				else if(*rule_to_rule_map->field_value_at_row_position(i,"dependency_lookup_root")=="N")
					get_nodes_by_symbol(new_phrase_non_head_root,*rule_to_rule_map->field_value_at_row_position(i,"dependent_node_symbol"),dependent_nodes_found_by_symbol);
				else{
					get_nodes_by_symbol(new_phrase_head_root,*rule_to_rule_map->field_value_at_row_position(i,"dependent_node_symbol"),dependent_nodes_found_by_symbol);
					get_nodes_by_symbol(new_phrase_non_head_root,*rule_to_rule_map->field_value_at_row_position(i,"dependent_node_symbol"),dependent_nodes_found_by_symbol);
				}
			}
			if(main_nodes_found_by_symbol.empty()==false&&dependent_nodes_found_by_symbol.empty()==false){
				//1)Loop over main_nodes_found_by_symbol
				for(j=main_nodes_found_by_symbol.begin();j!=main_nodes_found_by_symbol.end();++j){
					std::cout<<"loop pass on main_nodes_found_by_symbol:"<<*j<<std::endl;
					node_info& main_node=get_private_node_info(*j);
					//2)Loop over dependent_nodes_found_by_symbol where dependent_node is NOT in current_main_node.node_links
					for(k=dependent_nodes_found_by_symbol.begin();k!=dependent_nodes_found_by_symbol.end();++k){
						std::cout<<"loop pass on dependent_nodes_found_by_symbol:"<<*k<<std::endl;
						node_info& dependent_node=get_private_node_info(*k);
						for(l=main_node.dependency_validation_matrix.begin();l!=main_node.dependency_validation_matrix.end();++l){
							if(l->second==dependent_node.node_id) break;
						}
						if(l==main_node.dependency_validation_matrix.end()){
							functors=is_valid_expression(main_node,dependent_node);
							if(functors!=NULL){
								valid_iterations.insert(i);
								delete functors;
							}
							else if(std::atoi(rule_to_rule_map->field_value_at_row_position(i,"optional")->c_str())!=0){
								valid_iterations.insert(i);
								++nr_of_optional_rules;
							}
						}
					}
				}
			}
			else if(rule_to_rule_map->field_value_at_row_position(i,"main_node_symbol")->empty()==false
					&&main_nodes_found_by_symbol.empty()==false
					&&rule_to_rule_map->field_value_at_row_position(i,"dependent_node_symbol")->empty()==true
					&&dependent_nodes_found_by_symbol.empty()==true
					||rule_to_rule_map->field_value_at_row_position(i,"main_node_symbol")->empty()==true
					&&main_nodes_found_by_symbol.empty()==true
					&&rule_to_rule_map->field_value_at_row_position(i,"dependent_node_symbol")->empty()==false
					&&dependent_nodes_found_by_symbol.empty()==false
					||std::atoi(rule_to_rule_map->field_value_at_row_position(i,"optional")->c_str())!=0){
				//This experimental branch allows checking for symbols only in a subtree but not sure
				//if it just lets customizing to become complicated
				valid_iterations.insert(i);
				if(std::atoi(rule_to_rule_map->field_value_at_row_position(i,"optional")->c_str())!=0) ++nr_of_optional_rules;
			}
		}
		else{
			exit(EXIT_FAILURE);//TODO: throw exception
		}
	}
	delete rule_to_rule_map;
	if(valid_iterations.size()==rule_to_rule_map->nr_of_result_rows()&&nr_of_optional_rules<rule_to_rule_map->nr_of_result_rows()) valid_combination=true;
	else valid_combination=false;
	return valid_combination;
}

/*
std::vector<std::string> interpreter::find_ev_occurence_in(const std::string& script){
	std::string environment_variable;
	std::vector<std::string> environment_variables;
	std::istringstream stream_to_tokenize(script);
	size_t environment_variable_end;
	unsigned int i=0;

	while(std::getline(stream_to_tokenize,environment_variable,'$')){
		if(i>0){//Ignore first tokenized part, it ends in $, not begins with it
			environment_variable_end=environment_variable.find_first_of(" ;");
			if(environment_variable_end!=std::string::npos)	environment_variable.resize(environment_variable_end);
			environment_variables.push_back(environment_variable);
		}
		++i;
	}
	return environment_variables;
}
*/


/*
void interpreter::set_command(const std::string& command, const std::string& constant, const std::string& prep){
	std::string pattern,environment_variable,ev,ev_value,command_value,preposition_value,command_resolvee;
	unsigned int i,j;
	db *sqlite;
	std::vector<std::string> environment_variables;

	sqlite=db::get_instance();
	if(this->command.empty()==true){
		environment_variables=find_ev_occurence_in(command);
		//printf("DEBUG: environment_variables.size()=%d\n",environment_variables.size());
		for(j=0;j<environment_variables.size();++j){
			pattern=environment_variables[j];
			pattern+="=";
			//printf("\nDEBUG PATTERN: %s\n\n",pattern.c_str());
			Don't look up another definition if the environment variable is already defined in command
			if(command.find(pattern)==std::string::npos&&this->command.empty()==true
				||command.find(pattern)==std::string::npos&&this->command.empty()==false&&this->command.find(pattern)==std::string::npos){
				//printf("\nDEBUG PATTERN OK: %s\n\n",pattern.c_str());
				for(i=0;i<sqlite->result_size();++i){
					At least one entry must exist with the pattern specified
					command_value=sqlite->get_field_value(i,"command");
					//printf("\nDEBUG DB ENTRY command_value=%s\n\n",command_value.c_str());
					preposition_value=sqlite->get_field_value(i,"preposition");
					//printf("\nDEBUG DB ENTRY preposition_value=%s\n\n",preposition_value.c_str());
					if(command_value.find(pattern)!=std::string::npos&&
							(prep.empty()==false&&preposition_value==prep
							||prep.empty()==true&&preposition_value.empty()==false)){
						//Check if the script found contains environment variable definition
						if(pattern.substr(0,3)=="HI_"&&command_value.find(pattern)==std::string::npos){
							//No definition found for the environment variable stored in pattern, take it from process environment
							ev=pattern.substr(0,pattern.length()-1));//Cut '=' sign
							ev_value=std::getenv(ev.c_str());
						}
						if(this->command.empty()==true){
							if(ev_value.empty()==false){
								this->command=pattern+"\'"+ev_value+"';"+command_value;
							}
							else this->command=command_value;
						}
						else if(this->command.find(command_value)==std::string::npos){
							if(ev_value.empty()==false){
								this->command+=pattern+"\'"+ev_value+"';";
							}
							this->command+=command_value;
						}
						//printf("\nDEBUG VARIABLE: %s\n\n",this->command.c_str());
						break;
					}
				}
			}
		}
		if(constant.empty()==true){
			if(this->command.empty()==true){
				this->command=command;
			}
			else{
				this->command+=command;
			}
		}
		else{
			if(this->command.empty()==true){
				this->command="constant="+constant+";"+command;
			}
			else{
				this->command+="constant="+constant+";"+command;
			}
		}

	}
	else{
		if(constant.empty()==true){
			this->command=command+this->command;
		}
		else{
			pattern=command.substr(0,command.find('='));
			pattern+="=";
			command_resolvee=pattern+constant+command.substr(command.find(';'));
			//printf("command_resolvee:%s\n",command_resolvee.c_str());
			this->command=resolve_ev_redefinitions(this->command,command_resolvee);
		}
	}
	//printf("\nDEBUG SET_COMMAND: %s\n\n",this->command.c_str());
}
*/

/*
void interpreter::set_options(const std::string& options){

	 TODO: check for already existing environment variables in this->private.options and if such a variable
	 * occurs in the incoming options parameter, then rearrange this->private.options with string operations.
	 * Otherwise, with simple concatenation the already existing environment variable loses its value due to
	 * the redefinition in the incoming options parameter.
	if(this->options.empty()==true){
		this->options=options;
	}
	else{
		this->options+=options;
	}
	//printf("\nDEBUG SET_OPTIONS: %s\n\n",this->options.c_str());
}
*/

void interpreter::destroy_node_infos(){
	nr_of_nodes=0;
	return;
}
