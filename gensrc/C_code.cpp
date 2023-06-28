int yylex(yy::parser::semantic_type* yylval){
	int token;
	lexicon word={};

	if(lex->is_end_of_input()==false){
		token=lex->next_token();
		logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"next token:"+std::to_string(token));
		return token;
	}
	else return 0;//historic indicator of YACC about end of input stream
}

void yy::parser::error(const std::string& msg){
	token_paths->log_yyerror(msg);
	return;
}

#ifdef __EMSCRIPTEN__
extern "C"{
#endif

#ifdef __ANDROID__
const char *hi(const char *human_input,const char *language,const unsigned char toa,const char *target_language,const char *db_uri,JavaVM *vm,jobject activityobj,const char *source,const unsigned char crh){
#else
const char *hi(const char *human_input,const char *language,const unsigned char toa,const char *target_language,const char *db_uri,const char *source,const unsigned char crh){
#endif

	std::string analyses,modified_human_input,main_verb_symbols;
	db *sqlite=NULL;
	transgraph *transgraph=NULL;
	char *analysischr=NULL;
	std::locale locale;
	yy::parser parser;
    std::time_t timestamp=std::time(nullptr);
    std::set<std::pair<std::string,unsigned int>> functors_with_matching_nr_of_deps;
    std::set<std::pair<std::string,unsigned int>>::const_iterator functor_with_matching_nr_of_deps;
	lexicon main_verb;

    logger::singleton("console",0,"LE");//Don't forget to turn off logging i.e. comment out if necessary e.g. in android release versions
	logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"human_input:"+std::string(human_input));
	token_paths=new tokenpaths(toa);
	while(human_input!=NULL&&toa!=0&&token_paths->is_any_left()==true){
		logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"picking new token path");
		try{
			if(sqlite==NULL){
				#ifdef __ANDROID__
					if(vm!=NULL) jvm=vm;
					else{
						logger::singleton()==NULL?(void)0:logger::singleton()->log(2,"vm is NULL!");
						exit(EXIT_FAILURE);
					}
					activity=activityobj;
				#endif
				sqlite=db_factory::get_instance();
				#if defined(__EMSCRIPTEN__) && FS==NETWORK
				sqlite->open(db_uri);
				#elif defined(__EMSCRIPTEN__) && FS==NODEJS
				EM_ASM(
					FS.mkdir('/virtual');
					FS.mount(NODEFS, { root: '.' }, '/virtual');
				);
				sqlite->open("/virtual/"+std::string(db_uri));
				#else
				sqlite->open(db_uri);
				#endif
				query_result *main_symbol_result=NULL;
				main_symbol_result=sqlite->exec_sql("SELECT * FROM SETTINGS WHERE key='main_symbol';");
				std::string main_symbol=*main_symbol_result->field_value_at_row_position(0,"value");
				delete main_symbol_result;
				query_result *main_verb_result=NULL;
				main_verb_result=sqlite->exec_sql("SELECT * FROM SETTINGS WHERE key='"+main_symbol+"';");
				main_verb_symbols=*main_verb_result->field_value_at_row_position(0,"value");
				std::replace(main_verb_symbols.begin(),main_verb_symbols.end(),'<','\'');
				std::replace(main_verb_symbols.begin(),main_verb_symbols.end(),'>','\'');
				delete main_verb_result;
			}
			locale=std::locale();
            if(modified_human_input.empty()==true){
                lex=new lexer(human_input,language,locale,false,token_paths);
                token_paths->assign_lexer(lex);
            }
			logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"lexer started");
            sparser=new interpreter(toa);
			logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"interpreter started");
			bool delete_lexer=true;
			if(toa&HI_SYNTAX||toa&HI_SYNTAX&&toa&HI_SEMANTICS){
				int parse_error=parser.parse();
				if(parse_error==0){
					if(toa&HI_SEMANTICS){
						transgraph=sparser->longest_match_for_semantic_rules_found();
						if(transgraph!=NULL){
							token_paths->validate_parse_tree(sparser->nodes());
							token_paths->validate_path(lex->word_entries(),transgraph,true);
							logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"TRUE");
						}
						else{
							logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"semantic error");
							token_paths->invalidate_parse_tree(sparser->nodes());
							token_paths->invalidate_path(lex->word_entries(),"semantic error",NULL);
						}
					}
					else if(toa&HI_SYNTAX){
						token_paths->validate_parse_tree(sparser->nodes());
						token_paths->validate_path(lex->word_entries(),NULL,true);
					}
					else{
						throw std::runtime_error("Logic error: missing type of analysis code coverage in case of semantic error");
					}
				}
				else{//syntax error for token in yychar
					logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"syntax error");
					if(toa&HI_SEMANTICS){
						token_paths->invalidate_parse_tree(sparser->nodes());
						token_paths->invalidate_path(lex->word_entries(),"syntax error",NULL);
					}
					else if(toa&HI_SYNTAX){
						token_paths->invalidate_parse_tree(sparser->nodes());
						token_paths->invalidate_path(lex->word_entries(),"syntax error",NULL);
					}
					else{
						throw std::runtime_error("Logic error: missing type of analysis code coverage in case of syntax error");
					}
				}
				delete sparser;
				sparser=NULL;
				transgraph=NULL;
            }
            else if(toa&HI_MORPHOLOGY&&toa&HI_SEMANTICS){
				if(modified_human_input.empty()==true){
					if(crh>0){
						modified_human_input=token_paths->add_context_reference_word(crh,human_input);
						lex=token_paths->lexer();
						delete_lexer=false;
						while(lex->is_end_of_input()==false){//go through the input simulating what bison does as well but w/o syntactic analysis
							lex->next_token();
						}
					}
					else{
						//1. Find functor(s) with gcat set in settings
						//2. Determine the intersection of functors_found of each iteration
						//3. If there are >1 functors in the intersection, select those that
						//   have the highest number of dependencies found.
						//4. If there are >1, make as many turns as necessary to return analysis for each.
						while(lex->is_end_of_input()==false){//go through the input simulating what bison does as well but w/o syntactic analysis
							lex->next_token();
						}
						if(functors_with_matching_nr_of_deps.empty()==true){//Run only once, not for each token path
							std::cout<<"debug1"<<std::endl;
							//Get every possible word analysis from lexer cache to be able to look up all possible functors
							std::vector<lexicon> words=lex->all_word_entries();
							std::map<unsigned int,lexicon> main_verbs=lex->find_main_verb(words);
							functors_with_matching_nr_of_deps=sparser->find_functors_with_matching_nr_of_deps(words,main_verb_symbols);
							functor_with_matching_nr_of_deps=functors_with_matching_nr_of_deps.begin();
						}
						if(functor_with_matching_nr_of_deps!=functors_with_matching_nr_of_deps.end()){
							std::cout<<"debug2"<<std::endl;
							query_result *result=NULL;
							main_verb=lex->get_word_by_lexeme(functor_with_matching_nr_of_deps->first);
							std::cout<<"outer main_verb.lexeme:"<<main_verb.lexeme<<std::endl;
							if(main_verb.lexeme.empty()==true){
								result=sqlite->exec_sql("SELECT * FROM LEXICON WHERE LEXEME='"+functor_with_matching_nr_of_deps->first+"' AND LID='"+lex->language()+"' AND GCAT in("+main_verb_symbols+");");
								if(result!=NULL){
									std::string word=*result->field_value_at_row_position(0,"word");
									modified_human_input=token_paths->modify_human_input(word,human_input);
									lex=token_paths->lexer();
									delete_lexer=false;
									delete result;
									while(lex->is_end_of_input()==false){//go through the input simulating what bison does as well but w/o syntactic analysis
										lex->next_token();
									}
									main_verb=lex->get_word_by_lexeme(functor_with_matching_nr_of_deps->first);
								}
							}
							else{
								modified_human_input=human_input;
								delete_lexer=false;
							}
						}
					}
				}
				if(functor_with_matching_nr_of_deps!=functors_with_matching_nr_of_deps.end()){
					sparser->build_dependency_semantics(lex,token_paths,main_verb);
				}
				else{
					token_paths->invalidate_parse_tree(sparser->nodes());
					token_paths->invalidate_path(lex->word_entries(),"semantic error",NULL);
				}
                delete sparser;
                sparser=NULL;
                transgraph=NULL;
				if(crh>0){//TODO: check how to handle functor_with_matching_nr_of_deps
					if(token_paths->is_any_left()==true){
						delete lex;
						lex=new lexer(modified_human_input.c_str(),language,locale,false,token_paths);
						token_paths->assign_lexer(lex);
						while(lex->is_end_of_input()==false){//go through the input simulating what bison does as well but w/o syntactic analysis
							lex->next_token();
						}
						delete_lexer=false;
					}
				}
				else{
					if(token_paths->is_any_left()==true){
						delete lex;
						lex=new lexer(modified_human_input.c_str(),language,locale,false,token_paths);
						token_paths->assign_lexer(lex);
						while(lex->is_end_of_input()==false){//go through the input simulating what bison does as well but w/o syntactic analysis
							lex->next_token();
						}
						delete_lexer=false;
					}
					else{
						++functor_with_matching_nr_of_deps;
						if(functor_with_matching_nr_of_deps!=functors_with_matching_nr_of_deps.end()){
							query_result *result=NULL;
							main_verb=lex->get_word_by_lexeme(functor_with_matching_nr_of_deps->first);
							if(main_verb.lexeme.empty()==true){
								result=sqlite->exec_sql("SELECT * FROM LEXICON WHERE LEXEME='"+functor_with_matching_nr_of_deps->first+"' AND LID='"+lex->language()+"' AND GCAT in("+main_verb_symbols+");");
								if(result!=NULL){
									std::string word=*result->field_value_at_row_position(0,"word");
									modified_human_input=token_paths->modify_human_input(word,human_input);
									lex=token_paths->lexer();
									delete_lexer=false;
									delete result;
									while(lex->is_end_of_input()==false){//go through the input simulating what bison does as well but w/o syntactic analysis
										lex->next_token();
									}
									main_verb=lex->get_word_by_lexeme(functor_with_matching_nr_of_deps->first);
								}
							}
							else{
								modified_human_input=human_input;
								delete_lexer=false;
							}
						}
					}
				}
            }
			if(delete_lexer==true){
				delete lex;
				lex=NULL;
			}
			if(toa==HI_MORPHOLOGY) break;
		}
		catch(sql_execution_error& exception){
			logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"sql_execution_error:"+std::string(exception.what()));
			return NULL;
		}
		catch(failed_to_open_db& exception){
			logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"failed_to_open_db:"+std::string(exception.what()));
			return NULL;
		}
		catch(failed_to_close_db& exception){
			logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"failed_to_close_db:"+std::string(exception.what()));
			return NULL;
		}
		catch(lexicon_type_and_db_table_schema_mismatch& exception){
			logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"lexicon_type_and_db_table_schema_mismatch:"+std::string(exception.what()));
			return NULL;
		}
		catch(more_than_one_token_found& exception){
			logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"more_than_one_token_found:"+std::string(exception.what()));
			return NULL;
		}
		catch(morphan_error& exception){
			logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"morphan_error:"+std::string(exception.what()));
			return NULL;
		}
		catch(object_node_missing& exception){
			logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"object_node_missing:"+std::string(exception.what()));
			return NULL;
		}
		catch(head_node_missing& exception){
			logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"head_node_missing:"+std::string(exception.what()));
			return NULL;
		}
		catch(invalid_combination& exception){
            token_paths->invalidate_path(lex->word_entries(),"invalid combination",&exception);
            logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"invalid_combination:"+std::string(exception.what()));
            if(token_paths->is_any_left()==true){
				delete sparser;
				sparser=NULL;
				delete lex;
				lex=NULL;
				transgraph=NULL;
			}
		}
		catch(dependency_counter_manner_validation_failed& exception){
			token_paths->invalidate_path(lex->word_entries(),"semantic error",&exception);
			logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"semantic error:"+std::string(exception.what()));
			if(token_paths->is_any_left()==true){
				delete sparser;
				sparser=NULL;
				delete lex;
				lex=NULL;
				transgraph=NULL;
			}
		}
		catch(invalid_token_path& exception){
			delete sparser;
			sparser=NULL;
			delete lex;
			lex=NULL;
			transgraph=NULL;
		}
		catch(missing_prerequisite_symbol& exception){
			logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"missing_prerequisite_symbol:"+std::string(exception.what()));
			return NULL;
		}
		catch(std::runtime_error& exception){//Catch underived exceptions thrown with string based messages
			logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"runtime error:"+std::string(exception.what()));
			return NULL;
		}
		catch(...){
			logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"unexpected error ...");
			return NULL;
		}
    morphan_result::clear_global_features();
    transgraph::clear_node_functor_map();
    }
    analyses=token_paths->create_analysis(toa,language,target_language,std::string(human_input),timestamp,std::string(source));
    if(analyses.empty()==false){
        analysischr=new char[analyses.length()+1];
        analyses.copy(analysischr,analyses.length(),0);
        analysischr[analyses.length()]='\0';
	}
	lexer::delete_cache();
	delete token_paths;
	token_paths=NULL;
	if(sqlite!=NULL){
		//TODO: consider providing a release() function for the library
		//and NOT closing+freeing the db here as it'd increase performance
		//as in case of not freeing the stemmer.
		sqlite->close();
		db_factory::delete_instance();
		sqlite=NULL;
	}
	return analysischr;
}
#ifdef __EMSCRIPTEN__
}
#endif
