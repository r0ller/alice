#ifndef SH_TRANSCRIPTOR_H
#define SH_TRANSCRIPTOR_H

#include "transcriptor.h"

class sh_transcriptor:public transcriptor{
	private:
		std::string args_to_shfun_arglist(std::vector<std::string>&);
		std::string args_to_shfun_pmlist(std::vector<std::string>&);
	protected:
		std::string transcribeDependencies(rapidjson::Value&,rapidjson::Value&,rapidjson::Value&,rapidjson::Value&,std::vector<std::string>&,bool=false) override;
	public:
		sh_transcriptor(const char *analyses);
		~sh_transcriptor();
};

#endif
