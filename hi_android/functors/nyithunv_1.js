url="";
for(i=0;i<parameterList.length;++i){
	if(parameterList[i].indexOf('CON_')>-1){
		if(typeof arguments[i+2]!=='undefined'&&arguments[i+2].length>0){
			url=arguments[i+2];
			break;
		}
	}
}
Android.openUrl(url);