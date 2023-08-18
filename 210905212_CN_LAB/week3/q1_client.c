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
    struct sockaddr_in address;
    sd = socket(AF_INET, SOCK_DGRAM, 0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("172.16.48.95"); // Replace with your systems IP address
    address.sin_port = htons(9704);
    
    int buff[3][3];
    //printf("%d , %d",ROWS,COLS);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &buff[i][j]);
            //printf("%d , %d",i,j);
        }
    }

    int len = sizeof(address);

    // Send the rows of the matrix to the server
    for (int i = 0; i < 3; i++)
    {
        sendto(sd, buff[i], sizeof(int) * 3, 0, (struct sockaddr *)&address, len);
    }

    // Receive the combined matrix from the server
    int combinedMatrix[3][3];
    recvfrom(sd, combinedMatrix, sizeof(int) * 3* 3, 0, (struct sockaddr *)&address, &len);

    printf("The combined matrix is:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", combinedMatrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}