#include <stdio.h>
#include <czmq.h>

int main(int narg, const char *args[])
{
    if (narg < 2)
    {
        printf("Require at least 1 arguments");
        return -1;
    }

    zsock_t *client = zsock_new_req("tcp://localhost:5555");
    if (!client)
    {
        printf("Failed to create client socket.\n");
        return -1;
    }

    const char *message = args[1];
    zstr_send(client, message);

    char *reply = zstr_recv(client);
    if (reply)
    {
        printf("Received reply: %s\n", reply);
        zstr_free(&reply); // Free the allocated memory for the reply
    }
    else
    {
        printf("Failed to receive a reply from the server.\n");
    }

    // Step 4: Clean up and close the socket
    zsock_destroy(&client);

    return 0;
}