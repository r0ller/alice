PRAGMA foreign_keys = ON;

create table DEFTYPE(
deftype smallint primary key /*0:function definition, 1:option definition*/
);

create table ROOT_TYPE(
root_type varchar(1) primary key /*h:head root, n:non head root*/
);

create table LANGUAGES(
lid varchar(3) primary key,
language varchar(128),
head_position smallint /*0: undefined e.g. programming languages like bash, 1: head first, 2: head last*/
);

create table GCAT(/*Eventually, table for terminal symbols, i.e. to which yacc tokens can be assigned*/
gcat varchar(12), /*references SYMBOLS(symbol),*/
feature varchar(12), /*references SYMBOLS(symbol),*/
lid varchar(3) references LANGUAGES(lid),
token smallint,
description varchar(128),
PRIMARY KEY(gcat, feature, lid, token) /*gcat, feature, lid, token are all keys as once token literals in yacc source will be generated (by concatenating gcat, feature and lid), uniqueness will be granted*/
FOREIGN KEY(gcat, lid) REFERENCES SYMBOLS(symbol, lid)
FOREIGN KEY(feature, lid) REFERENCES SYMBOLS(symbol, lid)
);
/*create unique index i_gcat_lid on GCAT(gcat, lid);*/

create table SYMBOLS(/*Table for all kinds of symbols: terminals (including gcat features) and non-terminals*/
symbol varchar(12),/*Currently only used to reference from gcat and rule_to_rule_map*/
lid varchar(3) references LANGUAGES(lid),
PRIMARY KEY(symbol, lid)
);

/*See commenting reasons after the RELATION_FUNCTORS table
create table CARDINALITY(
cid varchar(2) primary key,
description varchar(32)
);

create table XLINKS(//eXternal Links
xid smallint primary key,
xlink varchar(32) //association, composition, aggregation
);
*/

create table LEXEMES(
lexeme varchar(47), /*TODO: Connect lexeme with the concatenation of LEXICON(lexeme,lid,gcat)*/
d_key smallint, /*smallest value: 1*/
PRIMARY KEY(lexeme, d_key)
);

/*handles semantic dependencies like e.g. kick the bucket=kick|1|1|the;kick|1|2|bucket; and so on like look|1|1|up;look|2|1|after;*/
/*It also stores semantic dependencies of lexemes and morphemes like: k�ldd el=k�ld|1|1|d;k�ld|1|2|el;*/
/*That is, it is to store dependencies within one semantic unit (szótári egység)*/
/*Does NOT contain dependencies with modifiers i.e. entries that fit in ATTRIBUTE_FUNCTORS or ADVERB_FUNCTORS like: yellow stone, play slowly, etc.*/
create table DEPOLEX(
lexeme varchar(47),
d_key smallint, /*smallest value: 1*/
d_counter smallint, /*smallest value: 1*/
manner smallint,/*0-absent, 1-mandatory, 2-optional*/
semantic_dependency varchar(47), /*dependencies must be stored explicitly (which means if a word has no dependencies i.e. can stand on its own,
must be stored with full key entry with NULL semantic_dependecy value), otherwise noone can tell if a functor (word) can stand on its own or only together with other words*/
ref_d_key smallint,/*belongs to the field semantic_dependency in this table*/
functor_d_key smallint, /*d_key of functor which identifies the corresponding entry in the functor table with which the dependency is paired*/
PRIMARY KEY(lexeme, d_key, d_counter)
FOREIGN KEY(lexeme, d_key) REFERENCES LEXEMES(lexeme, d_key)
FOREIGN KEY(semantic_dependency, ref_d_key) REFERENCES LEXEMES(lexeme, d_key) DEFERRABLE INITIALLY DEFERRED
);
/*TODO: with sqlite3.8.0 partial index is supported so a unique index could be created with 'where d_counter'*/
/*create unique index i_depolex_lexeme_d_key on DEPOLEX(lexeme, d_key) where d_counter;*/

/*Maps each syntactic rule to a semantic rule (note: semantic combination rules are divided into different steps due to
technical reasons)*/
create table RULE_TO_RULE_MAP(
parent_symbol varchar(12),/* references SYMBOLS(symbol),*/
head_root_symbol varchar(12),/* references SYMBOLS(symbol),*/
non_head_root_symbol varchar(12),/* references SYMBOLS(symbol),*/
step smallint,
main_node_symbol varchar(12),/* references SYMBOLS(symbol),*/
main_lookup_root varchar(1) references ROOT_TYPE(root_type), 
dependent_node_symbol varchar(12),/* references SYMBOLS(symbol),*/
dependency_lookup_root varchar(1) references ROOT_TYPE(root_type), 
lid varchar(3) references LANGUAGES(lid),/*TODO: check it in coding when reading the table, this was added later so in the code nowhere expects such a field to exist*/
PRIMARY KEY(parent_symbol, head_root_symbol, non_head_root_symbol, step)
FOREIGN KEY(parent_symbol, lid) REFERENCES SYMBOLS(symbol, lid)
FOREIGN KEY(head_root_symbol, lid) REFERENCES SYMBOLS(symbol, lid)
FOREIGN KEY(non_head_root_symbol, lid) REFERENCES SYMBOLS(symbol, lid)
FOREIGN KEY(main_node_symbol, lid) REFERENCES SYMBOLS(symbol, lid)
FOREIGN KEY(dependent_node_symbol, lid) REFERENCES SYMBOLS(symbol, lid)
); 

create table LEXICON(
word varchar(256),
lid varchar(3) references LANGUAGES(lid),
gcat varchar(12),
lexeme varchar(32),
PRIMARY KEY(word, lid, gcat)
FOREIGN KEY(gcat, lid) REFERENCES SYMBOLS(symbol, lid) /*TODO: figure out how to refer to GCAT(gcat, lid) to make sure that only terminals are allowed here*/
);

create table FUNCTORS(
functor_id int,
definition_type smallint references DEFTYPE(deftype),
definition text,
PRIMARY KEY(functor_id)
);

create table ENTITIES(
entity varchar(47),
d_key smallint,
is_a_entity varchar(47),
is_a_d_key smallint,
PRIMARY KEY(entity, d_key)
FOREIGN KEY(entity, d_key) REFERENCES LEXEMES(lexeme, d_key)
FOREIGN KEY(is_a_entity, is_a_d_key) REFERENCES ENTITIES(entity, d_key) DEFERRABLE INITIALLY DEFERRED
);
create unique index i_entities_entity on ENTITIES(entity);

create table ENTITY_FUNCTORS(
functor varchar(47),
d_key smallint,
io_type varchar(47) references ENTITIES(entity),
functor_id int,
PRIMARY KEY(functor, d_key)
FOREIGN KEY(functor, d_key) REFERENCES LEXEMES(lexeme, d_key)
);

/*Semantic tree for adjectives e.g. 'red','blue',etc. are derived from 'coloured'*/
create table ATTRIBUTES(
attribute varchar(47),
d_key smallint,
is_attribute varchar(47),
is_d_key smallint,
PRIMARY KEY(attribute, d_key)
FOREIGN KEY(attribute, d_key) REFERENCES LEXEMES(lexeme, d_key)
FOREIGN KEY(is_attribute, is_d_key) REFERENCES ATTRIBUTES(attribute, d_key) DEFERRABLE INITIALLY DEFERRED
);
create unique index i_attributes_attribute on ATTRIBUTES(attribute);

create table ATTRIBUTE_FUNCTORS(
functor varchar(47),
d_key smallint,
io_type varchar(47) references ENTITIES(entity),
functor_id int,
PRIMARY KEY(functor, d_key, io_type)
FOREIGN KEY(functor, d_key) REFERENCES LEXEMES(lexeme, d_key)
);

/*
As for attributes, the table scheme above would solve the problem posed by phrases: 'long files'<>'long directories',
where long needs to be interpreted in a different way. BUT: what about words that are not found in any tree?
Like e.g. 'dangerous file'? Any file can be dangerous, so not general but specific entity-attribute realtions should
be stored in such cases like 'dangerous file', 'dangerous directory', etc. which is not a real solution.
So no solution has been invented yet to handle such general relations...
*/

create table ADVERBS(/*Semantic tree for adverbs*/
adverb varchar(47),
d_key smallint,/*dependency counter: 1,2,3...*/
means_adverb varchar(47),
means_d_key smallint,
PRIMARY KEY(adverb, d_key)
FOREIGN KEY(adverb, d_key) REFERENCES LEXEMES(lexeme, d_key)
FOREIGN KEY(means_adverb, means_d_key) REFERENCES ADVERBS(adverb, d_key) DEFERRABLE INITIALLY DEFERRED
);
create unique index i_adverbs_adverb on ADVERBS(adverb);

create table ADVERB_FUNCTORS(
functor varchar(47),
d_key smallint,
relation_functor varchar(47),
relation_d_key smallint,
functor_id int,
PRIMARY KEY(functor, d_key, relation_functor, relation_d_key)
FOREIGN KEY(functor, d_key) REFERENCES LEXEMES(lexeme, d_key)
FOREIGN KEY(relation_functor, relation_d_key) REFERENCES RELATION_FUNCTORS(functor, d_key)
);

create table RELATIONS(/*Semantic tree for verbs e.g. 'fly' entails 'move'*/
relation varchar(47),
d_key smallint,
entails_relation varchar(47),
entails_d_key smallint,
PRIMARY KEY(relation, d_key)
FOREIGN KEY(relation, d_key) REFERENCES LEXEMES(lexeme, d_key)
FOREIGN KEY(entails_relation, entails_d_key) REFERENCES RELATIONS(relation, d_key) DEFERRABLE INITIALLY DEFERRED
);
create unique index i_relations_relation on RELATIONS(relation);

create table RELATION_FUNCTORS(
functor varchar(47),
d_key smallint,
functor_id int,
PRIMARY KEY(functor, d_key)
FOREIGN KEY(functor, d_key) REFERENCES LEXEMES(lexeme, d_key)
);

/*Taken out from RELATION_FUNCTORS because it seems better to have a separate features tables like: part_whole_relations, etc. Then a mapping table could be
introduced for the functors to map them to their features like: <functor>, <feature_table_name>.

part_role varchar(47) references ENTITIES(entity),//defines who takes the part role in the relation of entity-argument, the other one is then considered taking the whole role
p_cardinality varchar(2) references CARDINALITY(cid),//part cardinality
w_cardinality varchar(2) references CARDINALITY(cid),//whole cardinality
xlink smallint references XLINKS(xid), 
*/

BEGIN;
insert into DEFTYPE values('0');
insert into DEFTYPE values('1');

insert into ROOT_TYPE values('H');
insert into ROOT_TYPE values('N');

insert into LANGUAGES values('HUN', 'Hungarian', '1');
insert into LANGUAGES values('ENG', 'English', '1');
insert into LANGUAGES values('BSH', 'BASH', '0');
insert into LANGUAGES values('WPS', 'Windows PowerShell', '0');

/*TODO: remove ENG_ prefix later from non-terminals*/
insert into SYMBOLS values('A', 'ENG');
insert into SYMBOLS values('ADV', 'ENG');
insert into SYMBOLS values('DET', 'ENG');
insert into SYMBOLS values('N', 'ENG');
insert into SYMBOLS values('ENG_NP', 'ENG');
insert into SYMBOLS values('ENG_PP', 'ENG');
insert into SYMBOLS values('Stem', 'ENG');
insert into SYMBOLS values('Pl', 'ENG');
insert into SYMBOLS values('Sg', 'ENG');
insert into SYMBOLS values('PREP', 'ENG');
insert into SYMBOLS values('QPRO', 'ENG');
insert into SYMBOLS values('V', 'ENG');
insert into SYMBOLS values('ENG_VBAR1', 'ENG');
insert into SYMBOLS values('ENG_VBAR2', 'ENG');


/*Constant has hardcoded token value: 1, so all other tokens must be greater*/
/*TODO: Think over if the feature field for all gcats shall at least be 'Stem' or not?
For exmaple, DET is considered as well to have a stem? How is it analysed by Foma?*/
insert into GCAT values('A', NULL, 'ENG', '1', 'Adjective');
insert into GCAT values('ADV', NULL, 'ENG', '2', 'Adverb');
insert into GCAT values('DET', NULL, 'ENG', '3', 'Determiner');
insert into GCAT values('N', NULL, 'ENG', '4', 'Noun');
insert into GCAT values('N', 'Stem', 'ENG', '5', 'Noun');
insert into GCAT values('N', 'Pl', 'ENG', '6', 'Plural Noun');
insert into GCAT values('N', 'Sg', 'ENG', '7', 'Singular Noun');
insert into GCAT values('PREP', NULL, 'ENG', '8', 'Preposition');
insert into GCAT values('QPRO', NULL, 'ENG', '9', 'Quantifier Pronoun');
insert into GCAT values('V', 'Stem', 'ENG', '10', 'Verb');

/*
insert into CARDINALITY values('01', '0..1');
insert into CARDINALITY values('11', '1..1');
insert into CARDINALITY values('0N', '0..N');
insert into CARDINALITY values('1N', '1..N');

insert into XLINKS values('0', 'Association');
insert into XLINKS values('1', 'Aggregation');
insert into XLINKS values('2', 'Composition');//Composition means 'life cycle dependency'!
*/

insert into LEXEMES values('ACTENGV', '1');
insert into LEXEMES values('ALLENGQPRO', '1');
insert into LEXEMES values('CHANGEENGV', '1');
insert into LEXEMES values('COPYENGV', '1');
insert into LEXEMES values('CREATEENGV', '1');
insert into LEXEMES values('DELETEENGV', '1');
insert into LEXEMES values('DIRECTORYENGN', '1');
insert into LEXEMES values('ENTITYENGN', '1');
insert into LEXEMES values('EXECUTABLEENGA', '1');
insert into LEXEMES values('FILEENGN', '1');
insert into LEXEMES values('FROMENGPREP', '1');
insert into LEXEMES values('INENGPREP', '1');
insert into LEXEMES values('LISTENGV', '1');
insert into LEXEMES values('LISTENGV', '2');
insert into LEXEMES values('MAKEENGV', '1');
insert into LEXEMES values('MOVEENGV', '1');
insert into LEXEMES values('NON-EXECUTABLEENGA', '1');
insert into LEXEMES values('REMOVEENGV', '1');
insert into LEXEMES values('TOENGPREP', '1');
insert into LEXEMES values('SHUTENGV', '1');
insert into LEXEMES values('DOWNENGADV', '1');

/*no value in the semantic_dependency field means no dependency*/
insert into DEPOLEX values('ACTENGV', '1', '1', '0', NULL, NULL, '1');
insert into DEPOLEX values('ALLENGQPRO', '1', '1', '0', NULL, NULL, '1');
insert into DEPOLEX values('CHANGEENGV', '1', '1', '0', NULL, NULL, '1');
insert into DEPOLEX values('COPYENGV', '1', '1', '0', NULL, NULL, '1');
insert into DEPOLEX values('CREATEENGV', '1', '1', '0', NULL, NULL, '1');
insert into DEPOLEX values('DELETEENGV', '1', '1', '0', NULL, NULL, '1');
insert into DEPOLEX values('DIRECTORYENGN', '1', '1', '0', NULL, NULL, '1');
insert into DEPOLEX values('ENTITYENGN', '1', '1', '0', NULL, NULL, '1');
insert into DEPOLEX values('EXECUTABLEENGA', '1', '1', '0', NULL, NULL, '1');
insert into DEPOLEX values('FILEENGN', '1', '1', '0', NULL, NULL, '1');
insert into DEPOLEX values('FROMENGPREP', '1', '1', '0', NULL, NULL, '1');
insert into DEPOLEX values('INENGPREP', '1', '1', '1', 'DIRECTORYENGN', '1', '1');
insert into DEPOLEX values('LISTENGV', '1', '1', '1', 'FILEENGN', '1', '1');
insert into DEPOLEX values('LISTENGV', '1', '2', '2', 'INENGPREP', '1', '1');
insert into DEPOLEX values('LISTENGV', '2', '1', '1', 'DIRECTORYENGN', '1', '1');
insert into DEPOLEX values('LISTENGV', '2', '2', '2', 'INENGPREP', '1', '1');
insert into DEPOLEX values('MAKEENGV', '1', '1', '0', NULL, NULL, '1');
insert into DEPOLEX values('MOVEENGV', '1', '1', '0', NULL, NULL, '1');
insert into DEPOLEX values('NON-EXECUTABLEENGA', '1', '1', '0', NULL, NULL, '1');
insert into DEPOLEX values('REMOVEENGV', '1', '1', '0', NULL, NULL, '1');
insert into DEPOLEX values('TOENGPREP', '1', '1', '0', NULL, NULL, '1');
insert into DEPOLEX values('SHUTENGV', '1', '1', '0', 'DOWNENGADV', '1', '1');
insert into DEPOLEX values('DOWNENGADV', '1', '1', '0', NULL, NULL, '1');

insert into RULE_TO_RULE_MAP values( 'ENG_VBAR1', 'V', 'ENG_NP', '1', 'V', 'H', 'N', 'N', 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VBAR2', 'ENG_VBAR1', 'ENG_PP', '1', 'V', 'H', 'PREP', 'N', 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_PP', 'PREP', 'ENG_NP', '1', 'PREP', 'H', 'N', 'N', 'ENG');

insert into LEXICON values('list', 'ENG', 'V', 'LIST');
insert into LEXICON values('copy', 'ENG', 'V', 'COPY');
insert into LEXICON values('directory', 'ENG', 'N', 'DIRECTORY');
insert into LEXICON values('directories', 'ENG', 'N', 'DIRECTORY');
insert into LEXICON values('executable', 'ENG', 'A', 'EXECUTABLE');
insert into LEXICON values('non-executable', 'ENG', 'A', 'NON-EXECUTABLE');
insert into LEXICON values('all', 'ENG', 'QPRO', 'ALL');
insert into LEXICON values('file', 'ENG', 'N', 'FILE');
insert into LEXICON values('files', 'ENG', 'N', 'FILE');
insert into LEXICON values('to', 'ENG', 'PREP', 'TO');
insert into LEXICON values('remove', 'ENG', 'V', 'REMOVE');
insert into LEXICON values('delete', 'ENG', 'V', 'DELETE');
insert into LEXICON values('from', 'ENG', 'PREP', 'FROM');
insert into LEXICON values('change', 'ENG', 'V', 'CHANGE');
insert into LEXICON values('move', 'ENG', 'V', 'MOVE');
insert into LEXICON values('in', 'ENG', 'PREP', 'IN');
insert into LEXICON values('make', 'ENG', 'V', 'MAKE');
insert into LEXICON values('shut', 'ENG', 'V', 'SHUT');
insert into LEXICON values('down', 'ENG', 'ADV', 'DOWN');

/*Remove attributives from ENTITIES like executable,etc., leave only pure nouns*/
insert into ENTITIES values('ENTITYENGN', '1', 'ENTITYENGN', '1');
insert into ENTITIES values('FILEENGN', '1', 'ENTITYENGN', '1');
insert into ENTITIES values('DIRECTORYENGN', '1', 'FILEENGN', '1');

insert into RELATIONS values('ACTENGV', '1', 'ACTENGV', '1');
insert into RELATIONS values('CHANGEENGV', '1', 'ACTENGV', '1');
insert into RELATIONS values('CREATEENGV', '1', 'ACTENGV', '1');
insert into RELATIONS values('MAKEENGV', '1', 'CREATEENGV', '1');
insert into RELATIONS values('COPYENGV', '1', 'CREATEENGV', '1');
insert into RELATIONS values('LISTENGV', '1', 'ACTENGV', '1');

insert into RELATION_FUNCTORS values('LISTENGV', '1', NULL);
insert into RELATION_FUNCTORS values('LISTENGV', '2', NULL);
COMMIT;

/*Old relation functor definitions for later reference:
insert into RELATIONS values('LIST', '', '', 'options=''-maxdepth 1'';find $source$delim$constant $options;constant=;');
insert into RELATIONS values('LIST', '', 'DIRECTORY', 'export source;export delim;export constant;export tests;export options=''-maxdepth 1'';echo -e ''if [ -z $constant ]\nthen\nfind $source$delim$constant $options $tests\nelse\nfind $source$delim$constant $options\nfi'' 1>command;chmod a+x command;./command;constant=;');
insert into RELATIONS values('LIST', '', 'FILE', 'options=''-maxdepth 1'';find $source$delim$constant $options $tests;constant=;');
insert into RELATIONS values('COPY', '', '', 'cp -f $source$delim$constant $target;constant=;');
insert into RELATIONS values('COPY', '', 'FILE', 'export source;export delim;export constant;export tests;export options=''-maxdepth 1'';export target;echo -e ''files="$(find $source$delim$constant $options $tests)";\nfor f in $files\ndo\ncp -f $f $target\ndone'' 1>command;chmod a+x command;./command;constant=;');
insert into RELATIONS values('COPY', '', 'DIRECTORY', 'cp -f $source$delim$constant $target;constant=;');
insert into RELATIONS values('REMOVE', '', '', 'rm $source$delim$constant;constant=;');
insert into RELATIONS values('REMOVE', '', 'DIRECTORY', 'rmdir $source$delim$constant;constant=;');
insert into RELATIONS values('REMOVE', '', 'FILE', 'find $source$delim$constant $options $tests -exec rm ''{}'' +;constant=;');
insert into RELATIONS values('DELETE', '', '', 'rm $source$delim$constant;constant=;');
insert into RELATIONS values('DELETE', '', 'DIRECTORY', 'rmdir $source$delim$constant;constant=;');
insert into RELATIONS values('DELETE', '', 'FILE', 'find $source$delim$constant $options $tests -exec rm ''{}'' +;constant=;');
insert into RELATIONS values('CHANGE', '', 'DIRECTORY', 'source=$constant;constant=;');
insert into RELATIONS values('MAKE', '', 'DIRECTORY', 'mkdir $target$delim$constant;constant=;');
insert into RELATIONS values('MOVE', '', '', 'mv -f $source$delim$constant $target;constant=;');
insert into RELATIONS values('MOVE', '', 'DIRECTORY', 'mv -f $source$delim$constant $target;constant=;');
insert into RELATIONS values('MOVE', '', 'FILE', 'export source;export delim;export constant;export tests;export options=''-maxdepth 1'';export target;echo -e ''files="$(find $source$delim$constant $options $tests)";\nfor f in $files\ndo\nmv -f $f $target\ndone'' 1>command;chmod a+x command;./command;constant=;');
insert into RELATIONS values('LIST', 'TO', 'FILE', 'target=/dev/stdout;');
insert into RELATIONS values('LIST', 'IN', 'DIRECTORY', 'source=.;delim=/;');
insert into RELATIONS values('COPY', 'FROM', 'DIRECTORY', 'source=.;delim=/;');
insert into RELATIONS values('COPY', 'TO', 'DIRECTORY', 'target=.;');
insert into RELATIONS values('REMOVE', 'FROM', 'DIRECTORY', 'source=.;delim=/;');
insert into RELATIONS values('DELETE', 'FROM', 'DIRECTORY', 'source=.;delim=/;');
insert into RELATIONS values('CHANGE', 'TO', 'DIRECTORY', 'source=$constant;');
insert into RELATIONS values('MOVE', 'FROM', 'DIRECTORY', 'source=.;delim=/;');
insert into RELATIONS values('MOVE', 'TO', 'DIRECTORY', 'target=.;');
insert into RELATIONS values('MAKE', 'IN', 'DIRECTORY', 'target=.;delim=/;');
*/
