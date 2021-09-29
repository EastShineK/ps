#include<sys/types.h>
#include<stdlib.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc char **argv){
	int infd, outfd;
	char buf[1];
	int nbytes = 1;
	int number = 1;

//단어 형식:한 단어 위치 찾기 라인넘버&인덱스 출력
//단어 단어 형식: 2개 이상의 단어가 포함되어 있는 라인넘버 출력 순서상관없음
//"단어 단어"형식: 라인넘버&start인덱스
//단어*단어형식: 두 단어 사이에 하나 이상의 단어가 포함되어 있는 라인출력
//대문자 소문자 구분안함
	if((infd = open(argv[1], O_RDONLY)) < 0){
		perror("open");
		exit(1);
	}

	while(1){
	
		int lineNumber = 1;
		int wordIndex = 0;

		while(nbytes != 0){
		
			for(int i = 0; ;i++){
				nbytes = read(infd, buf, sizeof(buf));
				if(buf[0] == ' '){
					wordIndex++;
				}
				if(buf[0] == '\n'){
					lineNumber++;
					break;
				}
			}//for end
		} // while nbytes check end
	}//while 1 end
	
	close(infd);

	return 0;
}
