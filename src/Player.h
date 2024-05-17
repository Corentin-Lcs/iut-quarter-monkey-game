#ifndef PLAYER_H
#define PLAYER_H

/**
 * @file Player.h
 * @brief Player type and functions centered around the gameplay specific to the player
 * @author Corentin L. / Seweryn C.
 * @version 1.0
 */

#include <limits>
#include "Dictionary.h"

enum playerType {
    R = 0, H = 1
}; // A player can be either human or AI

enum {
    ASK_SYMBOL = 26, // ID of '?' symbol used to ask the previous player for the word he was thinking of
    NB_LETTERS_ALPHABET = 26, // Number of letters in an alphabet
};

/**
 * @brief Data structure of Player type, to represent a player in the game
 */
struct Player {
    uint playerID; // Player identifier
    playerType type; // Player type (R = Robot, H = Human)
    signed char nQuart; // Number of quarters
};

/**
 * @brief Initializes a new player
 * @param [in] pID ID of the added player
 * @param [in] type Player type of the added player
 * @param [out] player Player to be initialized
 * @return Initialized Player
 */
void initPlayer(uint pID, playerType type, Player &player);

/**
 * Adds a quarter to a player
 * @param [in,out] player That gets the quarter
 * @pre player.nQuart < 4
 */
void addQuarterToPlayer(Player &player);

/* --- AI FUNCTIONS --- */

/**
 * @brief Gets the character with the highest efficiency
 * @param [in] array Array with efficiencies
 * @return ID of character of highest efficiency or random choice if there aren't any efficient characters
 * @pre Array must be of size NB_LETTERS_ALPHABET
 */
uint maxEfficiency(const letterEfficiency *array);

/**
 * @brief Picks the best letter or sign to input for the AI
 * @param [in] dict Game dictionary
 * @param [in] currentWord Current word of the game turn
 * @param [in] playerNumber Number of players
 * @return Letter picked by the AI
 * @see getLetterEfficiency
 */
char pickCharR(Dictionary &dict, const char *currentWord, uint playerNumber);

/**
 * @brief Picks a word based on the current letters
 * @param [in] dict Game dictionary
 * @param [in] currentWord Current word of the turn
 * @param [out] inputWord Word picked by the AI
 */
void pickWordR(Dictionary &dict, const char *currentWord, char *&inputWord);

/**
 * @brief Randomly chooses the last action of the AI player if it has to finish a word
 * @param [in] lastLetterID ID of last letter to enter to finish the word
 * @return ID of chosen char
 * @pre lastLetterID must be between 0 and NB_LETTERS_ALPHABET
 */
unsigned char lastResortR(unsigned char lastLetterID);

/* --- INPUT FUNCTIONS --- */

/**
 * @brief Player letter input management
 * @return Inputted char
 */
char inputCharH();

/**
 * @brief Player word input management
 * @param [out] word Reference to input word
 */
void inputWordH(char *&word);

/* --- DISPLAY FUNCTIONS --- */

/**
 * @brief Displays the ID and the type of the player
 * @param [in] player Player to display information of
 */
void displayPlayerIDAndType(const Player &player);

/**
 * @brief Displays the character picked by the AI
 * @param [in] character The picked character
 */
void displayPickedChar(char character);

/**
 * @brief Displays the word picked by the AI
 * @param [in] word The picked word
 */
void displayPickedWord(const char *word);

#endif // PLAYER_H