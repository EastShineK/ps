#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 200000

int main(int argc, char *argv[]){
    int n, listenfd, connfd, caddrlen;
    struct hostent *h;
    struct sockaddr_in saddr, caddr;
    char buf[MAXLINE];
    int port=atoi(argv[1]);
    //printf("server working\n");
    

    if((listenfd=socket(AF_INET, SOCK_STREAM, 0))<0){
        printf("socket failed\n");
        exit(1);
    }
    memset((char*)&saddr, 0, sizeof(saddr));
    saddr.sin_family=AF_INET;
    saddr.sin_addr.s_addr=htonl(INADDR_ANY);
    saddr.sin_port=htons(port);
    if(bind(listenfd, (struct sockaddr *)&saddr, sizeof(saddr))<0){
        printf("bind() failed.\n");
        exit(2);
    }
    if (listen(listenfd, 5) < 0) {
        printf("listen() failed.\n");
        exit(3);
    }
    while (1) {
	int i = 1;
        caddrlen = sizeof(caddr);
        if ((connfd = accept(listenfd, (struct sockaddr *)&caddr,(socklen_t *)&caddrlen)) < 0) {
            //printf ("accept() failed.\n");
	    close(listenfd);
	    exit(0);
            continue;
        }
        // echo
        while ((n = read(connfd, buf, MAXLINE)) > 0) {
	    i = 0;
            printf ("got %d bytes from client.\n", n);
            write(connfd, buf, n);
        }
	//if(i == 1) close(listenfd);
        //printf("connection terminated.\n");
        close(connfd);
	//printf("%d\n", n);
	if(i == 1) close(listenfd);
    }
    //printf("befor close\n");
    close(listenfd);
    //return 0;
}
