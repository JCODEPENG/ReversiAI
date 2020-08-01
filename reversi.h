#include <vector>

using namespace std;

typedef struct coords{
    int x;
    int y;
}moveCoords;

class Reversi{
    private:
        int board[8][8]; 
        int whiteChips;
        int blackChips;

    public:
        Reversi();
        vector<moveCoords> potentialMoves(int color, int direction);
        bool checkGameOver();
        void checkGameState();
        void printPotentialMoves(vector<moveCoords> moves);
        void printBoard();
        int getWhiteChips();
        int getBlackChips();
};