number='';
prevNpref='';
isOrdinal=false;
Num_1_MORPHEMES='';
for(i=0;i<parameterList.length;++i){
	if(parameterList[i]===functionName+'_morphology'){
		if(typeof arguments[i+2]!=='undefined'&&arguments[i+2].length>0){
			Num=JSON.parse(arguments[i+2]);
			Num_1_MORPHEMES=Num.tags;
			break;
		}
	}
}
for(i=0;i<Num_1_MORPHEMES.length;++i){
  if(Num_1_MORPHEMES[i]==='Npref1nnn'){
    if((prevNpref.length===0||prevNpref.match(/^Npref[1-9]$/)===null)&&prevNpref.match(/^Npref[1-9]n$/)===null) number+='1';
    else if(prevNpref.match(/^Npref[1-9]n$/)!==null) number+='0';
  }
  else if(Num_1_MORPHEMES[i]==='Npref1nn'){
    if(prevNpref.length===0||prevNpref.match(/^Npref[1-9]$/)===null) number+='1';
  }
  else if(Num_1_MORPHEMES[i]==='Npref1n'){
    if(prevNpref==='Npref1nnn')number+='01';
    else number+='1';
  }
  else if(Num_1_MORPHEMES[i]==='Npref2n'){
    if(prevNpref==='Npref1nnn')number+='02';
    else number+='2';
  }
  else if(Num_1_MORPHEMES[i]==='Npref3n'){
    if(prevNpref==='Npref1nnn')number+='03';
    else number+='3';
  }
  else if(Num_1_MORPHEMES[i]==='Npref4n'){
    if(prevNpref==='Npref1nnn')number+='04';
    else number+='4';
  }
  else if(Num_1_MORPHEMES[i]==='Npref5n'){
    if(prevNpref==='Npref1nnn')number+='05';
    else number+='5';
  }
  else if(Num_1_MORPHEMES[i]==='Npref6n'){
    if(prevNpref==='Npref1nnn')number+='06';
    else number+='6';
  }
  else if(Num_1_MORPHEMES[i]==='Npref7n'){
    if(prevNpref==='Npref1nnn')number+='07';
    else number+='7';
  }
  else if(Num_1_MORPHEMES[i]==='Npref8n'){
    if(prevNpref==='Npref1nnn')number+='08';
    else number+='8';
  }
  else if(Num_1_MORPHEMES[i]==='Npref9n'){
    if(prevNpref==='Npref1nnn')number+='09';
    else number+='9';
  }
  else if(Num_1_MORPHEMES[i]==='Npref1'){
    if(prevNpref==='Npref1nn')number+='01';
    else number+='1';
  }
  else if(Num_1_MORPHEMES[i]==='Npref2'){
    if(prevNpref==='Npref1nn')number+='02';
    else number+='2';
  }
  else if(Num_1_MORPHEMES[i]==='Npref3'){
    if(prevNpref==='Npref1nn')number+='03';
    else number+='3';
  }
  else if(Num_1_MORPHEMES[i]==='Npref4'){
    if(prevNpref==='Npref1nn')number+='04';
    else number+='4';
  }
  else if(Num_1_MORPHEMES[i]==='Npref5'){
    if(prevNpref==='Npref1nn')number+='05';
    else number+='5';
  }
  else if(Num_1_MORPHEMES[i]==='Npref6'){
    if(prevNpref==='Npref1nn')number+='06';
    else number+='6';
  }
  else if(Num_1_MORPHEMES[i]==='Npref7'){
    if(prevNpref==='Npref1nn')number+='07';
    else number+='7';
  }
  else if(Num_1_MORPHEMES[i]==='Npref8'){
    if(prevNpref==='Npref1nn')number+='08';
    else number+='8';
  }
  else if(Num_1_MORPHEMES[i]==='Npref9'){
    if(prevNpref==='Npref1nn')number+='09';
    else number+='9';
  }
  else if(Num_1_MORPHEMES[i]==='nulla[stem]'){
  	number+='0';
  }
  else if(Num_1_MORPHEMES[i]==='egy[stem]'){
    if(prevNpref==='Npref1nnn')number+='001';
    else if(prevNpref==='Npref1nn')number+='01';
    else number+='1';
  }
  else if(Num_1_MORPHEMES[i]==='kettő[stem]'){
    if(prevNpref==='Npref1nnn')number+='002';
    else if(prevNpref==='Npref1nn')number+='02';
    else number+='2';
  }
  else if(Num_1_MORPHEMES[i]==='három[stem]'){
    if(prevNpref==='Npref1nnn')number+='003';
    else if(prevNpref==='Npref1nn')number+='03';
    else number+='3';
  }
  else if(Num_1_MORPHEMES[i]==='négy[stem]'){
    if(prevNpref==='Npref1nnn')number+='004';
    else if(prevNpref==='Npref1nn')number+='04';
    else number+='4';
  }
  else if(Num_1_MORPHEMES[i]==='öt[stem]'){
    if(prevNpref==='Npref1nnn')number+='005';
    else if(prevNpref==='Npref1nn')number+='05';
    else number+='5';
  }
  else if(Num_1_MORPHEMES[i]==='hat[stem]'){
    if(prevNpref==='Npref1nnn')number+='006';
    else if(prevNpref==='Npref1nn')number+='06';
    else number+='6';
  }
  else if(Num_1_MORPHEMES[i]==='hét[stem]'){
    if(prevNpref==='Npref1nnn')number+='007';
    else if(prevNpref==='Npref1nn')number+='07';
    else number+='7';
  }
  else if(Num_1_MORPHEMES[i]==='nyolc[stem]'){
    if(prevNpref==='Npref1nnn')number+='008';
    else if(prevNpref==='Npref1nn')number+='08';
    else number+='8';
  }
  else if(Num_1_MORPHEMES[i]==='kilenc[stem]'){
    if(prevNpref==='Npref1nnn')number+='009';
    else if(prevNpref==='Npref1nn')number+='09';
    else number+='9';
  }
  else if(Num_1_MORPHEMES[i]==='tíz[stem]'){
    if(prevNpref==='Npref1nnn')number+='010';
    else number+='10';
  }
  else if(Num_1_MORPHEMES[i]==='húsz[stem]'){
    if(prevNpref==='Npref1nnn')number+='020';
    else number+='20';
  }
  else if(Num_1_MORPHEMES[i]==='harminc[stem]'){
    if(prevNpref==='Npref1nnn')number+='030';
    else number+='30';
  }
  else if(Num_1_MORPHEMES[i]==='negyven[stem]'){
    if(prevNpref==='Npref1nnn')number+='040';
    else number+='40';
  }
  else if(Num_1_MORPHEMES[i]==='ötven[stem]'){
    if(prevNpref==='Npref1nnn')number+='050';
    else number+='50';
  }
  else if(Num_1_MORPHEMES[i]==='hatvan[stem]'){
    if(prevNpref==='Npref1nnn')number+='060';
    else number+='60';
  }
  else if(Num_1_MORPHEMES[i]==='hetven[stem]'){
    if(prevNpref==='Npref1nnn')number+='070';
    else number+='70';
  }
  else if(Num_1_MORPHEMES[i]==='nyolcvan[stem]'){
    if(prevNpref==='Npref1nnn')number+='080';
    else number+='80';
  }
  else if(Num_1_MORPHEMES[i]==='kilencven[stem]'){
    if(prevNpref==='Npref1nnn')number+='090';
    else number+='90';
  }
  else if(Num_1_MORPHEMES[i]==='száz[stem]'){
    if(prevNpref.length===0||prevNpref==='Npref1nnn')number+='100';
    else number+='00';
  }
  else if(Num_1_MORPHEMES[i]==='ezer[stem]'){
    if(prevNpref.length===0)number+='1000';
    else if(prevNpref==='Npref1nn') number+='00000';
    else if(prevNpref.match(/^Npref[1-9]n$/)!==null) number+='0000';
    else number+='000';
  }
  else;
  if(Num_1_MORPHEMES[i].indexOf('Npref')===0) prevNpref=Num_1_MORPHEMES[i];
  if(Num_1_MORPHEMES[i]==='Ik') isOrdinal=true;
}
if(isOrdinal===true) number+='.';
return number;