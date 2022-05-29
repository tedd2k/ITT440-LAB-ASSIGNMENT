#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <time.h>
#include <arpa/inet.h>


#define PORT 17

 int main(int argc, char *argv[])
{
	int sockfd,newSocket, message,c;
	struct sockaddr_in serverAddr;
	char reply[30];

	char buffer[1024] = { 0 };
	char clMsg[sizeof(buffer)];

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd == -1)
	{
		printf("Unable to create socket. Try again");
	}

	serverAddr.sin_family=AF_INET;
	serverAddr.sin_port=htons(13);
	serverAddr.sin_addr.s_addr=inet_addr("192.168.90.6");

	if(connect(sockfd,(struct sockaddr *)&serverAddr, sizeof(serverAddr))<0)
	{
		puts("Connection Error");
		return 1;
	}
	puts("Connection with server is success! \n");

	recv(sockfd, reply, 29, 0);
	printf("Time received from server = %s", reply);

	  
	close(sockfd);

	return 0;

}