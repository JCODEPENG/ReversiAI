using namespace std;

#include "reversi.h"

class MCTS {
    private:
        int max_number_of_playouts;
        int randomPlayouts(Reversi game, int turn, int totalScore);
    public:
        MCTS(int number_of_random_playouts = 100000);
        void doMove(Reversi game);
        int get_max_number_of_playouts();
};