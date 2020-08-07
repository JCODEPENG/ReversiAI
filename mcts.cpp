#include "mcts.h"

int maxIndex(vector<int> scores){
    int maxScore = scores[0];
    int index = 0;
    for (int i = 0; i < scores.size(); i++){
        if (scores[i] > maxScore){
            maxScore = scores[i];
            index = i;
        }
    }
    return index;
}

MCTS::MCTS(int max_number_of_playouts) {
    this->max_number_of_playouts = max_number_of_playouts;
}

int MCTS::get_max_number_of_playouts() {
    return this->max_number_of_playouts;
}

int MCTS::randomPlayouts(Reversi game, int turn, int totalScore) {
    
    if(game.checkGameOver() >= 0) {
        if (game.checkGameOver() == BLACK) {
            return totalScore-=1; 
        }
        else if (game.checkGameOver() == WHITE) {
            return totalScore+=1;
        }
        else {
            return totalScore;
        }
    }

    if(game.potentialMoves(turn).size() == 0) {
        if(turn == WHITE) {
            totalScore = randomPlayouts(game, BLACK, totalScore);
        }
        else {
            totalScore = randomPlayouts(game, WHITE, totalScore);
        }
    }
    else {
        for(unsigned int i = 0; i < game.potentialMoves(turn).size(); i++) {
            Reversi copy_game(game.getBoard(), game.getWhiteChips(), game.getBlackChips());
            copy_game.placePiece(turn, game.potentialMoves(turn)[i].x, game.potentialMoves(turn)[i].y);
            if(turn == WHITE) {
                totalScore = randomPlayouts(copy_game, BLACK, totalScore);
            }
            else {
                totalScore = randomPlayouts(copy_game, WHITE, totalScore);
            }
        }   
    }
    return totalScore;
}

 
void MCTS::doMove(Reversi game) {
    vector<int> scores;

    for(int i = 0; i < 1; i++){
        printf("move %d\n", i);

        Reversi copy_game(game.getBoard(), game.getWhiteChips(), game.getBlackChips());

        copy_game.placePiece(WHITE, game.potentialMoves(WHITE)[i].x, game.potentialMoves(WHITE)[i].y);
        
    
        int score = randomPlayouts(copy_game, BLACK, 0);


        scores.push_back(score);

    }

    cout << "\n--------------------SCORES----------------------" << endl;
    for(int i = 0; i < scores.size(); i++) {
        cout << scores[i] << endl;
    }
        
    int max_index_for_move = maxIndex(scores);
        
    game.placePiece(WHITE, game.potentialMoves(WHITE)[max_index_for_move].x, game.potentialMoves(WHITE)[max_index_for_move].y);

    game.printBoard();

}