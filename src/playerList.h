#ifndef LIST_H
#define LIST_H

/**
 * @file playerList.h
 * @brief Defining playerList type used in the project for the list of players
 * @author Corentin L. / Seweryn C.
 * @version 1.0
 */

#include "Player.h"

// Item type
typedef Player Item;

/**
 * @brief PlayerList data structure to represents the list of the players for the game
 */
struct playerList {
    uint nbElements; // Number of elements of list
    Item *tab; // Tab of Item elements
    uint currentPlayerID; // ID of current player
};

/**
 * @brief Initializes a list of capacity Item elements
 * @param [in] capacity List capacity
 * @param [out] list To initialize
 * @see destroy
 */
void initialize(playerList &list, uint capacity);

/**
 * @brief Deallocate the list of items
 * @param [in] list To destroy
 * @pre list.nbElements > 0
 * @see initialize
 */
void destroy(playerList &list);

/**
 * @brief Inserts an item into the end of the list
 * @param [in,out] list List to insert into
 * @param [in] item To insert
 * @param [in] i Position of inserted item
 * @pre i < list.nbElements
 */
void insert(playerList &list, const Item &item, uint i);

/**
 * @brief Reads an Item from the list
 * @param [in] list List to read from
 * @param [in] i Index to read
 * @return Reference to Item
 * @pre i < list.nbElements
 */
Item &read(const playerList &list, uint i);

/**
 * @brief Changes current player to the next one by changing currentPID
 * @param [in,out] list The list where the change has to be done
 * @pre list.nbElements > 0
 * @see previous
 */
void next(playerList &list);

/**
 * @brief Changes current player to the previous one by changing currentPID
 * @param [in,out] list The list where the change has to be done
 * @pre list.nbElements > 0
 * @see next
 */
void previous(playerList &list);

#endif // LIST_H