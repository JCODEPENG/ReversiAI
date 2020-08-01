#include <iostream>
#include "reversi.h"
using namespace std;

int main(){
    Reversi game;
    game.printBoard();
    game.potentialMoves(1, 2);
}