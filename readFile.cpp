#include "readFile.h"

using namespace std; 
/**
 * une méthode qui lis un fichier cnf, pour un fichier cnf donner elle le lis 
 * compte le monbre de variable qu'il y'a et leur nombre d'occurence , et elle
 * sotck la CNF dans un vecteur de vecteur ou chaque vecteur est une clause
 * fichier : le fichier qui contien la CNF 
 * CNF : le vecteur de vecteur ou sera srocker la CNF 
 * elle renvoi un vecteur qui indique lenombre d'occurence de chaque variable
 */
vector<int> readFile(ifstream& fichier , vector<vector<int>>& CNF)
{    
        string line; 
        int numVar=0;
        int literal;
        int index; 
         
        for(int i=0 ;i<=1; i++)
        {
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

