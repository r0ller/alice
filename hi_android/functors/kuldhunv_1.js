send="true";
for(i=0;i<parameterList.length;++i){
	if(parameterList[i].indexOf('NEHUNNEG_')>-1){
		if(typeof arguments[i+2]!=='undefined'&&arguments[i+2].length>0){
			if(arguments[i+2]=="false"){
				send=arguments[i+2];
				break;
			}
		}
	}
	else if(parameterList[i].indexOf('CON_')>-1){
		if(typeof arguments[i+2]!=='undefined'&&arguments[i+2].length>0){
			send=JSON.parse(arguments[i+2]);
			if(send.length>0) send=send+" "+send.stem;
			else send=send.stem;
		}
	}
}
Android.assertSend(send);