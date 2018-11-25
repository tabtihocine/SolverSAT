#include "simplify.h"
using namespace std;


vector<vector<int>> simplify(vector< vector<int> >& cnf, int x){
    vector<vector<int>> phi=cnf;

	for(int i = 0; i <phi.size() ; i++){
		int j = 0;
        
		while(j <phi[i].size()  && !phi[i].empty()){
			if(phi[i].at(j) == x){
				phi.erase(phi.begin()+i);
                break;
			}
			else if(phi[i].at(j) == -x){
				phi[i].erase((phi[i].begin())+j);
				break;	
			}
			j++;
		}
		if(phi.empty())
			break;
	}

   return phi; 
}