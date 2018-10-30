#include "simplify.h"

void simplify(vector< vector<int> >& CNF, int x){

    for(int i=0;i<= CNF.size()-1;i++){
        int j=0;
        
        while(j <= CNF.size()-1 && !CNF[i].empty()){
            if(CNF[i].at(j) == x){
                CNF.erase(CNF.begin()+i);
                break;
            }
            else if(CNF[i].at(j)==(x*-1)){
                CNF[i].erase((CNF[i].begin())+j);
                break;
            }
            else{

            }
            j++;
        }
        if(CNF.empty()){
            break;
        }
        
    }
}