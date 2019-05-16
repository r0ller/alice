#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include "logger.h"
#include "db_factory.h"
#include "query_result.h"
#include <tuple>
db *db_factory::singleton_instance=NULL;

class tree_node{
	private:
		std::string symbol_id_;
		std::string symbol_;
		std::vector<tree_node*> child_nodes_;
	public:
		tree_node(const std::string& symbol_id, const std::string& symbol);
		tree_node(const std::string& symbol_id, const std::string& symbol, const std::vector<tree_node*>& child_nodes);
		~tree_node();
		void traverse_rules_pre_order(std::multimap<std::string,std::pair<std::string,std::string> >& rules, std::multimap<std::string,std::pair<std::string,std::string> >& symbolic_rules);
		std::string symbol_id(void);
		std::string symbol(void);
};

tree_node::tree_node(const std::string& symbol_id, const std::string& symbol){
	symbol_id_=symbol_id;
	symbol_=symbol;
}

tree_node::tree_node(const std::string& symbol_id, const std::string& symbol, const std::vector<tree_node*>& child_nodes){
	symbol_id_=symbol_id;
	symbol_=symbol;
	child_nodes_=child_nodes;
}

tree_node::~tree_node(){
	for(auto&& i:child_nodes_){
		delete i;
	}
}

void tree_node::traverse_rules_pre_order(std::multimap<std::string,std::pair<std::string,std::string> >& rules, std::multimap<std::string,std::pair<std::string,std::string> >& symbolic_rules){

	std::cout<<"("<<symbol_id_<<" ";
	if(child_nodes_.empty()==false){
		if(child_nodes_.size()==1){
			bool rule_already_inserted=false;
			for(auto i=rules.lower_bound(symbol_id_);i!=rules.upper_bound(symbol_id_);++i){
				if(i->second.first==child_nodes_.at(0)->symbol_id()&&i->second.second.empty()==true){
					rule_already_inserted=true;
					break;
				}
			}
			if(rule_already_inserted==false){
				rules.insert(std::make_pair(symbol_id_,std::make_pair(child_nodes_.at(0)->symbol_id(),"")));
				symbolic_rules.insert(std::make_pair(symbol_,std::make_pair(child_nodes_.at(0)->symbol(),"")));
			}
		}
		else if(child_nodes_.size()==2){
			bool rule_already_inserted=false;
			for(auto i=rules.lower_bound(symbol_id_);i!=rules.upper_bound(symbol_id_);++i){
				if(i->second.first==child_nodes_.at(0)->symbol_id()&&i->second.second==child_nodes_.at(1)->symbol_id()){
					rule_already_inserted=true;
					break;
				}
			}
			if(rule_already_inserted==false){
				rules.insert(std::make_pair(symbol_id_,std::make_pair(child_nodes_.at(0)->symbol_id(),child_nodes_.at(1)->symbol_id())));
				symbolic_rules.insert(std::make_pair(symbol_,std::make_pair(child_nodes_.at(0)->symbol(),child_nodes_.at(1)->symbol())));
			}
		}
		else{
			std::cerr<<"Number of child nodes for symbol id "<<symbol_id_<<" are neither 1 nor 2: "<<child_nodes_.size()<<std::endl;
			exit(EXIT_FAILURE);
		}
		for(auto&& i:child_nodes_){
			i->traverse_rules_pre_order(rules,symbolic_rules);
		}
	}
	else if(child_nodes_.empty()==true){
		bool rule_already_inserted=false;
		for(auto i=rules.lower_bound(symbol_id_);i!=rules.upper_bound(symbol_id_);++i){
			if(i->second.first==symbol_&&i->second.second.empty()==true){
				rule_already_inserted=true;
				break;
			}
		}
		if(rule_already_inserted==false){
			rules.insert(std::make_pair(symbol_id_,std::make_pair(symbol_,"")));
			symbolic_rules.insert(std::make_pair(symbol_,std::make_pair(symbol_,"")));
		}
		std::cout<<symbol_<<" ";
	}
	std::cout<<")"<<symbol_id_<<" ";
}

std::string tree_node::symbol_id(){
	return symbol_id_;
}

std::string tree_node::symbol(){
	return symbol_;
}

tree_node* create_node(const std::map<std::string,std::pair<unsigned int,unsigned int> >& symbol_ids_brackets,const std::map<unsigned int,std::string>& positions_symbols,const std::string& symbol_id,const unsigned int opening_pos,const unsigned int closing_pos){
	std::vector<tree_node*> nodes;
	std::map<unsigned int,std::string> anchor_distance_of_child_symbol_ids;
	tree_node* node=NULL;

	for(auto&& i:symbol_ids_brackets){
		if(i.first!=symbol_id&&i.second.first>=opening_pos&&i.second.second<=closing_pos){
			bool symbol_id_embedded=false;
			for(auto&& j:symbol_ids_brackets){
				if(j.first!=symbol_id&&j.second.first>=opening_pos&&j.second.second<=closing_pos){
					if(j.first!=i.first&&i.second.first>=j.second.first&&i.second.second<=j.second.second){
						symbol_id_embedded=true;
						break;
					}
				}
			}
			if(symbol_id_embedded==false) anchor_distance_of_child_symbol_ids.insert(std::make_pair(i.second.first-opening_pos,i.first));
		}
	}
	for(auto&& i:anchor_distance_of_child_symbol_ids){
		auto symbol_id_with_brackets=symbol_ids_brackets.find(i.second);
		tree_node* child_node=create_node(symbol_ids_brackets,positions_symbols,symbol_id_with_brackets->first,symbol_id_with_brackets->second.first,symbol_id_with_brackets->second.second);
		nodes.push_back(child_node);
	}
	if(nodes.empty()==true){
		std::string symbol=positions_symbols.find(opening_pos)->second;
		node=new tree_node(symbol_id,symbol);
	}
	else{
		if(nodes.size()==1){
			node=new tree_node(symbol_id,nodes.at(0)->symbol(),nodes);
		}
		else if(nodes.size()==2){
			node=new tree_node(symbol_id,nodes.at(0)->symbol()+":"+nodes.at(1)->symbol(),nodes);
		}
		else if(nodes.size()>2){
			//TODO: if there are >2 symbols in the constituent (i.e elements in nodes vector),
			//create a tree from them in a controllable manner (via cli parameter)
			//either being right or left aligned or using some other logic
			if(true){//only right aligned tree for now
				while(nodes.size()>2){
					tree_node* right=nodes.back();
					nodes.pop_back();
					tree_node* left=nodes.back();
					nodes.pop_back();
					std::vector<tree_node*> child_nodes;
					child_nodes.push_back(left);
					child_nodes.push_back(right);
					tree_node* parent=new tree_node(left->symbol_id()+"__"+right->symbol_id(),left->symbol()+"__"+right->symbol(),child_nodes);
					nodes.push_back(parent);
				}
			}
			node=new tree_node(symbol_id,nodes.at(0)->symbol()+"__"+nodes.at(1)->symbol(),nodes);
		}
	}
	return node;
}

void bracket_each_symbol(const std::map<unsigned int,std::string>& positions_symbols,const unsigned int outmost_opening_pos,const unsigned int outmost_closing_pos,std::map<std::string,std::pair<unsigned int,unsigned int> >& symbol_ids_brackets,const unsigned int line_nr){
	std::map<unsigned int,std::string> positions_symbol_ids_of_enclosing_brackets;
	std::map<std::string,std::pair<unsigned int,unsigned int> >::iterator symbol_id_with_brackets;

	for(auto&& i:positions_symbols){
		unsigned int nearest_opening_bracket=outmost_opening_pos;
		unsigned int nearest_closing_bracket=outmost_closing_pos;
		std::string symbol_id;
		for(auto&& j:symbol_ids_brackets){
			if(j.second.first<=i.first&&j.second.second>i.first&&j.second.first>=nearest_opening_bracket&&j.second.second<=nearest_closing_bracket){
				nearest_opening_bracket=j.second.first;
				nearest_closing_bracket=j.second.second;
				symbol_id=j.first;
			}
		}
		positions_symbol_ids_of_enclosing_brackets.insert(std::make_pair(i.first,symbol_id));
	}
	for(auto&& i:positions_symbol_ids_of_enclosing_brackets){
		symbol_id_with_brackets=symbol_ids_brackets.find(i.second);
		if(symbol_id_with_brackets==symbol_ids_brackets.end()){
			std::cerr<<"Error: no symbol id found in symbol_ids_brackets map."<<std::endl;
			exit(EXIT_FAILURE);
		}
		if(symbol_id_with_brackets->second.first==i.first&&symbol_id_with_brackets->second.second==i.first+1){
			//Nothing to do, symbol already bracketed
			std::cout<<"position "<<i.first<<" already bracketed, nothing to do"<<std::endl;
		}
		else{
			//TODO: find out if the newly generated symbols are the same for the same rule in
			//different sentences. If not, a different way must be found to generate the same symbols.
			std::string symbol_id="_"+std::to_string(line_nr)+"_"+i.second+"_"+std::to_string(i.first);
			symbol_ids_brackets.insert(std::make_pair(symbol_id,std::make_pair(i.first,i.first+1)));
			std::cout<<"bracketing position "<<i.first<<" with symbol id "<<symbol_id<<std::endl;
		}
	}
}

bool find_rule(const std::multimap<std::string,std::pair<std::string,std::string> >& rules, const std::pair<std::string,std::pair<std::string,std::string>>& rule){
	bool rule_found=false;
	for(auto&& i=rules.lower_bound(rule.first);i!=rules.upper_bound(rule.first);++i){
		if(i->second.first==rule.second.first&&i->second.second==rule.second.second){
			rule_found=true;
			break;
		}
	}
	return rule_found;
}

void merge_rules(std::multimap<std::string,std::pair<std::string,std::string> >& rules,std::multimap<std::string,std::pair<std::string,std::string> >& merging_rules,const std::pair<std::string,std::pair<std::string,std::string> >& ref_rule){
	std::cout<<"ref_rule:"<<ref_rule.first<<"->"<<ref_rule.second.first<<" "<<ref_rule.second.second<<std::endl;
	for(auto&& i:rules){
		if(find_rule(merging_rules,i)==false){
			if(i.first!=ref_rule.first&&i.second.first==ref_rule.second.first&&i.second.second==ref_rule.second.second){
				merging_rules.insert(i);
				std::cout<<"insert rule in merging_rules:"<<i.first<<"->"<<i.second.first<<" "<<i.second.second<<std::endl;
				for(auto&& j:rules){
					if(j.first!=ref_rule.first
							&&j.second.first!=ref_rule.second.first
							&&j.second.second!=ref_rule.second.second
							&&find_rule(merging_rules,j)==false
							&&(j.second.first==i.first||j.second.second==i.first)){
						if(j.second.first==i.first){
							std::cout<<"changing "<<j.first<<"->"<<j.second.first<<" "<<j.second.second<<" to ";
							j.second.first=ref_rule.first;
							std::cout<<j.first<<"->"<<j.second.first<<" "<<j.second.second<<std::endl;
						}
						if(j.second.second==i.first){
							std::cout<<"changing "<<j.first<<"->"<<j.second.first<<" "<<j.second.second<<" to ";
							j.second.second=ref_rule.first;
							std::cout<<j.first<<"->"<<j.second.first<<" "<<j.second.second<<std::endl;
						}
					}
				}
			}
		}
	}
}

void merge_rules(std::multimap<std::string,std::pair<std::string,std::string> >& rules,std::multimap<std::string,std::pair<std::string,std::string> >& merging_rules){

	for(auto&& i:rules){//1st turn: unify rules having the same leaf
		if(find_rule(merging_rules,i)==false){
			if(i.first.empty()==false){
				if(i.second.first.empty()==false&&i.second.second.empty()==true){
					bool symbol_found_as_parent=false;
					for(auto&& j:rules){
						if(find_rule(merging_rules,j)==false&&j.first==i.second.first){
							symbol_found_as_parent=true;
							break;
						}
					}
					if(symbol_found_as_parent==false){
						merge_rules(rules,merging_rules,i);
					}
				}
				else if(i.second.first.empty()==true){
					std::cerr<<"Rule head field cannot be empty.Stop."<<std::endl;
					exit(EXIT_FAILURE);
				}
			}
			else{
				std::cerr<<"Rule parent field cannot be empty.Stop."<<std::endl;
				exit(EXIT_FAILURE);
			}
		}
	}
	int premerge_size=-1;
	while(merging_rules.size()!=premerge_size){//2nd turn: unify rules having equal rhs
		premerge_size=merging_rules.size();
		for(auto&& i:rules){
			if(find_rule(merging_rules,i)==false){
				merge_rules(rules,merging_rules,i);
			}
		}
	}
}

void add_start_symbol(std::multimap<std::string,std::pair<std::string,std::string> >& rules){
	std::set<std::string> top_node_symbols;

	for(auto&& i:rules){
		if(i.first!="S"&&top_node_symbols.find(i.first)==top_node_symbols.end()){
			bool symbol_found_on_rhs=false;
			for(auto&& j:rules){
				if(j.first!=i.first&&(j.second.first==i.first||j.second.second==i.first)){
					//j.first!=i.first is meant to handle recursive rules as well
					//in a way that their lhs does not count as top node
					symbol_found_on_rhs=true;
					break;
				}
			}
			if(symbol_found_on_rhs==false){
				top_node_symbols.insert(i.first);
			}
		}
	}
	for(auto&& i:top_node_symbols){
		std::cout<<"adding start rule:"<<"S->"<<i<<std::endl;
		rules.insert(std::make_pair("S",std::make_pair(i,"")));
	}
}

int main(int argc, char* argv[]){
	std::string abl_output,abl_row,db_file,lid;
	std::ifstream *filestream=NULL;
	std::multimap<std::string,std::pair<std::string,std::string> > rules,symbolic_rules,merging_rules;
	db *sqlite=NULL;
	unsigned int line_nr=0;

	if(argc<3){
		std::cerr<<"Usage: proc_abl /path/to/abl_select/output/file <language id> [/path/to/dbfile.db]"<<std::endl;
		exit(EXIT_FAILURE);
	}
	abl_output=argv[1];
	lid=argv[2];
	if(argc==4) db_file=argv[3];
	std::locale locale=std::locale();
	filestream=new std::ifstream(abl_output);
	if(filestream==NULL){
		exit(EXIT_FAILURE);
	}
	while(std::getline(*filestream,abl_row)){
		std::string::size_type hypos=abl_row.find("@@@");
		if(abl_row.front()!='#'&&hypos!=std::string::npos){
			++line_nr;
			std::map<unsigned int,std::string> positions_symbols;
			std::map<std::string,std::pair<unsigned int,unsigned int> > symbol_ids_brackets;
			std::string hypotheses=abl_row.substr(hypos+3);
			std::cout<<hypotheses<<std::endl;
			std::string symbols=abl_row.substr(0,hypos);
			std::cout<<symbols<<std::endl;
			unsigned int symbol_pos=0;
			std::string::size_type start_pos=0;
			std::string::size_type space_pos=symbols.find(' ');
			while(space_pos!=std::string::npos){
				std::string::size_type substr_length=space_pos-start_pos;
				std::string symbol=symbols.substr(start_pos,substr_length);
				std::cout<<"symbol_pos:"<<symbol_pos<<" symbol:"<<symbol<<std::endl;
				positions_symbols.insert(std::make_pair(symbol_pos,symbol));
				++symbol_pos;
				start_pos=space_pos+1;
				space_pos=symbols.find(' ',start_pos);
			}
			std::string number;
			int symbol_id=-1;
			int opening_bracket_pos=-1;
			int closing_bracket_pos=-1;
			int outmost_symbol_id=-1;
			int outmost_opening_bracket_pos=-1;
			int outmost_closing_bracket_pos=-1;
			while(hypotheses.empty()==false){
				if(std::isdigit(hypotheses.back(),locale)==true){
					number=hypotheses.back()+number;
				}
				else if(hypotheses.back()==','||hypotheses.back()=='('){
					if(symbol_id==-1) symbol_id=std::stoi(number);
					else if(closing_bracket_pos==-1) closing_bracket_pos=std::stoi(number);
					else if(opening_bracket_pos==-1) opening_bracket_pos=std::stoi(number);
					if(symbol_id>=0&&opening_bracket_pos>=0&&closing_bracket_pos>=0){
						symbol_ids_brackets.insert(std::make_pair("_"+std::to_string(line_nr)+"_"+std::to_string(symbol_id),std::make_pair(opening_bracket_pos,closing_bracket_pos)));
						std::cout<<"symbol id:"<<symbol_id<<" opening bracket pos:"<<opening_bracket_pos<<" closing bracket pos:"<<closing_bracket_pos<<std::endl;
						if(outmost_symbol_id==-1||outmost_symbol_id>=0&&opening_bracket_pos<=outmost_opening_bracket_pos&&closing_bracket_pos>=outmost_closing_bracket_pos){
							outmost_symbol_id=symbol_id;
							outmost_opening_bracket_pos=opening_bracket_pos;
							outmost_closing_bracket_pos=closing_bracket_pos;
						}
						symbol_id=-1;
						opening_bracket_pos=-1;
						closing_bracket_pos=-1;
					}
					number.clear();
				}
				hypotheses.pop_back();
			}
			std::cout<<"outmost symbol id:"<<outmost_symbol_id<<std::endl;
			bracket_each_symbol(positions_symbols,outmost_opening_bracket_pos,outmost_closing_bracket_pos,symbol_ids_brackets,line_nr);
			//TODO: verify if each symbol got bracketed and that the newly generated symbols
			//are the same for the same rule in each sentence
			tree_node* root=create_node(symbol_ids_brackets,positions_symbols,"_"+std::to_string(line_nr)+"_"+std::to_string(outmost_symbol_id),outmost_opening_bracket_pos,outmost_closing_bracket_pos);
			root->traverse_rules_pre_order(rules,symbolic_rules);
			std::cout<<std::endl;
			delete root;
		}
	}
	add_start_symbol(rules);
	merge_rules(rules,merging_rules);
	if(db_file.empty()==false){
		sqlite=db_factory::get_instance();
		sqlite->open(db_file);
	}
	std::cout<<"Rules:"<<std::endl;
	//Top symbols i.e. Start symbols (S) that don't get replaced won't show up
	//in merging_rules so an additional filter must be set up for them.
	//TODO: it may be a good idea to make it strict and throw an exception if
	//a non-start rule gets inserted in rules_inserted.
	std::set<std::tuple<std::string,std::string,std::string>> rules_inserted;
	for(auto&& i:rules){
		if(find_rule(merging_rules,i)==false&&rules_inserted.find(std::make_tuple(i.first,i.second.first,i.second.second))==rules_inserted.end()){
			if(i.second.second.empty()==false){
				std::cout<<i.first<<"->"<<i.second.first<<" "<<i.second.second<<std::endl;
				if(sqlite!=NULL){
					sqlite->exec_sql("INSERT OR IGNORE INTO SYMBOLS (SYMBOL,LID) VALUES ('"+i.first+"','"+lid+"');");
					sqlite->exec_sql("INSERT OR IGNORE INTO SYMBOLS (SYMBOL,LID) VALUES ('"+i.second.first+"','"+lid+"');");
					sqlite->exec_sql("INSERT OR IGNORE INTO SYMBOLS (SYMBOL,LID) VALUES ('"+i.second.second+"','"+lid+"');");
					sqlite->exec_sql("INSERT INTO GRAMMAR (LID,PARENT_SYMBOL,HEAD_SYMBOL,NON_HEAD_SYMBOL) VALUES ('"+lid+"','"+i.first+"','"+i.second.first+"','"+i.second.second+"');");
				}
			}
			else{
				std::cout<<i.first<<"->"<<i.second.first<<std::endl;
				if(sqlite!=NULL){
					sqlite->exec_sql("INSERT OR IGNORE INTO SYMBOLS (SYMBOL,LID) VALUES ('"+i.first+"','"+lid+"');");
					sqlite->exec_sql("INSERT OR IGNORE INTO SYMBOLS (SYMBOL,LID) VALUES ('"+i.second.first+"','"+lid+"');");
					sqlite->exec_sql("INSERT INTO GRAMMAR (LID,PARENT_SYMBOL,HEAD_SYMBOL) VALUES ('"+lid+"','"+i.first+"','"+i.second.first+"');");
				}
			}
			rules_inserted.insert(std::make_tuple(i.first,i.second.first,i.second.second));
		}
	}
//	std::cout<<"Symbolic rules:"<<std::endl;
//	for(auto&& i:symbolic_rules){
//		if(i.second.second.empty()==false){
//			std::cout<<i.first<<"->"<<i.second.first<<" "<<i.second.second<<std::endl;
//		}
//		else{
//			std::cout<<i.first<<"->"<<i.second.first<<std::endl;
//		}
//	}
	if(sqlite!=NULL){
		sqlite->close();
		db_factory::delete_instance();
		sqlite=NULL;
	}
	filestream->close();
	delete filestream;
	return 0;
}
