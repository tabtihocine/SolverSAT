#include "readFile.h"
#include "pick.h"
#include "simplify.h"

using namespace std; 

int main(int argc, char const *argv[])
{
   if (argc != 2){
       cerr<< "EREEUR : LE PROGRAMME A BESOIN D'UN SEUL FICHIER EN PARAMETRE"<< endl; 
       cerr << " USAGE : ./SAT fichier.cnf "<< endl; 
       return 1;
   }

    ifstream fichier(argv[1] , ios::in); 

    vector<vector<int>> phi;
    vector<int> occurenceVar = readFile(fichier,phi); 

     for (int i=0 ; i<phi.size();i++){
         for (int j=0 ; j<phi[i].size();j++){
             cout << phi[i][j]<< " ";
         }
         cout << endl;

     }
    int literalChosed = pick(occurenceVar); 
    cout<< "le literal est : " << literalChosed<< endl;

    vector<vector<int>> phiPrim = simplify(phi,literalChosed); 

    for (int i=0 ; i<phiPrim.size();i++){
         for (int j=0 ; j<phiPrim[i].size();j++){
             cout << phiPrim[i][j]<< " ";
         }
         cout << endl;
     }
    
    return 0;
}

