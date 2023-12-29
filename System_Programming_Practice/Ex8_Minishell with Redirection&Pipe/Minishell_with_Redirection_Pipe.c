#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

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

int main () {

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
    
    while(1) {

        int num = 0;
        cmd = NULL;
        getline(&cmd, &size, stdin);
        cmd[strlen(cmd)-1] = '\0';

        if(strcmp(cmd, "quit") == 0) {
            break;
        }

        if(strchr(cmd, '|') != NULL) {
            
            make_tokens(cmd, arg, arg2, "|");
            
            sprintf(path, "/bin/%s", arg[0]);
            sprintf(path2, "/bin/%s", arg2[0]);
            
            // insert your code
            // implement pipe using pipe and dup2 functions
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

        } 
        else if(strchr(cmd, '>') != NULL) {

            make_tokens(cmd, arg, arg2, ">");
            sprintf(path, "/bin/%s", arg[0]);
            
            // insert your code
            // implement > redirection using dup2
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
        else if(strchr(cmd, '<') != NULL) {

            make_tokens(cmd, arg, arg2, "<");
            sprintf(path, "/bin/%s", arg[0]);
            
            // insert your code
            // implement < redirection using dup2
            int in;
	    if(fork() == 0){
		in = open(arg2[0], O_RDONLY, 0644);
		dup2(in, 0);
		close(in);
		execv(path, arg);
                exit(0);

            }
            else{
		wait(&child_status);
            }
        }
        else {
        	
        	// mini shell from week5 - do not modify 

            ptr = strtok(cmd, " ");
            while (ptr != NULL) {
                arg[num++] = ptr;
                ptr = strtok(NULL, " ");
            }
            arg[num] = NULL;

            sprintf(path, "/bin/%s", arg[0]);
        
            if (fork() == 0) {
                execv(path, arg);
                exit(0);

            }
            else
                wait(&child_status);            

        }
	//printf("zhihizhlz\n");
    }

    return 0;

}
