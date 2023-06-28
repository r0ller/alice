#include <map>
#include <string>
std::map<std::string, unsigned int> symbol_token_map={
{"t_ENG_CON_Stem",yy::parser::token::t_ENG_CON_Stem},
{"t_ENG_A_Stem",yy::parser::token::t_ENG_A_Stem},
{"t_ENG_N_Stem",yy::parser::token::t_ENG_N_Stem},
{"t_ENG_N_Pl",yy::parser::token::t_ENG_N_Pl},
{"t_ENG_N_Sg",yy::parser::token::t_ENG_N_Sg},
{"t_ENG_V_Stem",yy::parser::token::t_ENG_V_Stem},
{"t_ENG_N_swVowel",yy::parser::token::t_ENG_N_swVowel},
{"t_ENG_N_swConsonant",yy::parser::token::t_ENG_N_swConsonant},
{"t_ENG_V_PRES",yy::parser::token::t_ENG_V_PRES},
{"t_ENG_N_3sg",yy::parser::token::t_ENG_N_3sg}
};

std::map<unsigned int,std::string> token_symbol_map={
{yy::parser::token::t_ENG_CON_Stem,"t_ENG_CON_Stem"},
{yy::parser::token::t_ENG_A_Stem,"t_ENG_A_Stem"},
{yy::parser::token::t_ENG_N_Stem,"t_ENG_N_Stem"},
{yy::parser::token::t_ENG_N_Pl,"t_ENG_N_Pl"},
{yy::parser::token::t_ENG_N_Sg,"t_ENG_N_Sg"},
{yy::parser::token::t_ENG_V_Stem,"t_ENG_V_Stem"},
{yy::parser::token::t_ENG_N_swVowel,"t_ENG_N_swVowel"},
{yy::parser::token::t_ENG_N_swConsonant,"t_ENG_N_swConsonant"},
{yy::parser::token::t_ENG_V_PRES,"t_ENG_V_PRES"},
{yy::parser::token::t_ENG_N_3sg,"t_ENG_N_3sg"}
};
