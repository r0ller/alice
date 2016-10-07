PRAGMA foreign_keys = ON;

create table ROOT_TYPE(
root_type varchar(1) primary key /*h:head root, n:non head root*/
);

/*Table for platform specific language id mapping*/
create table LIDMAP(
plid varchar(16),
platform varchar(16),
lid varchar(5),
PRIMARY KEY(plid, platform)
FOREIGN KEY(lid) REFERENCES LANGUAGES(lid)
);

create table LANGUAGES(
lid varchar(5) primary key,
language varchar(128),
head_position smallint, /*0: undefined, 1: head first, 2: head last*/
fst varchar(256)
);

create table GCAT(/*Eventually, table for terminal symbols, i.e. to which yacc tokens can be assigned*/
gcat varchar(12), /*references SYMBOLS(symbol),*/
feature varchar(12), /*references SYMBOLS(symbol),*/
lid varchar(5) references LANGUAGES(lid),
token smallint,
/*description varchar(128),*/
PRIMARY KEY(gcat, feature, lid) /*gcat, feature, lid are all keys as once token literals in yacc source will be generated (by concatenating gcat, feature and lid), uniqueness will be granted*/
FOREIGN KEY(gcat, lid) REFERENCES SYMBOLS(symbol, lid)
FOREIGN KEY(feature, lid) REFERENCES SYMBOLS(symbol, lid)
);
/*create unique index i_gcat_lid on GCAT(gcat, lid);*/

create table SYMBOLS(/*Table for all kinds of symbols: terminals (including gcat features) and non-terminals*/
symbol varchar(12),/*Currently only used to reference from gcat and rule_to_rule_map*/
lid varchar(5) references LANGUAGES(lid),
description varchar(128),
PRIMARY KEY(symbol, lid)
);

/*handles semantic dependencies like e.g. kick the bucket=kick|1|1|the;kick|1|2|bucket; and so on like look|1|1|up;look|2|1|after;*/
/*It also stores semantic dependencies of lexemes and morphemes like: k�ldd el=k�ld|1|1|d;k�ld|1|2|el;*/
/*That is, it is to store dependencies within one semantic unit (szótári egység)*/
/*Does NOT contain dependencies with modifiers i.e. entries that fit in ATTRIBUTE_FUNCTORS or ADVERB_FUNCTORS like: yellow stone, play slowly, etc.*/
create table DEPOLEX(
lexeme varchar(47),
d_key smallint, /*smallest value: 1*/
d_counter smallint, /*smallest value: 1*/
optional_parent_allowed smallint, /*if true, dependency entry is taken into account as well even if the lexeme was not found as dependency one level above; 0:false, otherwise:true; note that NULL is evaulated as 0*/
d_failover smallint, /*NULL or 0 means end of dependency chain; a failover dependency points to a d_counter (> than current d_counter) and is only executed if the current d_counter dependency check failed*/
d_successor smallint, /*NULL or 0 means end of dependency chain; a successor dependency points to a d_counter (> than current d_counter) and is only executed if the current d_counter dependency check was successful*/
manner smallint,/*0:exactly once, 1:at least once; 2:more than once*/
semantic_dependency varchar(47), /*dependencies must be stored explicitly (which means if a word has no dependencies i.e. can stand on its own,
must be stored with full key entry with NULL semantic_dependecy value), otherwise noone can tell if a functor (word) can stand on its own or only together with other words*/
ref_d_key smallint,/*belongs to the field semantic_dependency in this table*/
PRIMARY KEY(lexeme, d_key, d_counter)
FOREIGN KEY(lexeme, d_key) REFERENCES FUNCTORS(functor, d_key)
FOREIGN KEY(semantic_dependency, ref_d_key) REFERENCES FUNCTORS(functor, d_key) DEFERRABLE INITIALLY DEFERRED
);
/*TODO: with sqlite3.8.0 partial index is supported so a unique index could be created with 'where d_counter'*/
/*create unique index i_depolex_lexeme_d_key on DEPOLEX(lexeme, d_key) where d_counter;*/

/*Maps each syntactic rule to a semantic rule (note: semantic combination rules are divided into different steps due to
technical reasons)*/
create table RULE_TO_RULE_MAP(
parent_symbol varchar(12),/* references SYMBOLS(symbol),*/
head_root_symbol varchar(12),/* references SYMBOLS(symbol),*/
non_head_root_symbol varchar(12),/* references SYMBOLS(symbol),*/
step smallint, /*smallest value: 1*/
failover smallint, /*smallest value: 1; NULL or 0 means end of rule chain. A failover step is only executed if the current step failed (e.g. either symbols or functors are not found)*/
successor smallint, /*smallest value: 1; NULL or 0 means end of rule chain. A successor step is only executed if the current step succeeded*/
main_node_symbol varchar(12),/* references SYMBOLS(symbol),*/
main_node_lexeme varchar(47),
main_lookup_root varchar(1) references ROOT_TYPE(root_type),
main_lookup_subtree_symbol varchar(12),/* references SYMBOLS(symbol),*/
dependent_node_symbol varchar(12),/* references SYMBOLS(symbol),*/
dependent_node_lexeme varchar(47),
dependency_lookup_root varchar(1) references ROOT_TYPE(root_type),
dependency_lookup_subtree_symbol varchar(12),/* references SYMBOLS(symbol),*/
lid varchar(5) references LANGUAGES(lid),/*TODO: check it in coding when reading the table, this was added later so in the code nowhere expects such a field to exist*/
PRIMARY KEY(parent_symbol, head_root_symbol, non_head_root_symbol, step)
FOREIGN KEY(parent_symbol, lid) REFERENCES SYMBOLS(symbol, lid)
FOREIGN KEY(head_root_symbol, lid) REFERENCES SYMBOLS(symbol, lid)
FOREIGN KEY(non_head_root_symbol, lid) REFERENCES SYMBOLS(symbol, lid)
FOREIGN KEY(main_node_symbol, lid) REFERENCES SYMBOLS(symbol, lid)
/*FOREIGN KEY(main_node_lexeme) REFERENCES FUNCTORS(functor) No foreign key check possible as d_key makes functors unique*/
FOREIGN KEY(main_lookup_subtree_symbol, lid) REFERENCES SYMBOLS(symbol, lid)
FOREIGN KEY(dependent_node_symbol, lid) REFERENCES SYMBOLS(symbol, lid)
/*FOREIGN KEY(dependent_node_lexeme) REFERENCES FUNCTORS(functor)  No foreign key check possible as d_key makes functors unique*/
FOREIGN KEY(dependency_lookup_subtree_symbol, lid) REFERENCES SYMBOLS(symbol, lid)
); 

create table LEXICON(
word varchar(256),
lid varchar(5) references LANGUAGES(lid),
gcat varchar(12),
lexeme varchar(47),
PRIMARY KEY(word, lid, gcat)
FOREIGN KEY(gcat, lid) REFERENCES SYMBOLS(symbol, lid) /*TODO: figure out how to refer to GCAT(gcat, lid) to make sure that only terminals are allowed here*/
/*FOREIGN KEY(lexeme) REFERENCES FUNCTORS(functor)*/ /*TODO: figure out, how to connect functors table functor field and lexicon table lexeme field*/
);

create table TAGCONTEXT(/*Extracted tags, just for fast tag search to find the right fcontext*/
model_id text,/*id for the model in which the context was interpreted*/
context_source text,/*user or other source of context*/
session_id text,
timestamp text,
tag_counter smallint,
tag text,
value text,
PRIMARY KEY(model_id,context_source,session_id,timestamp,tag_counter)
);

create table FCONTEXT(
model_id text,/*id for the model in which the context was interpreted*/
context_source text,/*user or other source of context*/
session_id text,
timestamp text,
fcontext text,/*already compiled, interpreted result*/
PRIMARY KEY(model_id,context_source,session_id,timestamp)
);

create table FUNCTOR_DEFS(
functor_id varchar(51),
definition text,
PRIMARY KEY(functor_id)
);

create table FUNCTOR_TAGS(
functor_id varchar(51),
trigger_tag text,
counter smallint,
tag text,
value text,
PRIMARY KEY(functor_id, trigger_tag, counter)
FOREIGN KEY(functor_id) REFERENCES FUNCTOR_DEFS(functor_id)
);

create table FUNCTORS(
functor varchar(47),
d_key smallint,
functor_id varchar(51),
/*ftag_id varchar(51),*/
PRIMARY KEY(functor, d_key)
FOREIGN KEY(functor_id) REFERENCES FUNCTOR_DEFS(functor_id)
/*FOREIGN KEY(ftag_id) REFERENCES FUNCTOR_TAGS(functor_id)*/
);

create table GRAMMAR(
parent_symbol varchar(12),
head_symbol varchar(12),
non_head_symbol varchar(12),
action text,/*if content is in quotes then it is regarded as code, if not then it is regarded as filename*/
PRIMARY KEY(parent_symbol, head_symbol, non_head_symbol)
);
