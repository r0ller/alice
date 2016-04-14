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
insert into SYMBOLS values('Verb', 'HUN', 'Ige');
insert into SYMBOLS values('ConjDefSg2', 'HUN', 'Felszólító');
insert into SYMBOLS values('Vbpfx', 'HUN', 'Igekötő');
insert into SYMBOLS values('Acc', 'HUN', 'Tárgyas');
insert into SYMBOLS values('CON', 'HUN', 'Konstans');

/*Constant has hardcoded token value 1 in the yacc source but to avoid collision, the values here are increased
by 1 during runtime so, the smallest value here must at least be 1*/
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
insert into GCAT values('CON', 'Stem', 'HUN', '0');
insert into GCAT values('CON', 'Acc', 'HUN', '14');
insert into GCAT values('Verb', 'Stem', 'HUN', '15');
insert into GCAT values('Verb', 'ConjDefSg2', 'HUN', '16');
insert into GCAT values('Vbpfx', 'Stem', 'HUN', '17');

insert into FUNCTOR_DEFS values('NAMEENGN_1',	'return NAMEENGN_1_CON_1_IN;');
insert into FUNCTOR_DEFS values('WITHENGPREP_1', 'return NAMEENGN_1_OUT;');
insert into FUNCTOR_DEFS values('CONTACTENGN_1', NULL);
insert into FUNCTOR_DEFS values('LISTENGV_1',	'if(typeof WITHENGPREP_1_OUT===''undefined'') Android.fetchContacts('''');else Android.fetchContacts(WITHENGPREP_1_OUT)');
insert into FUNCTOR_DEFS values('PRODUCTENGN_1',	'if(PRODUCTENGN_1_CON_1_IN==''zero''||PRODUCTENGN_1_CON_1_IN==''bread'') return ''0'';else if(PRODUCTENGN_1_CON_1_IN==''one''||PRODUCTENGN_1_CON_1_IN==''milk'') return ''1'';');
insert into FUNCTOR_DEFS values('FORENGPREP_1', 'return PRODUCTENGN_1_OUT;');
insert into FUNCTOR_DEFS values('DETAILENGN_1', NULL);
insert into FUNCTOR_DEFS values('SHOWENGV_1',	'if(typeof FORENGPREP_1_OUT===''undefined'') Android.showProduct('''');else Android.showProduct(FORENGPREP_1_OUT)');
insert into FUNCTOR_DEFS values('FELHUNVBPFX_1', NULL);
insert into FUNCTOR_DEFS values('HIVHUNV_1',	'Android.Call(HIVHUNV_1_CON_2_IN)');

insert into FUNCTORS values('CON', '1', NULL);
insert into FUNCTORS values('WITHENGPREP', '1', 'WITHENGPREP_1');
insert into FUNCTORS values('LISTENGV', '1', 'LISTENGV_1');
insert into FUNCTORS values('NAMEENGN', '1', 'NAMEENGN_1');
insert into FUNCTORS values('CONTACTENGN', '1', 'CONTACTENGN_1');
insert into FUNCTORS values('FORENGPREP', '1', 'FORENGPREP_1');
insert into FUNCTORS values('SHOWENGV', '1', 'SHOWENGV_1');
insert into FUNCTORS values('PRODUCTENGN', '1', 'PRODUCTENGN_1');
insert into FUNCTORS values('DETAILENGN', '1', 'DETAILENGN_1');
insert into FUNCTORS values('HIVHUNV', '1', 'HIVHUNV_1');
insert into FUNCTORS values('FELHUNVBPFX', '1', 'FELHUNVBPFX_1');

insert into RULE_TO_RULE_MAP values( 'ENG_VBAR1', 'ENG_V', 'ENG_NP', '1', '2', NULL, 'RCV',  NULL, 'H', NULL, NULL, NULL, NULL, NULL, 'ENG');
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
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_VBAR1', 'ENG_RC', '2', NULL, '3', 'RCV', NULL, 'N', NULL, NULL, NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_VBAR1', 'ENG_RC', '3', NULL, NULL, 'RPRO', NULL, 'N', NULL, 'V', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_VBAR2', 'ENG_RC', '1', NULL, '2', 'N', NULL, 'H', 'ENG_VBAR1', 'RPRO', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_VBAR2', 'ENG_RC', '2', NULL, '3', 'RCV', NULL, 'N', NULL, NULL, NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_VBAR2', 'ENG_RC', '3', NULL, NULL, 'RPRO', NULL, 'N', NULL, 'V', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_IVP', 'ENG_V', 'ENG_PP', '1', NULL, NULL, 'V', NULL, 'H', NULL, 'PREP', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_IVP', 'ENG_NV', 'ENG_PP', '1', NULL, '2', 'V', NULL, 'H', NULL, 'NEG', NULL, 'H', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_IVP', 'ENG_NV', 'ENG_PP', '2', NULL, NULL, 'V', NULL, 'H', NULL, 'PREP', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'HUN_VP', 'HUN_ImpVerbPfx', 'HUN_NP', '1', NULL, NULL, 'Verb', NULL, 'H', NULL, 'CON', NULL, 'N', NULL, 'HUN');
insert into RULE_TO_RULE_MAP values( 'HUN_ImpVerbPfx', 'HUN_ImpVerb', 'Vbpfx', '1', NULL, NULL, 'Verb', NULL, 'H', NULL, 'Vbpfx', NULL, 'N', NULL, 'HUN');

insert into LEXICON values('list', 'ENG', 'V', 'LISTENGV');
insert into LEXICON values('contact', 'ENG', 'N', 'CONTACTENGN');
insert into LEXICON values('name', 'ENG', 'N', 'NAMEENGN');
insert into LEXICON values('with', 'ENG', 'PREP', 'WITHENGPREP');
insert into LEXICON values('first', 'ENG', 'A', 'FIRSTENGA');
insert into LEXICON values('last', 'ENG', 'A', 'LASTENGA');
insert into LEXICON values('show', 'ENG', 'V', 'SHOWENGV');
insert into LEXICON values('detail', 'ENG', 'N', 'DETAILENGN');
insert into LEXICON values('for', 'ENG', 'PREP', 'FORENGPREP');
insert into LEXICON values('product', 'ENG', 'N', 'PRODUCTENGN');
insert into LEXICON values('hív', 'HUN', 'Verb', 'HIVHUNV');
insert into LEXICON values('fel', 'HUN', 'Vbpfx', 'FELHUNVBPFX');

insert into DEPOLEX values('CON', '1', '1', NULL, NULL, NULL, NULL, NULL, NULL);
insert into DEPOLEX values('LISTENGV', '1', '1', NULL, NULL, '2', '0', 'CONTACTENGN', '1');
insert into DEPOLEX values('LISTENGV', '1', '2', NULL, '2', NULL, '0', 'WITHENGPREP', '1');
insert into DEPOLEX values('WITHENGPREP', '1', '1', NULL, '1', NULL, '0', 'NAMEENGN', '1');
insert into DEPOLEX values('NAMEENGN', '1', '1', '1', NULL, NULL, '1', 'CON', '1');
insert into DEPOLEX values('CONTACTENGN', '1', '1', NULL, NULL, NULL, '0', NULL, NULL);
insert into DEPOLEX values('SHOWENGV', '1', '1', NULL, NULL, '2', '0', 'DETAILENGN', '1');
insert into DEPOLEX values('SHOWENGV', '1', '2', NULL, '2', NULL, '0', 'FORENGPREP', '1');
insert into DEPOLEX values('FORENGPREP', '1', '1', NULL, '1', NULL, '0', 'PRODUCTENGN', '1');
insert into DEPOLEX values('PRODUCTENGN', '1', '1', '1', NULL, NULL, '1', 'CON', '1');
insert into DEPOLEX values('DETAILENGN', '1', '1', NULL, NULL, NULL, '0', NULL, NULL);
insert into DEPOLEX values('HIVHUNV', '1', '1', NULL, NULL, '2', '0', 'FELHUNVBPFX', '1');
insert into DEPOLEX values('HIVHUNV', '1', '2', NULL, NULL, NULL, '1', 'CON', '1');
insert into DEPOLEX values('FELHUNVBPFX', '1', '1', NULL, NULL, NULL, NULL, NULL, NULL);
COMMIT;
