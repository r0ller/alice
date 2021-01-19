contact="";
message="";
for(i=0;i<parameterList.length;++i){
	if(parameterList[i].indexOf('CONTACT_')>-1){
		if(typeof arguments[i+2]!=='undefined'&&arguments[i+2].length>0){
			contact=arguments[i+2];
		}
	}
	else if(parameterList[i].indexOf('HOGYHUNCONJ_')>-1){
		if(typeof arguments[i+2]!=='undefined'&&arguments[i+2].length>0){
			message=arguments[i+2];
		}
	}
}
Android.sendMessage(contact,message);