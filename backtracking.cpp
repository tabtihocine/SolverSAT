#include "backtracking.h"
using namespace std;

bool hasEmptyClause (vector<vector<int>>& cnf){
	bool empty;
	for(int i=0 ; i<cnf.size() ; i++){
		if(cnf[i].empty()){
			return true;
		}
	}
return false; 
} 


bool isIn(vector<int>& w , int x){
	for(int i =0 ; i<w.size() ; i++){
		if(abs(x)==abs(w[i])){
			return true;
		}
	}
	 return false; 
}

bool backtracking(vector<vector<int>>& phi , vector<int>& variable , vector<int>& w)
{	
	bool satisfaisable; 
	vector<vector<int>> phiPrim;
	vector<vector<int>> phi2Prim;
	vector<vector<int>> phiUnit; 

	if(phi.empty()){
		satisfaisable=true;
		return satisfaisable;
	}
	if(hasEmptyClause(phi)){
		satisfaisable=false;
		return satisfaisable;
	}
	


for(int i =0 ; i<phi.size() ; i++){

		for(int j =1 ; j<phi.size(); j++){

			if(  phi[i].size()==1 && phi[j].size()==1) {
				
				if(i!=j){
					if(phi[i][0] == -phi[j][0]  ){

					cout << i << "  " << j << endl ;
					satisfaisable =false;
					return satisfaisable; 
				}

				}
				
			}
		}
	}




	for(int i=0 ; i<phi.size() ; ++i){
		if(phi[i].size()==1){
			phiUnit = simplify(phi , phi[i].at(0));
			if(isIn(w,phi[i].at(0))==false){
			w.push_back(phi[i].at(0));
			}
			satisfaisable = backtracking(phiUnit, variable,w);
			return satisfaisable;
		}
	}
	
	int literal=pick(variable);
	if(literal==0){
		satisfaisable=false;
		return satisfaisable;
	}
	phiPrim=simplify(phi , literal);
	
	if(backtracking(phiPrim,variable,w)){
		if(isIn(w,literal)==false){
			w.push_back(literal);
		}
		satisfaisable=true;
		return satisfaisable;
	}else{
		phi2Prim=simplify(phi, -literal); 
		satisfaisable =backtracking(phi2Prim,variable,w);
		if(satisfaisable){
			if(isIn(w,literal)==false){
			w.push_back(-literal);
			}
		}
		return satisfaisable; 
	}


/* 
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
			model.push_back(phi[i][0]);
			vector<vector<int>> phiTemp = simplify(phi , phi[i][0]); 
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
					if (!satisfaisable){
						model.pop_back();
					}
					return satisfaisable; 
				}
			}

		}else{
			model.push_back(literal);
			satisfaisable= backtracking(phiPrim,variable,model);
			if (!satisfaisable){
						model.pop_back();
					}
			return satisfaisable;
		}
	}
*/

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
}



