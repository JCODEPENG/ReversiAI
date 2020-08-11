#include <queue>
#include <cmath>
#include <time.h>
#include "reversi.h"

using namespace std;

class MCTS {
    private:
        int max_number_of_playouts;
        int randomPlayouts(Reversi game, bool activateHeuristics);
        double coin_parity_heuristic(Reversi game, int AI_color);
        double mobility_heuristic(Reversi game, int AI_color);
        double corner_capture_heuristic(Reversi game, int AI_color);
    public:
        MCTS(int max_number_of_playouts = 100000);
        moveCoords doMove(Reversi game, bool activateHeuristics);
};