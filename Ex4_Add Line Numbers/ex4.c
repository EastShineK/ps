#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>

void ITOA(char *c, int n){
	int rad = 10;
	int count = 0;
	int deg = 1;

	while(1){
		if(n/deg>0)
			count++;
		else
			break;
		deg=deg*rad;
	}
	deg=deg/rad;

	for(int i = 0; i < count; i++){
		*(c+i)=(n/deg)+'0';
		n = n - (n/deg)*deg;
		deg = deg / rad;
	}

	*(c+count) = '\0';
}

int main(int argc, char **argv){
	int infd, outfd;
	char buf[1];
	int nbytes=1;
	int number = 1;

	if ((infd = open(argv[1], O_RDONLY)) < 0) {
		perror("open");
		exit(1);
	}

	outfd = open("Aladdin_num.txt", O_WRONLY | O_CREAT, 0755);
	char n[5];
       
	while(nbytes != 0){

		int k=1;
		int numberCopy;
		numberCopy = number;
		ITOA(n, number);
		while(1){
			numberCopy = numberCopy / 10;
			if(numberCopy > 0)
				k++;
			else
				break;
		}
                write(outfd,n,k);
                number++;

                char ok[3] = " | ";
                write(outfd,ok,sizeof(ok));

		for(int i = 0; ; i++){
                	nbytes = read(infd, buf, sizeof(buf));
                	//printf("%d\n", i);
                	//printf("%c\n", buf[0]);
                	write(outfd,buf,nbytes);
			if(buf[0] == '\n')
                        	break;
        	}
     
	}

	close(infd);
	close(outfd);
}
