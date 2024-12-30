//
//  Exer.cpp
//  Exer3
//
//  Created by Hamza Tebai on 28/12/2024.
//

#include "Exer.hpp"
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
using std::cin;



void showGrid(const vector<vector<char>>& grid ) {
    
    for (int i = 0; i < grid.size(); i ++) {
        for (int j = 0; j < grid[i].size(); j++) {
            cout << grid[i][j] << " ";
     
        }
        cout << endl;
    }
    
}


void choice (char& p1 ,char& p2) {
    
    cout << "\nEnter your choice here ==> ";
    
    cin >> p1;
    
    
    while (p1 != 'X' && p1 != 'X' && p1 != 'O' && p1 != 'o') {
        
        cout << "\nThe classic game is X and O :D , please enter one of them. Enter again ==> ";
        
        cin >> p1;
    }
    
    if (p1 == 'X' || p1 == 'x') {
        
        p2 = 'O';
        
        cout << "\nOkay, Player 1 you chose => "<< p1 << " <=  and Player 2 will be => "<< p2 << " <=  .Let's go" << endl;
    } else if (p1 == 'O' || p1 ==  'o') {
        
        p2 = 'X';
        cout << "\nOkay, Player 1 you chose -> " << p1 << " <- and Player 2 will be -> " << p2 << " <- .Let's go";
    }
    
    
}





void xO (char u1, char& uc,char u2,  int& r, int& c, vector<vector<char>>& gr, int& m) {
    
    cout << "\nPlayer symbol: " << uc << ", Row: " << r << ", Column: " << c << endl; //added condition check here for the place. 
    cout << "Grid before update: " << gr[r][c] << endl;
    
    
    do {
        
        cout << "\nPlayer " << u1 << " , enter your symbol and coordinates -Row- |column| ==>";
        cin >> uc >> r >> c;
        if (uc != u1) {
            cout << "\nThis is not your chosen sign! Please proceed with " << u1 << ".\n";
        }
        
    } while (uc != u1); // check here the whole thing without redundency no need for X = O ...
    
    do {// start of the NUMBERS implementation
        if (r < 1 || r > 3 || c < 1 || c > 3) { // aother do to check the numbers here! after the input so things go smooth and do not confuse! or no residuals !!!
            cout << "\nOur grid is only 3 x 3. Please make sure your numbers are between 1 and 3.";
            cout << "\nEnter coordinates again: ";
            cin >> r >> c;
        }
        
    } while (r < 1 || r > 3 || c < 1 || c > 3);
    
    r -= 1;
    c -= 1;
   
    
    do {
        if (gr[r][c] != '_') {
            cout << "\nPlace is taken! Choose different coordinates\n";
            cin >> r >> c;
            
        }
    }
    while (gr[r][c] != '_');
    
    gr[r][c] = uc;
    m ++;
    cout << "\nMoves: " << m << endl;
    
}



void oX (char u1, char& uc,char u2,  int& r, int& c,  vector<vector<char>>& gr, int& m) { // reversed the one up!!! it is practical now.
    
    
    
    cout << "\nPlayer symbol: " << uc << ", Row: " << r << ", Column: " << c << endl;//
    cout << "Grid before update: " << gr[r][c] << endl;
    
    do {
        
        cout << "\nPlayer " << u2 << " , enter your symbol and coordinates -Row- |column| ==>";
        cin >> uc >> r >> c;
        if (uc != u2) {
            cout << "\nThis is not your chosen sign! Please proceed with " << u2 << ".\n";
        }
        
    } while (uc != u2);
    
    do {
        if (r < 1 || r > 3 || c < 1 || c > 3) {
            cout << "\nOur grid is only 3 x 3. Please make sure your numbers are between 1 and 3.";
            cout << "\nEnter coordinates again: ";
            cin >> r >> c;
        }
        
    } while (r < 1 || r > 3 || c < 1 || c > 3);
    
    r -= 1;
    c -= 1;
    
    do {
        if (gr[r][c] != '_') {
            cout << "\nPlace is taken! Choose different coordinates ==> ";
            cin >> r >> c;
        }
    }
    while (gr[r][c] != '_');
    
    gr[r][c] = uc;
    m++;
    
    cout << "\nMoves: " << m << endl;
}


void wincheck(vector<vector<char>>& t, char a, char b, int& m) {
    

    
    if (m >= 5 &&
        ((a == t.at(0).at(0) && a == t.at(0).at(1) && a == t.at(0).at(2)) || // Row 1
         (a == t.at(1).at(0) && a == t.at(1).at(1) && a == t.at(1).at(2)) || // Row 2
         (a == t.at(2).at(0) && a == t.at(2).at(1) && a == t.at(2).at(2)) || // Row 3
         (a == t.at(0).at(0) && a == t.at(1).at(0) && a == t.at(2).at(0)) || // Column 1
         (a == t.at(0).at(1) && a == t.at(1).at(1) && a == t.at(2).at(1)) || // Column 2
         (a == t.at(0).at(2) && a == t.at(1).at(2) && a == t.at(2).at(2)) || // Column 3
         (a == t.at(0).at(0) && a == t.at(1).at(1) && a == t.at(2).at(2)) || // Main diagonal
         (a == t.at(0).at(2) && a == t.at(1).at(1) && a == t.at(2).at(0)))){
        cout << "\nPlayer " << a << " WiNsSsS!!!\n";
        
    } else {
        cout << "\nPlayes " << b << " Is the Winnerrr!\n";
    }
    
    
}

