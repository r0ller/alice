#include "sp.h"

struct cl_interpreter{
	struct public_sp{
		int (*set_node_info)(sp *, char *, char *, const node_info *);
		const node_info *(*get_node_info)(sp *, unsigned int);
		int (*combine_nodes)(sp *, char *, const node_info *, const node_info *);
		const node_info *(*get_object_node)(sp *, const node_info *);
		const node_info *(*get_head_node)(sp *, const node_info *);
		const char *(*get_command)(sp *);
	}public;
	struct private_sp{
		int (*validate_by_type)(sp *, const char *, const char *, char *);
		int (*validate_combination)(sp *, const node_info *, const node_info *, char *);
		void (*set_command)(sp *, char *, char *, const char *);
		void (*set_options)(sp *, char *);
		char *(*resolve_ev_redefinitions)(sp *, const char *, const char *);
		void (*destroy_node_infos)(sp *);
		node_info **node_info;
		unsigned int nr_of_nodes;
		char *command;
		char *options;
	}private;
};

/*PUBLIC*/
sp *new_sp(void){
	sp *psp=NULL;

	psp=malloc(sizeof(sp));
	psp->public.set_node_info=&hi_set_node_info;
	psp->public.get_node_info=&hi_get_node_info;
	psp->public.combine_nodes=&hi_combine_nodes;
	psp->public.get_object_node=&hi_get_object_node;
	psp->public.get_head_node=&hi_get_head_node;
	psp->public.get_command=&hi_get_command;
	psp->private.validate_by_type=&hi_validate_by_type;
	psp->private.validate_combination=&hi_validate_combination;
	psp->private.set_command=&hi_set_command;
	psp->private.set_options=&hi_set_options;
	psp->private.resolve_ev_redefinitions=&hi_resolve_ev_redefinitions;
	psp->private.destroy_node_infos=&hi_destroy_node_infos;
	psp->private.node_info=NULL;
	psp->private.nr_of_nodes=0;
	psp->private.command=NULL;
	psp->private.options=NULL;
	return psp;
}

void destroy_sp(sp **this){
	if(*this!=NULL){
		(*this)->private.destroy_node_infos(*this);
		free((*this)->private.command);
		free((*this)->private.options);
		free(*this);
		*this=NULL;
	}
	return;
}

int hi_set_node_info(sp *this, char *symbol, char *expression, const node_info *argument){
	node_info **nodeinfo=NULL;

	this->private.node_info=realloc(this->private.node_info,(this->private.nr_of_nodes+1)*sizeof(node_info *));
	nodeinfo=this->private.node_info+this->private.nr_of_nodes;
	*nodeinfo=malloc(sizeof(node_info));
	(*nodeinfo)->node_id=++this->private.nr_of_nodes;
	/*printf("set node id:%d\n",(*this->private.node_info[this->private.nr_of_nodes-1]).node_id);*/
	strcpy((*nodeinfo)->symbol,symbol);
	/*printf("symbol:%s\n",(*this->private.node_info[this->private.nr_of_nodes-1]).symbol);*/
	if(expression==NULL)strcpy((*nodeinfo)->expression,"\0");
	else strcpy((*nodeinfo)->expression,expression);
	/*printf("expression:%s\n",(*nodeinfo)->expression);*/
	(*nodeinfo)->left_child=NULL;
	(*nodeinfo)->right_child=(node_info *)argument;
	return this->private.nr_of_nodes;
}

const node_info *hi_get_node_info(sp *this, unsigned int node_id){

	if(node_id>0&&node_id<=this->private.nr_of_nodes)
		return this->private.node_info[node_id-1];
	else
		return NULL;
}

int hi_combine_nodes(sp *this, char *symbol, const node_info *left_node, const node_info *right_node){
	node_info **nodeinfo=NULL;
	const node_info *object_node=NULL, *head_node=NULL;
	char errmsg[512]="\0";

	/*TODO:valamit kezdeni kell azzal ha a left_node->symbol='QPro' ill. ha az object_node-nak van gyereke*/
	this->private.node_info=realloc(this->private.node_info,(this->private.nr_of_nodes+1)*sizeof(node_info *));
	nodeinfo=this->private.node_info+this->private.nr_of_nodes;
	*nodeinfo=malloc(sizeof(node_info));
	(*nodeinfo)->node_id=++this->private.nr_of_nodes;
	/*printf("combined node id:%d\n",(*this->private.node_info[this->private.nr_of_nodes-1]).node_id);*/
	strcpy((*nodeinfo)->symbol,symbol);
	/*printf("symbol:%s\n",(*this->private.node_info[this->private.nr_of_nodes-1]).symbol);*/
	head_node=this->public.get_head_node(this,left_node);
	if(head_node!=NULL&&right_node!=NULL){
		object_node=this->public.get_object_node(this,right_node);
		if(object_node==NULL)return -1;
		else if(strcmp(head_node->symbol,"QPro")!=0&&strcmp(head_node->symbol,"Prep")!=0
				&&(strlen(object_node->expression)>0||object_node->right_child!=NULL)){
			/* TODO: Instead of the current validation, the head node needs to be validated against
			 * all child nodes of the right_node having a non-empty expression. This would ensure that
			 * all constituents are checked against each other and not only the new head of the phrase and
			 * the object of the phrase. E.g. 'list big small files!' is contradictory but now only
			 * big<->files, small<->files and list<->files are validated and not small<->files, big<->small,
			 * big<->files, list<->files.*/
			if(this->private.validate_combination(this,left_node,right_node,errmsg)!=0){
				/*printf("%s\n",errmsg);*/
				return -1;
			}
			/*printf("valid combination:%s %s\n",head_node->expression,((node_info *)object_node)->expression);*/
		}
	}
	else return -1;
	strcpy((*nodeinfo)->expression,"\0");
	(*nodeinfo)->left_child=(node_info *)left_node;
	(*nodeinfo)->right_child=(node_info *)right_node;
	return this->private.nr_of_nodes;
}

const node_info *hi_get_object_node(sp *this, const node_info *node){
	const node_info *object_node=NULL;

	if(strcmp(node->symbol,"N")==0){
		/*printf("object_node id:%d symbol:%s expression:%s\n",node->node_id,node->symbol,node->expression);*/
		return node;
	}
	if(node->left_child!=NULL)object_node=this->public.get_object_node(this,node->left_child);
	if(node->right_child!=NULL)object_node=this->public.get_object_node(this,node->right_child);
	return object_node;
}

const node_info *hi_get_head_node(sp *this, const node_info *node){
	const node_info *head_node=NULL;

	if(strlen(node->expression)>0){
		/*printf("head_node id:%d symbol:%s expression:%s\n",node->node_id,node->symbol,node->expression);*/
		return node;
	}
	if(node->left_child!=NULL)head_node=this->public.get_head_node(this,node->left_child);
	/* Stop if head_node is already found on the left since English is a 'head first' language
	 * with a left-to-right word order!*/
	if(node->right_child!=NULL&&head_node==NULL)head_node=this->public.get_head_node(this,node->right_child);
	return head_node;
}

const char *hi_get_command(sp *this){
	char *command=NULL,*options_tok=NULL,*variable_start=NULL,*token_start=NULL,pattern[256]="",*variable_end=NULL,*result=NULL;
	unsigned int options_length=0,i;

	/* TODO: Check options and command attributes for environment variable redefinitions
	 * and resolve them using some logic.*/
	if(this->private.command!=NULL){
		command=malloc(strlen(this->private.command)+1);
		strcpy(command,this->private.command);
		if(this->private.options!=NULL){
			options_length=strlen(this->private.options);
			options_tok=malloc(options_length+1);
			strcpy(options_tok,this->private.options);
			token_start=strtok(options_tok,"=");
			while(token_start!=NULL){
				variable_start=strrchr(token_start,' ');
				if(variable_start==NULL)variable_start=token_start;
				strncpy(pattern,token_start,strlen(variable_start));
				strcat(pattern,"=");
				/*printf("\nDEBUG GET COMMAND PATTERN: %s\n\n",pattern);*/
				/*Look up redefinitions for the environment variable in command*/
				variable_start=strstr(command,pattern);
				if(variable_start!=NULL){
					/*printf("\nDEBUG GET COMMAND PATTERN OK: %s\n\n",pattern);*/
					if(variable_start[strlen(pattern)]=='\''){
						variable_end=strchr(variable_start+strlen(pattern)+1,'\'');
						++variable_end;
						if(*variable_end==';')++variable_end;
					}
					else{
						variable_end=strchr(variable_start,' ');
						if(variable_end==NULL){
							variable_end=strchr(variable_start,';');
							if(variable_end==NULL)variable_end=variable_start+strlen(variable_start);
						}
					}
					sprintf(variable_start,"%s",variable_end);
				}
				for(i=0;i<256;i++)pattern[i]='\0';
				token_start=strtok(NULL,"=");
			}
			free(options_tok);
			result=malloc(strlen(this->private.options)+strlen(command)+1);
			sprintf(result,"%s%s",this->private.options,command);
			free(command);
			command=result;
		}
	}
	return command;
}

/*PRIVATE*/
char *hi_resolve_ev_redefinitions(sp *this, const char *in, const char *from){
	char *command=NULL,*options_tok=NULL,*variable_start=NULL,*token_start=NULL,pattern[256]="",*variable_end=NULL,*result=NULL;
	unsigned int options_length=0,i;

	/* TODO: Check options and command attributes for environment variable redefinitions
	 * and resolve them using some logic.*/
	if(in!=NULL){
		command=malloc(strlen(in)+1);
		strcpy(command,in);
		if(from!=NULL){
			options_length=strlen(from);
			options_tok=malloc(options_length+1);
			strcpy(options_tok,from);
			token_start=strtok(options_tok,"=");
			while(token_start!=NULL&&strchr(token_start,';')+1!=options_tok+options_length){
				variable_start=strrchr(token_start,';');
				if(variable_start==NULL){
					printf("NULL\n");
					variable_start=strrchr(token_start,' ');
					if(variable_start==NULL)variable_start=token_start;
					else ++variable_start;
				}
				else ++variable_start;
				strncpy(pattern,variable_start,strlen(variable_start));
				strcat(pattern,"=");
				printf("\nDEBUG GET COMMAND PATTERN: %s\n\n",pattern);
				/*Look up redefinitions for the environment variable in command*/
				variable_start=strstr(command,pattern);
				if(variable_start!=NULL){
					printf("\nDEBUG GET COMMAND PATTERN OK: %s\n\n",pattern);
					if(variable_start[strlen(pattern)]=='\''){
						variable_end=strchr(variable_start+strlen(pattern)+1,'\'');
						++variable_end;
						if(*variable_end==';')++variable_end;
					}
					else{
						variable_end=strchr(variable_start,';');
						if(variable_end==NULL){
							variable_end=strchr(variable_start,' ');
							if(variable_end==NULL)variable_end=variable_start+strlen(variable_start);
						}
						else ++variable_end;
					}
					sprintf(variable_start,"%s",variable_end);
				}
				printf("resolve command: %s\n",command);
				for(i=0;i<256;i++)pattern[i]='\0';
				token_start=strtok(NULL,"=");
			}
			free(options_tok);
			result=malloc(strlen(from)+strlen(command)+1);
			sprintf(result,"%s%s",from,command);
			free(command);
			command=result;
		}
	}
	return command;
}

int hi_validate_by_type(sp *this, const char *expression, const char *type, char *errmsg){
	char *query=NULL, length, *select_from="SELECT * FROM ", *where=" WHERE ", key[16];

	if(strcmp(type,"RELATIONS")==0)strcpy(key,"RELATION = '");
	else if(strcmp(type,"ENTITIES")==0)strcpy(key,"ENTITY = '");
	length=strlen(select_from)+strlen(type)+strlen(where)+strlen(key)+strlen(expression)+3;
	query=malloc(length);
	strcpy(query,select_from);
	strcat(query,type);
	strcat(query,where);
	strcat(query,key);
	strcat(query,expression);
	strcat(query,"';");
	if(sqlite->public.exec_sql(sqlite,query,&errmsg)){
		free(query);
		return -1;
	}
	if(sqlite->public.query_result_values[0]==NULL||sqlite->public.query_result_values[1]==NULL){
		strcpy(errmsg,"Error: no entry was found in the database table '");
		strcat(errmsg,"' for '");
		strcat(errmsg,expression);
		strcat(errmsg,"'.");
	}
	free(query);
	return 0;
}

int hi_validate_combination(sp *this, const node_info *left_node, const node_info *right_node, char *errmsg){
	char entity[32],*argument=NULL,*command=NULL,*constant=NULL;
	int valid_combination=-1;
	unsigned int i,preposition_matched[256],command_length=0;
	const node_info *object_node=NULL, *head_node=NULL, *PP_head_node=NULL;

	strcpy(errmsg,"\0");
	head_node=this->public.get_head_node(this,left_node);
	if(strcmp(head_node->symbol,"V")==0){
		object_node=this->public.get_object_node(this,right_node);
		if(strcmp(right_node->symbol,"NP")==0){
			if(strlen(object_node->expression)>0){
				if(this->private.validate_by_type(this,object_node->expression,"ENTITIES",errmsg)!=0)return -1;
				if(strlen(errmsg)>0)return -1;
				command_length=strlen(sqlite->public.query_result_values[2]);
				command=malloc(command_length+1);
				strcpy(command,sqlite->public.query_result_values[2]);
			}
			/*Get all entries for relation in head node*/
			if(this->private.validate_by_type(this,head_node->expression,"RELATIONS",errmsg)!=0)return -1;
			if(strlen(errmsg)>0)return -1;
			for(i=0;i<sqlite->public.result_size/4;i++){
				/*At least one entry must exist for the transitive verb with no preposition specified*/
				valid_combination=strcmp("",sqlite->public.query_result_values[i*4+1]);
				if(valid_combination==0)preposition_matched[i]=1;/*Mark with 1 if preposition matches*/
				else preposition_matched[i]=0;
			}
			/*Check entries where preposition matched*/
			for(i=0;i<sqlite->public.result_size/4;i++){
				if(preposition_matched[i]==1){
					valid_combination=strcmp(object_node->expression,sqlite->public.query_result_values[i*4+2]);
					if(valid_combination==0){
						command=realloc(command,command_length+strlen(sqlite->public.query_result_values[i*4+3])+1);
						if(command_length==0)strcpy(command,sqlite->public.query_result_values[i*4+3]);
						else strcat(command,sqlite->public.query_result_values[i*4+3]);
						if(object_node->right_child!=NULL)this->private.set_command(this,command,object_node->right_child->expression,NULL);
						else this->private.set_command(this,command,NULL,NULL);
						break;
					}
				}
			}
		}
		else if(strcmp(right_node->symbol,"PP")==0){
			/*Get all entries for relation in head node*/
			if(this->private.validate_by_type(this,head_node->expression,"RELATIONS",errmsg)!=0)return -1;
			if(strlen(errmsg)>0)return -1;
			PP_head_node=this->public.get_head_node(this,right_node);
			for(i=0;i<sqlite->public.result_size/4;i++){
				/*At least one entry must exist for the transitive verb with the preposition specified in PP_head_node*/
				valid_combination=strcmp(PP_head_node->expression,sqlite->public.query_result_values[i*4+1]);
				if(valid_combination==0)preposition_matched[i]=1;/*Mark with 1 if preposition matches*/
				else preposition_matched[i]=0;
			}
			/*Check entries where preposition matched*/
			for(i=0;i<sqlite->public.result_size/4;i++){
				if(preposition_matched[i]==1){
					if(strlen(object_node->expression)>0){
						valid_combination=strcmp(object_node->expression,sqlite->public.query_result_values[i*4+2]);
						if(valid_combination==0){
							command=sqlite->public.query_result_values[i*4+3];
							if(object_node->right_child!=NULL)constant=object_node->right_child->expression;
							break;
						}
					}
					else{
						if(argument==NULL){
							argument=sqlite->public.query_result_values[i*4+2];
							command=sqlite->public.query_result_values[i*4+3];
							if(object_node->right_child!=NULL)constant=object_node->right_child->expression;
							valid_combination=0;
						}
						else{
							valid_combination=strcmp(argument,sqlite->public.query_result_values[i*4+2]);
							if(valid_combination!=0)break;
						}
					}
				}
			}
			if(valid_combination==0)this->private.set_command(this,command,constant,PP_head_node->expression);
			else return -1;
		}
		else return -1;
	}
	else{/*Entity tree traversal considering left_node->expression specific and object_node->expression general*/
		object_node=this->public.get_object_node(this,right_node);
		strcpy(entity,left_node->expression);
		do{
			if(this->private.validate_by_type(this,entity,"ENTITIES",errmsg)!=0)return -1;
			if(strlen(errmsg)>0)break;
			strcpy(entity,sqlite->public.query_result_values[1]);
			valid_combination=strcmp(object_node->expression,entity);
		}while(valid_combination!=0&&strcmp(sqlite->public.query_result_values[0],sqlite->public.query_result_values[1])!=0);
		if(valid_combination!=0&&strlen(errmsg)==0){
			/*Entity tree traversal considering left_node->expression general and object_node->expression specific*/
			strcpy(entity,object_node->expression);
			do{
				if(this->private.validate_by_type(this,entity,"ENTITIES",errmsg)!=0)return -1;
				if(strlen(errmsg)>0)break;
				strcpy(entity,sqlite->public.query_result_values[1]);
				valid_combination=strcmp(left_node->expression,entity);
			}while(valid_combination!=0&&strcmp(sqlite->public.query_result_values[0],sqlite->public.query_result_values[1])!=0);
		}
		if(valid_combination==0){
			this->private.set_options(this,sqlite->public.query_result_values[2]);
		}
	}
	return valid_combination;
}

void hi_set_command(sp *this, char *command, char *constant, const char *prep){
	char *buffer=NULL,pattern[256]="",*existing_variable=NULL,*variable_end=NULL,*command_tok=NULL,*in=NULL;
	unsigned int command_length=0,i;

	if(this->private.command==NULL){
		command_length=strlen(command);
		command_tok=malloc(command_length+1);
		strcpy(command_tok,command);
		existing_variable=strtok(command_tok,"$");
		/*Ignore first tokenized part, it ends in $, not begins with it*/
		existing_variable=strtok(NULL,"$");
		while(existing_variable!=NULL){
			variable_end=strchr(existing_variable,' ');
			if(variable_end==NULL)variable_end=existing_variable+strlen(existing_variable);
			else if(*(variable_end-1)=='\'')--variable_end;
			strncpy(pattern,existing_variable,variable_end-existing_variable);
			strcat(pattern,"=");
			printf("\nDEBUG PATTERN: %s\n\n",pattern);
			/*Don't look up another definition if the environment variable is already defined in command*/
			if(strstr(command,pattern)==NULL&&this->private.command==NULL
				||strstr(command,pattern)==NULL&&this->private.command!=NULL&&strstr(this->private.command,pattern)==NULL){
				printf("\nDEBUG PATTERN OK: %s\n\n",pattern);
				for(i=0;i<sqlite->public.result_size/4;i++){
					printf("\nDEBUG DB ENTRY: %s\n\n",sqlite->public.query_result_values[i*4+3]);
					/*At least one entry must exist with the pattern specified*/
					if(strstr(sqlite->public.query_result_values[i*4+3],pattern)!=NULL&&
							(prep!=NULL&&strcmp(prep,sqlite->public.query_result_values[i*4+1])==0
							||prep==NULL&&strlen(sqlite->public.query_result_values[i*4+1])>0)){
						command_length=command_length+strlen(sqlite->public.query_result_values[i*4+3]);
						if(this->private.command==NULL){
							this->private.command=malloc(command_length+1);
							strcpy(this->private.command,sqlite->public.query_result_values[i*4+3]);
						}
						else if(strstr(this->private.command,sqlite->public.query_result_values[i*4+3])==NULL){
							this->private.command=realloc(this->private.command,command_length+1);
							strcat(this->private.command,sqlite->public.query_result_values[i*4+3]);
						}
						printf("\nDEBUG VARIABLE: %s\n\n",this->private.command);
						break;
					}
				}
			}
			for(i=0;i<256;i++)pattern[i]='\0';
			existing_variable=strtok(NULL,"$");
		}
		free(command_tok);
		if(constant==NULL){
			if(this->private.command==NULL){
				this->private.command=malloc(command_length+1);
				strcpy(this->private.command,command);
			}
			else{
				strcat(this->private.command,command);
			}
		}
		else{
			if(this->private.command==NULL){
				this->private.command=malloc(command_length+strlen(constant)+12);
				sprintf(this->private.command,"constant=%s;%s",constant,command);
			}
			else{
				this->private.command=realloc(this->private.command,command_length+strlen(constant)+12);
				strcat(this->private.command,"constant=");
				strcat(this->private.command,constant);
				strcat(this->private.command,";");
				strcat(this->private.command,command);
			}
		}

	}
	else{
		if(constant==NULL){
			buffer=malloc(strlen(command)+strlen(this->private.command)+1);
			sprintf(buffer,"%s%s",command,this->private.command);
			free(this->private.command);
			this->private.command=buffer;
		}
		else{
			buffer=malloc(strlen(constant)+strlen(command)+strlen(this->private.command)+1);
			strncpy(pattern,command,strchr(command,'=')-command+1);
			sprintf(buffer,"%s%s",pattern,constant);
			variable_end=strchr(command,';');
			printf("variable_end: %s\n",variable_end);
			strncat(buffer,variable_end,strlen(variable_end));
			printf("buffer:%s\n",buffer);
			in=this->private.command;
			this->private.command=this->private.resolve_ev_redefinitions(this,(const char *)this->private.command,(const char *)buffer);
			free(in);
			free(buffer);

			/*buffer=malloc(strlen(constant)+strlen(command)+strlen(this->private.command)+1);
			strncpy(pattern,command,strchr(command,'=')-command+1);
			existing_variable=strstr(this->private.command,pattern);
			if(existing_variable!=NULL){
				if(existing_variable==this->private.command
						||existing_variable>this->private.command&&(*(existing_variable-1)==' '||*(existing_variable-1)==';')){
					if(existing_variable-this->private.command>0){
						printf("command1: %s\n",buffer);
						strncpy(buffer,this->private.command,existing_variable-this->private.command);
						printf("command1: %s\n",buffer);
						buffer[existing_variable-this->private.command]='\0';
						strcat(buffer,pattern);
						printf("command1: %s\n",buffer);
					}
					else{
						strcpy(buffer,pattern);
						printf("command2: %s\n",buffer);
					}
					strcat(buffer,constant);
					printf("command: %s\n",buffer);
					printf("variable_start: %s\n",existing_variable);
					variable_end=strchr(existing_variable,';');
					printf("variable_end: %s\n",variable_end);
					strncat(buffer,variable_end,strlen(variable_end));
					printf("command: %s\n",buffer);
					this->private.command=buffer;
				}
			}
			else{
				sprintf(buffer,"%s%s;%s",pattern,constant,this->private.command);
				free(this->private.command);
				this->private.command=buffer;
			}*/
		}
	}
	printf("\nDEBUG SET_COMMAND: %s\n\n",this->private.command);
}

void hi_set_options(sp *this, char *options){

	/* TODO: check for already existing environment variables in this->private.options and if such a variable
	 * occurs in the incoming options parameter, then rearrange this->private.options with string operations.
	 * Otherwise, with simple concatenation the already existing environment variable loses its value due to
	 * the redefinition in the incoming options parameter.*/
	if(this->private.options==NULL){
		this->private.options=malloc(strlen(options)+1);
		strcpy(this->private.options,options);
	}
	else{
		this->private.options=realloc(this->private.options,strlen(this->private.options)+strlen(options)+1);
		strcat(this->private.options,options);
	}
	/*printf("\nDEBUG SET_OPTIONS: %s\n\n",this->private.options);*/
}

void hi_destroy_node_infos(sp *this){
	unsigned int i;

	if(this->private.node_info!=NULL){
		for(i=0;i<this->private.nr_of_nodes;i++){
			free(this->private.node_info[i]);
		}
		free(this->private.node_info);
		this->private.node_info=NULL;
		this->private.nr_of_nodes=0;
	}
	return;
}
