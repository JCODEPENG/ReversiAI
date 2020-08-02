#include <iostream>
#include "reversi.h"
using namespace std;

int main(){
    Reversi game;
    game.printBoard();
    int turn = 1; 
    
    while(1){
        int x;
        int y;
        game.potentialMoves(turn, 1);
        cout<< "x value: ";
        cin >> x;
        cout<< "y value: ";
        cin >> y;
        game.placePiece(turn,x,y);
        if (turn == 1){
            turn++;
        }
        else{
            turn--;
        }
        game.printBoard();
        
    }
    
    
}