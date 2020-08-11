#include <iostream>
#include "mcts.h"
using namespace std;

int main(){
    Reversi game;
    MCTS aiMonte(100);
    int choice = 0;
    cout << "***********************************" << endl;
    cout << "WELCOME TO PB&J's REVERSI GAME\n";
    cout << "***********************************" << endl;
    cout << endl;
    cout << "In our game, the black piece is represented as the number 1.\nThe white piece is represented as the number 2." << endl;
    cout << "A blank spot is represented as the number 0" << endl;
    cout << endl;
    cout << "When playing the game, please enter the input by the coordinates of a 2D array." << endl;
    cout << "For example, for the board:" << endl;
    cout << "0 0 0 0 0 0 0 0" << endl;
    cout << "0 0 0 0 0 0 0 0" << endl;
    cout << "0 0 0 0 0 0 0 0" << endl;
    cout << "0 0 0 1 2 0 0 0" << endl;
    cout << "0 0 0 2 1 0 0 0" << endl;
    cout << "0 0 0 0 0 0 0 0" << endl;
    cout << "0 0 0 0 0 0 0 0" << endl;
    cout << "0 0 0 0 0 0 0 0" << endl;

    cout << "If your color is black and you choose the move > 5 3, the following piece would be placed as follows:" << endl;
    cout << "0 0 0 0 0 0 0 0" << endl;
    cout << "0 0 0 0 0 0 0 0" << endl;
    cout << "0 0 0 0 0 0 0 0" << endl;
    cout << "0 0 0 1 2 0 0 0" << endl;
    cout << "0 0 0 1 1 0 0 0" << endl;
    cout << "0 0 0 1 0 0 0 0" << endl;
    cout << "0 0 0 0 0 0 0 0" << endl;
    cout << "0 0 0 0 0 0 0 0" << endl;
    
    cout << "-----------------------" << endl;

    while (choice != 1 && choice != 2 && choice != 3){
        cout << "Please select from one of the following options" << endl;
        cout << "Press 1 to play the Reversi AI that plays on random playouts" << endl;
        cout << "Press 2 to play the Reversi AI that plays on special heuristics" << endl;
        cout << "Press 3 to watch the random playouts Reversi AI vs the special heuristics  (battle of the ages) :)" << endl;
        cout << "> ";
        cin >> choice;
        if (choice != 1 && choice != 2 && choice != 3){
            cout << "Invalid choice. Please select a choice from the following list" << endl;
        }
    }

    if (choice == 1){

        int turn = 0;
        while (turn != 1 && turn != 2){
            cout << "Would you like to go first? (Type 1 for Y, Type 2 for N): ";
            cin >> turn;
            if (turn != 1 && turn != 2){
                cout << "Please type 1 for Y or 2 for N!" << endl;
            }
        }
        
        
        while(1){
            int gameEnd = game.checkGameOver();
            if (gameEnd >= 0){
                cout << "------------------------------" << endl;
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
                cout << "Thanks for playing!" << endl;
                cout << "------------------------------" << endl;
                break;
            }
            cout << "------------------------------" << endl;
            int blackChips = game.getBlackChips();
            int whiteChips = game.getWhiteChips();
            cout << "black score: " << blackChips << endl;
            cout << "white score: " << whiteChips << endl;
            cout << "------------------------------" << endl;
            game.printBoard();
            if(turn == 1){
                bool validMove;
                int x = -1;
                int y = -1;
                cout << "Player's Turn" << endl;
                game.printPotentialMoves(game.potentialMoves(turn));
                while(x == -1 || y == -1){ 
                    cout<< "Enter your Move in the format from one of the following coordinates above: ";
                    cin >> x;
                    cin >> y;
                    if (x == -1 || y == -1){
                        cout<< "Invalid Move. Please try again!" << endl;
                    }
                }

                bool skip = game.turnSkip(turn);
                if (skip){
                    cout << "No moves, turn skipped" << endl;
                }
                else{
                    validMove = game.placePiece(x,y);
                    if (validMove){
                        game.switchTurn();
                    }
                    else{
                        cout<< "Invalid Move. Please try again!" << endl;
                    }
                }
            
                int blackChips = game.getBlackChips();
                int whiteChips = game.getWhiteChips();
                if (skip || validMove){
                    turn++;
                }
            }
            else{
                cout << "Cpu's turn" << endl;
                cout << "Please allow some time for the Cpu to think" << endl;
                bool skip = game.turnSkip(turn);
                if (skip){
                    cout << "No moves, turn skipped" << endl;
                    turn--;
                }
                else{
                    moveCoords move = aiMonte.doMove(game, false);
                    game.placePiece(move.x,move.y);
                    game.switchTurn();
                    
                }
                turn--;
            }
            
        }
    }

    if (choice == 2){

        int turn = 0;
        while (turn != 1 && turn != 2){
            cout << "Would you like to go first? (Type 1 for Y, Type 2 for N): ";
            cin >> turn;
            if (turn != 1 && turn != 2){
                cout << "Please type 1 for Y or 2 for N!" << endl;
            }
        }
        
        
        while(1){
            int gameEnd = game.checkGameOver();
            if (gameEnd >= 0){
                cout << "------------------------------" << endl;
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
                cout << "Thanks for playing!" << endl;
                cout << "------------------------------" << endl;
                break;
            }
            cout << "------------------------------" << endl;
            int blackChips = game.getBlackChips();
            int whiteChips = game.getWhiteChips();
            cout << "black score: " << blackChips << endl;
            cout << "white score: " << whiteChips << endl;
            cout << "------------------------------" << endl;
            game.printBoard();
            if(turn == 1){
                bool validMove;
                int x = -1;
                int y = -1;
                cout << "Player's Turn" << endl;
                game.printPotentialMoves(game.potentialMoves(turn));
                while(x == -1 || y == -1){ 
                    cout<< "Enter your Move in the format from one of the following coordinates above: ";
                    cin >> x;
                    cin >> y;
                    if (x == -1 || y == -1){
                        cout<< "Invalid Move. Please try again!" << endl;
                    }
                }

                bool skip = game.turnSkip(turn);
                if (skip){
                    cout << "No moves, turn skipped" << endl;
                }
                else{
                    validMove = game.placePiece(x,y);
                    if (validMove){
                        game.switchTurn();
                    }
                    else{
                        cout<< "Invalid Move. Please try again!" << endl;
                    }
                }
            
                int blackChips = game.getBlackChips();
                int whiteChips = game.getWhiteChips();
                if (skip || validMove){
                    turn++;
                }
            }
            else{
                cout << "Cpu's turn" << endl;
                cout << "Please allow some time for the Cpu to think" << endl;
                bool skip = game.turnSkip(turn);
                if (skip){
                    cout << "No moves, turn skipped" << endl;
                    turn--;
                }
                else{
                    moveCoords move = aiMonte.doMove(game, true);
                    game.placePiece(move.x,move.y);
                    game.switchTurn();
                    
                }
                turn--;
            }
            
        }
    }
    if (choice == 3){
        int turn = 0;
        while (turn != 1 && turn != 2){
            cout << "Would you like to go first? (Type 1 for Pure Random Playouts AI, Type 2 for Heuristics AI): ";
            cin >> turn;
            if (turn != 1 && turn != 2){
                cout << "Please type 1 for Y or 2 for N!" << endl;
            }
        }
        while(1) {
            int gameEnd = game.checkGameOver();
            if (gameEnd >= 0){
                game.printBoard();
                cout << "------------------------------" << endl;
                cout << "GAME OVER" << endl;
                cout << "------------------------------" << endl;
                int blackChips = game.getBlackChips();
                int whiteChips = game.getWhiteChips();
                cout << "Final Score" << endl;
                cout << "black score: " << blackChips << endl;
                cout << "white score: " << whiteChips << endl;
                cout << "------------------------------" << endl;
                if (gameEnd == 1){
                    cout << "Black wins" << endl;
                }
                else if (gameEnd == 2){
                    cout << "White wins" << endl;
                }
                else{
                    cout << "TIE" << endl;
                }
                cout << "Thanks for playing!" << endl;
                cout << "------------------------------" << endl;
                break;
            }
            cout << "------------------------------" << endl;
            int blackChips = game.getBlackChips();
            int whiteChips = game.getWhiteChips();
            cout << "black score: " << blackChips << endl;
            cout << "white score: " << whiteChips << endl;
            cout << "------------------------------" << endl;

            game.printBoard();
            bool skip = game.turnSkip(game.getTurn());
            if(skip) {
                cout << "No moves, turn (" << game.getTurn() << ") skipped" << endl; 
                game.switchTurn();
            }
            else {
                moveCoords move;
                if(turn == 1) {
                    cout << "Pure MCTS Cpu's turn" << endl;
                    move = aiMonte.doMove(game, false);
                }
                else {
                    cout << "Heuristic MCTS Cpu's turn" << endl;
                    move = aiMonte.doMove(game, true);
                }
                game.placePiece(move.x, move.y);
                game.switchTurn();
            }
            if (turn == 1){
                turn++;
            }
            else{
                turn--;
            }
        }
    }  
}
//  Reversi game;
//     MCTS aiMonte;

//     while(1) {
//         game.printBoard();

//         int gameEnd = game.checkGameOver();
//         if (gameEnd >= 0){
//                 cout << "GAME OVER" << endl;
//                 if (gameEnd == 1){
//                     cout << "Black wins" << endl;
//                 }
//                 else if (gameEnd == 2){
//                     cout << "White wins" << endl;
//                 }
//                 else{
//                     cout << "TIE" << endl;
//                 }
//                 break;
//             }

//         bool skip = game.turnSkip(game.getTurn());
//         if(skip) {
//             cout << "No moves, turn (" << game.getTurn() << ") skipped" << endl; 
//         }
//         else {
//             moveCoords move;
//             if(game.getTurn() == BLACK) {
//                 move = aiMonte.doMove(game, false);
//             }
//             else {
//                 move = aiMonte.doMove(game, true);
//             }
//             game.placePiece(move.x, move.y);
//             game.switchTurn();
//             game.checkGameState();
//             cout << "Turn: " << game.getTurn() << endl;
//             cout << "x: " << move.x << ", y: " << move.y << endl;
//             cout << "Black chips: " << game.getBlackChips() << endl;
//             cout << "white chips: " << game.getWhiteChips() << endl;
//         }
//     }
//
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
    