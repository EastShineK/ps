#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAXLINE 200000

int main(int argc, char *argv[]){
    int n, cfd;
    struct hostent *h;
    struct sockaddr_in saddr;
    char buf[MAXLINE];
    char *host =argv[1];
    int port=atoi(argv[2]);

    char filename[55];
    char filename2[60];
    int k = 0;
    while(1){
	if(k == 0) scanf("%s", filename);
	//printf("FILE NAME : %s\n", filename);
	sprintf(filename2, "%s_copy", filename);
    	if(strcmp(filename, "quit") == 0) k = 1/*exit(0)*/;
	else if(k != 1) printf("FILE NAME : %s\n", filename);
	int fd, fd2;
	fd=open(filename, O_RDONLY | O_APPEND);
    	fd2=open(filename2, O_WRONLY | O_CREAT | O_APPEND, 0755);

    
    	if((cfd=socket(AF_INET, SOCK_STREAM, 0))<0){
        	printf("socket failed\n");
        	exit(1);
    	}
    	if((h=gethostbyname(host))== 0){
        	//printf("invalid hostname\n");
        	exit(2);
    	}
    	memset((char*)&saddr, 0, sizeof(saddr));
    	saddr.sin_family=AF_INET;
    	memcpy((char*)&saddr.sin_addr, (char*)h->h_addr_list[0], h->h_length);//h_addr??
    	saddr.sin_port=htons(port);
	
	if(connect(cfd,(struct sockaddr *)&saddr,sizeof(saddr)) < 0){
		//printf("connect() failed.\n");
		exit(3);
	}
	//printf("befor read ok\n");
    	while((n=read(fd, buf, MAXLINE))>0){
		//printf("Send %d bytes to server.\n", n);
        	write(cfd, buf, n);
        	n=read(cfd, buf, MAXLINE);
        	write(fd2, buf, n);
		printf("Send %d bytes to server.\n", n);
    	}
    	close(cfd);
    }



    return 0;
}
