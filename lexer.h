#ifndef LEXER_H
	#define LEXER_H

	struct cl_lexer;
	typedef struct cl_lexer lexer;

	/*PUBLIC*/
	lexer *new_lexer(void);

	void destroy_lexer(lexer **);

	int hi_scan(lexer *, const char *, char **);

	lexicon hi_get_word_by_token(lexer *, unsigned int);

	/*PRIVATE*/
	int hi_store_word(lexer *, db *);

	char *hi_prepare_lex_query(lexer *, const char *);

	void hi_destroy_words(lexer *);
#endif
