#include <stdio.h>
#include <czmq.h>

int main()
{
    // Step 1: Create a ZMQ_REP (reply) socket
    zsock_t *server = zsock_new_rep("tcp://*:5555");
    if (!server)
    {
        printf("Failed to create server socket.\n");
        return -1;
    }

    printf("Server is running and bound to tcp://*:5555...\n");

    while (true)
    {
        char *request = zstr_recv(server);
        if (request)
        {
            printf("Received request: %s\n", request);
            zstr_send(server, "Hello, client!");
            zstr_free(&request);
        }
        free(request);
    }

    zsock_destroy(&server);

    return 0;
}