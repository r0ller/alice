else if(toa&HI_MORPHOLOGY&&toa&HI_SEMANTICS){
  if(crh>0&&modified_human_input.empty()==true){
    modified_human_input=token_paths->add_context_reference_word(crh);
  }
  else{
    if(functors_with_matching_nr_of_deps.empty()==true){
      std::vector<lexicon> words=lex->word_entries();
      std::map<unsigned int,lexicon> main_verbs=lex->find_main_verb(words);
      if(main_verbs.size()==0){
        std::multiset<std::pair<std::string,unsigned int>> functors_found_union;
        std::map<std::pair<std::pair<std::string,unsigned int>,unsigned int>> functors_found_with_nr_of_deps;
        for(auto& word: words){
          std::set<std::pair<std::string,unsigned int>> lexemes_processed;
          std::set<std::pair<std::string,unsigned int>> functors_found;
          //TODO:read main verb settings
          std::string lexeme=word.lexeme;
          if(word.lexicon_entry==false) lexeme=word.gcat;
            find_functors_for_dependency_with_gcat_in_db(words,lexeme,"",word.lid,"'V'",functors_found,lexemes_processed);
            for(auto& functor_found: functors_found){
              functors_found_union.insert(functor_found);
            }
        }
        for(auto& functor:functors_found_union){
          auto functor_found=functors_found_with_nr_of_deps.find(functor);
          if(functor_found==functors_found_with_nr_of_deps.end()){
            functors_found_with_nr_of_deps.insert(std::make_pair(functor,functors_found_union.count(functor)));
          }
        }
        for(auto& functor:functors_found_with_nr_of_deps){
          if(functor->second==words.size()){
            functors_with_matching_nr_of_deps.insert(functor->first);
          }
        }
       functor_with_matching_nr_of_deps=functors_with_matching_nr_of_deps.begin();
      }
    }
    if(functor_with_matching_nr_of_deps!=functors_with_matching_nr_of_deps.end()&&modified_human_input.empty()==true){
      query_result *result=NULL;
      result=sqlite->exec_sql("SELECT * FROM LEXICON WHERE LEXEME='"+functor_with_matching_nr_of_deps->first.first+"' AND LID='"++"' AND GCAT in("++");");
      if(result!=NULL){
        std::string word=result->field_value_at_row_position(0,"word");
        //taken from tokenpaths::add_context_reference_word()
        std::string human_input=lex->work_string();
        modified_human_input=main_verb_word+" "+human_input;
        std::locale locale=std::locale();
        std::string language=lex->language();
        delete lex;
        //lex points to the same instance as ::lex so deletion is fine
        //but to assign a new lexer the global needs to be updated as well
        lex=new lexer(modified_human_input.c_str(),language.c_str(),locale,false,this);
        path_nr_to_stop_at=0;//TODO:This actually reinitializes that counter for assign_lexer() to work properly but could be done nicer. Figure out how.
        assign_lexer(lex);
      }
    }
  }
  while(lex->is_end_of_input()==false){//go through the input simulating what bison does as well but w/o syntactic analysis
  lex->next_token();
  }
  sparser->build_dependency_semantics(lex,token_paths);
  //sparser->build_dependency_semantics(toa,crh,language,lex,token_paths);
  delete sparser;
  sparser=NULL;
  transgraph=NULL;
  if(token_paths->is_any_left()==false){
    ++functor_with_matching_nr_of_deps;
    //Do the same as in line 37-56 (without checking for modified_human_input.empty()==true) to fill again modified_human_input
  }
  //delete lex;
  //lex=NULL;
  //break;
}

