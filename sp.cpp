#include "sp.h"
#include <iterator>
#include <algorithm>
#include <functional>

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
	query_result *functors=NULL, *rule_to_rule_map=NULL,*main_symbol_entry=NULL,*main_symbol_root_entry=NULL,*dependent_symbol_entry=NULL,*dependent_symbol_root_entry=NULL;
	unsigned int rule_step_failed=0;
	const std::pair<const unsigned int,field> *rule_entry=NULL;
	std::vector<unsigned int> head_leafs, non_head_leafs;
	std::string head_leaf_words, non_head_leaf_words;

	nodeinfo.node_id=0;
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
		/*TODO:valamit kezdeni kell azzal ha a left_node->symbol='QPro' ill. ha az object_node-nak van gyereke*/
		nodeinfo.node_id=++nr_of_nodes;
		/*printf("combined node id:%d\n",(*this->private.node_info[this->private.nr_of_nodes-1]).node_id);*/
		nodeinfo.symbol=symbol;
		/*printf("symbol:%s\n",(*this->private.node_info[this->private.nr_of_nodes-1]).symbol);*/
		sqlite=db::get_instance();
//		std::cout<<"Looking for symbols for parent:"<<symbol<<", head root:"<<new_phrase_head_root.symbol<<", non-head root:"<<new_phrase_non_head_root.symbol<<std::endl;
		rule_to_rule_map=sqlite->exec_sql("SELECT * FROM RULE_TO_RULE_MAP WHERE PARENT_SYMBOL = '"+symbol+"' AND HEAD_ROOT_SYMBOL = '"+new_phrase_head_root.symbol+"' AND NON_HEAD_ROOT_SYMBOL = '"+new_phrase_non_head_root.symbol+"';");
		//TODO:Check how to find out CON iotype so that CONs can be part of a combination
		if(rule_to_rule_map!=NULL){
		/* TODO: Instead of the current validation, the head node needs to be validated against
		 * all child nodes of the right_node having a non-empty expression. This would ensure that
		 * all constituents are checked against each other and not only the new head of the phrase and
		 * the object of the phrase. E.g. 'list big small files!' is contradictory but now only
		 * big<->files, small<->files and list<->files are validated and not small<->files, big<->small,
		 * big<->files, list<->files.*/
			rule_step_failed=is_valid_combination(symbol,new_phrase_head_root,new_phrase_non_head_root);
			if(rule_step_failed!=0){
				//TODO:depending of head first or head last left-to-right (lr) or right-to-left (rl) method needs to be called to collect leafs
				get_leafs_of_node_lr(new_phrase_head_root,head_leafs);
				get_leafs_of_node_lr(new_phrase_non_head_root,non_head_leafs);
				for(auto&& i:head_leafs){
					//TODO: check why certain leaves don't have morphalytics
					//Most probably it happens only with dummies but to be on the safe side, CHECK IT!
					if(get_node_info(i).expression.morphalytics!=NULL&&get_node_info(i).expression.word.empty()==false)
						head_leaf_words+=get_node_info(i).expression.morphalytics->word()+" ";
				}
				if(head_leaf_words.empty()==false) head_leaf_words.pop_back();
				for(auto&& i:non_head_leafs){
					//TODO: check why certain leaves don't have morphalytics
					//Most probably it happens only with dummies but to be on the safe side, CHECK IT!
					if(get_node_info(i).expression.morphalytics!=NULL&&get_node_info(i).expression.word.empty()==false)
						non_head_leaf_words+=get_node_info(i).expression.morphalytics->word()+" ";
				}
				if(non_head_leaf_words.empty()==false) non_head_leaf_words.pop_back();
				throw invalid_combination(head_leaf_words,non_head_leaf_words);
			}
		/*printf("valid combination:%s %s\n",head_node->expression,((node_info *)object_node)->expression);*/
		}
		nodeinfo.left_child=left_node.node_id;
		nodeinfo.right_child=right_node.node_id;
		node_infos.push_back(nodeinfo);
		/*printf("combined node id:%d\n",node_infos[nr_of_nodes-1].node_id);
		printf("symbol:%s\n",node_infos[nr_of_nodes-1].symbol.c_str());
		printf("expression:%s\n",node_infos[nr_of_nodes-1].expression.c_str());
		printf("left_child:%d\n",node_infos[nr_of_nodes-1].left_child);
		printf("right_child:%d\n",node_infos[nr_of_nodes-1].right_child);*/
		validated_nodes.push_back(nodeinfo.node_id);
	}
	return nodeinfo.node_id;
}

std::multimap<std::pair<std::string,std::string>,std::pair<unsigned int,std::string> >* interpreter::is_valid_expression(node_info& main_node, node_info& dependent_node){
	std::multimap<std::pair<std::string,std::string>,std::pair<unsigned int,std::string> > *functors=NULL;

	if(main_node.expression.lexeme.empty()==false){//testing for leaves being leaves indeed
		if(dependent_node.node_id!=0){
			functors=functors_found_for_dependencies(dependent_node,main_node);
			if(functors!=NULL){
				if(functors->count(functors->begin()->first)==functors->size()){//check if one or more than one functor was found
					if(functors->begin()->first.first==main_node.expression.lexeme){
						//TODO: fill only functor attributes after finding the longest matching semantic rule when finishing interpretation
//						if(main_node.functor_attributes.functor.empty()==true){
//							main_node.functor_attributes.functor=functors->begin()->first.first;
//							main_node.functor_attributes.d_key=std::atoi(functors->begin()->first.second.c_str());
//							main_node.functor_attributes.functor_id=std::atoi(functors->field_value_at_row_position(rowid,"functor_id")->c_str());
//						}
//						else if(main_node.functor_attributes.functor!=functors->begin()->first.first
//								&&main_node.functor_attributes.d_key!=std::atoi(functors->begin()->first.second.c_str())){
//							exit(EXIT_FAILURE);//TODO:Throw exception
//						}
					}
					else exit(EXIT_FAILURE);//TODO:Throw exception
				}
				else if(functors->count(functors->begin()->first)<functors->size()){//More than one functor is acceptable as an intermediate result
				}
				else{
					exit(EXIT_FAILURE);//TODO:Throw exception
				}
			}
		}
	}
	return functors;
}

std::multimap<std::pair<std::string,std::string>,std::pair<unsigned int,std::string> >* interpreter::functors_found_for_dependencies(const node_info& dependent_node, node_info& main_node){
	std::multimap<std::pair<std::string,std::string>,std::pair<unsigned int,std::string> > *functors_found=NULL;
	std::string d_key_list,functor;
	query_result *functors=NULL;
	std::vector<std::pair<unsigned int,std::string> > dependency_stack;
	db *sqlite=NULL;
	field field;

	functor=main_node.expression.lexeme;
//	std::cout<<"functor to be found for dependency "<<dependent_node.expression.lexeme<<":"<<functor<<std::endl;
	functors_found=new std::multimap<std::pair<std::string,std::string>,std::pair<unsigned int,std::string> >();
	if(dependent_node.expression.gcat=="CON"){
		find_functors_for_dependency("CON",*main_node.expression.dependencies,*functors_found,dependency_stack);
	}
	else{
		find_functors_for_dependency(dependent_node.expression.lexeme,*main_node.expression.dependencies,*functors_found,dependency_stack);
	}
	if(functors_found->empty()==true){
		return NULL;
	}
	//generate d_key_list string which lists the d_keys of functors_found like: ('1', '2', ..., '3')
	d_key_list="(";
	for(std::multimap<std::pair<std::string,std::string>,std::pair<unsigned int,std::string> >::const_iterator j=functors_found->begin();
			j!=functors_found->end();++j){
		if(j->first.first==functor&&d_key_list.find("'"+j->first.second+"'")==std::string::npos){
			d_key_list+="'"+j->first.second+"',";
		}
	}
	d_key_list.resize(d_key_list.length()-1);//remove last ','
	d_key_list+=")";
	sqlite=db::get_instance();
	functors=sqlite->exec_sql("SELECT * FROM FUNCTORS WHERE FUNCTOR = '"+functor+"' AND D_KEY IN "+d_key_list+";");
	if(functors==NULL) exit(EXIT_FAILURE);
	for(auto i=functors_found->begin();i!=functors_found->end();){
		if(i->first.first==functor){
//			std::cout<<"dependency "<<i->second.second<<" with node id "<<dependent_node.node_id;
//			std::cout<<" and depolex row id "<<i->second.first;
//			std::cout<<" for functor "<<i->first.first<<" with node id "<<main_node.node_id<<" found"<<std::endl;
			++i;
		}
		else{
			i=functors_found->erase(i);
		}
	}
	return functors_found;
}

bool interpreter::find_functors_for_dependency(const std::string& dependency, const query_result& dependencies,
		std::multimap<std::pair<std::string,std::string>,std::pair<unsigned int,std::string> >& functors_found,
		std::vector<std::pair<unsigned int,std::string> >& dependency_stack){
	const std::pair<const unsigned int,field> *depolex_entry=NULL;
	std::string lexeme,d_key;
	std::vector<std::pair<unsigned int,std::string> >::const_iterator j;

	depolex_entry=dependencies.first_value_for_field_name_found("semantic_dependency",dependency);
	while(depolex_entry!=NULL){
//		std::cout<<"looking for functor with dependency "<<dependency<<std::endl;
		lexeme=*dependencies.field_value_at_row_position(depolex_entry->first,"lexeme");
		d_key=*dependencies.field_value_at_row_position(depolex_entry->first,"d_key");
		for(j=dependency_stack.begin();j!=dependency_stack.end();++j){
			if(j->first==depolex_entry->first&&j->second==depolex_entry->second.field_value) break;
		}
		if(j==dependency_stack.end()){
			dependency_stack.push_back(std::make_pair(depolex_entry->first,depolex_entry->second.field_value));
			if(find_functors_for_dependency(lexeme,dependencies,functors_found,dependency_stack)==true){
//				std::cout<<"inserting in functors_found an entry with row id "<<dependency_stack.begin()->first<<", functor="<<lexeme<<" d_key="<<d_key<<std::endl;
				functors_found.insert(std::make_pair(std::make_pair(lexeme,d_key),*dependency_stack.begin()));
			}
			dependency_stack.pop_back();
		}
		depolex_entry=dependencies.value_for_field_name_found_after_row_position(depolex_entry->first,"semantic_dependency",dependency);
	}
	return true;
}

void interpreter::get_nodes_by_symbol(const node_info& root_node, const std::string symbol, const std::string lexeme, std::vector<unsigned int>& nodes_found){
	//root_node: root node of the subtree in which the node should be found by the symbol
	//symbol: symbol of the node by which the node should be found
	//nodes_found: node ids of the nodes found
	//std::cout<<"symbol: "<<symbol<<std::endl;
	if(symbol.empty()==false){
		if(root_node.symbol==symbol&&lexeme.empty()==true
			||root_node.symbol!=symbol&&lexeme.empty()==true&&root_node.expression.morphalytics!=NULL&&root_node.expression.morphalytics->has_feature(symbol)==true
			||root_node.symbol==symbol&&lexeme.empty()==false&&root_node.expression.lexeme==lexeme){
			//std::cout<<"node_found_by_symbol '"<<symbol<<"':"<<root_node.node_id<<std::endl;
			nodes_found.push_back(root_node.node_id);
		}
		if(root_node.left_child!=0)get_nodes_by_symbol(get_node_info(root_node.left_child),symbol,lexeme,nodes_found);
		if(root_node.right_child!=0)get_nodes_by_symbol(get_node_info(root_node.right_child),symbol,lexeme,nodes_found);
	}
	else exit(EXIT_FAILURE);//TODO: throw exception, symbol cannot be empty
}

void interpreter::find_dependencies_for_node(const unsigned int node_id, t_map_of_node_ids_and_d_keys_to_nr_of_deps& dependencies_found,
		std::map<std::pair<std::string,unsigned int>,std::tuple<std::string,unsigned int,unsigned int> >& optional_dependencies_checked){
	std::pair<unsigned int,unsigned int> dependency_for_d_key_found;
	std::string d_key="0";
	unsigned int d_counter=0;
	const std::pair<const unsigned int,field> *depolex_entry=NULL;
	std::vector<p_m1_node_id_m2_d_key> node_d_key_route;
	p_m1_node_id_m2_d_key parent_node;

	const node_info& node=get_node_info(node_id);
	depolex_entry=node.expression.dependencies->first_value_for_field_name_found("lexeme",node.expression.lexeme);
	while(depolex_entry!=NULL&&node.expression.lexeme==*node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"lexeme")
			&&d_key!=*node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"d_key")){
		d_key=*node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"d_key");
		d_counter=std::atoi(node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"d_counter")->c_str());
//		std::cout<<"checking top level entry for functor "<<node.expression.lexeme<<" d_key "<<d_key<<std::endl;
		if(node_dependency_traversal_stack.empty()==false){
			parent_node=node_dependency_traversal_stack.top();
			auto traversal_node=node_dependency_traversal_stack_tree.find(std::make_pair(node_dependency_traversal_stack.size(),parent_node));
			if(traversal_node!=node_dependency_traversal_stack_tree.end()){
				traversal_node->second.push_back(std::make_pair(node_id,std::atoi(d_key.c_str())));
//				std::cout<<"push_back to vector of node_id "<<parent_node.first<<" with d_key "<<parent_node.second<<" the node_id "<<node_id<<" with d_key "<<d_key<<std::endl;
			}
			if(dependencies_found.empty()==false){
				auto traversal_node_dependencies=node_dependency_traversals.find(parent_node);
				if(traversal_node_dependencies==node_dependency_traversals.end()){
					node_dependency_traversals.insert(std::make_pair(parent_node,dependencies_found));
				}
				else{
					traversal_node_dependencies->second.clear();
					traversal_node_dependencies->second.insert(dependencies_found.begin(),dependencies_found.end());
				}
			}
			if(optional_dependencies_checked.empty()==false){
				auto traversal_node_odependencies=node_odependency_traversals.find(parent_node);
				if(traversal_node_odependencies==node_odependency_traversals.end()){
					node_odependency_traversals.insert(std::make_pair(parent_node,optional_dependencies_checked));
				}
				else{
					traversal_node_odependencies->second.clear();
					traversal_node_odependencies->second.insert(optional_dependencies_checked.begin(),optional_dependencies_checked.end());
				}
			}
		}
		dependencies_found.clear();
		optional_dependencies_checked.clear();
		node_dependency_traversal_stack.push(std::make_pair(node_id,std::atoi(d_key.c_str())));
//		std::cout<<"pushed to stack node_id "<<node_id<<" with d_key "<<d_key<<std::endl;
		auto traversal_node=node_dependency_traversal_stack_tree.find(std::make_pair(node_dependency_traversal_stack.size(),std::make_pair(node_id,std::atoi(d_key.c_str()))));
		if(traversal_node==node_dependency_traversal_stack_tree.end()){
			node_d_key_route.clear();
			node_dependency_traversal_stack_tree.insert(std::make_pair(std::make_pair(node_dependency_traversal_stack.size(),std::make_pair(node_id,std::atoi(d_key.c_str()))),node_d_key_route));
//			std::cout<<"inserting in traversal tree at level "<<node_dependency_traversal_stack.size()<<": node_id "<<node_id<<" with d_key "<<d_key<<" the node_d_key_route"<<std::endl;
		}
		else{
			//TODO: figure out what should happen in this case: a previously processed node with its functor/d_key gets processed again...
			exit(EXIT_FAILURE);
		}
		find_dependencies_for_functor(std::to_string(node.node_id),d_key,d_counter,node.node_id,d_key,dependencies_found,optional_dependencies_checked);
		parent_node=node_dependency_traversal_stack.top();
		if(dependencies_found.empty()==false){
			auto traversal_node_dependencies=node_dependency_traversals.find(parent_node);
			if(traversal_node_dependencies==node_dependency_traversals.end()){
				node_dependency_traversals.insert(std::make_pair(parent_node,dependencies_found));
			}
			else{
				traversal_node_dependencies->second.clear();
				traversal_node_dependencies->second.insert(dependencies_found.begin(),dependencies_found.end());
			}
		}
		dependencies_found.clear();
		if(optional_dependencies_checked.empty()==false){
			auto traversal_node_odependencies=node_odependency_traversals.find(parent_node);
			if(traversal_node_odependencies==node_odependency_traversals.end()){
				node_odependency_traversals.insert(std::make_pair(parent_node,optional_dependencies_checked));
			}
			else{
				traversal_node_odependencies->second.clear();
				traversal_node_odependencies->second.insert(optional_dependencies_checked.begin(),optional_dependencies_checked.end());
			}
		}
		optional_dependencies_checked.clear();
		node_dependency_traversal_stack.pop();
//		std::cout<<"popped stack"<<std::endl;
		if(node_dependency_traversal_stack.empty()==false){//restore dependencies_found and optional_dependencies_checked using node_dependency_traversal_stack.top()
			parent_node=node_dependency_traversal_stack.top();
			auto traversal_node_dependencies=node_dependency_traversals.find(parent_node);
			auto traversal_node_odependencies=node_odependency_traversals.find(parent_node);
			dependencies_found.clear();
			if(traversal_node_dependencies!=node_dependency_traversals.end()){
				dependencies_found.insert(traversal_node_dependencies->second.begin(),traversal_node_dependencies->second.end());
			}
			optional_dependencies_checked.clear();
			if(traversal_node_odependencies!=node_odependency_traversals.end()){
				optional_dependencies_checked.insert(traversal_node_odependencies->second.begin(),traversal_node_odependencies->second.end());
			}
		}
		while(depolex_entry!=NULL&&*node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"d_key")==d_key){
			depolex_entry=node.expression.dependencies->value_for_field_name_found_after_row_position(depolex_entry->first,"lexeme",node.expression.lexeme);
		}
	}
}

const std::pair<const unsigned int,field>* interpreter::followup_dependency(const unsigned int previous_dependency_row_index,const std::string& lexeme,const std::string& d_key,const bool previous_dependency_found,const query_result& dependencies){
	std::string next_counter;
	const std::pair<const unsigned int,field> *depolex_entry=NULL;

	if(previous_dependency_found==true){
		next_counter=*dependencies.field_value_at_row_position(previous_dependency_row_index,"d_successor");
	}
	else{
		next_counter=*dependencies.field_value_at_row_position(previous_dependency_row_index,"d_failover");
	}
//	std::cout<<"next counter: "<<next_counter<<std::endl;
	if(std::atoi(next_counter.c_str())>0&&std::atoi(next_counter.c_str())>std::atoi(dependencies.field_value_at_row_position(previous_dependency_row_index,"d_counter")->c_str())){
		depolex_entry=dependencies.value_for_field_name_found_after_row_position(previous_dependency_row_index,"lexeme",lexeme);
		while(depolex_entry!=NULL&&*dependencies.field_value_at_row_position(depolex_entry->first,"d_key")==d_key
				&&*dependencies.field_value_at_row_position(depolex_entry->first,"d_counter")!=next_counter){
			depolex_entry=dependencies.value_for_field_name_found_after_row_position(depolex_entry->first,"lexeme",lexeme);
		}
	}
	return depolex_entry;
}

void interpreter::find_dependencies_for_functor(const std::string& parent_node_id, const std::string& parent_d_key, const unsigned int parent_d_counter,
		const unsigned int node_id, const std::string& d_key,
		t_map_of_node_ids_and_d_keys_to_nr_of_deps& dependencies_found,
		std::map<std::pair<std::string,unsigned int>,std::tuple<std::string,unsigned int,unsigned int> >& optional_dependencies_checked){
	const std::pair<const unsigned int,field> *depolex_entry=NULL;
	std::string semantic_dependency,ref_d_key,d_counter="0",manner,d_failover,d_successor;
	std::multimap<unsigned int,unsigned int>::const_iterator dependency_matrix_entry;
	std::map<unsigned int,unsigned int>::const_iterator j;
	t_map_of_node_ids_and_d_keys_to_nr_of_deps::iterator dependencies_found_entry;
	std::set<unsigned int> d_counter_validated_dependencies,d_key_validated_dependencies;
	bool dependency_found_for_functor=false,node_being_processed=false;
	std::stack<p_m1_node_id_m2_d_key> traversal_stack;

	const node_info& node=get_node_info(node_id);
//	std::cout<<"checking dependency for functor "<<node.expression.lexeme<<" d_key "<<d_key<<std::endl;
	if(node.expression.gcat=="CON"){
		depolex_entry=node.expression.dependencies->first_value_for_field_name_found("lexeme","CON");
	}
	else{
		depolex_entry=node.expression.dependencies->first_value_for_field_name_found("lexeme",node.expression.lexeme);
	}
	if(depolex_entry==NULL){
		std::cout<<"exiting, no dependency entry found for functor "<<node.expression.lexeme<<std::endl;
		//TODO: throw exception as for each functor there must be one entry with at least NULL dependency
		exit(EXIT_FAILURE);
	}
	while(depolex_entry!=NULL&&*node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"d_key")!=d_key){
		depolex_entry=node.expression.dependencies->value_for_field_name_found_after_row_position(depolex_entry->first,"lexeme",node.expression.lexeme);
	}
	while(depolex_entry!=NULL&&*node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"d_key")==d_key){
		d_counter=*node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"d_counter");
		semantic_dependency=*node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"semantic_dependency");
		ref_d_key=*node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"ref_d_key");
		manner=*node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"manner");
		d_failover=*node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"d_failover");
		d_successor=*node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"d_successor");
//		std::cout<<"checking dependency entry "<<semantic_dependency<<" ref_d_key "<<ref_d_key<<" for functor "<<node.expression.lexeme<<" d_key "<<d_key<<" d_counter "<<d_counter<<std::endl;
		if(semantic_dependency.empty()==false&&ref_d_key.empty()==false&&(manner.empty()==true||manner=="0"||manner=="1"||manner=="2")){
//			std::cout<<"looking up depolex entry with row id "<<depolex_entry->first<<" in dep.val.matrix"<<std::endl;
			d_counter_validated_dependencies.clear();
			//Insert the corresponding entry into dependencies_found to indicate that the node id is already being checked
			dependencies_found.insert(std::make_pair(std::make_pair(node_id,std::atoi(d_key.c_str())),std::make_tuple(parent_node_id,0,0,std::atoi(parent_d_key.c_str()),parent_d_counter)));
			for(dependency_matrix_entry=node.dependency_validation_matrix.lower_bound(depolex_entry->first);
					dependency_matrix_entry!=node.dependency_validation_matrix.upper_bound(depolex_entry->first);
					++dependency_matrix_entry){
				//If the row_id of the depolex_entry is found among the row_ids stored in the dep.vld.matrix
				//then the field values match as well since both row_ids refer to the corresponding
				//field in the node.expression.dependencies attribute.
				if(d_key_validated_dependencies.find(dependency_matrix_entry->second)==d_key_validated_dependencies.end()){
					d_counter_validated_dependencies.insert(dependency_matrix_entry->second);
					d_key_validated_dependencies.insert(dependency_matrix_entry->second);
					find_dependencies_for_functor(std::to_string(node_id),d_key,std::atoi(d_counter.c_str()),get_node_info(dependency_matrix_entry->second).node_id,ref_d_key,dependencies_found,optional_dependencies_checked);
				}
			}
			if((manner.empty()==true||manner=="0")&&d_counter_validated_dependencies.size()==1
					||manner=="1"&&d_counter_validated_dependencies.size()>=1
					||manner=="2"&&d_counter_validated_dependencies.size()>1){
//				std::cout<<"dependency "<<semantic_dependency<<" checked for functor "<<node.expression.lexeme<<std::endl;
				dependency_found_for_functor=true;
			}
			else if((manner.empty()==true||manner=="0")&&d_counter_validated_dependencies.size()!=1
					||manner=="1"&&d_counter_validated_dependencies.size()<1
					||manner=="2"&&d_counter_validated_dependencies.size()<=1){
//				std::cout<<"dependency check for "<<semantic_dependency<<" returned FALSE for functor "<<node.expression.lexeme<<" with d_key "<<d_key<<std::endl;
				if(std::atoi(d_failover.c_str())>=std::atoi(d_counter.c_str())){
					find_dependencies_for_functor(std::to_string(node_id),d_key,std::atoi(d_counter.c_str()),node_id,d_key,semantic_dependency,ref_d_key,dependencies_found,optional_dependencies_checked);
				}
				dependency_found_for_functor=false;
			}
			else{
				//TODO: throw exception
				exit(EXIT_FAILURE);
			}
			dependencies_found_entry=dependencies_found.find(std::make_pair(node_id,std::atoi(d_key.c_str())));
			if(dependency_found_for_functor==true){
				if(dependencies_found_entry!=dependencies_found.end()){
					std::get<2>(dependencies_found_entry->second)+=d_counter_validated_dependencies.size();
					if(std::atoi(d_successor.c_str())==0||std::atoi(d_successor.c_str())>std::atoi(d_counter.c_str())){
						std::get<1>(dependencies_found_entry->second)+=d_counter_validated_dependencies.size();
					}
					else{
						//Don't increase counter for found dependencies: this indicates a deliberate error on the success branch
					}
				}
				else{
					dependencies_found.insert(std::make_pair(std::make_pair(node_id,std::atoi(d_key.c_str())),std::make_tuple(parent_node_id,d_counter_validated_dependencies.size(),d_counter_validated_dependencies.size(),std::atoi(parent_d_key.c_str()),parent_d_counter)));
				}
			}
			else{
				if(d_failover.empty()==true||d_failover=="0"||std::atoi(d_failover.c_str())<std::atoi(d_counter.c_str())){
					if(manner.empty()==true||manner=="0"||manner=="1"){
						std::get<2>(dependencies_found_entry->second)+=1;
//						dependencies_found_entry->second.second+=1;
					}
					else if(manner=="2"){
						std::get<2>(dependencies_found_entry->second)+=2;
//						dependencies_found_entry->second.second+=2;
					}
				}
				if(dependencies_found_entry!=dependencies_found.end()){
					//No manner condition was fulfilled, nothing to add
				}
				else{
					dependencies_found.insert(std::make_pair(std::make_pair(node_id,std::atoi(d_key.c_str())),std::make_tuple(parent_node_id,0,0,std::atoi(parent_d_key.c_str()),parent_d_counter)));
				}
			}
		}
		else if(semantic_dependency.empty()==true&&ref_d_key.empty()==true){
			//A leaf in the dependency tree is found so the semantic dependency is empty. As such, there's no
			//functor-dependency pair to be checked in the dep.vld.matrix so let's go on with the next dependency.
//			std::cout<<"leaf dependency "<<semantic_dependency<<" checked for functor "<<node.expression.lexeme<<" and has no further dependency"<<std::endl;
			dependencies_found_entry=dependencies_found.find(std::make_pair(node_id,std::atoi(d_key.c_str())));
			if(dependencies_found_entry!=dependencies_found.end()){
				//Don't increase the number of dependencies (++dependencies_found_entry->second;), NULL dependency is considered as found but not counted
				//dependency_found_for_functor=true;//TODO: consider if setting this flag is ok here or should it be set to true anyway for leaves?
			}
			else{
				dependencies_found.insert(std::make_pair(std::make_pair(node_id,std::atoi(d_key.c_str())),std::make_tuple(parent_node_id,0,0,std::atoi(parent_d_key.c_str()),parent_d_counter)));
				//dependency_found_for_functor=false;//TODO: consider if setting this flag is ok here or should it be set to true anyway for leaves?
			}
			dependency_found_for_functor=true;
		}
		else{
			//TODO: throw exception
			exit(EXIT_FAILURE);
		}
		if(node.expression.gcat=="CON"){
			depolex_entry=followup_dependency(depolex_entry->first,"CON",d_key,dependency_found_for_functor,*node.expression.dependencies);
		}
		else{
			depolex_entry=followup_dependency(depolex_entry->first,node.expression.lexeme,d_key,dependency_found_for_functor,*node.expression.dependencies);
		}
//		if(depolex_entry!=NULL) std::cout<<"followup d_counter: "<<*node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"d_counter")<<std::endl;
	}
	for(j=node.node_links.begin();j!=node.node_links.end();++j){
		node_being_processed=false;
		for(dependencies_found_entry=dependencies_found.begin();dependencies_found_entry!=dependencies_found.end();++dependencies_found_entry){
			if(dependencies_found_entry->first.first==j->first){
				node_being_processed=true;
				break;
			}
		}
		if(node_being_processed==false){
			traversal_stack=node_dependency_traversal_stack;
			while(traversal_stack.empty()==false){
				auto stack_top_node=traversal_stack.top();
				auto stack_top_node_dependencies=node_dependency_traversals.find(stack_top_node);
				if(stack_top_node_dependencies!=node_dependency_traversals.end()){
					for(auto dependency_entry=stack_top_node_dependencies->second.begin();dependency_entry!=stack_top_node_dependencies->second.end();++dependency_entry){
						if(dependency_entry->first.first==j->first){
							node_being_processed=true;
							break;
						}
					}
					if(node_being_processed==true) break;
				}
				traversal_stack.pop();
			}
		}
		if(node_being_processed==false){
			find_dependencies_for_node(j->first,dependencies_found,optional_dependencies_checked);
		}
	}
}

void interpreter::find_dependencies_for_functor(const std::string& parent_node_id, const std::string& parent_d_key,const unsigned int parent_d_counter,
		const unsigned int node_id, const std::string& node_d_key, const std::string& functor, const std::string& d_key,
		t_map_of_node_ids_and_d_keys_to_nr_of_deps& dependencies_found,
		std::map<std::pair<std::string,unsigned int>,std::tuple<std::string,unsigned int,unsigned int> >& optional_dependencies_checked){
	const std::pair<const unsigned int,field> *depolex_entry=NULL;
	std::string semantic_dependency,ref_d_key,d_counter="0",manner,d_failover,d_successor;
	std::multimap<unsigned int,unsigned int>::const_iterator dependency_matrix_entry;
	std::map<unsigned int,unsigned int>::const_iterator j;
	t_map_of_node_ids_and_d_keys_to_nr_of_deps::iterator dependencies_found_entry;
	std::set<unsigned int> d_counter_validated_dependencies,d_key_validated_dependencies,checked_d_counters;
	bool dependency_found_for_functor=false;
	unsigned int nr_of_skipped_opa_rules=0,nr_of_rules=0;

	const node_info& node=get_node_info(node_id);
//	std::cout<<"checking dependency for optional functor "<<functor<<" d_key "<<d_key<<std::endl;
	depolex_entry=node.expression.dependencies->first_value_for_field_name_found("lexeme",functor);
	if(depolex_entry==NULL){
		std::cout<<"exiting, no dependency entry found for functor "<<functor<<std::endl;
		//TODO: throw exception as for each functor there must be one entry with at least NULL dependency
		exit(EXIT_FAILURE);
	}
	while(depolex_entry!=NULL&&*node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"d_key")!=d_key){
		depolex_entry=node.expression.dependencies->value_for_field_name_found_after_row_position(depolex_entry->first,"lexeme",functor);
	}
	while(depolex_entry!=NULL&&*node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"d_key")==d_key){
		++nr_of_rules;
		if(std::atoi(node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"optional_parent_allowed")->c_str())==true){
			d_counter=*node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"d_counter");
			semantic_dependency=*node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"semantic_dependency");
			ref_d_key=*node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"ref_d_key");
			manner=*node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"manner");
			d_failover=*node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"d_failover");
			d_successor=*node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"d_successor");
//			std::cout<<"checking dependency entry "<<semantic_dependency<<" ref_d_key "<<ref_d_key<<" for functor "<<functor<<" d_key "<<d_key<<" d_counter "<<d_counter<<std::endl;
			if(semantic_dependency.empty()==false&&ref_d_key.empty()==false&&(manner.empty()==true||manner=="0"||manner=="1"||manner=="2")){
//				std::cout<<"looking up depolex entry with row id "<<depolex_entry->first<<" in dep.val.matrix"<<std::endl;
				d_counter_validated_dependencies.clear();
				//Insert the corresponding entry into dependencies_found to indicate that the node id is already being checked
				optional_dependencies_checked.insert(std::make_pair(std::make_pair(functor,std::atoi(d_key.c_str())),std::make_tuple(parent_node_id,std::atoi(parent_d_key.c_str()),parent_d_counter)));
				for(dependency_matrix_entry=node.dependency_validation_matrix.lower_bound(depolex_entry->first);
						dependency_matrix_entry!=node.dependency_validation_matrix.upper_bound(depolex_entry->first);
						++dependency_matrix_entry){
					//If the row_id of the depolex_entry is found among the row_ids stored in the dep.vld.matrix
					//then the field values match as well since both row_ids refer to the corresponding
					//field in the node.expression.dependencies attribute.
					if(d_key_validated_dependencies.find(dependency_matrix_entry->second)==d_key_validated_dependencies.end()){
						d_counter_validated_dependencies.insert(dependency_matrix_entry->second);
						d_key_validated_dependencies.insert(dependency_matrix_entry->second);
						find_dependencies_for_functor(functor,d_key,std::atoi(d_counter.c_str()),get_node_info(dependency_matrix_entry->second).node_id,ref_d_key,dependencies_found,optional_dependencies_checked);
					}
				}
				if((manner.empty()==true||manner=="0")&&d_counter_validated_dependencies.size()==1
						||manner=="1"&&d_counter_validated_dependencies.size()>=1
						||manner=="2"&&d_counter_validated_dependencies.size()>1){
//					std::cout<<"dependency "<<semantic_dependency<<" checked for functor "<<functor<<std::endl;
					dependency_found_for_functor=true;
				}
				else if((manner.empty()==true||manner=="0")&&d_counter_validated_dependencies.size()!=1
						||manner=="1"&&d_counter_validated_dependencies.size()<1
						||manner=="2"&&d_counter_validated_dependencies.size()<=1){
//					std::cout<<"dependency check for "<<semantic_dependency<<" returned FALSE for functor "<<functor<<" with d_key "<<d_key<<std::endl;
					if((std::atoi(d_failover.c_str())>=std::atoi(d_counter.c_str()))
						&&optional_dependencies_checked.find(std::make_pair(semantic_dependency,std::atoi(ref_d_key.c_str())))==optional_dependencies_checked.end()){
						find_dependencies_for_functor(functor,d_key,std::atoi(d_counter.c_str()),node_id,node_d_key,semantic_dependency,ref_d_key,dependencies_found,optional_dependencies_checked);
					}
					dependency_found_for_functor=false;
				}
				else{
					//TODO: throw exception
					exit(EXIT_FAILURE);
				}
				dependencies_found_entry=dependencies_found.find(std::make_pair(node_id,std::atoi(node_d_key.c_str())));
				if(dependency_found_for_functor==true){
					if(dependencies_found_entry!=dependencies_found.end()){
						std::get<2>(dependencies_found_entry->second)+=d_counter_validated_dependencies.size();
						if(std::atoi(d_successor.c_str())==0||std::atoi(d_successor.c_str())>std::atoi(d_counter.c_str())){
							std::get<1>(dependencies_found_entry->second)+=d_counter_validated_dependencies.size();
						}
						else{
							//Don't increase counter for found dependencies: this indicates a deliberate error on the success branch
						}
					}
					else{
						dependencies_found.insert(std::make_pair(std::make_pair(node_id,std::atoi(node_d_key.c_str())),std::make_tuple(parent_node_id,d_counter_validated_dependencies.size(),d_counter_validated_dependencies.size(),std::atoi(parent_d_key.c_str()),parent_d_counter)));
					}
				}
				else{//Don't increase dependencies_found_entry.second.second i.e. the counter for expected dependecies to be found as nothing is expected to be found for an optional dependency
					if(dependencies_found_entry!=dependencies_found.end()){
						//No manner condition was fulfilled, nothing to add
					}
					else{
						dependencies_found.insert(std::make_pair(std::make_pair(node_id,std::atoi(node_d_key.c_str())),std::make_tuple(std::string(),0,0,0,0)));
					}
				}
			}
			else if(semantic_dependency.empty()==true&&ref_d_key.empty()==true){
				//A leaf in the dependency tree is found so the semantic dependency is empty. As such, there's no
				//functor-dependency pair to be checked in the dep.vld.matrix so let's go on with the next dependency.
//				std::cout<<"leaf dependency "<<semantic_dependency<<" checked for functor "<<functor<<" and has no further dependency"<<std::endl;
				dependencies_found_entry=dependencies_found.find(std::make_pair(node_id,std::atoi(node_d_key.c_str())));
				if(dependencies_found_entry!=dependencies_found.end()){
					//Don't increase the number of dependencies (++dependencies_found_entry->second;), NULL dependency is considered as found but not counted
					//dependency_found_for_functor=true;//TODO: consider if setting this flag is ok here or should it be set to true anyway for leaves?
				}
				else{
					dependencies_found.insert(std::make_pair(std::make_pair(node_id,std::atoi(node_d_key.c_str())),std::make_tuple(std::string(),0,0,0,0)));
					//dependency_found_for_functor=false;//TODO: consider if setting this flag is ok here or should it be set to true anyway for leaves?
				}
				dependency_found_for_functor=true;
			}
			else{
				//TODO: throw exception
				exit(EXIT_FAILURE);
			}
		}
		else{
			++nr_of_skipped_opa_rules;
		}
		depolex_entry=followup_dependency(depolex_entry->first,functor,d_key,dependency_found_for_functor,*node.expression.dependencies);
	}
	if(nr_of_rules>0&&nr_of_rules==nr_of_skipped_opa_rules){
//		std::cout<<"dependency "<<semantic_dependency<<" checked for functor "<<functor<<" but has no further dependency"<<std::endl;
		dependencies_found_entry=dependencies_found.find(std::make_pair(node_id,std::atoi(node_d_key.c_str())));
		if(dependencies_found_entry!=dependencies_found.end()){
			//Don't increase the number of dependencies as earlier:
			//++dependencies_found_entry->second.first;
			//++dependencies_found_entry->second.second;
			//as NULL dependency is considered as found but not counted
		}
		else{
			dependencies_found.insert(std::make_pair(std::make_pair(node_id,std::atoi(node_d_key.c_str())),std::make_tuple(std::string(),0,0,0,0)));
		}
	}
}

unsigned int interpreter::nr_of_dependencies_to_be_found(){
	unsigned int nr_of_non_ref_leafs=0;
	db *sqlite=NULL;
	query_result *gcats=NULL;

	sqlite=db::get_instance();
	gcats=sqlite->exec_sql("SELECT DISTINCT GCAT FROM GCAT;");
	if(gcats==NULL){
		//TODO: throw exception
		exit(EXIT_FAILURE);
	}
	for(auto&& i:node_infos){
		if(i.expression.lexeme.empty()==false&&i.ref_node_ids.empty()==true&&gcats->first_value_for_field_name_found("gcat",i.expression.gcat)!=NULL){
			++nr_of_non_ref_leafs;
//			std::cout<<"Dependency to be found:"<<i.expression.lexeme<<std::endl;
		}
	}
	return nr_of_non_ref_leafs;
}

transgraph* interpreter::longest_match_for_semantic_rules_found(){
	t_map_of_node_ids_and_d_keys_to_nr_of_deps dependencies_found;
	std::map<std::pair<std::string,unsigned int>,std::tuple<std::string,unsigned int,unsigned int> > optional_dependencies_checked;
	std::vector<unsigned int> vbar_found,verbs_found;
	std::map<unsigned int,std::pair<unsigned int,unsigned int> > map_of_node_ids_to_total_nr_of_deps_and_d_key;
	std::map<unsigned int,std::pair<unsigned int,unsigned int> >::iterator node_id_with_longest_match_and_d_key;
	std::set<unsigned int> nodes_to_be_validated;
	unsigned int nr_of_dependencies_found=0,total_nr_of_dependencies=0,d_key=0,min_nr_of_deps=0;
	t_node_dependency_traversal *node_dependency_traversal=NULL;
	t_pair_of_node_id_and_d_key_with_nr_of_deps *node_id_and_d_key_with_nr_of_deps=NULL;
	std::pair<p_m1_node_id_m2_d_key,t_m0_parent_node_m1_nr_of_deps_m2_nr_of_deps_to_find_m3_parent_dkey_m4_parent_dcounter> functor_found;
	std::map<p_m1_node_id_m2_d_key,std::pair<t_m0_parent_node_m1_nr_of_deps_m2_nr_of_deps_to_find_m3_parent_dkey_m4_parent_dcounter,std::map<unsigned int,std::pair<t_m0_parent_node_m1_nr_of_deps_m2_nr_of_deps_to_find_m3_parent_dkey_m4_parent_dcounter,unsigned int> > > > longest_traversals;

	const node_info& root_node=get_node_info(nr_of_nodes);
	//TODO: 1) create a db customizing table where the symbols for looking up predicates can be listed
	//or rather 2) make use of adding a linguistic feature like "main verb" to the verb in the yacc source
	//at an appropriate place in the syntactic rules
	if(lex->language()=="ENG")get_nodes_by_symbol(root_node,"ENG_VBAR1",std::string(),vbar_found);
	else if(lex->language()=="HUN")get_nodes_by_symbol(root_node,"HUN_ImpVerb",std::string(),vbar_found);
	if(vbar_found.size()!=1) exit(EXIT_FAILURE);//TODO: throw exception
	const node_info& vbar_node=get_node_info(*vbar_found.begin());
	if(lex->language()=="ENG")get_nodes_by_symbol(vbar_node,"V",std::string(),verbs_found);
	else if(lex->language()=="HUN")get_nodes_by_symbol(vbar_node,"Verb",std::string(),verbs_found);
	if(verbs_found.size()!=1) exit(EXIT_FAILURE);//TODO: throw exception
	const node_info& node=get_node_info(*verbs_found.begin());
	find_dependencies_for_node(node.node_id,dependencies_found,optional_dependencies_checked);
	functor_found=calculate_longest_matching_dependency_route(longest_traversals);
	d_key=functor_found.first.second;
	min_nr_of_deps=std::get<2>(functor_found.second);
	std::cout<<"Minimum number of dependencies to match:"<<min_nr_of_deps<<std::endl;
	nr_of_dependencies_found=std::get<1>(functor_found.second);
	total_nr_of_dependencies=nr_of_dependencies_to_be_found()-1;
	std::cout<<"Total number of dependencies:"<<total_nr_of_dependencies<<std::endl;
	if(nr_of_dependencies_found==total_nr_of_dependencies&&nr_of_dependencies_found>=min_nr_of_deps){
		std::cout<<"Matching nr of dependencies found for functor "<<node.expression.lexeme<<" with d_key "<<d_key<<":"<<nr_of_dependencies_found<<std::endl;
		return build_transgraph(functor_found.first,std::make_pair(std::to_string(functor_found.first.first),functor_found.first.second),longest_traversals);
	}
	else{
		std::cout<<"No matching nr of dependencies found for functor "<<node.expression.lexeme<<" with any d_key "<<std::endl;
		return NULL;
	}
}

std::pair<p_m1_node_id_m2_d_key,t_m0_parent_node_m1_nr_of_deps_m2_nr_of_deps_to_find_m3_parent_dkey_m4_parent_dcounter> interpreter::calculate_longest_matching_dependency_route(std::map<p_m1_node_id_m2_d_key,std::pair<t_m0_parent_node_m1_nr_of_deps_m2_nr_of_deps_to_find_m3_parent_dkey_m4_parent_dcounter,std::map<unsigned int,std::pair<t_m0_parent_node_m1_nr_of_deps_m2_nr_of_deps_to_find_m3_parent_dkey_m4_parent_dcounter,unsigned int> > > >& longest_traversals){
	unsigned int node_level=1;
	t_m0_parent_node_m1_nr_of_deps_m2_nr_of_deps_to_find_m3_parent_dkey_m4_parent_dcounter nr_of_deps;
	p_m1_node_id_m2_d_key functor_node;
	std::pair<p_m1_node_id_m2_d_key,t_m0_parent_node_m1_nr_of_deps_m2_nr_of_deps_to_find_m3_parent_dkey_m4_parent_dcounter> functor_found;
	std::map<unsigned int,std::pair<t_m0_parent_node_m1_nr_of_deps_m2_nr_of_deps_to_find_m3_parent_dkey_m4_parent_dcounter,unsigned int> > map_of_node_ids_to_total_nr_of_deps_and_d_key;

	for(auto&& i:node_dependency_traversal_stack_tree){
		if(i.first.first==node_level){
			std::get<1>(nr_of_deps)=0;
			std::get<2>(nr_of_deps)=0;
			functor_node=i.first.second;
			map_of_node_ids_to_total_nr_of_deps_and_d_key.clear();
			nr_of_deps=calculate_longest_matching_dependency_route(node_level,functor_node,map_of_node_ids_to_total_nr_of_deps_and_d_key);
			longest_traversals.insert(std::make_pair(functor_node,std::make_pair(nr_of_deps,map_of_node_ids_to_total_nr_of_deps_and_d_key)));
		}
	}
	std::get<1>(functor_found.second)=0;
	std::get<2>(functor_found.second)=0;
	for(auto&& i:longest_traversals){
//TODO: two interpretations with the same number of deps must not be allowed.
//The only exception is when the scripts behind the functors are the same.
//This logic is missing though here.
		if(std::get<1>(i.second.first)>std::get<1>(functor_found.second)){
			functor_found.first=i.first;
			functor_found.second=i.second.first;
		}
	}
	return functor_found;
}

t_m0_parent_node_m1_nr_of_deps_m2_nr_of_deps_to_find_m3_parent_dkey_m4_parent_dcounter interpreter::calculate_longest_matching_dependency_route(const unsigned int node_level, const p_m1_node_id_m2_d_key& functor_node,
		std::map<unsigned int,std::pair<t_m0_parent_node_m1_nr_of_deps_m2_nr_of_deps_to_find_m3_parent_dkey_m4_parent_dcounter,unsigned int> >& map_of_node_ids_to_total_nr_of_deps_and_d_key){
	p_m1_tree_level_m2_p_m1_node_id_m2_d_key tree_level_and_functor_node;
	std::map<p_m1_tree_level_m2_p_m1_node_id_m2_d_key,std::vector<p_m1_node_id_m2_d_key> >::const_iterator functor_node_found;
	std::map<unsigned int,std::pair<t_m0_parent_node_m1_nr_of_deps_m2_nr_of_deps_to_find_m3_parent_dkey_m4_parent_dcounter,unsigned int> >::iterator node_id_with_longest_match_and_d_key;
	std::set<unsigned int> nodes_to_be_validated;
	t_node_dependency_traversals::const_iterator functor_node_dependencies;
	t_node_dependency_traversal *node_dependency_traversal=NULL;
	t_pair_of_node_id_and_d_key_with_nr_of_deps *node_id_and_d_key_with_nr_of_deps=NULL;
	t_m0_parent_node_m1_nr_of_deps_m2_nr_of_deps_to_find_m3_parent_dkey_m4_parent_dcounter nr_of_deps_found,nr_of_deps_found_tmp;

	tree_level_and_functor_node.first=node_level;
	tree_level_and_functor_node.second=functor_node;
	functor_node_found=node_dependency_traversal_stack_tree.find(tree_level_and_functor_node);
	if(functor_node_found==node_dependency_traversal_stack_tree.end()) exit(EXIT_FAILURE);//TODO: throw exception
	functor_node_dependencies=node_dependency_traversals.find(functor_node);
	if(functor_node_dependencies==node_dependency_traversals.end()) exit(EXIT_FAILURE);//TODO: throw exception
	//1) loop over functor_node_dependencies.map_of_node_ids_and_d_keys_to_nr_of_deps to get the longest matching deps and sum them up
	node_dependency_traversal=new t_node_dependency_traversal(functor_node_dependencies);
	for(t_map_of_node_ids_and_d_keys_to_nr_of_deps::const_iterator i=node_dependency_traversal->map_of_node_ids_and_d_keys_to_nr_of_deps.begin();
			i!=node_dependency_traversal->map_of_node_ids_and_d_keys_to_nr_of_deps.end();++i){
		node_id_and_d_key_with_nr_of_deps=new t_pair_of_node_id_and_d_key_with_nr_of_deps(i);
		if(map_of_node_ids_to_total_nr_of_deps_and_d_key.find(node_id_and_d_key_with_nr_of_deps->node_id_and_d_key.first)==map_of_node_ids_to_total_nr_of_deps_and_d_key.end()
			&&nodes_to_be_validated.find(node_id_and_d_key_with_nr_of_deps->node_id_and_d_key.first)==nodes_to_be_validated.end()){
			nodes_to_be_validated.insert(node_id_and_d_key_with_nr_of_deps->node_id_and_d_key.first);
		}
//		std::cout<<"for node id "<<i->first.first<<" with functor "<<get_node_info(i->first.first).expression.lexeme<<" and d_key "<<i->first.second;
//		std::cout<<" the nr_of_dependencies_found is: "<<i->second<<std::endl;
		node_id_with_longest_match_and_d_key=map_of_node_ids_to_total_nr_of_deps_and_d_key.find(node_id_and_d_key_with_nr_of_deps->node_id_and_d_key.first);
		if(node_id_with_longest_match_and_d_key!=map_of_node_ids_to_total_nr_of_deps_and_d_key.end()){
			if(std::get<1>(node_id_with_longest_match_and_d_key->second.first)<std::get<1>(node_id_and_d_key_with_nr_of_deps->nr_of_deps)){
				node_id_with_longest_match_and_d_key->second.first=node_id_and_d_key_with_nr_of_deps->nr_of_deps;
				node_id_with_longest_match_and_d_key->second.second=node_id_and_d_key_with_nr_of_deps->node_id_and_d_key.second;
			}
			else if(std::get<1>(node_id_with_longest_match_and_d_key->second.first)>0&&std::get<1>(node_id_with_longest_match_and_d_key->second.first)==std::get<1>(node_id_and_d_key_with_nr_of_deps->nr_of_deps)){
				//TODO: consider: before changing the return type to a pair, this function used to return an unsigned int.
				//Only after the change I noticed that here a boolean false was returned so even before the uint return type there must have been a boolean return type
				//that got changed. So, try to figure out why false was returned here originally and what shall be returned now that a pair should be returned.
				//For the time being, I just return the equivalent of an uint converted false in the pair i.e. (0,0).
				return std::make_tuple(std::to_string(0),0,0,0,0);
			}
		}
		else{
			map_of_node_ids_to_total_nr_of_deps_and_d_key.insert(std::make_pair(node_id_and_d_key_with_nr_of_deps->node_id_and_d_key.first,std::make_pair(node_id_and_d_key_with_nr_of_deps->nr_of_deps,node_id_and_d_key_with_nr_of_deps->node_id_and_d_key.second)));
			nodes_to_be_validated.erase(node_id_and_d_key_with_nr_of_deps->node_id_and_d_key.first);
		}
		delete node_id_and_d_key_with_nr_of_deps;
		node_id_and_d_key_with_nr_of_deps=NULL;
	}
	delete node_dependency_traversal;
	node_dependency_traversal=NULL;
	std::get<1>(nr_of_deps_found)=0;
	std::get<2>(nr_of_deps_found)=0;
	if(nodes_to_be_validated.empty()==true){
		std::cout<<"dependencies with longest match:"<<std::endl;
		for(auto&& i:map_of_node_ids_to_total_nr_of_deps_and_d_key){
			std::cout<<"functor "<<get_node_info(i.first).expression.lexeme<<" d_key "<<i.second.second<<":"<<std::get<1>(i.second.first)<<"/"<<std::get<2>(i.second.first)<<std::endl;
			std::get<1>(nr_of_deps_found)+=std::get<1>(i.second.first);
			std::get<2>(nr_of_deps_found)+=std::get<2>(i.second.first);
		}
	}
	else exit(EXIT_FAILURE);//TODO: debug what happened...
	//2) loop over functor_node_found.second (vector of children) and call recursively for each the method itself
	for(auto&& i:functor_node_found->second){
		nr_of_deps_found_tmp=calculate_longest_matching_dependency_route(node_level+1,i,map_of_node_ids_to_total_nr_of_deps_and_d_key);
		std::get<1>(nr_of_deps_found)+=std::get<1>(nr_of_deps_found_tmp);
		std::get<2>(nr_of_deps_found)+=std::get<2>(nr_of_deps_found_tmp);
	}
	return nr_of_deps_found;
}

unsigned int interpreter::is_valid_combination(const std::string& symbol, const node_info& new_phrase_head_root, const node_info& new_phrase_non_head_root){
	bool valid_combination=false;
	db *sqlite=NULL;
	query_result *rule_to_rule_map=NULL;
	std::multimap<std::pair<std::string,std::string>,std::pair<unsigned int,std::string> > *functors_found=NULL;
	std::multimap<unsigned int,unsigned int>::const_iterator l;
	std::vector<unsigned int>::const_iterator j,k;
	std::vector<unsigned int> main_nodes_found_by_symbol,dependent_nodes_found_by_symbol,main_subtree_nodes_found_by_symbol,dependency_subtree_nodes_found_by_symbol;
	const std::pair<const unsigned int,field> *rule_entry=NULL,*rule_entry_failure_copy=NULL;
	unsigned int current_step=0,successor=0,failover=0,main_node_id=0,dep_node_id=0,rule_step_failed=0;
	std::multimap<unsigned int,std::pair<unsigned int,unsigned int> > functors_validated_for_nodes;
	node_info *main_node=NULL,*dependent_node=NULL;
	std::multimap<unsigned int,unsigned int> ref_node_ids_to_set;
	std::set<unsigned int>::const_iterator main_ref_node_id,dep_ref_node_id;

	sqlite=db::get_instance();
	rule_to_rule_map=sqlite->exec_sql("SELECT * FROM RULE_TO_RULE_MAP WHERE PARENT_SYMBOL = '"+symbol+"' AND HEAD_ROOT_SYMBOL = '"+new_phrase_head_root.symbol+"' AND NON_HEAD_ROOT_SYMBOL = '"+new_phrase_non_head_root.symbol+"' ORDER BY STEP;");
	if(rule_to_rule_map==NULL) exit(EXIT_FAILURE);//TODO: throw exception
	rule_entry=rule_to_rule_map->first_value_for_field_name_found("step","1");
	while(rule_entry!=NULL){
		rule_entry_failure_copy=rule_entry;
		current_step=std::atoi(rule_to_rule_map->field_value_at_row_position(rule_entry->first,"step")->c_str());
//		std::cout<<"step:"<<current_step<<std::endl;
		failover=std::atoi(rule_to_rule_map->field_value_at_row_position(rule_entry->first,"failover")->c_str());
//		std::cout<<"failover:"<<failover<<std::endl;
		successor=std::atoi(rule_to_rule_map->field_value_at_row_position(rule_entry->first,"successor")->c_str());
//		std::cout<<"successor:"<<successor<<std::endl;
		main_nodes_found_by_symbol.clear();
		dependent_nodes_found_by_symbol.clear();
		main_subtree_nodes_found_by_symbol.clear();
		dependency_subtree_nodes_found_by_symbol.clear();
		if(*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"head_root_symbol")==new_phrase_head_root.symbol
			&&*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"non_head_root_symbol")==new_phrase_non_head_root.symbol){
			if(rule_to_rule_map->field_value_at_row_position(rule_entry->first,"main_node_symbol")->empty()==false){
				if(*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"main_lookup_root")=="H"){
					if(rule_to_rule_map->field_value_at_row_position(rule_entry->first,"main_lookup_subtree_symbol")->empty()==true)
						get_nodes_by_symbol(new_phrase_head_root,*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"main_node_symbol"),*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"main_node_lexeme"),main_nodes_found_by_symbol);
					else{
						get_nodes_by_symbol(new_phrase_head_root,*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"main_lookup_subtree_symbol"),std::string(),main_subtree_nodes_found_by_symbol);
						for(auto&& main_subtree_node:main_subtree_nodes_found_by_symbol){
							get_nodes_by_symbol(get_node_info(main_subtree_node),*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"main_node_symbol"),*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"main_node_lexeme"),main_nodes_found_by_symbol);
						}
					}
				}
				else if(*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"main_lookup_root")=="N"){
					if(rule_to_rule_map->field_value_at_row_position(rule_entry->first,"main_lookup_subtree_symbol")->empty()==true)
						get_nodes_by_symbol(new_phrase_non_head_root,*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"main_node_symbol"),*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"main_node_lexeme"),main_nodes_found_by_symbol);
					else{
						get_nodes_by_symbol(new_phrase_non_head_root,*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"main_lookup_subtree_symbol"),std::string(),main_subtree_nodes_found_by_symbol);
						for(auto&& main_subtree_node:main_subtree_nodes_found_by_symbol){
							get_nodes_by_symbol(get_node_info(main_subtree_node),*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"main_node_symbol"),*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"main_node_lexeme"),main_nodes_found_by_symbol);
						}
					}
				}
				else{
					if(rule_to_rule_map->field_value_at_row_position(rule_entry->first,"main_lookup_subtree_symbol")->empty()==true){
						get_nodes_by_symbol(new_phrase_head_root,*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"main_node_symbol"),*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"main_node_lexeme"),main_nodes_found_by_symbol);
						get_nodes_by_symbol(new_phrase_non_head_root,*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"main_node_symbol"),*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"main_node_lexeme"),main_nodes_found_by_symbol);
					}
					else{
						get_nodes_by_symbol(new_phrase_head_root,*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"main_lookup_subtree_symbol"),std::string(),main_subtree_nodes_found_by_symbol);
						get_nodes_by_symbol(new_phrase_non_head_root,*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"main_lookup_subtree_symbol"),std::string(),main_subtree_nodes_found_by_symbol);
						for(auto&& main_subtree_node:main_subtree_nodes_found_by_symbol){
							get_nodes_by_symbol(get_node_info(main_subtree_node),*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"main_node_symbol"),*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"main_node_lexeme"),main_nodes_found_by_symbol);
						}
					}
				}
			}
			if(rule_to_rule_map->field_value_at_row_position(rule_entry->first,"dependent_node_symbol")->empty()==false){
				if(*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"dependency_lookup_root")=="H"){
					if(rule_to_rule_map->field_value_at_row_position(rule_entry->first,"dependency_lookup_subtree_symbol")->empty()==true)
						get_nodes_by_symbol(new_phrase_head_root,*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"dependent_node_symbol"),*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"dependent_node_lexeme"),dependent_nodes_found_by_symbol);
					else{
						get_nodes_by_symbol(new_phrase_head_root,*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"dependency_lookup_subtree_symbol"),std::string(),dependency_subtree_nodes_found_by_symbol);
						for(auto&& dependency_subtree_node:dependency_subtree_nodes_found_by_symbol){
							get_nodes_by_symbol(get_node_info(dependency_subtree_node),*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"dependent_node_symbol"),*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"dependent_node_lexeme"),dependent_nodes_found_by_symbol);
						}
					}
				}
				else if(*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"dependency_lookup_root")=="N"){
					if(rule_to_rule_map->field_value_at_row_position(rule_entry->first,"dependency_lookup_subtree_symbol")->empty()==true)
						get_nodes_by_symbol(new_phrase_non_head_root,*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"dependent_node_symbol"),*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"dependent_node_lexeme"),dependent_nodes_found_by_symbol);
					else{
						get_nodes_by_symbol(new_phrase_non_head_root,*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"dependency_lookup_subtree_symbol"),std::string(),dependency_subtree_nodes_found_by_symbol);
						for(auto&& dependency_subtree_node:dependency_subtree_nodes_found_by_symbol){
							get_nodes_by_symbol(get_node_info(dependency_subtree_node),*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"dependent_node_symbol"),*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"dependent_node_lexeme"),dependent_nodes_found_by_symbol);
						}
					}
				}
				else{
					if(rule_to_rule_map->field_value_at_row_position(rule_entry->first,"dependency_lookup_subtree_symbol")->empty()==true){
						get_nodes_by_symbol(new_phrase_head_root,*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"dependent_node_symbol"),*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"dependent_node_lexeme"),dependent_nodes_found_by_symbol);
						get_nodes_by_symbol(new_phrase_non_head_root,*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"dependent_node_symbol"),*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"dependent_node_lexeme"),dependent_nodes_found_by_symbol);
					}
					else{
						get_nodes_by_symbol(new_phrase_head_root,*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"dependency_lookup_subtree_symbol"),std::string(),dependency_subtree_nodes_found_by_symbol);
						get_nodes_by_symbol(new_phrase_non_head_root,*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"dependency_lookup_subtree_symbol"),std::string(),dependency_subtree_nodes_found_by_symbol);
						for(auto&& dependency_subtree_node:dependency_subtree_nodes_found_by_symbol){
							get_nodes_by_symbol(get_node_info(dependency_subtree_node),*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"dependent_node_symbol"),*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"dependent_node_lexeme"),dependent_nodes_found_by_symbol);
						}
					}
				}
			}
			if(rule_to_rule_map->field_value_at_row_position(rule_entry->first,"main_node_symbol")->empty()==false
				&&rule_to_rule_map->field_value_at_row_position(rule_entry->first,"dependent_node_symbol")->empty()==false
				&&main_nodes_found_by_symbol.empty()==false
				&&dependent_nodes_found_by_symbol.empty()==false){
				for(auto&& i:ref_node_ids_to_set){
					dependent_node=&get_private_node_info(i.first);
					if(dependent_node->ref_node_ids.empty()==false){
						if(dependent_node->ref_node_ids.find(i.second)==dependent_node->ref_node_ids.end())
							dependent_node->ref_node_ids.insert(i.second);
					}
					else dependent_node->ref_node_ids.insert(i.second);
				}
				//1)Loop over main_nodes_found_by_symbol
				for(j=main_nodes_found_by_symbol.begin();j!=main_nodes_found_by_symbol.end();++j){
//					std::cout<<"loop pass on main_nodes_found_by_symbol:"<<*j<<std::endl;
					main_node=&get_private_node_info(*j);
//					std::cout<<"main node lexeme:"<<main_node->expression.lexeme<<std::endl;
					if(main_node->ref_node_ids.empty()==true) main_node_id=main_node->node_id;
					else{
						main_ref_node_id=main_node->ref_node_ids.begin();
						main_node_id=*main_ref_node_id;
					}
					while(main_node_id!=0){
						main_node=&get_private_node_info(main_node_id);
//						std::cout<<"main node refnode lexeme:"<<main_node->expression.lexeme<<std::endl;
						//2)Loop over dependent_nodes_found_by_symbol where dependent_node is NOT in current_main_node.node_links
						for(k=dependent_nodes_found_by_symbol.begin();k!=dependent_nodes_found_by_symbol.end();++k){
//							std::cout<<"loop pass on dependent_nodes_found_by_symbol:"<<*k<<std::endl;
							dependent_node=&get_private_node_info(*k);
//							std::cout<<"dependent node lexeme:"<<dependent_node->expression.lexeme<<std::endl;
							if(dependent_node->ref_node_ids.empty()==true) dep_node_id=dependent_node->node_id;
							else{
								dep_ref_node_id=dependent_node->ref_node_ids.begin();
								dep_node_id=*dep_ref_node_id;
							}
							while(dep_node_id!=0){
								dependent_node=&get_private_node_info(dep_node_id);
//								std::cout<<"dependent node refnode lexeme:"<<dependent_node->expression.lexeme<<std::endl;
								for(l=main_node->dependency_validation_matrix.begin();l!=main_node->dependency_validation_matrix.end();++l){
									//TODO:Consider if this logic is ok:
									//If a node is already registered in the main nodes's dvm for a dependency,
									//don't give a chance to register it for another dependency as well.
									if(l->second==dependent_node->node_id) break;
								}
								if(l==main_node->dependency_validation_matrix.end()){
									if(dependent_node->expression.morphalytics!=NULL
										&&dependent_node->expression.morphalytics->has_feature("Relative")==true){
										ref_node_ids_to_set.insert(std::make_pair(dependent_node->node_id,main_node->node_id));
										valid_combination=true;
									}
									else{
										functors_found=is_valid_expression(*main_node,*dependent_node);
										if(functors_found!=NULL){
											valid_combination=true;
											for(auto&& m:*functors_found){
												functors_validated_for_nodes.insert(std::make_pair(main_node->node_id,std::make_pair(m.second.first,dependent_node->node_id)));
											}
											delete functors_found;
										}
										else{
											if(failover==0||failover<current_step) valid_combination=false;
										}
									}
								}
								if(dep_node_id!=*k&&++dep_ref_node_id!=dependent_node->ref_node_ids.end())
									dep_node_id=*dep_ref_node_id;
								else dep_node_id=0;
							}
						}
						if(main_node_id!=*j&&++main_ref_node_id!=main_node->ref_node_ids.end())
							main_node_id=*main_ref_node_id;
						else main_node_id=0;
					}
				}
			}
			else if(rule_to_rule_map->field_value_at_row_position(rule_entry->first,"main_node_symbol")->empty()==false
					&&main_nodes_found_by_symbol.empty()==false
					&&rule_to_rule_map->field_value_at_row_position(rule_entry->first,"dependent_node_symbol")->empty()==true
					&&dependent_nodes_found_by_symbol.empty()==true
					||rule_to_rule_map->field_value_at_row_position(rule_entry->first,"main_node_symbol")->empty()==true
					&&main_nodes_found_by_symbol.empty()==true
					&&rule_to_rule_map->field_value_at_row_position(rule_entry->first,"dependent_node_symbol")->empty()==false
					&&dependent_nodes_found_by_symbol.empty()==false){//This branch allows checking just for symbol existence in a subtree
					if(successor==0||successor<current_step){
						valid_combination=false;
						break;
 					}
					else if(successor==current_step){
						valid_combination=true;
						break;
					}
					else{
						valid_combination=true;
					}
			}
			else if(rule_to_rule_map->field_value_at_row_position(rule_entry->first,"main_node_symbol")->empty()==false
					&&main_nodes_found_by_symbol.empty()==true
					&&rule_to_rule_map->field_value_at_row_position(rule_entry->first,"dependent_node_symbol")->empty()==true
					&&dependent_nodes_found_by_symbol.empty()==true
					||rule_to_rule_map->field_value_at_row_position(rule_entry->first,"main_node_symbol")->empty()==true
					&&main_nodes_found_by_symbol.empty()==true
					&&rule_to_rule_map->field_value_at_row_position(rule_entry->first,"dependent_node_symbol")->empty()==false
					&&dependent_nodes_found_by_symbol.empty()==true){//This branch allows checking just for symbol absence in a subtree
					if(failover==0||failover<current_step){
						valid_combination=false;
						break;
					}
					else if(failover==current_step){
						valid_combination=true;
						break;
					}
					else{
						valid_combination=false;
					}
			}
			else if(rule_to_rule_map->field_value_at_row_position(rule_entry->first,"main_node_symbol")->empty()==false
				&&rule_to_rule_map->field_value_at_row_position(rule_entry->first,"dependent_node_symbol")->empty()==false
				&&(main_nodes_found_by_symbol.empty()==true||dependent_nodes_found_by_symbol.empty()==true)){
				if(failover==0||failover<current_step){
					valid_combination=false;
				}
			}
			else{
				exit(EXIT_FAILURE);//TODO: throw exception
			}
			if(valid_combination==true){
				if(successor>current_step){
					rule_entry=rule_to_rule_map->value_for_field_name_found_after_row_position(rule_entry->first,"step",*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"successor"));
				}
				else if(successor!=0&&successor<=current_step) exit(EXIT_FAILURE);//TODO: throw exception
				else{
					rule_entry=NULL;
				}
			}
			else{
				if(failover>current_step){
					rule_entry=rule_to_rule_map->value_for_field_name_found_after_row_position(rule_entry->first,"step",*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"failover"));
				}
				else if(failover!=0&&failover<current_step) exit(EXIT_FAILURE);//TODO: throw exception
				else{
					rule_entry=NULL;
					if(failover==current_step&&rule_to_rule_map->nr_of_result_rows()==current_step) valid_combination=true;
				}
			}
		}
		else{
			exit(EXIT_FAILURE);//TODO: throw exception
		}
	}
	if(valid_combination==true){
		rule_step_failed=0;
		for(auto&& i:functors_validated_for_nodes){
			main_node=&get_private_node_info(i.first);
			dependent_node=&get_private_node_info(i.second.second);
			main_node->dependency_validation_matrix.insert(i.second);
			if(dependent_node->node_links.find(main_node->node_id)==dependent_node->node_links.end()){
				dependent_node->node_links.insert(std::make_pair(main_node->node_id,0));//TODO:get rid of second member in node_links
			}
		}
	}
	else{
		rule_step_failed=std::atoi(rule_entry_failure_copy->second.field_value.c_str());
		for(auto&& i:ref_node_ids_to_set){
			dependent_node=&get_private_node_info(i.first);
			dependent_node->ref_node_ids.erase(i.second);
		}
	}
	delete rule_to_rule_map;
	return rule_step_failed;
}

transgraph* interpreter::build_transgraph(const p_m1_node_id_m2_d_key& root, const std::pair<std::string,unsigned int>& parent,
		std::map<p_m1_node_id_m2_d_key,std::pair<t_m0_parent_node_m1_nr_of_deps_m2_nr_of_deps_to_find_m3_parent_dkey_m4_parent_dcounter,std::map<unsigned int,std::pair<t_m0_parent_node_m1_nr_of_deps_m2_nr_of_deps_to_find_m3_parent_dkey_m4_parent_dcounter,unsigned int> > > >& longest_traversals,
		const unsigned int node_level){
	p_m1_tree_level_m2_p_m1_node_id_m2_d_key tree_level_and_functor_node;
	std::set<std::pair<std::string,unsigned int> > functors_processed;
	transgraph *functor_transgraph=NULL;

//	std::cout<<"parent.first:"<<parent.first<<", parent.second:"<<parent.second<<std::endl;
	auto root_found=longest_traversals.find(root);
	if(root_found==longest_traversals.end()) exit(EXIT_FAILURE);//TODO: throw exception
	if(std::atoi(parent.first.c_str())>0){
//		std::cout<<get_node_info(std::atoi(parent.first.c_str())).expression.lexeme<<"_"<<parent.second<<std::endl;
		functor_transgraph=new transgraph(std::make_pair(get_node_info(std::atoi(parent.first.c_str())).expression.lexeme,parent.second),get_node_info(std::atoi(parent.first.c_str())).expression.morphalytics);
	}
	else{
//		std::cout<<parent.first<<"_"<<parent.second<<std::endl;
		functor_transgraph=new transgraph(std::make_pair(parent.first,parent.second),NULL);
	}
	for(auto&& i:root_found->second.second){
//		std::cout<<"debug lexeme:"<<get_node_info(i.first).expression.lexeme<<", d_key (i.second.second):"<<i.second.second<<
//		" parent node:"<<std::get<0>(i.second.first)<<
//		" parent d_key:"<<std::get<3>(i.second.first)<<
//		", i.first:"<<i.first<<std::endl;
		if(std::get<0>(i.second.first)==parent.first&&std::get<3>(i.second.first)==parent.second
		&&(i.first!=std::atoi(parent.first.c_str())||i.first==std::atoi(parent.first.c_str())&&i.second.second!=parent.second)){
			if(functors_processed.find(std::make_pair(std::to_string(i.first),i.second.second))==functors_processed.end()){
//				std::cout<<"recursive call 1"<<std::endl;
//				std::cout<<"debug lexeme:"<<get_node_info(i.first).expression.lexeme;
//				std::cout<<", d_key (i.second.second):"<<i.second.second;
//				std::cout<<", parent node:"<<std::get<0>(i.second.first);
//				std::cout<<", parent d_key:"<<std::get<3>(i.second.first);
//				std::cout<<", i.first:"<<i.first<<std::endl;
				functor_transgraph->insert(std::get<4>(i.second.first),build_transgraph(root,std::make_pair(std::to_string(i.first),i.second.second),longest_traversals,node_level));
				functors_processed.insert(std::make_pair(std::to_string(i.first),i.second.second));
//				std::cout<<"recursive return 1"<<std::endl;
			}
		}
		else if(std::all_of(std::get<0>(i.second.first).begin(),std::get<0>(i.second.first).end(),::isdigit)==false){//checking for parent being string indeed
			tree_level_and_functor_node.first=node_level;
			tree_level_and_functor_node.second=root;
			auto functor_node_found=node_dependency_traversal_stack_tree.find(tree_level_and_functor_node);
			if(functor_node_found==node_dependency_traversal_stack_tree.end()) exit(EXIT_FAILURE);//TODO: throw exception
			auto functor_node_odependencies=node_odependency_traversals.find(functor_node_found->first.second);
			if(functor_node_odependencies==node_odependency_traversals.end()) exit(EXIT_FAILURE);//TODO: throw exception
			for(auto&& i:functor_node_odependencies->second){
				if(std::get<0>(i.second)==parent.first&&std::get<1>(i.second)==parent.second){
					if(functors_processed.find(std::make_pair(i.first.first,i.first.second))==functors_processed.end()){
//						std::cout<<"recursive call 2"<<std::endl;
//						std::cout<<"debug lexeme:"<<i.first.first<<", d_key:"<<i.first.second<<
//						", parent node:"<<i.second.first<<", parent d_key:"<<i.second.second<<std::endl;
						functor_transgraph->insert(std::get<2>(i.second),build_transgraph(root,std::make_pair(i.first.first,i.first.second),longest_traversals,node_level));
						functors_processed.insert(std::make_pair(i.first.first,i.first.second));
//						std::cout<<"recursive return 2"<<std::endl;
					}
				}
			}
		}
	}
	return functor_transgraph;
}

unsigned int interpreter::add_feature_to_leaf(const node_info& node, const std::string& feature){
	unsigned int leaf_node_id=0;

	leaf_node_id=direct_descendant_of(node);
	if(leaf_node_id>0){
		const node_info& leaf_node=get_node_info(leaf_node_id);
		leaf_node.expression.morphalytics->add_feature(feature);
	}
	return leaf_node_id;
}

unsigned int interpreter::add_feature_to_leaf(const node_info& node, const std::string& leaf_symbol, const std::string& feature){
	unsigned int leaf_node_id=0;
	std::vector<unsigned int> nodes;

	get_nodes_by_symbol(node,leaf_symbol,std::string(),nodes);
	if(nodes.empty()==false) leaf_node_id=*nodes.begin();//Take only the first
	if(leaf_node_id>0){
		const node_info& leaf_node=get_node_info(leaf_node_id);
		leaf_node.expression.morphalytics->add_feature(feature);
	}
	return leaf_node_id;
}

unsigned int interpreter::direct_descendant_of(const node_info& root_node){
	if(root_node.left_child==0&&root_node.right_child==0){
		//std::cout<<"direct descendant found: "<<root_node.node_id<<std::endl;
		return root_node.node_id;
	}
	if(root_node.left_child!=0&&root_node.right_child==0) return direct_descendant_of(get_node_info(root_node.left_child));
	else if(root_node.right_child!=0&&root_node.left_child==0) return direct_descendant_of(get_node_info(root_node.right_child));
	else return 0;
}

void interpreter::get_leafs_of_node_lr(const node_info& root_node, std::vector<unsigned int>& leafs){
	if(root_node.left_child==0&&root_node.right_child==0){
		leafs.push_back(root_node.node_id);
//		std::cout<<"leaf word:"<<root_node.expression.word<<std::endl;
		return;
	}
	if(root_node.left_child!=0)get_leafs_of_node_lr(get_node_info(root_node.left_child),leafs);
	if(root_node.right_child!=0)get_leafs_of_node_lr(get_node_info(root_node.right_child),leafs);
}

std::set<unsigned int> interpreter::validated_terminals(){
	std::vector<unsigned int> leafs;
	std::set<unsigned int> terminals;

	for(auto&& i:validated_nodes){
		leafs.clear();
		get_leafs_of_node_lr(get_node_info(i),leafs);
		for(auto&& j:leafs){
			terminals.insert(j);
		}
	}
	return terminals;
}

void interpreter::destroy_node_infos(){
	nr_of_nodes=0;
	return;
}
