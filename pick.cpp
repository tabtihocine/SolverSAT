#include "pick.h"

using namespace std; 
/*
* méthode qui recherche la le literal qui a le plus grand nombre d'ocurence 
* elle renvoie ce literal et remis son nombre d'ocurence a zéro 
*/
int pick(vector<int>& ocurVariable){

    int maxOcur=0;
    int literal;
    
    for(int i=0 ; i<ocurVariable.size() ; i++){
        if(maxOcur<ocurVariable[i]){
            maxOcur=ocurVariable[i];
            literal=i;
            //Pour éviter de choisir ce litéral une nouvelle fois on le met a zero
            ocurVariable[i]=0;
            
        }
    }

    ocurVariable[literal]=0; 

    return literal;
}
