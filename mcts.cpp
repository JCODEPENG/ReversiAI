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

double MCTS::coin_parity_heuristic(Reversi game, int AI_color) {
    game.checkGameState();
    double coinParity = 0;

    if(AI_color == BLACK) {
        coinParity = 100 * ((game.getBlackChips() - game.getWhiteChips())/(game.getBlackChips() + game.getWhiteChips()));
    }
    else {
        coinParity = 100 * ((game.getWhiteChips() - game.getBlackChips())/(game.getBlackChips() + game.getWhiteChips()));
    }

    return ceil(coinParity * 100.0)/100.0;
}

double MCTS::mobility_heuristic(Reversi game, int AI_color) {
    int opponentColor;
    if(AI_color == BLACK) {
        opponentColor = WHITE;
    }
    else {
        opponentColor = BLACK;
    }
    int potentialMovesAI = game.potentialMoves(AI_color).size();
    int potentialMovesOpponent = game.potentialMoves(opponentColor).size();
    double mobility;
    if((game.checkGameOver() == -1) && (potentialMovesAI+potentialMovesOpponent != 0)) {
        mobility = 100 * ((potentialMovesAI - potentialMovesOpponent)/(potentialMovesAI + potentialMovesOpponent));
    }
    return ceil(mobility * 100.0)/100.0;
}

double MCTS::corner_capture_heuristic(Reversi game, int AI_color) {
    reversi_board& copyBoard = game.getBoard();
    int numOfBlackCorners = 0;
    int numOfWhiteCorners = 0;

    if(copyBoard[0][0] == BLACK) {
        numOfBlackCorners++;
    }
    else if(copyBoard[0][0] == WHITE) {
        numOfWhiteCorners++;
    }
    
    if(copyBoard[0][7] == BLACK) {
        numOfBlackCorners++;
    }
    else if(copyBoard[0][7] == WHITE) {
        numOfWhiteCorners++;
    }

    if(copyBoard[7][0] == BLACK) {
        numOfBlackCorners++;
    }
    else if(copyBoard[7][0] == WHITE) {
        numOfWhiteCorners++;
    }

    if(copyBoard[7][7] == BLACK) {
        numOfBlackCorners++;
    }
    else if(copyBoard[7][7] == WHITE) {
        numOfWhiteCorners++;
    }

    double cornerCount;
    if(numOfBlackCorners + numOfWhiteCorners != 0) {
        if(AI_color == BLACK) {
            cornerCount = 100 * ((numOfBlackCorners - numOfWhiteCorners)/(numOfBlackCorners + numOfWhiteCorners));
        }
        else {
            cornerCount = 100 * ((numOfWhiteCorners - numOfBlackCorners)/(numOfBlackCorners + numOfWhiteCorners));
        }
    }
    else {
        return 0;
    }

    return ceil(cornerCount*100.0)/100.0;
}

int MCTS::randomPlayouts(Reversi game, bool activateHeuristics) {

    int AI;
    if(game.getTurn() == BLACK) {
        AI = WHITE;
    }
    else {
        AI = BLACK;
    }

    queue<Reversi> playouts;
    playouts.push(game);

    int number_of_playouts = 0;
    int score = 0;
    while(!playouts.empty() && number_of_playouts < max_number_of_playouts) {
        Reversi currentGame = playouts.front();
        playouts.pop();
        number_of_playouts++; 

        for(int i = 0; i < currentGame.potentialMoves(currentGame.getTurn()).size(); i++) {
            Reversi copy_game(currentGame.getBoard(), currentGame.getWhiteChips(), currentGame.getBlackChips(), currentGame.getTurn());
            copy_game.placePiece(currentGame.potentialMoves(currentGame.getTurn())[i].x, currentGame.potentialMoves(currentGame.getTurn())[i].y);
            
            copy_game.switchTurn();
            copy_game.checkGameState();

            if(copy_game.checkGameOver() == AI) {
                score+=100;
            }
            if(copy_game.checkGameOver() == game.getTurn()) {
                score-=100;
            }
            if(copy_game.checkGameOver() == -1) {
                playouts.push(copy_game);
            }
        }
    }
    
    if(number_of_playouts >= max_number_of_playouts) {
        while(!playouts.empty()) {
            Reversi currentGame = playouts.front();
            playouts.pop();
            currentGame.checkGameState();

            if(!activateHeuristics) {
                if(AI == WHITE) {
                    if(currentGame.getBlackChips() < currentGame.getWhiteChips()) {
                        score+=50;
                    }
                    if(currentGame.getBlackChips() > currentGame.getWhiteChips()) {
                        score-=50;
                    }
                }
                else {
                    if(currentGame.getBlackChips() > currentGame.getWhiteChips()) {
                        score+=50;
                    }
                    if(currentGame.getBlackChips() < currentGame.getWhiteChips()) {
                        score-=50;
                    }
                }
            }
            else {
                score += round(coin_parity_heuristic(currentGame, AI) + mobility_heuristic(currentGame, AI) + corner_capture_heuristic(currentGame, AI));
            }
        }
    }

    return score;
    
}
 
moveCoords MCTS::doMove(Reversi game, bool activateHeuristics) {
    vector<int> scores;

    for(int i = 0; i < game.potentialMoves(game.getTurn()).size(); i++) {
        Reversi copy_game(game.getBoard(), game.getWhiteChips(), game.getBlackChips(), game.getTurn());
        copy_game.placePiece(game.potentialMoves(game.getTurn())[i].x, game.potentialMoves(game.getTurn())[i].y);
        copy_game.switchTurn();

        int score = randomPlayouts(copy_game, activateHeuristics);

        scores.push_back(score);
    }
    

    cout << "\n--------------------SCORES----------------------" << endl;
    for(int i = 0; i < scores.size(); i++) {
        cout << scores[i] << endl;
    }
    cout << endl;
    
    int max_index_for_move = maxIndex(scores);
         

    return game.potentialMoves(game.getTurn())[max_index_for_move];

}