/**
 * @file testGame.cpp
 * @brief Test of game component
 * @author Corentin L. / Seweryn C.
 * @version 1.0
 */

#include "Game.h"

int main() {
    assert(verifyPlayerInput("WRONGINPUT")==charError);
    assert(verifyPlayerInput("HHRR")==noError);
    assert(verifyPlayerInput("H")==lengthError);
    Game testGame{};
    initGame("HHRR",testGame);
    assert(!loserExists(testGame));
    char test[3]="AB";
    testGame.currentWord=test;
    assert(wordInputVerification(testGame,"ABAAAAA")==doesNotExist);
    assert(wordInputVerification(testGame,"ABACAS")==exists);
    assert(wordInputVerification(testGame,"HAHAHAH")==wrongStart);
    addQuarterToPlayer(read(testGame.playerList,testGame.playerList.currentPlayerID));
    addQuarterToPlayer(read(testGame.playerList,testGame.playerList.currentPlayerID));
    addQuarterToPlayer(read(testGame.playerList,testGame.playerList.currentPlayerID));
    assert(!loserExists(testGame));
    addQuarterToPlayer(read(testGame.playerList,testGame.playerList.currentPlayerID));
    assert(loserExists(testGame));
    endGame(testGame);
}