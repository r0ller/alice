out="";
for(i=0;i<parameterList.length;++i){
	if(parameterList[i].indexOf('_out')>-1){
		if(typeof arguments[i+2]!=='undefined'&&arguments[i+2].length>0){
			out=arguments[i+2];
			break;
		}
	}
}
return out;