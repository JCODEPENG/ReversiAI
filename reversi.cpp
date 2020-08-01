#include "reversi.h"
#include <iostream>
#include <vector>
using namespace std;
#define SIZE    8


//initializing board
Reversi::Reversi(){
    for (int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            board[i][j] = 0;
        }
    }
    board[3][3] = 1;
    board[3][4] = 2;
    board[4][4] = 1;
    board[4][3] = 2;
}

//checking the potential moves depending on whose turn it is via int color
//i think int direction is useless actually
vector<moveCoords> Reversi::potentialMoves(int color, int direction){
    vector<moveCoords> pieceLocations;
    vector<moveCoords> moves;
    int opposite;
    //based on whose color it is, the besiding piece must be opposite color so 
    //determine the opposite color
    if (color == 1){
        opposite = 2;
    }
    else{
        opposite = 1;
    }
    //find all the pieces of whose turn it is 
    for (int i = 0; i < SIZE; i++){  
        for (int j = 0; j < SIZE; j++){
            if (board[i][j] == color){
                moveCoords coords;
                coords.x = i;
                coords.y = j;
                pieceLocations.push_back(coords);
            }
        }
    }
   

    //go through all the pieces and check if two spots away is empty but 1 spot away is the opposite color
    for (int i = 0; i < pieceLocations.size(); i++){
        int xCoord = pieceLocations[i].x;
        int yCoord = pieceLocations[i].y;
        if (xCoord <= 0 || xCoord-1 <= 0 || xCoord >= SIZE-1 || xCoord+1 >= SIZE-1 ){
            continue;
        }
        if (yCoord <= 0 || yCoord-1 <= 0 || yCoord >= SIZE-1 || yCoord+1 >= SIZE-1 ){
            continue;
        }

        if (board[xCoord+1][yCoord] == opposite){
            if (board[xCoord+2][yCoord] == 0){
                moveCoords newCoords;
                newCoords.x = xCoord+2;
                newCoords.y = yCoord;
                moves.push_back(newCoords);
            }
        }
        if (board[xCoord-1][yCoord] == opposite){
            if (board[xCoord-2][yCoord] == 0){
                moveCoords newCoords;
                newCoords.x = xCoord-2;
                newCoords.y = yCoord;
                moves.push_back(newCoords);
            }
        }
        if (board[xCoord][yCoord+1] == opposite){
            if (board[xCoord][yCoord+2] == 0){
                moveCoords newCoords;
                newCoords.x = xCoord;
                newCoords.y = yCoord+2;
                moves.push_back(newCoords);
            }
        }
        if (board[xCoord][yCoord-1] == opposite){
            if (board[xCoord][yCoord-2] == 0){
                moveCoords newCoords;
                newCoords.x = xCoord;
                newCoords.y = yCoord-2;
                moves.push_back(newCoords);
            }
        }
        if (board[xCoord+1][yCoord+1] == opposite){
            if (board[xCoord+2][yCoord+2] == 0){
                moveCoords newCoords;
                newCoords.x = xCoord+2;
                newCoords.y = yCoord+2;
                moves.push_back(newCoords);
            }
        }
        if (board[xCoord+1][yCoord-1] == opposite){
            if (board[xCoord+2][yCoord-2] == 0){
                moveCoords newCoords;
                newCoords.x = xCoord+2;
                newCoords.y = yCoord-2;
                moves.push_back(newCoords);
            }
        }
        if (board[xCoord-1][yCoord-1] == opposite){
            if (board[xCoord-2][yCoord-2] == 0){
                moveCoords newCoords;
                newCoords.x = xCoord-2;
                newCoords.y = yCoord-2;
                moves.push_back(newCoords);
            }
        }
        if (board[xCoord-1][yCoord+1] == opposite){
            if (board[xCoord-2][yCoord+2] == 0){
                moveCoords newCoords;
                newCoords.x = xCoord-2;
                newCoords.y = yCoord+2;
                moves.push_back(newCoords);
            }
        }

    }
    printPotentialMoves(moves);
    return moves;
}

//just printing the coordinates of potential moves
void Reversi::printPotentialMoves(vector<moveCoords> moves){
    cout<< "size is " << moves.size()<< endl;
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

//checks the score for black and white pieces 
void Reversi::checkGameState(){
    int counter1 = 0;
    int counter2 = 0; 
    for (int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if (board[i][j] == 1){
                counter1++;
            }
            if (board[i][j] == 2){
                counter2++;
            }
        }
    }
    whiteChips = counter1;
    blackChips = counter2;
}

bool Reversi::placePiece(int color, int x, int y){
    bool flag;
    vector<moveCoords> availableMoves = potentialMoves(color, 1);
    for (int i = 0; i < availableMoves.size(); i++){
        if (availableMoves[i].x == x && availableMoves[i].y == y){
            flag = true;
        }
    }
    if (!flag){
        return false;
    }
    else{
        
    }

}

//checks if the board is filled
bool Reversi::checkGameOver(){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            if (board[i][j] == 0){
                return false;
            }
        }
    }
    return true;
}