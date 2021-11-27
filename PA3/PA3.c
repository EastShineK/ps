#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<pthread.h>
#include<netdb.h>
#include<arpa/inet.h>

// seat : 256(0~255), client :1024(0~1023), action : 1~5, out of range : -1
// 1: log in
// 2: reserve
// 3: check reservation
// 4: cancel
// 5: log out 

struct query {
	int user;
	int action;
	int data;
};

int userState[1024];
int seat[256];
int userSeatNum[1024];

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

void *act(void *arg){

	pthread_mutex_lock(&m);
	struct query information;
	int n = *(int*) arg;
	int recvD, ans;
	if((recvD = recv(n, &information, sizeof(information), 0)) > 0){
		if(information.action == 1){ // log in
			fdsf
		}
		else if(information.action == 2){// reserve
                        fdsf
                }
		else if(information.action == 3){// check
                        fdsf
                }
		else if(information.action == 4){// cancel
                        fdsf
                }
		else if(information.action == 5){// log out
                        fdsf
                }
	} // if recv end

	
	pthread_mutex_unlock(&m);
}

int main(int argc, char *argv[]){

	int listenfd, connfd;
	int n;
	socklen_t caddrlen;
	char buf[100];
	struct sockaddr_in saddr, caddr;

	int port = atoi(argv[1]);

	for(int i = 0; i < 1024; i++){
                userState[i] = -1;
        }

	for(int i = 0; i < 256; i++){
		seat[i] = -1;
	}

	for(int i = 0; i < 1024; i++){
                userSeatNum[i] = -1;
        }

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




	return 0;
}
