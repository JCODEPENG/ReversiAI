#include <iostream>
#include "mcts.h"
using namespace std;

int main(){
    Reversi game;
    game.printBoard();
    cout << &game << endl;
    
    MCTS AIMonte(50000);

    AIMonte.doMove(game);
    // game.printBoard();
    // MCTS aiMonte;
    // cout << aiMonte.get_max_number_of_playouts() << endl;


    
    // int turn = 1; 
    
    // while(1){
    //     int x;
    //     int y;
    //     game.potentialMoves(turn, 1);
    //     cout<< "x value: ";
    //     cin >> x;
    //     cout<< "y value: ";
    //     cin >> y;

    //     bool skip = game.turnSkip(turn);
    //     if (skip){
    //         cout << "No moves, turn skipped" << endl;
    //     }
    //     else{
    //         game.placePiece(turn,x,y);
    //         cout << turn << endl;
    //     }
      
    //     int gameEnd = game.checkGameOver();
    //     int blackChips = game.getBlackChips();
    //     int whiteChips = game.getWhiteChips();

    //     cout << "black score: " << blackChips << endl;
    //     cout << "white score: " << whiteChips << endl;
        

    //     if (gameEnd >= 0){
    //         cout << "GAME OVER" << endl;
    //         if (gameEnd == 1){
    //             cout << "Black wins" << endl;
    //         }
    //         else if (gameEnd == 2){
    //             cout << "White wins" << endl;
    //         }
    //         else{
    //             cout << "TIE" << endl;
    //         }
    //         break;
    //     }
    //     if (turn == 1){
    //         turn++;
    //     }
    //     else{
    //         turn--;
    //     }
    //     game.printBoard();
        
    // }
    
    
    
}