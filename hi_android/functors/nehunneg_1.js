ne="";
for(i=0;i<parameterList.length;++i){
	if(parameterList[i]===functionName+'_morphology'){
		if(typeof arguments[i+2]!=='undefined'&&arguments[i+2].length>0){
			ne="false";
			break;
		}
	}
}
return ne;