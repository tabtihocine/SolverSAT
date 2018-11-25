#include "backtracking.h"
using namespace std;

bool backtracking(vector<vector<int>>& phi , vector<int>& variable)
{

	bool satisfaisable= true; 
	vector<vector<int>> phiPrim;
	vector<vector<int>> phiPrimPrim;
	cout << "retour "<< endl; 
	if(phi.empty())
	{	
		cout<< " phi vide "<< endl;
		satisfaisable= true; 
		return satisfaisable; 
	}



	for(int i=0 ; i<phi.size();i++)
	{
		if(phi[i].empty())
		{	
			cout<< " phi a une clause vide vide "<< endl;
			satisfaisable=false;
			return satisfaisable;
		}
	}

	for(int i=0 ; i<phi.size();i++)
	{
		if(phi[i].size()==1)
		{
			cout<< " phi a une clause unitaire "<< endl;
			vector<vector<int>> phiTemp = simplify(phi , phi[i][0]); 
			cout<< "phi simple"<< endl;
			satisfaisable= backtracking(phiTemp , variable);
			cout << " aprés back"<< endl;
			return satisfaisable;
			
		}

	}

	  cout << " chose ======="<< endl;  
	int literal = pick(variable); 
	cout << " x = "<< literal<< endl;  
	phiPrim=simplify(phi, literal); 

	
		if(backtracking(phiPrim , variable))
	{
		satisfaisable=true;
		
		return satisfaisable; 
	}
	else
	{
		phiPrimPrim=simplify(phi , -literal);
		satisfaisable = backtracking(phiPrimPrim , variable);
		return satisfaisable; 
	}
	
}