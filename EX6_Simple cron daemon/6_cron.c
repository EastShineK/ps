#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <limits.h>
#include <signal.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <syslog.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	unsigned int pid;
	time_t t;
	struct tm *tm;	
	int fd;
	char *argv[3];
	char buf[512];
	int fd0, fd1, fd2;

	fd = open("./crontab", O_RDWR);
	pid = fork();
	
	if(pid == -1) return -1;
	if(pid != 0)
		exit(0);
	if(setsid() < 0)
		exit(0);
	if(chdir("/") < 0)
		exit(0);

	umask(0);

	close(0);
	close(1);
	close(2);

	fd0 = open("/dev/null", O_RDWR);
	fd1 = open("/dev/null", O_RDWR);
	fd2 = open("/dev/null", O_RDWR);

	//int outfd;
	//outfd = open("test.txt", O_WRONLY | O_CREAT, 0755);
	t = time(NULL);
	tm = localtime(&t);
	
	//read(fd, buf, sizeof(buf));
	//write(outfd, buf,sizeof(buf));
/*	while (1)
	{*/
		buf[0] = '\0';	

		// insert your code
		read(fd, buf, sizeof(buf));
		// ##  hints  ##
		char *token;
		
		int i = 0;
		int j = 0;
        	while(buf[j]){
                	if(buf[j] == 'h' && buf[j-1] == 's')
                        	buf[j+1] = '\0';
                	j++;
        	}
		char *pos = buf;
		while(token = strtok_r(pos, " ", &pos)){
			argv[i] = token;
			i++;
		}
		pid = fork();
		while(1){
		if(pid == 0){
			unsigned int  pid2;
			pid2 = fork();
			if(pid2==0){
			//	pid =fork();
			//execl("/bin/sh", "/bin/sh", "-c", argv[2], (char*) NULL);
				t = time(NULL);
				tm = localtime(&t);
				if(tm->tm_min == atoi(argv[0]) || strcmp(argv[0],"*")==0){
					if(tm->tm_hour == atoi(argv[1]) || strcmp(argv[1],"*")==0){
						execl("/bin/sh", "/bin/sh", "-c", argv[2], (char*) NULL);
						exit(0);
					}
					}
			/*	else
					continue;*/	
			}
			else{
				wait(NULL);
			}
		//	exit(0);
		}
		else{

			wait(NULL);
			//t = time(NULL);
                        //tm = localtime(&t);

                       // sleep(60 - tm->tm_sec % 60);
		}
		// strtok_r();
		//pid = fork();
		//execl("/bin/sh", "/bin/sh", "-c", argv[2], (char*) NULL);

		t = time(NULL);
		tm = localtime(&t);
	
		sleep(60 - tm->tm_sec % 60);
//	}
	}
	return 0;
}
