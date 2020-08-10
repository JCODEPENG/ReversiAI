#include <queue>
#include "reversi.h"

using namespace std;

class MCTS {
    private:
        int max_number_of_playouts;
        int randomPlayouts(Reversi game);
    public:
        MCTS(int max_number_of_playouts = 100000);
        void doMove(Reversi game);
};