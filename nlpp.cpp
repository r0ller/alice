#include "nlpp.h"

nl_preprocessor::nl_preprocessor(const time_t& timestamp,const std::string& text,const std::string& lid):preprocessor(timestamp){
//Check for new line chars and punctuation indicating end of sentence and split the text string according to them.
	std::string::size_type position=0,split_position=0;;

	this->lid=lid;
	std::string pp_text=text;
	pp_text=add_space(text);
	std::cout<<"spaced: "<<pp_text<<std::endl;
	std::locale locale=std::locale();
	lex=new lexer(pp_text.c_str(),lid.c_str(),locale,false,token_paths);
	//token_paths->assign_lexer(lex);
	std::string word=lex->next_word();
	std::vector<lexicon> new_words;
	bool sentence_end_found=false;
	std::string row;
	while(word.empty()==false){
		auto cache_hit=lex->copy_word_from_cache(word);
		if(cache_hit.second.empty()==false){
			new_words=cache_hit.second;
		}
		else{
			throw std::runtime_error("Word not found in cache:"+word);
		}
		for(auto new_word:new_words){
			if(new_word.gcat=="Punct") sentence_end_found=true;//TODO: rather a list of features like FullStop, etc. shall be checked
		}
		if(sentence_end_found==true){
			row+=word;
			std::cout<<"row:"<<row<<std::endl;
			rows.push_back(row);
			row.clear();
			sentence_end_found=false;
		}
		else{
			row+=word+" ";
		}
		word=lex->next_word();
	}
	delete lex;
}

nl_preprocessor::~nl_preprocessor(){
}

std::pair<std::string,std::string> nl_preprocessor::get_row(const unsigned int row_nr) const{
	std::pair<std::string,std::string> ref_id_and_row;

	if(row_nr<rows.size()){
		ref_id_and_row=std::make_pair(std::to_string(row_nr),rows.at(row_nr));
	}
	return ref_id_and_row;
}

std::string nl_preprocessor::get_search_ref_id(const std::string&) const{
}

std::string nl_preprocessor::add_space(const std::string& text){
	std::string spaced=text;
	size_t pos=0;
	while(pos<spaced.length()){
		switch(spaced[pos]){
		case '.':
			spaced.replace(pos,1," . ");
			pos=pos+3;
			break;
		case ',':
			spaced.replace(pos,1," , ");
			pos=pos+3;
			break;
		case '!':
			spaced.replace(pos,1," ! ");
			pos=pos+3;
			break;
		case '?':
			spaced.replace(pos,1," ? ");
			pos=pos+3;
			break;
		case ':':
			spaced.replace(pos,1," : ");
			pos=pos+3;
			break;
		default:
			++pos;
		}
	}
	return spaced;
}
