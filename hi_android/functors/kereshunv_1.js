contact="";
for(i=0;i<parameterList.length;++i){
	if(parameterList[i].indexOf('NEVJEGYHUNN_1')>-1||parameterList[i].indexOf('NEVJEGYZEKHUNN_1')>-1){
		if(typeof arguments[i+2]!=='undefined'&&arguments[i+2].length>0){
			contact=arguments[i+2];
			break;
		}
	}
}
let result={action:'fetchContacts',params:[contact]};
return result;
