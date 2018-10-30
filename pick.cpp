#include "pick.h"

using namespace std; 

int pick(vector<int>& ocurVariable){

    int maxOcur=0;
    int literal;

    for(int i=0 ; i<ocurVariable.size() ; i++){
        if(maxOcur<ocurVariable[i]){
            maxOcur=ocurVariable[i];
            literal=i; 
            ocurVariable[i]=0; 
        }
    }
    return literal;
}