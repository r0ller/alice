package com.bitroller.hi;

import android.content.Intent;

import org.json.JSONArray;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.List;
import java.util.Vector;
import java.util.concurrent.atomic.AtomicInteger;

public class AnalysisParser {
    private JSONObject analysesObj;
    static private JSONArray prevMorphology;
    static private JSONArray prevSemantics;
    static private JSONArray prevFunctors;

    public AnalysisParser(JSONObject analyses) {
        analysesObj=analyses;
    }

    private String transcribeDependencies(JSONArray morphology, JSONArray syntax, JSONArray dependencies, JSONArray functors, Vector<String> argList) throws org.json.JSONException {
        String script="";
        Vector<String> arguments=new Vector<String>();

        for(int i=0;i<dependencies.length();++i){
            JSONObject dependency=dependencies.optJSONObject(i);
            String functorID="";
            if(dependency.has("functor id")==true){
                functorID=dependency.getString("functor id");
            }
            else{
                functorID=dependency.getString("functor");
            }
            String dependencyID=dependency.getString("id");
            String functionName=functorID+"_"+dependencyID;
            String argument=functionName+"_out";
            argList.add(argument);
            if(dependency.has("dependencies")==true){
                script+=transcribeDependencies(morphology,syntax,dependency.getJSONArray("dependencies"),functors,arguments);
            }
            String morphologyArg="";
            if(dependency.has("morpheme id")==true) {
                String morphemeID = dependency.getString("morpheme id");
                for (int j = 0; j < morphology.length(); ++j) {
                    JSONObject morphologyObj = morphology.optJSONObject(j);
                    if (morphologyObj.getString("morpheme id").contentEquals(morphemeID)) {
                        morphologyArg = morphologyObj.toString();
                        morphologyArg = morphologyArg.replaceAll("\"", "\\\\\"");
                        break;
                    }
                }
            }
            String morphologyVarName=functionName+"_morphology";
            arguments.add(morphologyVarName);
            String argStr=arguments.toString();
            argStr=argStr.substring(1);
            argStr=argStr.substring(0,argStr.length()-1);
            String parameterList=argStr.replaceAll(" ","");
            parameterList=parameterList.replaceAll(",","','");
            parameterList="['"+parameterList+"']";
            String functorDef="";
            for(int j=0;j<functors.length();++j){
                JSONObject functor=functors.optJSONObject(j);
                if(functor.getString("functor id").contentEquals(functorID)){
                    functorDef=functor.getString("definition");
                    if(functorDef.isEmpty()==false){
                        functorDef = "function " + functionName + "(functionName,parameterList," + argStr + "){" + functorDef + "};";
                    }
                    break;
                }
            }
            if(functorDef.isEmpty()==true){
                //TODO:if functor has no definition but has dependencies, propagate the outgoing result of its dependencies to the parent.
                //However, if there are more than one functor having no definition it'll be necessary to pass on which is the last
                //functor that has a definition in order that the arguments are propagated to the right level.
                script+=functionName+"_out="+"\""+morphologyArg+"\";";
            }
            else{
                script+=morphologyVarName+"="+"\""+morphologyArg+"\";";
                script+=functorDef+functionName+"_out="+functionName+"('"+functionName+"',"+parameterList+","+argStr+");";
            }
            arguments.clear();
        }
        return script;
    }

    private JSONObject findMainFunctor(JSONArray morphology, JSONArray dependencies, JSONArray functors) throws org.json.JSONException{
        JSONObject dependency=null;
        for(int i=0;i<dependencies.length();++i) {
            dependency = dependencies.optJSONObject(i);
            if(dependency.has("functor id")==true){
                String morphemeID=dependency.getString("morpheme id");
                JSONObject morphologyObj=getMorpheme(morphology,morphemeID);
                if(morphologyObj.getString("gcat").contentEquals("Verb")||morphologyObj.getString("gcat").contentEquals("V")){
                    break;
                }
            }
            dependency=null;
        }
        return dependency;
    }

    private JSONArray mapFunctorDependenciesToSemantics(JSONArray morphology, JSONArray syntax, JSONArray dependencies, JSONArray relatedDependencies, JSONArray functors) throws org.json.JSONException {
        JSONObject dependency=findMainFunctor(morphology,dependencies,functors);
        if(dependency==null){
            return null;
        }
        String functorID=dependency.getString("functor id");
        String id=dependency.getString("id");
        JSONObject functor=null;
        JSONArray functorDependencies=null;
        for(int i=0;i<functors.length();++i){
            functor=functors.optJSONObject(i);
            if(functor.getString("functor id").contentEquals(functorID)){
                functorDependencies=functor.getJSONArray("dependencies");
                break;
            }
        }
        String dependenciesToMerge=dependencies.toString();
        dependenciesToMerge=dependenciesToMerge.substring(0,dependenciesToMerge.length()-1);
        dependenciesToMerge+=",";
        String relatedDependenciesToMerge=relatedDependencies.toString();
        relatedDependenciesToMerge=relatedDependenciesToMerge.substring(1);
        JSONArray dependenciesFound=new JSONArray(dependenciesToMerge+relatedDependenciesToMerge);
        boolean failed=findFunctorDependenciesForSemanticOnes(dependencies,functorDependencies,relatedDependencies,dependency,dependenciesFound);
        if(failed==true) dependenciesFound=null;
        else{
            List<String> idsToDelete=new ArrayList<String>();
            for(int i=0;i<dependenciesFound.length();++i){
                String idToDelete=dependenciesFound.getJSONObject(i).getString("id");
                if(idToDelete.contentEquals(id)==false){
                    idsToDelete.add(idToDelete);
                }
            }
            for(String idToDelete:idsToDelete){
                for(int i=0;i<dependenciesFound.length();++i){
                    if(dependenciesFound.getJSONObject(i).getString("id").contentEquals(idToDelete)) {
                        dependenciesFound.remove(i);
                    }
                }
            }
        }
        return dependenciesFound;
    }

    private void addToPos(int pos, JSONObject jsonObj, JSONArray jsonArr) throws org.json.JSONException{
        for (int i = jsonArr.length(); i > pos; i--){
            jsonArr.put(i, jsonArr.get(i-1));
        }
        jsonArr.put(pos, jsonObj);
    }

    private boolean findFunctorDependenciesForSemanticOnes(JSONArray dependencies,JSONArray functorDependencies, JSONArray relatedDependencies,JSONObject functorDependency,JSONArray dependenciesFound) throws org.json.JSONException{
        AtomicInteger dependencyIndex=new AtomicInteger(0);
        JSONObject dependencyToUpdate = getSemanticDependencyWithIndex(dependenciesFound, functorDependency.getString("functor"), functorDependency.getString("d_key"), dependencyIndex);
        JSONArray dependenciesArray = new JSONArray();
        functorDependency=nextFunctorDependency(functorDependencies,functorDependency,true);
        while(functorDependency!=null){
            JSONArray semanticDependencies=getSemanticDependencies(dependencies,functorDependency.getString("semantic_dependency"),functorDependency.getString("ref_d_key"));
            int manner=0;
            if(functorDependency.getString("manner").isEmpty()==false){
                manner=Integer.parseInt(functorDependency.getString("manner"));
            }
            int d_successor=0;
            if(functorDependency.getString("d_successor").isEmpty()==false){
                d_successor=Integer.parseInt(functorDependency.getString("d_successor"));
            }
            int d_failover=0;
            if(functorDependency.getString("d_failover").isEmpty()==false){
                d_failover=Integer.parseInt(functorDependency.getString("d_failover"));
            }
            int d_counter=0;
            if(functorDependency.getString("d_counter").isEmpty()==false){
                d_counter=Integer.parseInt(functorDependency.getString("d_counter"));
            }
            if(semanticDependencies.length()>0
                &&(manner==0&&semanticDependencies.length()==1
                ||manner==1&&semanticDependencies.length()>=1
                ||manner==2&&semanticDependencies.length()>1)){
                for(int i=0;i<semanticDependencies.length();++i) {
                    JSONObject semanticDependency=semanticDependencies.getJSONObject(i);
                    int insertIndex=0;
                    for(;insertIndex<dependenciesArray.length();++insertIndex) {
                        String dependencyMorphemeId=dependenciesArray.getJSONObject(insertIndex).optString("morpheme id");
                        if(dependencyMorphemeId.isEmpty()==false&&Integer.parseInt(dependencyMorphemeId)>Integer.parseInt(semanticDependency.getString("morpheme id"))){
                            break;
                        }
                    }
                    if(semanticDependency.has("functor id")==true){
                        boolean failed=findFunctorDependenciesForSemanticOnes(dependencies,functorDependencies,relatedDependencies,semanticDependency,dependenciesFound);
                    }
                    semanticDependency=getSemanticDependencyById(dependenciesFound,semanticDependency.getString("id"));
                    addToPos(insertIndex,semanticDependency,dependenciesArray);
                }
                if(d_successor>d_counter) {
                    //read d_successor
                    functorDependency = nextFunctorDependency(functorDependencies, functorDependency, true);
                }
                else if(d_successor==0){
                    break;
                }
                else{
                    return true;
                }
            }
            else{
                if(d_failover>=d_counter){
                    String semanticDependency=functorDependency.getString("semantic_dependency");
                    String refDKey=functorDependency.getString("ref_d_key");
                    boolean previousDependencyFound=false;
                    if(semanticDependency.isEmpty()==false&&refDKey.isEmpty()==false) {
                        JSONObject optionalDependency=getSemanticDependency(relatedDependencies,semanticDependency,refDKey);
                        if(optionalDependency!=null) {
                            boolean failed = findFunctorDependenciesForSemanticOnes(dependencies, functorDependencies, relatedDependencies, optionalDependency, dependenciesFound);
                            if(failed==true) previousDependencyFound=false;
                            else previousDependencyFound=true;
                            optionalDependency=getSemanticDependencyById(dependenciesFound,optionalDependency.getString("id"));
                            addToPos(dependenciesArray.length(),optionalDependency,dependenciesArray);
                        }
                        else previousDependencyFound=false;
                    }
                    functorDependency = nextFunctorDependency(functorDependencies, functorDependency, previousDependencyFound);
                    if(functorDependency!=null) {
                        int optional_parent_allowed = 0;
                        if (functorDependency.getString("optional_parent_allowed").isEmpty() == false) {
                            optional_parent_allowed = Integer.parseInt(functorDependency.getString("optional_parent_allowed"));
                        }
                        if (optional_parent_allowed == 0) return true;
                    }
                }
                else{
                    return true;
                }
            }
        }
        boolean failed=false;
        if(dependenciesArray.length()==0) failed=true;
        else{
            if(dependencyToUpdate.has("dependencies")==true) {
                JSONArray dependencyToUpdateDependenciesArray=dependencyToUpdate.getJSONArray("dependencies");
                if (dependencyToUpdateDependenciesArray.length()>0&&dependenciesArray.length()>0&&dependencyToUpdateDependenciesArray.toString().contentEquals(dependenciesArray.toString()) == false) {
                    for(int i=0;i<dependencyToUpdateDependenciesArray.length();++i){
                        dependenciesArray.put(dependencyToUpdateDependenciesArray.getJSONObject(i));
                    }
                }
            }
            dependencyToUpdate.put("dependencies",dependenciesArray );
            dependenciesFound.put(dependencyIndex.get(),dependencyToUpdate);
            for(int i=0;i<dependenciesArray.length();++i){
                JSONObject dependencyToDelete=getSemanticDependencyWithIndex(dependenciesFound,dependenciesArray.getJSONObject(i).getString("functor"),dependenciesArray.getJSONObject(i).getString("d_key"),dependencyIndex);
                dependenciesFound.remove(dependencyIndex.get());
            }
        }
        return failed;
    }

    private JSONObject getSemanticDependency(JSONArray dependencies, String functor, String d_key) throws org.json.JSONException{
        JSONObject functorFound=null;
        for(int i=0;i<dependencies.length();++i){
            JSONObject functorObj=dependencies.optJSONObject(i);
            if(functorObj.getString("functor").contentEquals(functor)
                    &&functorObj.getString("d_key").contentEquals(d_key)){
                functorFound=functorObj;
                break;
            }
        }
        return functorFound;
    }

    private JSONObject getSemanticDependencyById(JSONArray dependencies, String id) throws org.json.JSONException{
        JSONObject functorFound=null;
        for(int i=0;i<dependencies.length();++i){
            JSONObject functorObj=dependencies.optJSONObject(i);
            if(functorObj.getString("id").contentEquals(id)){
                functorFound=functorObj;
                break;
            }
        }
        return functorFound;
    }

    private JSONObject getSemanticDependencyWithIndex(JSONArray dependencies,String functor, String d_key, AtomicInteger index) throws org.json.JSONException{
        JSONObject functorFound=null;
        for(int i=0;i<dependencies.length();++i){
            JSONObject functorObj=dependencies.optJSONObject(i);
            if(functorObj.getString("functor").contentEquals(functor)
                &&functorObj.getString("d_key").contentEquals(d_key)){
                   functorFound=functorObj;
                   index.set(i);
                   break;
            }
        }
        return functorFound;
    }

    private JSONArray getSemanticDependencies(JSONArray dependencies,String functor, String d_key) throws org.json.JSONException{
        JSONArray functorsFound=new JSONArray();
        for(int index=0;index<dependencies.length();++index){
            JSONObject functorObj=dependencies.optJSONObject(index);
            if(functorObj.getString("functor").contentEquals(functor)
                &&functorObj.getString("d_key").contentEquals(d_key)){
                functorsFound.put(functorObj);
            }
        }
        return functorsFound;
    }

    private JSONObject getMorpheme(JSONArray morphology,String morphemeId) throws org.json.JSONException{
        JSONObject morpheme=null;
        for(int i=0;i<morphology.length();++i){
            morpheme=morphology.optJSONObject(i);
            if(morpheme.getString("morpheme id").contentEquals(morphemeId)){
                break;
            }
        }
        return morpheme;
    }

    private JSONObject getFunctor(JSONArray functors,String functorId) throws org.json.JSONException{
        JSONObject functor=null;
        for(int i=0;i<functors.length();++i){
            functor=functors.optJSONObject(i);
            if(functor.getString("functor id").contentEquals(functorId)){
                break;
            }
        }
        return functor;
    }

    private JSONObject nextFunctorDependency(JSONArray dependencies,JSONObject currentDependency,boolean previousDependencyFound) throws org.json.JSONException{
        JSONObject dependency=null;
        String functor=currentDependency.getString("functor");
        String d_key=currentDependency.getString("d_key");
        String d_counter="";
        if(currentDependency.has("d_counter")==true){
            if(previousDependencyFound==true) {
                String d_successor=currentDependency.getString("d_successor");
                if(d_successor.isEmpty()==false) {
                    d_counter = String.valueOf(Integer.parseInt(d_successor));
                }
            }
            else{
                String d_failover=currentDependency.getString("d_failover");
                if(d_failover.isEmpty()==false) {
                    d_counter = String.valueOf(Integer.parseInt(d_failover));
                }
            }
        }
        else{
            d_counter="1";
        }
        if(d_counter.isEmpty()==false) {
            for (int i = 0; i < dependencies.length(); ++i) {
                dependency = dependencies.optJSONObject(i);
                if (dependency.getString("functor").contentEquals(functor)
                        && dependency.getString("d_key").contentEquals(d_key)
                        && dependency.getString("d_counter").contentEquals(d_counter)) {
                    break;
                }
            }
        }
        return dependency;
    }

    public String getCommandScript(StringBuilder message){
        JSONArray analysesArray=null;
        String script="";
        Vector<String> arguments=new Vector<String>();

        try{
            analysesArray=analysesObj.getJSONArray("analyses");
            if(analysesArray.length()>0){
                JSONObject analysis=analysesArray.getJSONObject(0);
                JSONArray morphology=analysis.optJSONArray("morphology");
                JSONArray syntax=analysis.optJSONArray("syntax");
                JSONArray semantics=analysis.optJSONArray("semantics");
                JSONArray relatedSemantics=analysis.optJSONArray("related semantics");
                JSONArray functors=analysis.optJSONArray("functors");
                JSONArray errors=analysis.optJSONArray("errors");
                if(errors==null){
                    if(semantics.length()>0){
                        script=transcribeDependencies(morphology,syntax,semantics,functors,arguments);
                        prevMorphology=morphology;
                        prevSemantics=semantics;
                        prevFunctors=functors;
                    }
                    else{
                    }
                }
                else{
                    JSONArray updatedSemantics=mapFunctorDependenciesToSemantics(morphology,syntax,semantics,relatedSemantics,functors);
                    if(updatedSemantics!=null) {
                        script = transcribeDependencies(morphology, syntax, updatedSemantics, functors, arguments);
                        prevMorphology=morphology;
                        prevSemantics=updatedSemantics;
                        prevFunctors=functors;
                    }
                    else if(prevMorphology!=null&&prevSemantics!=null&&prevFunctors!=null){
                        //TODO: consider looking up mandatory dependencies of the main functor verb
                        //and prepend their words as well. However, this requires getting functor
                        //dependencies in case of successful interpretation as well.
                        JSONObject dependency=findMainFunctor(prevMorphology,prevSemantics,prevFunctors);
                        JSONObject morpheme=getMorpheme(prevMorphology,dependency.getString("morpheme id"));
                        if (LanguageChecker.getInstance().getDefaultLanguage() == "HUN"){
                            message.append("Megpróbálom az előző kontextusban értelmezni.");
                        }
                        else{
                            message.append("Trying to interpret it in the previous context.");
                        }
                        Intent callingIntent = new Intent(MainActivity.getContext(), MainActivity.class);
                        callingIntent.addFlags(Intent.FLAG_ACTIVITY_REORDER_TO_FRONT);
                        callingIntent.addFlags(Intent.FLAG_ACTIVITY_SINGLE_TOP);
                        callingIntent.putExtra("tryagain", "true");
                        callingIntent.putExtra("prependWord", morpheme.getString("word"));
                        MainActivity.getContext().startActivity(callingIntent);
                    }
                }
            }
            else{
            }
            }
        catch(org.json.JSONException e){

        }
        return script;
    }
}
