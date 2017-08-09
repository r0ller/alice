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
insert into SYMBOLS values('NEG', 'ENG', 'Negation');
insert into SYMBOLS values('RCV', 'ENG', 'Relative Clause Verb');
insert into SYMBOLS values('PAR', 'ENG', 'Tense particle');
insert into SYMBOLS values('fwVowel', 'ENG', 'following word starts with vowel');
insert into SYMBOLS values('fwConsonant', 'ENG', 'following word starts with consonant');
insert into SYMBOLS values('swVowel', 'ENG', 'word starts with vowel');
insert into SYMBOLS values('swConsonant', 'ENG', 'word starts with consonant');
insert into SYMBOLS values('Gerund', 'ENG', 'Gerund');
insert into SYMBOLS values('Verb', 'HUN', 'Ige');
insert into SYMBOLS values('ConjDefSg2', 'HUN', 'Felszólító');
insert into SYMBOLS values('Vbpfx', 'HUN', 'Igekötő');
insert into SYMBOLS values('Acc', 'HUN', 'Tárgyas');
insert into SYMBOLS values('CON', 'HUN', 'Konstans');
insert into SYMBOLS values('S','ENG',NULL);
insert into SYMBOLS values('HUN_VP','ENG',NULL);
insert into SYMBOLS values('ENG_NEG','ENG',NULL);
insert into SYMBOLS values('ENG_AdvP','ENG',NULL);
insert into SYMBOLS values('ENG_Prep','ENG',NULL);
insert into SYMBOLS values('ENG_AP','ENG',NULL);
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
insert into SYMBOLS values('HUN_Con','HUN',NULL);
insert into SYMBOLS values('HUN_Con_lfea_Acc','HUN',NULL);
insert into SYMBOLS values('HUN_Num','HUN',NULL);
insert into SYMBOLS values('HUN_Num_lfea_Ik','HUN',NULL);
insert into SYMBOLS values('HUN_Num_lfea_Par','HUN',NULL);
insert into SYMBOLS values('HUN_Num_lfea_Acc','HUN',NULL);
insert into SYMBOLS values('HUN_Num_Pref','HUN',NULL);
insert into SYMBOLS values('HUN_Num_Stem','HUN',NULL);
insert into SYMBOLS values('HUN_N_Acc','HUN',NULL);
insert into SYMBOLS values('HUN_Noun_lfea_Acc','HUN',NULL);
insert into SYMBOLS values('HUN_Nums','HUN',NULL);

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
insert into GCAT values('PAR', NULL, 'ENG', '18');
insert into GCAT values('DET', 'Indef', 'ENG', '19');
insert into GCAT values('DET', 'fwVowel', 'ENG', '20');
insert into GCAT values('DET', 'fwConsonant', 'ENG', '21');
insert into GCAT values('N', 'swVowel', 'ENG', '22');
insert into GCAT values('N', 'swConsonant', 'ENG', '23');
insert into GCAT values('V', 'Gerund', 'ENG', '24');
insert into GCAT values('Num', 'Stem', 'HUN', '25');
insert into GCAT values('Num', 'Ik', 'HUN', '26');
insert into GCAT values('Num', 'Par', 'HUN', '27');
insert into GCAT values('Num', 'Npref1', 'HUN', '28');
insert into GCAT values('Num', 'Npref2', 'HUN', '29');
insert into GCAT values('Num', 'Npref3', 'HUN', '30');
insert into GCAT values('Num', 'Npref4', 'HUN', '31');
insert into GCAT values('Num', 'Npref5', 'HUN', '32');
insert into GCAT values('Num', 'Npref6', 'HUN', '33');
insert into GCAT values('Num', 'Npref7', 'HUN', '34');
insert into GCAT values('Num', 'Npref8', 'HUN', '35');
insert into GCAT values('Num', 'Npref9', 'HUN', '36');
insert into GCAT values('Num', 'Npref1nn', 'HUN', '37');
insert into GCAT values('Num', 'Npref1nnn', 'HUN', '38');
insert into GCAT values('Det', NULL, 'HUN', '39');
insert into GCAT values('Det', 'Def', 'HUN', '40');
insert into GCAT values('Det', 'fwVowel', 'HUN', '41');
insert into GCAT values('Det', 'fwConsonant', 'HUN', '42');
insert into GCAT values('CON', 'swVowel', 'HUN', '43');
insert into GCAT values('CON', 'swConsonant', 'HUN', '44');
insert into GCAT values('Num', 'Acc', 'HUN', '45');
insert into GCAT values('Num', 'Npref1n', 'HUN', '46');
insert into GCAT values('Num', 'Npref2n', 'HUN', '47');
insert into GCAT values('Num', 'Npref3n', 'HUN', '48');
insert into GCAT values('Num', 'Npref4n', 'HUN', '49');
insert into GCAT values('Num', 'Npref5n', 'HUN', '50');
insert into GCAT values('Num', 'Npref6n', 'HUN', '51');
insert into GCAT values('Num', 'Npref7n', 'HUN', '52');
insert into GCAT values('Num', 'Npref8n', 'HUN', '53');
insert into GCAT values('Num', 'Npref9n', 'HUN', '54');
insert into GCAT values('Num', 'swVowel', 'HUN', '55');
insert into GCAT values('Num', 'swConsonant', 'HUN', '56');
insert into GCAT values('Noun', 'Stem', 'HUN', '57');
insert into GCAT values('Noun', 'Acc', 'HUN', '58');
insert into GCAT values('Noun', 'swVowel', 'HUN', '59');
insert into GCAT values('Noun', 'swConsonant', 'HUN', '60');

insert into FUNCTOR_DEFS values('NAMEENGN_1',	'return NAMEENGN_1_CON_1_IN;');
insert into FUNCTOR_DEFS values('WITHENGPREP_1', 'return NAMEENGN_1_OUT;');
insert into FUNCTOR_DEFS values('CONTACTENGN_1', NULL);
insert into FUNCTOR_DEFS values('LISTENGV_1',	'if(typeof WITHENGPREP_1_OUT===''undefined'') Android.fetchContacts('''');else Android.fetchContacts(WITHENGPREP_1_OUT)');
insert into FUNCTOR_DEFS values('PRODUCTENGN_1',	'if(PRODUCTENGN_1_CON_1_IN==''zero''||PRODUCTENGN_1_CON_1_IN==''bread'') return ''0'';else if(PRODUCTENGN_1_CON_1_IN==''one''||PRODUCTENGN_1_CON_1_IN==''milk'') return ''1'';');
insert into FUNCTOR_DEFS values('FORENGPREP_1', 'return PRODUCTENGN_1_OUT;');
insert into FUNCTOR_DEFS values('DETAILENGN_1', NULL);
insert into FUNCTOR_DEFS values('SHOWENGV_1',	'if(typeof FORENGPREP_1_OUT===''undefined'') Android.showProduct('''');else Android.showProduct(FORENGPREP_1_OUT)');
insert into FUNCTOR_DEFS values('FELHUNVBPFX_1', NULL);
insert into FUNCTOR_DEFS values('HIVHUNV_1',
'if(typeof HIVHUNV_1_CON_2_IN!==''undefined'') Android.Call(HIVHUNV_1_CON_2_IN);
else if(typeof Num_1_OUT!==''undefined''){

}');
insert into FUNCTOR_DEFS values('Num_1',
'number='''';
prevNpref='''';
isOrdinal=false;
for(i=0;i<Num_1_MORPHEMES.length;++i){
  if(Num_1_MORPHEMES[i]===''Npref1nnn''){
    if((prevNpref.length===0||prevNpref.match(/^Npref[1-9]$/)===null)&&prevNpref.match(/^Npref[1-9]n$/)===null) number+=''1'';
    else if(prevNpref.match(/^Npref[1-9]n$/)!==null) number+=''0'';
  }
  else if(Num_1_MORPHEMES[i]===''Npref1nn''){
    if(prevNpref.length===0||prevNpref.match(/^Npref[1-9]$/)===null) number+=''1'';
  }
  else if(Num_1_MORPHEMES[i]===''Npref1n''){
    if(prevNpref===''Npref1nnn'')number+=''01'';
    else number+=''1'';
  }
  else if(Num_1_MORPHEMES[i]===''Npref2n''){
    if(prevNpref===''Npref1nnn'')number+=''02'';
    else number+=''2'';
  }
  else if(Num_1_MORPHEMES[i]===''Npref3n''){
    if(prevNpref===''Npref1nnn'')number+=''03'';
    else number+=''3'';
  }
  else if(Num_1_MORPHEMES[i]===''Npref4n''){
    if(prevNpref===''Npref1nnn'')number+=''04'';
    else number+=''4'';
  }
  else if(Num_1_MORPHEMES[i]===''Npref5n''){
    if(prevNpref===''Npref1nnn'')number+=''05'';
    else number+=''5'';
  }
  else if(Num_1_MORPHEMES[i]===''Npref6n''){
    if(prevNpref===''Npref1nnn'')number+=''06'';
    else number+=''6'';
  }
  else if(Num_1_MORPHEMES[i]===''Npref7n''){
    if(prevNpref===''Npref1nnn'')number+=''07'';
    else number+=''7'';
  }
  else if(Num_1_MORPHEMES[i]===''Npref8n''){
    if(prevNpref===''Npref1nnn'')number+=''08'';
    else number+=''8'';
  }
  else if(Num_1_MORPHEMES[i]===''Npref9n''){
    if(prevNpref===''Npref1nnn'')number+=''09'';
    else number+=''9'';
  }
  else if(Num_1_MORPHEMES[i]===''Npref1''){
    if(prevNpref===''Npref1nn'')number+=''01'';
    else number+=''1'';
  }
  else if(Num_1_MORPHEMES[i]===''Npref2''){
    if(prevNpref===''Npref1nn'')number+=''02'';
    else number+=''2'';
  }
  else if(Num_1_MORPHEMES[i]===''Npref3''){
    if(prevNpref===''Npref1nn'')number+=''03'';
    else number+=''3'';
  }
  else if(Num_1_MORPHEMES[i]===''Npref4''){
    if(prevNpref===''Npref1nn'')number+=''04'';
    else number+=''4'';
  }
  else if(Num_1_MORPHEMES[i]===''Npref5''){
    if(prevNpref===''Npref1nn'')number+=''05'';
    else number+=''5'';
  }
  else if(Num_1_MORPHEMES[i]===''Npref6''){
    if(prevNpref===''Npref1nn'')number+=''06'';
    else number+=''6'';
  }
  else if(Num_1_MORPHEMES[i]===''Npref7''){
    if(prevNpref===''Npref1nn'')number+=''07'';
    else number+=''7'';
  }
  else if(Num_1_MORPHEMES[i]===''Npref8''){
    if(prevNpref===''Npref1nn'')number+=''08'';
    else number+=''8'';
  }
  else if(Num_1_MORPHEMES[i]===''Npref9''){
    if(prevNpref===''Npref1nn'')number+=''09'';
    else number+=''9'';
  }
  else if(Num_1_MORPHEMES[i]===''egy[stem]''){
    if(prevNpref===''Npref1nnn'')number+=''001'';
    else if(prevNpref===''Npref1nn'')number+=''01'';
    else number+=''1'';
  }
  else if(Num_1_MORPHEMES[i]===''kettő[stem]''){
    if(prevNpref===''Npref1nnn'')number+=''002'';
    else if(prevNpref===''Npref1nn'')number+=''02'';
    else number+=''2'';
  }
  else if(Num_1_MORPHEMES[i]===''három[stem]''){
    if(prevNpref===''Npref1nnn'')number+=''003'';
    else if(prevNpref===''Npref1nn'')number+=''03'';
    else number+=''3'';
  }
  else if(Num_1_MORPHEMES[i]===''négy[stem]''){
    if(prevNpref===''Npref1nnn'')number+=''004'';
    else if(prevNpref===''Npref1nn'')number+=''04'';
    else number+=''4'';
  }
  else if(Num_1_MORPHEMES[i]===''öt[stem]''){
    if(prevNpref===''Npref1nnn'')number+=''005'';
    else if(prevNpref===''Npref1nn'')number+=''05'';
    else number+=''5'';
  }
  else if(Num_1_MORPHEMES[i]===''hat[stem]''){
    if(prevNpref===''Npref1nnn'')number+=''006'';
    else if(prevNpref===''Npref1nn'')number+=''06'';
    else number+=''6'';
  }
  else if(Num_1_MORPHEMES[i]===''hét[stem]''){
    if(prevNpref===''Npref1nnn'')number+=''007'';
    else if(prevNpref===''Npref1nn'')number+=''07'';
    else number+=''7'';
  }
  else if(Num_1_MORPHEMES[i]===''nyolc[stem]''){
    if(prevNpref===''Npref1nnn'')number+=''008'';
    else if(prevNpref===''Npref1nn'')number+=''08'';
    else number+=''8'';
  }
  else if(Num_1_MORPHEMES[i]===''kilenc[stem]''){
    if(prevNpref===''Npref1nnn'')number+=''009'';
    else if(prevNpref===''Npref1nn'')number+=''09'';
    else number+=''9'';
  }
  else if(Num_1_MORPHEMES[i]===''tíz[stem]''){
    if(prevNpref===''Npref1nnn'')number+=''010'';
    else number+=''10'';
  }
  else if(Num_1_MORPHEMES[i]===''húsz[stem]''){
    if(prevNpref===''Npref1nnn'')number+=''020'';
    else number+=''20'';
  }
  else if(Num_1_MORPHEMES[i]===''harminc[stem]''){
    if(prevNpref===''Npref1nnn'')number+=''030'';
    else number+=''30'';
  }
  else if(Num_1_MORPHEMES[i]===''negyven[stem]''){
    if(prevNpref===''Npref1nnn'')number+=''040'';
    else number+=''40'';
  }
  else if(Num_1_MORPHEMES[i]===''ötven[stem]''){
    if(prevNpref===''Npref1nnn'')number+=''050'';
    else number+=''50'';
  }
  else if(Num_1_MORPHEMES[i]===''hatvan[stem]''){
    if(prevNpref===''Npref1nnn'')number+=''060'';
    else number+=''60'';
  }
  else if(Num_1_MORPHEMES[i]===''hetven[stem]''){
    if(prevNpref===''Npref1nnn'')number+=''070'';
    else number+=''70'';
  }
  else if(Num_1_MORPHEMES[i]===''nyolcvan[stem]''){
    if(prevNpref===''Npref1nnn'')number+=''080'';
    else number+=''80'';
  }
  else if(Num_1_MORPHEMES[i]===''kilencven[stem]''){
    if(prevNpref===''Npref1nnn'')number+=''090'';
    else number+=''90'';
  }
  else if(Num_1_MORPHEMES[i]===''száz[stem]''){
    if(prevNpref.length===0||prevNpref===''Npref1nnn'')number+=''100'';
    else number+=''00'';
  }
  else if(Num_1_MORPHEMES[i]===''ezer[stem]''){
    if(prevNpref.length===0)number+=''1000'';
    else if(prevNpref===''Npref1nn'') number+=''00000'';
    else if(prevNpref.match(/^Npref[1-9]n$/)!==null) number+=''0000'';
    else number+=''000'';
  }
  else;
  if(Num_1_MORPHEMES[i].startsWith(''Npref'')===true) prevNpref=Num_1_MORPHEMES[i];
  if(Num_1_MORPHEMES[i]===''Ik'') isOrdinal=true;
}
if(isOrdinal===true) number+=''.'';
return number');
insert into FUNCTOR_DEFS values('ELSOUTSOHUNNOUN_1', 'if(ELSOUTSOHUNNOUN_1_STEM===''első'') return 1;if(ELSOUTSOHUNNOUN_1_STEM===''utolsó'') return 0;');

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
insert into FUNCTORS values('Num', '1', 'Num_1');
insert into FUNCTORS values('ELSOUTSOHUNNOUN', '1', 'ELSOUTSOHUNNOUN_1');

insert into RULE_TO_RULE_MAP values( 'ENG_Vbar1', 'ENG_V', 'ENG_NP', '1', '2', NULL, 'RCV',  NULL, 'H', NULL, NULL, NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_Vbar1', 'ENG_V', 'ENG_NP', '2', '3', '4', 'N', NULL, 'N', NULL, 'CON', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_Vbar1', 'ENG_V', 'ENG_NP', '3', '4', NULL, 'V', NULL, 'H', NULL, 'CON', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_Vbar1', 'ENG_V', 'ENG_NP', '4', NULL, '5', 'V', NULL, 'H', NULL, 'N', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_Vbar1', 'ENG_V', 'ENG_NP', '5', '5', '6', NULL, NULL, NULL, NULL, 'Sg', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_Vbar1', 'ENG_V', 'ENG_NP', '6', '7', NULL, NULL, NULL, NULL, NULL, 'N', 'NAMEENGN', 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_Vbar1', 'ENG_V', 'ENG_NP', '7', '7', NULL, NULL, NULL, NULL, NULL, 'N', 'CONTACTENGN', 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_Vbar2', 'ENG_Vbar1', 'ENG_PP', '1', NULL, NULL, 'V', NULL, 'H', NULL, 'PREP', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_CNP', 'A', 'ENG_CNP', '1', NULL, NULL, 'A', NULL, 'H', NULL, 'N', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_PP', 'PREP', 'ENG_NP', '1', '2', '3', 'PREP', NULL, 'H', NULL, 'N', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_PP', 'PREP', 'ENG_NP', '2', NULL, NULL, 'PREP', NULL, 'H', NULL, 'CON', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_PP', 'PREP', 'ENG_NP', '3', '3', NULL, 'N', NULL, 'N', NULL, 'CON', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_Vbar1', 'ENG_RC', '1', NULL, '2', 'N', NULL, 'H', NULL, 'RPRO', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_Vbar1', 'ENG_RC', '2', NULL, '3', 'RCV', NULL, 'N', NULL, NULL, NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_Vbar1', 'ENG_RC', '3', NULL, NULL, 'RPRO', NULL, 'N', NULL, 'V', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_Vbar2', 'ENG_RC', '1', NULL, '2', 'N', NULL, 'H', 'ENG_Vbar1', 'RPRO', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_Vbar2', 'ENG_RC', '2', NULL, '3', 'RCV', NULL, 'N', NULL, NULL, NULL, NULL, NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_VP', 'ENG_Vbar2', 'ENG_RC', '3', NULL, NULL, 'RPRO', NULL, 'N', NULL, 'V', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_IVP', 'ENG_V', 'ENG_PP', '1', NULL, NULL, 'V', NULL, 'H', NULL, 'PREP', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_IVP', 'ENG_NV', 'ENG_PP', '1', NULL, '2', 'V', NULL, 'H', NULL, 'NEG', NULL, 'H', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'ENG_IVP', 'ENG_NV', 'ENG_PP', '2', NULL, NULL, 'V', NULL, 'H', NULL, 'PREP', NULL, 'N', NULL, 'ENG');
insert into RULE_TO_RULE_MAP values( 'HUN_VP', 'HUN_ImpVerbPfx', 'HUN_NP', '1', NULL, NULL, 'Verb', NULL, 'H', NULL, 'CON', NULL, 'N', NULL, 'HUN');
insert into RULE_TO_RULE_MAP values( 'HUN_ImpVerbPfx', 'HUN_ImpVerb', 'Vbpfx', '1', NULL, NULL, 'Verb', NULL, 'H', NULL, 'Vbpfx', NULL, 'N', NULL, 'HUN');
insert into RULE_TO_RULE_MAP values( 'HUN_VP', 'HUN_ImpVerbPfx', 'HUN_DP', '1', '2', NULL, 'Verb', NULL, 'H', NULL, 'CON', NULL, 'N', NULL, 'HUN');
insert into RULE_TO_RULE_MAP values( 'HUN_VP', 'HUN_ImpVerbPfx', 'HUN_DP', '2', '3', NULL, 'Verb', NULL, 'H', NULL, 'Num', NULL, 'N', NULL, 'HUN');
insert into RULE_TO_RULE_MAP values( 'HUN_VP', 'HUN_ImpVerbPfx', 'HUN_DP', '3', NULL, NULL, 'Verb', NULL, 'H', NULL, 'Noun', NULL, 'N', NULL, 'HUN');

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
insert into LEXICON values('első', 'HUN', 'Noun', 'ELSOUTSOHUNNOUN');
insert into LEXICON values('utolsó', 'HUN', 'Noun', 'ELSOUTSOHUNNOUN');

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
insert into DEPOLEX values('HIVHUNV', '1', '2', NULL, '3', NULL, '1', 'CON', '1');
insert into DEPOLEX values('HIVHUNV', '1', '3', NULL, '4', NULL, '1', 'Num', '1');
insert into DEPOLEX values('HIVHUNV', '1', '4', NULL, NULL, NULL, '1', 'ELSOUTSOHUNNOUN', '1');
insert into DEPOLEX values('FELHUNVBPFX', '1', '1', NULL, NULL, NULL, NULL, NULL, NULL);
insert into DEPOLEX values('Num', '1', '1', NULL, NULL, NULL, NULL, NULL, NULL);
insert into DEPOLEX values('ELSOUTSOHUNNOUN', '1', '1', NULL, NULL, NULL, NULL, NULL, NULL);

insert into GRAMMAR values('ENG','S','ENG_VP',NULL,NULL);
insert into GRAMMAR values('HUN','S','HUN_VP',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_VP','ENG_Vbar1',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_VP','ENG_Vbar1','ENG_AdvP',NULL);
insert into GRAMMAR values('ENG','ENG_VP','ENG_Vbar2',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_VP','ENG_Vbar2','ENG_PP',NULL);
insert into GRAMMAR values('ENG','ENG_VP','ENG_Vbar3','ENG_NP',NULL);
insert into GRAMMAR values('ENG','ENG_VP','ENG_Vbar1','ENG_RC',NULL);
insert into GRAMMAR values('ENG','ENG_VP','ENG_Vbar2','ENG_RC',NULL);
insert into GRAMMAR values('ENG','ENG_VP','ENG_Vbar4','ENG_DP',NULL);
insert into GRAMMAR values('ENG','ENG_IVP','ENG_V','ENG_PP',
'"const node_info& ENG_V=sparser->get_node_info($1);
const node_info& ENG_PP=sparser->get_node_info($2);
sparser->add_feature_to_leaf(ENG_V,"RCV");
$$=sparser->combine_nodes("ENG_IVP",ENG_V,ENG_PP);
logger::singleton()->log(0,"ENG_IVP->ENG_V ENG_PP");"');
/*std::cout<<"ENG_IVP->ENG_V ENG_PP"<<std::endl;"');*/
insert into GRAMMAR values('ENG','ENG_IVP','ENG_NV','ENG_PP',
'"const node_info& ENG_NV=sparser->get_node_info($1);
const node_info& ENG_PP=sparser->get_node_info($2);
sparser->add_feature_to_leaf(ENG_NV,"V","RCV");
$$=sparser->combine_nodes("ENG_IVP",ENG_NV,ENG_PP);
logger::singleton()->log(0,"ENG_IVP->ENG_NV ENG_PP");"');
/*std::cout<<"ENG_IVP->ENG_NV ENG_PP"<<std::endl;"');*/
insert into GRAMMAR values('ENG','ENG_NV','ENG_V','ENG_NEG',NULL);
insert into GRAMMAR values('ENG','ENG_Vbar3','ENG_V','ENG_AdvP',NULL);
insert into GRAMMAR values('ENG','ENG_Vbar2','ENG_Vbar1','ENG_PP',NULL);
insert into GRAMMAR values('ENG','ENG_Vbar2','ENG_Vbar1','ENG_NP',NULL);
insert into GRAMMAR values('ENG','ENG_Vbar1','ENG_V','ENG_NP',
'"const node_info& ENG_V=sparser->get_node_info($1);
const node_info& ENG_NP=sparser->get_node_info($2);
sparser->add_feature_to_leaf(ENG_V,"main_verb");
$$=sparser->combine_nodes("ENG_Vbar1",ENG_V,ENG_NP);
logger::singleton()->log(0,"ENG_Vbar1->ENG_V ENG_NP");"');
/*std::cout<<"ENG_Vbar1->ENG_V ENG_NP"<<std::endl;"');*/
insert into GRAMMAR values('ENG','ENG_Vbar4','ENG_DP','ENG_V',
'"const node_info& ENG_DP=sparser->get_node_info($1);
const node_info& ENG_V=sparser->get_node_info($2);
sparser->add_feature_to_leaf(ENG_V,"main_verb");
$$=sparser->combine_nodes("ENG_Vbar4",ENG_V,ENG_DP);
logger::singleton()->log(0,"ENG_Vbar4->ENG_DP ENG_V");"');
/*std::cout<<"ENG_Vbar4->ENG_DP ENG_V"<<std::endl;"');*/
insert into GRAMMAR values('ENG','ENG_Vbar4','ENG_TP','ENG_V',
'"const node_info& ENG_TP=sparser->get_node_info($1);
const node_info& ENG_V=sparser->get_node_info($2);
sparser->add_feature_to_leaf(ENG_V,"main_verb");
$$=sparser->combine_nodes("ENG_Vbar4",ENG_V,ENG_TP);
logger::singleton()->log(0,"ENG_Vbar4->ENG_TP ENG_V");"');
/*std::cout<<"ENG_Vbar4->ENG_TP ENG_V"<<std::endl;"');*/
insert into GRAMMAR values('ENG','ENG_PP','ENG_Prep','ENG_NP',NULL);
insert into GRAMMAR values('ENG','ENG_NP','ENG_CNP',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_NP','ENG_AP',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_NP','ENG_QPro','ENG_CNP',NULL);
insert into GRAMMAR values('ENG','ENG_CNP','ENG_A','ENG_CNP',NULL);
insert into GRAMMAR values('ENG','ENG_CNP','ENG_N',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_AdvP','ENG_Adv',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_V','ENG_V_Stem',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_V','ENG_V_Stem','ENG_V_lfea_aux',NULL);
insert into GRAMMAR values('ENG','ENG_V_ger','ENG_V_Stem','ENG_V_lfea_ger',NULL);
insert into GRAMMAR values('ENG','ENG_V_Stem','t_ENG_V_Stem',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_V_lfea_aux','t_ENG_V_Aux',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_V_lfea_ger','t_ENG_V_Gerund',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_QPro','t_ENG_QPRO',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_N','ENG_N_Sg',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_N','ENG_N_Pl',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_DP','ENG_Indef_Det_a','ENG_N_Sg_0Con_swC',NULL);
insert into GRAMMAR values('ENG','ENG_DP','ENG_Indef_Det_an','ENG_N_Sg_0Con_swV',NULL);
insert into GRAMMAR values('ENG','ENG_N_Sg_0Con','ENG_N_Stem','ENG_N_lfea_Sg',NULL);
insert into GRAMMAR values('ENG','ENG_N_Sg_0Con_swC','ENG_N_Sg_0Con','ENG_lfea_swConsonant',NULL);
insert into GRAMMAR values('ENG','ENG_N_Sg_0Con_swV','ENG_N_Sg_0Con','ENG_lfea_swVowel',NULL);
insert into GRAMMAR values('ENG','ENG_N_Sg','ENG_N_Sg_0Con_swC','ENG_1Con',NULL);
insert into GRAMMAR values('ENG','ENG_N_Sg','ENG_N_Sg_0Con_swV','ENG_1Con',NULL);
insert into GRAMMAR values('ENG','ENG_N_Sg','ENG_1Con',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_N_Sg','ENG_N_Sg_0Con_swC',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_N_Sg','ENG_N_Sg_0Con_swV',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_N_Pl_0Con','ENG_N_Stem','ENG_N_lfea_Pl',NULL);
insert into GRAMMAR values('ENG','ENG_N_Pl_0Con_swC','ENG_N_Pl_0Con','ENG_lfea_swConsonant',NULL);
insert into GRAMMAR values('ENG','ENG_N_Pl_0Con_swV','ENG_N_Pl_0Con','ENG_lfea_swVowel',NULL);
insert into GRAMMAR values('ENG','ENG_1Con','ENG_Con',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_nCon','ENG_1Con','ENG_Con',NULL);
insert into GRAMMAR values('ENG','ENG_nCon','ENG_nCon','ENG_Con',NULL);
insert into GRAMMAR values('ENG','ENG_N_Pl','ENG_N_Pl_0Con_swC',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_N_Pl','ENG_N_Pl_0Con_swV',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_N_Pl','ENG_N_Pl_0Con_swC','ENG_nCon',NULL);
insert into GRAMMAR values('ENG','ENG_N_Pl','ENG_N_Pl_0Con_swV','ENG_nCon',NULL);
insert into GRAMMAR values('ENG','ENG_N_Pl','ENG_nCon',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_N_Pl','ENG_N_Sg','ENG_nCon',
'"//Exploit read ahead triggered by the shift/reduce conflict due to this very rule and return error to make sure
//that a singular noun cannot combine with more than one constant like in ''list file abc def''
//TODO: Any better solution???
return -1;"');
insert into GRAMMAR values('ENG','ENG_N_Stem','t_ENG_N_Stem',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_N_lfea_Sg','t_ENG_N_Sg',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_N_lfea_Pl','t_ENG_N_Pl',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_A','t_ENG_A_Stem',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_AP','ENG_1Con','ENG_N_Pl_0Con_swC',NULL);
insert into GRAMMAR values('ENG','ENG_AP','ENG_1Con','ENG_N_Pl_0Con_swV',NULL);
insert into GRAMMAR values('ENG','ENG_Prep','t_ENG_PREP',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Con','t_Con',NULL,
'"lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_Con);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,"Constant:"+word.word);"');
/*std::cout<<"Constant:"<<word.word<<std::endl;"');*/
insert into GRAMMAR values('ENG','ENG_Adv','t_ENG_ADV',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_RPro','ENG_RPro_stem','ENG_RPro_lfea_relative',NULL);
insert into GRAMMAR values('ENG','ENG_RPro_stem','t_ENG_RPRO',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_RPro_lfea_relative','t_ENG_RPRO_Relative',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Tense_particle','t_ENG_PAR',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_TP','ENG_Tense_particle','ENG_V_Stem',NULL);
insert into GRAMMAR values('ENG','ENG_TP','ENG_V_ger',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_RC','ENG_RPro','ENG_IVP',NULL);
insert into GRAMMAR values('ENG','ENG_NEG','t_ENG_NEG_Stem',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_Indef_Det_an','ENG_Indef_Det','ENG_lfea_fwVowel',NULL);
insert into GRAMMAR values('ENG','ENG_Indef_Det_a','ENG_Indef_Det','ENG_lfea_fwConsonant',NULL);
insert into GRAMMAR values('ENG','ENG_Indef_Det','ENG_Det_stem','ENG_lfea_IndefDet',NULL);
insert into GRAMMAR values('ENG','ENG_Det_stem','t_ENG_DET',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_lfea_IndefDet','t_ENG_DET_Indef',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_lfea_fwVowel','t_ENG_DET_fwVowel',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_lfea_fwConsonant','t_ENG_DET_fwConsonant',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_lfea_swVowel','t_ENG_N_swVowel',NULL,NULL);
insert into GRAMMAR values('ENG','ENG_lfea_swConsonant','t_ENG_N_swConsonant',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_VP','HUN_ImpVerbPfx','HUN_NP',NULL);
insert into GRAMMAR values('HUN','HUN_ImpVerbPfx','HUN_ImpVerb','HUN_Vbpfx',NULL);
insert into GRAMMAR values('HUN','HUN_ImpVerb','HUN_Verb_stem','HUN_Verb_lfea_ConjDefSg2',
'"const node_info& HUN_Verb_stem=sparser->get_node_info($1);
const node_info& HUN_Verb_lfea_ConjDefSg2=sparser->get_node_info($2);
sparser->add_feature_to_leaf(HUN_Verb_stem,"main_verb");
$$=sparser->combine_nodes("HUN_ImpVerb",HUN_Verb_stem,HUN_Verb_lfea_ConjDefSg2);
logger::singleton()->log(0,"HUN_ImpVerb->HUN_Verb_stem HUN_Verb_lfea_ConjDefSg2");"');
/*std::cout<<"HUN_ImpVerb->HUN_Verb_stem HUN_Verb_lfea_ConjDefSg2"<<std::endl;"');*/
insert into GRAMMAR values('HUN','HUN_Verb_lfea_ConjDefSg2','t_HUN_Verb_ConjDefSg2',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_Verb_stem','t_HUN_Verb_Stem',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_Vbpfx','t_HUN_Vbpfx_Stem',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_NP','HUN_N_Acc',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_N_Sg','t_HUN_Noun_Stem',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_N_Acc','HUN_N_Sg','HUN_Con_lfea_Acc',NULL);
insert into GRAMMAR values('HUN','HUN_1Con','HUN_Con',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_nCon','HUN_1Con','HUN_Con',NULL);
insert into GRAMMAR values('HUN','HUN_nCon','HUN_nCon','HUN_Con',NULL);
insert into GRAMMAR values('HUN','HUN_N_Sg','HUN_nCon',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_N_Sg','HUN_1Con',NULL,NULL);
insert into GRAMMAR values('HUN','HUN_Con','t_Con',NULL,
'"lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_Con);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,"Konstans:"+word.word);"');
/*std::cout<<"Konstans:"<<word.word<<std::endl;"');*/
insert into GRAMMAR values('HUN','HUN_Con','HUN_lfea_swVowel','HUN_Con',NULL);
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
insert into GRAMMAR values('HUN','HUN_N_Acc','HUN_Nums','HUN_Num_lfea_Acc',NULL);

COMMIT;
