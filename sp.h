#ifndef SP_H
	#define SP_H

	struct cl_interpreter;
	typedef struct cl_interpreter sp;
	typedef struct node_info{
		unsigned int node_id;
		char symbol[10];
		char expression[256];/*lexeme or constant*/
		struct node_info *left_child;
		struct node_info *right_child;/*argument node*/
	}node_info;

	/*PUBLIC*/
	sp *new_sp(void);

	void destroy_sp(sp **);

	int hi_set_node_info(sp *, char *, char *, const node_info *);

	const node_info *hi_get_node_info(sp *, unsigned int);

	int hi_combine_nodes(sp *, char *, const node_info *, const node_info *);

	const node_info *hi_get_object_node(sp *, const node_info *);

	const node_info *hi_get_head_node(sp *, const node_info *);

	const char *hi_get_command(sp *);

	/*PRIVATE*/
	int hi_validate_by_type(sp *, const char *, const char *, char *);

	int hi_validate_combination(sp *, const node_info *, const node_info *, char *);

	void hi_set_command(sp *, char *, char *, const char *);

	void hi_set_options(sp *, char *);

	char *hi_resolve_ev_redefinitions(sp *, const char *, const char *);

	void hi_destroy_node_infos(sp *);
#endif
