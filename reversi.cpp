#include "reversi.h"
#include <iostream>
#include <vector>
using namespace std;
#define SIZE    8



Reversi::Reversi(){
    for (int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            board[i][j] = 0;
        }
    }
}

vector<moveCoords> Reversi::potentialMoves(){
    vector<moveCoords> moves;
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            if (board[i][j] == 0){
                moveCoords coords;
                coords.x = i;
                coords.y = j;
                moves.push_back(coords);
            }
        }
    }
    printPotentialMoves(moves);
    return moves;
}

void Reversi::printPotentialMoves(vector<moveCoords> moves){
    for (int i = 0; i < moves.size(); i++){
        cout << "{" << moves[i].x << "," << moves[i].y << "}" << endl;
    }
}

void Reversi::printBoard(){
    for (int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            cout << board[i][j] << " ";
        }
        cout<< endl;
    }
}