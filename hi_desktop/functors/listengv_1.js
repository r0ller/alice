console.log("printing parameters and their contents for "+arguments[0]);

output="";
for(i=0;i<parameterList.length;++i){
    console.log("parameter: "+parameterList[i]+"\n");
    console.log("value: "+arguments[i+2]+"\n");
}
return output;
