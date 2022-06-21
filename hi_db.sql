PRAGMA encoding="UTF-8";
PRAGMA foreign_keys = ON;

create table ROOT_TYPE(
root_type varchar(1) primary key /*h:head root, n:non head root*/
);

create table PRECEDENCES(
precedence varchar(12) primary key,
declaration varchar(12)
);

create table LANGUAGES(
lid varchar(5) primary key,
language varchar(128),
head_position smallint, /*0: undefined, 1: head first, 2: head last*/
fst varchar(256)
);

create table GCAT_LID(
gcat varchar(12) not null,
lid varchar(5) references LANGUAGES(lid),
PRIMARY KEY(gcat, lid)
);

create table GCAT(/*Eventually, table for terminal symbols, i.e. to which bison tokens can be assigned*/
gcat varchar(12) not null,
feature varchar(12) not null,
lid varchar(5) references LANGUAGES(lid),
token smallint,/*NULL or '0': don't generate token in bison source, non-NULL: generate token in bison source*/
precedence varchar(12) references PRECEDENCES(precedence),
precedence_level smallint check(precedence_level>=0),
PRIMARY KEY(gcat, feature, lid) /*gcat, feature, lid are all keys as once token literals in bison source will be generated (by concatenating gcat, feature and lid), uniqueness will be granted*/
FOREIGN KEY(gcat, lid) REFERENCES SYMBOLS(symbol, lid)
FOREIGN KEY(feature, lid) REFERENCES SYMBOLS(symbol, lid)
);
/*create unique index i_gcat_lid on GCAT(gcat,lid) where feature='stem' collate nocase;*/

CREATE TRIGGER GCAT_TRIGGER
AFTER INSERT ON GCAT
FOR EACH ROW
BEGIN
INSERT OR IGNORE INTO GCAT_LID(gcat,lid) select gcat,lid from gcat where rowid=last_insert_rowid();
END;

create table SYMBOLS(/*Table for all kinds of symbols: terminals (including gcat features) and non-terminals*/
symbol varchar(12),/*Currently only used to reference from gcat and rule_to_rule_map*/
lid varchar(5) references LANGUAGES(lid),
description varchar(128),
PRIMARY KEY(symbol, lid)
);

/*Handles semantic dependencies like e.g. kick the bucket=kick|1|1|the;kick|1|2|bucket; and so on like look|1|1|up;look|2|1|after;*/
/*That is, it is to store dependencies of one semantic unit (szótári egység)*/
create table DEPOLEX(
lexeme varchar(47),
d_key smallint not null check(d_key>0), /*start value: 1*/
d_counter smallint not null check(d_counter>0), /*start value: 1*/
optional_parent_allowed smallint, /*if true, dependency entry is taken into account as well even if the lexeme was not found as dependency one level above; 0:false, otherwise:true; note that NULL is evaulated as 0*/
d_failover smallint, /*NULL or 0 means end of dependency chain; a failover dependency points to a d_counter (> than current d_counter) and is only executed if the current d_counter dependency check failed*/
d_successor smallint, /*NULL or 0 means end of dependency chain; a successor dependency points to a d_counter (> than current d_counter) and is only executed if the current d_counter dependency check was successful*/
manner smallint,/*0:exactly once, 1:at least once; 2:more than once*/
semantic_dependency varchar(47), /*dependencies must be stored explicitly (which means if a word has no dependencies i.e. can stand on its own,
must be stored with full key entry with NULL semantic_dependecy value), otherwise noone can tell if a functor (word) can stand on its own or only together with other words*/
ref_d_key smallint,/*belongs to the field semantic_dependency in this table*/
PRIMARY KEY(lexeme, d_key, d_counter)
FOREIGN KEY(lexeme, d_key) REFERENCES FUNCTORS(functor, d_key) DEFERRABLE INITIALLY DEFERRED
FOREIGN KEY(semantic_dependency, ref_d_key) REFERENCES FUNCTORS(functor, d_key) DEFERRABLE INITIALLY DEFERRED
);

/*Maps each syntactic rule to a semantic rule (note: semantic combination rules are divided into different steps due to
technical reasons)*/
create table RULE_TO_RULE_MAP(
parent_symbol varchar(12),
head_root_symbol varchar(12),
non_head_root_symbol varchar(12),
step smallint not null check(step>0), /*start value: 1*/
failover smallint, /*smallest value: 1; NULL or 0 means end of rule chain. A failover step is only executed if the current step failed (e.g. either symbols or functors are not found)*/
successor smallint, /*smallest value: 1; NULL or 0 means end of rule chain. A successor step is only executed if the current step succeeded*/
main_node_symbol varchar(12),
main_node_lexeme varchar(47),
main_lookup_root varchar(1) references ROOT_TYPE(root_type),
main_lookup_subtree_symbol varchar(12),
main_set_op smallint check(main_set_op>0 and main_set_op<6),
dependent_node_symbol varchar(12),
dependent_node_lexeme varchar(47),
dependency_lookup_root varchar(1) references ROOT_TYPE(root_type),
dependency_lookup_subtree_symbol varchar(12),
dependent_set_op smallint check(dependent_set_op>0 and dependent_set_op<6),
lid varchar(5) references LANGUAGES(lid),
PRIMARY KEY(parent_symbol, head_root_symbol, non_head_root_symbol, step)
FOREIGN KEY(parent_symbol, lid) REFERENCES SYMBOLS(symbol, lid)
FOREIGN KEY(head_root_symbol, lid) REFERENCES SYMBOLS(symbol, lid)
FOREIGN KEY(non_head_root_symbol, lid) REFERENCES SYMBOLS(symbol, lid)
FOREIGN KEY(main_node_symbol, lid) REFERENCES SYMBOLS(symbol, lid)
FOREIGN KEY(main_node_lexeme) REFERENCES FUNCTOR_DECL(functor) DEFERRABLE INITIALLY DEFERRED
FOREIGN KEY(main_lookup_subtree_symbol, lid) REFERENCES SYMBOLS(symbol, lid)
FOREIGN KEY(dependent_node_symbol, lid) REFERENCES SYMBOLS(symbol, lid)
FOREIGN KEY(dependent_node_lexeme) REFERENCES FUNCTOR_DECL(functor) DEFERRABLE INITIALLY DEFERRED
FOREIGN KEY(dependency_lookup_subtree_symbol, lid) REFERENCES SYMBOLS(symbol, lid)
);

create table LEXICON(
word varchar(256),
lid varchar(5) references LANGUAGES(lid) DEFERRABLE INITIALLY DEFERRED,
gcat varchar(12),
lexeme varchar(47),
PRIMARY KEY(word, lid, gcat)
FOREIGN KEY(lexeme) REFERENCES FUNCTOR_DECL(functor) DEFERRABLE INITIALLY DEFERRED
FOREIGN KEY(gcat, lid) REFERENCES GCAT_LID(gcat, lid) DEFERRABLE INITIALLY DEFERRED
);


/*create table TAGCONTEXT(*//*Extracted tags, just for fast tag search to find the right fcontext*/
/*model_id text,*//*id for the model in which the context was interpreted*/
/*context_source text,*//*user or other source of context*/
/*session_id text,*/
/*timestamp text,*/
/*tag_counter smallint,*/
/*tag text,*/
/*value text,*/
/*PRIMARY KEY(model_id,context_source,session_id,timestamp,tag_counter)*/
/*);*/

/*TODO:add language*/
create table ANALYSES(
source text,/*user name or any other source of the utterance*/
timestamp int,/*epoch*/
sentence text,
rank smallint,/*nr of constants, the smaller the better*/
a_counter smallint,
analysis text,
PRIMARY KEY(source,timestamp,sentence,rank,a_counter)
);

/*TODO:add language*/
create table FAILED_ANALYSES(
source text,/*user name or any other source of the utterance*/
timestamp int,/*epoch*/
sentence text,
analysis text,
PRIMARY KEY(source,timestamp,sentence)
);

create table FUNCTOR_DECL(
functor varchar(47),
PRIMARY KEY(functor)
);

create table FUNCTOR_IDS(
functor_id varchar(51),
PRIMARY KEY(functor_id)
);

create table FUNCTOR_DEFS(
functor_id varchar(51),
tlid varchar(5),
imp_counter smallint not null check(imp_counter>0),/*start value: 1*/
definition text,
PRIMARY KEY(functor_id, tlid)
);

CREATE TRIGGER FUNCTOR_DEFS_TRIGGER
AFTER INSERT ON FUNCTOR_DEFS
FOR EACH ROW
BEGIN
INSERT OR IGNORE INTO FUNCTOR_IDS(functor_id) select functor_id from functor_defs where rowid=last_insert_rowid();
END;

create table FUNCTOR_TAGS(
functor varchar(47),
d_key smallint,
trigger_tag text,/*serves as condition: if such a tag was created during the interpretation it triggers taking into account (during transcription)
the tag-value pairs of the entry e.g. grammatical mood of the verb (imperative, interrogative, indicative),
since different tag-value pairs may belong to an indicative mood and an imperative mood as in case of
"a directory lists files" and "list files"*/
counter smallint not null check(counter>0),/*start value: 1*/
tag text,/*if the trigger_tag is empty, tag-value pairs are added unconditionally*/
value text,
PRIMARY KEY(functor, d_key, trigger_tag, counter)
FOREIGN KEY(functor, d_key) REFERENCES FUNCTORS(functor, d_key) DEFERRABLE INITIALLY DEFERRED
);

create table FUNCTORS(
functor varchar(47),
d_key smallint not null check(d_key>0),/*start value: 1*/
functor_id varchar(51),
PRIMARY KEY(functor, d_key)
FOREIGN KEY(functor_id) REFERENCES FUNCTOR_IDS(functor_id) DEFERRABLE INITIALLY DEFERRED
);

CREATE TRIGGER FUNCTORS_TRIGGER
AFTER INSERT ON FUNCTORS
FOR EACH ROW
BEGIN
INSERT OR IGNORE INTO FUNCTOR_DECL(functor) select functor from functors where rowid=last_insert_rowid();
END;

create table GRAMMAR(
lid varchar(5) references LANGUAGES(lid) DEFERRABLE INITIALLY DEFERRED,
parent_symbol varchar(12) not null check(length(parent_symbol)>0),
head_symbol varchar(12) not null check(length(head_symbol)>0),
non_head_symbol varchar(12),
precedence varchar(12),
action text,/*if content is in quotes then it is regarded as code, if not then it is regarded as filename*/
PRIMARY KEY(lid, parent_symbol, head_symbol, non_head_symbol)
FOREIGN KEY(parent_symbol, lid) REFERENCES SYMBOLS(symbol, lid)
FOREIGN KEY(head_symbol, lid) REFERENCES SYMBOLS(symbol, lid)
FOREIGN KEY(non_head_symbol, lid) REFERENCES SYMBOLS(symbol, lid)
FOREIGN KEY(precedence, lid) REFERENCES SYMBOLS(symbol, lid) /*Reference to GCAT is too strict as it's not a must for a precedence symbol to match a token*/
);

create table SETTINGS(
key text primary key,
value text
);

create table ANALYSES_DEPS(
source text,
timestamp int,
sentence text,
rank smallint,
a_counter smallint,
mood text,
function text,
counter smallint,
level smallint,
word text,
lexeme text,
d_key smallint,
d_counter smallint,
dependency text,
ref_d_key smallint,
tags text,
c_value text,
PRIMARY KEY(source,timestamp,sentence,rank,a_counter,mood,function)/*key contains that of the analyses table to be able to make match*/
);
