contact="";
for(i=0;i<parameterList.length;++i){
	if(parameterList[i].indexOf('CON_')>-1){
		if(typeof arguments[i+2]!=='undefined'&&arguments[i+2].length>0){
			con=JSON.parse(arguments[i+2]);
			if(contact.length>0)contact=contact+" "+con.stem;
			else contact=con.stem;
		}
	}
}
return contact;