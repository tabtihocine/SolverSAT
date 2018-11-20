#ifndef __READFILE_H
#define __READFILE_H

#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

vector<int> readFile(ifstream& fichier , vector<vector<int>>&CNF);

#endif  