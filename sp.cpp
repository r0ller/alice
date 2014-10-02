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
	std::string functor_table_name,io_type,functor_definition,shell_function_call,functor_result;
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
		if(node.symbol=="CON"){//TODO: This is an inefficient (bruteforce) way of determining what the constant is. Later another logic should be introduced
			//that marks somewhere that a constant is lingering without having any classification as in case of 'Delete abc.' Once e.g. the verb is available,
			//it could be used to get all entries from the RELATION_FUNCTORS and just scan the functors of the IO_TYPEs found there.
			if(word.gcat=="V"){
				functor_table_name="RELATION_FUNCTORS";
			}
			else if(word.gcat=="N"){
				functor_table_name="ENTITY_FUNCTORS";
			}
			else if(word.gcat=="ADJ"){
				functor_table_name="ENTITY_FUNCTORS";
			}
			else if(word.gcat=="ADV"){
				functor_table_name="RELATION_FUNCTORS";
			}
			else exit(EXIT_FAILURE);//TODO: throw exception
			sqlite=db::get_instance();
			functors=sqlite->exec_sql("SELECT * FROM "+functor_table_name+";");
			if(functors==NULL) exit(EXIT_FAILURE);
			number_of_functors=functors->result_rows();
			for(unsigned int i=0;i<number_of_functors;++i){
				io_type=functors->get_field_value(i,"IO_TYPE");
				io_type_functors=sqlite->exec_sql("SELECT * FROM ENTITY_FUNCTORS WHERE FUNCTOR = '"+io_type+"' AND IO_TYPE = '"+io_type+"' AND ARGUMENT = '"+io_type+"';");
				if(io_type_functors==NULL) exit(EXIT_FAILURE);
				number_of_io_type_functors=io_type_functors->result_rows();
				if(number_of_io_type_functors==1){
					functor_definition=io_type_functors->get_field_value(0,"DEFINITION");
					//TODO: Figure out how to execute the shell scripts, as invoking a shell function is language
					//specific (bash, ksh, etc.) which might be impossible to implement in a POSIX shell manner...
					shell_function_call=functor_definition;
					shell_function_call+="io_array[0]=\""+node.expression.lexeme+"\";"
						+"argument[0]=\""+node.expression.lexeme+"\";"+io_type+" io_array argument;echo $?;";
					//executing shell_function_call
					functor_process=popen(shell_function_call.c_str(),"r");
					while(fgets(functor_result_block,sizeof functor_result_block,functor_process)) functor_result+=functor_result_block;
					pclose(functor_process);
					//if functor returns the same output what the input was
					if(functor_result==node.expression.lexeme){
						//insert the word of the functor in the parent node of the constant as expression
						constant_word=lex->get_word_by_lexeme(io_type_functors->get_field_value(0,"FUNCTOR"));
						nodeinfo.expression=constant_word;
						break;
					}
				}
				else exit(EXIT_FAILURE);//TODO: throw exception
			}
		}
		else;//Not an error: Phrase nodes like NP usually don't have anything in the expression field
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
	else exit(EXIT_FAILURE);//TODO: throw exception
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

unsigned int interpreter::get_head_node(const node_info& node){
	unsigned int head_node_id=0;

	if(node.expression.lexeme.empty()==false){
		std::cout<<"head_node:"<<node.node_id<<std::endl;
		return node.node_id;
	}
	if(node.left_child!=0)head_node_id=get_head_node(get_node_info(node.left_child));
	/* Stop if head_node is already found on the left since English is a 'head first' language
	 * with a left-to-right word order!*/
	if(node.right_child!=0&&head_node_id==0)head_node_id=get_head_node(get_node_info(node.right_child));
	return head_node_id;
}


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

query_result *interpreter::is_valid_expression(node_info& head_leaf, node_info& non_head_leaf, node_info& head_dependency, node_info& non_head_dependency){
	//leaf1, leaf2: leaves (lowest level nodes in the semantic tree) that need to be validated for combination

	//Method responsibility: When two nodes are combined, check their assignment either in the
	//ATTRIBUTE_FUNCTORS, ADVERB_FUNCTORS or RELATION_FUNCTORS table using the keys available depending on their
	//grammatical categories:

	//ADJ-N: look up existing entries in ATTRIBUTE_FUNCTORS using keys functor=lexeme+lid+gcat of ADJ,
	//io_type=lexeme+lid+gcat of N

	//ADV-V: Look up existing entries in ADVERB_FUNCTORS using keys functor=lexeme+lid+gcat of ADV,
	//relation_functor=lexeme+lid+gcat of V, relation_io_type=not used, argument=not used.
	//This means that the ADV-V combination is validated only
	//theoretically (i.e. to see if a certain verb like 'PLAY' can combine with the adverb 'SLOWER' at all),
	//and not for the concrete object of the sentence (io_type of V).
	//That must be done in is_valid_combination() when the object (gcat N) of the predicate of the
	//sentence is validated.

	//V-N: Look up existing entries in RELATION_FUNCTORS using keys functor=lexeme+lid+gcat of V,
	//io_type=lexeme+lid+gcat of N.

	std::string query,relation_functor_name,io_type,functor,d_key_list;
	std::stringstream d_key,io_type_ss;
	db *sqlite=NULL;
	query_result *functors=NULL,*relation_functors=NULL, *entity_functors=NULL;
	std::multimap<unsigned int,field>::const_iterator i,k,functor_found;
	std::multimap<unsigned int,depolex>::const_iterator j;
	std::multimap<unsigned int,depolex> head_leaf_dependency_table,non_head_leaf_dependency_table,relevant_head_dependencies,relevant_non_head_dependencies,*relevant_dependencies;
	std::multimap<unsigned int,relation_functor> relation_functor_table,entity_functor_table;
	std::multimap<unsigned int,relation_functor>::const_iterator l;
	relation_functor relation_functor, relation_functor_found;
	depolex head_leaf_dependency={},non_head_leaf_dependency={};
	unsigned int row_index=0,previous_iteration_d_key=0;
	dependency_validation_pair dependency_pair;
	std::multimap<unsigned int,dependency_validation_pair>::const_iterator m;
	bool complete_dependency_found, partial_dependency_found;
	node_info dependent_node;
	std::multimap<std::string,std::string> functor_criteria;

	sqlite=db::get_instance();
	if(head_leaf.expression.lexeme.empty()==false&&non_head_leaf.expression.lexeme.empty()==false){//testing for leaves being leaves indeed
		if(head_dependency.node_id!=0){
			//loop over head_node.dependencies into dependency_entry where dependency.lexeme=head_node and dependency.semantic_dependency=head_dependency
			//	collect dependency entry into dependency_entries
			//endloop
			const std::multimap<unsigned int,field>& head_leaf_dependencies=head_leaf.expression.dependencies->result_set();
			for(row_index=0,i=head_leaf_dependencies.begin();i!=head_leaf_dependencies.end();++i){
				if(row_index>0&&row_index<i->first){
					head_leaf_dependency_table.insert(std::make_pair(row_index,head_leaf_dependency));
				}
				row_index=i->first;
				if(i->second.field_name=="lexeme"){
					head_leaf_dependency.lexeme=i->second.field_value;
				}
				else if(i->second.field_name=="d_key"){
					head_leaf_dependency.d_key=std::atoi(i->second.field_value.c_str());
				}
				else if(i->second.field_name=="d_counter"){
					head_leaf_dependency.d_counter=std::atoi(i->second.field_value.c_str());
				}
				else if(i->second.field_name=="manner"){
					head_leaf_dependency.manner=std::atoi(i->second.field_value.c_str());
				}
				else if(i->second.field_name=="semantic_dependency"){
					head_leaf_dependency.semantic_dependency=i->second.field_value;
				}
				else if(i->second.field_name=="ref_d_key"){
					head_leaf_dependency.ref_d_key=std::atoi(i->second.field_value.c_str());
				}
				else if(i->second.field_name=="functor_d_key"){
					head_leaf_dependency.functor_d_key=std::atoi(i->second.field_value.c_str());
				}
				else exit(EXIT_FAILURE);
			}
			row_index=0;
			for(j=head_leaf_dependency_table.begin();j!=head_leaf_dependency_table.end();++j){
				if(j->second.lexeme==head_leaf.expression.lexeme+head_leaf.expression.lid+head_leaf.expression.gcat
						&&j->second.semantic_dependency==head_dependency.expression.lexeme+head_dependency.expression.lid+head_dependency.expression.gcat){
					//CHECK: the condition above should as well apply to cases where the head_dependency is empty!!!
					//They count as relevant dependencies because a lexeme (functor) may have a dependent argument without having
					//any lexical dependency. See e.g. 'send Mary an email'.
					relevant_head_dependencies.insert(*j);
				}

			}
			if(relevant_head_dependencies.empty()==true) exit(EXIT_FAILURE);
		}
		if(non_head_dependency.node_id!=0){
			const std::multimap<unsigned int,field>& non_head_leaf_dependencies=non_head_leaf.expression.dependencies->result_set();
			for(row_index=0,i=non_head_leaf_dependencies.begin();i!=non_head_leaf_dependencies.end();++i){
				if(row_index>0&&row_index<i->first){
					non_head_leaf_dependency_table.insert(std::make_pair(row_index,non_head_leaf_dependency));
				}
				row_index=i->first;
				if(i->second.field_name=="lexeme"){
					non_head_leaf_dependency.lexeme=i->second.field_value;
				}
				else if(i->second.field_name=="d_key"){
					non_head_leaf_dependency.d_key=std::atoi(i->second.field_value.c_str());
				}
				else if(i->second.field_name=="d_counter"){
					non_head_leaf_dependency.d_counter=std::atoi(i->second.field_value.c_str());
				}
				else if(i->second.field_name=="manner"){
					head_leaf_dependency.manner=std::atoi(i->second.field_value.c_str());
				}
				else if(i->second.field_name=="semantic_dependency"){
					non_head_leaf_dependency.semantic_dependency=i->second.field_value;
				}
				else if(i->second.field_name=="ref_d_key"){
					head_leaf_dependency.ref_d_key=std::atoi(i->second.field_value.c_str());
				}
				else if(i->second.field_name=="functor_d_key"){
					head_leaf_dependency.functor_d_key=std::atoi(i->second.field_value.c_str());
				}
				else exit(EXIT_FAILURE);
			}
			row_index=0;
			for(j=non_head_leaf_dependency_table.begin();j!=non_head_leaf_dependency_table.end();++j){
				if(j->second.lexeme==non_head_leaf.expression.lexeme+non_head_leaf.expression.lid+non_head_leaf.expression.gcat
						&&j->second.semantic_dependency==non_head_dependency.expression.lexeme+non_head_dependency.expression.lid+non_head_dependency.expression.gcat){
					//CHECK: the condition above should as well apply to cases where the non_head_dependency is empty!!!
					//They count as relevant dependencies because a lexeme (functor) may have a dependent argument without having
					//any lexical dependency. See e.g. 'send Mary an email'.
					relevant_non_head_dependencies.insert(*j);
				}

			}
			if(relevant_non_head_dependencies.empty()==true) exit(EXIT_FAILURE);
		}
		//TODO: Add a check in each 'if' branch below to test for relevant_(non)_head_dependencies!!!
		if(head_leaf.symbol=="V"&&non_head_leaf.symbol=="N"||head_leaf.symbol=="N"&&non_head_leaf.symbol=="V"){
			if(head_leaf.symbol=="V"&&non_head_leaf.symbol=="N"){
				functor=head_leaf.expression.lexeme+head_leaf.expression.lid+head_leaf.expression.gcat;
				io_type=non_head_leaf.expression.lexeme+non_head_leaf.expression.lid+non_head_leaf.expression.gcat;
			}
			else{
				functor=non_head_leaf.expression.lexeme+non_head_leaf.expression.lid+non_head_leaf.expression.gcat;
				io_type=head_leaf.expression.lexeme+head_leaf.expression.lid+head_leaf.expression.gcat;
			}
			if(non_head_dependency.node_id!=0){
				if(non_head_leaf.symbol=="N"){
					full_dependency_table=&non_head_leaf_dependency_table;
					relevant_dependencies=&relevant_non_head_dependencies;
					validator_node_id=head_leaf.node_id;
					N_node=&non_head_leaf;
					dependent_node=&non_head_dependency;
				}
				else{
					full_dependency_table=&head_leaf_dependency_table;
					relevant_dependencies=&relevant_head_dependencies;
					validator_node_id=non_head_leaf.node_id;
					N_node=&head_leaf;
					dependent_node=&head_dependency;
				}
				//generate d_key_list string which lists the d_keys of relevant_dependencies like: ('1', '2', ..., '3')
				d_key_list="(";
				for(j=*relevant_dependencies.begin();j!=*relevant_dependencies.end();++j){
					d_key<<j->second.functor_d_key;
					if(d_key_list.find("'"+d_key.str()+"'")==std::string::npos){
						d_key_list+="'"+d_key.str()+"',";
					}
				}
				d_key_list.resize(d_key_list.length()-1);//remove last ','
				d_key_list+=")";
				entity_functors=sqlite->exec_sql("SELECT * FROM ENTITY_FUNCTORS WHERE FUNCTOR = '"+io_type+"' AND D_KEY IN "+d_key_list+";");
				if(entity_functors==NULL) exit(EXIT_FAILURE);
				//set_node_dependencies(dependent_node->node_id,validator_node_id,*relevant_dependencies,entity_functors,*N_node);
				functor_criteria.clear();
				functor_criteria.insert(std::make_pair("FUNCTOR",N_node->expression.lexeme+N_node->expression.lid+N_node->expression.gcat));
				find_functor_for_dependencies(dependent_node->node_id,validator_node_id,*full_dependency_table,functor_criteria,*N_node,entity_functors);
				if(entity_functors->result_rows()==1){
					if(N_node->command.functor.empty()==true){
						functors=entity_functors;
						rowid=entity_functors->result_set().begin()->first;
						N_node->command.functor=entity_functors.get_field_value(rowid,"FUNCTOR");
						N_node->command.d_key=entity_functors.get_field_value(rowid,"D_KEY");
						N_node->command.io_type=entity_functors.get_field_value(rowid,"IO_TYPE");
						N_node->command.argument=entity_functors.get_field_value(rowid,"ARGUMENT");
						N_node->command.definition=entity_functors.get_field_value(rowid,"DEFINITION");
					}
					else if(N_node->command.functor!=entity_functors.get_field_value(rowid,"FUNCTOR")
							&&N_node->command.d_key!=std::atoi(entity_functors.get_field_value(rowid,"D_KEY").c_str())
							&&N_node->command.io_type!=entity_functors.get_field_value(rowid,"IO_TYPE")){
						exit(EXIT_FAILURE);//TODO:Throw exception
					}
				}
				else if(entity_functors->result_rows()>1){
					functors=entity_functors;
				}
				else exit(EXIT_FAILURE);//TODO:Throw exception
				dependent_node->node_links.insert(std::make_pair(N_node->node_id,dependent_node->node_links.size()+1));
				N_node->node_links.insert(std::make_pair(dependent_node->node_id,N_node->node_links.size()+1));
			}
			if(head_dependency.node_id!=0){
				if(head_leaf.symbol=="V"){
					full_dependency_table=&head_leaf_dependency_table;
					relevant_dependencies=&relevant_head_dependencies;
					validator_node_id=non_head_leaf.node_id;
					V_node=&head_leaf;
					N_node=&non_head_leaf;
					dependent_node=&head_dependency;
				}
				else{
					full_dependency_table=&non_head_leaf_dependency_table;
					relevant_dependencies=&relevant_non_head_dependencies;
					validator_node_id=head_leaf.node_id;
					V_node=&non_head_leaf;
					N_node=&head_leaf;
					dependent_node=&non_head_dependency;
				}
				//generate d_key_list string which lists the d_keys of relevant_dependencies like: ('1', '2', ..., '3')
				d_key_list="(";
				for(j=*relevant_dependencies.begin();j!=*relevant_dependencies.end();++j){
					d_key<<j->second.functor_d_key;
					if(d_key_list.find("'"+d_key.str()+"'")==std::string::npos){
						d_key_list+="'"+d_key.str()+"',";
					}
				}
				d_key_list.resize(d_key_list.length()-1);//remove last ','
				d_key_list+=")";
				//select entries from RELATION_FUNCTORS into relation_functors with keys functor=head_node and d_key is in dependency_entries.d_key and io_type=non_head_node and definition_type=executable
				relation_functors=sqlite->exec_sql("SELECT * FROM RELATION_FUNCTORS WHERE FUNCTOR = '"+functor+"' AND D_KEY IN "+d_key_list+" AND IO_TYPE = '"+io_type+"';");
				if(relation_functors==NULL) exit(EXIT_FAILURE);
				//loop over relation_functors into relation_functor
					//put the pair of non_head_node and head_dependency node into head_node.dependency_validation matrix with the row_index of dependency_entry in dependency_entries
					//where dependency_entry.lexeme=relation_functor.lexeme and dependency_entry.d_key=relation_functor.d_key
				//endloop
				//set_node_dependencies(dependent_node->node_id,validator_node_id,*relevant_dependencies,relation_functors,V_node);
				functor_criteria.clear();
				functor_criteria.insert(std::make_pair("FUNCTOR",V_node->expression.lexeme+V_node->expression.lid+V_node->expression.gcat));
				functor_criteria.insert(std::make_pair("IO_TYPE",N_node->expression.lexeme+N_node->expression.lid+N_node->expression.gcat));
				//functor_criteria.insert(std::make_pair("DEFINITION_TYPE","0"));
				find_functor_for_dependencies(dependent_node->node_id,validator_node_id,*full_dependency_table,functor_criteria,*V_node,relation_functors);
				if(relation_functors->result_rows()==1){
					if(V_node->command.functor.empty()==true){
						functors=relation_functors;
						rowid=relation_functors->result_set().begin()->first;
						V_node->command.functor=relation_functors.get_field_value(rowid,"FUNCTOR");
						V_node->command.d_key=relation_functors.get_field_value(rowid,"D_KEY");
						V_node->command.io_type=relation_functors.get_field_value(rowid,"IO_TYPE");
						V_node->command.argument=relation_functors.get_field_value(rowid,"ARGUMENT");
						V_node->command.definition_type=relation_functors.get_field_value(rowid,"DEFINITION_TYPE");
						V_node->command.definition=relation_functors.get_field_value(rowid,"DEFINITION");
					}
					else if(V_node->command.functor!=relation_functors.get_field_value(rowid,"FUNCTOR")
							&&V_node->command.d_key!=std::atoi(relation_functors.get_field_value(rowid,"D_KEY").c_str())
							&&V_node->command.io_type!=relation_functors.get_field_value(rowid,"IO_TYPE")){
						exit(EXIT_FAILURE);//TODO:Throw exception
					}
				}
				else if(relation_functors->result_rows()>1){
					functors=relation_functors;
				}
				else exit(EXIT_FAILURE);//TODO:Throw exception
				dependent_node->node_links.insert(std::make_pair(V_node->node_id,dependent_node->node_links.size()+1));
				V_node->node_links.insert(std::make_pair(dependent_node->node_id,V_node->node_links.size()+1));
				V_node->node_links.insert(std::make_pair(N_node->node_id,V_node->node_links.size()+1));
				N_node->node_links.insert(std::make_pair(V->node_id,N_node->node_links.size()+1));
			}
			if(functors==NULL)//Only execute query if functors==NULL, as functors may have been filled due to finding a complete/partial dependency
				functors=sqlite->exec_sql("SELECT * FROM RELATION_FUNCTORS WHERE FUNCTOR = '"+functor+"' AND IO_TYPE = '"+io_type+"' AND DEFINITION_TYPE = 0;");
		}
		else if(head_leaf.symbol=="N"&&non_head_leaf.symbol=="ADJ"||head_leaf.symbol=="ADJ"&&non_head_leaf.symbol=="N"){
			if(head_leaf.symbol=="N"&&non_head_leaf.symbol=="ADJ"){
				io_type=head_leaf.expression.lexeme+head_leaf.expression.lid+head_leaf.expression.gcat;
				functor=non_head_leaf.expression.lexeme+non_head_leaf.expression.lid+non_head_leaf.expression.gcat;
			}
			else{
				io_type=non_head_leaf.expression.lexeme+non_head_leaf.expression.lid+non_head_leaf.expression.gcat;
				functor=head_leaf.expression.lexeme+head_leaf.expression.lid+head_leaf.expression.gcat;
			}
			if(non_head_dependency.node_id!=0){
				if(non_head_leaf.symbol=="N"){
					full_dependency_table=&non_head_leaf_dependency_table;
					relevant_dependencies=&relevant_non_head_dependencies;
					validator_node_id=head_leaf.node_id;
					N_node=&non_head_leaf;
					dependent_node=&non_head_dependency;
				}
				else{
					full_dependency_table=&head_leaf_dependency_table;
					relevant_dependencies=&relevant_head_dependencies;
					validator_node_id=non_head_leaf.node_id;
					N_node=&head_leaf;
					dependent_node=&head_dependency;
				}
				//generate d_key_list string which lists the d_keys of relevant_dependencies like: ('1', '2', ..., '3')
				d_key_list="(";
				for(j=*relevant_dependencies.begin();j!=*relevant_dependencies.end();++j){
					d_key<<j->second.functor_d_key;
					if(d_key_list.find("'"+d_key.str()+"'")==std::string::npos){
						d_key_list+="'"+d_key.str()+"',";
					}
				}
				d_key_list.resize(d_key_list.length()-1);//remove last ','
				d_key_list+=")";
				entity_functors=sqlite->exec_sql("SELECT * FROM ENTITY_FUNCTORS WHERE FUNCTOR = '"+io_type+"' AND D_KEY IN "+d_key_list+";");
				if(entity_functors==NULL) exit(EXIT_FAILURE);
				//set_node_dependencies(dependent_node->node_id,validator_node_id,*relevant_dependencies,entity_functors,*N_node);
				functor_criteria.clear();
				functor_criteria.insert(std::make_pair("FUNCTOR",N_node->expression.lexeme+N_node->expression.lid+N_node->expression.gcat));
				find_functor_for_dependencies(dependent_node->node_id,validator_node_id,*full_dependency_table,functor_criteria,*N_node,entity_functors);
				if(entity_functors->result_rows()==1){
					if(N_node->command.functor.empty()==true){
						functors=entity_functors;
						rowid=entity_functors->result_set().begin()->first;
						N_node->command.functor=entity_functors.get_field_value(rowid,"FUNCTOR");
						N_node->command.d_key=entity_functors.get_field_value(rowid,"D_KEY");
						N_node->command.io_type=entity_functors.get_field_value(rowid,"IO_TYPE");
						N_node->command.argument=entity_functors.get_field_value(rowid,"ARGUMENT");
						N_node->command.definition=entity_functors.get_field_value(rowid,"DEFINITION");
					}
					else if(N_node->command.functor!=entity_functors.get_field_value(rowid,"FUNCTOR")
							&&N_node->command.d_key!=std::atoi(entity_functors.get_field_value(rowid,"D_KEY").c_str())
							&&N_node->command.io_type!=entity_functors.get_field_value(rowid,"IO_TYPE")){
						exit(EXIT_FAILURE);//TODO:Throw exception
					}
				}
				else if(entity_functors->result_rows()>1){
					functors=entity_functors;
				}
				else exit(EXIT_FAILURE);//TODO:Throw exception
				dependent_node->node_links.insert(std::make_pair(N_node->node_id,dependent_node->node_links.size()+1));
				N_node->node_links.insert(std::make_pair(dependent_node->node_id,N_node->node_links.size()+1));
			}
			if(head_dependency.node_id!=0){
				if(head_leaf.symbol=="ADJ"){
					full_dependency_table=&head_leaf_dependency_table;
					relevant_dependencies=&relevant_head_dependencies;
					validator_node_id=non_head_leaf.node_id;
					ADJ_node=&head_leaf;
					N_node=&non_head_leaf;
					dependent_node=&head_dependency;
				}
				else{
					full_dependency_table=&non_head_leaf_dependency_table;
					relevant_dependencies=&relevant_non_head_dependencies;
					validator_node_id=head_leaf.node_id;
					ADJ_node=&non_head_leaf;
					N_node=&head_leaf;
					dependent_node=&non_head_dependency;
				}
				//generate d_key_list string which lists the d_keys of relevant_dependencies like: ('1', '2', ..., '3')
				d_key_list="(";
				for(j=*relevant_dependencies.begin();j!=*relevant_dependencies.end();++j){
					d_key<<j->second.functor_d_key;
					if(d_key_list.find("'"+d_key.str()+"'")==std::string::npos){
						d_key_list+="'"+d_key.str()+"',";
					}
				}
				d_key_list.resize(d_key_list.length()-1);//remove last ','
				d_key_list+=")";
				attribute_functors=sqlite->exec_sql("SELECT * FROM ATTRIBUTE_FUNCTORS WHERE FUNCTOR = '"+functor+"' AND D_KEY IN "+d_key_list+" AND IO_TYPE = '"+io_type+"';");
				if(attribute_functors==NULL) exit(EXIT_FAILURE);
				//set_node_dependencies(dependent_node->node_id,validator_node_id,*relevant_dependencies,attribute_functors,ADJ_node);
				functor_criteria.clear();
				functor_criteria.insert(std::make_pair("FUNCTOR",V_node->expression.lexeme+V_node->expression.lid+V_node->expression.gcat));
				functor_criteria.insert(std::make_pair("IO_TYPE",N_node->expression.lexeme+N_node->expression.lid+N_node->expression.gcat));
				//functor_criteria.insert(std::make_pair("DEFINITION_TYPE","0"));
				find_functor_for_dependencies(dependent_node->node_id,validator_node_id,*full_dependency_table,functor_criteria,*ADJ_node,attribute_functors);
				if(attribute_functors->result_rows()==1){
					if(ADJ_node->command.functor.empty()==true){
						functors=attribute_functors;
						rowid=attribute_functors->result_set().begin()->first;
						ADJ_node->command.functor=attribute_functors.get_field_value(rowid,"FUNCTOR");
						ADJ_node->command.d_key=attribute_functors.get_field_value(rowid,"D_KEY");
						ADJ_node->command.io_type=attribute_functors.get_field_value(rowid,"IO_TYPE");
						ADJ_node->command.argument=attribute_functors.get_field_value(rowid,"ARGUMENT");
						ADJ_node->command.definition_type=attribute_functors.get_field_value(rowid,"DEFINITION_TYPE");
						ADJ_node->command.definition=attribute_functors.get_field_value(rowid,"DEFINITION");
					}
					else if(ADJ_node->command.functor!=attribute_functors.get_field_value(rowid,"FUNCTOR")
							&&ADJ_node->command.d_key!=std::atoi(attribute_functors.get_field_value(rowid,"D_KEY").c_str())
							&&ADJ_node->command.io_type!=attribute_functors.get_field_value(rowid,"IO_TYPE")){
						exit(EXIT_FAILURE);//TODO:Throw exception
					}
				}
				else if(relation_functors->result_rows()>1){
					functors=relation_functors;
				}
				else exit(EXIT_FAILURE);//TODO:Throw exception
				dependent_node->node_links.insert(std::make_pair(ADJ_node->node_id,dependent_node->node_links.size()+1));
				ADJ_node->node_links.insert(std::make_pair(dependent_node->node_id,ADJ_node->node_links.size()+1));
				ADJ_node->node_links.insert(std::make_pair(N_node->node_id,ADJ_node->node_links.size()+1));
				N_node->node_links.insert(std::make_pair(ADJ_node->node_id,N_node->node_links.size()+1));
			}
			if(functors==NULL)//Only execute query if functors==NULL, as functors may have been filled due to finding a complete/partial dependency
				functors=sqlite->exec_sql("SELECT * FROM ATTRIBUTE_FUNCTORS WHERE FUNCTOR = '"+functor+"' AND IO_TYPE = '"+io_type+"';");
		}
		else if(head_leaf.symbol=="V"&&non_head_leaf.symbol=="ADV"||head_leaf.symbol=="ADV"&&non_head_leaf.symbol=="V"){
			if(head_leaf.symbol=="V"&&non_head_leaf.symbol=="ADV"){
				relation_functor=head_leaf.expression.lexeme+head_leaf.expression.lid+head_leaf.expression.gcat;
				adverb_functor=non_head_leaf.expression.lexeme+non_head_leaf.expression.lid+non_head_leaf.expression.gcat;
			}
			else{
				relation_functor=non_head_leaf.expression.lexeme+non_head_leaf.expression.lid+non_head_leaf.expression.gcat;
				adverb_functor=head_leaf.expression.lexeme+head_leaf.expression.lid+head_leaf.expression.gcat;
			}
			if(head_dependency.node_id!=0){
				if(head_leaf.symbol=="V"){
					full_dependency_table=&head_leaf_dependency_table;
					relevant_dependencies=&relevant_head_dependencies;
					validator_node_id=non_head_leaf.node_id;
					V_node=&head_leaf;
					ADV_node=&non_head_leaf;
					dependent_node=&head_dependency;
				}
				else{
					full_dependency_table=&non_head_leaf_dependency_table;
					relevant_dependencies=&relevant_non_head_dependencies;
					validator_node_id=head_leaf.node_id;
					V_node=&non_head_leaf;
					ADV_node=&head_leaf;
					dependent_node=&non_head_dependency;
				}
				//generate d_key_list string which lists the d_keys of relevant_dependencies like: ('1', '2', ..., '3')
				d_key_list="(";
				for(j=*relevant_dependencies.begin();j!=*relevant_dependencies.end();++j){
					d_key<<j->second.functor_d_key;
					if(d_key_list.find("'"+d_key.str()+"'")==std::string::npos){
						d_key_list+="'"+d_key.str()+"',";
					}
				}
				d_key_list.resize(d_key_list.length()-1);//remove last ','
				d_key_list+=")";
				functor_criteria.clear();
				functor_criteria.insert(std::make_pair("FUNCTOR",V_node->expression.lexeme+V_node->expression.lid+V_node->expression.gcat));
				//functor_criteria.insert(std::make_pair("DEFINITION_TYPE","0"));
				//generate io_type string which lists the io_types of the nouns already linked to the verb
				io_types="(";
				for(const std::map<unsigned int,unsigned int>::const_iterator i=V_node.node_links.begin();i!=V_node.node_links.end();++i){
					N_node=get_node_info(i->first);
					if(N_node.gcat=='N'){
						io_type=N_node.expression.lexeme+N_node.expression.lid+N_node.expression.gcat;
						if(io_types.find(io_type)==std::string::npos){
							io_types+="'"+io_type+"',";
							functor_criteria.insert(std::make_pair("IO_TYPE",io_type));
						}
					}
				}
				io_types.resize(io_types.length()-1);//remove last ','
				io_types+=")";
				//select entries from RELATION_FUNCTORS into relation_functors with keys functor=head_node and d_key is in dependency_entries.d_key and io_type=non_head_node and definition_type=executable
				if(io_types=="()"){
					relation_functors=sqlite->exec_sql("SELECT * FROM RELATION_FUNCTORS WHERE FUNCTOR = '"+relation_functor+"' AND D_KEY IN "+d_key_list+";");
				}
				else{
					relation_functors=sqlite->exec_sql("SELECT * FROM RELATION_FUNCTORS WHERE FUNCTOR = '"+relation_functor+"' AND D_KEY IN "+d_key_list+" AND IO_TYPE IN "+io_types+";");
				}
				if(relation_functors==NULL) exit(EXIT_FAILURE);
				//loop over relation_functors into relation_functor
					//put the pair of non_head_node and head_dependency node into head_node.dependency_validation matrix with the row_index of dependency_entry in dependency_entries
					//where dependency_entry.lexeme=relation_functor.lexeme and dependency_entry.d_key=relation_functor.d_key
				//endloop
				//set_node_dependencies(dependent_node->node_id,validator_node_id,*relevant_dependencies,relation_functors,V_node);
				find_functor_for_dependencies(dependent_node->node_id,validator_node_id,*full_dependency_table,functor_criteria,*V_node,relation_functors);
				if(relation_functors->result_rows()==1){
					if(V_node->command.functor.empty()==true){
						functors=relation_functors;
						rowid=relation_functors->result_set().begin()->first;
						V_node->command.functor=relation_functors.get_field_value(rowid,"FUNCTOR");
						V_node->command.d_key=relation_functors.get_field_value(rowid,"D_KEY");
						V_node->command.io_type=relation_functors.get_field_value(rowid,"IO_TYPE");
						V_node->command.argument=relation_functors.get_field_value(rowid,"ARGUMENT");
						V_node->command.definition_type=relation_functors.get_field_value(rowid,"DEFINITION_TYPE");
						V_node->command.definition=relation_functors.get_field_value(rowid,"DEFINITION");
					}
					else if(V_node->command.functor!=relation_functors.get_field_value(rowid,"FUNCTOR")
							&&V_node->command.d_key!=std::atoi(relation_functors.get_field_value(rowid,"D_KEY").c_str())
							&&V_node->command.io_type!=relation_functors.get_field_value(rowid,"IO_TYPE")){
						exit(EXIT_FAILURE);//TODO:Throw exception
					}
				}
				else if(relation_functors->result_rows()>1){
					functors=relation_functors;
				}
				else exit(EXIT_FAILURE);//TODO:Throw exception
				dependent_node->node_links.insert(std::make_pair(V_node->node_id,dependent_node->node_links.size()+1));
				V_node->node_links.insert(std::make_pair(dependent_node->node_id,V_node->node_links.size()+1));
			}
			if(head_dependency.node_id!=0){
				if(head_leaf.symbol=="ADV"){
					full_dependency_table=&head_leaf_dependency_table;
					relevant_dependencies=&relevant_head_dependencies;
					validator_node_id=non_head_leaf.node_id;
					ADV_node=&head_leaf;
					V_node=&non_head_leaf;
					dependent_node=&head_dependency;
				}
				else{
					full_dependency_table=&non_head_leaf_dependency_table;
					relevant_dependencies=&relevant_non_head_dependencies;
					validator_node_id=head_leaf.node_id;
					ADV_node=&non_head_leaf;
					V_node=&head_leaf;
					dependent_node=&non_head_dependency;
				}
				//generate d_key_list string which lists the d_keys of relevant_dependencies like: ('1', '2', ..., '3')
				d_key_list="(";
				for(j=*relevant_dependencies.begin();j!=*relevant_dependencies.end();++j){
					d_key<<j->second.functor_d_key;
					if(d_key_list.find("'"+d_key.str()+"'")==std::string::npos){
						d_key_list+="'"+d_key.str()+"',";
					}
				}
				d_key_list.resize(d_key_list.length()-1);//remove last ','
				d_key_list+=")";
				functor_criteria.clear();
				functor_criteria.insert(std::make_pair("FUNCTOR",adverb_functor));
				functor_criteria.insert(std::make_pair("RELATION_FUNCTOR",V_node->expression.lexeme+V_node->expression.lid+V_node->expression.gcat));
				nr_of_functors=relation_functors.result_rows();
				relation_d_keys="(";
				io_types="(";
				for(unsigned int k=0;k<nr_of_functors;++k){
					relation_d_key=relation_functors.get_field_value(k,"D_KEY");
					if(relation_d_keys.find("'"+relation_d_key+"'")==std::string::npos){
						relation_d_keys+="'"+relation_d_key+"',";
						functor_criteria.insert(std::make_pair("RELATION_D_KEY",relation_d_key));
					}
					io_type=relation_functors.get_field_value(k,"IO_TYPE");
					if(io_types.find("'"+io_type+"'")==std::string::npos){
						io_types+="'"+io_type+"',";
						functor_criteria.insert(std::make_pair("RELATION_IO_TYPE",io_type));
					}
				}
				relation_d_keys.resize(relation_d_keys.length()-1);//remove last ','
				relation_d_keys+=")";
				io_types.resize(io_types.length()-1);//remove last ','
				io_types+=")";
				if(io_types=="()"){
					adverb_functors=sqlite->exec_sql("SELECT * FROM ADVERB_FUNCTORS WHERE FUNCTOR = '"+adverb_functor+"' AND D_KEY IN "+d_key_list+" AND RELATION_FUNCTOR = '"+relation_functor+"' AND RELATION_D_KEY IN "+relation_d_keys+";");
				}
				else{
					//TODO: due the the nature of sql in-lists, the result set contains the Cartesian product of
					//relation_d_key and relation_io_type. That is, the relation_d_keys are not bound to the
					//corresponding relation_io_type which can yield wrong results.
					adverb_functors=sqlite->exec_sql("SELECT * FROM ADVERB_FUNCTORS WHERE FUNCTOR = '"+adverb_functor+"' AND D_KEY IN "+d_key_list+" AND RELATION_FUNCTOR = '"+relation_functor+"' AND RELATION_D_KEY IN "+relation_d_keys+" AND RELATION_IO_TYPE IN "+io_types+";");
				}
				if(attribute_functors==NULL) exit(EXIT_FAILURE);
				//set_node_dependencies(dependent_node->node_id,validator_node_id,*relevant_dependencies,attribute_functors,ADJ_node);
				//functor_criteria.insert(std::make_pair("DEFINITION_TYPE","0"));
				find_functor_for_dependencies(dependent_node->node_id,validator_node_id,*full_dependency_table,functor_criteria,*ADV_node,adverb_functors);
				if(adverb_functors->result_rows()==1){
					if(ADV_node->command.functor.empty()==true){
						functors=adverb_functors;
						rowid=adverb_functors->result_set().begin()->first;
						ADV_node->command.functor=adverb_functors.get_field_value(rowid,"FUNCTOR");
						ADV_node->command.d_key=adverb_functors.get_field_value(rowid,"D_KEY");
						ADV_node->command.relation_functor=adverb_functors.get_field_value(rowid,"RELATION_FUNCTOR");
						ADV_node->command.relation_d_key=adverb_functors.get_field_value(rowid,"RELATION_D_KEY");
						ADV_node->command.relation_io_type=adverb_functors.get_field_value(rowid,"RELATION_IO_TYPE");
						ADV_node->command.argument=adverb_functors.get_field_value(rowid,"ARGUMENT");
						ADV_node->command.definition_type=adverb_functors.get_field_value(rowid,"DEFINITION_TYPE");
						ADV_node->command.definition=adverb_functors.get_field_value(rowid,"DEFINITION");
					}
					else if(ADV_node->command.functor!=adverb_functors.get_field_value(rowid,"FUNCTOR")
							&&ADV_node->command.d_key!=std::atoi(adverb_functors.get_field_value(rowid,"D_KEY").c_str())
							&&ADV_node->command.functor!=adverb_functors.get_field_value(rowid,"RELATION_FUNCTOR")
							&&ADV_node->command.d_key!=std::atoi(adverb_functors.get_field_value(rowid,"RELATION_D_KEY").c_str())
							&&ADV_node->command.io_type!=adverb_functors.get_field_value(rowid,"RELATION_IO_TYPE")){
						exit(EXIT_FAILURE);//TODO:Throw exception
					}
				}
				else if(adverb_functors->result_rows()>1){
					functors=adverb_functors;
				}
				else exit(EXIT_FAILURE);//TODO:Throw exception
				dependent_node->node_links.insert(std::make_pair(ADV_node->node_id,dependent_node->node_links.size()+1));
				ADV_node->node_links.insert(std::make_pair(dependent_node->node_id,ADV_node->node_links.size()+1));
				ADV_node->node_links.insert(std::make_pair(V_node->node_id,ADV_node->node_links.size()+1));
				V_node->node_links.insert(std::make_pair(ADV_node->node_id,V_node->node_links.size()+1));
			}
			if(functors==NULL)//Only execute query if functors==NULL, as functors may have been filled due to finding a complete/partial dependency
				functors=sqlite->exec_sql("SELECT * FROM ADVERB_FUNCTORS WHERE FUNCTOR = '"+functor+"' AND RELATION_FUNCTOR = '"+relation_functor+"';");
		}
		else if(head_leaf.symbol=="V"&&non_head_leaf.symbol!="N"&&non_head_leaf.symbol!="ADV"&&non_head_leaf.symbol!="ADJ"||
				non_head_leaf.symbol=="V"&&head_leaf.symbol!="N"&&head_leaf.symbol!="ADV"&&head_leaf.symbol!="ADJ"){
			if(head_dependency.node_id!=0){
				if(head_leaf.symbol=="V"){
					full_dependency_table=&head_leaf_dependency_table;
					relevant_dependencies=&relevant_head_dependencies;
					validator_node_id=non_head_leaf.node_id;
					V_node=&head_leaf;
					NC_node=&non_head_leaf;
					dependent_node=&head_dependency;
				}
				else{
					full_dependency_table=&non_head_leaf_dependency_table;
					relevant_dependencies=&relevant_non_head_dependencies;
					validator_node_id=head_leaf.node_id;
					V_node=&non_head_leaf;
					NC_node=&head_leaf;
					dependent_node=&non_head_dependency;
				}
				//generate d_key_list string which lists the d_keys of relevant_dependencies like: ('1', '2', ..., '3')
				d_key_list="(";
				for(j=*relevant_dependencies.begin();j!=*relevant_dependencies.end();++j){
					d_key<<j->second.functor_d_key;
					if(d_key_list.find("'"+d_key.str()+"'")==std::string::npos){
						d_key_list+="'"+d_key.str()+"',";
					}
				}
				d_key_list.resize(d_key_list.length()-1);//remove last ','
				d_key_list+=")";
				functor_criteria.clear();
				functor_criteria.insert(std::make_pair("FUNCTOR",V_node->expression.lexeme+V_node->expression.lid+V_node->expression.gcat));
				//functor_criteria.insert(std::make_pair("DEFINITION_TYPE","0"));
				//generate io_type string which lists the io_types of the nouns already linked to the verb
				io_types="(";
				for(const std::map<unsigned int,unsigned int>::const_iterator i=V_node.node_links.begin();i!=V_node.node_links.end();++i){
					N_node=get_node_info(i->first);
					if(N_node.gcat=='N'){
						io_type=N_node.expression.lexeme+N_node.expression.lid+N_node.expression.gcat;
						if(io_types.find(io_type)==std::string::npos){
							io_types+="'"+io_type+"',";
							functor_criteria.insert(std::make_pair("IO_TYPE",io_type));
						}
					}
				}
				io_types.resize(io_types.length()-1);//remove last ','
				io_types+=")";
				//select entries from RELATION_FUNCTORS into relation_functors with keys functor=head_node and d_key is in dependency_entries.d_key and io_type=non_head_node and definition_type=executable
				if(io_types=="()"){
					relation_functors=sqlite->exec_sql("SELECT * FROM RELATION_FUNCTORS WHERE FUNCTOR = '"+relation_functor+"' AND D_KEY IN "+d_key_list+";");
				}
				else{
					relation_functors=sqlite->exec_sql("SELECT * FROM RELATION_FUNCTORS WHERE FUNCTOR = '"+relation_functor+"' AND D_KEY IN "+d_key_list+" AND IO_TYPE IN "+io_types+";");
				}
				if(relation_functors==NULL) exit(EXIT_FAILURE);
				//loop over relation_functors into relation_functor
					//put the pair of non_head_node and head_dependency node into head_node.dependency_validation matrix with the row_index of dependency_entry in dependency_entries
					//where dependency_entry.lexeme=relation_functor.lexeme and dependency_entry.d_key=relation_functor.d_key
				//endloop
				//set_node_dependencies(dependent_node->node_id,validator_node_id,*relevant_dependencies,relation_functors,V_node);
				find_functor_for_dependencies(dependent_node->node_id,validator_node_id,*full_dependency_table,functor_criteria,*V_node,relation_functors);
				if(relation_functors->result_rows()==1){
					if(V_node->command.functor.empty()==true){
						functors=relation_functors;
						rowid=relation_functors->result_set().begin()->first;
						V_node->command.functor=relation_functors.get_field_value(rowid,"FUNCTOR");
						V_node->command.d_key=relation_functors.get_field_value(rowid,"D_KEY");
						V_node->command.io_type=relation_functors.get_field_value(rowid,"IO_TYPE");
						V_node->command.argument=relation_functors.get_field_value(rowid,"ARGUMENT");
						V_node->command.definition_type=relation_functors.get_field_value(rowid,"DEFINITION_TYPE");
						V_node->command.definition=relation_functors.get_field_value(rowid,"DEFINITION");
					}
					else if(V_node->command.functor!=relation_functors.get_field_value(rowid,"FUNCTOR")
							&&V_node->command.d_key!=std::atoi(relation_functors.get_field_value(rowid,"D_KEY").c_str())
							&&V_node->command.io_type!=relation_functors.get_field_value(rowid,"IO_TYPE")){
						exit(EXIT_FAILURE);//TODO:Throw exception
					}
				}
				else if(relation_functors->result_rows()>1){
					functors=relation_functors;
				}
				else exit(EXIT_FAILURE);//TODO:Throw exception
				dependent_node->node_links.insert(std::make_pair(V_node->node_id,dependent_node->node_links.size()+1));
				V_node->node_links.insert(std::make_pair(dependent_node->node_id,V_node->node_links.size()+1));
			}
			if(non_head_dependency.node_id!=0){
				if(head_leaf.symbol=="V"){
					full_dependency_table=&head_leaf_dependency_table;
					relevant_dependencies=&relevant_head_dependencies;
					validator_node_id=non_head_leaf.node_id;
					V_node=&head_leaf;
					NC_node=&non_head_leaf;
					dependent_node=&head_dependency;
				}
				else{
					full_dependency_table=&non_head_leaf_dependency_table;
					relevant_dependencies=&relevant_non_head_dependencies;
					validator_node_id=head_leaf.node_id;
					V_node=&non_head_leaf;
					NC_node=&head_leaf;
					dependent_node=&non_head_dependency;
				}
				//generate d_key_list string which lists the d_keys of relevant_dependencies like: ('1', '2', ..., '3')
				d_key_list="(";
				for(j=*relevant_dependencies.begin();j!=*relevant_dependencies.end();++j){
					d_key<<j->second.functor_d_key;
					if(d_key_list.find("'"+d_key.str()+"'")==std::string::npos){
						d_key_list+="'"+d_key.str()+"',";
					}
				}
				d_key_list.resize(d_key_list.length()-1);//remove last ','
				d_key_list+=")";
				set_functorless_node_dependencies(dependent_node->node_id,validator_node_id,*relevant_dependencies,NC_node);
				dependent_node->node_links.insert(std::make_pair(NC_node->node_id,dependent_node->node_links.size()+1));
				NC_node->node_links.insert(std::make_pair(dependent_node->node_id,NC_node->node_links.size()+1));
				V_node->node_links.insert(std::make_pair(NC_node->node_id,V_node->node_links.size()+1));
				NC_node->node_links.insert(std::make_pair(V->node_id,NC_node->node_links.size()+1));
			}
		}
		else if(head_leaf.symbol=="N"&&non_head_leaf.symbol!="V"&&non_head_leaf.symbol!="ADV"&&non_head_leaf.symbol!="ADJ"||
				non_head_leaf.symbol=="V"&&head_leaf.symbol!="N"&&head_leaf.symbol!="ADV"&&head_leaf.symbol!="ADJ"){
		}
		else if(head_leaf.symbol=="ADJ"&&non_head_leaf.symbol!="V"&&non_head_leaf.symbol!="ADV"&&non_head_leaf.symbol!="N"||
				non_head_leaf.symbol=="ADJ"&&head_leaf.symbol!="V"&&head_leaf.symbol!="ADV"&&head_leaf.symbol!="N"){
		}
		else if(head_leaf.symbol=="ADV"&&non_head_leaf.symbol!="V"&&non_head_leaf.symbol!="ADJ"&&non_head_leaf.symbol!="N"||
				non_head_leaf.symbol=="ADV"&&head_leaf.symbol!="V"&&head_leaf.symbol!="ADJ"&&head_leaf.symbol!="N"){
		}
		if(functors->result_set().empty()==true){
			delete functors;
			return NULL;
		}
		else return functors;
	}
	else exit(EXIT_FAILURE);//TODO: throw exception
}

void interpreter::set_functorless_node_dependencies(const unsigned int dependent_node_id,const unsigned int validator_node_id,
		const std::multimap<unsigned int,depolex>& dependencies, node_info& node){
	unsigned int nr_of_functors=0;
	std::multimap<unsigned int,depolex>::const_iterator j;
	dependency_validation_pair dependency_pair;

	nr_of_functors=functors.result_rows();
	for(j=dependencies.begin();j!=dependencies.end();++j){
		for(unsigned int i=0;i<nr_of_functors;++i){
			if(functors.get_field_value(i,"FUNCTOR")==j->second.lexeme
					&&std::atoi(functors.get_field_value(i,"D_KEY").c_str())==j->second.functor_d_key){
				//TODO: Shall any further checks be performed for duplicate entries in the
				//dependency_validation_matrix?
				dependency_pair.dependent_node_id=dependent_node_id;
				dependency_pair.validator_node_id=validator_node_id;
				node.dependency_validation_matrix.insert(std::make_pair(j->first,dependency_pair));
			}
		}
	}
}

void interpreter::find_functor_for_dependencies(const unsigned int dependent_node_id, const unsigned int validator_node_id,const std::multimap<unsigned int,depolex>& dependencies,const std::multimap<std::string,std::string>& functor_criteria,
		node_info& node,query_result& functors){
	std::map<std::string,std::string>::const_iterator l;
	std::multimap<unsigned int,depolex>::const_iterator j;
	unsigned int rowid_of_functor_found=0,previous_iteration_d_key,nr_of_functors=0;
	std::set<unsigned int> rowids_to_keep;
	bool complete_dependency_found,partial_dependency_found;
	node_info dependent_node;
	dependency_validation_pair dependency_pair;
	std::pair <std::multimap<std::string,std::string>::const_iterator,std::string,std::string>::const_iterator> range;

	//if all the d_counter dependency entries of a dependency of a functor belonging to a relation_functor
	//entry can be found in head_node.dependency_validation_matrix in pair with the non_head_node:
	//check if head_node.command already contains an executable relation_functor entry with a different key
	//and if so, throw exception, otherwise insert the relation_functor entry just validated.
	//Remark: This way that the dependencies are put together with the noun in the validation matrix,
	//the first noun with all the dependencies of the verb that match an executable relation_functor
	//gets validated. If nouns were not stored together with the dependencies in the matrix, different
	//iterations with different nouns would validate dependencies which would result in
	//a wrong relation_functor.
	complete_dependency_found=true;
	for(j=dependencies.begin(),previous_iteration_d_key=j->second.d_key;j!=dependencies.end();++j){
		if(previous_iteration_d_key==j->second.d_key){
			if(complete_dependency_found==true){
				dependent_node=get_node_info(dependent_node_id);
				if(j->second.lexeme==node.expression.lexeme+node.expression.lid+node.expression.gcat
						&&j->second.semantic_dependency==dependent_node.expression.lexeme+dependent_node.expression.lid+dependent_node.expression.gcat){
					//read table relation_functor_table with functor=head_leaf.expression.lexeme+lid+gcat
					//and d_key=d_key of current iteration and io_type=non_head_leaf.expression.lexeme+lid+gcat
					//and definition_type=function_definition
					//into relation_functor_found;
					nr_of_functors=functors.result_rows();
					for(unsigned int k=0;k<nr_of_functors;++k){
						if(functors.get_field_value(k,"D_KEY")==j->second.functor_d_key){
							for(l=functor_criteria.begin(),range=functor_criteria.equal_range(l->first);l!=functor_criteria.end();++l){
								if(l>=range->first){
									for(;range->first!=range->second;++range->first){
										if(range->first->first!="D_KEY"&&functors.get_field_value(k,range->first->first)==range->first->second) break;//passing in D_KEY criterion is illegal, ignore if it comes in
									}
									if(range->first==range->second) break;//not any criterion in range matched the functor
								}
							}
						}
						if(l==functor_criteria.end()){
							rowid_of_functor_found=k;
							dependency_pair.dependent_node_id=dependent_node_id;
							dependency_pair.validator_node_id=validator_node_id;
							node.dependency_validation_matrix.insert(std::make_pair(j->first,dependency_pair));
							break;
						}
					}
				}
				else{
					partial_dependency_found=false;
					for(m=node.dependency_validation_matrix.lower_bound(j->first);m!=node.dependency_validation_matrix.upper_bound(j->first);++m){
						if(m->second.validator_node_id==validator_node_id){
							dependent_node=get_node_info(m->second.dependent_node_id);
							if(j->second.semantic_dependency==dependent_node.expression.lexeme+dependent_node.expression.lid+dependent_node.expression.gcat){
								partial_dependency_found=true;
								break;
							}
						}
					}
					if(partial_dependency_found==false)
						complete_dependency_found=false;
				}
			}
		}
		else{
			if(complete_dependency_found==true){
				rowids_to_keep.insert(rowid_of_functor_found);
				functors.keep(rowids_to_keep);
				//TODO:This does NOT guarantee that the entry for the functor with the d_key found is executable
				//i.e. that the definition_type=0. So the executable entry needs to be looked up later...
				break;
			}
			else{
				complete_dependency_found=true;
			}
		}
		previous_iteration_d_key=j->second.d_key;
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

bool interpreter::is_valid_combination(const std::string& symbol, const node_info& new_phrase_head_root, const node_info& new_phrase_non_head_root){
	std::string entity,argument,command,constant,options,options_field_value, preposition_field_value,
				argument_field_value, command_field_value, entity_field_value, is_a_field_value, lexeme;
	bool valid_combination=false;
	unsigned int preposition_matched[256],rule_to_rule_map_entry_index=0;
	db *sqlite=NULL;
	rule_to_rule_map rule_to_rule_map_entry={};
	query_result *functors=NULL, *rule_to_rule_map_result=NULL;
	std::map<unsigned int,unsigned int> dependency_validation_matrix;//uint1:row_index of dependency entry, uint2: true=validated node
	std::multimap<unsigned int,field>::const_iterator i;
	std::vector<unsigned int>::const_iterator j,k,l,m;
	std::vector<unsigned int> head_nodes_found_by_symbol,head_d_nodes_found_by_symbol,non_head_nodes_found_by_symbol,non_head_d_nodes_found_by_symbol;
	node_info empty_nodeinfo={};

	sqlite=db::get_instance();
	rule_to_rule_map_result=sqlite->exec_sql("SELECT * FROM RULE_TO_RULE_MAP WHERE PARENT_SYMBOL = '"+symbol+"' AND HEAD_ROOT_SYMBOL = '"+new_phrase_head_root.symbol+"' AND NON_HEAD_ROOT_SYMBOL = '"+new_phrase_non_head_root.symbol+"';");
	//TODO: Each and every combination must have a rule_to_rule_map entry, otherwise the combined nodes cannot be validated i.e. the node_links in the corresponding nodes
	//won't be crossreferenced. Thus later, checking for dependencies would not take into account such nodes that aren't referenced in node_links. Therefore, is_valid_expression()
	//must be extended in a way that each base node-non base node combination looks up their dependencies as well.
	if(rule_to_rule_map_result==NULL) exit(EXIT_FAILURE);
	const std::multimap<unsigned int,field>& rule_to_rule_map=rule_to_rule_map_result->result_set();
	for(i=rule_to_rule_map.begin();i!=rule_to_rule_map.end();++i){
		if(i->second.field_name=="parent_symbol"){
			rule_to_rule_map_entry.parent_symbol=i->second.field_value;
		}
		else if(i->second.field_name=="head_root_symbol"){
			rule_to_rule_map_entry.head_root_symbol=i->second.field_value;
		}
		else if(i->second.field_name=="non_head_root_symbol"){
			rule_to_rule_map_entry.non_head_root_symbol=i->second.field_value;
		}
		else if(i->second.field_name=="step"){
			rule_to_rule_map_entry.step=std::atoi(i->second.field_value.c_str());
		}
		else if(i->second.field_name=="head_node_symbol"){
			rule_to_rule_map_entry.head_node_symbol=i->second.field_value;
		}
		else if(i->second.field_name=="head_d_node_symbol"){
			rule_to_rule_map_entry.head_d_node_symbol=i->second.field_value;
		}
		else if(i->second.field_name=="head_dependency_lookup_root"){
			rule_to_rule_map_entry.head_dependency_lookup_root=i->second.field_value;
		}
		else if(i->second.field_name=="non_head_node_symbol"){
			rule_to_rule_map_entry.non_head_node_symbol=i->second.field_value;
		}
		else if(i->second.field_name=="non_head_d_node_symbol"){
			rule_to_rule_map_entry.non_head_d_node_symbol=i->second.field_value;
		}
		else if(i->second.field_name=="non_head_dependency_lookup_root"){
			rule_to_rule_map_entry.non_head_dependency_lookup_root=i->second.field_value;
			++rule_to_rule_map_entry_index;
		}
		else exit(EXIT_FAILURE);
		if(rule_to_rule_map_entry_index>0&&rule_to_rule_map_entry_index==i->first+1){
			if(rule_to_rule_map_entry.head_root_symbol==new_phrase_head_root.symbol&&rule_to_rule_map_entry.non_head_root_symbol==new_phrase_non_head_root.symbol){
				get_nodes_by_symbol(new_phrase_head_root,rule_to_rule_map_entry.head_node_symbol,head_nodes_found_by_symbol);
				get_nodes_by_symbol(new_phrase_non_head_root,rule_to_rule_map_entry.non_head_node_symbol,non_head_nodes_found_by_symbol);
				if(rule_to_rule_map_entry.head_d_node_symbol.empty()==false){
					if(rule_to_rule_map_entry.head_dependency_lookup_root=="H")
						get_nodes_by_symbol(new_phrase_head_root,rule_to_rule_map_entry.head_d_node_symbol,head_d_nodes_found_by_symbol);
					else if(rule_to_rule_map_entry.head_dependency_lookup_root=="N")
						get_nodes_by_symbol(new_phrase_non_head_root,rule_to_rule_map_entry.head_d_node_symbol,head_d_nodes_found_by_symbol);
					else
						get_nodes_by_symbol(new_phrase_head_root,rule_to_rule_map_entry.head_d_node_symbol,head_d_nodes_found_by_symbol);
						get_nodes_by_symbol(new_phrase_non_head_root,rule_to_rule_map_entry.head_d_node_symbol,head_d_nodes_found_by_symbol);
				}
				if(rule_to_rule_map_entry.non_head_d_node_symbol.empty()==false){
					if(rule_to_rule_map_entry.non_head_dependency_lookup_root=="H")
						get_nodes_by_symbol(new_phrase_head_root,rule_to_rule_map_entry.non_head_d_node_symbol,non_head_d_nodes_found_by_symbol);
					else if(rule_to_rule_map_entry.non_head_dependency_lookup_root=="N")
						get_nodes_by_symbol(new_phrase_non_head_root,rule_to_rule_map_entry.non_head_d_node_symbol,non_head_d_nodes_found_by_symbol);
					else
						get_nodes_by_symbol(new_phrase_head_root,rule_to_rule_map_entry.non_head_d_node_symbol,non_head_d_nodes_found_by_symbol);
						get_nodes_by_symbol(new_phrase_non_head_root,rule_to_rule_map_entry.non_head_d_node_symbol,non_head_d_nodes_found_by_symbol);
				}
				//1)Loop over head_nodes_found_by_symbol
				for(j=head_nodes_found_by_symbol.begin();j!=head_nodes_found_by_symbol.end();++j){
					std::cout<<"loop pass on head_nodes_found_by_symbol:"<<*j<<std::endl;
					node_info& head_node=get_private_node_info(*j);
					//2)Loop over non_head_nodes_found_by_symbol where non_head_node is NOT in current_head_node.node_links
					for(k=non_head_nodes_found_by_symbol.begin();k!=non_head_nodes_found_by_symbol.end();++k){
						std::cout<<"loop pass on non_head_nodes_found_by_symbol:"<<*k<<std::endl;
						node_info& non_head_node=get_private_node_info(*k);
						if(std::find(head_node.node_links.begin(),head_node.node_links.end(),non_head_node.node_id)==head_node.node_links.end()){
							if(head_d_nodes_found_by_symbol.empty()==false){//TODO: cover other branches for non_head_d_nodes
								//3)Loop over head_d_nodes_found_by_symbol
								for(l=head_d_nodes_found_by_symbol.begin();l!=head_d_nodes_found_by_symbol.end();++l){
									if(non_head_d_nodes_found_by_symbol.empty()==false){
										//4)Loop over non_head_d_nodes_found_by_symbol
										for(m=non_head_d_nodes_found_by_symbol.begin();m!=non_head_d_nodes_found_by_symbol.end();++m){
											functors=is_valid_expression(head_node,non_head_node,get_private_node_info(*l),get_private_node_info(*m));
										}
									}
									else{
										???
									}
								}
							}
							else{???
								functors=is_valid_expression(head_node,non_head_node,empty_nodeinfo,empty_nodeinfo);
							}
						}
					}
				}
			}
			else exit(EXIT_FAILURE);//TODO: throw exception
		}
	}
	if(functors!=NULL) valid_combination=true;
	delete functors;
	delete rule_to_rule_map_result;
	//END OF universal head driven approach

/*
	const node_info& head_node=get_node_info(get_head_node(left_node));
	if(head_node.symbol=="V"){
		const node_info& object_node=get_node_info(get_object_node(right_node));
		if(right_node.symbol=="NP"){
			if(object_node.expression.empty()==false){
				sqlite=is_valid_expression_of_type(object_node.expression);
				if(sqlite==NULL){
					return false;
				}
				options_field_value=sqlite->get_field_value(0,"options");
				command=options_field_value;
			}
			Get all entries for relation in head node
			sqlite=is_valid_expression_of_type(head_node.expression,"RELATIONS");
			if(sqlite==NULL){
				return false;
			}
			for(i=0;i<sqlite->result_size();++i){
				At least one entry must exist for the transitive verb with no preposition specified
				preposition_field_value=sqlite->get_field_value(i,"preposition");
				if(preposition_field_value.empty()==true){
					preposition_matched[i]=1;Mark with 1 if preposition matches
					valid_combination=true;
				}
				else{
					preposition_matched[i]=0;
					valid_combination=false;
				}
			}
			Check entries where preposition matched
			for(i=0;i<sqlite->result_size();++i){
				if(preposition_matched[i]==1){
					argument_field_value=sqlite->get_field_value(i,"argument");
					if(argument_field_value==object_node.expression){
						valid_combination=true;
						command_field_value=sqlite->get_field_value(i,"command");
						if(command.empty()==true)command=command_field_value;
						else command+=command_field_value;
						if(object_node.right_child!=0)set_command(command,get_node_info(object_node.right_child).expression,"");
						else set_command(command,"","");
						break;
					}
				}
			}
		}
		else if(right_node.symbol=="PP"){
			Get all entries for relation in head node
			sqlite=is_valid_expression_of_type(head_node.expression,"RELATIONS");
			if(sqlite==NULL){
				return false;
			}
			const node_info& PP_head_node=get_node_info(get_head_node(right_node));
			for(i=0;i<sqlite->result_size();++i){
				At least one entry must exist for the transitive verb with the preposition specified in PP_head_node
				preposition_field_value=sqlite->get_field_value(i,"preposition");
				if(preposition_field_value==PP_head_node.expression){
					preposition_matched[i]=1;Mark with 1 if preposition matches
					valid_combination=true;
				}
				else{
					preposition_matched[i]=0;
					valid_combination=false;
				}
			}
			Check entries where preposition matched
			for(i=0;i<sqlite->result_size();++i){
				if(preposition_matched[i]==1){
					if(object_node.expression.empty()==false){
						argument_field_value=sqlite->get_field_value(i,"argument");
						if(argument_field_value==object_node.expression){
							valid_combination=true;
							command_field_value=sqlite->get_field_value(i,"command");
							command=command_field_value;
							if(object_node.right_child!=0)constant=get_node_info(object_node.right_child).expression;
							break;
						}
					}
					else{
						if(argument.empty()==true){
							argument_field_value=sqlite->get_field_value(i,"argument");
							argument=argument_field_value;
							command_field_value=sqlite->get_field_value(i,"command");
							command=command_field_value;
							if(object_node.right_child!=0)constant=get_node_info(object_node.right_child).expression;
							valid_combination=true;
						}
						else{
							argument_field_value=sqlite->get_field_value(i,"argument");
							if(argument_field_value!=argument){
								valid_combination=false;
								break;
							}
						}
					}
				}
			}
			if(valid_combination==true)set_command(command,constant,PP_head_node.expression);
			else return false;
		}
		else return false;
	}
	else{Entity tree traversal considering left_node->expression specific and object_node->expression general
		const node_info& object_node=get_node_info(get_object_node(right_node));
		entity=left_node.expression;
		do{
			sqlite=is_valid_expression_of_type(entity,"ENTITIES");
			if(sqlite==NULL){
				break;
			}
			entity_field_value=sqlite->get_field_value(0,"entity");
			is_a_field_value=sqlite->get_field_value(0,"is_a");
			entity=is_a_field_value;
			if(object_node.expression==entity) valid_combination=true;
			else valid_combination=false;
		}while(valid_combination==false&&entity_field_value!=is_a_field_value);
		if(valid_combination==false){
			Entity tree traversal considering left_node->expression general and object_node->expression specific
			entity=object_node.expression;
			do{
				sqlite=is_valid_expression_of_type(entity,"ENTITIES");
				if(sqlite==NULL) break;
				entity_field_value=sqlite->get_field_value(0,"entity");
				is_a_field_value=sqlite->get_field_value(0,"is_a");
				entity=is_a_field_value;
				if(left_node.expression==entity) valid_combination=true;
				else valid_combination=false;
			}while(valid_combination==false&&entity_field_value!=is_a_field_value);
		}
		if(valid_combination==true){
			options_field_value=sqlite->get_field_value(0,"options");
			options=options_field_value;
			set_options(options);
		}
	}
*/
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
