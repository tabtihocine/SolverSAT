#include "simplify.h"
using namespace std;


vector<vector<int>>simplify(vector<vector<int>>& CNF, int literal){

vector<vector<int>> CNFprime = CNF;

	for(int i = 0; i<=CNFprime.size()-1 ; i++){
		int j = 0;
		while(j <= CNFprime[i].size()-1 && !CNFprime[i].empty()){
			if(CNFprime[i].at(j) == literal){
                // suprimer la clause ou apparai le literal choisi 
				CNFprime.erase(CNFprime.begin()+i);
				break;
			}
			else {if(CNFprime[i].at(j) == (literal*-1)){
                // suprimé le litetral choisi
				CNFprime[i].erase((CNFprime[i].begin())+j);
				break;
			}
            }
			j++;
		}
		if(CNFprime.empty())
			break;
	}

    return CNFprime;
}


/*
vector<vector<int>> simplify(vector< vector<int> >& CNF, int x){

vector<vector<int>>CNFprime= CNF;

for(int i=0 ; i<CNFprime.size() ; i++ ){
    for(int j=0 ; j<CNFprime[i].size()-1 ;j++){
        if(!CNFprime[i].empty()){
             if(CNFprime[i].at(j)==x){

            CNFprime.erase(CNFprime.begin()+j);
            break;
            
        }else{

            if(CNF[i].at(j)==(x*-1)){

                CNFprime[i].erase(CNFprime[i].begin()+j);
                break;
            }
        }
        }else{
            break;
        }
    }
}
return CNFprime; 
}*/