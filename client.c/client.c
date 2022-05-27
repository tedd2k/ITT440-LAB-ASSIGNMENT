#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char **argv){
  if(argc != 2){
    printf("Usage: %s <port>\n", argv[0]);
    exit(0);
  }

  int port = atoi(argv[1]);
  printf("Port: %d\n", port);

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  char response[30];
  struct sockaddr_in server;
  server.sin_family = AF_INET;
  //server.sin_addr.s_addr = inet_addr("192.168.90.6");
  server.sin_port = htons(13);

  connect(sockfd, (struct sockaddr*)&server, sizeof(server));
  printf("[+]Connected to the server\n");

  recv(sockfd, response, 29, 0);
  printf("Time from server: %s", response);

  return 0;

}