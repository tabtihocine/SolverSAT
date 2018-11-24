#include "backtracking.h"
using namespace std;

bool backtracking(vector<vector<int>>& phi , vector<int>& variable){

	bool satisfiable;
	vector<vector<int>> phiPrim; 
	vector<vector<int>> phiPrimPrim; 

	if(phi.empty()){
		satisfiable = true; 
		return satisfiable; 
	}
    
	for(int i=0 ; i<phi.size() ; i++){
		if(phi[i].empty()){
			satisfiable = false; 
			return satisfiable;
		}
	}

	for(int i=0 ; i<phi.size() ; i++){
		if(phi[i].size()==1){
			vector<vector<int>> cnf = simplify(phi,phi[i].at(0));
			satisfiable = backtracking(cnf , variable );
			return satisfiable;
		}
	}

	int literal = pick(variable); 
	phiPrim=simplify(phi , literal);

	if(phiPrim.empty()){
		satisfiable=true;
		return satisfiable;
	} 
	
	if(!phiPrim.empty())
	{
		int i=0;
		while(i<phiPrim.size())
		{
			if(phiPrim[i].empty())
			{
				phiPrimPrim= simplify(phi  , (literal)*(-1));
				if(phiPrimPrim.empty())
				{
					satisfiable=true;
					break;
				}
				if(!phiPrimPrim.empty())
				{
					int j=0; 
					while(j<phiPrimPrim.size())
					{
						if(phiPrimPrim[j].empty())
						{
							return false; 
						}
						j++;  		
					}
					return backtracking(phiPrimPrim , variable);  
						
				}  
				break;
			}
		 	i++;	
		}
	return backtracking(phiPrim , variable); 
	
	}
	
	return satisfiable; 
}