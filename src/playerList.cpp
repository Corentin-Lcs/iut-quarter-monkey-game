/**
 * @file playerList.cpp
 * @brief Implementation of playerList type functions
 * @author Corentin L. / Seweryn C.
 * @version 1.0
 */

#include "playerList.h"

void initialize(playerList &list, uint capacity) {
    list.nbElements = capacity;
    list.tab = new Item[capacity];
    list.currentPlayerID = 0;
}

void destroy(playerList &list) {
    assert(list.nbElements > 0);
    delete[] list.tab;
    list.tab = NULL;
}

void insert(playerList &list, const Item &item, uint i) {
    assert(i < list.nbElements);
    list.tab[i] = item;
}

Item &read(const playerList &list, uint i) {
    assert(i < list.nbElements);
    return list.tab[i];
}

void next(playerList &list) {
    assert(list.nbElements != 0);
    // If the current player is the last one, then the next one is the first one
    if (list.currentPlayerID == list.nbElements - 1) {
        list.currentPlayerID = 0;
    } else {
        list.currentPlayerID++;
    }
}

void previous(playerList &list) {
    assert(list.nbElements != 0);
    // If the current player is the first one, then the next one is the last one
    if (list.currentPlayerID == 0) {
        list.currentPlayerID = list.nbElements - 1;
    } else {
        list.currentPlayerID--;
    }
}