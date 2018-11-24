#include "readFile.h"
#include "backtracking.h"
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
    vector<int> model;
    vector<int> variable = readFile(fichier,phi); 
    
    bool sat = backtracking(phi , variable);
     if(sat){
         cout<< "s AAAAAASATISFIABLE" << endl ;

     }else {
          cout<< "s UNSATISFIABLE" << endl ;
     }



   
    return 0;
}

