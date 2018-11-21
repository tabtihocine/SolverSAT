#include "backtracking.h"
#include "pick.h"
#include "simplify.h"

using namespace std;

bool backtracking(vector<vector<int>>& CNF ,vector<int>& variable , vector<int>& model){
    bool SATISFIABLE;
    

    if(CNF.empty()){
        SATISFIABLE=false;
        return SATISFIABLE;  
    }
    
    for(int i=0 ; i< CNF.size() ; i++){
        if(CNF[i].empty()){
            SATISFIABLE=false;
            return SATISFIABLE; 
        }
    }

    int literal = pick(variable);
    vector<vector<int>>CNFprim = simplify(CNF,literal);

    if(CNFprim.empty()){
       SATISFIABLE=true;
       model.push_back(literal);
       return SATISFIABLE; 
    }
    else {
        for(int i=0 ; i<CNFprim.size() ; i++){
            if(CNFprim[i].empty()){
                vector<vector<int>>CNF2prim=simplify(CNF,literal* -1); 
            }
        }
        
    }



}