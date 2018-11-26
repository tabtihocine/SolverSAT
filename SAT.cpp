#include "readFile.h"
#include "backtracking.h"
#include <algorithm>

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
    phi.pop_back();
    cout << " back " << endl; 
    bool SAT = backtracking(phi, variable,model); 

   // model.erase(unique(model.begin(), model.end()) ,  model.end());


    if(SAT){
       cout << "s SATISFIABLE" << endl;
       for(int i=0 ; i< model.size();i++){
           cout << model[i] << " " ; 
       }
       cout<< endl ; 
    }else{
       cout << "s UNSATISFIABLE" << endl;
    }

    return 0;
}

