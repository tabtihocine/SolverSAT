#include "readFile.h"

using namespace std; 

int main(int argc, char const *argv[])
{
   if (argc < 1 || argc > 1){
       cerr<< "EREEUR : LE PROGRAMME A BESOIN D'UN SEUL FICHIER EN PARAMETRE"<< endl; 
       cerr << "SAT fichier.cnf "<< endl; 
   }

    ifstream fichier(argv[1] , ios::in); 
    
    vector<vector<int>> phi;
    vector<int> var= readFile(fichier,phi); 

    /*for(int i=0 ; i<CNF.size(); i++){
            for(int j=0 ; j<CNF[i].size();j++){
                cout << CNF[i][j]<< endl;
            }
            
        }*/

        for(int i =0; i<var.size();i++){
            cout<<var[i] << " || " ; 
        }

    return 0;
}

