#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

#define MAXLINE 4096

int main(int argc, char** argv)
{
    int    listenfd, connfd;
    struct sockaddr_in     servaddr;
    char    buff[4096];
    int     n;

    if( (listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1 ){
    	printf("create socket error: %s(errno: %d)\n",strerror(errno),errno);
   	exit(0);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(6666);

    if( bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1){
    	printf("bind socket error: %s(errno: %d)\n",strerror(errno),errno);
    	exit(0);
    }

    if( listen(listenfd, 10) == -1){
    	printf("listen socket error: %s(errno: %d)\n",strerror(errno),errno);
    	exit(0);
    }

    printf("======waiting for client's request======\n");
   
    struct sockaddr_in client_addr;
    memset(&client_addr,0,sizeof(client_addr));
    size_t size=sizeof(client_addr);
    while(1){
	//the third parameter type is socklen_t*,unsigned int
    	if( (connfd = accept(listenfd, (struct sockaddr*)&client_addr, (unsigned int *)&size)) == -1){
        	printf("accept socket error: %s(errno: %d)",strerror(errno),errno);
        	continue;
    	}	
    	printf("client's IP:%s\nclient's port:%d\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));

    	n = recv(connfd, buff, MAXLINE, 0);
    	buff[n] = '\0';
    	printf("recv msg from client: %s\n", buff);
    	close(connfd);
    }

    close(listenfd);
}
