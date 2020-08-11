#include <iostream>
#include "mcts.h"
using namespace std;

int main(){
    Reversi game;
    MCTS aiMonte;

    while(1) {
        game.printBoard();

        int gameEnd = game.checkGameOver();
        if (gameEnd >= 0){
                cout << "GAME OVER" << endl;
                if (gameEnd == 1){
                    cout << "Black wins" << endl;
                }
                else if (gameEnd == 2){
                    cout << "White wins" << endl;
                }
                else{
                    cout << "TIE" << endl;
                }
                break;
            }

        bool skip = game.turnSkip(game.getTurn());
        if(skip) {
            cout << "No moves, turn (" << game.getTurn() << ") skipped" << endl; 
        }
        else {
            moveCoords move;
            if(game.getTurn() == BLACK) {
                move = aiMonte.doMove(game, false);
            }
            else {
                move = aiMonte.doMove(game, true);
            }
            game.placePiece(move.x, move.y);
            game.switchTurn();
            game.checkGameState();
            cout << "Turn: " << game.getTurn() << endl;
            cout << "x: " << move.x << ", y: " << move.y << endl;
            cout << "Black chips: " << game.getBlackChips() << endl;
            cout << "white chips: " << game.getWhiteChips() << endl;
        }
    }
    // int turn = 1; 
    
    // while(1){
    //     if(turn == 1){
    //         int x;
    //         int y;
    //         game.printBoard();
    //         game.printPotentialMoves(game.potentialMoves(turn));
    //         cout<< "x value: ";
    //         cin >> x;
    //         cout<< "y value: ";
    //         cin >> y;

    //         bool skip = game.turnSkip(turn);
    //         if (skip){
    //             cout << "No moves, turn skipped" << endl;
    //         }
    //         else{
    //             game.placePiece(x,y);
    //             game.switchTurn();
    //             cout << turn << endl;
    //         }
        
    //         int gameEnd = game.checkGameOver();
    //         int blackChips = game.getBlackChips();
    //         int whiteChips = game.getWhiteChips();

    //         cout << "black score: " << blackChips << endl;
    //         cout << "white score: " << whiteChips << endl;
            

    //         if (gameEnd >= 0){
    //             cout << "GAME OVER" << endl;
    //             if (gameEnd == 1){
    //                 cout << "Black wins" << endl;
    //             }
    //             else if (gameEnd == 2){
    //                 cout << "White wins" << endl;
    //             }
    //             else{
    //                 cout << "TIE" << endl;
    //             }
    //             break;
    //         }
            
    //         turn++;
            
    //         game.printBoard();
    //     }
    //     else{
            
    //         bool skip = game.turnSkip(turn);
    //         if (skip){
    //             cout << "No moves, turn skipped" << endl;
    //             turn--;
    //         }
    //         else{
    //             moveCoords move = aiMonte.doMove(game, false);
    //             game.placePiece(move.x,move.y);
    //             game.switchTurn();
    //         }
            
    //         turn--;
    //     }
        
    // }
    
    
    
}