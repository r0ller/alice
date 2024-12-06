PRAGMA foreign_keys = ON;
BEGIN;

insert into SETTINGS values('main_symbol','main_verb');
insert into SETTINGS values('main_verb','<V>');
insert into SETTINGS values('imperative_mood_tag','imperative');
insert into SETTINGS values('interrogative_mood_tag','interrogative');
insert into SETTINGS values('indicative_mood_tag','indicative');

insert into ROOT_TYPE values('H');
insert into ROOT_TYPE values('N');

insert into PRECEDENCES values('L','%left');
insert into PRECEDENCES values('R','%right');
insert into PRECEDENCES values('P','%precedence');
insert into PRECEDENCES values('N','%nonassoc');

/*insert into LANGUAGES values('HUN', 'Hungarian', '1', 'magyar.fst', '1');*/
insert into LANGUAGES values('ENG', 'English', '1', 'english.fst', '1');

/*TODO: remove ENG_ prefix later from non-terminals*/
insert into SYMBOLS values('A', 'ENG', 'Adjective');
insert into SYMBOLS values('ADV', 'ENG', 'Adverb');
insert into SYMBOLS values('CON', 'ENG', 'Constant');
insert into SYMBOLS values('CONJ', 'ENG', 'Conjunction');
insert into SYMBOLS values('DET', 'ENG', 'Determiner');
insert into SYMBOLS values('Indef', 'ENG', 'Indefinite Determiner');
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
insert into SYMBOLS values('ENG_Vbar1', 'ENG', 'Intermediate Verb Pharse');
insert into SYMBOLS values('ENG_Vbar2', 'ENG', 'Intermediate Verb Pharse');
insert into SYMBOLS values('ENG_Vbar3', 'ENG', 'Intermediate Verb Pharse');
insert into SYMBOLS values('ENG_Vbar4', 'ENG', 'Intermediate Verb Pharse');
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
insert into SYMBOLS values('VNEG', 'ENG', 'Verb Negation');
insert into SYMBOLS values('ANEG', 'ENG', 'Adjective Negation');
insert into SYMBOLS values('RCV', 'ENG', 'Relative Clause Verb');
insert into SYMBOLS values('PAR', 'ENG', 'Tense particle');
insert into SYMBOLS values('fwVowel', 'ENG', 'following word starts with vowel');
insert into SYMBOLS values('fwConsonant', 'ENG', 'following word starts with consonant');
insert into SYMBOLS values('swVowel', 'ENG', 'word starts with vowel');
insert into SYMBOLS values('swConsonant', 'ENG', 'word starts with consonant');
insert into SYMBOLS values('Gerund', 'ENG', 'Gerund');
insert into SYMBOLS values('S','ENG',NULL);
insert into SYMBOLS values('ENG_VNEG','ENG',NULL);
insert into SYMBOLS values('ENG_VNEG_Stem','ENG',NULL);
insert into SYMBOLS values('ENG_ANEG','ENG',NULL);
insert into SYMBOLS values('ENG_A0NEG','ENG',NULL);
insert into SYMBOLS values('ENG_ANEG_Stem','ENG',NULL);
insert into SYMBOLS values('ENG_AdvP','ENG',NULL);
insert into SYMBOLS values('ENG_Prep','ENG',NULL);
insert into SYMBOLS values('ENG_CAP','ENG','Constant Adjective Phrase');
insert into SYMBOLS values('ENG_AP','ENG','Adjective Phrase');
insert into SYMBOLS values('ENG_CONJ','ENG',NULL);
insert into SYMBOLS values('ENG_ACONJ','ENG',NULL);
insert into SYMBOLS values('ENG_CONJA','ENG',NULL);
insert into SYMBOLS values('ENG_Abar1','ENG',NULL);
insert into SYMBOLS values('ENG_Ahead','ENG',NULL);
insert into SYMBOLS values('ENG_Abar2','ENG',NULL);
insert into SYMBOLS values('ENG_Alist','ENG',NULL);
insert into SYMBOLS values('ENG_QPro', 'ENG',NULL);
insert into SYMBOLS values('ENG_Adv','ENG',NULL);
insert into SYMBOLS values('ENG_V_Stem','ENG',NULL);
insert into SYMBOLS values('ENG_V_lfea_aux','ENG',NULL);
insert into SYMBOLS values('ENG_V_ger','ENG',NULL);
insert into SYMBOLS values('ENG_V_lfea_ger','ENG',NULL);
insert into SYMBOLS values('ENG_N','ENG',NULL);
insert into SYMBOLS values('ENG_N_Sg','ENG',NULL);
insert into SYMBOLS values('ENG_N_Pl','ENG',NULL);
insert into SYMBOLS values('ENG_Indef_Det_a','ENG',NULL);
insert into SYMBOLS values('ENG_Indef_Det_an','ENG',NULL);
insert into SYMBOLS values('ENG_N_Sg_0Con','ENG',NULL);
insert into SYMBOLS values('ENG_N_Sg_0Con_swC','ENG',NULL);
insert into SYMBOLS values('ENG_N_Sg_0Con_swV','ENG',NULL);
insert into SYMBOLS values('ENG_1Con','ENG',NULL);
insert into SYMBOLS values('ENG_N_Pl_0Con','ENG',NULL);
insert into SYMBOLS values('ENG_N_Pl_0Con_swC','ENG',NULL);
insert into SYMBOLS values('ENG_N_Pl_0Con_swV','ENG',NULL);
insert into SYMBOLS values('ENG_nCon','ENG',NULL);
insert into SYMBOLS values('ENG_Con','ENG',NULL);
insert into SYMBOLS values('ENG_N_Stem','ENG',NULL);
insert into SYMBOLS values('ENG_N_lfea_Sg','ENG',NULL);
insert into SYMBOLS values('ENG_N_lfea_Pl','ENG',NULL);
insert into SYMBOLS values('ENG_A','ENG',NULL);
insert into SYMBOLS values('ENG_A_Stem','ENG',NULL);
insert into SYMBOLS values('ENG_RPro','ENG',NULL);
insert into SYMBOLS values('ENG_RPro_stem','ENG',NULL);
insert into SYMBOLS values('ENG_RPro_lfea_relative','ENG',NULL);
insert into SYMBOLS values('ENG_Tense_particle','ENG',NULL);
insert into SYMBOLS values('ENG_Indef_Det','ENG',NULL);
insert into SYMBOLS values('ENG_Det_stem','ENG',NULL);
insert into SYMBOLS values('ENG_lfea_IndefDet','ENG',NULL);
insert into SYMBOLS values('ENG_lfea_fwVowel','ENG',NULL);
insert into SYMBOLS values('ENG_lfea_fwConsonant','ENG',NULL);
insert into SYMBOLS values('ENG_lfea_swVowel','ENG',NULL);
insert into SYMBOLS values('ENG_lfea_swConsonant','ENG',NULL);
insert into SYMBOLS values('t_ENG_V_Stem','ENG',NULL);
insert into SYMBOLS values('t_ENG_V_Aux','ENG',NULL);
insert into SYMBOLS values('t_ENG_V_Gerund','ENG',NULL);
insert into SYMBOLS values('t_ENG_QPRO_Stem','ENG',NULL);
insert into SYMBOLS values('t_ENG_N_Stem','ENG',NULL);
insert into SYMBOLS values('t_ENG_N_Pl','ENG',NULL);
insert into SYMBOLS values('t_ENG_N_Sg','ENG',NULL);
insert into SYMBOLS values('t_ENG_A_Stem','ENG',NULL);
insert into SYMBOLS values('t_ENG_PREP_Stem','ENG',NULL);
insert into SYMBOLS values('t_ENG_CON_Stem','ENG',NULL);
insert into SYMBOLS values('t_ENG_ADV_Stem','ENG',NULL);
insert into SYMBOLS values('t_ENG_RPRO_Stem','ENG',NULL);
insert into SYMBOLS values('t_ENG_RPRO_Relative','ENG',NULL);
insert into SYMBOLS values('t_ENG_PAR_Stem','ENG',NULL);
insert into SYMBOLS values('t_ENG_VNEG_Stem','ENG',NULL);
insert into SYMBOLS values('t_ENG_ANEG_Stem','ENG',NULL);
insert into SYMBOLS values('t_ENG_DET_Stem','ENG',NULL);
insert into SYMBOLS values('t_ENG_DET_Indef','ENG',NULL);
insert into SYMBOLS values('t_ENG_DET_fwVowel','ENG',NULL);
insert into SYMBOLS values('t_ENG_DET_fwConsonant','ENG',NULL);
insert into SYMBOLS values('t_ENG_N_swVowel','ENG',NULL);
insert into SYMBOLS values('t_ENG_N_swConsonant','ENG',NULL);
insert into SYMBOLS values('t_ENG_CONJ_Stem','ENG',NULL);
insert into SYMBOLS values('ENG_CONJ_Stem','ENG',NULL);
insert into SYMBOLS values('%empty','ENG',NULL);
insert into SYMBOLS values('ENG_Empty','ENG',NULL);

insert into SYMBOLS values('ENG_Vbar5','ENG','Vbar1 indicative mood');
insert into SYMBOLS values('FullStop', 'ENG', 'FullStop');
insert into SYMBOLS values('QuestionMark', 'ENG', 'QuestionMark');
insert into SYMBOLS values('ExclamationMark', 'ENG', 'ExclamationMark');
insert into SYMBOLS values('Punct', 'ENG', 'Punctuation');
insert into SYMBOLS values('ENG_Punct', 'ENG', 'Punctuation');
insert into SYMBOLS values('ENG_Punct_Stem', 'ENG', 'Punctuation');
insert into SYMBOLS values('t_ENG_Punct_Stem', 'ENG', 'Punctuation');
insert into SYMBOLS values('t_ENG_Punct_FullStop', 'ENG', NULL);
insert into SYMBOLS values('ENG_Punct_FullStop', 'ENG', NULL);
insert into SYMBOLS values('t_ENG_Punct_QuestionMark', 'ENG', NULL);
insert into SYMBOLS values('t_ENG_Punct_ExclamationMark', 'ENG', NULL);
insert into SYMBOLS values('ENG_Punct_QuestionMark', 'ENG', NULL);
insert into SYMBOLS values('ENG_Punct_ExclamationMark', 'ENG', NULL);
insert into SYMBOLS values('Pron', 'ENG', 'Pronoun');
insert into SYMBOLS values('3sg', 'ENG', '3rd person singular');
insert into SYMBOLS values('wh', 'ENG', 'question word');
insert into SYMBOLS values('t_ENG_Pron_Stem', 'ENG', NULL);
insert into SYMBOLS values('ENG_Pron_Stem', 'ENG', NULL);
insert into SYMBOLS values('t_ENG_Pron_3sg', 'ENG', NULL);
insert into SYMBOLS values('ENG_Pron_3sg', 'ENG', NULL);
insert into SYMBOLS values('t_ENG_Pron_wh', 'ENG', NULL);
insert into SYMBOLS values('ENG_Pron_wh', 'ENG', NULL);
insert into SYMBOLS values('ENG_Pron_qw', 'ENG', NULL);
insert into SYMBOLS values('ENG_Pron', 'ENG', NULL);
insert into SYMBOLS values('ENG_Vbar6','ENG','questioning');

/*insert into SYMBOLS values('HUN_VP','HUN',NULL);
insert into SYMBOLS values('HUN_ImpVerbPfx','HUN',NULL);
insert into SYMBOLS values('HUN_ImpVerb','HUN',NULL);
insert into SYMBOLS values('HUN_Verb_lfea_ConjDefSg2','HUN',NULL);
insert into SYMBOLS values('HUN_Verb_stem','HUN',NULL);
insert into SYMBOLS values('HUN_Vbpfx','HUN',NULL);
insert into SYMBOLS values('HUN_NP','HUN',NULL);
insert into SYMBOLS values('HUN_N','HUN',NULL);
insert into SYMBOLS values('HUN_N_Sg','HUN',NULL);
insert into SYMBOLS values('HUN_1Con','HUN',NULL);
insert into SYMBOLS values('HUN_nCon','HUN',NULL);
insert into SYMBOLS values('HUN_AccCon','HUN',NULL);
insert into SYMBOLS values('HUN_Con','HUN',NULL);
insert into SYMBOLS values('HUN_Con_lfea_Acc','HUN',NULL);
insert into SYMBOLS values('S','HUN',NULL);
insert into SYMBOLS values('t_HUN_Verb_ConjDefSg2','HUN',NULL);
insert into SYMBOLS values('t_HUN_Verb_Stem','HUN',NULL);
insert into SYMBOLS values('t_HUN_Vbpfx_Stem','HUN',NULL);
insert into SYMBOLS values('t_Con','HUN',NULL);
insert into SYMBOLS values('t_HUN_CON_Acc','HUN',NULL);*/

/*Entries with NULL or '0' value for token are not to be generated in the bison source.*/
insert into GCAT values('CON', 'Stem', 'ENG', '1', NULL, NULL);
insert into GCAT values('A', 'Stem', 'ENG', '1', NULL, NULL);
insert into GCAT values('ADV', 'Stem', 'ENG', '2', NULL, NULL);
insert into GCAT values('DET', 'Stem', 'ENG', '3', NULL, NULL);
insert into GCAT values('N', 'Stem', 'ENG', '4', NULL, NULL);
insert into GCAT values('N', 'Pl', 'ENG', '5', NULL, NULL);
insert into GCAT values('N', 'Sg', 'ENG', '6', NULL, NULL);
insert into GCAT values('PREP', 'Stem', 'ENG', '7', NULL, NULL);
insert into GCAT values('QPRO', 'Stem', 'ENG', '8', NULL, NULL);
insert into GCAT values('V', 'Stem', 'ENG', '9', NULL, NULL);
insert into GCAT values('V', 'Aux', 'ENG', '10', NULL, NULL);
insert into GCAT values('V', 'RCV', 'ENG', NULL, NULL, NULL);
insert into GCAT values('V', 'Sg', 'ENG', NULL, NULL, NULL);
insert into GCAT values('V', 'Pl', 'ENG', NULL, NULL, NULL);
insert into GCAT values('RPRO', 'Stem', 'ENG', '11', NULL, NULL);
insert into GCAT values('RPRO', 'Relative', 'ENG', '12', NULL, NULL);
insert into GCAT values('VNEG', 'Stem', 'ENG', '13', NULL, NULL);
insert into GCAT values('ANEG', 'Stem', 'ENG', '14', NULL, NULL);
insert into GCAT values('PAR', 'Stem', 'ENG', '18', NULL, NULL);
insert into GCAT values('DET', 'Indef', 'ENG', '19', NULL, NULL);
insert into GCAT values('DET', 'fwVowel', 'ENG', '20', NULL, NULL);
insert into GCAT values('DET', 'fwConsonant', 'ENG', '21', NULL, NULL);
insert into GCAT values('N', 'swVowel', 'ENG', '22', NULL, NULL);
insert into GCAT values('N', 'swConsonant', 'ENG', '23', NULL, NULL);
insert into GCAT values('V', 'Gerund', 'ENG', '24', NULL, NULL);
insert into GCAT values('CONJ', 'Stem', 'ENG', '25', NULL, NULL);

insert into GCAT values('Punct', 'Stem', 'ENG', '1',NULL,NULL);
insert into GCAT values('Punct', 'FullStop', 'ENG', '1',NULL,NULL);
insert into GCAT values('Punct', 'QuestionMark', 'ENG', '1',NULL,NULL);
insert into GCAT values('Punct', 'ExclamationMark', 'ENG', '1',NULL,NULL);
insert into GCAT values('Pron', 'Stem', 'ENG', '1',NULL,NULL);
insert into GCAT values('Pron', '3sg', 'ENG', '1',NULL,NULL);
insert into GCAT values('Pron', 'wh', 'ENG', '1',NULL,NULL);

insert into FUNCTOR_DEFS values('LISTENGV_1', 'sh', '1', 'listengv_1.sh');
insert into FUNCTOR_DEFS values('LISTENGV_2', 'sh', '1', 'listengv_2.sh');
insert into FUNCTOR_DEFS values('FILEENGN_1', 'sh', '1', 'fileengn_1.sh');
insert into FUNCTOR_DEFS values('FILEENGN_2', 'sh', '1', 'fileengn_2.sh');
insert into FUNCTOR_DEFS values('INENGPREP_1', 'sh', '1', 'inengprep_1.sh');
insert into FUNCTOR_DEFS values('BEENGV_1', 'sh', '1', 'beengv_1.sh');
insert into FUNCTOR_DEFS values('BEENGV_2', 'sh', '1', 'beengv_2.sh');
insert into FUNCTOR_DEFS values('DIRECTORYENGN_1', 'sh', '1', 'directoryengn_1.sh');
insert into FUNCTOR_DEFS values('NOTENGVNEG_1', 'sh', '1', 'notengvneg_1.sh');
insert into FUNCTOR_DEFS values('NOTENGANEG_1', 'sh', '1', 'notenganeg_1.sh');
insert into FUNCTOR_DEFS values('FROMENGPREP_1', 'sh', '1', NULL);
insert into FUNCTOR_DEFS values('EXECUTABLEENGA_1', 'sh', '1', 'executableenga_1.sh');
insert into FUNCTOR_DEFS values('EXECUTABLEENGA_2', 'sh', '1', 'executableenga_2.sh');
insert into FUNCTOR_DEFS values('EMPTYENGA_1', 'sh', '1', 'emptyenga_1.sh');
insert into FUNCTOR_DEFS values('ANAENGDET_1', 'sh', '1', NULL);
insert into FUNCTOR_DEFS values('SYMLINKEDENGA_1', 'sh', '1', NULL);
insert into FUNCTOR_DEFS values('SYMLINKEDENGA_2', 'sh', '1', 'symlinkedenga_2.sh');
insert into FUNCTOR_DEFS values('ANDENGCONJ_1', 'sh', '1', 'andengconj_1.sh');
insert into FUNCTOR_DEFS values('ORENGCONJ_1', 'sh', '1', 'orengconj_1.sh');
insert into FUNCTOR_DEFS values('FILEBEPROP_1', 'sh', '1', 'filebeprop_1.sh');
insert into FUNCTOR_DEFS values('DIRBEPROP_1', 'sh', '1', 'dirbeprop_1.sh');
insert into FUNCTOR_DEFS values('PROPERTIES_1', 'sh', '1', 'properties_1.sh');
insert into FUNCTOR_DEFS values('PROPERTIES_2', 'sh', '1', 'properties_2.sh');
insert into FUNCTOR_DEFS values('LOCATED_1', 'sh', '1', 'located_1.sh');
insert into FUNCTOR_DEFS values('WHATENGPRON_1', 'sh', '1', NULL);

/*insert into FUNCTORS values('CON', '1', NULL);
insert into FUNCTORS values('INENGPREP', '1', 'INENGPREP_1');
insert into FUNCTORS values('FROMENGPREP', '1', 'FROMENGPREP_1');
insert into FUNCTORS values('LISTENGV', '1', 'LISTENGV_1');
insert into FUNCTORS values('LISTENGV', '2', 'LISTENGV_2');
insert into FUNCTORS values('THATENGRPRO', '1', NULL);
insert into FUNCTORS values('FILEENGN', '1', 'FILEENGN_1');
insert into FUNCTORS values('DIRECTORYENGN', '1', 'DIRECTORYENGN_1');
insert into FUNCTORS values('BEENGV', '1', 'BEENGV_1');
insert into FUNCTORS values('NOTENGVNEG', '1', 'NOTENGVNEG_1');
insert into FUNCTORS values('NOTENGANEG', '1', 'NOTENGANEG_1');
insert into FUNCTORS values('EXECUTABLEENGA', '1', 'EXECUTABLEENGA_2');
insert into FUNCTORS values('EXECUTABLEENGA', '2', 'EXECUTABLEENGA_2');
insert into FUNCTORS values('EMPTYENGA', '1', 'EMPTYENGA_1');
insert into FUNCTORS values('SYMLINKEDENGA', '1', 'SYMLINKEDENGA_2');
insert into FUNCTORS values('SYMLINKEDENGA', '2', 'SYMLINKEDENGA_2');
insert into FUNCTORS values('ANAENGDET', '1', 'ANAENGDET_1');
insert into FUNCTORS values('FILEBEPROP', '1', 'FILEBEPROP_1');
insert into FUNCTORS values('DIRBEPROP', '1', 'DIRBEPROP_1');
insert into FUNCTORS values('ANDENGCONJ', '1', 'ANDENGCONJ_1');
insert into FUNCTORS values('PROPERTIES', '1', 'PROPERTIES_2');
insert into FUNCTORS values('ORENGCONJ', '1', 'ORENGCONJ_1');
insert into FUNCTORS values('LOCATED', '1', 'LOCATED_1');
insert into FUNCTORS values('BEPROPS', '1', 'BEPROPS_1');*/

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
insert into FUNCTORS values('BEENGV', '2', 'BEENGV_2');
insert into FUNCTORS values('NOTENGVNEG', '1', 'NOTENGVNEG_1');
insert into FUNCTORS values('NOTENGVNEG', '2', 'NOTENGVNEG_1');
insert into FUNCTORS values('NOTENGANEG', '1', 'NOTENGANEG_1');
insert into FUNCTORS values('NOTENGANEG', '2', 'NOTENGANEG_1');
insert into FUNCTORS values('EXECUTABLEENGA', '1', 'EXECUTABLEENGA_1');
insert into FUNCTORS values('EXECUTABLEENGA', '2', 'EXECUTABLEENGA_2');
insert into FUNCTORS values('EMPTYENGA', '1', 'EMPTYENGA_1');
insert into FUNCTORS values('SYMLINKEDENGA', '1', 'SYMLINKEDENGA_2');
insert into FUNCTORS values('SYMLINKEDENGA', '2', 'SYMLINKEDENGA_2');
insert into FUNCTORS values('ANAENGDET', '1', 'ANAENGDET_1');
insert into FUNCTORS values('FILEBEPROP', '1', 'FILEBEPROP_1');
insert into FUNCTORS values('DIRBEPROP', '1', 'DIRBEPROP_1');
insert into FUNCTORS values('ANDENGCONJ', '1', 'ANDENGCONJ_1');
insert into FUNCTORS values('ANDENGCONJ', '2', 'ANDENGCONJ_1');
insert into FUNCTORS values('PROPERTIES', '1', 'PROPERTIES_1');
insert into FUNCTORS values('PROPERTIES', '2', 'PROPERTIES_2');
insert into FUNCTORS values('ORENGCONJ', '1', 'ORENGCONJ_1');
insert into FUNCTORS values('ORENGCONJ', '2', 'ORENGCONJ_1');
insert into FUNCTORS values('LOCATED', '1', 'LOCATED_1');
insert into FUNCTORS values('WHATENGPRON', '1', 'WHATENGPRON_1');

insert into FUNCTOR_TAGS values('LISTENGV', '1', 'main_verb', '1', 'type', 'action');
insert into FUNCTOR_TAGS values('LISTENGV', '1', 'imperative', '1', 'mood', 'imperative');
insert into FUNCTOR_TAGS values('BEENGV', '1', 'main_verb', '1', 'is_root', 'true');
insert into FUNCTOR_TAGS values('BEENGV', '1', 'interrogative', '1', 'mood', 'interrogative');
insert into FUNCTOR_TAGS values('BEENGV', '1', 'indicative', '1', 'mood', 'indicative');
insert into FUNCTOR_TAGS values('FILEENGN', '1', 'qword', '1', 'qword', 'what');
insert into FUNCTOR_TAGS values('WHATENGPRON', '1', 'qword', '1', 'is_qword', 'true');

insert into RULE_TO_RULE_MAP values( 'ENG_Vbar1', 'ENG_V', 'ENG_NP', '1', '2', NULL, 'RCV', NULL, 'H', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_Vbar1', 'ENG_V', 'ENG_NP', '2', '3', '4', 'N', NULL, 'N', NULL, NULL, NULL, 'CON', NULL, 'N', NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_Vbar1', 'ENG_V', 'ENG_NP', '3', '4', NULL, 'V', NULL, 'H', NULL, NULL, NULL, 'CON', NULL, 'N', NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_Vbar1', 'ENG_V', 'ENG_NP', '4', NULL, '5', 'V', NULL, 'H', NULL, NULL, NULL, 'N', NULL, 'N', NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_Vbar1', 'ENG_V', 'ENG_NP', '5', '5', '6', NULL, NULL, NULL, NULL, NULL, NULL, 'Sg', NULL, 'N', NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_Vbar1', 'ENG_V', 'ENG_NP', '6', '7', '9', NULL, NULL, NULL, NULL, NULL, NULL, 'N', 'FILEENGN', 'N', NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_Vbar1', 'ENG_V', 'ENG_NP', '7', '7', '8', NULL, NULL, NULL, NULL, NULL, NULL, 'N', 'DIRECTORYENGN', 'N', NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_Vbar1', 'ENG_V', 'ENG_NP', '8', NULL, '8', NULL, NULL, NULL, NULL, NULL, NULL, 'CON', NULL, 'N', NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_Vbar1', 'ENG_V', 'ENG_NP', '9', NULL, '10', 'V', 'BEENGV', 'H', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_Vbar1', 'ENG_V', 'ENG_NP', '10', NULL, '11', 'N', NULL, 'N', NULL, NULL, NULL, 'CON', NULL, 'N', NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_Vbar1', 'ENG_V', 'ENG_NP', '11', NULL, NULL, 'V', NULL, 'H', NULL, NULL, NULL, 'N', NULL, 'N', NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_Vbar2', 'ENG_Vbar1', 'ENG_PP', '1', NULL, NULL, 'N', NULL, 'H', NULL, NULL, NULL, 'PREP', NULL, 'N', NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_CNP', 'ENG_AP', 'ENG_N', '1', '2', '3', 'N', NULL, 'N', NULL, NULL, NULL, 'ANEG', NULL, 'H', NULL, 'ENG_Ahead', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_CNP', 'ENG_AP', 'ENG_N', '2', '4', '3', 'N', NULL, 'N', NULL, NULL, NULL, 'A', NULL, 'H', NULL, 'ENG_Ahead', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_CNP', 'ENG_AP', 'ENG_N', '3', NULL, NULL, 'N', NULL, 'N', NULL, NULL, NULL, 'CONJ', NULL, 'H', NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_CNP', 'ENG_AP', 'ENG_N', '4', '5', '5', 'N', NULL, 'N', NULL, NULL, NULL, 'ANEG', NULL, 'H', NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_CNP', 'ENG_AP', 'ENG_N', '5', '5', NULL, 'N', NULL, 'N', NULL, NULL, NULL, 'A', NULL, 'H', NULL, 'ENG_A0NEG', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_PP', 'ENG_Prep', 'ENG_NP', '1', '2', '3', 'PREP', NULL, 'H', NULL, NULL, NULL, 'N', NULL, 'N', NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_PP', 'ENG_Prep', 'ENG_NP', '2', NULL, NULL, 'PREP', NULL, 'H', NULL, NULL, NULL, 'CON', NULL, 'N', NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_PP', 'ENG_Prep', 'ENG_NP', '3', NULL, NULL, 'N', NULL, 'N', NULL, NULL, NULL, 'CON', NULL, 'N', NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_Vbar1', 'ENG_RC', '1', NULL, '2', 'N', NULL, 'H', NULL, NULL, NULL, 'RPRO', NULL, 'N', NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_Vbar1', 'ENG_RC', '2', NULL, '3', 'RCV', NULL, 'N', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_Vbar1', 'ENG_RC', '3', NULL, '4', 'RPRO', NULL, 'N', NULL, NULL, NULL, 'V', NULL, 'N', NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_Vbar1', 'ENG_RC', '4', '5', '6', 'V', NULL, 'N', NULL, NULL, NULL, 'ANEG', NULL, 'H', NULL, 'ENG_Ahead', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_Vbar1', 'ENG_RC', '5', '7', '6', 'V', NULL, 'N', NULL, NULL, NULL, 'A', NULL, 'H', NULL, 'ENG_Ahead', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_Vbar1', 'ENG_RC', '6', NULL, NULL, 'V', NULL, 'N', NULL, NULL, NULL, 'CONJ', NULL, 'H', NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_Vbar1', 'ENG_RC', '7', '8', '8', 'V', NULL, 'N', NULL, NULL, NULL, 'ANEG', NULL, 'H', NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_Vbar1', 'ENG_RC', '8', '8', NULL, 'V', NULL, 'N', NULL, NULL, NULL, 'A', NULL, 'H', NULL, 'ENG_A0NEG', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_Vbar2', 'ENG_RC', '1', NULL, '2', 'N', NULL, 'H', NULL, 'ENG_Vbar1', NULL, 'RPRO', NULL, 'N', NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_Vbar2', 'ENG_RC', '2', NULL, '3', 'RCV', NULL, 'N', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_Vbar2', 'ENG_RC', '3', NULL, '4', 'RPRO', NULL, 'N', NULL, NULL, NULL, 'V', NULL, 'N', NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_Vbar2', 'ENG_RC', '4', '5', '5', 'V', NULL, 'N', NULL, NULL, NULL, 'PREP', NULL, 'H', NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_Vbar2', 'ENG_RC', '5', '6', '7', 'V', NULL, 'N', NULL, NULL, NULL, 'ANEG', NULL, 'H', NULL, 'ENG_Ahead', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_Vbar2', 'ENG_RC', '6', '8', '7', 'V', NULL, 'N', NULL, NULL, NULL, 'A', NULL, 'H', NULL, 'ENG_Ahead', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_Vbar2', 'ENG_RC', '7', NULL, NULL, 'V', NULL, 'N', NULL, NULL, NULL, 'CONJ', NULL, 'H', NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_Vbar2', 'ENG_RC', '8', '9', '9', 'V', NULL, 'N', NULL, NULL, NULL, 'ANEG', NULL, 'H', NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_Vbar2', 'ENG_RC', '9', '9', NULL, 'V', NULL, 'N', NULL, NULL, NULL, 'A', NULL, 'H', NULL, 'ENG_A0NEG', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_IVP', 'ENG_V', 'ENG_PP', '1', NULL, NULL, 'V', NULL, 'H', NULL, NULL, NULL, 'PREP', NULL, 'N', NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_IVP', 'ENG_NV', 'ENG_PP', '1', NULL, '2', 'V', NULL, 'H', NULL, NULL, NULL, 'VNEG', NULL, 'H', NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_IVP', 'ENG_NV', 'ENG_PP', '2', NULL, NULL, 'VNEG', NULL, 'H', NULL, NULL, NULL, 'PREP', NULL, 'N', NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_IVP', 'ENG_V', 'ENG_AP', '1', '2', '3', 'V', NULL, 'H', NULL, NULL, NULL, 'ANEG', NULL, 'N', NULL, 'ENG_Ahead', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_IVP', 'ENG_V', 'ENG_AP', '2', '4', '3', 'V', NULL, 'H', NULL, NULL, NULL, 'A', NULL, 'N', NULL, 'ENG_Ahead', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_IVP', 'ENG_V', 'ENG_AP', '3', NULL, NULL, 'V', NULL, 'H', NULL, NULL, NULL, 'CONJ', NULL, 'N', NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_IVP', 'ENG_V', 'ENG_AP', '4', '5', '5', 'V', NULL, 'H', NULL, NULL, NULL, 'ANEG', NULL, 'N', NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_IVP', 'ENG_V', 'ENG_AP', '5', '5', NULL, 'V', NULL, 'H', NULL, NULL, NULL, 'A', NULL, 'N', NULL, 'ENG_A0NEG', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_IVP', 'ENG_NV', 'ENG_AP', '1', NULL, '2', 'V', NULL, 'H', NULL, NULL, NULL, 'VNEG', NULL, 'H', NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_IVP', 'ENG_NV', 'ENG_AP', '2', '3', '4', 'VNEG', NULL, 'H', NULL, NULL, NULL, 'ANEG', NULL, 'N', NULL, 'ENG_Ahead', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_IVP', 'ENG_NV', 'ENG_AP', '3', '5', '4', 'VNEG', NULL, 'H', NULL, NULL, NULL, 'A', NULL, 'N', NULL, 'ENG_Ahead', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_IVP', 'ENG_NV', 'ENG_AP', '4', NULL, NULL, 'VNEG', NULL, 'H', NULL, NULL, NULL, 'CONJ', NULL, 'N', NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_IVP', 'ENG_NV', 'ENG_AP', '5', '6', '6', 'VNEG', NULL, 'H', NULL, NULL, NULL, 'ANEG', NULL, 'N', NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_IVP', 'ENG_NV', 'ENG_AP', '6', '6', NULL, 'VNEG', NULL, 'H', NULL, NULL, NULL, 'A', NULL, 'N', NULL, 'ENG_A0NEG', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_Abar1', 'ENG_ANEG', 'ENG_A', '1', NULL, NULL, 'ANEG', NULL, 'H', NULL, NULL, NULL, 'A', NULL, 'N', NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_CONJA','ENG_CONJ','ENG_Abar1', '1', '2', NULL, 'CONJ', NULL, 'H', NULL, NULL, NULL, 'ANEG', NULL, 'N', NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_CONJA','ENG_CONJ','ENG_Abar1', '2', NULL, NULL, 'CONJ', NULL, 'H', NULL, NULL, NULL, 'A', NULL, 'N', NULL, NULL, NULL, 'ENG');

/*begin rules for statements*/
insert into RULE_TO_RULE_MAP values( 'ENG_Vbar5', 'ENG_V', 'ENG_N_Sg', '1', NULL, '2', 'N', NULL, 'N', NULL, NULL, NULL, 'CON', NULL, 'N', NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_Vbar5', 'ENG_V', 'ENG_N_Sg', '2', NULL, NULL, 'V', NULL, 'H', NULL, NULL, NULL, 'N', NULL, 'N', NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_Vbar5', 'ENG_AP', '1', NULL, NULL, 'V', NULL, 'H', NULL, NULL, NULL, 'A', NULL, 'N', NULL, NULL, NULL, 'ENG');
/*end rules for statements*/

/*begin rules for questions*/
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_Vbar1', 'ENG_AP', '1', NULL, NULL, 'V', NULL, 'H', NULL, NULL, NULL, 'A', NULL, 'N', NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_Vbar6', 'ENG_V', 'ENG_AP', '1', NULL, NULL, 'V', NULL, 'H', NULL, NULL, NULL, 'A', NULL, 'N', NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP','ENG_Pron_qw','ENG_Vbar6', '1', NULL, NULL, 'V', NULL, 'N', NULL, NULL, NULL, 'Pron', NULL, 'H', NULL, NULL, NULL, 'ENG');
/*end rules for questions*/

/*insert into RULE_TO_RULE_MAP values( 'HUN_VP', 'HUN_ImpVerbPfx', 'HUN_NP', '1', '2', NULL, 'Verb', NULL, 'H', NULL, NULL, 'Noun', NULL, 'N', NULL, NULL, 'HUN');
insert into RULE_TO_RULE_MAP values( 'HUN_VP', 'HUN_ImpVerbPfx', 'HUN_NP', '2', NULL, NULL, 'Verb', NULL, 'H', NULL, NULL, 'CON', NULL, 'N', NULL, NULL, 'HUN');
insert into RULE_TO_RULE_MAP values( 'HUN_ImpVerbPfx', 'HUN_ImpVerb', 'Vbpfx', '1', NULL, NULL, 'Verb', NULL, 'H', NULL, NULL, 'Vbpfx', NULL, 'N', NULL, NULL, 'HUN');
insert into RULE_TO_RULE_MAP values( 'HUN_VP', 'HUN_ImpVerbPfx', 'HUN_DP', '1', '2', NULL, 'Verb', NULL, 'H', NULL, NULL, 'CON', NULL, 'N', NULL, NULL, 'HUN');
insert into RULE_TO_RULE_MAP values( 'HUN_VP', 'HUN_ImpVerbPfx', 'HUN_DP', '2', '3', NULL, 'Verb', NULL, 'H', NULL, NULL, 'Num', NULL, 'N', NULL, NULL, 'HUN');
insert into RULE_TO_RULE_MAP values( 'HUN_VP', 'HUN_ImpVerbPfx', 'HUN_DP', '3', NULL, NULL, 'Verb', NULL, 'H', NULL, NULL, 'Noun', NULL, 'N', NULL, NULL, 'HUN');
*/

insert into LEXICON values('list', 'ENG', 'V', 'LISTENGV');
insert into LEXICON values('file', 'ENG', 'N', 'FILEENGN');
insert into LEXICON values('directory', 'ENG', 'N', 'DIRECTORYENGN');
insert into LEXICON values('from', 'ENG', 'PREP', 'FROMENGPREP');
insert into LEXICON values('in', 'ENG', 'PREP', 'INENGPREP');
insert into LEXICON values('is', 'ENG', 'V', 'BEENGV');
insert into LEXICON values('are', 'ENG', 'V', 'BEENGV');
insert into LEXICON values('be', 'ENG', 'V', 'BEENGV');
insert into LEXICON values('not', 'ENG', 'VNEG', 'NOTENGVNEG');
insert into LEXICON values('not', 'ENG', 'ANEG', 'NOTENGANEG');
insert into LEXICON values('that', 'ENG', 'RPRO', 'THATENGRPRO');
insert into LEXICON values('executable', 'ENG', 'A', 'EXECUTABLEENGA');
insert into LEXICON values('empty', 'ENG', 'A', 'EMPTYENGA');
insert into LEXICON values('symlinked', 'ENG', 'A', 'SYMLINKEDENGA');
insert into LEXICON values('a', 'ENG', 'DET', 'ANAENGDET');
insert into LEXICON values('an', 'ENG', 'DET', 'ANAENGDET');
insert into LEXICON values('and', 'ENG', 'CONJ', 'ANDENGCONJ');
insert into LEXICON values('but', 'ENG', 'CONJ', 'ANDENGCONJ');
insert into LEXICON values('or', 'ENG', 'CONJ', 'ORENGCONJ');
insert into LEXICON values('what', 'ENG', 'Pron', 'WHATENGPRON');
/*
insert into LEXICON values('to', 'ENG', 'PREP', 'TOENGPREP');
insert into LEXICON values('to', 'ENG', 'PAR', 'TOENGPAR');
*/

/*no value in the semantic_dependency field means no dependency*/
insert into DEPOLEX values('CON', '1', '1', NULL, NULL, NULL, NULL, NULL, NULL);
insert into DEPOLEX values('DIRECTORYENGN', '1', '1', NULL, '2', NULL, '0', 'BEENGV', '2');
insert into DEPOLEX values('DIRECTORYENGN', '1', '2', '1', '2', NULL, '1', 'CON', '1');
insert into DEPOLEX values('EMPTYENGA', '1', '1', NULL, NULL, NULL, NULL, NULL, NULL);
insert into DEPOLEX values('SYMLINKEDENGA', '1', '1', NULL, NULL, NULL, NULL, NULL, NULL);
insert into DEPOLEX values('SYMLINKEDENGA', '2', '1', NULL, NULL, NULL, NULL, NULL, NULL);
insert into DEPOLEX values('EXECUTABLEENGA', '1', '1', NULL, NULL, NULL, NULL, NULL, NULL);
insert into DEPOLEX values('EXECUTABLEENGA', '2', '1', NULL, NULL, NULL, NULL, NULL, NULL);
insert into DEPOLEX values('FILEENGN', '1', '1', NULL, '2', NULL, '0', 'BEENGV', '1');
insert into DEPOLEX values('FILEENGN', '1', '2', '1', '2', NULL, '1', 'CON', '1');
insert into DEPOLEX values('FROMENGPREP', '1', '1', NULL, '1', NULL, '0', 'DIRECTORYENGN', '1');
insert into DEPOLEX values('INENGPREP', '1', '1', NULL, '1', NULL, '0', 'DIRECTORYENGN', '1');
insert into DEPOLEX values('LISTENGV', '1', '1', NULL, NULL, NULL, '0', 'FILEENGN', '1');
insert into DEPOLEX values('LISTENGV', '2', '1', NULL, '1', NULL, '0', 'DIRECTORYENGN', '1');
insert into DEPOLEX values('THATENGRPRO', '1', '1', NULL, NULL, NULL, '0', NULL, NULL);

insert into DEPOLEX values('BEENGV', '1', '1', '1', '2', '2', '0', 'WHATENGPRON', '1');
insert into DEPOLEX values('BEENGV', '1', '2', '1', '3', '3', '0', 'NOTENGVNEG', '1');
insert into DEPOLEX values('BEENGV', '1', '3', '1', '3', NULL, '0', 'PROPERTIES', '1');
insert into DEPOLEX values('BEENGV', '2', '1', '1', '2', '2', '0', 'NOTENGVNEG', '2');
insert into DEPOLEX values('BEENGV', '2', '2', '1', '2', NULL, '0', 'PROPERTIES', '2');
insert into DEPOLEX values('NOTENGVNEG', '1', '1', NULL, '1', NULL, '0', 'PROPERTIES', '1');
insert into DEPOLEX values('NOTENGVNEG', '2', '1', NULL, '1', NULL, '0', 'PROPERTIES', '2');

/*insert into DEPOLEX values('BEENGV', '1', '1', '1', '1', NULL, '0', 'PROPERTIES', '1');
insert into DEPOLEX values('BEENGV', '2', '1', '1', '1', NULL, '0', 'PROPERTIES', '2');*/

insert into DEPOLEX values('PROPERTIES', '1', '1', '1', '2', '2', '1', 'NOTENGANEG', '1');
insert into DEPOLEX values('PROPERTIES', '1', '2', '1', '3', '3', '1', 'ANDENGCONJ', '1');
insert into DEPOLEX values('PROPERTIES', '1', '3', '1', '4', '4', '1', 'ORENGCONJ', '1');
insert into DEPOLEX values('PROPERTIES', '1', '4', '1', '4', NULL, '0', 'FILEBEPROP', '1');
insert into DEPOLEX values('PROPERTIES', '2', '1', '1', '2', '2', '1', 'NOTENGANEG', '2');
insert into DEPOLEX values('PROPERTIES', '2', '2', '1', '3', '3', '1', 'ANDENGCONJ', '2');
insert into DEPOLEX values('PROPERTIES', '2', '3', '1', '4', '4', '1', 'ORENGCONJ', '2');
insert into DEPOLEX values('PROPERTIES', '2', '4', '1', '4', NULL, '0', 'DIRBEPROP', '1');
insert into DEPOLEX values('NOTENGANEG', '1', '1', NULL, '1', NULL, '0', 'FILEBEPROP', '1');
insert into DEPOLEX values('NOTENGANEG', '2', '1', NULL, '1', NULL, '0', 'DIRBEPROP', '1');
insert into DEPOLEX values('ANDENGCONJ', '1', '1', NULL, '2', '2', '0', 'NOTENGANEG', '1');
insert into DEPOLEX values('ANDENGCONJ', '1', '2', NULL, '2', NULL, '0', 'FILEBEPROP', '1');
insert into DEPOLEX values('ANDENGCONJ', '2', '1', NULL, '2', '2', '0', 'NOTENGANEG', '2');
insert into DEPOLEX values('ANDENGCONJ', '2', '2', NULL, '2', NULL, '0', 'DIRBEPROP', '1');
insert into DEPOLEX values('ORENGCONJ', '1', '1', NULL, '2', '2', '0', 'NOTENGANEG', '1');
insert into DEPOLEX values('ORENGCONJ', '1', '2', NULL, '2', NULL, '0', 'FILEBEPROP', '1');
insert into DEPOLEX values('ORENGCONJ', '2', '1', NULL, '2', '2', '0', 'NOTENGANEG', '2');
insert into DEPOLEX values('ORENGCONJ', '2', '2', NULL, '2', NULL, '0', 'DIRBEPROP', '1');
insert into DEPOLEX values('FILEBEPROP', '1', '1', '1', '2', '2', '0', 'SYMLINKEDENGA', '1');
insert into DEPOLEX values('FILEBEPROP', '1', '2', '1', '3', '3', '0', 'EXECUTABLEENGA', '1');
/*insert into DEPOLEX values('FILEBEPROP', '1', '3', '1', '3', NULL, '0', 'LOCATED', '1');*/
insert into DEPOLEX values('FILEBEPROP', '1', '3', '1', '4', '4', '0', 'LOCATED', '1');
insert into DEPOLEX values('FILEBEPROP', '1', '4', '1', '4', NULL, '0', 'FILEENGN', '1');
insert into DEPOLEX values('DIRBEPROP', '1', '1', '1', '2', '2', '0', 'EMPTYENGA', '1');
insert into DEPOLEX values('DIRBEPROP', '1', '2', '1', '3', '3', '0', 'SYMLINKEDENGA', '2');
insert into DEPOLEX values('DIRBEPROP', '1', '3', '1', '4', '4', '0', 'EXECUTABLEENGA', '2');
/*insert into DEPOLEX values('DIRBEPROP', '1', '4', '1', '5', '5', '0', 'LOCATED', '1');*/
insert into DEPOLEX values('DIRBEPROP', '1', '4', '1', '4', NULL, '0', 'LOCATED', '1');
/*insert into DEPOLEX values('DIRBEPROP', '1', '5', '1', '6', '6', '0', 'FILEENGN', '1');
insert into DEPOLEX values('DIRBEPROP', '1', '6', '1', '6', NULL, '0', 'DIRECTORYENGN', '1');*/
insert into DEPOLEX values('LOCATED', '1', '1', '1', NULL, NULL, '0', 'INENGPREP', '1');
insert into DEPOLEX values('ANAENGDET', '1', '1', NULL, NULL, NULL, NULL, NULL, NULL);
/*insert into DEPOLEX values('TOENGPREP', '1', '1', NULL, NULL, NULL, NULL, NULL, NULL);
insert into DEPOLEX values('TOENGPAR', '1', '1', NULL, NULL, NULL, NULL, NULL, NULL);*/

insert into DEPOLEX values('WHATENGPRON', '1', '1', NULL, NULL, NULL, NULL, NULL, NULL);

/*insert into GRAMMAR values('ENG','S','ENG_VP',NULL,NULL,NULL);*/
insert into GRAMMAR values('ENG','S','ENG_VP','ENG_Punct',NULL,
'"const node_info& ENG_VP=sparser->get_node_info($1);
const node_info& ENG_Punct=sparser->get_node_info($2);
std::vector<unsigned int> nodes;
std::map<unsigned int,bool> lookup_nodes_reached;
sparser->get_nodes_by_symbol(ENG_Punct,"QuestionMark",std::string(),lookup_nodes_reached,nodes);
if(nodes.size()==1){
		const node_info& punct=sparser->get_node_info(nodes[0]);
		sparser->add_feature_to_leaf(ENG_VP,"main_verb",std::string("interrogative"),true);
}
else{
		nodes.clear();
		sparser->get_nodes_by_symbol(ENG_Punct,"FullStop",std::string(),lookup_nodes_reached,nodes);
		if(nodes.size()==1){
				const node_info& punct=sparser->get_node_info(nodes[0]);
				sparser->add_feature_to_leaf(ENG_VP,"main_verb",std::string("indicative"),true);
		}
		else{
				sparser->add_feature_to_leaf(ENG_VP,"main_verb",std::string("imperative"),true);
		}
}
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"S->ENG_VP ENG_Punct");
$$=sparser->combine_nodes("S",ENG_VP,ENG_Punct);"');
insert into GRAMMAR values('ENG','ENG_VP','ENG_Vbar1',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_VP','ENG_Vbar1','ENG_AdvP',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_VP','ENG_Vbar2',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_VP','ENG_Vbar2','ENG_PP',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_VP','ENG_Vbar3','ENG_NP',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_VP','ENG_Vbar1','ENG_RC',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_VP','ENG_Vbar2','ENG_RC',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_VP','ENG_Vbar4','ENG_DP',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_IVP','ENG_V','ENG_PP',NULL,
'"const node_info& ENG_V=sparser->get_node_info($1);
const node_info& ENG_PP=sparser->get_node_info($2);
sparser->add_feature_to_leaf(ENG_V,"RCV");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVP->ENG_V ENG_PP");
$$=sparser->combine_nodes("ENG_IVP",ENG_V,ENG_PP);"');
insert into GRAMMAR values('ENG','ENG_Vbar3','ENG_V','ENG_AdvP',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Vbar2','ENG_Vbar1','ENG_PP',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Vbar2','ENG_Vbar1','ENG_NP',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Vbar1','ENG_V','ENG_NP',NULL,
'"const node_info& ENG_V=sparser->get_node_info($1);
const node_info& ENG_NP=sparser->get_node_info($2);
sparser->add_feature_to_leaf(ENG_V,"main_verb");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar1->ENG_V ENG_NP");
$$=sparser->combine_nodes("ENG_Vbar1",ENG_V,ENG_NP);"');
insert into GRAMMAR values('ENG','ENG_Vbar4','ENG_DP','ENG_V',NULL,
'"const node_info& ENG_DP=sparser->get_node_info($1);
const node_info& ENG_V=sparser->get_node_info($2);
sparser->add_feature_to_leaf(ENG_V,"main_verb");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar4->ENG_DP ENG_V");
$$=sparser->combine_nodes("ENG_Vbar4",ENG_V,ENG_DP);"');
insert into GRAMMAR values('ENG','ENG_Vbar4','ENG_TP','ENG_V',NULL,
'"const node_info& ENG_TP=sparser->get_node_info($1);
const node_info& ENG_V=sparser->get_node_info($2);
sparser->add_feature_to_leaf(ENG_V,"main_verb");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar4->ENG_TP ENG_V");
$$=sparser->combine_nodes("ENG_Vbar4",ENG_V,ENG_TP);"');
insert into GRAMMAR values('ENG','ENG_PP','ENG_Prep','ENG_NP',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_NP','ENG_CNP',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_NP','ENG_CAP',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_NP','ENG_QPro','ENG_CNP',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_CNP','ENG_AP','ENG_N',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_CNP','ENG_N',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_AdvP','ENG_Adv',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_V','ENG_V_Stem',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_V','ENG_V_Stem','ENG_V_lfea_aux',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_V_ger','ENG_V_Stem','ENG_V_lfea_ger',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_V_Stem','t_ENG_V_Stem',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_V_lfea_aux','t_ENG_V_Aux',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_V_lfea_ger','t_ENG_V_Gerund',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_QPro','t_ENG_QPRO_Stem',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_N','ENG_N_Sg',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_N','ENG_N_Pl',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_DP','ENG_Indef_Det_a','ENG_N_Sg_0Con_swC',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_DP','ENG_Indef_Det_an','ENG_N_Sg_0Con_swV',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_N_Sg_0Con','ENG_N_Stem','ENG_N_lfea_Sg',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_N_Sg_0Con_swC','ENG_N_Sg_0Con','ENG_lfea_swConsonant',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_N_Sg_0Con_swV','ENG_N_Sg_0Con','ENG_lfea_swVowel',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_N_Sg','ENG_N_Sg_0Con_swC','ENG_1Con',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_N_Sg','ENG_N_Sg_0Con_swV','ENG_1Con',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_N_Sg','ENG_1Con',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_N_Sg','ENG_N_Sg_0Con_swC',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_N_Sg','ENG_N_Sg_0Con_swV',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_N_Pl_0Con','ENG_N_Stem','ENG_N_lfea_Pl',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_N_Pl_0Con_swC','ENG_N_Pl_0Con','ENG_lfea_swConsonant',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_N_Pl_0Con_swV','ENG_N_Pl_0Con','ENG_lfea_swVowel',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_1Con','ENG_Con',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_nCon','ENG_1Con','ENG_Con',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_nCon','ENG_nCon','ENG_Con',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_N_Pl','ENG_N_Pl_0Con_swC',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_N_Pl','ENG_N_Pl_0Con_swV',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_N_Pl','ENG_N_Pl_0Con_swC','ENG_nCon',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_N_Pl','ENG_N_Pl_0Con_swV','ENG_nCon',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_N_Pl','ENG_nCon',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_N_Pl','ENG_N_Sg','ENG_nCon',NULL,
'"//Exploit read ahead triggered by the shift/reduce conflict due to this very rule and return error to make sure
//that a singular noun cannot combine with more than one constant like in ''list file abc def''
//TODO: Any better solution???
YYERROR;"');
insert into GRAMMAR values('ENG','ENG_N_Stem','t_ENG_N_Stem',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_N_lfea_Sg','t_ENG_N_Sg',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_N_lfea_Pl','t_ENG_N_Pl',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_A_Stem','t_ENG_A_Stem',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_A','ENG_A_Stem',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_CAP','ENG_1Con','ENG_N_Pl_0Con_swC',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_CAP','ENG_1Con','ENG_N_Pl_0Con_swV',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Prep','t_ENG_PREP_Stem',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Con','t_ENG_CON_Stem',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Adv','t_ENG_ADV_Stem',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_RPro','ENG_RPro_stem','ENG_RPro_lfea_relative',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_RPro_stem','t_ENG_RPRO_Stem',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_RPro_lfea_relative','t_ENG_RPRO_Relative',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Tense_particle','t_ENG_PAR_Stem',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_TP','ENG_Tense_particle','ENG_V_Stem',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_TP','ENG_V_ger',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_RC','ENG_RPro','ENG_IVP',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_ANEG_Stem','t_ENG_ANEG_Stem',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_ANEG','ENG_ANEG_Stem',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Indef_Det_an','ENG_Indef_Det','ENG_lfea_fwVowel',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Indef_Det_a','ENG_Indef_Det','ENG_lfea_fwConsonant',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Indef_Det','ENG_Det_stem','ENG_lfea_IndefDet',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Det_stem','t_ENG_DET_Stem',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_lfea_IndefDet','t_ENG_DET_Indef',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_lfea_fwVowel','t_ENG_DET_fwVowel',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_lfea_fwConsonant','t_ENG_DET_fwConsonant',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_lfea_swVowel','t_ENG_N_swVowel',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_lfea_swConsonant','t_ENG_N_swConsonant',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_IVP','ENG_V','ENG_AP',NULL,
'"const node_info& ENG_V=sparser->get_node_info($1);
const node_info& ENG_AP=sparser->get_node_info($2);
sparser->add_feature_to_leaf(ENG_V,"RCV");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVP->ENG_V ENG_AP");
$$=sparser->combine_nodes("ENG_IVP",ENG_V,ENG_AP);"');
insert into GRAMMAR values('ENG','ENG_A0NEG','ENG_A',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Abar1','ENG_ANEG','ENG_A',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Abar1','ENG_A0NEG',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Alist','ENG_Abar1','ENG_Abar1',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Alist','ENG_Alist','ENG_Abar1',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_CONJA','ENG_CONJ','ENG_Abar1',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_CONJA','ENG_CONJ','ENG_Alist',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Abar2','ENG_Ahead','ENG_CONJA',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Abar2','ENG_Alist','ENG_CONJA',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Abar2','ENG_Abar2','ENG_CONJA',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Ahead','ENG_Abar1',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_AP','ENG_Abar1',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_AP','ENG_Abar2',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_AP','ENG_Alist',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_CONJ_Stem','t_ENG_CONJ_Stem',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_CONJ','ENG_CONJ_Stem',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_VNEG_Stem','t_ENG_VNEG_Stem',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_VNEG','ENG_VNEG_Stem',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_NV','ENG_V','ENG_VNEG',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_IVP','ENG_NV','ENG_PP',NULL,
'"const node_info& ENG_NV=sparser->get_node_info($1);
const node_info& ENG_PP=sparser->get_node_info($2);
sparser->add_feature_to_leaf(ENG_NV,"V",std::string("RCV"));
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVP->ENG_NV ENG_PP");
$$=sparser->combine_nodes("ENG_IVP",ENG_NV,ENG_PP);"');

/*begin rules for statements*/
insert into GRAMMAR values('ENG','ENG_Vbar5','ENG_N_Sg','ENG_V',NULL,
'"const node_info& ENG_N_Sg=sparser->get_node_info($1);
const node_info& ENG_V=sparser->get_node_info($2);
sparser->add_feature_to_leaf(ENG_V,"main_verb");
sparser->add_feature_to_leaf(ENG_N_Sg,"N",std::string("qword"));
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar5->ENG_N_Sg ENG_V");
$$=sparser->combine_nodes("ENG_Vbar5",ENG_V,ENG_N_Sg);"');
insert into GRAMMAR values('ENG','ENG_VP','ENG_Vbar5','ENG_DP',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_VP','ENG_Vbar5','ENG_AP',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Punct_Stem','t_ENG_Punct_Stem',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Punct_FullStop','t_ENG_Punct_FullStop',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Punct','ENG_Punct_Stem','ENG_Punct_FullStop',NULL,NULL);
/*end rules for statements*/

/*begin rules for questions*/
insert into GRAMMAR values('ENG','ENG_VP','ENG_Vbar1','ENG_AP',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Punct_QuestionMark','t_ENG_Punct_QuestionMark',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Punct','ENG_Punct_Stem','ENG_Punct_QuestionMark',NULL,NULL);
/*end rules for questions*/

/*begin rules for questions*/
insert into GRAMMAR values('ENG','ENG_Punct_ExclamationMark','t_ENG_Punct_ExclamationMark',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Punct','ENG_Punct_Stem','ENG_Punct_ExclamationMark',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Pron_Stem','t_ENG_Pron_Stem',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Pron_3sg','t_ENG_Pron_3sg',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Pron_wh','t_ENG_Pron_wh',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Pron','ENG_Pron_Stem','ENG_Pron_3sg',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Pron_qw','ENG_Pron','ENG_Pron_wh',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_VP','ENG_Pron_qw','ENG_Vbar6',NULL,
'"const node_info& ENG_Pron_qw=sparser->get_node_info($1);
const node_info& ENG_Vbar6=sparser->get_node_info($2);
sparser->add_feature_to_leaf(ENG_Pron_qw,"Pron",std::string("qword"));
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Pron_qw ENG_Vbar6");
$$=sparser->combine_nodes("ENG_VP",ENG_Pron_qw,ENG_Vbar6);"');
insert into GRAMMAR values('ENG','ENG_Vbar6','ENG_V','ENG_AP',NULL,
'"const node_info& ENG_V=sparser->get_node_info($1);
const node_info& ENG_AP=sparser->get_node_info($2);
sparser->add_feature_to_leaf(ENG_V,"main_verb");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar6->ENG_V ENG_AP");
$$=sparser->combine_nodes("ENG_Vbar6",ENG_V,ENG_AP);"');
/*end rules for questions*/


/*Mocking a missing terminal:
insert into GRAMMAR values('ENG','ENG_V','%empty',NULL,NULL,
'"lexicon empty;
std::string symbol="t_ENG_V_Stem";
auto&& symbol_token_map_entry=symbol_token_map.find(symbol);
empty.word="";
empty.gcat="V";
empty.lexeme="?";
empty.dependencies=lex->dependencies_read_for_functor("V");
empty.morphalytics=new morphan_result(empty.word,"ENG","V");
empty.token=symbol_token_map_entry->second;
empty.tokens.clear();
empty.tokens.push_back(empty.token);
empty.lexicon_entry=false;
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Empty->%empty");
$$=sparser->set_node_info("ENG_V",empty);"');
*/

/*start: taking out rules for negating adejctive phrase in relative clause*/
/*insert into GRAMMAR values('ENG','ENG_IVP','ENG_NV','ENG_AP',
NULL,'"const node_info& ENG_NV=sparser->get_node_info($1);
const node_info& ENG_AP=sparser->get_node_info($2);
sparser->add_feature_to_leaf(ENG_NV,"V","RCV");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVP->ENG_NV ENG_AP");
$$=sparser->combine_nodes("ENG_IVP",ENG_NV,ENG_AP);"');*/
/*end: taking out rules for negating relative clause*/


/*insert into GRAMMAR values('HUN','S','HUN_VP',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_VP','HUN_ImpVerbPfx','HUN_NP',NULL);
insert into GRAMMAR values('HUN','HUN_ImpVerbPfx','HUN_ImpVerb','HUN_Vbpfx',NULL);
insert into GRAMMAR values('HUN','HUN_ImpVerb','HUN_Verb_stem','HUN_Verb_lfea_ConjDefSg2',
'"const node_info& HUN_Verb_stem=sparser->get_node_info($1);
const node_info& HUN_Verb_lfea_ConjDefSg2=sparser->get_node_info($2);
sparser->add_feature_to_leaf(HUN_Verb_stem,"main_verb");
logger::singleton()->log(0,"HUN_ImpVerb->HUN_Verb_stem HUN_Verb_lfea_ConjDefSg2");
$$=sparser->combine_nodes("HUN_ImpVerb",HUN_Verb_stem,HUN_Verb_lfea_ConjDefSg2);"');*/
/*std::cout<<"HUN_ImpVerb->HUN_Verb_stem HUN_Verb_lfea_ConjDefSg2"<<std::endl;"');*/
/*insert into GRAMMAR values('HUN','HUN_Verb_lfea_ConjDefSg2','t_HUN_Verb_ConjDefSg2',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_Verb_stem','t_HUN_Verb_Stem',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_Vbpfx','t_HUN_Vbpfx_Stem',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_NP','HUN_N_Acc',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_Noun_Stem','HUN_lfea_swVowel','HUN_Noun_Stem',NULL);
insert into GRAMMAR values('HUN','HUN_Noun_Stem','HUN_lfea_swConsonant','HUN_Noun_Stem',NULL);
insert into GRAMMAR values('HUN','HUN_Noun_Stem','t_HUN_Noun_Stem',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_N_Sg','HUN_Noun_Stem',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_N_Acc','HUN_N_Sg','HUN_Con_lfea_Acc',NULL);
insert into GRAMMAR values('HUN','HUN_1Con','HUN_Con',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_nCon','HUN_1Con','HUN_Con',NULL);
insert into GRAMMAR values('HUN','HUN_nCon','HUN_nCon','HUN_Con',NULL);
insert into GRAMMAR values('HUN','HUN_N_Sg','HUN_nCon',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_N_Sg','HUN_1Con',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_Con','t_Con',NULL,
'"lexicon word;
word=lex->last_word_scanned(token::t_Con);
logger::singleton()->log(0,"Konstans:"+word.word);
$$=sparser->set_node_info("HUN_Con",word);"');*/
/*std::cout<<"Konstans:"<<word.word<<std::endl;"');*/
/*insert into GRAMMAR values('HUN','HUN_Con','HUN_lfea_swVowel','HUN_Con',NULL);
insert into GRAMMAR values('HUN','HUN_Con','HUN_lfea_swConsonant','HUN_Con',NULL);
insert into GRAMMAR values('HUN','HUN_Con_lfea_Acc','t_HUN_CON_Acc',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_Noun_lfea_Acc','t_HUN_Noun_Acc',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_Def_Det_az','HUN_Def_Det','HUN_lfea_fwVowel',NULL);
insert into GRAMMAR values('HUN','HUN_Def_Det_a','HUN_Def_Det','HUN_lfea_fwConsonant',NULL);
insert into GRAMMAR values('HUN','HUN_Def_Det','HUN_Det_stem','HUN_lfea_DefDet',NULL);
insert into GRAMMAR values('HUN','HUN_Det_stem','t_HUN_Det',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_lfea_DefDet','t_HUN_Det_Def',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_lfea_fwVowel','t_HUN_Det_fwVowel',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_lfea_fwConsonant','t_HUN_Det_fwConsonant',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_lfea_swVowel','t_HUN_Noun_swVowel',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_lfea_swConsonant','t_HUN_Noun_swConsonant',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_lfea_swVowel','t_HUN_CON_swVowel',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_lfea_swConsonant','t_HUN_CON_swConsonant',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_lfea_swVowel','t_HUN_Num_swVowel',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_lfea_swConsonant','t_HUN_Num_swConsonant',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_DP','HUN_DPbar','HUN_N_Acc',NULL);
insert into GRAMMAR values('HUN','HUN_DPbar','HUN_Def_Det_a','HUN_lfea_swConsonant',NULL);
insert into GRAMMAR values('HUN','HUN_DPbar','HUN_Def_Det_az','HUN_lfea_swVowel',NULL);
insert into GRAMMAR values('HUN','HUN_Num_Stem','t_HUN_Num_Stem',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_Num_Pref','t_HUN_Num_Npref1',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_Num_Pref','t_HUN_Num_Npref2',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_Num_Pref','t_HUN_Num_Npref3',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_Num_Pref','t_HUN_Num_Npref4',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_Num_Pref','t_HUN_Num_Npref5',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_Num_Pref','t_HUN_Num_Npref6',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_Num_Pref','t_HUN_Num_Npref7',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_Num_Pref','t_HUN_Num_Npref8',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_Num_Pref','t_HUN_Num_Npref9',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_Num_Pref','t_HUN_Num_Npref1n',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_Num_Pref','t_HUN_Num_Npref2n',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_Num_Pref','t_HUN_Num_Npref3n',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_Num_Pref','t_HUN_Num_Npref4n',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_Num_Pref','t_HUN_Num_Npref5n',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_Num_Pref','t_HUN_Num_Npref6n',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_Num_Pref','t_HUN_Num_Npref7n',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_Num_Pref','t_HUN_Num_Npref8n',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_Num_Pref','t_HUN_Num_Npref9n',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_Num_Pref','t_HUN_Num_Npref1nn',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_Num_Pref','t_HUN_Num_Npref1nnn',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_Num','HUN_Num_Pref','HUN_Num',NULL);
insert into GRAMMAR values('HUN','HUN_Num','HUN_Num_Stem',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_Num','HUN_Num','HUN_Num_lfea_Par',NULL);
insert into GRAMMAR values('HUN','HUN_Num','HUN_Num','HUN_Num_lfea_Ik',NULL);
insert into GRAMMAR values('HUN','HUN_N_Acc','HUN_Num','HUN_Num_lfea_Acc',NULL);
insert into GRAMMAR values('HUN','HUN_Num_lfea_Par','t_HUN_Num_Par',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_Num_lfea_Ik','t_HUN_Num_Ik',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_Num_lfea_Acc','t_HUN_Num_Acc',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_VP','HUN_ImpVerbPfx','HUN_DP',NULL);
insert into GRAMMAR values('HUN','HUN_N_Acc','HUN_N_Sg','HUN_Noun_lfea_Acc',NULL);
insert into GRAMMAR values('HUN','HUN_Num','HUN_lfea_swVowel','HUN_Num',NULL);
insert into GRAMMAR values('HUN','HUN_Num','HUN_lfea_swConsonant','HUN_Num',NULL);
insert into GRAMMAR values('HUN','HUN_Nums','HUN_Num','HUN_Num',NULL);
insert into GRAMMAR values('HUN','HUN_Nums','HUN_Nums','HUN_Num',NULL);
insert into GRAMMAR values('HUN','HUN_N_Acc','HUN_Nums','HUN_Num_lfea_Acc',NULL);*/

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
