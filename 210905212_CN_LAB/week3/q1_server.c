#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

//#define ROWS 3
//#define COLS 3

int main()
{
    int sd;
    char buf[25];
    struct sockaddr_in sadd, cadd;

    // Create a UDP socket
    sd = socket(AF_INET, SOCK_DGRAM, 0);

    // Construct the address for use with sendto/recvfrom...
    sadd.sin_family = AF_INET;
    sadd.sin_addr.s_addr = inet_addr("172.16.48.95"); // Replace with your systems IP address
    sadd.sin_port = htons(9704);

    int result = bind(sd, (struct sockaddr *)&sadd, sizeof(sadd));
    int len = sizeof(cadd);

    // Receive the rows of the matrix from the client
    int matrix[3][3];
    for (int i = 0; i < 3; i++)
    {
        recvfrom(sd, matrix[i], sizeof(int) * 3, 0, (struct sockaddr *)&cadd, &len);
    }

    // Combine the rows to form a matrix
    int combinedMatrix[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            combinedMatrix[i][j] = matrix[i][j];
        }
    }

    printf("The combined matrix is:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", combinedMatrix[i][j]);
        }
        printf("\n");
    }
    // Send the combined matrix back to the client
    sendto(sd, combinedMatrix, sizeof(int) * 3 * 3, 0, (struct sockaddr *)&cadd, len);

    return 0;
}