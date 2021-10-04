#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

int main(){


        pid_t pid;


	while(1){
		
		char *cmd;
        	size_t size;
        	int i = 0;
        	char *arg[10] = { NULL, };
       		char path[100];
		
		
		getline(&cmd, &size, stdin);
		cmd[strlen(cmd)-1] = '\0';
		
		char *ptr = strtok(cmd, " ");

		while(ptr != NULL){
			arg[i++] = ptr;
			ptr = strtok(NULL, " ");
		}
		arg[i] = NULL;
		
		sprintf(path, "/bin/%s", arg[0]);

		if(strcmp(arg[0], "quit")==0)
			break;
		pid = fork();
		if(pid == 0){
			if(i==1){
				execlp(path, path, NULL);
				exit(0);
			}
			else{
				//printf("%d\n", i);
				//printf("%s %s %s\n", arg[0], arg[1], arg[2]);
				//execl(path, arg[0], arg[1], NULL);
				execv(path, arg);
				exit(0);
			}
		}
		else{
			wait(NULL);
		}
			
	
	}

}
