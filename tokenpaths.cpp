#include "tokenpaths.h"

tokenpaths::tokenpaths(){

}

tokenpaths::~tokenpaths(){

}

bool tokenpaths::is_any_left(){
	unsigned int nr_of_paths=1,nr_of_paths_covered=0;
	t_word_count *word_count=NULL;

	if(wordtoken_counter.empty()==true&&(valid_paths.empty()==false||invalid_paths.empty()==false)
		||wordtoken_counter.empty()==false&&valid_paths.empty()==true&&invalid_paths.empty()==true){
		exit(EXIT_FAILURE);//TODO: throw exception
	}
	else if(wordtoken_counter.empty()==false&&(valid_paths.empty()==false||invalid_paths.empty()==false)){
		for(std::map<std::string,unsigned int>::iterator i=wordtoken_counter.begin();i!=wordtoken_counter.end();++i){
			word_count=new t_word_count(i);
			nr_of_paths=nr_of_paths*word_count->count;
			delete word_count;
		}
		nr_of_paths_covered=valid_paths.size()+invalid_paths.size();
//		std::cout<<"nr_of_paths="<<nr_of_paths<<", nr_of_paths_covered="<<nr_of_paths_covered<<std::endl;
		if(nr_of_paths==nr_of_paths_covered) return false;
		else if(nr_of_paths_covered<nr_of_paths) return true;
		else exit(EXIT_FAILURE);//TODO: throw exception
	}
	else if(wordtoken_counter.empty()==true){
		return true;
	}
	else{
		exit(EXIT_FAILURE);//TODO: throw exception
	}
}

void tokenpaths::add_word(const lexicon& word){
	bool exists_already=false;
	unsigned int nr_of_matching_words=0;
	t_word_count *word_count=NULL;
	std::map<std::string,unsigned int>::iterator it_wordtoken_counter;

	for(auto&& i:words){
		if(i.word==word.word){
			++nr_of_matching_words;
			if(i.tokens==word.tokens){
				exists_already=true;
			}
		}
	}
	if(exists_already==false){
		words.push_back(word);
		++nr_of_matching_words;
	}
	it_wordtoken_counter=wordtoken_counter.find(word.word);
	if(it_wordtoken_counter!=wordtoken_counter.end()){
		word_count=new t_word_count(it_wordtoken_counter);
		if(word_count->count<nr_of_matching_words) word_count->count=nr_of_matching_words;
		delete word_count;
	}
	else{
		wordtoken_counter.insert(std::make_pair(word.word,1));
	}
}

lexicon tokenpaths::next_word(const std::string& word){
	lexicon word_found={};

	for(auto&& i:words){
		if(i.word==word){
			word_found=i;
			break;
		}
	}
	return word_found;
}

void tokenpaths::mark_syntax_error(const lexicon& word){
	bool exists_already=false;

	for(auto&& i:words_with_token_errors){
		if(i.word==word.word&&i.tokens==word.tokens){
			exists_already=true;
			break;
		}
	}
	if(exists_already==false){
		words_with_token_errors.push_back(word);
		for(std::vector<lexicon>::iterator i=words.begin();i!=words.end();++i){
			if(i->word==word.word&&i->tokens==word.tokens){
				words.erase(i);
				break;
			}
		}
	}
}

void tokenpaths::add_valid_path(const std::vector<lexicon>& words){
	valid_paths.push_back(words);
}

void tokenpaths::add_invalid_path(const std::vector<lexicon>& words){
	invalid_paths.push_back(words);
}
