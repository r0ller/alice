BEGIN;
/*
insert into DEFTYPE values('0');
insert into DEFTYPE values('1');
*/

insert into ROOT_TYPE values('H');
insert into ROOT_TYPE values('N');

insert into LANGUAGES values('HUN', 'Hungarian', '1');
insert into LANGUAGES values('ENG', 'English', '1');
insert into LANGUAGES values('BSH', 'BASH', '0');
insert into LANGUAGES values('WPS', 'Windows PowerShell', '0');

/*TODO: remove ENG_ prefix later from non-terminals*/
insert into SYMBOLS values('A', 'ENG');
insert into SYMBOLS values('ADV', 'ENG');
insert into SYMBOLS values('CON', 'ENG');
insert into SYMBOLS values('DET', 'ENG');
insert into SYMBOLS values('N', 'ENG');
insert into SYMBOLS values('ENG_VP', 'ENG');
insert into SYMBOLS values('ENG_NP', 'ENG');
insert into SYMBOLS values('ENG_CNP', 'ENG');
insert into SYMBOLS values('ENG_PP', 'ENG');
insert into SYMBOLS values('Stem', 'ENG');
insert into SYMBOLS values('Pl', 'ENG');
insert into SYMBOLS values('Sg', 'ENG');
insert into SYMBOLS values('PREP', 'ENG');
insert into SYMBOLS values('QPRO', 'ENG');
insert into SYMBOLS values('V', 'ENG');
insert into SYMBOLS values('ENG_VBAR1', 'ENG');
insert into SYMBOLS values('ENG_VBAR2', 'ENG');
insert into SYMBOLS values('ENG_VBAR3', 'ENG');
insert into SYMBOLS values('RPRO', 'ENG');
insert into SYMBOLS values('Relative', 'ENG');
insert into SYMBOLS values('Aux', 'ENG');
insert into SYMBOLS values('ENG_RC', 'ENG');
insert into SYMBOLS values('ENG_IVP', 'ENG');
insert into SYMBOLS values('ENG_V', 'ENG');
insert into SYMBOLS values('ENG_TP', 'ENG');
insert into SYMBOLS values('ENG_RPRO', 'ENG');
insert into SYMBOLS values('ENG_NV', 'ENG');
insert into SYMBOLS values('NEG', 'ENG');

/*Constant has hardcoded token value 1 in the yacc source but to avoid collision, the values here are increased
by 1 during runtime so, the smallest value here must at least be 1*/
/*TODO: Think over if the feature field for all gcats shall at least be 'Stem' or not?
For exmaple, DET is considered as well to have a stem? How is it analysed by Foma?*/
insert into GCAT values('CON', NULL, 'ENG', '0', 'Constant');/*Plays role only when checking for terminal symbols*/
insert into GCAT values('A', 'Stem', 'ENG', '1', 'Adjective');
insert into GCAT values('ADV', NULL, 'ENG', '2', 'Adverb');
insert into GCAT values('DET', NULL, 'ENG', '3', 'Determiner');
insert into GCAT values('N', 'Stem', 'ENG', '4', 'Noun');
insert into GCAT values('N', 'Pl', 'ENG', '5', 'Plural Noun');
insert into GCAT values('N', 'Sg', 'ENG', '6', 'Singular Noun');
insert into GCAT values('PREP', NULL, 'ENG', '7', 'Preposition');
insert into GCAT values('QPRO', NULL, 'ENG', '8', 'Quantifier Pronoun');
insert into GCAT values('V', 'Stem', 'ENG', '9', 'Verb');
insert into GCAT values('V', 'Aux', 'ENG', '10', 'Auxiliary');
insert into GCAT values('RPRO', NULL, 'ENG', '11', 'Relative Pronoun');
insert into GCAT values('RPRO', 'Relative', 'ENG', '12', 'Relativizer feature');
insert into GCAT values('NEG', 'Stem', 'ENG', '13', 'Negation');

insert into FUNCTOR_DEFS values('NAMEENGN_1',	'return NAMEENGN_1_CON_1_IN;');
insert into FUNCTOR_DEFS values('WITHENGPREP_1', 'return NAMEENGN_1_OUT;');
insert into FUNCTOR_DEFS values('CONTACTENGN_1', NULL);
insert into FUNCTOR_DEFS values('LISTENGV_1',	'if(typeof WITHENGPREP_1_OUT===''undefined'') Android.fetchContacts('''');else Android.fetchContacts(WITHENGPREP_1_OUT)');

insert into FUNCTORS values('CON', '1', NULL);
insert into FUNCTORS values('WITHENGPREP', '1', 'WITHENGPREP_1');
insert into FUNCTORS values('LISTENGV', '1', 'LISTENGV_1');
insert into FUNCTORS values('NAMEENGN', '1', 'NAMEENGN_1');
insert into FUNCTORS values('CONTACTENGN', '1', 'CONTACTENGN_1');

insert into RULE_TO_RULE_MAP values( 'ENG_VBAR1', 'ENG_V', 'ENG_NP', '1', '2', NULL, 'Aux',  NULL, 'H', NULL, NULL, NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VBAR1', 'ENG_V', 'ENG_NP', '2', '3', '4', 'N', NULL, 'N', NULL, 'CON', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VBAR1', 'ENG_V', 'ENG_NP', '3', '4', NULL, 'V', NULL, 'H', NULL, 'CON', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VBAR1', 'ENG_V', 'ENG_NP', '4', NULL, '5', 'V', NULL, 'H', NULL, 'N', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VBAR1', 'ENG_V', 'ENG_NP', '5', '5', '6', NULL, NULL, NULL, NULL, 'Sg', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VBAR1', 'ENG_V', 'ENG_NP', '6', '7', NULL, NULL, NULL, NULL, NULL, 'N', 'NAMEENGN', 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VBAR1', 'ENG_V', 'ENG_NP', '7', '7', NULL, NULL, NULL, NULL, NULL, 'N', 'CONTACTENGN', 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VBAR2', 'ENG_VBAR1', 'ENG_PP', '1', NULL, NULL, 'V', NULL, 'H', NULL, 'PREP', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_CNP', 'A', 'ENG_CNP', '1', NULL, NULL, 'A', NULL, 'H', NULL, 'N', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_PP', 'PREP', 'ENG_NP', '1', '2', '3', 'PREP', NULL, 'H', NULL, 'N', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_PP', 'PREP', 'ENG_NP', '2', NULL, NULL, 'PREP', NULL, 'H', NULL, 'CON', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_PP', 'PREP', 'ENG_NP', '3', '3', NULL, 'N', NULL, 'N', NULL, 'CON', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_VBAR1', 'ENG_RC', '1', NULL, '2', 'N', NULL, 'H', NULL, 'RPRO', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_VBAR1', 'ENG_RC', '2', NULL, '3', 'Aux', NULL, 'N', NULL, NULL, NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_VBAR1', 'ENG_RC', '3', NULL, NULL, 'RPRO', NULL, 'N', NULL, 'V', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_VBAR2', 'ENG_RC', '1', NULL, '2', 'N', NULL, 'H', 'ENG_VBAR1', 'RPRO', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_VBAR2', 'ENG_RC', '2', NULL, '3', 'Aux', NULL, 'N', NULL, NULL, NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_VBAR2', 'ENG_RC', '3', NULL, NULL, 'RPRO', NULL, 'N', NULL, 'V', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_IVP', 'ENG_V', 'ENG_PP', '1', NULL, NULL, 'V', NULL, 'H', NULL, 'PREP', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_IVP', 'ENG_NV', 'ENG_PP', '1', NULL, '2', 'V', NULL, 'H', NULL, 'NEG', NULL, 'H', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_IVP', 'ENG_NV', 'ENG_PP', '2', NULL, NULL, 'V', NULL, 'H', NULL, 'PREP', NULL, 'N', NULL, 'ENG');

insert into LEXICON values('list', 'ENG', 'V', 'LISTENGV');
insert into LEXICON values('contact', 'ENG', 'N', 'CONTACTENGN');
insert into LEXICON values('name', 'ENG', 'N', 'NAMEENGN');
insert into LEXICON values('with', 'ENG', 'PREP', 'WITHENGPREP');
insert into LEXICON values('first', 'ENG', 'A', 'FIRSTENGA');
insert into LEXICON values('last', 'ENG', 'A', 'LASTENGA');

insert into DEPOLEX values('CON', '1', '1', NULL, NULL, NULL, NULL, NULL, NULL);
insert into DEPOLEX values('LISTENGV', '1', '1', NULL, NULL, '2', '0', 'CONTACTENGN', '1');
insert into DEPOLEX values('LISTENGV', '1', '2', NULL, '2', NULL, '0', 'WITHENGPREP', '1');
insert into DEPOLEX values('WITHENGPREP', '1', '1', NULL, '1', NULL, '0', 'NAMEENGN', '1');
insert into DEPOLEX values('NAMEENGN', '1', '1', '1', NULL, NULL, '1', 'CON', '1');
insert into DEPOLEX values('CONTACTENGN', '1', '1', NULL, NULL, NULL, '0', NULL, NULL);
COMMIT;
