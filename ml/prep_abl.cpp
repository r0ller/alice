#include <iostream>
#include <fstream>
#include <sstream>
#include "logger.cpp"
#include "db.h"
#include "query_result.cpp"
#include "morphan_result.cpp"
#include "morphan.cpp"

int main(int argc, char* argv[]){

	db *sqlite=NULL;
	query_result *lexicon=NULL;
	std::string db_file,lid,corpus_file,output;
	morphan *stemmer=NULL;

	logger::singleton("console",0,"LE");
	if(argc<5){
		std::cerr<<"Usage: prep_abl /path/to/dbfile.db /path/to/abl/training/corpus <language id> <output file name>"<<std::endl;
		exit(EXIT_FAILURE);
	}
	db_file=argv[1];
	corpus_file=argv[2];
	lid=argv[3];
	output=argv[4];
	sqlite=db_factory::get_instance();
	sqlite->open(db_file);
	stemmer=morphan::get_instance(lid);
	//itt kéne ledarálni az inputot soronként tokenpath-al meg lexerrel mint a hi()-ban?
	delete stemmer;
	sqlite->close();
	db_factory::delete_instance();
	sqlite=NULL;
	return 0;
}
