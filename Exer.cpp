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
            cout << grid.at(i).at(j) << " ";
     
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
    cout << "Grid before update: " << gr.at(r).at(c) << endl;
    
    
    do {
        
        cout << "\nPlayer " << u1 << " , enter your symbol and coordinates -Row- |column| ==>";
        cin >> uc >> r >> c;
        if (uc != u1) {
            cout << "\nThis is not your chosen sign! Please proceed with " << u1 << ".\n";
        }
        
    } while (uc != u1); // check here the whole thing without redundency no need for X = O ...
    
    do {// start of the NUMBERS implementation
        if (r < 1 || r > 3 || c < 1 || c > 3) { // another do to check the numbers here! after the input so things go smooth and do not confuse! or no residuals !!!
            cout << "\nOur grid is only 3 x 3. Please make sure your numbers are between 1 and 3.";
            cout << "\nEnter coordinates again: ";
            cin >> r >> c;
        }
        
    } while (r < 1 || r > 3 || c < 1 || c > 3);
    
    r -= 1;
    c -= 1;
   
    
    do {
        if (gr.at(r).at(c) != '_') {
            cout << "\nPlace is taken! Choose different coordinates\n";
            cin >> r >> c;
            
        }
    }
    while (gr.at(r).at(c) != '_');
    
    gr[r][c] = uc;
    //m++removed 
    cout << "\nMoves: " << m << endl;
    
}



void oX (char u1, char& uc,char u2,  int& r, int& c,  vector<vector<char>>& gr, int& m) { // reversed the one up!!! it is practical now.
    
    
    
    cout << "\nPlayer symbol: " << uc << ", Row: " << r << ", Column: " << c << endl;//
    cout << "Grid before update: " << gr.at(r).at(c) << endl;
    
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
        if (gr.at(r).at(c) != '_') {
            cout << "\nPlace is taken! Choose different coordinates ==> ";
            cin >> r >> c;
        }
    }
    while (gr.at(r).at(c) != '_');
    
    gr.at(r).at(c) = uc;
  // m++ removed
    
    cout << "\nMoves: " << m << endl;
}

/*
. wincheck became a boolean, when void the win loop is chaoctic.
. Added const to the vector in the wincheck function.
. wincheck Whole part refactored due to the poor latest structure.
. Used .at() method only  and not mixing it with [].
. wincheck removed the > 5 condition that is causing the prorgam to end with a random winner,
  unplayable. Also removed the m++ with each iteration, now it is explicit in main.
 
 */
    
        
      
bool wincheck(const vector<vector<char>>& t, char a, char b, int m) {
    cout << "\nChecking for a winner... Moves: " << m << endl;

    // Check for Player a's win conditions
    if ((t.at(0).at(0) == a && t.at(0).at(1) == a && t.at(0).at(2) == a) || // Row 1
        (t.at(1).at(0) == a && t.at(1).at(1) == a && t.at(1).at(2) == a) || // Row 2
        (t.at(2).at(0) == a && t.at(2).at(1) == a && t.at(2).at(2) == a) || // Row 3
        (t.at(0).at(0) == a && t.at(1).at(0) == a && t.at(2).at(0) == a) || // Column 1
        (t.at(0).at(1) == a && t.at(1).at(1) == a && t.at(2).at(1) == a) || // Column 2
        (t.at(0).at(2) == a && t.at(1).at(2) == a && t.at(2).at(2) == a) || // Column 3
        (t.at(0).at(0) == a && t.at(1).at(1) == a && t.at(2).at(2) == a) || // Diagonal 1
        (t.at(0).at(2) == a && t.at(1).at(1) == a && t.at(2).at(0) == a)) { // Diagonal 2
        cout << "\nPlayer " << a << " wins!\n";
        return true; // normally returns to main if a is a winner
    }

    // Check for Player b's win conditions
    if ((t.at(0).at(0) == b && t.at(0).at(1) == b && t.at(0).at(2) == b) ||
        (t.at(1).at(0) == b && t.at(1).at(1) == b && t.at(1).at(2) == b) ||
        (t.at(2).at(0) == b && t.at(2).at(1) == b && t.at(2).at(2) == b) ||
        (t.at(0).at(0) == b && t.at(1).at(0) == b && t.at(2).at(0) == b) ||
        (t.at(0).at(1) == b && t.at(1).at(1) == b && t.at(2).at(1) == b) ||
        (t.at(0).at(2) == b && t.at(1).at(2) == b && t.at(2).at(2) == b) ||
        (t.at(0).at(0) == b && t.at(1).at(1) == b && t.at(2).at(2) == b) ||
        (t.at(0).at(2) == b && t.at(1).at(1) == b && t.at(2).at(0) == b)) {
        cout << "\nPlayer " << b << " wins!\n";
        return true; //also should return to main in case b is winner
    }

    // No winner yet to track the bug. 
    cout << "No winner yet. Keep playing.\n";
    return false; // No winner
}
    
    


