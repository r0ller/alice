BEGIN;
/*
insert into DEFTYPE values('0');
insert into DEFTYPE values('1');
*/

insert into ROOT_TYPE values('H');
insert into ROOT_TYPE values('N');

insert into LANGUAGES values('HUN', 'Hungarian', '1', 'magyar.fst');
insert into LANGUAGES values('ENG', 'English', '1', 'english.fst');

/*TODO: remove ENG_ prefix later from non-terminals*/
insert into SYMBOLS values('A', 'ENG', 'Adjective');
insert into SYMBOLS values('ADV', 'ENG', 'Adverb');
insert into SYMBOLS values('CON', 'ENG', 'Constant');
insert into SYMBOLS values('DET', 'ENG', 'Determiner');
insert into SYMBOLS values('N', 'ENG', 'Noun');
insert into SYMBOLS values('ENG_VP', 'ENG', 'Verb Phrase');
insert into SYMBOLS values('ENG_NP', 'ENG', 'Noun Phrase');
insert into SYMBOLS values('ENG_CNP', 'ENG', 'Common Noun Phrase');
insert into SYMBOLS values('ENG_PP', 'ENG', 'Prepositional Phrase');
insert into SYMBOLS values('Stem', 'ENG', 'Stem');
insert into SYMBOLS values('Pl', 'ENG', 'Plural');
insert into SYMBOLS values('Sg', 'ENG', 'Singular');
insert into SYMBOLS values('PREP', 'ENG', 'Preposition');
insert into SYMBOLS values('QPRO', 'ENG', 'Quantifier Pronoun');
insert into SYMBOLS values('V', 'ENG', 'Verb');
insert into SYMBOLS values('ENG_VBAR1', 'ENG', 'Intermediate Verb Pharse');
insert into SYMBOLS values('ENG_VBAR2', 'ENG', 'Intermediate Verb Pharse');
insert into SYMBOLS values('ENG_VBAR3', 'ENG', 'Intermediate Verb Pharse');
insert into SYMBOLS values('RPRO', 'ENG', 'Relative Pronoun');
insert into SYMBOLS values('Relative', 'ENG', 'Relativizer feature');
insert into SYMBOLS values('Aux', 'ENG', 'Auxiliary');
insert into SYMBOLS values('ENG_RC', 'ENG', 'Relative Clause');
insert into SYMBOLS values('ENG_IVP', 'ENG', 'Incomplete Verb Phrase');
insert into SYMBOLS values('ENG_V', 'ENG', 'Verb');
insert into SYMBOLS values('ENG_TP', 'ENG', 'Tense Phrase');
insert into SYMBOLS values('ENG_RPRO', 'ENG', 'Relative Pronoun');
insert into SYMBOLS values('ENG_NV', 'ENG', 'Negated Verb');
insert into SYMBOLS values('NEG', 'ENG', 'Negation');
insert into SYMBOLS values('RCV', 'ENG', 'Relative Clause Verb');

/*Constant has hardcoded token value 1 in the yacc source so to avoid collision, the values here are increased
by 1 during runtime; Entries with NULL value for token are not to be generated in the yacc source.*/
/*TODO: Think over if the feature field for all gcats shall at least be 'Stem' or not?
For exmaple, DET is considered as well to have a stem? How is it analysed by Foma?*/
insert into GCAT values('CON', NULL, 'ENG', '0');/*Plays role only when checking for terminal symbols*/
insert into GCAT values('A', 'Stem', 'ENG', '1');
insert into GCAT values('ADV', NULL, 'ENG', '2');
insert into GCAT values('DET', NULL, 'ENG', '3');
insert into GCAT values('N', 'Stem', 'ENG', '4');
insert into GCAT values('N', 'Pl', 'ENG', '5');
insert into GCAT values('N', 'Sg', 'ENG', '6');
insert into GCAT values('PREP', NULL, 'ENG', '7');
insert into GCAT values('QPRO', NULL, 'ENG', '8');
insert into GCAT values('V', 'Stem', 'ENG', '9');
insert into GCAT values('V', 'Aux', 'ENG', '10');
insert into GCAT values('V', 'RCV', 'ENG', NULL);
insert into GCAT values('V', 'Pl', 'ENG', NULL);
insert into GCAT values('RPRO', NULL, 'ENG', '11');
insert into GCAT values('RPRO', 'Relative', 'ENG', '12');
insert into GCAT values('NEG', 'Stem', 'ENG', '13');

/*
insert into CARDINALITY values('01', '0..1');
insert into CARDINALITY values('11', '1..1');
insert into CARDINALITY values('0N', '0..N');
insert into CARDINALITY values('1N', '1..N');

insert into XLINKS values('0', 'Association');
insert into XLINKS values('1', 'Aggregation');
insert into XLINKS values('2', 'Composition');//Composition means 'life cycle dependency'!
*/
insert into FUNCTOR_DEFS values('LISTENGV_1', NULL);
insert into FUNCTOR_DEFS values('FILEENGN_1', NULL);
insert into FUNCTOR_DEFS values('INENGPREP_1', NULL);
insert into FUNCTOR_DEFS values('BEENGV_1', NULL);
insert into FUNCTOR_DEFS values('DIRECTORYENGN_1', NULL);

insert into FUNCTORS values('CON', '1', NULL);
insert into FUNCTORS values('INENGPREP', '1', 'INENGPREP_1');
insert into FUNCTORS values('FROMENGPREP', '1', 'FROMENGPREP_1');
insert into FUNCTORS values('LISTENGV', '1', 'LISTENGV_1');
insert into FUNCTORS values('LISTENGV', '2', 'LISTENGV_2');
insert into FUNCTORS values('THATENGRPRO', '1', NULL);
insert into FUNCTORS values('FILEENGN', '1', 'FILEENGN_1');
insert into FUNCTORS values('FILEENGN', '2', 'FILEENGN_2');
insert into FUNCTORS values('DIRECTORYENGN', '1', 'DIRECTORYENGN_1');
insert into FUNCTORS values('BEENGV', '1', 'BEENGV_1');
insert into FUNCTORS values('NOTENGNEG', '1', 'NOTENGNEG_1');
insert into FUNCTORS values('EXECUTABLEENGA', '1', 'EXECUTABLEENGA_1');

insert into RULE_TO_RULE_MAP values( 'ENG_VBAR1', 'ENG_V', 'ENG_NP', '1', '2', NULL, 'RCV',  NULL, 'H', NULL, NULL, NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VBAR1', 'ENG_V', 'ENG_NP', '2', '3', '4', 'N', NULL, 'N', NULL, 'CON', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VBAR1', 'ENG_V', 'ENG_NP', '3', '4', NULL, 'V', NULL, 'H', NULL, 'CON', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VBAR1', 'ENG_V', 'ENG_NP', '4', NULL, '5', 'V', NULL, 'H', NULL, 'N', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VBAR1', 'ENG_V', 'ENG_NP', '5', '5', '6', NULL, NULL, NULL, NULL, 'Sg', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VBAR1', 'ENG_V', 'ENG_NP', '6', '7', NULL, NULL, NULL, NULL, NULL, 'N', 'FILEENGN', 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VBAR1', 'ENG_V', 'ENG_NP', '7', '7', '8', NULL, NULL, NULL, NULL, 'N', 'DIRECTORYENGN', 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VBAR1', 'ENG_V', 'ENG_NP', '8', NULL, '8', NULL, NULL, NULL, NULL, 'CON', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VBAR2', 'ENG_VBAR1', 'ENG_PP', '1', NULL, NULL, 'V', NULL, 'H', NULL, 'PREP', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_CNP', 'A', 'ENG_CNP', '1', NULL, NULL, 'A', NULL, 'H', NULL, 'N', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_PP', 'PREP', 'ENG_NP', '1', '2', '3', 'PREP', NULL, 'H', NULL, 'N', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_PP', 'PREP', 'ENG_NP', '2', NULL, NULL, 'PREP', NULL, 'H', NULL, 'CON', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_PP', 'PREP', 'ENG_NP', '3', NULL, NULL, 'N', NULL, 'N', NULL, 'CON', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_VBAR1', 'ENG_RC', '1', NULL, '2', 'N', NULL, 'H', NULL, 'RPRO', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_VBAR1', 'ENG_RC', '2', NULL, '3', 'RCV', NULL, 'N', NULL, NULL, NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_VBAR1', 'ENG_RC', '3', NULL, NULL, 'RPRO', NULL, 'N', NULL, 'V', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_VBAR2', 'ENG_RC', '1', NULL, '2', 'N', NULL, 'H', 'ENG_VBAR1', 'RPRO', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_VBAR2', 'ENG_RC', '2', NULL, '3', 'RCV', NULL, 'N', NULL, NULL, NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_VBAR2', 'ENG_RC', '3', NULL, NULL, 'RPRO', NULL, 'N', NULL, 'V', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_IVP', 'ENG_V', 'ENG_PP', '1', NULL, NULL, 'V', NULL, 'H', NULL, 'PREP', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_IVP', 'ENG_NV', 'ENG_PP', '1', NULL, '2', 'V', NULL, 'H', NULL, 'NEG', NULL, 'H', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_IVP', 'ENG_NV', 'ENG_PP', '2', NULL, NULL, 'V', NULL, 'H', NULL, 'PREP', NULL, 'N', NULL, 'ENG');

insert into LEXICON values('list', 'ENG', 'V', 'LISTENGV');
insert into LEXICON values('file', 'ENG', 'N', 'FILEENGN');
insert into LEXICON values('directory', 'ENG', 'N', 'DIRECTORYENGN');
insert into LEXICON values('from', 'ENG', 'PREP', 'FROMENGPREP');
insert into LEXICON values('in', 'ENG', 'PREP', 'INENGPREP');
insert into LEXICON values('are', 'ENG', 'V', 'BEENGV');
insert into LEXICON values('be', 'ENG', 'V', 'BEENGV');
insert into LEXICON values('not', 'ENG', 'NEG', 'NOTENGNEG');
insert into LEXICON values('that', 'ENG', 'RPRO', 'THATENGRPRO');
insert into LEXICON values('executable', 'ENG', 'A', 'EXECUTABLEENGA');

/*Remove attributives from ENTITIES like executable,etc., leave only pure nouns*/
/*
insert into ENTITIES values('ENTITYENGN', '1', 'ENTITYENGN', '1');
insert into ENTITIES values('FILEENGN', '1', 'ENTITYENGN', '1');
insert into ENTITIES values('DIRECTORYENGN', '1', 'FILEENGN', '1');

insert into RELATIONS values('ACTENGV', '1', 'ACTENGV', '1');
insert into RELATIONS values('CHANGEENGV', '1', 'ACTENGV', '1');
insert into RELATIONS values('CREATEENGV', '1', 'ACTENGV', '1');
insert into RELATIONS values('MAKEENGV', '1', 'CREATEENGV', '1');
insert into RELATIONS values('COPYENGV', '1', 'CREATEENGV', '1');
insert into RELATIONS values('LISTENGV', '1', 'ACTENGV', '1');
*/

/*no value in the semantic_dependency field means no dependency*/
insert into DEPOLEX values('CON', '1', '1', NULL, NULL, NULL, NULL, NULL, NULL);
insert into DEPOLEX values('DIRECTORYENGN', '1', '1', NULL, '2', NULL, '0', 'BEENGV', '1');
insert into DEPOLEX values('DIRECTORYENGN', '1', '2', '1', '2', NULL, '1', 'CON', '1');
insert into DEPOLEX values('EXECUTABLEENGA', '1', '1', NULL, NULL, NULL, '0', 'FILEENGN', '1');
insert into DEPOLEX values('FILEENGN', '1', '1', NULL, '1', NULL, '0', 'BEENGV', '1');
insert into DEPOLEX values('FILEENGN', '2', '1', '1', NULL, NULL, '1', 'CON', '1');
insert into DEPOLEX values('FROMENGPREP', '1', '1', NULL, '1', NULL, '0', 'DIRECTORYENGN', '1');
insert into DEPOLEX values('INENGPREP', '1', '1', NULL, '1', NULL, '0', 'DIRECTORYENGN', '1');
insert into DEPOLEX values('LISTENGV', '1', '1', NULL, NULL, '2', '0', 'FILEENGN', '1');
insert into DEPOLEX values('LISTENGV', '1', '2', NULL, '3', NULL, '0', 'INENGPREP', '1');
insert into DEPOLEX values('LISTENGV', '1', '3', NULL, '3', NULL, '0', 'FROMENGPREP', '1');
insert into DEPOLEX values('LISTENGV', '2', '1', NULL, '2', '2', '0', 'DIRECTORYENGN', '1');
insert into DEPOLEX values('LISTENGV', '2', '2', NULL, '3', NULL, '0', 'INENGPREP', '1');
insert into DEPOLEX values('LISTENGV', '2', '3', NULL, '3', NULL, '0', 'FROMENGPREP', '1');
insert into DEPOLEX values('NON-EXECUTABLEENGA', '1', '1', NULL, NULL, NULL, '0', NULL, NULL);
insert into DEPOLEX values('THATENGRPRO', '1', '1', NULL, NULL, NULL, '0', NULL, NULL);
insert into DEPOLEX values('BEENGV', '1', '1', NULL, '2', '2', '0', 'NOTENGNEG', '1');
insert into DEPOLEX values('BEENGV', '1', '2', NULL, NULL, NULL, '0', 'INENGPREP', '1');
insert into DEPOLEX values('NOTENGNEG', '1', '1', NULL, NULL, NULL, '0', NULL, NULL);

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
