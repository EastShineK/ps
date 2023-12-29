#include <sys/select.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAXUSER 10
#define MAXNAME 10
#define MAXLINE 80

int main (int argc, char *argv[]) {

    int n, listenfd, connfd, caddrlen, fdmax, fdnum, usernum;
    struct hostent *h;
    struct sockaddr_in saddr, caddr;
    char buf[MAXLINE];
    char name[MAXUSER][MAXNAME];
    char temp[MAXLINE+MAXNAME+1];
    int port = atoi(argv[1]);
    fd_set readset, copyset;

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("socket() failed.\n");
        exit(1);
    }

    memset((char *)&saddr, 0, sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);
    saddr.sin_port = htons(port);

    if (bind(listenfd, (struct sockaddr *)&saddr, sizeof(saddr)) < 0) {
        printf("bind() failed.\n");
        exit(2);
    }

    if (listen(listenfd, 5) < 0) {
        printf("listen() failed.\n");
        exit(3);
    }
	
    //printf("hi2222\n");
    /* Insert your code for file descriptor set
	*
	*
	**/
    //fdmax = listenfd, fdnum;
    FD_ZERO(&readset);
    FD_SET(listenfd, &readset);
    fdmax = listenfd, fdnum; 

    int people[100] = {0,};
    char* mes;
    mes = (char*)malloc(sizeof(char)*100);

    while (1) {

        copyset = readset;

        if( (fdnum = select(fdmax + 1, &copyset, NULL, NULL, NULL)) < 0 ) {
            printf("select() failed.\n");
            exit(4);
        }
	//printf("hi000\n");
	//printf("fdmax : %d\n", fdmax);
	caddrlen=sizeof(caddr);
       for (int i = 3; i < fdmax + 1; i++) {

           //memset(buf, 0, MAXLINE);
           //memset(temp, 0, MAXLINE+MAXNAME+1);

            if ( FD_ISSET(i, &copyset)) {

                if (i == listenfd) {
                    
                    //caddrlen = sizeof(caddr);
                    if ((connfd = accept(listenfd, (struct sockaddr *)&caddr, (socklen_t *)&caddrlen)) < 0) {
                        printf ("accept() failed.\n");
                        continue;
                    }
                    /* Insert your code */
		    FD_SET(connfd, &readset);
		    if(fdmax < connfd) fdmax = connfd; 

                }
                else {
                    /* Insert your code */
			//printf("else hi\n");
			if(people[i] == 0){//first come
				//printf("else hi0\n");
				if((n=read(i, buf, MAXLINE)) > 0){
					memcpy(name[i], buf, MAXUSER);
					//printf("else hi1-2\n");
					//mes = (char*)malloc(sizeof(char)*2);
					memset(mes, 0, sizeof(mes));
					memset(temp, 0, MAXLINE+MAXNAME+1);
					//printf("else hi1-3\n");
					sprintf(mes, "%s joined. %d current users", name[i], fdmax-3);
					strcpy(temp, mes);
					//printf("mes: %s\n", mes);
					//printf("temp: %s\n", temp);
					for(int k = 4; k < fdmax + 1; k++){
						//printf("in joined write\n");
						if(FD_ISSET(k, &readset) && k != i){
							//printf("fwiqejflwef: temp : %s\n", temp);
							write(k, temp, sizeof(temp));
						}
					}
				}
				//printf("else hi2\n");
				people[i]++;
			}
			else if((n=read(i, buf, MAXLINE)) > 0){
				//printf("else hi3\n");
				if(strncmp(buf, "quit", 4) == 0){
               				sprintf(mes, "%s leaved. %d current users\n", name[i], fdmax-4);
                                        strcpy(temp, mes);
                			FD_CLR(i, &readset);
					close(i);
        			}
				else{
					printf("got %d bytes from user %s.\n", n, name[i]);
					memset(mes, 0, sizeof(mes));
					sprintf(mes, "%s: %s", name[i], buf);
					//printf("%s: %s", name[i], buf);
                                        strcpy(temp, mes);
				}
				for(int k = 4; k < fdmax + 1; k++){
				//	printf("in write\n");
				//	printf("in wri temp: %s\n", temp);
					if(FD_ISSET(k, &readset) && k != i){
						//printf("kodwkjflkdwmqlf;we\n");
                                                        write(k, temp, sizeof(temp));
					}
                                }
			}
			else{
				FD_CLR(i, &readset);
				printf("connection terminated.\n");
				close(i);
			}
                    
                }
            }  
        }
       memset(buf, 0, sizeof(buf));
    }

    return 0;

}

