#ifndef __BACKTRACKING_H
#define __BACKTRACKING_H

#include <vector>
#include <iostream>
#include "pick.h"
#include "simplify.h"

using namespace std;

bool backtracking(vector<vector<int>>& CNF ,vector<int>& variable,vector<int>& w);
bool hasEmptyClause (vector<vector<int>>& cnf); 
bool isIn(vector< int>& m , int x); 

#endif  