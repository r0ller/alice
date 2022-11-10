package com.bitroller.hi;

import android.content.Intent;

import org.json.JSONArray;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Set;
import java.util.SortedSet;
import java.util.TreeSet;
import java.util.Vector;
import java.util.concurrent.atomic.AtomicInteger;

public class AnalysisParser {
    private JSONObject analysesObj;
    static private JSONArray prevMorphology;
    static private JSONArray prevSemantics;
    static private JSONArray prevFunctors;
    private Set<Integer> analysesExecuted;

    public AnalysisParser(JSONObject analyses) {
        analysesObj=analyses;
        analysesExecuted=new HashSet<Integer>();
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
            if(dependency.has("functor id")==true&&dependency.has("tags")==true){
                JSONObject tags=dependency.getJSONObject("tags");
                if(tags.has("type")==true){
                    if(tags.getString("type").contentEquals("action")) break;
                }
//                String morphemeID=dependency.getString("morpheme id");
//                JSONObject morphologyObj=getMorpheme(morphology,morphemeID);
//                if(morphologyObj.getString("gcat").contentEquals("Verb")||morphologyObj.getString("gcat").contentEquals("V")){
//                    break;
//                }
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
        boolean failed=findFunctorDependenciesForSemanticOnes(dependencies,functorDependencies,relatedDependencies,dependency,dependenciesFound,false);
        if(failed==true) dependenciesFound=null;
        else{
            List<String> idsToDelete=new ArrayList<String>();
            for(int i=0;i<dependenciesFound.length();++i){
                if(dependenciesFound.isNull(i)==true){
                    dependenciesFound.remove(i);
                }
            }
            for(int i=0;i<dependenciesFound.length();++i){
                String idToDelete = dependenciesFound.getJSONObject(i).getString("id");
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

    private boolean findFunctorDependenciesForSemanticOnes(JSONArray dependencies,JSONArray functorDependencies, JSONArray relatedDependencies,JSONObject functorDependency,JSONArray dependenciesFound, boolean optional) throws org.json.JSONException{
        AtomicInteger dependencyIndex=new AtomicInteger(0);
        JSONObject dependencyToUpdate = getSemanticDependencyWithIndex(dependenciesFound, functorDependency.getString("functor"), functorDependency.getString("d_key"), dependencyIndex);
        JSONArray dependenciesArray = new JSONArray();
        functorDependency=nextFunctorDependency(functorDependencies,functorDependency,true);
        while(functorDependency!=null){
            boolean previousDependencyFound = false;
            JSONArray semanticDependencies=getSemanticDependencies(dependencies,functorDependency.getString("semantic_dependency"),functorDependency.getString("ref_d_key"));
            int optional_parent_allowed = 0;
            if (functorDependency.getString("optional_parent_allowed").isEmpty() == false) {
                optional_parent_allowed = Integer.parseInt(functorDependency.getString("optional_parent_allowed"));
            }
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
            if(optional == false || optional == true && optional_parent_allowed !=0) {
                if (semanticDependencies.length() > 0
                        && (manner == 0 && semanticDependencies.length() == 1
                        || manner == 1 && semanticDependencies.length() >= 1
                        || manner == 2 && semanticDependencies.length() > 1)) {
                    for (int i = 0; i < semanticDependencies.length(); ++i) {
                        JSONObject semanticDependency = semanticDependencies.getJSONObject(i);
                        int insertIndex = 0;
                        for (; insertIndex < dependenciesArray.length(); ++insertIndex) {
                            String dependencyMorphemeId = dependenciesArray.getJSONObject(insertIndex).optString("morpheme id");
                            if (dependencyMorphemeId.isEmpty() == false && Integer.parseInt(dependencyMorphemeId) > Integer.parseInt(semanticDependency.getString("morpheme id"))) {
                                break;
                            }
                        }
                        if (semanticDependency.has("functor id") == true) {
                            boolean failed = findFunctorDependenciesForSemanticOnes(dependencies, functorDependencies, relatedDependencies, semanticDependency, dependenciesFound, false);
                        }
                        semanticDependency = getSemanticDependencyById(dependenciesFound, semanticDependency.getString("id"));
                        addToPos(insertIndex, semanticDependency, dependenciesArray);
                    }
                    if (d_successor > d_counter) {
                        previousDependencyFound = true;
                    } else if (d_successor == 0) {
                        break;
                    } else {
                        return true;
                    }
                } else {
                    if (d_failover >= d_counter) {
                        String semanticDependency = functorDependency.getString("semantic_dependency");
                        String refDKey = functorDependency.getString("ref_d_key");
//                        boolean previousDependencyFound = false;
                        if (semanticDependency.isEmpty() == false && refDKey.isEmpty() == false) {
                            JSONObject optionalDependency = getSemanticDependency(relatedDependencies, semanticDependency, refDKey);
                            if (optionalDependency != null) {
                                boolean failed = findFunctorDependenciesForSemanticOnes(dependencies, functorDependencies, relatedDependencies, optionalDependency, dependenciesFound, true);
                                if (failed == true) previousDependencyFound = false;
                                else previousDependencyFound = true;
                                optionalDependency = getSemanticDependencyById(dependenciesFound, optionalDependency.getString("id"));
                                addToPos(dependenciesArray.length(), optionalDependency, dependenciesArray);
                            } else previousDependencyFound = false;
                        }
                    } else {
                        return true;
                    }
                }
            }
            functorDependency = nextFunctorDependency(functorDependencies, functorDependency, previousDependencyFound);
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
            //the returned semantic dependency is not interesting, this call is only to update the dependencyIndex
            //as the dependencyToUpdate position may have changed due to deletions in dependenciesFound
            getSemanticDependencyWithIndex(dependenciesFound, dependencyToUpdate.getString("functor"), dependencyToUpdate.getString("d_key"), dependencyIndex);
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
        int d_counter=0;
        String next_d_counter="";
        if(currentDependency.has("d_counter")==true){
            d_counter=Integer.parseInt(currentDependency.getString("d_counter"));
            if(previousDependencyFound==true) {
                String d_successor=currentDependency.getString("d_successor");
                if(d_successor.isEmpty()==false) {
                    next_d_counter = String.valueOf(Integer.parseInt(d_successor));
                }
            }
            else{
                String d_failover=currentDependency.getString("d_failover");
                if(d_failover.isEmpty()==false) {
                    next_d_counter = String.valueOf(Integer.parseInt(d_failover));
                }
            }
        }
        else{
            next_d_counter="1";
        }
        if(next_d_counter.isEmpty()==false&&Integer.parseInt(next_d_counter)>d_counter) {
            for (int i = 0; i < dependencies.length(); ++i) {
                dependency = dependencies.optJSONObject(i);
                if (dependency.getString("functor").contentEquals(functor)
                        && dependency.getString("d_key").contentEquals(d_key)
                        && dependency.getString("d_counter").contentEquals(next_d_counter)) {
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
            if(analysesArray.length()>0&&analysesExecuted.size()<analysesArray.length()){
                int minNumOfCons=1000;
                int minNumOfConsAnalysisIndex=0;
                for(int i=0;i<analysesArray.length();++i){
                    if(analysesExecuted.contains(i)==false) {
                        JSONObject analysis = analysesArray.getJSONObject(i);
                        //TODO: consider adding a condition checking for the errors in the
                        //analysis being null and rank analyses together with that.
                        JSONArray morphologyArray = analysis.optJSONArray("morphology");
                        int numOfCons = 0;
                        for (int j = 0; j < morphologyArray.length(); ++j) {
                            JSONObject morpheme = morphologyArray.getJSONObject(j);
                            if (morpheme.getString("gcat").contentEquals("CON")) ++numOfCons;
                        }
                        if (numOfCons < minNumOfCons) {
                            minNumOfCons = numOfCons;
                            minNumOfConsAnalysisIndex = i;
                        }
                    }
                }
                JSONObject analysis=analysesArray.getJSONObject(minNumOfConsAnalysisIndex);
                JSONArray morphology=analysis.optJSONArray("morphology");
                JSONArray syntax=analysis.optJSONArray("syntax");
                JSONArray semantics=analysis.optJSONArray("semantics");
                JSONArray relatedSemantics=analysis.optJSONArray("related semantics");
                JSONArray functors=analysis.optJSONArray("functors");
                JSONArray errors=analysis.optJSONArray("errors");
                analysesExecuted.add(minNumOfConsAnalysisIndex);
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
                    SortedSet<Integer> indexesToDelete=new TreeSet<Integer>();
                    Set<Integer> indexesProcessed=new HashSet<Integer>();
                    //remove morphemes having CON gcat if multiple morpheme analyses are available for the same word form with different gcat
                    //or if multiple morpheme analyses are available but only with CON gcat, leave the one having the most tags
                    for(int i=0;i<morphology.length();++i){
                        JSONObject morpheme_i=morphology.getJSONObject(i);
                        if(indexesToDelete.contains(i)==false&&morpheme_i.getString("gcat").contentEquals("CON")){
                            String wordForm=morpheme_i.getString("word");
                            JSONArray tags_i=morpheme_i.optJSONArray("tags");
                            int nrOfTags=0;
                            if(tags_i!=null) nrOfTags=tags_i.length();
                            for(int j=0;j<morphology.length();++j){
                                JSONObject morpheme_j=morphology.getJSONObject(j);
                                if(i!=j&&indexesToDelete.contains(j)==false&&morpheme_j.getString("gcat").contentEquals("CON")
                                        &&morpheme_j.getString("word").contentEquals(wordForm)){
                                    JSONArray tags_j=morpheme_j.optJSONArray("tags");
                                    if(tags_j!=null&&tags_j.length()>nrOfTags) {
                                        nrOfTags = tags_j.length();
                                        indexesToDelete.add(i);
                                        break;
                                    }
                                    else{
                                        indexesToDelete.add(j);
                                    }
                                }
                                else if(i!=j&&morpheme_j.getString("gcat").contentEquals("CON")==false
                                        &&morpheme_j.getString("word").contentEquals(wordForm)){
                                    indexesToDelete.add(i);
                                    break;
                                }
                            }
                        }
                    }
                    if(indexesToDelete.isEmpty()==false){
                        Integer last=indexesToDelete.last();
                        while(indexesToDelete.first()!=last){
                            morphology.remove(last);
                            last=indexesToDelete.headSet(last).last();
                        }
                        morphology.remove(last);
                    }
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
                        if(dependency!=null) {
                            JSONObject morpheme = getMorpheme(prevMorphology, dependency.getString("morpheme id"));
                            if (LanguageChecker.getInstance().getDefaultLanguage() == "hu-HU") {
                                message.append("Megpróbálom az előző kontextusban értelmezni.");
                            } else {
                                message.append("Trying to interpret it in the previous context.");
                            }
                            Intent callingIntent = new Intent(MainActivity.getContext(), MainActivity.class);
                            callingIntent.addFlags(Intent.FLAG_ACTIVITY_REORDER_TO_FRONT);
                            callingIntent.addFlags(Intent.FLAG_ACTIVITY_SINGLE_TOP);
                            callingIntent.putExtra("tryagain", "true");
                            callingIntent.putExtra("prependWord", morpheme.getString("word"));
                            MainActivity.getContext().startActivity(callingIntent);
                        }
                        else{
                            if (LanguageChecker.getInstance().getDefaultLanguage() == "hu-HU") {
                                message.append("Nem találtam a korábbi kontextusban funktort amivel együtt ezt értelmezni tudnám.");
                            } else {
                                message.append("Didn't find functor in the previous context with which I could interpret this.");
                            }
                        }
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
