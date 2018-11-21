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
    vector<int> variable = readFile(fichier,phi); 

     
    return 0;
}

