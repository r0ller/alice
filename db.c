#include "db.h"
#include <string.h>

struct cl_db{
	struct public_db{
		int (*open)(db *, const char *);
		int (*close)(db *);
		const char *(*get_errmsg)(db *);
		int (*exec_sql)(db *, const char *, char **);
		char **query_result_fields;
		char **query_result_values;
		unsigned int result_size;
		}public;
	struct private_db{
		int (*store_row_data)(void *, int, char **, char **);
		void (*destroy_result)(db *);
		sqlite3 *db;
		}private;
};

/*PUBLIC*/
db *new_db(){
	/*static*/ db *pdb=NULL;

	/*if(db==NULL){*/
		pdb=malloc(sizeof(db));
		pdb->public.open=&hi_open;
		pdb->public.close=&hi_close;
		pdb->public.get_errmsg=&hi_get_errmsg;
		pdb->public.exec_sql=&hi_exec_sql;
		pdb->public.query_result_fields=NULL;
		pdb->public.query_result_values=NULL;
		pdb->public.result_size=0;
		pdb->private.store_row_data=&hi_store_row_data;
		pdb->private.destroy_result=&hi_destroy_result;
		pdb->private.db=NULL;
		/*}*/
	/*printf("public.query_result_fields: %x\n",db->public.query_result_fields);*/
	return pdb;
}

void destroy_db(db **this){
	if(*this!=NULL){
		(*this)->private.destroy_result(*this);
		free(*this);
		*this=NULL;
	}
	return;
}

int hi_open(db *this, const char *filename){
	return sqlite3_open(filename, &this->private.db);
}

int hi_close(db *this){
	sqlite3_close(this->private.db);
	return 0;
}

const char *hi_get_errmsg(db *this){
	return sqlite3_errmsg(this->private.db);
}

int hi_exec_sql(db *this, const char *sql, char **errmsg){
	this->private.destroy_result(this);
	return sqlite3_exec(this->private.db, sql, this->private.store_row_data, this, errmsg);
}

/*PRIVATE*/
int hi_store_row_data(void *this, int nr_of_columns, char **fieldvalues, char **fields){/*CALLBACK function for sqlite3_exec*/
	unsigned int i,length;
	db *p_this=NULL;
	char **pac_query_result_fields=NULL,**pac_query_result_values=NULL;/*pac: pointer arithmetic copy*/

	/*for(i=0;i<nr_of_columns;i++){
		printf("%s=%s\n", fields[i], fieldvalues[i]);
		}*/
	p_this=this;
	p_this->public.query_result_fields=realloc(p_this->public.query_result_fields,(p_this->public.result_size+nr_of_columns)*sizeof(char *));
	pac_query_result_fields=p_this->public.query_result_fields+p_this->public.result_size;
	p_this->public.query_result_values=realloc(p_this->public.query_result_values,(p_this->public.result_size+nr_of_columns)*sizeof(char *));
	pac_query_result_values=p_this->public.query_result_values+p_this->public.result_size;
	for(i=0;i<nr_of_columns;i++){
		length=strlen(fields[i]);
		*pac_query_result_fields=malloc(length+1);
		strcpy(*pac_query_result_fields,fields[i]);
		pac_query_result_fields++;
		length=strlen(fieldvalues[i]);
		*pac_query_result_values=malloc(length+1);
		strcpy(*pac_query_result_values,fieldvalues[i]);
		pac_query_result_values++;
	}
	p_this->public.result_size=p_this->public.result_size+nr_of_columns;
	return 0; 
}

void hi_destroy_result(db *this){
	unsigned int i;
	char **pac_query_result_fields=NULL,**pac_query_result_values=NULL;/*pac: pointer arithmetic copy*/

	if(this->public.query_result_fields!=NULL){
		pac_query_result_fields=this->public.query_result_fields;
		for(i=0;i<this->public.result_size;i++){
			free(*pac_query_result_fields);
			pac_query_result_fields++;
		}
		free(this->public.query_result_fields);
		this->public.query_result_fields=NULL;
	}
	if(this->public.query_result_values!=NULL){
		pac_query_result_values=this->public.query_result_values;
		for(i=0;i<this->public.result_size;i++){
			free(*pac_query_result_values);
			pac_query_result_values++;
		}
		free(this->public.query_result_values);
		this->public.query_result_values=NULL;
	}
	this->public.result_size=0;
	return;
}
