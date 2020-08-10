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

int MCTS::randomPlayouts(Reversi game) {

    queue<Reversi> playouts;
    playouts.push(game);

    int number_of_playouts = 0;
    int score = 0;
    while(!playouts.empty() && number_of_playouts < max_number_of_playouts) {
        Reversi currentGame = playouts.front();
        playouts.pop();

        cout << "THIS IS THE EXPLORING BOARD" << endl;
        currentGame.printBoard();
        number_of_playouts++;

        for(int i = 0; i < currentGame.potentialMoves(currentGame.getTurn()).size(); i++) {
            Reversi copy_game(currentGame.getBoard(), currentGame.getWhiteChips(), currentGame.getBlackChips());
            copy_game.placePiece(currentGame.potentialMoves(currentGame.getTurn())[i].x, currentGame.potentialMoves(currentGame.getTurn())[i].y);
            copy_game.switchTurn();

            if(copy_game.checkGameOver() == WHITE) {
                score++;
            }
            if(copy_game.checkGameOver() == BLACK) {
                score--;
            }
            if(copy_game.checkGameOver() == -1) {
                playouts.push(copy_game);
                 
            }
        }

        
    }

    if(number_of_playouts > max_number_of_playouts) {
        while(!playouts.empty()) {
            Reversi currentGame = playouts.front();
            playouts.pop();
            cout << "THIS IS THE D" << endl;
            currentGame.printBoard();
            currentGame.checkGameState();
            if(currentGame.getBlackChips() < currentGame.getWhiteChips()) {
                score++;
            }
            if(currentGame.getBlackChips() > currentGame.getWhiteChips()) {
                score--;
            }

        }
    }

    return score;
    
}

 
void MCTS::doMove(Reversi game) {
    vector<int> scores;

    for(int i = 0; i < 1; i++) {
        Reversi copy_game(game.getBoard(), game.getWhiteChips(), game.getBlackChips());
        copy_game.placePiece(game.potentialMoves(game.getTurn())[i].x, game.potentialMoves(game.getTurn())[i].y);
        copy_game.switchTurn();
        // copy_game.printBoard();

        int score = randomPlayouts(copy_game);

        scores.push_back(score);
    }
    

    cout << "\n--------------------SCORES----------------------" << endl;
    for(int i = 0; i < scores.size(); i++) {
        cout << scores[i] << endl;
    }
        
    int max_index_for_move = maxIndex(scores);
        
    game.placePiece(game.potentialMoves(game.getTurn())[max_index_for_move].x, game.potentialMoves(game.getTurn())[max_index_for_move].y);

    game.printBoard();

}