// src/main.c
#include <stdio.h>
#include "game.h"

int main() {
    Game game;
    initializeGame(&game, MAX_PLAYERS);
    shuffleDeck(game.deck);
    dealCards(&game, 5); // Deal 5 cards to each player

    // Print out each player's hand for verification
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("Player %d's hand:\n", game.players[i].id);
        for (int j = 0; j < game.players[i].cardCount; j++) {
            printf("Card %d: Rank %d, Suit %c\n", j + 1, game.players[i].hand[j].rank, game.players[i].hand[j].suit);
        }
    }
    return 0;
}
