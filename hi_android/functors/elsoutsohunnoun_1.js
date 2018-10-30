elsoutso='';
for(i=0;i<parameterList.length;++i){
	if(parameterList[i]===functionName+'_morphology'){
		if(typeof arguments[i+2]!=='undefined'&&arguments[i+2].length>0){
			elsoutso=JSON.parse(arguments[i+2]);
			elsoutso=elsoutso.stem;
			break;
		}
	}
}
if(elsoutso==='első') return '1.';
else if(elsoutso==='utolsó') return '0.';
else return "";