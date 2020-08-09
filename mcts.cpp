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
    this->number_of_playouts = 0;
}

int MCTS::randomPlayouts(Reversi game, int turn, int totalScore) {
    number_of_playouts++;
    
    if(game.checkGameOver() >= 0) {
        if (game.checkGameOver() == BLACK) {
            cout << "returned (-1)" << endl;
            return totalScore-=1;
        }
        else if (game.checkGameOver() == WHITE) {
            cout << "returned (+1)" << endl;
            return totalScore+=1;
        }
        else {
            cout << "returned (0)" << endl;
            return totalScore;
        }
    }

    if(number_of_playouts > max_number_of_playouts) {
        game.checkGameState();
        if(game.getBlackChips() > game.getWhiteChips()) {
            return totalScore-=1;
        }
        else if(game.getBlackChips() < game.getWhiteChips()) {
            return totalScore+=1;
        }
        else {
            return totalScore;
        }
    }

    if(game.potentialMoves(turn).size() == 0) {
        if(turn == WHITE) {
            // cout << "skip white" << endl;
            totalScore = randomPlayouts(game, BLACK, totalScore);
        }
        else {
            // cout << "skip black" << endl;
            totalScore = randomPlayouts(game, WHITE, totalScore);
        }
    }
    else {
        for(unsigned int i = 0; i < game.potentialMoves(turn).size(); i++) {
            Reversi copy_game(game.getBoard(), game.getWhiteChips(), game.getBlackChips());
            copy_game.placePiece(turn, game.potentialMoves(turn)[i].x, game.potentialMoves(turn)[i].y);
            copy_game.printBoard();

            if(turn == WHITE) {
                cout << "recusive call to black's turn" << endl;
                totalScore = randomPlayouts(copy_game, BLACK, totalScore);
            }
            else {
                cout << "recusive call to white's turn" << endl;
                totalScore = randomPlayouts(copy_game, WHITE, totalScore);
            }
        }   
    }
    cout << "finished all potential moves so return" << endl;
    return totalScore;
}

 
void MCTS::doMove(Reversi game) {
    vector<int> scores;

    cout << max_number_of_playouts << endl;
    for(int i = 0; i < game.potentialMoves(WHITE).size(); i++){
        number_of_playouts = 0;

        Reversi copy_game(game.getBoard(), game.getWhiteChips(), game.getBlackChips());

        copy_game.placePiece(WHITE, game.potentialMoves(WHITE)[i].x, game.potentialMoves(WHITE)[i].y);
        copy_game.printBoard();
    
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