#include <iostream>
#include "reversi.h"
using namespace std;

int main(){
    Reversi game;
    game.printBoard();
    game.potentialMoves(1, 2);
    game.placePiece(2, 2, 3);
    game.printBoard();
    game.placePiece(1, 2, 2);
    game.printBoard();
}