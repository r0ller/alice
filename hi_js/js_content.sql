BEGIN;

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
insert into SYMBOLS values('ENG_VBAR4', 'ENG', 'Intermediate Verb Pharse');
insert into SYMBOLS values('RPRO', 'ENG', 'Relative Pronoun');
insert into SYMBOLS values('Relative', 'ENG', 'Relativizer feature');
insert into SYMBOLS values('Aux', 'ENG', 'Auxiliary');
insert into SYMBOLS values('ENG_RC', 'ENG', 'Relative Clause');
insert into SYMBOLS values('ENG_IVP', 'ENG', 'Incomplete Verb Phrase');
insert into SYMBOLS values('ENG_V', 'ENG', 'Verb');
insert into SYMBOLS values('ENG_TP', 'ENG', 'Tense Phrase');
insert into SYMBOLS values('ENG_DP', 'ENG', 'Determiner Phrase');
insert into SYMBOLS values('ENG_RPRO', 'ENG', 'Relative Pronoun');
insert into SYMBOLS values('ENG_NV', 'ENG', 'Negated Verb');
insert into SYMBOLS values('NEG', 'ENG', 'Negation');
insert into SYMBOLS values('RCV', 'ENG', 'Relative Clause Verb');
insert into SYMBOLS values('PAR', 'ENG', 'Tense particle');
insert into SYMBOLS values('fwVowel', 'ENG', 'following word starts with vowel');
insert into SYMBOLS values('fwConsonant', 'ENG', 'following word starts with consonant');
insert into SYMBOLS values('swVowel', 'ENG', 'word starts with vowel');
insert into SYMBOLS values('swConsonant', 'ENG', 'word starts with consonant');

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
insert into GCAT values('V', 'Sg', 'ENG', NULL);
insert into GCAT values('V', 'Pl', 'ENG', NULL);
insert into GCAT values('RPRO', NULL, 'ENG', '11');
insert into GCAT values('RPRO', 'Relative', 'ENG', '12');
insert into GCAT values('NEG', 'Stem', 'ENG', '13');
insert into GCAT values('PAR', NULL, 'ENG', '18');
insert into GCAT values('DET','Indef', 'ENG', '19');
insert into GCAT values('DET','fwVowel', 'ENG', '20');
insert into GCAT values('DET','fwConsonant', 'ENG', '21');
insert into GCAT values('N','swVowel', 'ENG', '22');
insert into GCAT values('N','swConsonant', 'ENG', '23');
insert into GCAT values('V','Gerund', 'ENG', '24');

insert into FUNCTOR_DEFS values('LOCATIONENGN_1',	NULL);
insert into FUNCTOR_DEFS values('OFENGPREP_1', NULL);
insert into FUNCTOR_DEFS values('RESTAURANTENGN_1',	NULL);
insert into FUNCTOR_DEFS values('INENGPREP_1', NULL);
insert into FUNCTOR_DEFS values('SHOWENGV_1',	NULL);
insert into FUNCTOR_DEFS values('CON_1',	NULL);

insert into FUNCTORS values('CON', '1', 'CON_1');
insert into FUNCTORS values('OFENGPREP', '1', 'OFENGPREP_1');
insert into FUNCTORS values('RESTAURANTENGN', '1', 'RESTAURANTENGN_1');
insert into FUNCTORS values('LOCATIONENGN', '1', 'LOCATIONENGN_1');
insert into FUNCTORS values('INENGPREP', '1', 'INENGPREP_1');
insert into FUNCTORS values('SHOWENGV', '1', 'SHOWENGV_1');

insert into RULE_TO_RULE_MAP values( 'ENG_VBAR1', 'ENG_V', 'ENG_NP', '1', '2', NULL, 'RCV',  NULL, 'H', NULL, NULL, NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VBAR1', 'ENG_V', 'ENG_NP', '2', '3', '4', 'N', NULL, 'N', NULL, 'CON', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VBAR1', 'ENG_V', 'ENG_NP', '3', '4', NULL, 'V', NULL, 'H', NULL, 'CON', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VBAR1', 'ENG_V', 'ENG_NP', '4', NULL, NULL, 'V', NULL, 'H', NULL, 'N', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VBAR2', 'ENG_VBAR1', 'ENG_PP', '1', NULL, NULL, 'N', NULL, 'H', NULL, 'PREP', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_CNP', 'A', 'ENG_CNP', '1', NULL, NULL, 'A', NULL, 'H', NULL, 'N', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_PP', 'PREP', 'ENG_NP', '1', '2', '3', 'PREP', NULL, 'H', NULL, 'N', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_PP', 'PREP', 'ENG_NP', '2', NULL, NULL, 'PREP', NULL, 'H', NULL, 'CON', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_PP', 'PREP', 'ENG_NP', '3', '3', NULL, 'N', NULL, 'N', NULL, 'CON', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_VBAR2', 'ENG_PP', '1', NULL, NULL, 'N', NULL, 'H', 'ENG_VBAR1', 'PREP', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_VBAR1', 'ENG_RC', '1', NULL, '2', 'N', NULL, 'H', NULL, 'RPRO', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_VBAR1', 'ENG_RC', '2', NULL, '3', 'RCV', NULL, 'N', NULL, NULL, NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_VBAR1', 'ENG_RC', '3', NULL, NULL, 'RPRO', NULL, 'N', NULL, 'V', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_VBAR2', 'ENG_RC', '1', NULL, '2', 'N', NULL, 'H', 'ENG_VBAR1', 'RPRO', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_VBAR2', 'ENG_RC', '2', NULL, '3', 'RCV', NULL, 'N', NULL, NULL, NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_VBAR2', 'ENG_RC', '3', NULL, NULL, 'RPRO', NULL, 'N', NULL, 'V', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_IVP', 'ENG_V', 'ENG_PP', '1', NULL, NULL, 'V', NULL, 'H', NULL, 'PREP', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_IVP', 'ENG_NV', 'ENG_PP', '1', NULL, '2', 'V', NULL, 'H', NULL, 'NEG', NULL, 'H', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_IVP', 'ENG_NV', 'ENG_PP', '2', NULL, NULL, 'V', NULL, 'H', NULL, 'PREP', NULL, 'N', NULL, 'ENG');

insert into LEXICON values('location', 'ENG', 'N', 'LOCATIONENGN');
insert into LEXICON values('of', 'ENG', 'PREP', 'OFENGPREP');
insert into LEXICON values('show', 'ENG', 'V', 'SHOWENGV');
insert into LEXICON values('restaurant', 'ENG', 'N', 'RESTAURANTENGN');
insert into LEXICON values('in', 'ENG', 'PREP', 'INENGPREP');

insert into DEPOLEX values('CON', '1', '1', NULL, NULL, NULL, NULL, NULL, NULL);
insert into DEPOLEX values('LOCATIONENGN', '1', '1', '1', '2', '2', '0', 'OFENGPREP', '1');
insert into DEPOLEX values('LOCATIONENGN', '1', '2', '1', '2', NULL, '0', 'INENGPREP', '1');
insert into DEPOLEX values('OFENGPREP', '1', '1', '1', '2', NULL, '0', 'RESTAURANTENGN', '1');
insert into DEPOLEX values('OFENGPREP', '1', '2', '1', NULL, NULL, '0', 'CON', '1');
insert into DEPOLEX values('RESTAURANTENGN', '1', '1', '1', '1', NULL, '0', 'CON', '1');
insert into DEPOLEX values('SHOWENGV', '1', '1', NULL, '1', NULL, '0', 'LOCATIONENGN', '1');
insert into DEPOLEX values('INENGPREP', '1', '1', NULL, NULL, NULL, '0', 'CON', '1');
COMMIT;
