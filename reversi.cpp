#include "reversi.h"

using namespace std;



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

Reversi::Reversi(reversi_board& board, int whiteChips, int blackChips) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            this->board[i][j] = board[i][j];
        }
    }
    this->blackChips = blackChips;
    this->whiteChips = whiteChips;
}

bool existsInPotential(int x, int y, vector<moveCoords> moves){
    for (int i = 0; i < moves.size(); i++){
        if (x == moves[i].x && y == moves[i].y){
            return true;
        }
    }
    return false;
}

//checking the potential moves depending on whose turn it is via int color
//i think int direction is useless actually
vector<moveCoords> Reversi::potentialMoves(int color){
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
    for (unsigned int i = 0; i < pieceLocations.size(); i++){
        int xCoord = pieceLocations[i].x;
        int yCoord = pieceLocations[i].y;
        

        if (xCoord+1 < SIZE && board[xCoord+1][yCoord] == opposite){
            int x = xCoord+2;
            while (x < SIZE){
                if (board[x][yCoord] == color){
                    break;
                }
                if (board[x][yCoord] == 0){
                    moveCoords newCoords;
                    newCoords.x = x;
                    newCoords.y = yCoord;
                    if (!existsInPotential(newCoords.x, newCoords.y,moves)){
                        moves.push_back(newCoords);
                    }
                    break;
                }
                x++;
            }
        }
        if (xCoord-1 >= 0 && board[xCoord-1][yCoord] == opposite){
            int x = xCoord-2;
            while (x >= 0){
                if (board[x][yCoord] == color){
                    break;
                }
                if (board[x][yCoord] == 0){
                    moveCoords newCoords;
                    newCoords.x = x;
                    newCoords.y = yCoord;
                    if (!existsInPotential(newCoords.x, newCoords.y,moves)){
                        moves.push_back(newCoords);
                    }
                    break;
                }
                x--;
            }
            
        }
        if (yCoord+1 < SIZE && board[xCoord][yCoord+1] == opposite){
            int y = yCoord+2;
            while (y < SIZE){
                if (board[xCoord][y] == color){
                    break;
                }
                if (board[xCoord][y] == 0){
                    moveCoords newCoords;
                    newCoords.x = xCoord;
                    newCoords.y = y;
                    if (!existsInPotential(newCoords.x, newCoords.y,moves)){
                        moves.push_back(newCoords);
                    }
                    break;
                }
                y++;
            }
            
        }
        if ( yCoord-1 >= 0 && board[xCoord][yCoord-1] == opposite){
            int y = yCoord-2;
            while (y >= 0){
                if (board[xCoord][y] == color){
                    break;
                }
                if (board[xCoord][y] == 0){
                    moveCoords newCoords;
                    newCoords.x = xCoord;
                    newCoords.y = y;
                    if (!existsInPotential(newCoords.x, newCoords.y,moves)){
                        moves.push_back(newCoords);
                    }
                    break;
                }
                y--;
            }
        }
        if (xCoord+1 < SIZE && yCoord+1 < SIZE && board[xCoord+1][yCoord+1] == opposite){
            int x = xCoord + 2;
            int y = yCoord + 2;
            while(x < SIZE && y < SIZE){
                if (board[x][y] == color){
                    break;
                }
                if (board[x][y] == 0){
                    moveCoords newCoords;
                    newCoords.x = x;
                    newCoords.y = y;
                    if (!existsInPotential(newCoords.x, newCoords.y,moves)){
                        moves.push_back(newCoords);
                    }
                    break;
                }
                x++;
                y++;
            }
        }
        if (xCoord+1 < SIZE && yCoord-1 >= 0 && board[xCoord+1][yCoord-1] == opposite){
            int x = xCoord + 2;
            int y = yCoord - 2;
            while(x < SIZE && y >= 0){
                if (board[x][y] == color){
                    break;
                }
                if (board[x][y] == 0){
                    moveCoords newCoords;
                    newCoords.x = x;
                    newCoords.y = y;
                    if (!existsInPotential(newCoords.x, newCoords.y,moves)){
                        moves.push_back(newCoords);
                    }
                    break;
                }
                x++;
                y--;
            }
        }
        if (xCoord-1 >= 0 && yCoord-1 >= 0 && board[xCoord-1][yCoord-1] == opposite){
            int x = xCoord - 2;
            int y = yCoord - 2;
            while (x >= 0 && y >= 0){
                if (board[x][y] == color){
                    break;
                }
                if (board[x][y] == 0){
                    moveCoords newCoords;
                    newCoords.x = x;
                    newCoords.y = y;
                    if (!existsInPotential(newCoords.x, newCoords.y,moves)){
                        moves.push_back(newCoords);
                    }                        
                    break;
                }
                x--;
                y--;
            }
        }
        if (xCoord-1 >= 0 && yCoord+1 < SIZE && board[xCoord-1][yCoord+1] == opposite){
            int x = xCoord - 2;
            int y = yCoord + 2;
            while (x >= 0 && y < SIZE){
                if (board[x][y] == color){
                    break;
                }
                if (board[x][y] == 0){
                    moveCoords newCoords;
                    newCoords.x = x;
                    newCoords.y = y;
                    if (!existsInPotential(newCoords.x, newCoords.y,moves)){
                        moves.push_back(newCoords);                      
                    }  
                    break;
                }
                x--;
                y++;
            }
        }

    }
    // printPotentialMoves(moves);
    return moves;
}

bool Reversi::turnSkip(int color){
    vector <moveCoords> freeMoves = potentialMoves(color);
    if (freeMoves.size() == 0){
        return true;
    }
    return false;
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
    cout << endl;
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
    blackChips = counter1;
    whiteChips = counter2;
}

int Reversi::getWhiteChips(){
    return whiteChips;
}

int Reversi::getBlackChips(){
    return blackChips;
}

reversi_board& Reversi::getBoard() {
    return board;
}


bool Reversi::placePiece(int color, int x, int y){
    bool flag = false;
    int opposite;
    if (color == 1){
        opposite = 2;
    }
    else{
        opposite = 1;
    }
    vector<moveCoords> availableMoves = potentialMoves(color);
    for (int i = 0; i < availableMoves.size(); i++){
        if (availableMoves[i].x == x && availableMoves[i].y == y){
            flag = true;
        }
    }
    if (!flag){
        return false;
    }
    else{
        //messes up here cause I'm not backtracking ie, if the neighbor is an opposite color 
        //it will change it right away but we need to first check if its an opposite color
        //and then keep checking if the next pieces in that direction will ever be the current 
        //color... thennnn we can change the pieces in between.
        //but what im doing is im changing the pieces as I go when i search for the current color which is wrong.
        board[x][y] = color;
        vector<int> directions;
        
        if (x+1 < SIZE && board[x+1][y] == opposite){
            int i = 1;
            while (x+i < SIZE){
                if (board[x+i][y] == 0){
                    break;
                }
                if (board[x+i][y] == color){
                    directions.push_back(0);
                    break;
                }
                i++;
            }
        }
        if(x-1 >= 0 && board[x-1][y] == opposite){
            int i = 1;
            while (x-i >= 0){
                if (board[x-i][y] == 0){
                    break;
                }
                if (board[x-i][y] == color){
                    directions.push_back(1);
                    break;
                }
                i++;
                
            }
        }
        if(y+1 < SIZE && board[x][y+1] == opposite){
            int i = 1;
            while (y+i < SIZE){
                if (board[x][y+i] == 0){
                    break;
                }
                if (board[x][y+i] == color){
                    directions.push_back(2);
                    break;
                }
                i++;
            }
        }
        if (y-1 >= 0 && board[x][y-1]== opposite){
            int i = 1;
            while (y-i >= 0){
                if (board[x][y-i] == 0){
                    break;
                }
                if (board[x][y-i] == color){
                    directions.push_back(3);
                    break;
                }
                i++;
            }
        }
        if (x+1 < SIZE && y+1 < SIZE && board[x+1][y+1] == opposite){
           
            int i = 1;
            while (x+i < SIZE && y+i < SIZE){
                if (board[x+i][y+i] == 0){
                    break;
                }
                if (board[x+i][y+i] == color){
                    directions.push_back(4);
                    break;
                }
                i++;
                
            }
        }
        if (x-1 >= 0 && y+1 < SIZE && board[x-1][y+1] == opposite){
            
            int i = 1;
            while (x-i >= 0 && y+i < SIZE){
                if (board[x-i][y+i] == 0){
                    break;
                }
                if (board[x-i][y+i] == color){
                    directions.push_back(5);
                    break;
                }
                i++;
                
            }
        }
        if (x+1 < SIZE && y-1 >= 0 && board[x+1][y-1] == opposite){
           
            int i = 1;
            while (x+i < SIZE && y-i >= 0){
                if (board[x+i][y-i] == 0){
                    break;
                }
                if (board[x+i][y-i] == color){
                    directions.push_back(6);
                    break;
                }
                i++;
                
            }
        }
        if (x-1 >= 0 && y-1 >=0 && board[x-1][y-1] == opposite){
           
            int i = 1;
            
            while (x-i >= 0 && y-i >= 0){
                if (board[x-i][y-i] == 0){
                    break;
                }
                if (board[x-i][y-i] == color){
                    
                    directions.push_back(7);
                    break;
                }
                i++;
                
            }
        }

        for (unsigned int i = 0; i < directions.size(); i++){
            if (directions[i] == 0){
               
                int i = 1;
                while (x+i < SIZE){
                    if (board[x+i][y] == color){
                        break;
                    }
                    else{
                        board[x+i][y] = color;
                    }
                    i++;

                }
            }
            else if (directions[i] == 1){
                int i = 1;
                while (x-i >= 0){
                    if (board[x-i][y] == color){
                        break;
                    }
                    else{
                        board[x-i][y] = color;
                    }
                    i++;

                }
            }
            else if (directions[i] == 2){
                int i = 1;
                while (y+i < SIZE){
                    if (board[x][y+i] == color){
                        break;
                    }
                    else{
                        board[x][y+i] = color;
                    }
                    i++;
                }
            }
            else if (directions[i] == 3){
                int i = 1;
                while (y-i >= 0){
                    if (board[x][y-i] == color){
                        break;
                    }
                    else{
                        board[x][y-i] = color;
                    }
                    i++;
                }
            }
            else if (directions[i] == 4){
                int i = 1;
                while (x+i < SIZE && y+i < SIZE){
                    if (board[x+i][y+i] == color){
                        break;
                    }
                    else{
                        board[x+i][y+i] = color;
                    }
                    i++;
                }
            }
            else if (directions[i] == 5){
                int i = 1;
                while (x-i >= 0 && y+i < SIZE){
                    if (board[x-i][y+i] == color){
                        break;
                    }
                    else{
                        board[x-i][y+i] = color;
                    }
                    i++;
                }
            }
            else if (directions[i] == 6){
                int i = 1;
                while (x+i >= 0 && y-i < SIZE){
                    if (board[x+i][y-i] == color){
                        break;
                    }
                    else{
                        board[x+i][y-i] = color;
                    }
                    i++;
                }
            }
            else if (directions[i] == 7){
                int i = 1;
                while (x-i >= 0 && y-i >= 0){
                    if (board[x-i][y-i] == color){
                        break;
                    }
                    else{
                        board[x-i][y-i] = color;
                    }
                    i++;
                }
            }
        
        }
        
        return true;

    }

}

//checks if the board is filled
int Reversi::checkGameOver(){
    bool stop = true;
    checkGameState();
    
    
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            if (board[i][j] == 0){
                stop = false;
            }
        }
    }
    
    if (stop == true){
        if (blackChips > whiteChips){
            return 1;
        }
        else if (whiteChips > blackChips){
            return 2;
        }
        else{
            return 0;
        }
    }
    else{
        return -1;
    }
}