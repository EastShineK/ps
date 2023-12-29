#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <sys/msg.h>
#include <unistd.h>
#include <time.h> 


struct msg
{
	long msgtype;
	/* implement here */ 
	char text[256];
};


struct msg_ack 
{
	long msgtype;
	/* implement here */
        char text[256];	
};


int main()
{
	/* 
	 * @ int uid: user id 
	 * @ int receiver_id: receveri's id 
	 * */ 
	int uid; 
	int receiver_id;
        printf("my id is\n");	
	scanf("%d", &uid);
	getchar(); // flush  
        printf("who to send ?\n");	
	scanf("%d", &receiver_id); 
	getchar(); // flush  
		
	/* 
	 * code to get key and QID 
	 *
	 *
	 * */ 
	key_t k = ftok(".", 'a');
	int qid = msgget(k, IPC_CREAT|IPC_NOWAIT|0660);
	if (qid == -1) {
		perror("msgget error : ");
		exit(0);
	}
	time_t tim = time(NULL);
	struct tm t = *localtime(&tim);
	//printf("hi\n");
	if (fork() == 0) 
	{
		while (1)
		{
			/* receive message  */ 
			/* get msg from queue and print out */ 
			char inp_reciver[256];
			//printf("hi\n");
			char* timeCheck;
			//printf("hi2\n");

			printf("RECEIVED ");
			struct msg_ack *m = malloc(sizeof(struct msg_ack));
			if(msgrcv(qid, (void *)m, sizeof(struct msg_ack), uid, 0) == -1){
				perror("msgrcv error : ");
				exit(0);
			}
			//printf("hi3\n");
			tim = time(NULL);
			timeCheck = ctime(&tim);
			printf("%s\n", m->text);
			
			char tk[50];

			//printf("%d read message at:	%s", uid, timeCheck);
			sprintf(tk,"%d read message at:     %s", uid, timeCheck);
			
			struct msg *m2 = malloc(sizeof(struct msg));
			m2->msgtype = uid;
			strcpy(m2->text, tk);
			//printf("hi4\n");
			if(msgsnd(qid, (void *)m2, sizeof(struct msg), 0) == -1){
				perror("msgsnd error : ");
				exit(0);
			}

			free(m);
			m = NULL;
			free(m2);
			m2 = NULL;
		}		
	
	}
	else
	{
		while (1) 
		{
			/*0send message  */ 
			/* get user input and send to the msg queue*/
			//printf("hi else1\n");
			struct msg *m2 = malloc(sizeof(struct msg));
			char inp_sender[256];

			m2->msgtype = receiver_id;
			//printf("hi else2\n");
			fgets(inp_sender, 256, stdin);
			strcpy(m2->text, inp_sender);

			if(msgsnd(qid, (void *)m2, sizeof(struct msg), 0) == -1){
                                perror("msgsnd error : ");
                                exit(0);
                        }
			//printf("hi else3\n");
			struct msg_ack *m = malloc(sizeof(struct msg_ack));
			if(msgrcv(qid, (void *)m, sizeof(struct msg_ack), receiver_id, 0) == -1){
                                perror("msgrcv error : ");
                                exit(0);
                        }
			//printf("hi else4\n");
			printf("%s\n", m->text);

			free(m2);
			m2 = NULL;
			free(m);
			m = NULL;

			
		}

		
	}	


	return 0;
}
