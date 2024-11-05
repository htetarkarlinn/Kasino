// src/game_server.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include "game.h"

#define PORT 8080
#define MAX_PLAYERS 4

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("Setsockopt SO_REUSEADDR failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Define address for the socket
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(server_fd, MAX_PLAYERS) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    printf("Server started! Waiting for players to connect...\n");

    // Accept incoming connections
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            close(server_fd);
            exit(EXIT_FAILURE);
        }
        printf("Player %d connected!\n", i + 1);

        // Send a welcome message to the client
        char *welcome = "Welcome to the Bullshit Game!";
        send(new_socket, welcome, strlen(welcome), 0);
    }

    close(server_fd);
    return 0;
}

void process_message(Game *game, int player_index, GameMessage *message) {
    switch (message->type) {
        case MSG_PLAY_CARD:
            // Extract the card information from the message
            Card card;
            sscanf(message->content, "%s %s", card.rank, card.suit); // Assuming content has the rank and suit
            play_card(game, player_index, card); // Handle the card play (you may need to implement play_card())
            break;

        case MSG_CALL_BULLSHIT:
            // Handle the call bullshit action
            call_bullshit(game, player_index); // Implement this function to handle the call bullshit logic
            break;

        case MSG_GAME_UPDATE:
            // Handle game state updates if needed (optional, can be used for sending game status)
            break;

        case MSG_INVALID:
        default:
            printf("Received an invalid message from player %d\n", player_index);
            break;
    }

    update_game_flow(game); // After processing the message, update the game flow (next turn, etc.)
}
void update_game_flow(Game *game) {
    // Switch to the next player's turn
    game->currentTurn = (game->currentTurn + 1) % MAX_PLAYERS; // Assuming MAX_PLAYERS is defined
    printf("It's now player %d's turn.\n", game->currentTurn);
}
