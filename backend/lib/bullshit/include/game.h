// include/game.h
#ifndef GAME_H
#define GAME_H

#include "player.h"
#define MAX_PLAYERS 4  // Adjust as needed

// Message types for communication
typedef enum {
    MSG_PLAY_CARD,
    MSG_CALL_BULLSHIT,
    MSG_GAME_UPDATE,
    MSG_INVALID // For handling invalid or unknown messages
} MessageType;

// Message structure for sending/receiving data
typedef struct {
    MessageType type;  // Type of the message (e.g., play card, call bullshit)
    char content[256]; // Content of the message (e.g., card details or actions)
} GameMessage;


typedef struct {
    Card deck[MAX_CARDS]; // Main deck of cards
    Player players[MAX_PLAYERS]; // Array of players
    int currentTurn; // Tracks whose turn it is
    int deckIndex;   // Tracks where in the deck we are
} Game;

// Function prototypes for game logic
void initializeGame(Game *game, int numPlayers);
void shuffleDeck(Card *deck);
void dealCards(Game *game, int numCardsPerPlayer);

// Function prototypes for game flow and messaging
void process_message(Game *game, int player_index, GameMessage *message);
void update_game_flow(Game *game);
void send_message(int sock, MessageType type, const char *content);

#endif // GAME_H
