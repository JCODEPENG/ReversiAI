#include <vector>

using namespace std;

typedef struct coords{
    int x;
    int y;
}moveCoords;

class Reversi{
    private:
        int board[8][8]; 
        int size;

    public:
        Reversi();
        vector<int>* potentialMoves();
        void printBoard();
};