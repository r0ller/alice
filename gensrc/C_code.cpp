int yylex(void){
	int token;
	lexicon word={};

	if(lex->is_end_of_input()==false){
		token=lex->next_token();
		std::cout<<"next token:"<<token<<std::endl;
		return token+1;
	}
	else return 0;//historic indicator of YACC about end of input stream
}

void yyerror(char const *yymsgp){
	std::cout<<yymsgp<<std::endl;
	return;
}

#ifdef __EMSCRIPTEN__
extern "C"{
#endif

#ifdef __ANDROID__
const char *hi(const char *human_input,const char *language,char *error, JavaVM *vm, jobject activityobj){
#elif defined(__EMSCRIPTEN__) && FS==NETWORK
const char *hi(const char *human_input,const char *language,const char *db_uri,char *error){
#elif defined(__EMSCRIPTEN__) && FS==NODEJS
const char *hi(const char *human_input,const char *language,const char *db_file_path,char *error){
#else
const char *hi(const char *human_input,const char *language,char *error){
#endif

	std::string commandstr,last_word,validated_words;
	db *sqlite=NULL;
	transgraph *transgraph=NULL;
	char *commandchr=NULL;
	logger *logger=NULL;
	std::locale locale;

	logger=logger::singleton("console",3,"LE");
	token_paths=new tokenpaths;
	//TODO: implement result wrapper (JSON?) and remove commandchr==NULL condition to return not only the first but all valid results
	while(human_input!=NULL&&commandchr==NULL&&token_paths->is_any_left()==true){
		std::cout<<"picking new token path"<<std::endl;
		try{
			if(sqlite==NULL){
				#ifdef __ANDROID__
					__android_log_print(ANDROID_LOG_INFO, "hi", "human_input: %s", human_input);
					if(vm!=NULL) jvm=vm;
					else{
						__android_log_print(ANDROID_LOG_INFO, "hi", "vm is NULL!");
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
				sqlite->open("/virtual/"+std::string(db_file_path));
				#else
				sqlite->open("hi.db");
				#endif
			}
			locale=std::locale();
			lex=new lexer(human_input,language,locale);
			#ifdef __ANDROID__
				__android_log_print(ANDROID_LOG_INFO, "hi", "lexer started");
			#endif
			sparser=new interpreter;
			#ifdef __ANDROID__
				__android_log_print(ANDROID_LOG_INFO, "hi", "interpreter started");
			#endif
			if(yyparse()==0){
				transgraph=sparser->longest_match_for_semantic_rules_found();
				if(transgraph!=NULL){
					token_paths->validate_path(lex->word_entries());
					logger::singleton()->log(0,"TRUE");
					commandstr=transgraph->transcript(std::string());
					std::cout<<commandstr<<std::endl;
				}
				else{
					logger::singleton()->log(0,"semantic error");
					token_paths->invalidate_path(lex->word_entries());
					validated_words=lex->validated_words();
					logger::singleton()->log(0,"validated words:"+validated_words);
					if(lex->last_word_scanned().morphalytics!=NULL)
						last_word=lex->last_word_scanned().morphalytics->word();
					else last_word=lex->last_word_scanned().word;
					logger::singleton()->log(0,"FALSE: error at "+last_word);
					if(error!=NULL){
						if(validated_words.empty()==false){
							validated_words.copy(error,validated_words.length(),0);
							error[validated_words.length()]='/';
							last_word.copy(&error[validated_words.length()+1],last_word.length(),0);
							error[validated_words.length()+last_word.length()+1]='\0';
						}
						else{
							last_word.copy(error,last_word.length(),0);
							error[last_word.length()]='\0';
						}
					}
				}
			}
			else{//syntax error for token in yychar
				logger::singleton()->log(0,"syntax error");
				token_paths->invalidate_path(lex->word_entries());
/*				std::cout<<"yychar="<<yychar<<std::endl;
				std::cout<<"last_word_scanned().token="<<lex->last_word_scanned().token<<std::endl;
				std::cout<<"last_token_returned()="<<lex->last_token_returned()<<std::endl;
				//checking sparser->validated_terminals() may help in either this or the else branch
				std::set<unsigned int> validated_terminals;
				validated_terminals=sparser->validated_terminals();
				if(yychar!=YYEMPTY&&yychar!=YYEOF&&validated_terminals.find(yychar)!=validated_terminals.end()){
					std::cout<<"yychar found in validated terminals!"<<std::endl;
				}
				else if(yychar!=YYEMPTY&&yychar!=YYEOF&&validated_terminals.find(yychar)==validated_terminals.end()){
					std::cout<<"yychar NOT found in validated terminals!"<<std::endl;
				}
				else std::cout<<"yychar is empty or 0"<<std::endl;
				if(validated_terminals.find(lex->last_token_returned())!=validated_terminals.end()){
					std::cout<<"last token found in validated terminals!"<<std::endl;
				}
				else{
					std::cout<<"last token NOT found in validated terminals!"<<std::endl;
				}
//				if(lex->nr_of_words==1&&lex->last_word_scanned().token==lex->last_token_returned()){
//				}
				//TODO: find out which token should be passed to the followup_token() call in which case (see experimenting if-else cases above for printing out the error token
				token_paths->followup_token(lex->last_token_returned());*/
				validated_words=lex->validated_words();
				logger::singleton()->log(0,"validated words:"+validated_words);
				if(lex->last_word_scanned().morphalytics!=NULL)
					last_word=lex->last_word_scanned().morphalytics->word();
				else last_word=lex->last_word_scanned().word;
				logger::singleton()->log(0,"FALSE: error at "+last_word);
				if(error!=NULL){
					if(validated_words.empty()==false){
						validated_words.copy(error,validated_words.length(),0);
						error[validated_words.length()]='/';
						last_word.copy(&error[validated_words.length()+1],last_word.length(),0);
						error[validated_words.length()+last_word.length()+1]='\0';
					}
					else{
						last_word.copy(error,last_word.length(),0);
						error[last_word.length()]='\0';
					}
				}
			}
			delete sparser;
			sparser=NULL;
			delete lex;
			lex=NULL;
			delete transgraph;
			if(commandstr.empty()==false){
				commandchr=new char[commandstr.length()+1];
				commandstr.copy(commandchr,commandstr.length(),0);
				commandchr[commandstr.length()]='\0';
				if(error!=NULL) error[0]='\0';
			}
		}
		catch(sql_execution_error& exception){
			logger::singleton()->log(0,"sql_execution_error:"+std::string(exception.what()));
			return NULL;
		}
		catch(failed_to_open_db& exception){
			logger::singleton()->log(0,"failed_to_open_db:"+std::string(exception.what()));
			return NULL;
		}
		catch(failed_to_close_db& exception){
			logger::singleton()->log(0,"failed_to_close_db:"+std::string(exception.what()));
			return NULL;
		}
		catch(lexicon_type_and_db_table_schema_mismatch& exception){
			logger::singleton()->log(0,"lexicon_type_and_db_table_schema_mismatch:"+std::string(exception.what()));
			return NULL;
		}
		catch(more_than_one_token_found& exception){
			logger::singleton()->log(0,"more_than_one_token_found:"+std::string(exception.what()));
			return NULL;
		}
		catch(morphan_error& exception){
			logger::singleton()->log(0,"morphan_error:"+std::string(exception.what()));
			return NULL;
		}
		catch(object_node_missing& exception){
			logger::singleton()->log(0,"object_node_missing:"+std::string(exception.what()));
			return NULL;
		}
		catch(head_node_missing& exception){
			logger::singleton()->log(0,"head_node_missing:"+std::string(exception.what()));
			return NULL;
		}
		catch(invalid_combination& exception){
			token_paths->invalidate_path(lex->word_entries());
			validated_words=lex->validated_words();
			logger::singleton()->log(0,"validated words:"+validated_words);
			logger::singleton()->log(0,"invalid_combination:"+std::string(exception.what()));
			if(token_paths->is_any_left()==true){
				delete sparser;
				sparser=NULL;
				delete lex;
				lex=NULL;
				delete transgraph;
			}
			else{
				if(error!=NULL){
					if(validated_words.empty()==false){
						validated_words.copy(error,validated_words.length(),0);
						error[validated_words.length()]='/';
						std::string left_node_words=exception.get_left();
						left_node_words.copy(&error[validated_words.length()+1],left_node_words.length(),0);
						error[validated_words.length()+left_node_words.length()+1]=' ';
						std::string right_node_words=exception.get_right();
						right_node_words.copy(&error[validated_words.length()+left_node_words.length()+2],right_node_words.length(),0);
						error[validated_words.length()+left_node_words.length()+right_node_words.length()+2]='\0';
					}
					else{
						std::string left_node_words=exception.get_left();
						left_node_words.copy(error,left_node_words.length(),0);
						error[left_node_words.length()]=' ';
						std::string right_node_words=exception.get_right();
						right_node_words.copy(&error[left_node_words.length()+1],right_node_words.length(),0);
						error[left_node_words.length()+right_node_words.length()+1]='\0';
					}
					return NULL;
				}
			}
		}
		catch(invalid_token_path& exception){
			delete sparser;
			sparser=NULL;
			delete lex;
			lex=NULL;
			delete transgraph;
		}
		catch(missing_prerequisite_symbol& exception){
			logger::singleton()->log(0,"missing_prerequisite_symbol:"+std::string(exception.what()));
			return NULL;
		}
		catch(std::runtime_error& exception){//Catch underived exceptions thrown with string based messages
			logger::singleton()->log(0,"runtime exception:"+std::string(exception.what()));
			return NULL;
		}
		catch(...){
			logger::singleton()->log(0,"Unexpected error ..."+validated_words);
			return NULL;
		}
	}
	delete token_paths;
	token_paths=NULL;
	if(sqlite!=NULL){
		sqlite->close();
		db_factory::delete_instance();
		sqlite=NULL;
	}
	return commandchr;
}
#ifdef __EMSCRIPTEN__
}
#endif
