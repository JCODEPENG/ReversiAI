#include "reversi.h"
#include <iostream>
using namespace std;

Reversi::Reversi(){
    for (int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            board[i][j] = 0;
        }
    }
}

void Reversi::printBoard(){
    for (int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cout << board[i][j] << " ";
        }
        cout<< endl;
    }
}