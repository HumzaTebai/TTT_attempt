//
//  main.cpp
//  Exer3
//
//  Created by Hamza Tebai on 28/12/2024.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Exer.hpp"
using namespace std;

int main() {
    
    string playagain {"yes"};
    
    
    while (playagain == "yes"){
        
        cout << "\n\n========== NEW GAME ==========\n\n";
        char user1choice {'\0'};
        char user2choice {'\0'};
        int r {0};
        int c {0};
        
        cout << "\n*^*^*^*^*^*^*^*^*^*^*^*^\n";
        
        cout << "\n\tTik Tak Toe!!\n\n";
        
        cout << "\n\tLet's play!\n";
        
        cout << "\n*^*^*^*^*^*^*^*^*^*^*^*^\n";
        
        vector<vector<char>> grid = {
            
            { '_', '_', '_'},
            { '_', '_', '_'},
            { '_', '_', '_'}
            
        };
        
        showGrid(grid);
        
        cout << "\nFirst let's chose who is X and who is O\n";
        
        cout << "\nOne of you should chose X or O and the other will be automatically assigned the other sign\n";
        
        choice(user1choice, user2choice);
        
        cout << "\n\n*^*^*^*^*^*^*^*^*^*^*^*^\n";
        cout << "\n*^*^*^*^*^*^*^*^*^*^*^*^\n\n";
        
        cout << "\nNow that Player 1 is -> " << user1choice << " <- and Player 2 is -> " << user2choice << " <-. We Start!";
        
        cout << "\n\n*^*^*^*^*^*^*^*^*^*^*^*^\n";
        cout << "\n*^*^*^*^*^*^*^*^*^*^*^*^\n\n";
        
        cout << "\nPlayer 1 Start!";
        
        char usercorrection = user1choice;
        
        int moves {0};
        
        char currentPlayer = user1choice;
        
        bool gameOver = false; // added bool here for game over check.
        
        while (moves < 9 && !gameOver) {
               cout << "\nPlayer " << (currentPlayer == user1choice ? "1" : "2") << ":\n";

               if (currentPlayer == user1choice) {
                   xO(user1choice, usercorrection, user2choice, r, c, grid, moves);
               } else {
                   oX(user1choice, usercorrection, user2choice, r, c, grid, moves);
               }

               moves++;
               showGrid(grid);

               // Check for a winner
               if (moves >= 5) {
                   gameOver = wincheck(grid, user1choice, user2choice, moves);
               }

               // Handle draw condition
               if (moves == 9 && !gameOver) {
                   cout << "\nIt's a draw! No one wins.\n";
                   break;
               }

               // Switch players
               currentPlayer = (currentPlayer == user1choice) ? user2choice : user1choice;
           }

        
        cout << "\nDo you want to play again? Yes/ No ==> ";
        cin >> ws; // Clear the leading whitespace, maybe it is the problem?
        getline(cin, playagain); // used getline to make sure the input is captured, maybe spaces are a problem?.
        transform(playagain.begin(), playagain.end(), playagain.begin(), ::tolower);
        cin.ignore();
    }
    cout << "\n\n*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^\n";
    cout << "\nThank you for playing. See you soon!\n";
    cout << "\n*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^\n";
    
    
    return 0;
}
