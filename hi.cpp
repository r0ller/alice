#include "hilib.h" 
#include <string>
#include <iostream>

int main(void){

	const char *translation;
	std::string command;

	while(true){
		std::getline(std::cin, command);
		if(command.empty()==false){
			translation=hi(command.c_str(),"ENG",HI_MORPHOLOGY|HI_SEMANTICS,"","hi.db");
			std::cout<<translation<<std::endl;
			command.clear();
		}
		else break;
	}
}
