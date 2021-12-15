#include "logger.h"
#include "sp.h"
#include "hi_constants.h"
#include <iterator>
#include <algorithm>
#include <functional>
#include "lexer.h"

/*PUBLIC*/
interpreter::interpreter(const unsigned char toa){
    nr_of_nodes_=0;
	toa_=toa;
}

interpreter::~interpreter(){
	destroy_node_infos();
}

int interpreter::set_node_info(const std::string& symbol, const lexicon& word){
	node_info nodeinfo;
	db *sqlite=NULL;
	unsigned int rule_step_failed=0;

    nodeinfo.node_id=++nr_of_nodes_;
	nodeinfo.symbol=symbol;
	if(word.lexeme.empty()==false){
		if(word.gcat.empty()==true){
			throw std::runtime_error("No way that I set an empty gcat for a node.");
		}
		nodeinfo.expression=word;
	}
	nodeinfo.left_child=0;
	nodeinfo.right_child=0;
	node_infos.push_back(nodeinfo);
	return nodeinfo.node_id;
}

int interpreter::set_node_info(const std::string& symbol, const node_info& node){
	lexicon word;
	node_info nodeinfo;
	db *sqlite=NULL;
	unsigned int rule_step_failed=0;

	word.gcat=symbol;
    nodeinfo.node_id=++nr_of_nodes_;
	if(word.gcat.empty()==true){
		throw std::runtime_error("No way that I set an empty gcat for a node.");
	}
	nodeinfo.symbol=symbol;
	if(word.lexeme.empty()==false) nodeinfo.expression=word;
	nodeinfo.left_child=0;
	nodeinfo.right_child=node.node_id;
	node_infos.push_back(nodeinfo);
	if(nodeinfo.right_child!=0){//This means that no checks can be set up for nonterminal->terminal symbol rules
		rule_step_failed=check_prerequisite_symbols(nodeinfo,get_node_info(nodeinfo.right_child));
		if(rule_step_failed!=0){
			throw missing_prerequisite_symbol(nodeinfo.symbol,get_node_info(nodeinfo.right_child).symbol);
		}
	}
	return nodeinfo.node_id;
}

unsigned int interpreter::check_prerequisite_symbols(const node_info& parent_node, const node_info& child_node){
	bool valid_combination=false;
	db *sqlite=NULL;
	query_result *rule_to_rule_map=NULL;
	std::vector<unsigned int> main_nodes_found_by_symbol,main_subtree_nodes_found_by_symbol;
	const std::pair<const unsigned int,field> *rule_entry=NULL,*rule_entry_failure_copy=NULL;
	unsigned int current_step=0,successor=0,failover=0,rule_step_failed=0;

	logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"checking prerequisite symbols for parent symbol:"+parent_node.symbol+", child symbol:"+child_node.symbol);
	sqlite=db_factory::get_instance();
	rule_to_rule_map=sqlite->exec_sql("SELECT * FROM RULE_TO_RULE_MAP WHERE PARENT_SYMBOL = '"+parent_node.symbol+"' AND HEAD_ROOT_SYMBOL = '"+child_node.symbol+"' AND (NON_HEAD_ROOT_SYMBOL = '' OR NON_HEAD_ROOT_SYMBOL IS NULL) ORDER BY STEP;");
	if(rule_to_rule_map!=NULL){
		rule_entry=rule_to_rule_map->first_value_for_field_name_found("step","1");
		while(rule_entry!=NULL){
			rule_entry_failure_copy=rule_entry;
			current_step=std::atoi(rule_to_rule_map->field_value_at_row_position(rule_entry->first,"step")->c_str());
			logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"step:"+std::to_string(current_step));
			failover=std::atoi(rule_to_rule_map->field_value_at_row_position(rule_entry->first,"failover")->c_str());
			logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"failover:"+std::to_string(failover));
			successor=std::atoi(rule_to_rule_map->field_value_at_row_position(rule_entry->first,"successor")->c_str());
			logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"successor:"+std::to_string(successor));
			main_nodes_found_by_symbol.clear();
			main_subtree_nodes_found_by_symbol.clear();
			if(*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"parent_symbol")==parent_node.symbol
				&&*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"head_root_symbol")==child_node.symbol){
				if(rule_to_rule_map->field_value_at_row_position(rule_entry->first,"main_node_symbol")->empty()==false){
					if(rule_to_rule_map->field_value_at_row_position(rule_entry->first,"main_lookup_subtree_symbol")->empty()==true)
						get_nodes_by_symbol(child_node,*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"main_node_symbol"),*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"main_node_lexeme"),main_nodes_found_by_symbol);
					else{
						get_nodes_by_symbol(child_node,*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"main_lookup_subtree_symbol"),std::string(),main_subtree_nodes_found_by_symbol);
						for(auto&& main_subtree_node:main_subtree_nodes_found_by_symbol){
							get_nodes_by_symbol(get_node_info(main_subtree_node),*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"main_node_symbol"),*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"main_node_lexeme"),main_nodes_found_by_symbol);
						}
					}
				}
				else{
					throw std::runtime_error("Main node symbol is empty for parent symbol "+parent_node.symbol+", head root symbol "+child_node.symbol+" and empty or NULL non-head root symbol in RULE_TO_RULE_MAP db table.");
				}
				if(rule_to_rule_map->field_value_at_row_position(rule_entry->first,"main_node_symbol")->empty()==false
						&&main_nodes_found_by_symbol.empty()==false){
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
						&&main_nodes_found_by_symbol.empty()==true){
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
				else{
					throw std::runtime_error("Main node symbol is empty for parent symbol "+parent_node.symbol+", head root symbol "+child_node.symbol+" and empty or NULL non-head root symbol in RULE_TO_RULE_MAP db table.");
				}
				if(valid_combination==true){
					if(successor>current_step){
						rule_entry=rule_to_rule_map->value_for_field_name_found_after_row_position(rule_entry->first,"step",*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"successor"));
					}
					else if(successor!=0&&successor<=current_step){
						throw std::runtime_error("You have a successor branch loop for parent symbol "+parent_node.symbol+", head root symbol "+child_node.symbol+" and empty/NULL non-head root symbol at step "+std::to_string(current_step)+". Sorry, no loops are allowed in the rule to rule map.");
					}
					else{
						rule_entry=NULL;
					}
				}
				else{
					if(failover>current_step){
						rule_entry=rule_to_rule_map->value_for_field_name_found_after_row_position(rule_entry->first,"step",*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"failover"));
					}
					else if(failover!=0&&failover<current_step){
						throw std::runtime_error("You have a failover branch loop for parent symbol "+parent_node.symbol+", head root symbol "+child_node.symbol+" and empty/NULL non-head root symbol at step "+std::to_string(current_step)+". Sorry, no loops are allowed in the rule to rule map.");
					}
					else{
						rule_entry=NULL;
						if(failover==current_step&&rule_to_rule_map->nr_of_result_rows()==current_step) valid_combination=true;
					}
				}
			}
			else{
				throw std::runtime_error("No entry found for parent symbol "+parent_node.symbol+", head root symbol "+child_node.symbol+" and empty or NULL non-head root symbol in RULE_TO_RULE_MAP db table.");
			}
		}
		if(valid_combination==true){
			rule_step_failed=0;
		}
		else{
			rule_step_failed=std::atoi(rule_entry_failure_copy->second.field_value.c_str());
		}
		delete rule_to_rule_map;
	}
	return rule_step_failed;
}

const node_info& interpreter::get_node_info(unsigned int node_id){
	if(node_id>0) return node_infos.at(node_id-1);//Make use of out_of_range exception
}

node_info& interpreter::get_private_node_info(unsigned int node_id){
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
        nodeinfo.node_id=++nr_of_nodes_;
		nodeinfo.symbol=symbol;
		if(toa_&HI_SEMANTICS){
			sqlite=db_factory::get_instance();
            logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"Looking for symbols for parent:"+symbol+", head root:"+new_phrase_head_root.symbol+", non-head root:"+new_phrase_non_head_root.symbol);
			rule_to_rule_map=sqlite->exec_sql("SELECT * FROM RULE_TO_RULE_MAP WHERE PARENT_SYMBOL = '"+symbol+"' AND HEAD_ROOT_SYMBOL = '"+new_phrase_head_root.symbol+"' AND NON_HEAD_ROOT_SYMBOL = '"+new_phrase_non_head_root.symbol+"';");
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
						if(get_node_info(i).expression.morphalytics!=NULL&&get_node_info(i).expression.morphalytics->is_mocked()==false&&get_node_info(i).expression.word.empty()==false)
							head_leaf_words+=get_node_info(i).expression.morphalytics->word()+" ";
					}
					if(head_leaf_words.empty()==false) head_leaf_words.pop_back();
					for(auto&& i:non_head_leafs){
						if(get_node_info(i).expression.morphalytics!=NULL&&get_node_info(i).expression.morphalytics->is_mocked()==false&&get_node_info(i).expression.word.empty()==false)
							non_head_leaf_words+=get_node_info(i).expression.morphalytics->word()+" ";
					}
					if(non_head_leaf_words.empty()==false) non_head_leaf_words.pop_back();
                    throw invalid_combination(head_leaf_words,non_head_leaf_words);
				}
			}
		}
		nodeinfo.left_child=left_node.node_id;
		nodeinfo.right_child=right_node.node_id;
		node_infos.push_back(nodeinfo);
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
					if(functors->begin()->first.first!=main_node.expression.lexeme){
						throw std::runtime_error("Functor "+functors->begin()->first.first+" and main node lexeme "+main_node.expression.lexeme+" don't match.");
					}
				}
				else if(functors->count(functors->begin()->first)<functors->size()){//More than one functor is acceptable as an intermediate result
				}
				else{
					throw std::runtime_error("More functors found for "+functors->begin()->first.first+" with key "+functors->begin()->first.second+" than the number of functors found altogether.");
				}
			}
		}
	}
	return functors;
}

std::multimap<std::pair<std::string,std::string>,std::pair<unsigned int,std::string> >* interpreter::functors_found_for_dependencies(const node_info& dependent_node, node_info& main_node){
	std::multimap<std::pair<std::string,std::string>,std::pair<unsigned int,std::string> > *functors_found=NULL;
	std::set<std::tuple<std::string,std::string,unsigned int,std::string> > functors_deps_found_unique;
	std::string d_key_list,functor;
	query_result *functors=NULL;
	std::vector<std::pair<unsigned int,std::string> > dependency_stack;
	db *sqlite=NULL;
	field field;

	functor=main_node.expression.lexeme;
	logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"functor to be found for dependency "+dependent_node.expression.lexeme+":"+functor);
	functors_found=new std::multimap<std::pair<std::string,std::string>,std::pair<unsigned int,std::string> >();
	if(dependent_node.expression.gcat=="CON"){
		find_functors_for_dependency("CON","",*main_node.expression.dependencies,*functors_found,dependency_stack);
	}
	else if(dependent_node.expression.lexicon_entry==false){
		find_functors_for_dependency(dependent_node.expression.gcat,"",*main_node.expression.dependencies,*functors_found,dependency_stack);
	}
	else{
		find_functors_for_dependency(dependent_node.expression.lexeme,"",*main_node.expression.dependencies,*functors_found,dependency_stack);
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
	sqlite=db_factory::get_instance();
	functors=sqlite->exec_sql("SELECT * FROM FUNCTORS WHERE FUNCTOR = '"+functor+"' AND D_KEY IN "+d_key_list+";");
	if(functors==NULL){
		throw std::runtime_error("Functor "+functor+" not found in FUNCTOR db table.");
	}
	for(auto i=functors_found->begin();i!=functors_found->end();){
		if(i->first.first==functor&&functors_deps_found_unique.find(std::make_tuple(i->first.first,i->first.second,i->second.first,i->second.second))==functors_deps_found_unique.end()){
			logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"dependency "+i->second.second+" with node id "+std::to_string(dependent_node.node_id)
			+" and depolex row id "+std::to_string(i->second.first)
			+" for functor "+i->first.first+" with d_key "+i->first.second
			+" with node id "+std::to_string(main_node.node_id)+" found");
			functors_deps_found_unique.insert(std::make_tuple(i->first.first,i->first.second,i->second.first,i->second.second));
			++i;
		}
		else{
			i=functors_found->erase(i);
		}
	}
	return functors_found;
}

void interpreter::find_functors_for_dependency(const std::string& dependency, const std::string& d_key, const query_result& dependencies,
		std::multimap<std::pair<std::string,std::string>,std::pair<unsigned int,std::string> >& functors_found,
		std::vector<std::pair<unsigned int,std::string> >& dependency_stack){
	const std::pair<const unsigned int,field> *depolex_entry=NULL;
	std::string lexeme,lexeme_d_key;
	std::vector<std::pair<unsigned int,std::string> >::const_iterator j;

	if(&dependencies!=NULL){//c++ battlefield: null object reference is possible, check it
		depolex_entry=dependencies.first_value_for_field_name_found("semantic_dependency",dependency);
		if(d_key.empty()==false){
			while(depolex_entry!=NULL&&*dependencies.field_value_at_row_position(depolex_entry->first,"semantic_dependency")==dependency
					&&*dependencies.field_value_at_row_position(depolex_entry->first,"ref_d_key")!=d_key){
				depolex_entry=dependencies.value_for_field_name_found_after_row_position(depolex_entry->first,"semantic_dependency",dependency);
			}
		}
		while(depolex_entry!=NULL){
			logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"looking for functor with dependency "
			+*dependencies.field_value_at_row_position(depolex_entry->first,"semantic_dependency")+" with d_key "
			+*dependencies.field_value_at_row_position(depolex_entry->first,"d_key"));
			lexeme=*dependencies.field_value_at_row_position(depolex_entry->first,"lexeme");
			lexeme_d_key=*dependencies.field_value_at_row_position(depolex_entry->first,"d_key");
			for(j=dependency_stack.begin();j!=dependency_stack.end();++j){
				if(j->first==depolex_entry->first&&j->second==depolex_entry->second.field_value) break;
			}
			if(j==dependency_stack.end()){
				logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"push to dependency stack the row index:"+std::to_string(depolex_entry->first)+" and semantic dependency:"+depolex_entry->second.field_value);
				dependency_stack.push_back(std::make_pair(depolex_entry->first,depolex_entry->second.field_value));
				logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"inserting in functors_found an entry with row id "+std::to_string(dependency_stack.begin()->first)+", functor="+lexeme+" d_key="+lexeme_d_key);
				functors_found.insert(std::make_pair(std::make_pair(lexeme,lexeme_d_key),*dependency_stack.begin()));
				find_functors_for_dependency(lexeme,lexeme_d_key,dependencies,functors_found,dependency_stack);
				logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"pop from dependency stack the row index:"+std::to_string(depolex_entry->first)+" and semantic dependency:"+depolex_entry->second.field_value);
				dependency_stack.pop_back();
			}
			depolex_entry=dependencies.value_for_field_name_found_after_row_position(depolex_entry->first,"semantic_dependency",dependency);
			if(d_key.empty()==false){
				while(depolex_entry!=NULL&&*dependencies.field_value_at_row_position(depolex_entry->first,"semantic_dependency")==dependency
						&&*dependencies.field_value_at_row_position(depolex_entry->first,"ref_d_key")!=d_key){
					depolex_entry=dependencies.value_for_field_name_found_after_row_position(depolex_entry->first,"semantic_dependency",dependency);
				}
			}
		}
	}
}

void interpreter::get_nodes_by_symbol(const node_info& root_node, const std::string symbol, const std::string lexeme, std::vector<unsigned int>& nodes_found){
	//root_node: root node of the subtree in which the node should be found by the symbol
	//symbol: symbol of the node by which the node should be found
	//nodes_found: node ids of the nodes found
	logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"get nodes by symbol: "+symbol);
	if(symbol.empty()==false){
		if(root_node.symbol==symbol&&lexeme.empty()==true
			||lexeme.empty()==true&&root_node.expression.morphalytics!=NULL&&root_node.expression.morphalytics->gcat()==symbol
			||lexeme.empty()==true&&root_node.expression.morphalytics!=NULL&&root_node.expression.morphalytics->is_mocked()==false&&root_node.expression.morphalytics->has_feature(symbol)==true
			||lexeme.empty()==false&&root_node.expression.morphalytics!=NULL&&root_node.expression.morphalytics->gcat()==symbol&&root_node.expression.lexeme==lexeme){
			logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"node_found_by_symbol '"+symbol+"':"+std::to_string(root_node.node_id));
			nodes_found.push_back(root_node.node_id);
		}
		if(root_node.left_child!=0)get_nodes_by_symbol(get_node_info(root_node.left_child),symbol,lexeme,nodes_found);
		if(root_node.right_child!=0)get_nodes_by_symbol(get_node_info(root_node.right_child),symbol,lexeme,nodes_found);
	}
	else{
		throw std::runtime_error("Do you want me to look for empty symbols in parser tree? Stop.");
	}
}

void interpreter::find_dependencies_for_node(const unsigned int node_id, t_map_of_node_ids_and_d_keys_to_nr_of_deps& dependencies_found,
		std::multimap<std::pair<std::string,unsigned int>,std::tuple<std::string,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int> >& optional_dependencies_checked){
	std::pair<unsigned int,unsigned int> dependency_for_d_key_found;
	std::string d_key="0";
	unsigned int d_counter=0;
	const std::pair<const unsigned int,field> *depolex_entry=NULL;
	std::vector<p_m1_node_id_m2_d_key> node_d_key_route;
	p_m1_node_id_m2_d_key parent_node;
	//TODO: shall dependencies_found_via_optional_paths be a map instead of multimap?
	std::multimap<unsigned int,std::tuple<unsigned int,unsigned int,unsigned int,unsigned int> > dependencies_found_via_optional_paths;
	std::set<unsigned int> unique_optional_dependency_paths;

	const node_info& node=get_node_info(node_id);
	depolex_entry=node.expression.dependencies->first_value_for_field_name_found("lexeme",node.expression.lexeme);
	while(depolex_entry!=NULL&&node.expression.lexeme==*node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"lexeme")
			&&d_key!=*node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"d_key")){
		d_key=*node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"d_key");
		d_counter=std::atoi(node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"d_counter")->c_str());
		logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"checking top level entry for functor "+node.expression.lexeme+" d_key "+d_key);
		if(node_dependency_traversal_stack.empty()==false){
			parent_node=node_dependency_traversal_stack.top();
			auto traversal_node=node_dependency_traversal_stack_tree.find(std::make_pair(node_dependency_traversal_stack.size(),parent_node));
			if(traversal_node!=node_dependency_traversal_stack_tree.end()&&node.node_links.find(parent_node.first)!=node.node_links.end()){
				traversal_node->second.push_back(std::make_pair(node_id,std::atoi(d_key.c_str())));
				logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"push_back to vector of node_id "+std::to_string(parent_node.first)+" with d_key "+std::to_string(parent_node.second)+" the node_id "+std::to_string(node_id)+" with d_key "+d_key);
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
		logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"pushed to stack node_id "+std::to_string(node_id)+" with d_key "+d_key);
		auto traversal_node=node_dependency_traversal_stack_tree.find(std::make_pair(node_dependency_traversal_stack.size(),std::make_pair(node_id,std::atoi(d_key.c_str()))));
		if(traversal_node==node_dependency_traversal_stack_tree.end()){
			node_d_key_route.clear();
			node_dependency_traversal_stack_tree.insert(std::make_pair(std::make_pair(node_dependency_traversal_stack.size(),std::make_pair(node_id,std::atoi(d_key.c_str()))),node_d_key_route));
			logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"inserting in traversal tree at level "+std::to_string(node_dependency_traversal_stack.size())+": node_id "+std::to_string(node_id)+" with d_key "+d_key+" the node_d_key_route");
		}
		else{
			throw std::runtime_error("What shall I do in this case? A previously processed node with its functor/d_key gets processed again. There may be a conflict in the rule_to_rule_map table.");
		}
		find_dependencies_for_functor(std::to_string(node.node_id),d_key,d_counter,node.node_id,d_key,dependencies_found,optional_dependencies_checked,dependencies_found_via_optional_paths);
		unique_optional_dependency_paths.clear();
		for(auto&& i:dependencies_found_via_optional_paths){
			//if there are more than one optional dependency paths leading to the same real dependency,
			//select the first one and collect them in a set
			logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"checking uniqueness of optional dependency with path nr "+std::to_string(i.first)
			+" and node id "+std::to_string(std::get<0>(i.second))
			+" d_key "+std::to_string(std::get<1>(i.second))
			+" dependent node id "+std::to_string(std::get<2>(i.second))
			+" odep level "+std::to_string(std::get<3>(i.second)));
			bool duplicate_found=false;
			for(auto&& j:unique_optional_dependency_paths){
				auto optional_dependency_path=dependencies_found_via_optional_paths.find(j);
				logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"against optional dependency with path nr "+std::to_string(j)
				+" and node id "+std::to_string(std::get<0>(optional_dependency_path->second))
				+" d_key "+std::to_string(std::get<1>(optional_dependency_path->second))
				+" dependent node id "+std::to_string(std::get<2>(optional_dependency_path->second))
				+" odep level "+std::to_string(std::get<3>(optional_dependency_path->second)));
				if(i.first!=j&&std::get<0>(i.second)==std::get<0>(optional_dependency_path->second)
					&&std::get<1>(i.second)==std::get<1>(optional_dependency_path->second)
					&&std::get<2>(i.second)==std::get<2>(optional_dependency_path->second)){
					duplicate_found=true;
					logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"duplicate found");
				}
			}
			if(duplicate_found==false){
				logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"inserting optional dependency in unique optional dependency paths");
				unique_optional_dependency_paths.insert(i.first);
			}
		}
		for(std::map<std::pair<std::string,unsigned int>,std::tuple<std::string,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int> >::iterator j=optional_dependencies_checked.begin();j!=optional_dependencies_checked.end();){
			logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"looking for optional dependency in unique odep paths with path nr "+std::to_string(std::get<3>(j->second))
			+" and functor "+j->first.first
			+" d_key "+std::to_string(j->first.second)
			+" d_counter "+std::to_string(std::get<5>(j->second))
			+" parent node id "+std::get<0>(j->second)
			+" parent d_key "+std::to_string(std::get<1>(j->second))
			+" parent d_counter "+std::to_string(std::get<2>(j->second))
			+" odep level "+std::to_string(std::get<4>(j->second)));
			auto unique_optional_dependency_path=unique_optional_dependency_paths.find(std::get<3>(j->second));
			if(unique_optional_dependency_path==unique_optional_dependency_paths.end()){
				//if there are more than one optional dependency paths leading to the same real dependency,
				//keep only the first ones selected into unique_optional_dependency_paths, delete all others
				j=optional_dependencies_checked.erase(j);
				logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"deleting optional dependency: no unique optional dependency path found");
			}
			else if(std::get<4>(j->second)>std::get<3>(dependencies_found_via_optional_paths.find(*unique_optional_dependency_path)->second)){
				//Cut off optional dependencies checked out that stem from a real dependency but lead to no other real dependency
				//TODO: if there are more than one entries with the same path nr in dependencies_found_via_optional_paths
				//find the entry with the greatest odep level and carry out the comparison with that.
				//That will mean that the optional dependency being iterated over was inserted in its container AFTER
				//finding the last real dependency that was registered in dependencies_found_via_optional_paths.
				j=optional_dependencies_checked.erase(j);
				logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"deleting optional dependency: odep level in optional_dependencies_checked is greater for this functor than in dependencies_found_via_optional_paths");
			}
			else{
				logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"optional dependency path is unique: leave it as it is");
				++j;
			}
		}
		parent_node=node_dependency_traversal_stack.top();
		if(dependencies_found.empty()==false){
			logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"inserting dependencies found into dependency traversals of parent node id "+std::to_string(parent_node.first)+" with d_key "+std::to_string(parent_node.second));
			auto traversal_node_dependencies=node_dependency_traversals.find(parent_node);
			if(traversal_node_dependencies==node_dependency_traversals.end()){
				node_dependency_traversals.insert(std::make_pair(parent_node,dependencies_found));
			}
			else{
				traversal_node_dependencies->second.clear();
				traversal_node_dependencies->second.insert(dependencies_found.begin(),dependencies_found.end());
			}
		}
		else{
			logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"there are no dependencies found to insert into dependency traversals");
		}
		dependencies_found.clear();
		if(optional_dependencies_checked.empty()==false){
			logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"inserting optional dependencies checked into optional dependency traversals of parent node id "+std::to_string(parent_node.first)+" with d_key "+std::to_string(parent_node.second));
			auto traversal_node_odependencies=node_odependency_traversals.find(parent_node);
			if(traversal_node_odependencies==node_odependency_traversals.end()){
				node_odependency_traversals.insert(std::make_pair(parent_node,optional_dependencies_checked));
			}
			else{
				traversal_node_odependencies->second.clear();
				traversal_node_odependencies->second.insert(optional_dependencies_checked.begin(),optional_dependencies_checked.end());
			}
		}
		else{
			logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"there are no optional dependencies checked to insert into optional dependency traversals");
		}
		optional_dependencies_checked.clear();
		node_dependency_traversal_stack.pop();
		logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"popped dependency traversal stack");
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
	logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"next counter: "+next_counter);
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
		std::multimap<std::pair<std::string,unsigned int>,std::tuple<std::string,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int> >& optional_dependencies_checked,
		std::multimap<unsigned int,std::tuple<unsigned int,unsigned int,unsigned int,unsigned int> >& dependencies_found_via_optional_paths){
	const std::pair<const unsigned int,field> *depolex_entry=NULL;
	std::string semantic_dependency,ref_d_key,d_counter="0",manner,d_failover,d_successor;
	std::multimap<unsigned int,unsigned int>::const_iterator dependency_matrix_entry;
	std::map<unsigned int,unsigned int>::const_iterator j;
	t_map_of_node_ids_and_d_keys_to_nr_of_deps::iterator dependencies_found_entry;
	std::set<unsigned int> d_counter_validated_dependencies,d_key_validated_dependencies;
	bool dependency_found_for_functor=false,node_being_processed=false;
	std::stack<p_m1_node_id_m2_d_key> traversal_stack;

	const node_info& node=get_node_info(node_id);
    logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"checking dependency for functor "+node.expression.lexeme+" d_key "+d_key);
	if(node.expression.gcat=="CON"){
		depolex_entry=node.expression.dependencies->first_value_for_field_name_found("lexeme","CON");
//		Just copied here as a reminder once CON is allowed to have more than one d_key
//		while(depolex_entry!=NULL&&*node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"d_key")!=d_key){
//			depolex_entry=node.expression.dependencies->value_for_field_name_found_after_row_position(depolex_entry->first,"lexeme","CON");
//		}
	}
	else if(node.expression.lexicon_entry==false){
		depolex_entry=node.expression.dependencies->first_value_for_field_name_found("lexeme",node.expression.gcat);
		while(depolex_entry!=NULL&&*node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"d_key")!=d_key){
			depolex_entry=node.expression.dependencies->value_for_field_name_found_after_row_position(depolex_entry->first,"lexeme",node.expression.gcat);
		}
	}
	else{
		depolex_entry=node.expression.dependencies->first_value_for_field_name_found("lexeme",node.expression.lexeme);
		while(depolex_entry!=NULL&&*node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"d_key")!=d_key){
			depolex_entry=node.expression.dependencies->value_for_field_name_found_after_row_position(depolex_entry->first,"lexeme",node.expression.lexeme);
		}
	}
	if(depolex_entry==NULL){
		//throw exception as for each functor there must be one entry with at least NULL dependency
		throw std::runtime_error("Exiting, no dependency entry found for functor "+node.expression.lexeme+" in DEPOLEX db table.");
	}
	while(depolex_entry!=NULL&&*node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"d_key")==d_key){
		d_counter=*node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"d_counter");
		semantic_dependency=*node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"semantic_dependency");
		ref_d_key=*node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"ref_d_key");
		manner=*node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"manner");
		d_failover=*node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"d_failover");
		d_successor=*node.expression.dependencies->field_value_at_row_position(depolex_entry->first,"d_successor");
		logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"checking dependency entry "+semantic_dependency+" ref_d_key "+ref_d_key+" for functor "+node.expression.lexeme+" d_key "+d_key+" d_counter "+d_counter);
		if(semantic_dependency.empty()==false&&ref_d_key.empty()==false&&(manner.empty()==true||manner=="0"||manner=="1"||manner=="2")){
			logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"looking up depolex entry with row id "+std::to_string(depolex_entry->first)+" in dep.val.matrix");
			d_counter_validated_dependencies.clear();
			//Insert the corresponding entry into dependencies_found to indicate that the node id is already being checked
			dependencies_found.insert(std::make_pair(std::make_pair(node_id,std::atoi(d_key.c_str())),std::make_tuple(parent_node_id,0,0,std::atoi(parent_d_key.c_str()),parent_d_counter)));
            for(dependency_matrix_entry=node.dependency_validation_matrix.lower_bound(depolex_entry->first);
					dependency_matrix_entry!=node.dependency_validation_matrix.upper_bound(depolex_entry->first);
					++dependency_matrix_entry){
				logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"dvm entry row index:"+std::to_string(dependency_matrix_entry->first)+", dep.node id:"+std::to_string(dependency_matrix_entry->second));
				//If the row_id of the depolex_entry is found among the row_ids stored in the dep.vld.matrix
				//then the field values match as well since both row_ids refer to the corresponding
				//field in the node.expression.dependencies attribute.
				if(d_key_validated_dependencies.find(dependency_matrix_entry->second)==d_key_validated_dependencies.end()){
					d_counter_validated_dependencies.insert(dependency_matrix_entry->second);
					d_key_validated_dependencies.insert(dependency_matrix_entry->second);
					find_dependencies_for_functor(std::to_string(node_id),d_key,std::atoi(d_counter.c_str()),get_node_info(dependency_matrix_entry->second).node_id,ref_d_key,dependencies_found,optional_dependencies_checked,dependencies_found_via_optional_paths);
				}
			}
			if((manner.empty()==true||manner=="0")&&d_counter_validated_dependencies.size()==1
					||manner=="1"&&d_counter_validated_dependencies.size()>=1
					||manner=="2"&&d_counter_validated_dependencies.size()>1){
				logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"dependency "+semantic_dependency+" checked for functor "+node.expression.lexeme);
				dependency_found_for_functor=true;
			}
			else if((manner.empty()==true||manner=="0")&&d_counter_validated_dependencies.size()==0
					||manner=="1"&&d_counter_validated_dependencies.size()<1
					||manner=="2"&&d_counter_validated_dependencies.size()<=1){
				logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"dependency check for "+semantic_dependency+" returned FALSE for functor "+node.expression.lexeme+" with d_key "+d_key);
				if(std::atoi(d_failover.c_str())>=std::atoi(d_counter.c_str())){
					find_dependencies_for_functor(std::to_string(node_id),d_key,std::atoi(d_counter.c_str()),node_id,d_key,semantic_dependency,ref_d_key,dependencies_found,optional_dependencies_checked,dependencies_found_via_optional_paths);
				}
				dependency_found_for_functor=false;
			}
			else{
				throw dependency_counter_manner_validation_failed(node.expression.lexeme);
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
				if(dependencies_found_entry!=dependencies_found.end()){
					//No manner condition was fulfilled, don't increase the number of dependencies found
					//but increase the number of dependencies to be found
					if(d_failover.empty()==true||d_failover=="0"||std::atoi(d_failover.c_str())<std::atoi(d_counter.c_str())){
						if(manner.empty()==true||manner=="0"||manner=="1"){
							std::get<2>(dependencies_found_entry->second)+=1;
						}
						else if(manner=="2"){
							std::get<2>(dependencies_found_entry->second)+=2;
						}
					}
				}
				else{
					dependencies_found.insert(std::make_pair(std::make_pair(node_id,std::atoi(d_key.c_str())),std::make_tuple(parent_node_id,0,0,std::atoi(parent_d_key.c_str()),parent_d_counter)));
				}
			}
		}
		else if(semantic_dependency.empty()==true&&ref_d_key.empty()==true){
			//A leaf in the dependency tree is found so the semantic dependency is empty. As such, there's no
			//functor-dependency pair to be checked in the dep.vld.matrix so let's go on with the next dependency.
			logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"leaf dependency "+semantic_dependency+" checked for functor "+node.expression.lexeme+" and has no further dependency");
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
			throw std::runtime_error("Inconsistent setup of manner, semantic_dependency and ref_d_key for lexeme "+node.expression.lexeme+", d_key "+d_key+" and d_counter "+d_counter+" in DEPOLEX db table.");
		}
		if(node.expression.gcat=="CON"){
			depolex_entry=followup_dependency(depolex_entry->first,"CON",d_key,dependency_found_for_functor,*node.expression.dependencies);
		}
		else{
			depolex_entry=followup_dependency(depolex_entry->first,node.expression.lexeme,d_key,dependency_found_for_functor,*node.expression.dependencies);
		}
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
		std::multimap<std::pair<std::string,unsigned int>,std::tuple<std::string,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int> >& optional_dependencies_checked,
		std::multimap<unsigned int,std::tuple<unsigned int,unsigned int,unsigned int,unsigned int> >& dependencies_found_via_optional_paths){
	const std::pair<const unsigned int,field> *depolex_entry=NULL;
	std::string semantic_dependency,ref_d_key,d_counter="0",manner,d_failover,d_successor;
	std::multimap<unsigned int,unsigned int>::const_iterator dependency_matrix_entry;
	std::map<unsigned int,unsigned int>::const_iterator j;
	t_map_of_node_ids_and_d_keys_to_nr_of_deps::iterator dependencies_found_entry;
	std::set<unsigned int> d_counter_validated_dependencies,d_key_validated_dependencies,checked_d_counters;
	bool dependency_found_for_functor=false;
	unsigned int nr_of_skipped_opa_rules=0,nr_of_rules=0,path_nr=0,odep_level=0;

	const node_info& node=get_node_info(node_id);
    logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"checking dependency for optional functor "+functor+" d_key "+d_key);
	depolex_entry=node.expression.dependencies->first_value_for_field_name_found("lexeme",functor);
	if(depolex_entry==NULL){
		//throw exception as for each functor there must be one entry with at least NULL dependency
		throw std::runtime_error("Exiting, no dependency entry found for functor "+functor+" in DEPOLEX db table.");
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
			logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"checking dependency entry "+semantic_dependency+" ref_d_key "+ref_d_key+" for functor "+functor+" d_key "+d_key+" d_counter "+d_counter);
			if(semantic_dependency.empty()==false&&ref_d_key.empty()==false&&(manner.empty()==true||manner=="0"||manner=="1"||manner=="2")){
				logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"looking up depolex entry with row id "+std::to_string(depolex_entry->first)+" in dep.val.matrix");
				d_counter_validated_dependencies.clear();
				//Insert the corresponding entry into optional_dependencies_checked to indicate that the node id is already being checked
				if(dependencies_found_via_optional_paths.empty()==true) path_nr=1;
				else path_nr=dependencies_found_via_optional_paths.rbegin()->first+1;
				odep_level=optional_dependencies_checked.size()+1;
				optional_dependencies_checked.insert(std::make_pair(std::make_pair(functor,std::atoi(d_key.c_str())),std::make_tuple(parent_node_id,std::atoi(parent_d_key.c_str()),parent_d_counter,path_nr,odep_level,std::atoi(d_counter.c_str()))));
				logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"optional dependency level:"+std::to_string(odep_level)+"path_nr:"+std::to_string(path_nr));
				for(dependency_matrix_entry=node.dependency_validation_matrix.lower_bound(depolex_entry->first);
					dependency_matrix_entry!=node.dependency_validation_matrix.upper_bound(depolex_entry->first);
					++dependency_matrix_entry){
					//If the row_id of the depolex_entry is found among the row_ids stored in the dep.vld.matrix
					//then the field values match as well since both row_ids refer to the corresponding
					//field in the node.expression.dependencies attribute.
					if(d_key_validated_dependencies.find(dependency_matrix_entry->second)==d_key_validated_dependencies.end()){
						d_counter_validated_dependencies.insert(dependency_matrix_entry->second);
						d_key_validated_dependencies.insert(dependency_matrix_entry->second);
						find_dependencies_for_functor(functor,d_key,std::atoi(d_counter.c_str()),get_node_info(dependency_matrix_entry->second).node_id,ref_d_key,dependencies_found,optional_dependencies_checked,dependencies_found_via_optional_paths);
					}
				}
				if((manner.empty()==true||manner=="0")&&d_counter_validated_dependencies.size()==1
						||manner=="1"&&d_counter_validated_dependencies.size()>=1
						||manner=="2"&&d_counter_validated_dependencies.size()>1){
					logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"dependency "+semantic_dependency+" checked for functor "+functor);
					dependency_found_for_functor=true;
				}
				else if((manner.empty()==true||manner=="0")&&d_counter_validated_dependencies.size()==0
						||manner=="1"&&d_counter_validated_dependencies.size()<1
						||manner=="2"&&d_counter_validated_dependencies.size()<=1){
					logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"dependency check for "+semantic_dependency+" returned FALSE for functor "+functor+" with d_key "+d_key);
					if((std::atoi(d_failover.c_str())>=std::atoi(d_counter.c_str()))){
						find_dependencies_for_functor(functor,d_key,std::atoi(d_counter.c_str()),node_id,node_d_key,semantic_dependency,ref_d_key,dependencies_found,optional_dependencies_checked,dependencies_found_via_optional_paths);
					}
					dependency_found_for_functor=false;
				}
				else{
					throw dependency_counter_manner_validation_failed(functor);
				}
				dependencies_found_entry=dependencies_found.find(std::make_pair(node_id,std::atoi(node_d_key.c_str())));
				if(dependency_found_for_functor==true){
					unsigned int nr_of_deps_to_add=0;
					if(dependencies_found_entry!=dependencies_found.end()){
						//shall path_nr be recalculated here or the previously calculated value should be used?
						if(dependencies_found_via_optional_paths.empty()==true) path_nr=1;
						else path_nr=dependencies_found_via_optional_paths.rbegin()->first+1;
						for(auto&& i:d_counter_validated_dependencies){
							bool dependency_already_found_for_node_id=false;
							for(auto&& j:dependencies_found_via_optional_paths){
								if(std::get<0>(j.second)==node_id
									&&std::get<1>(j.second)==std::atoi(node_d_key.c_str())
									&&std::get<2>(j.second)==i){
									dependency_already_found_for_node_id=true;
									break;
								}
							}
							if(dependency_already_found_for_node_id==false){
								logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"register dependency "+semantic_dependency+" for functor "+get_node_info(node_id).expression.lexeme+" node_id "+std::to_string(node_id)+" with optional functor "+functor
								+"optional dependency level:"+std::to_string(odep_level));
								dependencies_found_via_optional_paths.insert(std::make_pair(path_nr,std::make_tuple(node_id,std::atoi(node_d_key.c_str()),i,odep_level)));
								++nr_of_deps_to_add;
							}
						}
						if(nr_of_deps_to_add>0){
							std::get<2>(dependencies_found_entry->second)+=nr_of_deps_to_add;
							if(std::atoi(d_successor.c_str())==0||std::atoi(d_successor.c_str())>std::atoi(d_counter.c_str())){
								std::get<1>(dependencies_found_entry->second)+=nr_of_deps_to_add;
							}
							else{
								//Don't increase counter for found dependencies: this indicates a deliberate error on the success branch
							}
						}
					}
					else{
						//shall path_nr be recalculated here or the previously calculated value should be used?
						if(dependencies_found_via_optional_paths.empty()==true) path_nr=1;
						else path_nr=dependencies_found_via_optional_paths.rbegin()->first+1;
						for(auto&& i:d_counter_validated_dependencies){
							bool dependency_already_found_for_node_id=false;
							for(auto&& j:dependencies_found_via_optional_paths){
								if(std::get<0>(j.second)==node_id
									&&std::get<1>(j.second)==std::atoi(node_d_key.c_str())
									&&std::get<2>(j.second)==i){
									dependency_already_found_for_node_id=true;
									break;
								}
							}
							if(dependency_already_found_for_node_id==false){
								logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"register dependency "+semantic_dependency+" for functor "+get_node_info(node_id).expression.lexeme+" node_id "+std::to_string(node_id)+" with optional functor "+functor
								+"optional dependency level:"+std::to_string(odep_level));
								dependencies_found_via_optional_paths.insert(std::make_pair(path_nr,std::make_tuple(node_id,std::atoi(node_d_key.c_str()),i,odep_level)));
								++nr_of_deps_to_add;
							}
						}
						if(nr_of_deps_to_add>0){
							dependencies_found.insert(std::make_pair(std::make_pair(node_id,std::atoi(node_d_key.c_str())),std::make_tuple(parent_node_id,nr_of_deps_to_add,nr_of_deps_to_add,std::atoi(parent_d_key.c_str()),parent_d_counter)));
						}
					}
				}
				else{//Don't increase dependencies_found_entry.second.second i.e. the counter for expected dependencies to be found as nothing is expected to be found for an optional dependency
					if(dependencies_found_entry!=dependencies_found.end()){
						//No manner condition was fulfilled, nothing to add
					}
					else{
						dependencies_found.insert(std::make_pair(std::make_pair(node_id,std::atoi(node_d_key.c_str())),std::make_tuple(std::string(),0,0,0,0)));
					}
				}
				if(dependencies_found_via_optional_paths.empty()==true||path_nr>dependencies_found_via_optional_paths.rbegin()->first){
					//If no real dependency was found on the path branching from this optional dependency,
					//delete this optional dependency from the list of odeps that are part of a path
					//that leads to a real dependency.
					for(auto&& i=optional_dependencies_checked.lower_bound(std::make_pair(functor,std::atoi(d_key.c_str())));
							i!=optional_dependencies_checked.upper_bound(std::make_pair(functor,std::atoi(d_key.c_str())));){
						if(std::get<4>(i->second)==odep_level){
							logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"deleting optional dependency with functor "+i->first.first+" and d_key "+std::to_string(i->first.second));
							i=optional_dependencies_checked.erase(i);
						}
						else{
							++i;
						}
					}
				}
			}
			else if(semantic_dependency.empty()==true&&ref_d_key.empty()==true){
				//A leaf in the dependency tree is found so the semantic dependency is empty. As such, there's no
				//functor-dependency pair to be checked in the dep.vld.matrix so let's go on with the next dependency.
				logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"leaf dependency "+semantic_dependency+" checked for functor "+functor+" and has no further dependency");
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
				throw std::runtime_error("Inconsistent setup of manner, semantic_dependency and ref_d_key for lexeme "+functor+", d_key "+d_key+" and d_counter "+d_counter+" in DEPOLEX db table.");
			}
		}
		else{
			++nr_of_skipped_opa_rules;
		}
		depolex_entry=followup_dependency(depolex_entry->first,functor,d_key,dependency_found_for_functor,*node.expression.dependencies);
	}
	if(nr_of_rules>0&&nr_of_rules==nr_of_skipped_opa_rules){
		logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"dependency "+semantic_dependency+" checked for functor "+functor+" but has no further dependency");
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

	sqlite=db_factory::get_instance();
	gcats=sqlite->exec_sql("SELECT DISTINCT GCAT FROM GCAT;");
	if(gcats==NULL){
		throw std::runtime_error("GCAT db table is empty.");
	}
	for(auto&& i:node_infos){
		if(i.expression.lexeme.empty()==false&&i.ref_node_ids.empty()==true&&gcats->first_value_for_field_name_found("gcat",i.expression.gcat)!=NULL){
			++nr_of_non_ref_leafs;
			logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"Dependency to be found:"+i.expression.lexeme);
		}
	}
	return nr_of_non_ref_leafs;
}

transgraph* interpreter::longest_match_for_semantic_rules_found(){
	t_map_of_node_ids_and_d_keys_to_nr_of_deps dependencies_found;
	std::multimap<std::pair<std::string,unsigned int>,std::tuple<std::string,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int> > optional_dependencies_checked;
	std::vector<unsigned int> verbs_found;
	std::map<unsigned int,std::pair<unsigned int,unsigned int> > map_of_node_ids_to_total_nr_of_deps_and_d_key;
	std::map<unsigned int,std::pair<unsigned int,unsigned int> >::iterator node_id_with_longest_match_and_d_key;
	std::set<unsigned int> nodes_to_be_validated;
	unsigned int nr_of_dependencies_found=0,total_nr_of_dependencies=0,d_key=0,min_nr_of_deps=0;
	t_node_dependency_traversal *node_dependency_traversal=NULL;
	t_pair_of_node_id_and_d_key_with_nr_of_deps *node_id_and_d_key_with_nr_of_deps=NULL;
	std::pair<p_m1_node_id_m2_d_key,t_m0_parent_node_m1_nr_of_deps_m2_nr_of_deps_to_find_m3_parent_dkey_m4_parent_dcounter> functor_found;
	std::map<p_m1_node_id_m2_d_key,std::pair<t_m0_parent_node_m1_nr_of_deps_m2_nr_of_deps_to_find_m3_parent_dkey_m4_parent_dcounter,std::map<unsigned int,std::pair<t_m0_parent_node_m1_nr_of_deps_m2_nr_of_deps_to_find_m3_parent_dkey_m4_parent_dcounter,unsigned int> > > > longest_traversals;
    db *sqlite=NULL;
    query_result *result=NULL;

	//TODO: add an entry in the symbols table for the symbol main_verb
	//and think over how to make it customizable for different languages
    sqlite=db_factory::get_instance();
    result=sqlite->exec_sql("SELECT * FROM SETTINGS WHERE key='main_symbol';");
    if(result==NULL) throw std::runtime_error("No main symbol is set up in settings table.");
    std::string main_symbol=*result->field_value_at_row_position(0,"value");
    const node_info& root_node=get_node_info(nr_of_nodes_);
    get_nodes_by_symbol(root_node,main_symbol,std::string(),verbs_found);
	if(verbs_found.size()==1){
		const node_info& node=get_node_info(*verbs_found.begin());
        find_dependencies_for_node(node.node_id,dependencies_found,optional_dependencies_checked);
		functor_found=calculate_longest_matching_dependency_route(longest_traversals);
		d_key=functor_found.first.second;
		//TODO: min nr of deps is shown differently here than in calculate_longest_matching_dependency_route
		//in case of e.g. the first dependency is not found as in "list peter" instead of "list contacts" on android
		min_nr_of_deps=std::get<2>(functor_found.second);
		logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"Minimum number of dependencies to match:"+std::to_string(min_nr_of_deps));
		nr_of_dependencies_found=std::get<1>(functor_found.second);
		logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"Matching nr of dependencies found for functor "+node.expression.lexeme+" with d_key "+std::to_string(d_key)+":"+std::to_string(nr_of_dependencies_found));
		total_nr_of_dependencies=nr_of_dependencies_to_be_found()-1;
		logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"Total number of dependencies:"+std::to_string(total_nr_of_dependencies));
		if(nr_of_dependencies_found>=min_nr_of_deps){
			//The original condition if(nr_of_dependencies_found==total_nr_of_dependencies&&nr_of_dependencies_found>=min_nr_of_deps)
			//seems to be too strict as it requires that all dependencies need to be found.
			//Made it looser due to enabling partial analysis to experiment with this condition and see if it fits the bill.
			if(nr_of_dependencies_found!=total_nr_of_dependencies||nr_of_dependencies_found<min_nr_of_deps)
				logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"Not all dependencies have been found for functor "+node.expression.lexeme);
			return build_transgraph(functor_found.first,std::make_pair(std::to_string(functor_found.first.first),functor_found.first.second),longest_traversals);
		}
		else{
			logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"No matching nr of dependencies found for functor "+node.expression.lexeme+" with any d_key");
			return NULL;
		}
	}
	else{
		if(verbs_found.size()==0)
            throw std::runtime_error("No main verb found.");
		else
			throw std::runtime_error("More than one main verb found.");
	}
}

std::pair<p_m1_node_id_m2_d_key,t_m0_parent_node_m1_nr_of_deps_m2_nr_of_deps_to_find_m3_parent_dkey_m4_parent_dcounter> interpreter::calculate_longest_matching_dependency_route(std::map<p_m1_node_id_m2_d_key,std::pair<t_m0_parent_node_m1_nr_of_deps_m2_nr_of_deps_to_find_m3_parent_dkey_m4_parent_dcounter,std::map<unsigned int,std::pair<t_m0_parent_node_m1_nr_of_deps_m2_nr_of_deps_to_find_m3_parent_dkey_m4_parent_dcounter,unsigned int> > > >& longest_traversals){
	unsigned int node_level=1;
	t_m0_parent_node_m1_nr_of_deps_m2_nr_of_deps_to_find_m3_parent_dkey_m4_parent_dcounter nr_of_deps;
	p_m1_node_id_m2_d_key functor_node;
	std::pair<p_m1_node_id_m2_d_key,t_m0_parent_node_m1_nr_of_deps_m2_nr_of_deps_to_find_m3_parent_dkey_m4_parent_dcounter> functor_found;
	std::map<unsigned int,std::pair<t_m0_parent_node_m1_nr_of_deps_m2_nr_of_deps_to_find_m3_parent_dkey_m4_parent_dcounter,unsigned int> > map_of_node_ids_to_total_nr_of_deps_and_d_key;

	for(auto&& i:node_dependency_traversal_stack_tree){
		logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"tree level: "+std::to_string(i.first.first));
		if(i.first.first==node_level){
			std::get<1>(nr_of_deps)=0;
			std::get<2>(nr_of_deps)=0;
			functor_node=i.first.second;
			map_of_node_ids_to_total_nr_of_deps_and_d_key.clear();
			calculate_longest_matching_dependency_route(node_level,functor_node,map_of_node_ids_to_total_nr_of_deps_and_d_key);
			logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"dependencies with longest match:");
			for(auto&& i:map_of_node_ids_to_total_nr_of_deps_and_d_key){
				logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"functor "+get_node_info(i.first).expression.lexeme+" d_key "+std::to_string(i.second.second)+": "+std::to_string(std::get<1>(i.second.first))+" deps found out of the expected "+std::to_string(std::get<2>(i.second.first))+" deps to be found");
				std::get<1>(nr_of_deps)+=std::get<1>(i.second.first);
				std::get<2>(nr_of_deps)+=std::get<2>(i.second.first);
			}
			longest_traversals.insert(std::make_pair(functor_node,std::make_pair(nr_of_deps,map_of_node_ids_to_total_nr_of_deps_and_d_key)));
		}
	}
	std::get<1>(functor_found.second)=0;
	std::get<2>(functor_found.second)=0;
	functor_found.first.first=0;
	functor_found.first.second=0;
	for(auto&& i:longest_traversals){
	//TODO: two interpretations with the same number of deps must not be allowed.
	//The only exception is when the scripts behind the functors are the same.
	//This logic is missing though here.
		if(functor_found.first.first==0&&functor_found.first.second==0||std::get<1>(i.second.first)>std::get<1>(functor_found.second)){
			functor_found.first=i.first;
			functor_found.second=i.second.first;
		}
	}
	return functor_found;
}

void interpreter::calculate_longest_matching_dependency_route(const unsigned int node_level, const p_m1_node_id_m2_d_key& functor_node,
		std::map<unsigned int,std::pair<t_m0_parent_node_m1_nr_of_deps_m2_nr_of_deps_to_find_m3_parent_dkey_m4_parent_dcounter,unsigned int> >& map_of_node_ids_to_total_nr_of_deps_and_d_key){
	p_m1_tree_level_m2_p_m1_node_id_m2_d_key tree_level_and_functor_node;
	std::map<p_m1_tree_level_m2_p_m1_node_id_m2_d_key,std::vector<p_m1_node_id_m2_d_key> >::const_iterator functor_node_found;
	std::map<unsigned int,std::pair<t_m0_parent_node_m1_nr_of_deps_m2_nr_of_deps_to_find_m3_parent_dkey_m4_parent_dcounter,unsigned int> >::iterator node_id_with_longest_match_and_d_key;
	std::set<unsigned int> nodes_to_be_validated;
	t_node_dependency_traversals::const_iterator functor_node_dependencies;
	t_node_dependency_traversal *node_dependency_traversal=NULL;
	t_pair_of_node_id_and_d_key_with_nr_of_deps *node_id_and_d_key_with_nr_of_deps=NULL;

	tree_level_and_functor_node.first=node_level;
	tree_level_and_functor_node.second=functor_node;
	functor_node_found=node_dependency_traversal_stack_tree.find(tree_level_and_functor_node);
	if(functor_node_found==node_dependency_traversal_stack_tree.end()){
		throw std::runtime_error("Functor node not found in node dependency traversal stack tree.");
	}
	functor_node_dependencies=node_dependency_traversals.find(functor_node);
	if(functor_node_dependencies==node_dependency_traversals.end()){
		throw std::runtime_error("Functor node dependencies not found in node dependency traversals.");
	}
	//1) loop over functor_node_dependencies.map_of_node_ids_and_d_keys_to_nr_of_deps to get the longest matching deps and sum them up
	node_dependency_traversal=new t_node_dependency_traversal(functor_node_dependencies);
	for(t_map_of_node_ids_and_d_keys_to_nr_of_deps::const_iterator i=node_dependency_traversal->map_of_node_ids_and_d_keys_to_nr_of_deps.begin();
			i!=node_dependency_traversal->map_of_node_ids_and_d_keys_to_nr_of_deps.end();++i){
		node_id_and_d_key_with_nr_of_deps=new t_pair_of_node_id_and_d_key_with_nr_of_deps(i);
		//TODO1a: think over if a local, initially empty map_of_node_ids_to_total_nr_of_deps_and_d_key shall be used
		//in the loop and before returning, the result of it shall be merged with the content of the incoming one.
		if(map_of_node_ids_to_total_nr_of_deps_and_d_key.find(node_id_and_d_key_with_nr_of_deps->node_id_and_d_key.first)==map_of_node_ids_to_total_nr_of_deps_and_d_key.end()
			&&nodes_to_be_validated.find(node_id_and_d_key_with_nr_of_deps->node_id_and_d_key.first)==nodes_to_be_validated.end()){
			nodes_to_be_validated.insert(node_id_and_d_key_with_nr_of_deps->node_id_and_d_key.first);
		}
		logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"for node id "+std::to_string(node_id_and_d_key_with_nr_of_deps->node_id_and_d_key.first)+" with functor "+get_node_info(node_id_and_d_key_with_nr_of_deps->node_id_and_d_key.first).expression.lexeme
		+" and d_key "+std::to_string(node_id_and_d_key_with_nr_of_deps->node_id_and_d_key.second)+" the nr_of_dependencies_found is: "+std::to_string(std::get<1>(node_id_and_d_key_with_nr_of_deps->nr_of_deps)));
		node_id_with_longest_match_and_d_key=map_of_node_ids_to_total_nr_of_deps_and_d_key.find(node_id_and_d_key_with_nr_of_deps->node_id_and_d_key.first);
		if(node_id_with_longest_match_and_d_key!=map_of_node_ids_to_total_nr_of_deps_and_d_key.end()){
			if(std::get<1>(node_id_with_longest_match_and_d_key->second.first)<std::get<1>(node_id_and_d_key_with_nr_of_deps->nr_of_deps)){
				node_id_with_longest_match_and_d_key->second.first=node_id_and_d_key_with_nr_of_deps->nr_of_deps;
				node_id_with_longest_match_and_d_key->second.second=node_id_and_d_key_with_nr_of_deps->node_id_and_d_key.second;
			}
			else if(std::get<1>(node_id_with_longest_match_and_d_key->second.first)>0&&std::get<1>(node_id_with_longest_match_and_d_key->second.first)==std::get<1>(node_id_and_d_key_with_nr_of_deps->nr_of_deps)){
				throw std::runtime_error("Ambiguous interpretations found. Sorry, can't handle that yet.");
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
	if(nodes_to_be_validated.empty()==false){
		throw std::runtime_error("Sanity check failed for having all nodes to be validated processed.");
	}
	//2) loop over functor_node_found.second (vector of children) and call recursively for each the method itself
	for(auto&& i:functor_node_found->second){
		//TODO1b: (corollary of TODO1a) think over if the local or the incoming
		//map_of_node_ids_to_total_nr_of_deps_and_d_key shall be passed over here
		calculate_longest_matching_dependency_route(node_level+1,i,map_of_node_ids_to_total_nr_of_deps_and_d_key);
	}
}

unsigned int interpreter::is_valid_combination(const std::string& symbol, const node_info& new_phrase_head_root, const node_info& new_phrase_non_head_root){
	bool valid_combination=false;
	db *sqlite=NULL;
	query_result *rule_to_rule_map=NULL;
	std::multimap<std::pair<std::string,std::string>,std::pair<unsigned int,std::string> > *functors_found=NULL;
	std::multimap<unsigned int,unsigned int>::const_iterator l;
	std::vector<unsigned int>::const_iterator j,k;
	std::vector<unsigned int> main_nodes_found_by_symbol,dependent_nodes_found_by_symbol,main_subtree_nodes_found_by_symbol,dependency_subtree_nodes_found_by_symbol,prev_main_nodes_found_by_symbol,prev_dependent_nodes_found_by_symbol;
	const std::pair<const unsigned int,field> *rule_entry=NULL,*rule_entry_failure_copy=NULL;
	unsigned int current_step=0,successor=0,failover=0,main_node_id=0,dep_node_id=0,rule_step_failed=0,main_set_op=0,dependent_set_op=0;
	std::multimap<unsigned int,std::pair<unsigned int,unsigned int> > functors_validated_for_nodes;
	node_info *main_node=NULL,*dependent_node=NULL;
	std::multimap<unsigned int,unsigned int> ref_node_ids_to_set;
	std::set<unsigned int>::const_iterator main_ref_node_id,dep_ref_node_id;
	std::string main_node_symbol,dependent_node_symbol,prev_main_node_symbol,prev_dependent_node_symbol;

	sqlite=db_factory::get_instance();
	rule_to_rule_map=sqlite->exec_sql("SELECT * FROM RULE_TO_RULE_MAP WHERE PARENT_SYMBOL = '"+symbol+"' AND HEAD_ROOT_SYMBOL = '"+new_phrase_head_root.symbol+"' AND NON_HEAD_ROOT_SYMBOL = '"+new_phrase_non_head_root.symbol+"' ORDER BY STEP;");
	if(rule_to_rule_map==NULL){
		throw std::runtime_error("No entries found for parent symbol "+symbol+", head root symbol "+new_phrase_head_root.symbol+" and non-head root symbol "+new_phrase_non_head_root.symbol+" in RULE_TO_RULE_MAP db table.");
	}
	rule_entry=rule_to_rule_map->first_value_for_field_name_found("step","1");
	while(rule_entry!=NULL){
		valid_combination=false;
		rule_entry_failure_copy=rule_entry;
		prev_main_node_symbol=main_node_symbol;
		prev_dependent_node_symbol=dependent_node_symbol;
		main_node_symbol=*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"main_node_symbol");
		dependent_node_symbol=*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"dependent_node_symbol");
		current_step=std::atoi(rule_to_rule_map->field_value_at_row_position(rule_entry->first,"step")->c_str());
		failover=std::atoi(rule_to_rule_map->field_value_at_row_position(rule_entry->first,"failover")->c_str());
		successor=std::atoi(rule_to_rule_map->field_value_at_row_position(rule_entry->first,"successor")->c_str());
		logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"step:"+std::to_string(current_step)+" failover:"+std::to_string(failover)+" successor:"+std::to_string(successor));
		std::string head_root_symbol=*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"head_root_symbol");
		std::string non_head_root_symbol=*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"non_head_root_symbol");
		std::string main_lookup_root=*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"main_lookup_root");
		std::string main_lookup_subtree_symbol=*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"main_lookup_subtree_symbol");
		std::string main_node_lexeme=*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"main_node_lexeme");
		std::string dependency_lookup_root=*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"dependency_lookup_root");
		std::string dependency_lookup_subtree_symbol=*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"dependency_lookup_subtree_symbol");
		std::string dependent_node_lexeme=*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"dependent_node_lexeme");

		main_set_op=std::atoi(rule_to_rule_map->field_value_at_row_position(rule_entry->first,"main_set_op")->c_str());
		dependent_set_op=std::atoi(rule_to_rule_map->field_value_at_row_position(rule_entry->first,"dependent_set_op")->c_str());
		if(current_step>1&&main_set_op>0&&main_node_symbol.empty()==false&&main_node_symbol==prev_main_node_symbol&&main_nodes_found_by_symbol.empty()==false){
			prev_main_nodes_found_by_symbol=main_nodes_found_by_symbol;
		}
		else prev_main_nodes_found_by_symbol.clear();
		main_nodes_found_by_symbol.clear();
		if(current_step>1&&dependent_set_op>0&&dependent_node_symbol.empty()==false&&dependent_node_symbol==prev_dependent_node_symbol&&dependent_nodes_found_by_symbol.empty()==false){
			prev_dependent_nodes_found_by_symbol=dependent_nodes_found_by_symbol;
		}
		else prev_dependent_nodes_found_by_symbol.clear();
		dependent_nodes_found_by_symbol.clear();
		main_subtree_nodes_found_by_symbol.clear();
		dependency_subtree_nodes_found_by_symbol.clear();
		if(head_root_symbol==new_phrase_head_root.symbol&&non_head_root_symbol==new_phrase_non_head_root.symbol){
			if(main_node_symbol.empty()==false){
				if(main_lookup_root=="H"){
					if(main_lookup_subtree_symbol.empty()==true)
						get_nodes_by_symbol(new_phrase_head_root,main_node_symbol,main_node_lexeme,main_nodes_found_by_symbol);
					else{
						get_nodes_by_symbol(new_phrase_head_root,main_lookup_subtree_symbol,std::string(),main_subtree_nodes_found_by_symbol);
						for(auto&& main_subtree_node:main_subtree_nodes_found_by_symbol){
							get_nodes_by_symbol(get_node_info(main_subtree_node),main_node_symbol,main_node_lexeme,main_nodes_found_by_symbol);
						}
					}
				}
				else if(main_lookup_root=="N"){
					if(main_lookup_subtree_symbol.empty()==true)
						get_nodes_by_symbol(new_phrase_non_head_root,main_node_symbol,main_node_lexeme,main_nodes_found_by_symbol);
					else{
						get_nodes_by_symbol(new_phrase_non_head_root,main_lookup_subtree_symbol,std::string(),main_subtree_nodes_found_by_symbol);
						for(auto&& main_subtree_node:main_subtree_nodes_found_by_symbol){
							get_nodes_by_symbol(get_node_info(main_subtree_node),main_node_symbol,main_node_lexeme,main_nodes_found_by_symbol);
						}
					}
				}
				else{
					if(main_lookup_subtree_symbol.empty()==true){
						get_nodes_by_symbol(new_phrase_head_root,main_node_symbol,main_node_lexeme,main_nodes_found_by_symbol);
						get_nodes_by_symbol(new_phrase_non_head_root,main_node_symbol,main_node_lexeme,main_nodes_found_by_symbol);
					}
					else{
						get_nodes_by_symbol(new_phrase_head_root,main_lookup_subtree_symbol,std::string(),main_subtree_nodes_found_by_symbol);
						get_nodes_by_symbol(new_phrase_non_head_root,main_lookup_subtree_symbol,std::string(),main_subtree_nodes_found_by_symbol);
						for(auto&& main_subtree_node:main_subtree_nodes_found_by_symbol){
							get_nodes_by_symbol(get_node_info(main_subtree_node),main_node_symbol,main_node_lexeme,main_nodes_found_by_symbol);
						}
					}
				}
			}
			if(dependent_node_symbol.empty()==false){
				if(dependency_lookup_root=="H"){
					if(dependency_lookup_subtree_symbol.empty()==true)
						get_nodes_by_symbol(new_phrase_head_root,dependent_node_symbol,dependent_node_lexeme,dependent_nodes_found_by_symbol);
					else{
						get_nodes_by_symbol(new_phrase_head_root,dependency_lookup_subtree_symbol,std::string(),dependency_subtree_nodes_found_by_symbol);
						for(auto&& dependency_subtree_node:dependency_subtree_nodes_found_by_symbol){
							get_nodes_by_symbol(get_node_info(dependency_subtree_node),dependent_node_symbol,dependent_node_lexeme,dependent_nodes_found_by_symbol);
						}
					}
				}
				else if(dependency_lookup_root=="N"){
					if(dependency_lookup_subtree_symbol.empty()==true)
						get_nodes_by_symbol(new_phrase_non_head_root,dependent_node_symbol,dependent_node_lexeme,dependent_nodes_found_by_symbol);
					else{
						get_nodes_by_symbol(new_phrase_non_head_root,dependency_lookup_subtree_symbol,std::string(),dependency_subtree_nodes_found_by_symbol);
						for(auto&& dependency_subtree_node:dependency_subtree_nodes_found_by_symbol){
							get_nodes_by_symbol(get_node_info(dependency_subtree_node),dependent_node_symbol,dependent_node_lexeme,dependent_nodes_found_by_symbol);
						}
					}
				}
				else{
					if(dependency_lookup_subtree_symbol.empty()==true){
						get_nodes_by_symbol(new_phrase_head_root,dependent_node_symbol,dependent_node_lexeme,dependent_nodes_found_by_symbol);
						get_nodes_by_symbol(new_phrase_non_head_root,dependent_node_symbol,dependent_node_lexeme,dependent_nodes_found_by_symbol);
					}
					else{
						get_nodes_by_symbol(new_phrase_head_root,dependency_lookup_subtree_symbol,std::string(),dependency_subtree_nodes_found_by_symbol);
						get_nodes_by_symbol(new_phrase_non_head_root,dependency_lookup_subtree_symbol,std::string(),dependency_subtree_nodes_found_by_symbol);
						for(auto&& dependency_subtree_node:dependency_subtree_nodes_found_by_symbol){
							get_nodes_by_symbol(get_node_info(dependency_subtree_node),dependent_node_symbol,dependent_node_lexeme,dependent_nodes_found_by_symbol);
						}
					}
				}
			}
			if(main_set_op>0){
				combine_sets(main_set_op,prev_main_nodes_found_by_symbol,main_nodes_found_by_symbol);
			}
			if(dependent_set_op>0){
				combine_sets(dependent_set_op,prev_dependent_nodes_found_by_symbol,dependent_nodes_found_by_symbol);
			}
			if(main_node_symbol.empty()==false
				&&dependent_node_symbol.empty()==false
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
					logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"loop pass on main_nodes_found_by_symbol:"+std::to_string(*j));
					main_node=&get_private_node_info(*j);
					logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"main node lexeme:"+main_node->expression.lexeme);
					if(main_node->ref_node_ids.empty()==true) main_node_id=main_node->node_id;
					else{
						main_ref_node_id=main_node->ref_node_ids.begin();
						main_node_id=*main_ref_node_id;
					}
					while(main_node_id!=0){
						node_info *main_or_ref_node=&get_private_node_info(main_node_id);
						logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"main node refnode lexeme:"+main_or_ref_node->expression.lexeme);
						//2)Loop over dependent_nodes_found_by_symbol where dependent_node is NOT in current_main_node.node_links
						for(k=dependent_nodes_found_by_symbol.begin();k!=dependent_nodes_found_by_symbol.end();++k){
							logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"loop pass on dependent_nodes_found_by_symbol:"+std::to_string(*k));
							dependent_node=&get_private_node_info(*k);
							logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"dependent node lexeme:"+dependent_node->expression.lexeme);
							if(dependent_node->ref_node_ids.empty()==true) dep_node_id=dependent_node->node_id;
							else{
								dep_ref_node_id=dependent_node->ref_node_ids.begin();
								dep_node_id=*dep_ref_node_id;
							}
							while(dep_node_id!=0){
								node_info *dependent_or_ref_node=&get_private_node_info(dep_node_id);
								logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"dependent node refnode lexeme:"+dependent_or_ref_node->expression.lexeme);
								for(l=main_or_ref_node->dependency_validation_matrix.begin();l!=main_or_ref_node->dependency_validation_matrix.end();++l){
									//TODO:Consider if this logic is ok:
									//If a node is already registered in the main nodes's dvm for a dependency,
									//don't give a chance to register it for another dependency as well.
									if(l->second==dependent_or_ref_node->node_id) break;
								}
								if(l==main_or_ref_node->dependency_validation_matrix.end()){
									if(dependent_or_ref_node->expression.morphalytics!=NULL&&dependent_or_ref_node->expression.morphalytics->is_mocked()==false
										&&dependent_or_ref_node->expression.morphalytics->has_feature("Relative")==true){
										ref_node_ids_to_set.insert(std::make_pair(dependent_or_ref_node->node_id,main_or_ref_node->node_id));
										valid_combination=true;
									}
									else{
										functors_found=is_valid_expression(*main_or_ref_node,*dependent_or_ref_node);
										if(functors_found!=NULL){
											valid_combination=true;
											for(auto&& m:*functors_found){
												functors_validated_for_nodes.insert(std::make_pair(main_or_ref_node->node_id,std::make_pair(m.second.first,dependent_or_ref_node->node_id)));
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
			else if(main_node_symbol.empty()==false
					&&main_nodes_found_by_symbol.empty()==false
					&&dependent_node_symbol.empty()==true
					&&dependent_nodes_found_by_symbol.empty()==true
					||main_node_symbol.empty()==true
					&&main_nodes_found_by_symbol.empty()==true
					&&dependent_node_symbol.empty()==false
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
			else if(main_node_symbol.empty()==false
					&&main_nodes_found_by_symbol.empty()==true
					&&dependent_node_symbol.empty()==true
					&&dependent_nodes_found_by_symbol.empty()==true
					||main_node_symbol.empty()==true
					&&main_nodes_found_by_symbol.empty()==true
					&&dependent_node_symbol.empty()==false
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
			else if(main_node_symbol.empty()==false
				&&dependent_node_symbol.empty()==false
				&&(main_nodes_found_by_symbol.empty()==true||dependent_nodes_found_by_symbol.empty()==true)){
					valid_combination=false;
			}
			else{
				throw std::runtime_error("Either got empty main and/or dependent node symbol and/or if not empty then no nodes found for them to validate their combination.");
			}
			if(valid_combination==true){
				if(successor>current_step){
					rule_entry=rule_to_rule_map->value_for_field_name_found_after_row_position(rule_entry->first,"step",*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"successor"));
				}
				else if(successor!=0&&successor<=current_step){
					throw std::runtime_error("You have a successor branch loop for parent symbol "+symbol+", head root symbol "+new_phrase_head_root.symbol+" and non-head root symbol "+new_phrase_non_head_root.symbol+" at step "+std::to_string(current_step)+". Sorry, no loops are allowed in the rule to rule map.");
				}
				else{
					rule_entry=NULL;
				}
			}
			else{
				if(failover>current_step){
					rule_entry=rule_to_rule_map->value_for_field_name_found_after_row_position(rule_entry->first,"step",*rule_to_rule_map->field_value_at_row_position(rule_entry->first,"failover"));
				}
				else if(failover!=0&&failover<current_step){
					throw std::runtime_error("You have a failover branch loop for parent symbol "+symbol+", head root symbol "+new_phrase_head_root.symbol+" and non-head root symbol "+new_phrase_non_head_root.symbol+" at step "+std::to_string(current_step)+". Sorry, no loops are allowed in the rule to rule map.");
				}
				else{
					rule_entry=NULL;
					//if(failover==current_step&&rule_to_rule_map->nr_of_result_rows()==current_step) valid_combination=true;
					if(failover==current_step) valid_combination=true;
				}
			}
		}
		else{
			throw std::runtime_error("Head root symbol and/or non-head root symbol variable/s don't match the symbols in the rule read from RULE_TO_RULE_MAP db table.");
		}
	}
	if(valid_combination==true){
		rule_step_failed=0;
        insert_in_main_dvm_and_dep_node_links(functors_validated_for_nodes);
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

void interpreter::insert_in_main_dvm_and_dep_node_links(std::multimap<unsigned int,std::pair<unsigned int,unsigned int> >& functors_validated_for_nodes){
    for(auto&& i:functors_validated_for_nodes){
        node_info *main_node=&get_private_node_info(i.first);
        node_info *dependent_node=&get_private_node_info(i.second.second);
        if(main_node->expression.dependencies==NULL||dependent_node->expression.dependencies==NULL){
            //TODO: check if rule_step_failed needs to be set here or exception should be thrown.
            //This may be the right place (check it!) to prevent dumps if a word gets combined with another
            //one where one of them is not registered in the DEPOLEX.
            //See comments in lexer::dependencies_read_for_functor().
            //As there may be more than one functors, it might be the case that execution can continue if
            //there's at least one, where the dependencies attributes are not null.
            //this may make sense as a first try instead of throwing an exception:
            //rule_step_failed=std::atoi(rule_entry_failure_copy->second.field_value.c_str());
        }
        else{//this else branch was not here earlier so this alone may complicate matters even though the
            // if branch still does not do anything
            main_node->dependency_validation_matrix.insert(i.second);
            logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"inserting in dvm, dependent node functor "+dependent_node->expression.lexeme+" for main node functor "+main_node->expression.lexeme);
            if(dependent_node->node_links.find(main_node->node_id)==dependent_node->node_links.end()){
                dependent_node->node_links.insert(std::make_pair(main_node->node_id,0));//TODO:get rid of second member in node_links
            }
        }
    }
}

bool interpreter::is_valid_combination(const unsigned int& main_node_id,const unsigned int& dependent_node_id){
    std::multimap<std::pair<std::string,std::string>,std::pair<unsigned int,std::string> > *functors_found=NULL;
    std::multimap<unsigned int,std::pair<unsigned int,unsigned int> > functors_validated_for_nodes;
    bool valid_combination=false;

    node_info *main_node=&get_private_node_info(main_node_id);
    node_info *dependent_node=&get_private_node_info(dependent_node_id);
    functors_found=is_valid_expression(*main_node,*dependent_node);
    if(functors_found!=NULL){
        for(auto&& m:*functors_found){
            functors_validated_for_nodes.insert(std::make_pair(main_node->node_id,std::make_pair(m.second.first,dependent_node->node_id)));
        }
        delete functors_found;
        insert_in_main_dvm_and_dep_node_links(functors_validated_for_nodes);
        valid_combination=true;
    }
    return valid_combination;
}

void interpreter::combine_sets(const unsigned int& operation, const std::vector<unsigned int>& prev_set, std::vector<unsigned int>& current_set){
	if(operation==1){//union
		std::set<unsigned int> union_set;
		for(auto&& i:prev_set){
			union_set.insert(i);
		}
		for(auto&& i:current_set){
			union_set.insert(i);
		}
		current_set.clear();
		for(auto&& i:union_set){
			current_set.push_back(i);
		}
	}
	else if(operation==2){//intersection
		std::multiset<unsigned int> union_set;
		for(auto&& i:prev_set){
			union_set.insert(i);
		}
		for(auto&& i:current_set){
			union_set.insert(i);
		}
		current_set.clear();
		for(auto&& i:union_set){
			if(union_set.count(i)==2) current_set.push_back(i);
		}
	}
	else if(operation==3){//Current minus previous -> current minus intersection
		std::multiset<unsigned int> union_set;
		std::set<unsigned int> current_set_copy;
		for(auto&& i:prev_set){
			union_set.insert(i);
		}
		for(auto&& i:current_set){
			union_set.insert(i);
			current_set_copy.insert(i);
		}
		current_set.clear();
		for(auto&& i:current_set_copy){
			if(union_set.count(i)==1) current_set.push_back(i);
		}
	}
	else if(operation==4){//Previous minus current -> previous minus intersection
		std::multiset<unsigned int> union_set;
		std::set<unsigned int> prev_set_copy;
		for(auto&& i:prev_set){
			union_set.insert(i);
			prev_set_copy.insert(i);
		}
		for(auto&& i:current_set){
			union_set.insert(i);
		}
		current_set.clear();
		for(auto&& i:prev_set_copy){
			if(union_set.count(i)==1) current_set.push_back(i);
		}
	}
	else if(operation==5){//disjunct
		std::multiset<unsigned int> union_set;
		for(auto&& i:prev_set){
			union_set.insert(i);
		}
		for(auto&& i:current_set){
			union_set.insert(i);
		}
		current_set.clear();
		for(auto&& i:union_set){
			if(union_set.count(i)==1) current_set.push_back(i);
		}
	}
}

transgraph* interpreter::build_transgraph(const p_m1_node_id_m2_d_key& root, const std::pair<std::string,unsigned int>& parent,
		std::map<p_m1_node_id_m2_d_key,std::pair<t_m0_parent_node_m1_nr_of_deps_m2_nr_of_deps_to_find_m3_parent_dkey_m4_parent_dcounter,std::map<unsigned int,std::pair<t_m0_parent_node_m1_nr_of_deps_m2_nr_of_deps_to_find_m3_parent_dkey_m4_parent_dcounter,unsigned int> > > >& longest_traversals,
		const unsigned int node_level, const unsigned int prev_parent_node_id){
	p_m1_tree_level_m2_p_m1_node_id_m2_d_key tree_level_and_functor_node;
	std::set<std::pair<std::string,unsigned int> > functors_processed;
	transgraph *functor_transgraph=NULL;

	logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"parent.first:"+parent.first+", parent.second:"+std::to_string(parent.second));
	auto root_found=longest_traversals.find(root);
	if(root_found==longest_traversals.end()){
		throw std::runtime_error("Root node not found.");
	}
	if(std::all_of(parent.first.begin(),parent.first.end(),::isdigit)==true){
		const node_info& nodeinfo=get_node_info(std::atoi(parent.first.c_str()));
		if(nodeinfo.expression.lexicon_entry==true){
			logger::singleton()==NULL?(void)0:logger::singleton()->log(3,nodeinfo.expression.lexeme+"_"+std::to_string(parent.second));
			functor_transgraph=new transgraph(std::to_string(nodeinfo.node_id),std::make_pair(nodeinfo.expression.lexeme,parent.second),get_node_info(std::atoi(parent.first.c_str())).expression.morphalytics);
		}
		else{
			logger::singleton()==NULL?(void)0:logger::singleton()->log(3,nodeinfo.expression.gcat+"_"+std::to_string(parent.second));
			functor_transgraph=new transgraph(std::to_string(nodeinfo.node_id),std::make_pair(nodeinfo.expression.gcat,parent.second),get_node_info(std::atoi(parent.first.c_str())).expression.morphalytics);
		}
	}
	else{
		logger::singleton()==NULL?(void)0:logger::singleton()->log(3,parent.first+"_"+std::to_string(parent.second));
		functor_transgraph=new transgraph(std::to_string(prev_parent_node_id),std::make_pair(parent.first,parent.second),NULL);
	}
	for(auto&& i:root_found->second.second){
		//TODO: think over if it's necessary to implement a logic after all the traversals
		//are done that cuts off branches leading to the same dependency node leaving only
		//the first path found. Unfortunately, it can only be done after the traversal as
		//it cannot be forseen that a path leads to a dependency node that was already reached via another path.

		const node_info& dep_node=get_node_info(i.first);
		logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"transgraph lexeme:"+dep_node.expression.lexeme+", d_key (i.second.second):"+std::to_string(i.second.second)
		+" lexeme node id (i.first):"+std::to_string(i.first)
		+" parent node:"+std::get<0>(i.second.first)
		+" parent d_key:"+std::to_string(std::get<3>(i.second.first))
		+" parent d_counter:"+std::to_string(std::get<4>(i.second.first)));
		bool odep_parent_found=false;
		std::pair<std::string,unsigned int> node_found=std::make_pair("",0);
		auto functor_node_odependencies=node_odependency_traversals.end();
		if(std::any_of(std::get<0>(i.second.first).begin(),std::get<0>(i.second.first).end(),::isdigit)==false){
			tree_level_and_functor_node.first=node_level;
			tree_level_and_functor_node.second=root;
			auto functor_node_found=node_dependency_traversal_stack_tree.find(tree_level_and_functor_node);
			if(functor_node_found==node_dependency_traversal_stack_tree.end()){
				throw std::runtime_error("Functor node not found in node dependency traversal stack tree.");
			}
			functor_node_odependencies=node_odependency_traversals.find(functor_node_found->first.second);
			if(functor_node_odependencies==node_odependency_traversals.end()){
				throw std::runtime_error("Functor node not found in node (optional) dependency traversals.");
			}
			unsigned int top_parent_node_id=0;
			if(prev_parent_node_id==0&&std::all_of(parent.first.begin(),parent.first.end(),::isdigit)==true) top_parent_node_id=std::atoi(parent.first.c_str());
			else top_parent_node_id=prev_parent_node_id;
			node_found=find_child_for_parent_bottom_up_via_optional_path(top_parent_node_id,std::get<0>(i.second.first),std::get<3>(i.second.first),std::get<4>(i.second.first),functor_node_odependencies->second,root_found->second.second);
			logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"parent_node_found_via_optional_path:"+node_found.first+" with d_key:"+std::to_string(node_found.second));
			if(node_found.first.empty()==false&&node_found.second>0&&dep_node.node_links.find(top_parent_node_id)!=dep_node.node_links.end()) odep_parent_found=true;
		}
		if(std::get<0>(i.second.first)==parent.first&&std::get<3>(i.second.first)==parent.second
		&&(i.first!=std::atoi(parent.first.c_str())||i.first==std::atoi(parent.first.c_str())&&i.second.second!=parent.second)
		&&(std::atoi(std::get<0>(i.second.first).c_str())==0&&odep_parent_found==true||std::atoi(std::get<0>(i.second.first).c_str())>0)){
			if(functors_processed.find(std::make_pair(std::to_string(i.first),i.second.second))==functors_processed.end()){
				logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"recursive call 1");
				logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"transgraph lexeme:"+get_node_info(i.first).expression.lexeme
				+", d_key (i.second.second):"+std::to_string(i.second.second)
				+", lexeme node id (i.first):"+std::to_string(i.first)
				+", parent node:"+std::get<0>(i.second.first)
				+", parent d_key:"+std::to_string(std::get<3>(i.second.first))
				+", parent d_counter:"+std::to_string(std::get<4>(i.second.first)));
				transgraph *child_transgraph=NULL;
				child_transgraph=build_transgraph(root,std::make_pair(std::to_string(i.first),i.second.second),longest_traversals,node_level,i.first);
				if(child_transgraph!=NULL){
					functor_transgraph->insert(std::get<4>(i.second.first),child_transgraph);
					functors_processed.insert(std::make_pair(std::to_string(i.first),i.second.second));
				}
				logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"recursive return 1");
			}
			else{
				logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"functor already processed");
			}
		}
		else if(std::any_of(std::get<0>(i.second.first).begin(),std::get<0>(i.second.first).end(),::isdigit)==false){//checking for parent being optional dependency
			for(auto&& j:functor_node_odependencies->second){
				logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"checking for optional dependency with functor "+j.first.first+" d_key "+std::to_string(j.first.second)+" d_counter "+std::to_string(std::get<5>(j.second))+" parent node "+std::get<0>(j.second)+" d_key "+std::to_string(std::get<1>(j.second))+" d_counter "+std::to_string(std::get<2>(j.second))+" and path nr "+std::to_string(std::get<3>(j.second)));
				if(std::get<0>(j.second)==parent.first&&std::get<1>(j.second)==parent.second&&std::all_of(parent.first.begin(),parent.first.end(),::isdigit)==false
					||std::get<0>(j.second)==parent.first&&std::get<1>(j.second)==parent.second&&j.first.first==node_found.first&&j.first.second==node_found.second){
					if(functors_processed.find(std::make_pair(j.first.first,j.first.second))==functors_processed.end()){
						logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"recursive call 2");
						logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"transgraph lexeme:"+j.first.first+", d_key:"+std::to_string(j.first.second)
						+", parent node:"+std::get<0>(j.second)+", parent d_key:"+std::to_string(std::get<1>(j.second))
						+", odep_level:"+std::to_string(std::get<4>(j.second)));
						transgraph *child_transgraph=NULL;
						if(prev_parent_node_id==0&&std::all_of(parent.first.begin(),parent.first.end(),::isdigit)==true){
							child_transgraph=build_transgraph(root,std::make_pair(j.first.first,j.first.second),longest_traversals,node_level,std::atoi(parent.first.c_str()));
						}
						else{
							child_transgraph=build_transgraph(root,std::make_pair(j.first.first,j.first.second),longest_traversals,node_level,prev_parent_node_id);
						}
						if(child_transgraph!=NULL){
							functor_transgraph->insert(std::get<2>(j.second),child_transgraph);
							functors_processed.insert(std::make_pair(j.first.first,j.first.second));
						}
						logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"recursive return 2");
					}
					else{
						logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"functor already processed");
					}
				}
			}
		}
	}
	if(std::any_of(parent.first.begin(),parent.first.end(),::isdigit)==false&&functors_processed.empty()==true){
		delete functor_transgraph;
		functor_transgraph=NULL;
	}
	return functor_transgraph;
}

std::pair<std::string,unsigned int> interpreter::find_child_for_parent_bottom_up_via_optional_path(const unsigned int top_parent_node_id, const std::string& node_to_track, const unsigned int dkey_to_track, const unsigned int dcounter_to_track,
		std::multimap<std::pair<std::string,unsigned int>,std::tuple<std::string,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int> >& odeps,
		std::map<unsigned int,std::pair<t_m0_parent_node_m1_nr_of_deps_m2_nr_of_deps_to_find_m3_parent_dkey_m4_parent_dcounter,unsigned int> >& deps){

	std::pair<std::string,unsigned int> node_found=std::make_pair("",0);
	if(std::all_of(node_to_track.begin(),node_to_track.end(),::isdigit)==false){
		for(auto&& i:odeps){
			logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"checking optional path via node:"+i.first.first
			+", d_key:"+std::to_string(i.first.second)
			+", d_counter:"+std::to_string(std::get<5>(i.second))
			+", parent node:"+std::get<0>(i.second)
			+" for top parent node:"+std::to_string(top_parent_node_id));
			if(i.first.first==node_to_track
				&&i.first.second==dkey_to_track
				&&std::get<5>(i.second)==dcounter_to_track
				&&std::atoi(std::get<0>(i.second).c_str())==top_parent_node_id){
				node_found.first=i.first.first;
				node_found.second=i.first.second;
				break;
			}
		}
		if(node_found.first.empty()==true&&node_found.second==0){
			for(auto&& i:odeps){
				if(i.first.first==node_to_track
					&&i.first.second==dkey_to_track
					&&std::get<5>(i.second)==dcounter_to_track
					&&std::atoi(std::get<0>(i.second).c_str())!=top_parent_node_id){
					node_found=find_child_for_parent_bottom_up_via_optional_path(top_parent_node_id,std::get<0>(i.second),std::get<1>(i.second),std::get<2>(i.second),odeps,deps);
					if(node_found.first.empty()==false&&node_found.second>0) break;
				}
			}
		}
	}
	else{//TODO:handle intermediate real dependency node in the path leading to top parent node once such "cross binding" is supported
		logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"Cannot yet handle intermediate real dependency node in the path leading to top parent node.");
	}
	return node_found;
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
	if(nodes.size()==1){
		leaf_node_id=*nodes.begin();
		if(leaf_node_id>0){
			const node_info& leaf_node=get_node_info(leaf_node_id);
			leaf_node.expression.morphalytics->add_feature(feature);
		}
	}
	return leaf_node_id;
}

unsigned int interpreter::add_feature_to_leaf(const node_info& node, const std::string& subnode_symbol, const std::string& leaf_symbol, const std::string& feature){
	unsigned int leaf_node_id=0;
	std::vector<unsigned int> nodes,subnodes;

	if(subnode_symbol.empty()==true)
		get_nodes_by_symbol(node,leaf_symbol,std::string(),nodes);
	else{
		get_nodes_by_symbol(node,subnode_symbol,std::string(),subnodes);
		for(auto&& subnode:subnodes){
			get_nodes_by_symbol(get_node_info(subnode),leaf_symbol,std::string(),nodes);
		}
	}
	if(nodes.size()==1){
		leaf_node_id=*nodes.begin();
		if(leaf_node_id>0){
			const node_info& leaf_node=get_node_info(leaf_node_id);
			leaf_node.expression.morphalytics->add_feature(feature);
		}
	}
	return leaf_node_id;
}

unsigned int interpreter::direct_descendant_of(const node_info& root_node){
	if(root_node.left_child==0&&root_node.right_child==0){
		logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"direct descendant found: "+std::to_string(root_node.node_id));
		return root_node.node_id;
	}
	if(root_node.left_child!=0&&root_node.right_child==0) return direct_descendant_of(get_node_info(root_node.left_child));
	else if(root_node.right_child!=0&&root_node.left_child==0) return direct_descendant_of(get_node_info(root_node.right_child));
	else return 0;
}

void interpreter::get_leafs_of_node_lr(const node_info& root_node, std::vector<unsigned int>& leafs){
	if(root_node.left_child==0&&root_node.right_child==0){
		leafs.push_back(root_node.node_id);
		logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"leaf word:"+root_node.expression.word);
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

std::vector<node_info> interpreter::nodes(){
	return node_infos;
}

void interpreter::destroy_node_infos(){
    nr_of_nodes_=0;
	return;
}

void interpreter::build_dependency_semantics(const unsigned char& toa,const unsigned char& crh,const std::string& language,lexer *lex,tokenpaths *tokenpaths){
    //TODO: Consider moving this and the related methods to the interpreter class
    //1. rank analyses in create_analysis(), store the successful and the failed analyses in different db tables
    //2. check if the returned analyses has the 'errors' property
    //3. if there's no error, return the ranked analyses
    //4. if there's an error but there's a main verb, call build_dependency_semantics()
    //5. if there's an error and no verb, look up the main verbs in the previous analyses. The mandatory dependencies
    //   of the verb finally chosen shall match the MOST of the lexemes of the human input i.e. the verb having the most
    //   mandatory dependencies matching most of the lexemes wins. Besides that if there are mandatory dependencies that are missing,
    //   check if they belong to the verb (like a prefix) and copy the corresponding word(s) of the missing dependencies
    //   together with the verb to construct a new (syntactically incorrect) sentence.
    //   However, it's not sure if it makes sense to check earlier utterances than the latest one.
    //6. start over the interpreter with the newly constructed sentence but this newly triggered interpretation
    //   shall be marked as autocorrected sentence interpretation in order that it can be stored in the db
    //   at the end of the interpretation
    db *sqlite=NULL;

    //is_any_path_left=false;//dependency semantics is not token path based, set it false to quit outer loop
    sqlite=db_factory::get_instance();
    //unsigned int nr_of_analyses=valid_paths.size();
    //std::map<std::string,std::vector<lexicon> > words_analyses=lexer::words_analyses();
    std::vector<lexicon> words_wo_cons=lex->words_wo_cons();
    //for(auto&& word_analyses:words_analyses){
        //morphology_wo_cons(word_analyses.second,words_wo_cons);
    //}
    //std::map<unsigned int,lexicon> main_verbs=find_main_verb(words_wo_cons);
    std::map<unsigned int,lexicon> main_verbs=lex->find_main_verb(words_wo_cons);
    if(crh&HI_VERB&&main_verbs.size()==0){
        //Check only the latest utterance, as it's not sure if it makes sense to check earlier ones.
        query_result *result=NULL;
        result=sqlite->exec_sql("SELECT * FROM ANALYSES WHERE TIMESTAMP=(SELECT MAX(TIMESTAMP) FROM ANALYSES) AND RANK=(SELECT MIN(RANK) FROM ANALYSES WHERE TIMESTAMP=(SELECT MAX(TIMESTAMP) FROM ANALYSES));");
        if(result!=NULL&&result->nr_of_result_rows()==1){
            rapidjson::Document jsondoc;
            std::string previous_analysis=*result->field_value_at_row_position(0,"analysis");
            logger::singleton()==NULL?(void)0:logger::singleton()->log(3,previous_analysis);
            jsondoc.Parse(previous_analysis.c_str());
            //TODO:Check for the value of main_symbol first once that's added. See todo comment below about features added
            //at syntactic level. If nothing is found by main_symbol, the logic below shall be used to find
            //the verbs which currently only looks for the first verb having the same gcat set in settings db table
            //for the symbol of the main_symbol.
            query_result *main_verb_result=NULL;
            main_verb_result=sqlite->exec_sql("SELECT * FROM SETTINGS WHERE key='main_verb';");
            std::string main_verb=*main_verb_result->field_value_at_row_position(0,"value");
            rapidjson::Value& morphologyArray=jsondoc["morphology"];
            std::string main_verb_word;
            rapidjson::Value morphologyObj;
            for(unsigned int i=0;i<morphologyArray.Size();++i){
                morphologyObj=morphologyArray[i];
                if(morphologyObj["gcat"].GetString()==main_verb){
                    logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"main verb gcat:"+std::string(morphologyObj["gcat"].GetString()));
                    main_verb_word=morphologyObj["word"].GetString();
                    break;
                }
            }
            std::locale locale=std::locale();
            delete lex;
            //lex points to the same instance as ::lex so deletion is fine
            //but to assign a new lexer the global needs to be updated as well
            lex=new lexer(main_verb_word.c_str(),language.c_str(),locale,false,tokenpaths);
            tokenpaths->assign_lexer(lex);
            //words_analyses=lexer::words_analyses();
            words_wo_cons.clear();
            words_wo_cons=lex->words_wo_cons();
            //for(auto&& word_analyses:words_analyses){
                //morphology_wo_cons(word_analyses.second,words_wo_cons);
            //}
            main_verbs.clear();
            main_verbs=lex->find_main_verb(words_wo_cons);
        }
    }
    if(main_verbs.size()==1){
        std::set<unsigned int> processed_words;
        std::set<std::pair<unsigned int,unsigned int>> processed_depolex;
        std::map<unsigned int,unsigned int> word_index_to_node_id_map;
        std::pair<unsigned int,lexicon> main_verb_indexed=*main_verbs.begin();
        unsigned int word_index=main_verb_indexed.first;
        lexicon main_verb=main_verb_indexed.second;
        main_verb.morphalytics->add_feature("main_verb");
        processed_words.insert(word_index);
        unsigned int main_node_id=set_node_info(main_verb.gcat,main_verb);
        word_index_to_node_id_map.insert(std::make_pair(word_index,main_node_id));
        //TODO: check what else may need to be cleaned up so that
        //in case of success the json analysis is not affected by
        //previously failed runs.
        //valid_parse_trees.clear();
        //valid_graphs.clear();
        //valid_paths.clear();
        //invalid_parse_trees.clear();
        //invalid_paths.clear();
        //invalid_path_errors.clear();
//        try{
            build_dependency_semantics(words_wo_cons,processed_words,word_index_to_node_id_map,main_node_id,"",processed_depolex,lex);
            const node_info& main_node=get_node_info(main_node_id);
            unsigned int root_node_id=set_node_info("S",main_node);
            node_info root_node=get_node_info(root_node_id);
            transgraph *transgraph=NULL;
            transgraph=longest_match_for_semantic_rules_found();
            if(transgraph!=NULL){
                tokenpaths->validate_parse_tree(nodes());
                tokenpaths->validate_path_wo_checks(words_wo_cons,transgraph);
                //calling validate_path(words_wo_cons,transgraph,true) doesn't work
                //as it does checks for different token paths which does not make sense
                //in dependency semantics so let's do the necessary part manually
                //valid_paths.push_back(words_wo_cons);
                //valid_graphs.push_back(transgraph);
                logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"TRUE");
                //nr_of_analyses=valid_paths.size();
            }
            else{
                logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"semantic error");
                tokenpaths->invalidate_parse_tree(nodes());
                tokenpaths->invalidate_path(words_wo_cons,"semantic error",NULL);
            }
//        }
//        catch(...){
//            logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"Unhandled exception when building dependency semantics.");
//            exit(EXIT_FAILURE);
//        }
    }
    else{
        if(main_verbs.size()>1){
            logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"More than one main verb found.");
        }
        else{
            logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"No main verb found.");
        }
    }
}

void interpreter::build_dependency_semantics(std::vector<lexicon>& words,std::set<unsigned int>& processed_words,std::map<unsigned int,unsigned int>& words2nodes,const unsigned int& main_node_id,const std::string& optional_dependency,std::set<std::pair<unsigned int,unsigned int>>& processed_depolex,lexer *lex){
    const std::pair<const unsigned int,field> *depolex_entry=NULL;

    const node_info& main_node=get_node_info(main_node_id);
    const lexicon& main_word=main_node.expression;
    std::string lexeme=main_word.lexeme;
    if(optional_dependency.empty()==false){
        lexeme=optional_dependency;
    }
    logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"lexeme:"+lexeme+", word:"+main_word.word);
    if(main_word.gcat!="CON"){
        depolex_entry=main_word.dependencies->first_value_for_field_name_found("lexeme",lexeme);
        while(depolex_entry!=NULL&&lexeme==*main_word.dependencies->field_value_at_row_position(depolex_entry->first,"lexeme")){
            std::string d_key=*main_word.dependencies->field_value_at_row_position(depolex_entry->first,"d_key");
            while(depolex_entry!=NULL&&lexeme==*main_word.dependencies->field_value_at_row_position(depolex_entry->first,"lexeme")
                  &&d_key==*main_word.dependencies->field_value_at_row_position(depolex_entry->first,"d_key")){
                std::string dependency_lexeme=*main_word.dependencies->field_value_at_row_position(depolex_entry->first,"semantic_dependency");
                std::string ref_d_key=*main_word.dependencies->field_value_at_row_position(depolex_entry->first,"ref_d_key");
                std::string manner=*main_word.dependencies->field_value_at_row_position(depolex_entry->first,"manner");
                //find_word_by_lexeme() returns the first hit but there may be more than one word with the same lexeme
                //so when recording which word has already been combined as dependency then the word entry (lexicon) itself
                //is recorded not only the lexeme
                bool all_possibilities_checked=false;
                std::set<unsigned int> dependencies_found;
                while(all_possibilities_checked==false&&(dependencies_found.empty()==true
                      ||manner=="1"&&dependencies_found.size()==1
                      ||manner=="2"&&dependencies_found.size()<=1)){
                    unsigned int dependency_word_index=0;
                    lexicon dependency=lex->find_word_by_lexeme(words,processed_words,dependency_lexeme,dependency_word_index);
                    if(dependency.lexeme.empty()==true){
                        dependency=lex->find_word_by_gcat(words,processed_words,dependency_lexeme,dependency_word_index);
                    }
                    logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"dependency.lexeme:"+dependency.lexeme+", dependency.gcat:"+dependency.gcat);
                    unsigned int combined_node_id=0;
                    unsigned int dependent_node_id=0;
                    if(dependency.lexeme.empty()==false||dependency.lexeme.empty()==true&&dependency.gcat=="CON"){
                        //NOTE: there may be >1 matching dependencies during the loop
                        auto dependent_word_node=words2nodes.find(dependency_word_index);
                        if(dependent_word_node!=words2nodes.end()&&dependent_word_node->first==dependency_word_index) dependent_node_id=dependent_word_node->second;
                        else{
                            dependent_node_id=set_node_info(dependency.gcat,dependency);
                            words2nodes.insert(std::make_pair(dependency_word_index,dependent_node_id));
                        }
                        if(processed_depolex.find(std::make_pair(main_node_id,dependent_node_id))==processed_depolex.end()){
                            //No tree is built from the combined nodes as there's no syntax tree in this case
                            combined_node_id=combine_nodes(words,processed_words,words2nodes,main_node_id,dependent_node_id,dependency_word_index,processed_depolex,ref_d_key);
                            dependencies_found.insert(dependent_node_id);
                        }
                    }
                    else{
                        all_possibilities_checked=true;
                    }
                }
                std::string dependency_counter=*main_word.dependencies->field_value_at_row_position(depolex_entry->first,"d_counter");
                std::string dependency_failover=*main_word.dependencies->field_value_at_row_position(depolex_entry->first,"d_failover");
                if((manner.empty()==true||manner=="0")&&dependencies_found.size()==1
                        ||manner=="1"&&dependencies_found.size()>=1
                        ||manner=="2"&&dependencies_found.size()>1){
                    for(auto& dependent_node_id:dependencies_found){
                        build_dependency_semantics(words,processed_words,words2nodes,dependent_node_id,"",processed_depolex,lex);
                    }
                }
                else if(((manner.empty()==true||manner=="0")&&dependencies_found.size()==0
                        ||manner=="1"&&dependencies_found.size()<1
                        ||manner=="2"&&dependencies_found.size()<=1)
                        &&std::atoi(dependency_failover.c_str())>=std::atoi(dependency_counter.c_str())){
                    build_dependency_semantics(words,processed_words,words2nodes,main_node_id,dependency_lexeme,processed_depolex,lex);
                }
                depolex_entry=main_word.dependencies->value_for_field_name_found_after_row_position(depolex_entry->first,"lexeme",lexeme);
            }
        }
    }
}

unsigned int interpreter::combine_nodes(std::vector<lexicon>& words,std::set<unsigned int>& processed_words,std::map<unsigned int,unsigned int>& words2nodes,const unsigned int& main_node_id,const unsigned int& dependent_node_id,const unsigned int& dependency_word_index,std::set<std::pair<unsigned int,unsigned int>>& processed_depolex,const std::string& ref_d_key){
    unsigned int combined_node_id=0;

    const node_info& main_node=get_node_info(main_node_id);
    const node_info& dependent_node=get_node_info(dependent_node_id);
    const lexicon& main_word=main_node.expression;
    logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"combining nodes: main node with id "+std::to_string(main_node_id)+", lexeme "+main_word.lexeme+" and dependent id "+std::to_string(dependent_node_id)+", lexeme:"+dependent_node.expression.lexeme);
    try{
        bool valid_combination=is_valid_combination(main_node_id,dependent_node_id);
        if(valid_combination==true){
            logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"main word:"+main_node.expression.word+", dvm size:"+std::to_string(main_node.dependency_validation_matrix.size()));
            combined_node_id=combine_nodes(main_word.gcat+"_"+dependent_node.expression.gcat+"_"+std::to_string(main_node_id)+"_"+std::to_string(dependent_node_id),main_node,dependent_node);
            logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"combined_node_id:"+std::to_string(combined_node_id));
            processed_words.insert(dependency_word_index);
            processed_depolex.insert(std::make_pair(main_node_id,dependent_node_id));
        }
    }
    catch(invalid_combination& exception){
        logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"Unhandled exception in tokenpaths::combine_nodes().");
    }
    return combined_node_id;
}
