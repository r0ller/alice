#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

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
					tree_node* parent=new tree_node(left->symbol_id()+":"+right->symbol_id(),left->symbol()+":"+right->symbol(),child_nodes);
					nodes.push_back(parent);
				}
			}
			node=new tree_node(symbol_id,nodes.at(0)->symbol()+":"+nodes.at(1)->symbol(),nodes);
		}
	}
	return node;
}

void bracket_each_symbol(const std::map<unsigned int,std::string>& positions_symbols,const unsigned int outmost_opening_pos,const unsigned int outmost_closing_pos,std::map<std::string,std::pair<unsigned int,unsigned int> >& symbol_ids_brackets){
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
			std::string symbol_id=i.second+"_"+std::to_string(i.first);
			symbol_ids_brackets.insert(std::make_pair(symbol_id,std::make_pair(i.first,i.first+1)));
			std::cout<<"bracketing position "<<i.first<<" with symbol id "<<symbol_id<<std::endl;
		}
	}
}

int main(int argc, char* argv[]){
	std::string abl_output,output,abl_row;
	std::ifstream *filestream=NULL;
	std::ofstream *output_file=NULL;
	std::multimap<std::string,std::pair<std::string,std::string> > rules,symbolic_rules;

	if(argc<2){
		std::cerr<<"Usage: proc_abl /path/to/abl_select/output/file [/path/to/output/file/name]"<<std::endl;
		exit(EXIT_FAILURE);
	}
	abl_output=argv[1];
	//output=argv[2];
	std::locale locale=std::locale();
	filestream=new std::ifstream(abl_output);
	if(filestream==NULL){
		exit(EXIT_FAILURE);
	}
	while(std::getline(*filestream,abl_row)){
		std::string::size_type hypos=abl_row.find("@@@");
		if(abl_row.front()!='#'&&hypos!=std::string::npos){
			//std::map<unsigned int,std::pair<std::vector<unsigned int>,std::vector<unsigned int> > > symbol_bracket_positions;
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
						symbol_ids_brackets.insert(std::make_pair(std::to_string(symbol_id),std::make_pair(opening_bracket_pos,closing_bracket_pos)));
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
			bracket_each_symbol(positions_symbols,outmost_opening_bracket_pos,outmost_closing_bracket_pos,symbol_ids_brackets);
			//TODO: verify if each symbol got bracketed and that the newly generated symbols
			//are the same for the same rule in each sentence
			tree_node* root=create_node(symbol_ids_brackets,positions_symbols,std::to_string(outmost_symbol_id),outmost_opening_bracket_pos,outmost_closing_bracket_pos);
			root->traverse_rules_pre_order(rules,symbolic_rules);
			std::cout<<std::endl;
			delete root;
		}
	}
	std::cout<<"Rules:"<<std::endl;
	for(auto&& i:rules){
		if(i.second.second.empty()==false){
			std::cout<<i.first<<"->"<<i.second.first<<" "<<i.second.second<<std::endl;
		}
		else{
			std::cout<<i.first<<"->"<<i.second.first<<std::endl;
		}
	}
	std::cout<<"Symbolic rules:"<<std::endl;
	for(auto&& i:symbolic_rules){
		if(i.second.second.empty()==false){
			std::cout<<i.first<<"->"<<i.second.first<<" "<<i.second.second<<std::endl;
		}
		else{
			std::cout<<i.first<<"->"<<i.second.first<<std::endl;
		}
	}
	filestream->close();
	delete filestream;
//	output_file->close();
//	delete output_file;
	return 0;
}
