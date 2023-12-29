//2020312812 김동빈(Kim Dongbin)
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

#define cmd_type1 1
#define cmd_type1_1 5
#define cmd_type2 2
#define cmd_type3 3
#define cmd_type4 4

pid_t pid;

void make_tokens(char* cmd, char* arg[], char* arg2[], char* target) {

    int check = 0;
    int i = 0;
    char *ptr = strtok(cmd, " ");
    while(ptr != NULL){
	    //printf("%s\n", ptr);
	    if(strcmp(&ptr[0], &target[0])==0){
		    check++;
		    arg[i] = NULL;
		    i=0;
		    //printf("kzkzkzkz\n");
		    ptr = strtok(NULL, " ");
		    continue;
	    }
	    if(check == 0){
		    arg[i++] = ptr;
		    ptr = strtok(NULL, " ");
	    }
	    else{
		    //printf("hello\n");
		    arg2[i++] = ptr;
		    ptr = strtok(NULL, " ");
	    }
    }
    arg2[i] = NULL;
    //printf("hi : %s %s %s\n", arg[0],arg[1], arg2[0]);
    return;
}

void make_tokens_pipe(char* cmd, char* arg3[][128], char* target, int pipeNum) {

    int check = 0;
    int i = 0;
    int j = 0;
    char *ptr = strtok(cmd, " ");
    while(ptr != NULL){
            //printf("%s\n", ptr);
            if(strcmp(&ptr[0], &target[0])==0){
                    check++;
                    arg3[i][j] = NULL;
                    i++;
		    j = 0;
                    //printf("step2\n");

                    ptr = strtok(NULL, " ");
                    continue;
            }
	    else{
		    //printf("step 1\n");
                    arg3[i][j++] = ptr;
                    ptr = strtok(NULL, " ");
            }
	    //printf("hihi\n");
    }
    arg3[i][j] = NULL;
    /*for(int c = 0; c < i+1; c++){
    	//printf("hi : %s\n", &arg3[c][0]);
	printf("hi : %s\n", arg3[c][0]);
    }*/
    return;
}


int checkCmdType(char *arg){
	if(strcmp(&arg[0],"mv") == 0 || strcmp(&arg[0],"rm") == 0 || strcmp(&arg[0],"cd") == 0){
                  return cmd_type3;
        }
        else if(strcmp(&arg[0],"pwd") == 0 || strcmp(&arg[0],"exit") == 0){
                  return cmd_type4;
        }
	else if(strcmp(&arg[0],"head") == 0 || strcmp(&arg[0],"tail") == 0 || strcmp(&arg[0],"cat") == 0 || strcmp(&arg[0],"cp") == 0){
                  return cmd_type2;
        }
	else if(strcmp(&arg[0],"ls") == 0 || strcmp(&arg[0],"man") == 0 || strcmp(&arg[0],"grep") == 0 || strcmp(&arg[0],"sort") == 0 || strcmp(&arg[0],"awk") == 0 || strcmp(&arg[0],"bc") == 0){
                  return cmd_type1;
        }
	else if(arg[0] == '.')
		return cmd_type1_1;
	else
		return 0;



}


int main(){

	size_t size;
	char *cmd;
	char *ptr;
	char *arg[128];
	char *arg2[128];
	char *arg3[128][128];
	char *arg4[128];
	char *arg5[128];
	char path[128];
	//char path2[128];
	char path3[128][128];
	int child_status;
	int fd[100][2] = {0,};
	//int fdr;
	//char *sArr[50] = {NULL,};
	//cmd type1: ls, man, grep, sort, awk, bc
	//cmd type2: head, tail, cat, cp
	//cmd type3: mv, rm, cd
	//cmd type4: pwd, exit

	while(1){ // while 1 start : 0

		//signal(SIGTSTP, SIG_IGN);
		int num = 0;
		int typeOfcmd = 0;
		cmd = NULL;
		signal(SIGTSTP, SIG_IGN);
		signal(SIGINT, SIG_IGN);
		getline(&cmd, &size, stdin);
		cmd[strlen(cmd)-1] = '\0';

		if(strchr(cmd, '|') != NULL){ // if | check : 1
			int numberOfpipe = 0;
			//if(cmd[0] == '.')
				//numberOfType = 1;
			for(int i = 0; cmd[i] != '\0' ; i++){
				//printf("%c\n", cmd[i]);
				if(cmd[i] == 124/*strcmp(&cmd[i], "|") == 0*/)
					numberOfpipe++;
			}
			//printf("pipeMum: %d\n", numberOfpipe);
			//make_tokens(cmd, arg, arg2, " | ");
			make_tokens_pipe(cmd, arg3, "|", numberOfpipe);
			//char *ptr = strtok(cmd, "|");
			//int l = 0;
			//while(ptr != NULL){
			//	sArr[l] = ptr;
			//	l++;
			//	ptr = strtok(NULL, "|");
			//}
			for(int s = 0; s < numberOfpipe + 1; s++){
				sprintf(path3[s], "/bin/%s", arg3[s][0]);
			}
			//sprintf(path, "/bin/%s", arg[0]);
 		        //sprintf(path2, "/bin/%s", arg2[0]);
           		//printf("path3 0: %s\n", path3[0]); 
            		//printf("path3 1: %s %s\n", path3[1], arg3[1][1]);
			//printf("path3 2: %s %s\n", path3[2], arg3[2][1]);
			int check60 = 0, locate60 = 0;
			for(int a = 0; arg3[0][a] != '\0'; a++){
			if(strchr(arg3[0][a], '<') != NULL){
				check60 = 1;
				//printf("heleoehohele\n");
				for(int r = 0; arg3[0][r] != '\0'; r++){
					//printf("%s\n", arg3[0][r]);
					if(strcmp(arg3[0][r],"<") == 0){
						//printf("come in\n");
						locate60 = r + 1;
						arg3[0][r] = NULL;
						arg4[0] = arg3[0][r+1];				
					}
					if(locate60 != 0)
						arg3[0][r] = NULL;
					//printf("%s\n", arg3[0][r]);
				}
			}
			}
			if(access(arg4[0], F_OK) == -1){
                                                        fprintf(stderr, "swsh: No such file\n");
                                                        continue;
                        }

			//for(int r = 0; arg3[0][r] != '\0'; r++)
				//printf("%s\n", arg3[0][r]);
			
			if(pipe(fd[0]) == -1){
                    		exit(1);
            		}
			int in;
			//printf("%s\n", arg4[0]);i
			int q = checkCmdType(arg3[0][0]);
			//printf("%d\n", q);
			if(q == 0){
				//printf("jo\n");
				fprintf(stderr, "swsh: Command not found\n");
				continue;
			}
            		if(fork() == 0){
				close(STDOUT_FILENO);
				dup2(fd[0][1], STDOUT_FILENO);
				//printf("com 3\n");
                                close(fd[0][0]);
				//printf("com 4\n");
                                close(fd[0][1]);
				if(check60 == 1){
                                        //printf("in open\n");
                                        in = open(arg4[0], O_RDONLY, 0644);
					dup2(in ,0);
                                	close(in);
                                }
                                //printf("com 2\n");
				//printf("com 5\n");
				if(checkCmdType(arg3[0][0]) == 5)
					execl(arg3[0][0], arg3[0][0], NULL);
				else
                                	execv(path3[0], arg3[0]);
				//printf("com 6\n");
                                exit(0);
            		}
            		else{
				//printf("com 7\n");
                		//close(fd[0][0]);
                		close(fd[0][1]);
                		wait(&child_status);
				//printf("com 8\n");
            		}
			//printf("okokok1");
			for(int v = 1; v < numberOfpipe; v++){
                                if(pipe(fd[v])==-1){
                                        exit(1);
                                }
				if(checkCmdType(arg3[v][0]) == 0){
                                	//printf("jo222\n");
					fprintf(stderr, "swsh: Command not found\n");
                                	continue;
                        	}	
				if(fork() == 0){
					//printf("hixxxxxx\n");
					dup2(fd[v-1][0], STDIN_FILENO);
                                	dup2(fd[v][1], STDOUT_FILENO);
                                	close(fd[v-1][0]);
                                	close(fd[v][1]);
					if(checkCmdType(arg3[v][0]) == 5)
						execl(arg3[v][0],arg3[v][0], NULL);
					else
                                		execv(path3[v], arg3[v]);
                                	exit(0);
                        	}
                        	else{
                                	//close(fd[v][0]);
                                	close(fd[v][1]);
                                	wait(&child_status);
                        	}
                        }
			
			/*if(pipe(fd[numberOfpipe]) == -1){
				exit(1);
			}*/
			//printf("okokok2
			int check62 = 0, locate62 = 0;
                        for(int a = 0; arg3[numberOfpipe][a] != '\0'; a++){
                        if(strchr(arg3[numberOfpipe][a], '>') != NULL){
                                check62 = 1;
                                //printf("heleoehohele\n");
                                for(int r = 0; arg3[numberOfpipe][r] != '\0'; r++){
                                        //printf("%s\n", arg3[numberOfpipe][r]);
                                        if(strcmp(arg3[numberOfpipe][r],">") == 0){
                                                //printf("come in\n");
                                                locate62 = r + 1;
                                                arg3[numberOfpipe][r] = NULL;
                                                arg5[0] = arg3[numberOfpipe][r+1];
                                        }
                                        if(locate62 != 0)
                                                arg3[numberOfpipe][r] = NULL;
                                        //printf("%s\n", arg3[0][r]);
                                }
                        }
			}

			//for(int r = 0; arg3[numberOfpipe][r] != '\0'; r++)
                                //printf("k : %s\n", arg3[numberOfpipe][r]);

                        if(checkCmdType(arg3[numberOfpipe][0]) == 0){
				//printf("jo3333\n");
                                fprintf(stderr, "swsh: Command not found\n");
                                continue;
                        }
			int out;
			//printf("%s\n", arg5[0]);
			if(fork() == 0){
				//printf("comcomcomco\n");
                                dup2(fd[numberOfpipe-1][0], STDIN_FILENO);
                                close(fd[numberOfpipe-1][0]);
                                close(fd[numberOfpipe-1][1]);
				if(check62 == 1){
					out = open(arg5[0], O_RDWR|O_CREAT|O_TRUNC, 0644);
					dup2(out, 1);
				}
				if(checkCmdType(arg3[numberOfpipe][0]) == 5)
					execl(arg3[numberOfpipe][0],arg3[numberOfpipe][0], NULL);
				else
                                	execv(path3[numberOfpipe], arg3[numberOfpipe]);
                                exit(0);
                        }
                        else{
				//printf("nonononoon\n");
                                //close(fd[numberOfpipe-1][0]);
                                //close(fd[numberOfpipe-1][1]);
                                wait(&child_status);
				//printf("end pipe?\n");
                        }

        	} //if | check end : 1		
		else{ // not pipe, command only 1 start  : 2
			if(strchr(cmd, '<') != NULL && strchr(cmd, '>') != NULL){ //command < file > file
				make_tokens(cmd, arg, arg2, "<");
				//make_tokens(arg2, arg2, arg3, ">");
				sprintf(path, "/bin/%s", arg[0]);
				int in, out;
				typeOfcmd = checkCmdType(arg[0]);
				//printf("1: %s 2: %s 3: %s\n", arg[0], arg2[0], arg2[2]);
				if(access(arg2[0], F_OK) == -1){
                                                        fprintf(stderr, "swsh: No such file\n");
                                                        continue;
                                }
				if(typeOfcmd == 1){
                                        if(fork() == 0){
                                                in = open(arg2[0], O_RDONLY, 0644);
						out = open(arg2[2], O_RDWR|O_CREAT|O_TRUNC, 0644);
                                                //printf("%s\n", arg2[0]);
                                                dup2(in, 0);
                                                close(in);
                                                //printf("%s %s\n", arg[0], arg[1]);
                                                //execv(path, arg);
						dup2(out, 1);
						execv(path, arg);
                                                exit(0);
                                        }
                                        else{
                                                wait(&child_status);
                                        }
                                }
				if(typeOfcmd == 2){
                                        if(fork() == 0){
                                                in = open(arg2[0], O_RDONLY, 0644);
                                                out = open(arg2[2], O_RDWR|O_CREAT|O_TRUNC, 0644);
                                                //printf("%s\n", arg2[0]);
                                                dup2(in, 0);
                                                close(in);
                                                //printf("%s %s\n", arg[0], arg[1]);
                                                //execv(path, arg);
                                                dup2(out, 1);
                                                execv(path, arg);
                                                exit(0);
                                        }
                                        else{
                                                wait(&child_status);
                                        }
                                }
				else if(typeOfcmd == 3){ // < input을 파일을 통해 넣어 줄 경우의 코드 추가해야함
                                        int checkCmd3;
                                        if(strcmp(arg[0], "cd") == 0){
                                                checkCmd3 = 1;
                                        }
                                        if(fork() == 0){
                                                in = open(arg2[0], O_RDONLY, 0644);
						out = open(arg2[2], O_RDWR|O_CREAT|O_TRUNC, 0644);
                                                //printf("%s\n", arg2[0]);
                                                dup2(in, 0);
                                                close(in);
						dup2(out, 1);
                                                //printf("%s %s\n", arg[0], arg[1]);
                                                if(checkCmd3 == 1){
                                                        chdir(arg[1]);
                                                        exit(0);
                                                }
                                                else{
                                                        execv(path, arg);
                                                        exit(0);
                                                }
                                        }
                                        else{
                                                wait(&child_status);
                                                if(checkCmd3 == 1){
                                                        if(chdir(arg[1]))
                                                                fprintf(stderr, "cd: %s\n", strerror(errno));
                                                }
                                        }
                                }
				else if(typeOfcmd == 4){ // < input을 파일을 통해 넣어 줄 경우의 코드 추가해야함
                                        int checkCmd4;
                                        if(strcmp(arg[0], "exit") == 0){
                                                checkCmd4 = 1;
                                        }
                                        if(fork() == 0){
                                                in = open(arg2[0], O_RDONLY, 0644);
						out = open(arg2[2], O_RDWR|O_CREAT|O_TRUNC, 0644);
                                                //printf("%s\n", arg2[0]);
                                                dup2(in, 0);
                                                close(in);
						dup2(out, 1);
                                                //printf("%s %s\n", arg[0], arg[1]);
                                                if(checkCmd4 == 1){
                                                        int exitNum = atoi(arg[1]);
                                                        exit(exitNum);
                                                }
                                                else{
                                                        execv(path, arg);
                                                        exit(0);
                                                }
                                        }
                                        else{
                                                wait(&child_status);
                                                if(checkCmd4 == 1){
                                                        if(arg[1] == NULL)
                                                                exit(0);
                                                        else
                                                                exit(atoi(arg[1]));
                                                }
                                        }
                                }
				else{
					fprintf(stderr, "swsh: Command not found\n");
				}
			}
			else if(strchr(cmd, '<') != NULL){ // command < file start : 4
				make_tokens(cmd, arg, arg2, "<");
                                sprintf(path, "/bin/%s", arg[0]);
                                int in;
				typeOfcmd = checkCmdType(arg[0]);
				if(access(arg2[0], F_OK) == -1){
                                                        fprintf(stderr, "swsh: No such file\n");
							continue;
                                }

				if(typeOfcmd == 1){
                                        if(fork() == 0){
                                                in = open(arg2[0], O_RDONLY, 0644);
                                                //printf("%s\n", arg2[0]);
                                                dup2(in, 0);
						close(in);
                                                //printf("%s %s\n", arg[0], arg[1]);
                                                execv(path, arg);
                                                exit(0);
                                        }
                                        else{
                                                wait(&child_status);
                                        }
                                }
				else if(typeOfcmd == 2){ // file doesn't exist -> print error 추가해야함
                                        if(fork() == 0){
                                                in = open(arg2[0], O_RDONLY, 0644);
                                                //printf("%s\n", arg2[0]);
                                                dup2(in, 0);
                                                close(in);
                                                //printf("%s %s\n", arg[0], arg[1]);
                                                execv(path, arg);
                                                exit(0);
                                        }
                                        else{
                                                wait(&child_status);
                                        }
                                }
				else if(typeOfcmd == 3){ // < input을 파일을 통해 넣어 줄 경우의 코드 추가해야함 
                                        int checkCmd3;
                                        if(strcmp(arg[0], "cd") == 0){
                                                checkCmd3 = 1;
                                        }
                                        if(fork() == 0){
                                                in = open(arg2[0], O_RDONLY, 0644);
                                                //printf("%s\n", arg2[0]);
                                                dup2(in, 0);
                                                close(in);

                                                //printf("%s %s\n", arg[0], arg[1]);
                                                if(checkCmd3 == 1){
                                                        chdir(arg[1]);
                                                        exit(0);
                                                }
                                                else{
                                                        execv(path, arg);
                                                        exit(0);
                                                }
                                        }
                                        else{
                                                wait(&child_status);
                                                if(checkCmd3 == 1){
                                                        if(chdir(arg[1]))
                                                                fprintf(stderr, "cd: %s\n", strerror(errno));
                                                }
                                        }
                                }
				else if(typeOfcmd == 4){ // < input을 파일을 통해 넣어 줄 경우의 코드 추가해야함 
                                        int checkCmd4;
                                        if(strcmp(arg[0], "exit") == 0){
                                                checkCmd4 = 1;
                                        }
                                        if(fork() == 0){
                                                in = open(arg2[0], O_RDONLY, 0644);
                                                //printf("%s\n", arg2[0]);
                                                dup2(in, 0);
                                                close(in);

                                                //printf("%s %s\n", arg[0], arg[1]);
                                                if(checkCmd4 == 1){
							int exitNum = atoi(arg[1]);
                                                        exit(exitNum);
                                                }
                                                else{
                                                        execv(path, arg);
                                                        exit(0);
                                                }
                                        }
                                        else{
                                                wait(&child_status);
                                                if(checkCmd4 == 1){
							if(arg[1] == NULL)
								exit(0);
							else
                                                        	exit(atoi(arg[1]));
                                                }
                                        }
                                }
				else{
					if(cmd[0] == '.'){
                                        	if(fork()==0){
                                                	in = open(arg2[0], O_RDONLY, 0644);
                                                //printf("%s\n", arg2[0]);
                                                	dup2(in, 0);
                                                	close(in);
                                                //printf("%s %s\n", arg[0], arg[1]);
                                                	execl(cmd, cmd, NULL);
                                                	exit(0);
                                        	}
                                        	else{
                                                	wait(&child_status);
                                        	}
                                	}
					else
                                        	fprintf(stderr, "swsh: Command not found\n");
                                }

                        } // command < file end : 3
			else if(strstr(cmd, ">>") != NULL){ // command >> file
				make_tokens(cmd, arg, arg2, ">>");
                                sprintf(path, "/bin/%s", arg[0]);
                                int out;
                                typeOfcmd = checkCmdType(arg[0]);
                                //printf("gheelo >\n");

                                if(typeOfcmd == 1){
                                        pid = fork();
					if(pid == 0){
                                                out = open(arg2[0], O_RDWR|O_CREAT|O_APPEND, 0644);
                                                //printf("%s\n", arg2[0]);
                                                //lseek(out, 0, SEEK_END);
						dup2(out, 1);
                                                //printf("%s %s\n", arg[0], arg[1]);
						//lseek(out, 0, SEEK_END);
                                                execv(path, arg);
                                                exit(0);
                                        }
                                        else{
                                                //wait(&child_status);
                                                waitpid(-1, &child_status, WNOHANG | WUNTRACED );
                                                     
                                        }
				}
				else if(typeOfcmd == 2){
                                        pid = fork();
					if(pid == 0){
                                                out = open(arg2[0], O_RDWR|O_CREAT|O_APPEND, 0644);
                                                //printf("%s\n", arg2[0]);
                                                //lseek(out, 0, SEEK_END);
						dup2(out, 1);
						//lseek(out, 0, SEEK_END);
                                                //printf("%s %s\n", arg[0], arg[1]);
                                                execv(path, arg);
                                                exit(0);
                                        }
                                        else{
                                                //wait(&child_status);
                                                waitpid(-1, &child_status, WNOHANG | WUNTRACED );
                                                      
                                        }
                                }
				else if(typeOfcmd == 3){
                                        int checkCmd3;
                                        if(strcmp(arg[0], "cd") == 0){
                                                checkCmd3 = 1;
                                        }
					pid = fork();
                                        if(pid == 0){
                                                out = open(arg2[0], O_RDWR|O_CREAT|O_APPEND, 0644);
                                                //printf("%s\n", arg2[0]);
                                                dup2(out, 1);
						//lseek(out, 0, SEEK_END);
                                                //printf("%s %s\n", arg[0], arg[1]);
                                                if(checkCmd3 == 1){
                                                        chdir(arg[1]);
                                                        exit(0);
                                                }
                                                else{
                                                        execv(path, arg);
                                                        exit(0);
                                                }
                                        }
                                        else{
                                                //wait(&child_status);
                                                waitpid(-1, &child_status, WNOHANG | WUNTRACED );
                                                        
                                        

                                                if(checkCmd3 == 1){
                                                        if(chdir(arg[1]))
                                                                fprintf(stderr, "cd: %s\n", strerror(errno));
                                                }
                                        }
                                }
				else if(typeOfcmd == 4){
                                        int checkCmd4;
                                        if(strcmp(arg[0], "exit") == 0){
                                                checkCmd4 = 1;
                                        }
					pid = fork();
                                        if(pid == 0){
                                                out = open(arg2[0], O_RDWR|O_CREAT|O_APPEND, 0644);
                                                //printf("%s\n", arg2[0]);
                                                dup2(out, 1);
						//lseek(out, 0, SEEK_END);
                                                //printf("%s %s\n", arg[0], arg[1]);
                                                if(checkCmd4 == 1){
                                                        int exitNum = atoi(arg[1]);
                                                        exit(exitNum);
                                                }
                                                else{
                                                        execv(path, arg);
                                                        exit(0);
                                                }
                                        }
                                        else{
                                                //wait(&child_status);
                                                waitpid(-1, &child_status, WNOHANG | WUNTRACED );
                                                     

                                                if(checkCmd4 == 1){
                                                        if(arg[1] == NULL)
                                                                exit(0);
                                                        else
                                                                exit(atoi(arg[1]));
                                                }
                                        }
                                }
                                //`close(out);
				else{
                                        if(cmd[0] == '.'){
                                                pid = fork();
						if(pid == 0){
                                                        out = open(arg2[0], O_RDWR|O_CREAT|O_APPEND, 0664);
                                                //printf("%s\n", arg2[0]);
                                                        dup2(out, 1);
                                                //printf("%s %s\n", arg[0], arg[1]);
                                                        execl(cmd, cmd, NULL);
                                                        exit(0);
                                                }
                                                else{
                                                //wait(&child_status);
                                                	waitpid(-1, &child_status, WNOHANG | WUNTRACED );
                                                        	
                                        	}

                                        }
                                        else
                                                fprintf(stderr, "swsh: Command not found\n");
                                }

                         }
			else if(strchr(cmd, '>') != NULL){ // command > file start : 4
				
				make_tokens(cmd, arg, arg2, ">");
            			sprintf(path, "/bin/%s", arg[0]);
            			int out;
				typeOfcmd = checkCmdType(arg[0]);
            			//printf("gheelo >\n");

				if(typeOfcmd == 1){
					pid = fork();
					if(pid == 0){
                                        	out = open(arg2[0], O_RDWR|O_CREAT|O_TRUNC, 0644);
                                        	//printf("%s\n", arg2[0]);
                                        	dup2(out, 1);
                                        	//printf("%s %s\n", arg[0], arg[1]);
                                        	execv(path, arg);
                                        	exit(0);
                                	}
                             		else{
                                                //wait(&child_status);
                                                waitpid(-1, &child_status, WNOHANG | WUNTRACED );
                                                     
                                        }

				}
				else if(typeOfcmd == 2){
                                        pid = fork();
					if(pid == 0){
                                                out = open(arg2[0], O_RDWR|O_CREAT|O_TRUNC, 0644);
                                                //printf("%s\n", arg2[0]);
                                                dup2(out, 1);
                                                //printf("%s %s\n", arg[0], arg[1]);
                                                execv(path, arg);
                                                exit(0);
                                        }
                                        else{
                                                //wait(&child_status);
                                                waitpid(-1, &child_status, WNOHANG | WUNTRACED );
                                                       
                                        }

				}
				else if(typeOfcmd == 3){
					int checkCmd3;
					if(strcmp(arg[0], "cd") == 0){
						checkCmd3 = 1;
					}
					pid = fork();
                                        if(pid == 0){
                                                out = open(arg2[0], O_RDWR|O_CREAT|O_TRUNC, 0644);
                                                //printf("%s\n", arg2[0]);
                                                dup2(out, 1);
                                                //printf("%s %s\n", arg[0], arg[1]);
						if(checkCmd3 == 1){
							chdir(arg[1]);
							exit(0);
						}
						else{
                                                	execv(path, arg);
                                                	exit(0);
						}
                                        }
                                        else{
                                                
                                                //wait(&child_status);
                                                waitpid(-1, &child_status, WNOHANG | WUNTRACED );
                                                       
                                        

						if(checkCmd3 == 1){
							if(chdir(arg[1]))
                                                                fprintf(stderr, "cd: %s\n", strerror(errno));
						}
                                        }
                                }
				else if(typeOfcmd == 4){
                                        int checkCmd4;
                                        if(strcmp(arg[0], "exit") == 0){
                                                checkCmd4 = 1;
                                        }
					pid = fork();
                                        if(pid == 0){
                                                out = open(arg2[0], O_RDWR|O_CREAT|O_TRUNC, 0644);
                                                //printf("%s\n", arg2[0]);
                                                dup2(out, 1);
                                                //printf("%s %s\n", arg[0], arg[1]);
                                                if(checkCmd4 == 1){
							int exitNum = atoi(arg[1]);
                                                        exit(exitNum);
                                                }
                                                else{
                                                        execv(path, arg);
                                                        exit(0);
                                                }
                                        }
                                        else{
						
                                                //wait(&child_status);
                                                waitpid(-1, &child_status, WNOHANG | WUNTRACED );
                                        	
                                                if(checkCmd4 == 1){
                                                        if(arg[1] == NULL)
								exit(0);
							else
								exit(atoi(arg[1]));
                                                }
                                        }
                                }
            			//`close(out);
				else{
					if(cmd[0] == '.'){
						pid = fork();
                                        	if(pid == 0){
                                                	out = open(arg2[0], O_RDWR|O_CREAT|O_TRUNC, 0644);
                                                //printf("%s\n", arg2[0]);
                                                	dup2(out, 1);
                                                //printf("%s %s\n", arg[0], arg[1]);
                                                	execl(cmd,cmd, NULL);
                                                	exit(0);
                                        	}
                                        	else{
                                                //wait(&child_status);
                                                	waitpid(-1, &child_status, WNOHANG | WUNTRACED );
                                                    
                                        	}

                                	}
					else
                                        	fprintf(stderr, "swsh: Command not found\n");
                                }
                         } // command > file end : 4
			 else{ // command start : 7
				
				ptr = strtok(cmd, " ");
				while(ptr != NULL){
					arg[num++] = ptr;
					ptr = strtok(NULL, " ");
				}
				arg[num] = NULL;
	
				typeOfcmd = checkCmdType(arg[0]);
				//printf("type Cmd : %d\n", typeOfcmd);

				if(typeOfcmd == 1){
					sprintf(path, "/bin/%s", arg[0]);
					pid = fork();
                                	if(pid == 0){
                                        	execv(path, arg);
                                        	exit(0);
                                	}
                                	else{
                                        	//wait(&child_status);
						
						waitpid(-1, &child_status, WNOHANG | WUNTRACED );
                                                if(WIFSTOPPED(child_status))
                                                        kill(pid, SIGKILL);

						//printf("wefq\n");
					}
				}
				else if(typeOfcmd == 2){
					sprintf(path, "/bin/%s", arg[0]);
					pid = fork();
                                	if(pid == 0){
						//printf("hi2\n");
                                        	if(execv(path, arg))
							fprintf(stderr, "%s\n", strerror(errno));
                                        	exit(0);
                                	}
                                	else{
                                                //wait(&child_status);
                                                waitpid(-1, &child_status, WNOHANG | WUNTRACED );
						//printf("%d %d %d %d\n", WIFSIGNALED(child_status), WIFSTOPPED(child_status), WTERMSIG(child_status), WSTOPSIG(child_status));

                                                if(WIFSTOPPED(child_status))        
							kill(pid, SIGKILL);
						//printf("nono\n");
                                        }

                                        	
                                }
				else if(typeOfcmd == 3){
					int checkCmd3;
					if(strcmp(arg[0],"mv") == 0){
						//printf("in mv\n");
                  				checkCmd3 = 0;//rename();
        				}
					else if(strcmp(arg[0],"rm") == 0){
                                                //printf("in rm\n");
						checkCmd3 = 2;//unlink();
                                        }
					else if(strcmp(arg[0],"cd") == 0){
                                                //printf("in cd\n");
						checkCmd3 = 1;//chdir();
                                        }
					sprintf(path, "/bin/%s", arg[0]);
					//printf("%s %s\n", arg[0], arg[1]);
					//printf("check cmd3 : %d\n", checkCmd3);
                                        pid = fork();
					if(pid == 0){
						if(checkCmd3 == 1){
							//char pa[1024];
							//printf("%s\n", getcwd(pa, 1024));
							chdir(arg[1]);
							//printf("%s\n", getcwd(pa, 1024));
							exit(0);
						}
						else{
                                                	execv(path, arg);
                                                	exit(0);
						}
                                        }
                                        else{
                                                //wait(&child_status);
                                                waitpid(-1, &child_status, WNOHANG | WUNTRACED );
                                                        
                            
						if(checkCmd3 == 1){
							if(chdir(arg[1]))
								fprintf(stderr, "cd: %s\n", strerror(errno));
						}
					}

                                }
				else if(typeOfcmd == 4){
					int checkCmd4;
					sprintf(path, "/bin/%s", arg[0]);
					if(strcmp(arg[0],"exit") == 0){
                                                checkCmd4 = 1;//rename();
                                        }

					pid =fork();
                                        if(pid == 0){
                                                if(checkCmd4 == 1){
							int exitNum = atoi(arg[1]);
							//printf("%d\n", exitNum);
                                                        exit(exitNum);
							//printf("ok222\n");
                                                }
                                                else{
                                                        execv(path, arg);
                                                        exit(0);
                                                }
                                        }
                                        else{
                                                
                                                //wait(&child_status);
                                                waitpid(-1, &child_status, WNOHANG | WUNTRACED );
                                                        
                                        

						if(checkCmd4 == 1){
							if(arg[1] == NULL)
								exit(0);
							else
								exit(atoi(arg[1]));
						}
					}

                                }
				else{
					//printf("in\n");
					if(cmd[0] == '.'){
						pid = fork();
						if(pid == 0){
                                                	execl(cmd, cmd, NULL);
                                                	exit(0);
                                        	}
                                        	else{
                                                //wait(&child_status);
                                                	waitpid(-1, &child_status, WNOHANG | WUNTRACED );
                                                       
                                        	}

                                                	
					}
					else{
                                        	fprintf(stderr, "swsh: Command not found\n");
						//printf("\n");
					}
                                }

			 } // command end : 7

		} // not pipe, command only 1 end : 2
		//printf("%d\n", typeOfcmd);
				
		
		
		
	}// while 1 end	: 0
	return 0;
}
