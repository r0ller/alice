contact="";
for(i=0;i<parameterList.length;++i){
	if(parameterList[i].indexOf('CONTACTENGN_1')>-1){
		if(typeof arguments[i+2]!=='undefined'&&arguments[i+2].length>0){
			contact=arguments[i+2];
			break;
		}
	}
}
let result={action:'fetchContacts',params:[contact]};
return result;
