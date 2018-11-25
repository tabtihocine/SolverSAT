#include "backtracking.h"
using namespace std;

bool hasEmptyClause (vector<vector<int>>& cnf){
	bool empty;
	for(int i=0 ; i<cnf.size() ; i++){
		if(cnf[i].empty()){
			empty= true;
		}else{
			empty= false; 
		}
	}
return empty;
} 


bool backtracking(vector<vector<int>>& phi , vector<int>& variable,vector<int>&model)
{	

	bool satisfaisable; 
	vector<vector<int>> phiPrim;
	vector<vector<int>> phiPrimPrim;

 
  if(phi.empty())
	{	
		satisfaisable= true; 
		return satisfaisable; 
	}

	if(hasEmptyClause(phi)){
		satisfaisable=false;
		return satisfaisable;
	}

	for(int i=0 ; i<phi.size();i++)
	{
		if(phi[i].size()==1)
		{
			vector<vector<int>> phiTemp = simplify(phi , phi[i][0]); 
			model.push_back(phi[i][0]);
			satisfaisable= backtracking(phiTemp , variable, model);
			return satisfaisable;	
		}

	}
	

	int literal = pick(variable);
	phiPrim=simplify(phi , literal);

	if(phiPrim.empty()){
		model.push_back(literal);
		satisfaisable=true;
		return satisfaisable; 
	}else{
		if(hasEmptyClause(phiPrim)){
			phiPrimPrim=simplify(phi, -literal);
			if(phiPrimPrim.empty()){
				model.push_back(-literal);
				satisfaisable=true;
				return satisfaisable; 
			}else{
				if(hasEmptyClause(phiPrimPrim)){
					satisfaisable=false;
					return satisfaisable; 
				}else{
					model.push_back(-literal);
					satisfaisable=backtracking(phiPrimPrim,variable,model);
					return satisfaisable; 
				}
			}

		}else{
			model.push_back(literal);
			satisfaisable= backtracking(phiPrim,variable,model);
			return satisfaisable;
		}
	}
}


/*	 
	int literal = pick(variable); 
	phiPrim=simplify(phi, literal); 
	
	if(phiPrim.empty()){
		model.push_back(literal);
		satisfaisable=true;
		return satisfaisable;
	}else{
		satisfaisable =backtracking(phiPrim , variable , model); 
		if(satisfaisable){
			satisfaisable=true;
			return satisfaisable; 
		}else{
			phiPrimPrim=simplify(phi, -literal); 
			if(phiPrimPrim.empty()){
				model.push_back(-literal);
				satisfaisable=true;
				return satisfaisable;
			}else{
				satisfaisable=backtracking(phiPrimPrim , variable , model);
				return satisfaisable; 
			}
		}
	}*/
