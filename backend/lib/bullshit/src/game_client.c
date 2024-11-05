#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h> // Include this for socket programming functions and types
#include "game.h"

#define PORT 8080

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;

    // Create a socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    // Define the server address structure
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/Address not supported \n");
        return -1;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        return -1;
    }

    printf("Connected to the server!\n");
    close(sock); // Close the socket
    return 0;
}

void send_message(int sock, MessageType type, const char *content) {
    GameMessage message;
    message.type = type; // Set the type of message (e.g., play card, call bullshit)
    snprintf(message.content, sizeof(message.content), "%s", content); // Set the content
    send(sock, &message, sizeof(GameMessage), 0); // Send the message to the server
}
void send_play_card(int sock, Card card) {
    char buffer[50]; // Buffer to hold the card details (rank and suit)
    snprintf(buffer, sizeof(buffer), "%s %s", card.rank, card.suit); // Format the card details
    send_message(sock, MSG_PLAY_CARD, buffer); // Send the play card message
}
void send_call_bullshit(int sock) {
    send_message(sock, MSG_CALL_BULLSHIT, ""); // Send the call bullshit message with empty content
}
