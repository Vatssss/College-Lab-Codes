#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_DATA_SIZE 1024
#define PORT 12345

void die(const char *s)
{
    perror(s);
    exit(1);
}

int main()
{
    int sock;
    struct sockaddr_in server;
    socklen_t server_len = sizeof(server);

    // Create socket
    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
    {
        die(&quot; socket & quot;);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = INADDR_ANY;

    char buffer[MAX_DATA_SIZE];

    int sequence = 0;

    while (1)
    {
        // Send data
        printf(&quot; Sending packet with sequence number
               : % d\n & quot;
               , sequence);
        sprintf(buffer, &quot; Packet % d & quot;, sequence);
        if (sendto(sock, buffer, strlen(buffer), 0, (struct sockaddr *)&amp; server, server_len) == -1)
        {
            die(&quot; sendto() & quot;);
        }

        // Wait for acknowledgment
        if (recvfrom(sock, buffer, MAX_DATA_SIZE, 0, (struct sockaddr *)&amp; server, &amp; server_len) == -1)
        {
            die(&quot; recvfrom() & quot;);
        }
printf(&quot;Received acknowledgment for packet with sequence number: %d\n&quot;, sequence);

// Toggle sequence number
sequence = 1 - sequence;

// Sleep for a while to simulate real-world delay
sleep(1);
    }

    close(sock);
    return 0;
}