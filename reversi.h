#include <vector>
#include <iostream>

#define SIZE    8
#define BLACK   1
#define WHITE   2

using namespace std;

typedef struct coords{
    int x;
    int y;
}moveCoords;

typedef int reversi_board[8][8];

class Reversi{
    private:
        int board[8][8];
        int whiteChips;
        int blackChips;
        int turn;
    public:
        Reversi();
        Reversi(reversi_board& board, int whiteChips, int blackChips, int turn);
        vector<moveCoords> potentialMoves(int color);
        bool placePiece(int x, int y);
        int checkGameOver();
        void checkGameState();
        void printPotentialMoves(vector<moveCoords> moves);
        void printBoard();
        bool turnSkip(int color);
        int getWhiteChips();
        int getBlackChips();
        reversi_board& getBoard();
        int getTurn();
        void switchTurn();
};