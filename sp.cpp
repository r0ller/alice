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

int interpreter::set_node_info(const std::string& symbol, const std::string& expression, const node_info& argument){
	node_info nodeinfo;

	nodeinfo.node_id=++nr_of_nodes;
	nodeinfo.symbol=symbol;
	if(expression.empty()==false) nodeinfo.expression=expression;
	nodeinfo.left_child=0;
	nodeinfo.right_child=argument.node_id;
	node_infos.push_back(nodeinfo);
	/*printf("set node id:%d\n",node_infos[nr_of_nodes-1].node_id);
	printf("symbol:%s\n",node_infos[nr_of_nodes-1].symbol.c_str());
	printf("expression:%s\n",node_infos[nr_of_nodes-1].expression.c_str());
	printf("left_child:%d\n",node_infos[nr_of_nodes-1].left_child);
	printf("right_child:%d\n",node_infos[nr_of_nodes-1].right_child);*/
	return nodeinfo.node_id;
}

const node_info& interpreter::get_node_info(unsigned int node_id){
	/*printf("node info:\nnode id:%d\n",node_infos.at(node_id-1).node_id);
	printf("symbol:%s\n",node_infos.at(node_id-1).symbol.c_str());
	printf("expression:%s\n",node_infos.at(node_id-1).expression.c_str());
	printf("left_child:%d\n",node_infos.at(node_id-1).left_child);
	printf("right_child:%d\n",node_infos.at(node_id-1).right_child);*/
	return node_infos.at(node_id-1);//Make use of out_of_range exception
}

int interpreter::combine_nodes(const std::string& symbol, const node_info& left_node, const node_info& right_node){
	node_info nodeinfo;
	unsigned int head_node_id=0,object_node_id=0;

	/*TODO:valamit kezdeni kell azzal ha a left_node->symbol='QPro' ill. ha az object_node-nak van gyereke*/
	nodeinfo.node_id=++nr_of_nodes;
	/*printf("combined node id:%d\n",(*this->private.node_info[this->private.nr_of_nodes-1]).node_id);*/
	nodeinfo.symbol=symbol;
	/*printf("symbol:%s\n",(*this->private.node_info[this->private.nr_of_nodes-1]).symbol);*/
	head_node_id=get_head_node(left_node);
	if(head_node_id!=0&&right_node.node_id!=0){
		object_node_id=get_object_node(right_node);
		if(object_node_id==0) throw object_node_missing(left_node.expression,right_node.expression);
		else if(get_node_info(head_node_id).symbol!="QPro"&&get_node_info(head_node_id).symbol!="Prep"
				&&(get_node_info(object_node_id).expression.empty()==false||get_node_info(object_node_id).right_child!=0)){
			/* TODO: Instead of the current validation, the head node needs to be validated against
			 * all child nodes of the right_node having a non-empty expression. This would ensure that
			 * all constituents are checked against each other and not only the new head of the phrase and
			 * the object of the phrase. E.g. 'list big small files!' is contradictory but now only
			 * big<->files, small<->files and list<->files are validated and not small<->files, big<->small,
			 * big<->files, list<->files.*/
			if(is_valid_combination(left_node,right_node)==false){
				throw invalid_combination(left_node.expression,right_node.expression);
			}
			/*printf("valid combination:%s %s\n",head_node->expression,((node_info *)object_node)->expression);*/
		}
	}
	else throw head_node_missing(left_node.expression,right_node.expression);
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

unsigned int interpreter::get_object_node(const node_info& node){
	unsigned int object_node_id=0;

	if(node.symbol=="N"){
		//printf("DEBUG: object_node id:%d symbol:%s expression:%s\n",node.node_id,node.symbol.c_str(),node.expression.c_str());
		return node.node_id;
	}
	if(node.left_child!=0)object_node_id=get_object_node(get_node_info(node.left_child));
	if(node.right_child!=0)object_node_id=get_object_node(get_node_info(node.right_child));
	//printf("DEBUG: get_object_node object_node.node_id=%d\n",object_node_id);
	return object_node_id;
}

unsigned int interpreter::get_head_node(const node_info& node){
	unsigned int head_node_id=0;

	if(node.expression.empty()==false){
		//printf("DEBUG: head_node id:%d symbol:%s expression:%s\n",node.node_id,node.symbol.c_str(),node.expression.c_str());
		return node.node_id;
	}
	if(node.left_child!=0)head_node_id=get_head_node(get_node_info(node.left_child));
	/* Stop if head_node is already found on the left since English is a 'head first' language
	 * with a left-to-right word order!*/
	if(node.right_child!=0&&head_node_id==0)head_node_id=get_head_node(get_node_info(node.right_child));
	return head_node_id;
}

std::string interpreter::get_command(){
	std::string command,environment_variable;
	std::vector<std::string> environment_variables;

	/* TODO: Check options and command attributes for environment variable redefinitions
	 * and resolve them using some logic.*/
	if(this->command.empty()==false){
		command=this->command;
		if(options.empty()==false){
			find_ev_definitions(options,environment_variables);
			for(unsigned int i=0;i<environment_variables.size();++i){
				environment_variable=environment_variables[i];
				/*Look up redefinitions for the environment variable in command*/
				delete_ev_redefinitions(environment_variable,command);
			}
			command=options+command;
		}
	}
	return command;
}

/*PRIVATE*/
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

std::string interpreter::resolve_ev_redefinitions(const std::string& in, const std::string& from){
	std::string command,ev_string;
	ev_name_value_pair environment_variable;
	char *old_ev_cstring=NULL, *new_ev_cstring=NULL;
	std::vector<ev_name_value_pair> environment_variables;

	/* TODO: Check options and command attributes for environment variable redefinitions
	 * and resolve them using some logic.*/
	if(in.empty()==false){
		command=in;
		if(from.empty()==false){
			find_ev_definitions(from,environment_variables);
			for(unsigned int i=0;i<environment_variables.size();++i){
				environment_variable=environment_variables[i];
				/*Look up redefinitions for the environment variable in command*/
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

db *interpreter::is_valid_expression_of_type(const std::string& expression, const std::string& type){
	std::string query, select_from("SELECT * FROM "), where(" WHERE "), key;
	db *sqlite=NULL;

	if(type=="RELATIONS") key="RELATION = '";
	else if(type=="ENTITIES") key="ENTITY = '";
	query=select_from+type+where+key+expression+"';";
	sqlite=db::get_instance();
	sqlite->exec_sql(query);
	if(sqlite->query_result_set().empty()==true) return NULL;
	else return sqlite;
}

bool interpreter::is_valid_combination(const node_info& left_node, const node_info& right_node){
	std::string entity,argument,command,constant,options,options_field_value, preposition_field_value,
				argument_field_value, command_field_value, entity_field_value, is_a_field_value;
	bool valid_combination=false;
	unsigned int i,preposition_matched[256];
	db *sqlite=NULL;

	const node_info& head_node=get_node_info(get_head_node(left_node));
	if(head_node.symbol=="V"){
		const node_info& object_node=get_node_info(get_object_node(right_node));
		if(right_node.symbol=="NP"){
			if(object_node.expression.empty()==false){
				sqlite=is_valid_expression_of_type(object_node.expression,"ENTITIES");
				if(sqlite==NULL){
					return false;
				}
				options_field_value=sqlite->get_field_value(0,"options");
				command=options_field_value;
			}
			/*Get all entries for relation in head node*/
			sqlite=is_valid_expression_of_type(head_node.expression,"RELATIONS");
			if(sqlite==NULL){
				return false;
			}
			for(i=0;i<sqlite->result_size();++i){
				/*At least one entry must exist for the transitive verb with no preposition specified*/
				preposition_field_value=sqlite->get_field_value(i,"preposition");
				if(preposition_field_value.empty()==true){
					preposition_matched[i]=1;/*Mark with 1 if preposition matches*/
					valid_combination=true;
				}
				else{
					preposition_matched[i]=0;
					valid_combination=false;
				}
			}
			/*Check entries where preposition matched*/
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
			/*Get all entries for relation in head node*/
			sqlite=is_valid_expression_of_type(head_node.expression,"RELATIONS");
			if(sqlite==NULL){
				return false;
			}
			const node_info& PP_head_node=get_node_info(get_head_node(right_node));
			for(i=0;i<sqlite->result_size();++i){
				/*At least one entry must exist for the transitive verb with the preposition specified in PP_head_node*/
				preposition_field_value=sqlite->get_field_value(i,"preposition");
				if(preposition_field_value==PP_head_node.expression){
					preposition_matched[i]=1;/*Mark with 1 if preposition matches*/
					valid_combination=true;
				}
				else{
					preposition_matched[i]=0;
					valid_combination=false;
				}
			}
			/*Check entries where preposition matched*/
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
	else{/*Entity tree traversal considering left_node->expression specific and object_node->expression general*/
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
			/*Entity tree traversal considering left_node->expression general and object_node->expression specific*/
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
	return valid_combination;
}

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
			/*Don't look up another definition if the environment variable is already defined in command*/
			if(command.find(pattern)==std::string::npos&&this->command.empty()==true
				||command.find(pattern)==std::string::npos&&this->command.empty()==false&&this->command.find(pattern)==std::string::npos){
				//printf("\nDEBUG PATTERN OK: %s\n\n",pattern.c_str());
				for(i=0;i<sqlite->result_size();++i){
					/*At least one entry must exist with the pattern specified*/
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

void interpreter::set_options(const std::string& options){

	/* TODO: check for already existing environment variables in this->private.options and if such a variable
	 * occurs in the incoming options parameter, then rearrange this->private.options with string operations.
	 * Otherwise, with simple concatenation the already existing environment variable loses its value due to
	 * the redefinition in the incoming options parameter.*/
	if(this->options.empty()==true){
		this->options=options;
	}
	else{
		this->options+=options;
	}
	//printf("\nDEBUG SET_OPTIONS: %s\n\n",this->options.c_str());
}

void interpreter::destroy_node_infos(){
	nr_of_nodes=0;
	return;
}
