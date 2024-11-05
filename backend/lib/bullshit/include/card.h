// include/card.h
#ifndef CARD_H
#define CARD_H

typedef struct {
    int rank;  // e.g., 1 for Ace, 11 for Jack, etc.
    char suit; // e.g., 'H' for hearts, 'D' for diamonds, 'S' for spades, 'C' for clubs
} Card;

#endif // CARD_H
