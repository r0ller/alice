const {execFile}=require('node:child_process');
let tags="";
for(let i=0;i<parameterList.length;++i){
    if(parameterList[i].indexOf('_tags')>-1){
        if(typeof arguments[i+2]!=='undefined'&&arguments[i+2].length>0){
            tags=JSON.parse(arguments[i+2]);
            break;
        }
    }
}
if(tags.mood=='interrogative'){
    /*Call hi_query() as wasm exported function or node.js system call*/
    jsonDoc=JSON.parse(analysis_deps);
    execFile('./hi',['-q','hi_desktop/m1.db','indicative',analysis_deps],(error, stdout, stderr) => {
        console.log(`stdout: ${stdout}`);
        if (error) {
            console.error(`exec error: ${error}`);
            return;
        }
        console.error(`stderr: ${stderr}`);
    });
}
else if(tags.mood=='indicative'){
    /*Do nothing*/
}
else if(tags.mood=='imperative'){
    /*Not part of use case*/
}
else{
    /*Error*/
}

return;
