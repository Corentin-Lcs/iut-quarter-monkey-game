/**
 * @file main.cpp
 * @brief Main file of the program
 * @author Corentin L. / Seweryn C.
 * @version 1.0
 */

#include <ctime>
#include "Game.h"

int main(int argc, char *argv[]) {
    srand(time(NULL));
    // We need 2 arguments for : executable call and input of players
    if (argc == 2) {
        inputErrorType error = verifyPlayerInput(argv[1]);
        if (error > 0) {
            displayPlayersInputError(error);
        }
        else {
            Game game{};
            initGame(argv[1], game);
            playGame(game);
        }
    }
    else {
        displayCommandError(argc);
    }
}