#include "simplify.h"
using namespace std;


vector<vector<int>> simplify(vector< vector<int> >& cnf, int x){
    vector<vector<int>> phi=cnf;

	for(int i = 0; i <= (phi.size() - 1); i++){
		int j = 0;
        
		while(j <= (phi[i].size() - 1) && !phi[i].empty()){
			if(phi[i].at(j) == x){
				phi.erase(phi.begin()+i);
                i--;
			}
			else if(phi[i].at(j) == (x * -1)){
				phi[i].erase((phi[i].begin())+j);	
			}
			//else{}
			j++;
		}
		if(phi.empty())
			break;
	}

   return phi; 
}