contact="";
for(i=0;i<parameterList.length;++i){
	if(parameterList[i].indexOf('CON_')>-1){
		if(typeof arguments[i+2]!=='undefined'&&arguments[i+2].length>0){
			con=JSON.parse(arguments[i+2]);
			if(contact.length>0)contact=contact+" "+con.stem;
			else contact=con.stem;
		}
	}
	else if(parameterList[i].indexOf('Noun_')>-1){
		if(typeof arguments[i+2]!=='undefined'&&arguments[i+2].length>0){
			con=JSON.parse(arguments[i+2]);
			if(contact.length>0)contact=contact+" "+con.stem;
			else contact=con.stem;
		}
	}
	else if(parameterList[i].indexOf('Num_')>-1){
		if(typeof arguments[i+2]!=='undefined'&&arguments[i+2].length>0){
			contact+=arguments[i+2];
		}
	}
	else if(parameterList[i].indexOf('FIRSTLASTENGN_')>-1){
		if(typeof arguments[i+2]!=='undefined'&&arguments[i+2].length>0){
			contact+=arguments[i+2];
		}
	}
}
Android.Call(contact);