let tags="";
let date="";
for(i=0;i<parameterList.length;++i){
    if(parameterList[i].indexOf('_tags')>-1){
        if(typeof arguments[i+2]!=='undefined'&&arguments[i+2].length>0){
            tags=JSON.parse(arguments[i+2]);
            break;
        }
    }
    else if(parameterList[i].indexOf('_out')>-1){
        /*Get the result of the called functor (from depolex we know though that there's only one)*/
        date=arguments[i+2];
    }
}
if(tags.mood==='interrogative'){
    /*Not part of use case*/
}
else if(tags.mood==='indicative'){
    /*Nothing to do, date has already been stored, just pass it on*/
}
else if(tags.mood==='imperative'){
    /*Not part of use case*/
}
else{
    /*Error*/
}
return date;
