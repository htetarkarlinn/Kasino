// include/player.h
#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"

#define MAX_CARDS 52  // Max cards in a deck; adjust for your needs

typedef struct {
    int id;               // Player ID
    Card hand[MAX_CARDS]; // Array to hold the player's cards
    int cardCount;        // Number of cards in player's hand
} Player;

#endif // PLAYER_H
