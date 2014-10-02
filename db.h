#ifndef DB_H
	#define DB_H

	struct cl_db;
	typedef struct cl_db db;
	typedef struct {
		unsigned int rowid;
		char word[255];
		char gcat[12];
		char lexeme[32];
	}lexicon;

	/*PUBLIC*/
	db *new_db(void);

	void destroy_db(db **);

	int hi_open(db *, const char *);

	int hi_close(db *);

	const char *hi_get_errmsg(db *);

	int hi_exec_sql(db *, const char *, char **);

	/*PRIVATE*/
	int hi_store_row_data(void *, int, char **, char **);

	void hi_destroy_result(db *);
#endif
