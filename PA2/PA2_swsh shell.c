#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define cmd_type1 1
#define cmd_type2 2
#define cmd_type3 3
#define cmd_type4 4

void make_tokens(char* cmd, char* arg[], char* arg2[], char* target) {

   // insert your code
   // make tokens which will be used in pipe or redirections
   // you can change the parameters if you want
    int check = 0;
    int saveI = 0;
    int i = 0, j = 0;
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
	else
		return 0;



}


int main(){

	size_t size;
	char *cmd;
	char *ptr;
	char *arg[128];
	char *arg2[128];
	char path[128];
	char path2[128];
	int child_status;
	int fd[2];
	int fdr;
	
	//cmd type1: ls, man, grep, sort, awk, bc
	//cmd type2: head, tail, cat, cp
	//cmd type3: mv, rm, cd
	//cmd type4: pwd, exit

	while(1){ // while 1 start : 0
		int num = 0;
		int typeOfcmd = 0;
		cmd = NULL;
		getline(&cmd, &size, stdin);
		cmd[strlen(cmd)-1] = '\0';

		if(strchr(cmd, '|') != NULL){ // if | check : 1
			
			make_tokens(cmd, arg, arg2, "|");

			 sprintf(path, "/bin/%s", arg[0]);
 		         sprintf(path2, "/bin/%s", arg2[0]);

            
            
            		if(pipe(fd) == -1){
                    		exit(1);
            		}
            		//printf("%s %s %s  %s\n", arg[0], arg[1], arg2[0], arg2[1]);
            		if(fork() == 0){
                    		if(fork() == 0){
                            		//close(fd[0]);
                            		dup2(fd[1], STDOUT_FILENO);
                            		close(fd[0]);
                            		close(fd[1]);
                            		execv(path, arg);
                            		exit(0);
                    		}
                    		else{
                            		//close(fd[1]);
                            		dup2(fd[0], STDIN_FILENO);
                            		close(fd[1]);
                            		close(fd[0]);
                            		execv(path2, arg2);
                            		exit(0);
                    		}
            		}
            		else{
                		close(fd[0]);
                		close(fd[1]);
                		wait(&child_status);
            		}

        	} //if | check end : 1		
		else{ // not pipe, command only 1 start  : 2
			if(strchr(cmd, '<') != NULL && strchr(cmd, '>') != NULL){ //command < file > file

			}
			else if(strchr(cmd, '<') != NULL){ // command < file

                        }
			else if(strchr(cmd, '>') != NULL){ // command > file
				
				make_tokens(cmd, arg, arg2, ">");
            			sprintf(path, "/bin/%s", arg[0]);
            			int out;
            			//printf("gheelo >\n");
            			if(fork() == 0){
                			out = open(arg2[0], O_RDWR|O_CREAT|O_TRUNC, 0644);
                			//printf("%s\n", arg2[0]);
                			dup2(out, 1);
                		  	//printf("%s %s\n", arg[0], arg[1]);
                			execv(path, arg);
                			exit(0);
           			}
            			else{
                			wait(&child_status);
            			}
            			//`close(out);
                         }
			 else if(strchr(cmd, ">>") != NULL){ // command >> file

                         }
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

                                	if(fork() == 0){
                                        	execv(path, arg);
                                        	exit(0);
                                	}
                                	else
                                        	wait(&child_status);
				}
				else if(typeOfcmd == 2){
					sprintf(path, "/bin/%s", arg[0]);

                                	if(fork() == 0){
                                        	execv(path, arg);
                                        	exit(0);
                                	}
                                	else
                                        	wait(&child_status);
                                }
				else if(typeOfcmd == 3){
					int checkCmd3;
					if(strcmp(arg[0],"mv") == 0){
						//printf("in mv\n");
                  				checkCmd3 = 0;//rename();
        				}
					else if(strcmp(arg[0],"rm") == 0){
                                                //printf("in rm\n");
						checkCmd3 = 0;//unlink();
                                        }
					else if(strcmp(arg[0],"cd") == 0){
                                                //printf("in cd\n");
						checkCmd3 = 1;//chdir();
                                        }
					sprintf(path, "/bin/%s", arg[0]);
					//printf("%s %s\n", arg[0], arg[1]);
					//printf("check cmd3 : %d\n", checkCmd3);
                                        if(fork() == 0){
						if(checkCmd3 == 1){
							char pa[1024];
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
                                                wait(&child_status);
						if(checkCmd3 == 1){
							chdir(arg[1]);
						}
					}

                                }
				else if(typeOfcmd == 4){
					int checkCmd4;
					sprintf(path, "/bin/%s", arg[0]);
					if(strcmp(arg[0],"exit") == 0){
                                                checkCmd4 = 1;//rename();
                                        }

					
                                        if(fork() == 0){
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
                                                wait(&child_status);
						if(checkCmd4 == 1){
							if(arg[1] == NULL)
								exit(0);
							else
								exit(atoi(arg[1]));
						}
					}

                                }
				else{ // cmd type == 0

				}

			 } // command end : 7

		} // not pipe, command only 1 end : 2

				
		
		
		
	}// while 1 end	: 0
	return 0;
}
