#include "sp.h"

struct cl_interpreter{
	struct public_sp{
		int (*set_node_info)(sp *, char *, char *, const node_info *);
		const node_info *(*get_node_info)(sp *, unsigned int);
		int (*combine_nodes)(sp *, char *, const node_info *, const node_info *);
		const node_info *(*get_object_node)(sp *, const node_info *);
		const node_info *(*get_head_node)(sp *, const node_info *);
	}public;
	struct private_sp{
		int (*validate_by_type)(sp *, const char *, const char *, char *);
		int (*validate_combination)(sp *, const node_info *, const node_info *, char *);
		void (*destroy_node_infos)(sp *);
		node_info **node_info;
		unsigned int nr_of_nodes;
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
	psp->private.validate_by_type=&hi_validate_by_type;
	psp->private.validate_combination=&hi_validate_combination;
	psp->private.destroy_node_infos=&hi_destroy_node_infos;
	psp->private.node_info=NULL;
	psp->private.nr_of_nodes=0;
	return psp;
}

void destroy_sp(sp **this){
	if(*this!=NULL){
		(*this)->private.destroy_node_infos(*this);
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
	printf("set node id:%d\n",(*this->private.node_info[this->private.nr_of_nodes-1]).node_id);
	strcpy((*nodeinfo)->symbol,symbol);
	printf("symbol:%s\n",(*this->private.node_info[this->private.nr_of_nodes-1]).symbol);
	if(expression==NULL)strcpy((*nodeinfo)->expression,"\0");
	else strcpy((*nodeinfo)->expression,expression);
	printf("expression:%s\n",(*nodeinfo)->expression);
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
	printf("combined node id:%d\n",(*this->private.node_info[this->private.nr_of_nodes-1]).node_id);
	strcpy((*nodeinfo)->symbol,symbol);
	printf("symbol:%s\n",(*this->private.node_info[this->private.nr_of_nodes-1]).symbol);
	head_node=this->public.get_head_node(this,left_node);
	if(head_node!=NULL){
		object_node=this->public.get_object_node(this,right_node);
		if(object_node==NULL)return -1;
		else if(strcmp(head_node->symbol,"QPro")!=0&&strlen(object_node->expression)>0){
			/* TODO: Instead of the current validation, the head node needs to be validated against
			 * all child nodes of the right_node having a non-empty expression. This would ensure that
			 * all constituents are checked against each other and not only the new head of the phrase and
			 * the object of the phrase. E.g. 'list big small files!' is contradictory but now only
			 * big<->files, small<->files and list<->files are validated and not small<->files, big<->small,
			 * big<->files, list<->files.*/
			if(this->private.validate_combination(this,left_node,right_node,errmsg)!=0){
				printf("%s\n",errmsg);
				return -1;
			}
			printf("valid combination:%s %s\n",head_node->expression,((node_info *)object_node)->expression);
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

	if(strcmp(node->symbol,"N")==0)return node;
	if(node->left_child!=NULL)object_node=this->public.get_object_node(this,node->left_child);
	if(node->right_child!=NULL)object_node=this->public.get_object_node(this,node->right_child);
	if(object_node!=NULL)printf("object_node id:%d symbol:%s expression:%s\n",object_node->node_id,object_node->symbol,object_node->expression);
	return object_node;
}

const node_info *hi_get_head_node(sp *this, const node_info *node){
	const node_info *head_node=NULL;

	if(strlen(node->expression)>0)return node;
	if(node->left_child!=NULL)head_node=this->public.get_head_node(this,node->left_child);
	/* Stop if head_node is already found on the left since English is a 'head first' language
	 * with a left-to-right word order!*/
	if(node->right_child!=NULL&&head_node==NULL)head_node=this->public.get_head_node(this,node->right_child);
	if(head_node!=NULL)printf("head_node id:%d symbol:%s expression:%s\n",head_node->node_id,head_node->symbol,head_node->expression);
	return head_node;
}

/*PRIVATE*/
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
	char entity[32];
	int valid_combination=-1;
	unsigned int i, direct_object_match[256];
	const node_info *object_node=NULL, *direct_object_node=NULL, *indirect_object_node=NULL, *head_node=NULL;

	strcpy(errmsg,"\0");
	head_node=this->public.get_head_node(this,left_node);
	if(strcmp(head_node->symbol,"V")==0){
		/*Get all entries for relation in head node*/
		if(this->private.validate_by_type(this,head_node->expression,"RELATIONS",errmsg)!=0)return -1;
		if(strlen(errmsg)>0)return -1;
		if(strcmp(left_node->symbol,"Vt")==0){
			direct_object_node=this->public.get_object_node(this,right_node);
			for(i=0;i<sqlite->public.result_size/3;i++){
				/*At least one entry must exist for the transitive verb with the direct object specified in head_node*/
				valid_combination=strcmp(direct_object_node->expression,sqlite->public.query_result_values[i*3+1]);
				if(valid_combination==0)break;
			}
		}
		else if(strcmp(left_node->symbol,"Vdt")==0){
			indirect_object_node=this->public.get_object_node(this,right_node);
			direct_object_node=this->public.get_object_node(this,left_node->right_child);
			for(i=0;i<sqlite->public.result_size/3;i++){
				/*At least one entry must exist for the transitive verb with the direct object specified in head_node*/
				valid_combination=strcmp(direct_object_node->expression,sqlite->public.query_result_values[i*3+1]);
				if(valid_combination==0)direct_object_match[i]=1;/*Mark with 1 if direct object matches*/
				else direct_object_match[i]=0;
			}
			/*Check indirect object for entries where direct object matched*/
			for(i=0;i<sqlite->public.result_size/3;i++){
				if(direct_object_match[i]==1){
					valid_combination=strcmp(indirect_object_node->expression,sqlite->public.query_result_values[i*3+2]);
					if(valid_combination==0)break;
				}
			}
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
	}
	return valid_combination;
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
