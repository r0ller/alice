firstlast='';
for(i=0;i<parameterList.length;++i){
	if(parameterList[i]===functionName+'_morphology'){
		if(typeof arguments[i+2]!=='undefined'&&arguments[i+2].length>0){
			firstlast=JSON.parse(arguments[i+2]);
			firstlast=firstlast.stem;
			break;
		}
	}
}
if(firstlast==='first') return '1.';
else if(firstlast==='last') return '0.';
else return "";