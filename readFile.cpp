#include "readFile.h"

using namespace std; 

vector<int> readFile(ifstream& fichier , vector<vector<int>>& CNF)
{
     
        string line; 
        int numVar=0;
        int literal;
        int index; 
         
         for(int i=0 ;i<=1; i++){
             fichier >> line; 
         }
        
        fichier >> numVar; 
        fichier >> line; 

        vector<int> ocurVariable(numVar+1 , 0); 
        
        while(fichier){
            vector<int> clause; 
            fichier >> literal; 

            while(literal!=0){
                clause.push_back(literal); 
                index=abs(literal);
                ocurVariable.at(index)++;
                 fichier >> literal; 
            }  
            CNF.push_back(clause); 

        }
       

    return ocurVariable;
}

