#include "readFile.h"
#include "pick.h"
#include "simplify.h"

using namespace std; 

int main(int argc, char const *argv[])
{
   if (argc != 2){
       cerr<< "EREEUR : LE PROGRAMME A BESOIN D'UN SEUL FICHIER EN PARAMETRE"<< endl; 
       cerr << " USAGE : ./SAT fichier.cnf "<< endl; 
   }

    ifstream fichier(argv[1] , ios::in); 
    vector<vector<int>> phi;

    vector<int> occurenceVar = readFile(fichier,phi); 
for (int i=0 ; i<phi.size();i++){
         for(int j=0 ; j<phi[i].size();i++){
             cout << phi[i][j] << " ";
         }
         cout << endl;
     }
    int literalCosed = pick(occurenceVar); 

    cout<< "le literal est : " << literalCosed<< endl;

 /*   vector<vector<int>> Phiprim= simplify(phi,literalCosed); 

     for (int i=0 ; i<Phiprim.size();i++){
         for(int j=0 ; j<Phiprim[i].size();i++){
             cout << Phiprim[i][j] << "  "  << endl;
         }
     }
*/
    return 0;
}

