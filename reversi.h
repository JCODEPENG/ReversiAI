#include <vector>

using namespace std;

typedef struct coords{
    int x;
    int y;
}moveCoords;

class Reversi{
    private:
        int board[8][8]; 

    public:
        Reversi();
        vector<moveCoords> potentialMoves();
        void printPotentialMoves(vector<moveCoords> moves);
        void printBoard();
};