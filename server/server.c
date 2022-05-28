#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#define BACKLOG 10
#define PORT 13

int main(int argc, char *argv[] )
{
	int sockfd,newSocket,c,message, n_client = 0;
	struct sockaddr_in serverAddr, client;
	char buffer[1024] = { 0 };
	char svReply[sizeof(buffer)];

    sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd == -1)
    {
		
		printf("\nFailed to create socket!");

    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(13);

    if(bind(sockfd,(struct sockaddr *)&serverAddr, sizeof(serverAddr))<0)
    {

		puts("\nbind failed");
		return 1;
    }
    puts("\nSocket is successfully binded! ");

    listen (sockfd,3);
    puts("\nWaiting for incoming connections....");
    c=sizeof(struct sockaddr_in);

    newSocket = accept(sockfd,(struct sockaddr *)&client,(socklen_t*)&c);
    if(newSocket<0)
    {
		perror("\nFAILED TO ACCEPT");
		return 1;
    }
    puts("Connection accepted!");

	{
    
    n_client++;
    time_t currentTime;
    time(&currentTime);

    printf("Sending client the current time = %s ", ctime(&currentTime));
    send(newSocket, ctime(&currentTime), 30, 0);
	}

  
    close(newSocket);

return 0;
}
