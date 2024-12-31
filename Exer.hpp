//
//  Exer.hpp
//  Exer3
//
//  Created by Hamza Tebai on 28/12/2024.
//

#pragma once

#include <vector>
#include <iostream>
using std::vector; 

void showGrid(const vector<vector<char>>& grid );

void xO (char u1, char& uc,char u2,  int& r, int& c, vector<vector<char>>& gr, int& m);
    
void oX (char u1, char& uc,char u2,  int& r, int& c, vector<vector<char>>& gr, int& m);

void choice (char& p1 ,char& p2);
    
bool wincheck(const vector<vector<char>>& t, char a, char b, int m);
    
    
