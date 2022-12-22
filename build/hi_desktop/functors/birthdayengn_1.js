const {execFile}=require('node:child_process');
let tags="";
let date="";
for(i=0;i<parameterList.length;++i){
    if(parameterList[i].indexOf('_tags')>-1){
        if(typeof arguments[i+2]!=='undefined'&&arguments[i+2].length>0){
            tags=JSON.parse(arguments[i+2]);
            break;
        }
    }
    else if(parameterList[i].indexOf('DATEENGN_')>-1){
        date=arguments[i+2];
    }
}
if(tags.mood==='interrogative'){
    /*Not part of use case*/
}
else if(tags.mood==='indicative'){
    /*get rid of year*/
    let dateObj=new Date(date);
    let month=dateObj.getMonth()+1;
    if(month<10) month="0"+month;
    let day=dateObj.getDate();
    if(day<10) day="0"+day;
    date=month+"-"+day;
    /*Call hi_state_cvalue() as wasm exported function or node.js system call*/
    execFile('./hi',['-c','hi_desktop/m1.db',analysis_deps,functionName,date],(error, stdout, stderr) => {
        console.log(`stdout: ${stdout}`);
        if (error) {
            console.error(`exec error: ${error}`);
            return;
        }
        console.error(`stderr: ${stderr}`);
    });
}
else if(tags.mood==='imperative'){
    /*Not part of use case*/
}
else{
    /*Error*/
}
return date;
