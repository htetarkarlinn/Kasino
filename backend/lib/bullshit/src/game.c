// src/game.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"

void initializeGame(Game *game, int numPlayers) {
    game->currentTurn = 0;
    game->deckIndex = 0;
    // Initialize players with no cards initially
    for (int i = 0; i < numPlayers; i++) {
        game->players[i].id = i + 1;
        game->players[i].cardCount = 0;
    }
}

void shuffleDeck(Card *deck) {
    srand(time(0));
    for (int i = 0; i < MAX_CARDS; i++) {
        int j = rand() % MAX_CARDS;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void dealCards(Game *game, int numCardsPerPlayer) {
    int cardPos = 0;
    for (int i = 0; i < MAX_PLAYERS; i++) {
        for (int j = 0; j < numCardsPerPlayer; j++) {
            game->players[i].hand[j] = game->deck[cardPos++];
            game->players[i].cardCount++;
        }
    }
}
