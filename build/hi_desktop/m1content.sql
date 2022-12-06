PRAGMA foreign_keys = ON;
BEGIN;

insert into SETTINGS values('main_symbol','main_verb');
insert into SETTINGS values('main_verb','<V>');
insert into SETTINGS values('imperative_mood_tag','imperative');
insert into SETTINGS values('interrogative_mood_tag','interrogative');
insert into SETTINGS values('indicative_mood_tag','indicative');

insert into ROOT_TYPE values('H');
insert into ROOT_TYPE values('N');

insert into LANGUAGES values('ENG', 'English', '1', 'english.fst');

insert into SYMBOLS values('CON', 'ENG', 'Constant');
insert into SYMBOLS values('DET', 'ENG', 'Determiner');
insert into SYMBOLS values('N', 'ENG', 'Noun');
insert into SYMBOLS values('Stem', 'ENG', 'Stem');
insert into SYMBOLS values('Pl', 'ENG', 'Plural');
insert into SYMBOLS values('Sg', 'ENG', 'Singular');
insert into SYMBOLS values('3sg', 'ENG', '3rd person singular');
insert into SYMBOLS values('wh', 'ENG', 'question word');
insert into SYMBOLS values('Aux', 'ENG', 'Auxiliary');
insert into SYMBOLS values('PREP', 'ENG', 'Preposition');
insert into SYMBOLS values('PRON', 'ENG', 'Pronoun');
insert into SYMBOLS values('GEN', 'ENG', 'Genitive');
insert into SYMBOLS values('Punct', 'ENG', 'Punctuation');
insert into SYMBOLS values('FullStop', 'ENG', 'Full stop');
insert into SYMBOLS values('QuestionMark', 'ENG', 'Question mark');
insert into SYMBOLS values('ExclamationMark', 'ENG', 'Exclamation mark');
insert into SYMBOLS values('V', 'ENG', 'Verb');
insert into SYMBOLS values('S','ENG', NULL);
insert into SYMBOLS values('Num','ENG',NULL);
insert into SYMBOLS values('Nom','ENG',NULL);
insert into SYMBOLS values('Ord','ENG',NULL);
insert into SYMBOLS values('Npref1n','ENG',NULL);
insert into SYMBOLS values('Npref2n','ENG',NULL);
insert into SYMBOLS values('Npref3n','ENG',NULL);
insert into SYMBOLS values('Npref4n','ENG',NULL);
insert into SYMBOLS values('Npref5n','ENG',NULL);
insert into SYMBOLS values('Npref6n','ENG',NULL);
insert into SYMBOLS values('Npref7n','ENG',NULL);
insert into SYMBOLS values('Npref8n','ENG',NULL);
insert into SYMBOLS values('Npref9n','ENG',NULL);

insert into SYMBOLS values('t_ENG_CON_Stem','ENG',NULL);
insert into SYMBOLS values('t_ENG_CON_3sg','ENG',NULL);
insert into SYMBOLS values('t_ENG_CON_GEN','ENG',NULL);
insert into SYMBOLS values('t_ENG_DET_Stem','ENG',NULL);
insert into SYMBOLS values('t_ENG_N_Stem','ENG',NULL);
insert into SYMBOLS values('t_ENG_N_Pl','ENG',NULL);
insert into SYMBOLS values('t_ENG_N_Sg','ENG',NULL);
insert into SYMBOLS values('t_ENG_PREP_Stem','ENG',NULL);
insert into SYMBOLS values('t_ENG_PRON_Stem','ENG',NULL);
insert into SYMBOLS values('t_ENG_PRON_wh','ENG',NULL);
insert into SYMBOLS values('t_ENG_V_Stem','ENG',NULL);
insert into SYMBOLS values('t_ENG_V_3sg','ENG',NULL);
insert into SYMBOLS values('t_ENG_V_Aux','ENG',NULL);
insert into SYMBOLS values('t_ENG_Num_Stem','ENG',NULL);
insert into SYMBOLS values('t_ENG_Num_Ord','ENG',NULL);
insert into SYMBOLS values('t_ENG_Num_Nom','ENG',NULL);
insert into SYMBOLS values('t_ENG_Num_Npref1n','ENG',NULL);
insert into SYMBOLS values('t_ENG_Num_Npref2n','ENG',NULL);
insert into SYMBOLS values('t_ENG_Num_Npref3n','ENG',NULL);
insert into SYMBOLS values('t_ENG_Num_Npref4n','ENG',NULL);
insert into SYMBOLS values('t_ENG_Num_Npref5n','ENG',NULL);
insert into SYMBOLS values('t_ENG_Num_Npref6n','ENG',NULL);
insert into SYMBOLS values('t_ENG_Num_Npref7n','ENG',NULL);
insert into SYMBOLS values('t_ENG_Num_Npref8n','ENG',NULL);
insert into SYMBOLS values('t_ENG_Num_Npref9n','ENG',NULL);
insert into SYMBOLS values('t_ENG_Punct_Stem','ENG',NULL);
insert into SYMBOLS values('t_ENG_Punct_FullStop','ENG',NULL);
insert into SYMBOLS values('t_ENG_Punct_QuestionMark','ENG',NULL);
insert into SYMBOLS values('t_ENG_Punct_ExclamationMark','ENG',NULL);

insert into SYMBOLS values('ENG_N_lfea_Pl','ENG',NULL);
insert into SYMBOLS values('ENG_N_lfea_Sg','ENG',NULL);
insert into SYMBOLS values('ENG_N_Sg','ENG',NULL);
insert into SYMBOLS values('ENG_N_Pl','ENG',NULL);
insert into SYMBOLS values('ENG_N','ENG',NULL);
insert into SYMBOLS values('ENG_N_Stem','ENG',NULL);
insert into SYMBOLS values('ENG_NP','ENG',NULL);
insert into SYMBOLS values('ENG_PREP_Stem','ENG',NULL);
insert into SYMBOLS values('ENG_PREP','ENG',NULL);
insert into SYMBOLS values('ENG_PRON_Stem','ENG',NULL);
insert into SYMBOLS values('ENG_PRON_lfea_wh','ENG',NULL);
insert into SYMBOLS values('ENG_PRON_qw','ENG',NULL);
insert into SYMBOLS values('ENG_V_lfea_Aux','ENG',NULL);
insert into SYMBOLS values('ENG_V_lfea_3sg','ENG',NULL);
insert into SYMBOLS values('ENG_V_Stem','ENG',NULL);
insert into SYMBOLS values('ENG_V','ENG',NULL);
insert into SYMBOLS values('ENG_V_Aux','ENG',NULL);
insert into SYMBOLS values('ENG_PP','ENG',NULL);
insert into SYMBOLS values('ENG_VP_Imp','ENG',NULL);
insert into SYMBOLS values('ENG_VP_Ind','ENG',NULL);
insert into SYMBOLS values('ENG_VP_Int','ENG',NULL);
insert into SYMBOLS values('ENG_Vbar1','ENG',NULL);
insert into SYMBOLS values('ENG_Vbar2','ENG',NULL);
insert into SYMBOLS values('ENG_Vbar3','ENG',NULL);
insert into SYMBOLS values('ENG_DET_Stem','ENG',NULL);
insert into SYMBOLS values('ENG_DP','ENG',NULL);
insert into SYMBOLS values('ENG_Num_Ord','ENG',NULL);
insert into SYMBOLS values('ENG_Num_Nom','ENG',NULL);
insert into SYMBOLS values('ENG_Num_Stem','ENG',NULL);
insert into SYMBOLS values('ENG_Num','ENG',NULL);
insert into SYMBOLS values('ENG_Num_lfea_Ord','ENG',NULL);
insert into SYMBOLS values('ENG_Num_lfea_Nom','ENG',NULL);
insert into SYMBOLS values('ENG_Num_Pref','ENG',NULL);
insert into SYMBOLS values('ENG_Punct_Stem','ENG',NULL);
insert into SYMBOLS values('ENG_Punct_ExclamationMark','ENG',NULL);
insert into SYMBOLS values('ENG_Punct_FullStop','ENG',NULL);
insert into SYMBOLS values('ENG_Punct_QuestionMark','ENG',NULL);
insert into SYMBOLS values('ENG_Punct_Imp','ENG',NULL);
insert into SYMBOLS values('ENG_Punct_Ind','ENG',NULL);
insert into SYMBOLS values('ENG_Punct_Int','ENG',NULL);
insert into SYMBOLS values('ENG_CON','ENG',NULL);
insert into SYMBOLS values('ENG_CON_lfea_3sg','ENG',NULL);
insert into SYMBOLS values('ENG_CON_lfea_GEN','ENG',NULL);
insert into SYMBOLS values('ENG_CON_GEN','ENG',NULL);
insert into SYMBOLS values('ENG_CON_3sgGEN','ENG',NULL);
insert into SYMBOLS values('ENG_1CON','ENG',NULL);

insert into GCAT values('CON', 'Stem', 'ENG', '1',NULL,NULL);
insert into GCAT values('CON', '3sg', 'ENG', '1',NULL,NULL);
insert into GCAT values('CON', 'GEN', 'ENG', '1',NULL,NULL);
insert into GCAT values('DET', 'Stem', 'ENG', '1',NULL,NULL);
insert into GCAT values('N', 'Stem', 'ENG', '1',NULL,NULL);
insert into GCAT values('N', 'Pl', 'ENG', '1',NULL,NULL);
insert into GCAT values('N', 'Sg', 'ENG', '1',NULL,NULL);
insert into GCAT values('PREP', 'Stem', 'ENG', '1',NULL,NULL);
insert into GCAT values('PRON', 'Stem', 'ENG', '1',NULL,NULL);
insert into GCAT values('PRON', 'wh', 'ENG', '1',NULL,NULL);
insert into GCAT values('V', 'Stem', 'ENG', '1',NULL,NULL);
insert into GCAT values('V', '3sg', 'ENG', '1',NULL,NULL);
insert into GCAT values('V', 'Aux', 'ENG', '1',NULL,NULL);
insert into GCAT values('Num', 'Stem', 'ENG', '1',NULL,NULL);
insert into GCAT values('Num', 'Nom', 'ENG', '1',NULL,NULL);
insert into GCAT values('Num', 'Ord', 'ENG', '1',NULL,NULL);
insert into GCAT values('Num', 'Npref1n', 'ENG', '1',NULL,NULL);
insert into GCAT values('Num', 'Npref2n', 'ENG', '1',NULL,NULL);
insert into GCAT values('Num', 'Npref3n', 'ENG', '1',NULL,NULL);
insert into GCAT values('Num', 'Npref4n', 'ENG', '1',NULL,NULL);
insert into GCAT values('Num', 'Npref5n', 'ENG', '1',NULL,NULL);
insert into GCAT values('Num', 'Npref6n', 'ENG', '1',NULL,NULL);
insert into GCAT values('Num', 'Npref7n', 'ENG', '1',NULL,NULL);
insert into GCAT values('Num', 'Npref8n', 'ENG', '1',NULL,NULL);
insert into GCAT values('Num', 'Npref9n', 'ENG', '1',NULL,NULL);
insert into GCAT values('Punct', 'Stem', 'ENG', '1',NULL,NULL);
insert into GCAT values('Punct', 'FullStop', 'ENG', '1',NULL,NULL);
insert into GCAT values('Punct', 'QuestionMark', 'ENG', '1',NULL,NULL);
insert into GCAT values('Punct', 'ExclamationMark', 'ENG', '1',NULL,NULL);

insert into FUNCTOR_DEFS values('LISTENGV_1', 'js', '1', 'listengv_1.js');
insert into FUNCTOR_DEFS values('CONTACTENGN_1', 'js', '1', 'contactengn_1.js');
insert into FUNCTOR_DEFS values('WITHENGPREP_1', 'js', '1', 'withengprep_1.js');
insert into FUNCTOR_DEFS values('CALLENGV_1', 'js', '1', 'callengv_1.js');
insert into FUNCTOR_DEFS values('Num_1', 'js', '1', 'numeng_1.js');
insert into FUNCTOR_DEFS values('FIRSTLASTENGN_1', 'js', '1', 'firstlastengn_1.js');
insert into FUNCTOR_DEFS values('TODAYENGN_1', 'js', '1', 'todayengn_1.js');
insert into FUNCTOR_DEFS values('BEENGV_1', 'js', '1', 'beengv_1.js');

insert into FUNCTORS values('CON', '1', NULL);
insert into FUNCTORS values('CALLENGV', '1', 'CALLENGV_1');
insert into FUNCTORS values('LISTENGV', '1', 'LISTENGV_1');
insert into FUNCTORS values('CONTACTENGN', '1', 'CONTACTENGN_1');
insert into FUNCTORS values('Num', '1', 'Num_1');
insert into FUNCTORS values('FIRSTLASTENGN', '1', 'FIRSTLASTENGN_1');
insert into FUNCTORS values('WITHENGPREP', '1', 'WITHENGPREP_1');
insert into FUNCTORS values('TODAYENGN', '1', 'TODAYENGN_1');
insert into FUNCTORS values('BIRTHDAYENGN', '1', NULL);
insert into FUNCTORS values('BEENGV', '1', 'BEENGV_1');
insert into FUNCTORS values('WHENENGPRON', '1', NULL);/*its functor shall return the question word 'when' which BEENGV uses in the query*/
insert into FUNCTORS values('DATEENGN', '1', NULL);

insert into FUNCTOR_TAGS values('BEENGV', '1', 'indicative', '1', 'mood', 'indicative');

insert into LEXICON values('call', 'ENG', 'V', 'CALLENGV');
insert into LEXICON values('list', 'ENG', 'V', 'LISTENGV');
insert into LEXICON values('contact', 'ENG', 'N', 'CONTACTENGN');
insert into LEXICON values('first', 'ENG', 'N', 'FIRSTLASTENGN');
insert into LEXICON values('last', 'ENG', 'N', 'FIRSTLASTENGN');
insert into LEXICON values('with', 'ENG', 'PREP', 'WITHENGPREP');
insert into LEXICON values('today', 'ENG', 'N', 'TODAYENGN');
insert into LEXICON values('birthday', 'ENG', 'N', 'BIRTHDAYENGN');
insert into LEXICON values('be', 'ENG', 'V', 'BEENGV');
insert into LEXICON values('when', 'ENG', 'PRON', 'WHENENGPRON');

insert into GRAMMAR values('ENG','ENG_CON','t_ENG_CON_Stem',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_CON_lfea_3sg','t_ENG_CON_3sg',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_CON_lfea_GEN','t_ENG_CON_GEN',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_CON_3sgGEN','ENG_CON_lfea_3sg','ENG_CON_lfea_GEN',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_CON_GEN','ENG_CON','ENG_CON_3sgGEN',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_1CON','ENG_CON',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_N_Stem','t_ENG_N_Stem',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_N_lfea_Pl','t_ENG_N_Pl',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_N_lfea_Sg','t_ENG_N_Sg',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_N','ENG_N_Sg',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_N','ENG_N_Pl',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_N_Pl','ENG_N_Stem','ENG_N_lfea_Pl',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_N_Sg','ENG_N_Stem','ENG_N_lfea_Sg',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_N_Sg','ENG_1CON',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_NP','ENG_N',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_PREP_Stem','t_ENG_PREP_Stem',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_PREP','ENG_PREP_Stem',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_V_lfea_Aux','t_ENG_V_Aux',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_V_lfea_3sg','t_ENG_V_3sg',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_V_Stem','t_ENG_V_Stem',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_V','ENG_V_Stem',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_V','ENG_V_Stem','ENG_V_lfea_3sg',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_V_Aux','ENG_V','ENG_V_lfea_Aux',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_PP','ENG_PREP','ENG_NP',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Vbar1','ENG_V','ENG_NP',NULL,
'"const node_info& main_node=sparser->get_node_info($1);
const node_info& dependent_node=sparser->get_node_info($2);
sparser->add_feature_to_leaf(main_node,"main_verb");
std::string parent_symbol="ENG_Vbar1";
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,parent_symbol+"->"+main_node.symbol+" "+dependent_node.symbol);
$$=sparser->combine_nodes(parent_symbol,main_node,dependent_node);"');
insert into GRAMMAR values('ENG','ENG_VP_Imp','ENG_Vbar1',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_VP_Imp','ENG_Vbar1','ENG_PP',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_VP_Imp','ENG_V','ENG_DP',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_DET_Stem','t_ENG_DET_Stem',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_DP','ENG_DET_Stem','ENG_Num_Ord',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_DP','ENG_DET_Stem','ENG_Num_Nom',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_DP','ENG_DET_Stem','ENG_N',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Num_Stem','t_ENG_Num_Stem',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Num','ENG_Num_Stem',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Num_lfea_Ord','t_ENG_Num_Ord',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Num_lfea_Nom','t_ENG_Num_Nom',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Num_Ord','ENG_Num','ENG_Num_lfea_Ord',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Num_Nom','ENG_Num','ENG_Num_lfea_Nom',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Num_Pref','t_ENG_Num_Npref1n',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Num_Pref','t_ENG_Num_Npref2n',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Num_Pref','t_ENG_Num_Npref3n',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Num_Pref','t_ENG_Num_Npref4n',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Num_Pref','t_ENG_Num_Npref5n',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Num_Pref','t_ENG_Num_Npref6n',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Num_Pref','t_ENG_Num_Npref7n',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Num_Pref','t_ENG_Num_Npref8n',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Num_Pref','t_ENG_Num_Npref9n',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Num','ENG_Num_Pref','ENG_Num',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Punct_Stem','t_ENG_Punct_Stem',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Punct_ExclamationMark','t_ENG_Punct_ExclamationMark',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Punct_Imp','ENG_Punct_Stem','ENG_Punct_ExclamationMark',NULL,NULL);
insert into GRAMMAR values('ENG','S','ENG_VP_Imp','ENG_Punct_Imp',NULL,
'"const node_info& main_node=sparser->get_node_info($1);
const node_info& dependent_node=sparser->get_node_info($2);
sparser->add_feature_to_leaf(main_node,"main_verb","imperative",true);
std::string parent_symbol="S";
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,parent_symbol+"->"+main_node.symbol+" "+dependent_node.symbol);
$$=sparser->combine_nodes(parent_symbol,main_node,dependent_node);"');
/*Statements related rules{*/
insert into GRAMMAR values('ENG','S','ENG_VP_Ind','ENG_Punct_Ind',NULL,
'"const node_info& main_node=sparser->get_node_info($1);
const node_info& dependent_node=sparser->get_node_info($2);
sparser->add_feature_to_leaf(main_node,"main_verb","indicative",true);
std::string parent_symbol="S";
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,parent_symbol+"->"+main_node.symbol+" "+dependent_node.symbol);
$$=sparser->combine_nodes(parent_symbol,main_node,dependent_node);"');
insert into GRAMMAR values('ENG','ENG_Vbar2','ENG_N_Sg','ENG_V_Aux',NULL,
'"const node_info& main_node=sparser->get_node_info($1);
const node_info& dependent_node=sparser->get_node_info($2);
sparser->add_feature_to_leaf(dependent_node,"V",std::string("main_verb"));
std::string parent_symbol="ENG_Vbar2";
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,parent_symbol+"->"+main_node.symbol+" "+dependent_node.symbol);
$$=sparser->combine_nodes(parent_symbol,main_node,dependent_node);"');
insert into GRAMMAR values('ENG','ENG_VP_Ind','ENG_Vbar2','ENG_NP',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_NP','ENG_CON_GEN','ENG_N',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Punct_FullStop','t_ENG_Punct_FullStop',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Punct_Ind','ENG_Punct_Stem','ENG_Punct_FullStop',NULL,NULL);
/*}Statements related rules*/
/*Questions related rules{*/
insert into GRAMMAR values('ENG','S','ENG_VP_Int','ENG_Punct_Int',NULL,
'"const node_info& main_node=sparser->get_node_info($1);
const node_info& dependent_node=sparser->get_node_info($2);
sparser->add_feature_to_leaf(main_node,"main_verb","interrogative",true);
std::string parent_symbol="S";
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,parent_symbol+"->"+main_node.symbol+" "+dependent_node.symbol);
$$=sparser->combine_nodes(parent_symbol,main_node,dependent_node);"');
insert into GRAMMAR values('ENG','ENG_Punct_QuestionMark','t_ENG_Punct_QuestionMark',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Punct_Int','ENG_Punct_Stem','ENG_Punct_QuestionMark',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_PRON_Stem','t_ENG_PRON_Stem',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_PRON_lfea_wh','t_ENG_PRON_wh',NULL,NULL,NULL);
insert into GRAMMAR values('ENG','ENG_PRON_qw','ENG_PRON_Stem','ENG_PRON_lfea_wh',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Vbar3','ENG_PRON_qw','ENG_V_Aux',NULL,
'"const node_info& main_node=sparser->get_node_info($1);
const node_info& dependent_node=sparser->get_node_info($2);
sparser->add_feature_to_leaf(dependent_node,"main_verb");
std::string parent_symbol="ENG_Vbar3";
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,parent_symbol+"->"+main_node.symbol+" "+dependent_node.symbol);
$$=sparser->combine_nodes(parent_symbol,main_node,dependent_node);"');
insert into GRAMMAR values('ENG','ENG_VP_Int','ENG_Vbar3','ENG_NP',NULL,NULL);
/*}Questions related rules*/

insert into DEPOLEX values('LISTENGV', '1', '1', NULL, NULL, NULL, '0', 'CONTACTENGN', '1');
insert into DEPOLEX values('CONTACTENGN', '1', '1', NULL, '1', NULL, '0', 'WITHENGPREP', '1');
insert into DEPOLEX values('WITHENGPREP', '1', '1', NULL, NULL, NULL, '0', 'CON', '1');
insert into DEPOLEX values('CON', '1', '1', NULL, NULL, NULL, NULL, NULL, NULL);
insert into DEPOLEX values('CALLENGV', '1', '1', NULL, '2', NULL, '0', 'FIRSTLASTENGN', '1');
insert into DEPOLEX values('CALLENGV', '1', '2', NULL, '3', NULL, '1', 'Num', '1');
insert into DEPOLEX values('CALLENGV', '1', '3', NULL, NULL, NULL, '0', 'CON', '1');
insert into DEPOLEX values('Num', '1', '1', NULL, NULL, NULL, NULL, NULL, NULL);
insert into DEPOLEX values('FIRSTLASTENGN', '1', '1', NULL, NULL, NULL, NULL, NULL, NULL);
insert into DEPOLEX values('TODAYENGN', '1', '1', NULL, NULL, NULL, NULL, NULL, NULL);
insert into DEPOLEX values('DATEENGN', '1', '1', '1', NULL, NULL, '0', 'TODAYENGN', '1');
insert into DEPOLEX values('BEENGV', '1', '1', NULL, '2', '3', '0', 'WHENENGPRON', '1');
insert into DEPOLEX values('BEENGV', '1', '2', NULL, '3', '3', '0', 'DATEENGN', '1');
insert into DEPOLEX values('BEENGV', '1', '3', NULL, NULL, NULL, '0', 'BIRTHDAYENGN', '1');
insert into DEPOLEX values('BIRTHDAYENGN', '1', '1', NULL, NULL, NULL, '0', 'CON', '1');
insert into DEPOLEX values('WHENENGPRON', '1', '1', NULL, NULL, NULL, NULL, NULL, NULL);

insert into RULE_TO_RULE_MAP values( 'ENG_Vbar1', 'ENG_V', 'ENG_NP', '1', '2', NULL, 'V',  NULL, 'H', NULL, NULL, 'N', NULL, 'N', NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_Vbar1', 'ENG_V', 'ENG_NP', '2', NULL, NULL, 'V',  NULL, 'H', NULL, NULL, 'CON', NULL, 'N', NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP_Imp', 'ENG_Vbar1', 'ENG_PP', '1', NULL, NULL, 'N',  NULL, 'H', NULL, NULL, 'PREP', NULL, 'N', NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_PP', 'ENG_PREP', 'ENG_NP', '1', NULL, NULL, 'PREP',  NULL, 'H', NULL, NULL, 'CON', NULL, 'N', NULL, NULL, 'ENG');

insert into RULE_TO_RULE_MAP values( 'ENG_VP_Imp', 'ENG_V', 'ENG_DP', '1', '2', NULL, 'V', NULL, 'H', NULL, NULL, 'CON', NULL, 'N', NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP_Imp', 'ENG_V', 'ENG_DP', '2', '3', NULL, 'V', NULL, 'H', NULL, NULL, 'Num', NULL, 'N', NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP_Imp', 'ENG_V', 'ENG_DP', '3', NULL, NULL, 'V', NULL, 'H', NULL, NULL, 'N', NULL, 'N', NULL, NULL, 'ENG');

/*begin rules for statements*/
insert into RULE_TO_RULE_MAP values( 'ENG_Vbar2', 'ENG_N_Sg', 'ENG_V_Aux', '1', NULL, NULL, 'V', NULL, 'N', NULL, NULL, 'N', NULL, 'H', NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_NP', 'ENG_CON_GEN', 'ENG_N', '1', NULL, NULL, 'N', NULL, 'N', NULL, NULL, 'CON', NULL, 'H', NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP_Ind', 'ENG_Vbar2', 'ENG_NP', '1', NULL, NULL, 'V', NULL, 'H', NULL, NULL, 'N', NULL, 'N', NULL, NULL, 'ENG');
/*end rules for statements*/

/*begin rules for questions*/
insert into RULE_TO_RULE_MAP values( 'ENG_Vbar3', 'ENG_PRON_qw', 'ENG_V_Aux', '1', NULL, NULL, 'V', NULL, 'N', NULL, NULL, 'PRON', NULL, 'H', NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP_Int', 'ENG_Vbar3', 'ENG_NP', '1', NULL, NULL, 'V', NULL, 'H', NULL, NULL, 'N', NULL, 'N', NULL, NULL, 'ENG');
/*end rules for questions*/

COMMIT;
