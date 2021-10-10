#include<sys/types.h>
#include<stdlib.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>  // 나중에 지워야함 오류확인용

#define inpSize 1024

void ITOA(char *c, int n){
	int rad = 10;
	int count = 0;
	int deg = 1;
	if(n==0){
		*c = '0';
		*(c+1) = '\0';
	}
	else{
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
			deg=deg/rad;
		}

		*(c+count)='\0';
	}
}

int disting(char a, char b){
	
	if(a == b)
		return 1;
	else if(a == b + 32)
		return 1;
	else if(a == b - 32)
		return 1;
	else
		return 0;
}

int checkWordStartEnd(char a, char b){
	if(a == 32 && b == 32)
		return 0;
	else if(a == 32 && b == '\0')
		return 0;
	else if(a == '\0' && b == 32)
		return 0;
	else if(a == '\0' && b == '\0')
		return 0;
	else if(a != 32 && b == 32)
                return 1;
        else if(a != 32 && b == '\0')
                return 1;
        else if(a != '\0' && b == 32)
                return 1;
        else if(a != '\0' && b == '\0')
                return 1;

	/*else
		return 1;*/
}

int main(int argc, char **argv){
	int infd, outfd;
	char buf[1];
	char buf2[inpSize];
	char saveLine[1024];
	char ch;
	int inp_size = 0;
	int nbytes = 1;
	int number = 1;

//단어 형식:한 단어 위치 찾기 라인넘버&인덱스 출력  clear
//단어 단어 형식: 2개 이상의 단어가 포함되어 있는 라인넘버 출력 순서상관없음
//"단어 단어"형식: 라인넘버&start인덱스
//단어*단어형식: 두 단어 사이에 하나 이상의 단어가 포함되어 있는 라인출력
//대문자 소문자 구분안함
	while(1){
	
		int lineNumber = 1;
		int wordIndex = 0;
		int k = 0;
		int imple = 1, check = 0;
		while(read(0, &ch, 1)){ //implementation 입력 받기
			if(ch == '\n'){
				buf2[inp_size] = '\0';
				break;
			}
			else{
				buf2[inp_size++] = ch;
				if(ch == 42  && check == 0){ 
					//printf("hi1\n");
					imple = 4;
					check = 1;
				}
				else if(ch == 34 && check == 0){ 
					//printf("hi2\n");
					imple = 3;
					check = 1;
				}
				else if(ch == 32 && check == 0){
					imple = 2;
					check = 1;
					//printf("hi3\n");
				}				
			}
		}
		//printf("%d ", imple);
		//printf("%s\n", buf2); 
		// check OK
	
		if((infd = open(argv[1], O_RDONLY)) < 0){
                	perror("open");
                	exit(1);
        	}
		nbytes = 1;

		while(nbytes != 0){		
			for(int i = 0; ;i++){
				nbytes = read(infd, buf, sizeof(buf));
				saveLine[k] = buf[0];			
				k++;
				if(buf[0] == '\n'){
					saveLine[k-1] = '\0';
					if(imple == 1){ // word
						int ans = 0;
						int j = 0;
						for(j ; j < k; j++){
							if(disting(buf2[0], saveLine[j])){
								wordIndex = j;
								
								if(j > 0 && saveLine[j-1] != 32  /*saveLine[j-1] != 0*/)
									continue;
								for(int c = 0; c < inp_size; c++){
									if(disting(buf2[c], saveLine[j])){
										j++;
										ans = 1;
										//if(lineNumber = 106)
										//	printf("%d %d hi\n", lineNumber, j);
										 if(buf2[c+1] == '\0'){
                                                                                             
											 if(saveLine[j] == 32||saveLine[j] == '\0'){
                                                                                                       ans = 1;
                                                                                                       break;
                                                                                               }
                                                                                               else{
                                                                                                       ans = 0;
                                                                                                       break;
                                                                                               }
                                                                                }
		
									}
									else{
										//if(lineNumber = 106)
										//	printf("sorry\n");
										ans = 0;
										break;
										
									}
								}//for c end
							}//if end
							if(ans == 1){
								char Line[5];
								ITOA(Line, lineNumber);
								char Index[3];
								ITOA(Index, wordIndex);
								int lineCopy = lineNumber;
								int wordCopy = wordIndex;
								int sizeL = 1, sizeI = 1;
								while(1){
									lineCopy = lineCopy / 10;
									if(lineCopy > 0)
										sizeL++;
									else 
										break;
								}
								while(1){
                                                                        wordCopy = wordCopy / 10;
                                                                        if(wordCopy > 0)
                                                                                sizeI++;
                                                                        else
                                                                                break;
                                                                }
								write(1,Line, sizeL);
								write(1, ":", 1);
								write(1, Index, sizeI);
								write(1, " ", 1);
								ans = 0;
								break;
							}
						} // for j end					
					}
					else if(imple == 2){ // word word
						int u = 0;
						int x = 0;
						int ans = 0;
						int count = 0, ansCount = 0;
						while(buf2[u] != '\0'){
							count++;
							int KT = u;
							while(buf2[u] != 32){
								while(saveLine[x] != '\0'){
									if(disting(buf2[u], saveLine[x])){
										u++;
										x++;
										ans = 1;
										if(lineNumber == 36){
											printf("buf2[u] saveLine[x] : %d %d\n", buf2[u], saveLine[x]);
											printf("buf2[u-2] saveLine[x-2] : %d %d\n", buf2[u-2], saveLine[x-2]);
											printf("u x : %d %d\n", u, x);
										}
										
										if(checkWordStartEnd(buf2[u-2], saveLine[x-2])){
											if(lineNumber == 36){
                                                                                        	printf("In : %d %d\n", buf2[u-2], saveLine[x-2]);
                                                                                		printf("In u x : %d %d\n", u, x);
											}

											ans = 0;
											u = KT;
											x++;
										}
										if((buf2[u] == 32 && saveLine[x] == 32) || (buf2[u] == '\0' && (saveLine[x] == 32 || saveLine[x] == '\0')))
                                                                                        break;

									}
									else{
										u = KT;
										x++;
										ans = 0;
									}
								}// while saveLine null
								if(lineNumber == 36)
									printf("count, ans : %d %d %d\n", count, ansCount, ans);	
								if(ans == 1){
									ansCount++;
									x = 0;
									break;
								}
								//u++;
								if(saveLine[x] == '\0')
									break;
								
							}//while 32
							if(lineNumber == 36)
                                                                        printf("count : %d %d\n", count, ansCount);
							if(ans == 1 && buf2[u] == '\0')
								break;
							u++;
						} // while null
						if(count == ansCount){
							char Line[5];
                                                        ITOA(Line, lineNumber);
							int lineCopy = lineNumber;
                                                        int sizeL = 1;
                                                        while(1){
                                                                lineCopy = lineCopy / 10;
                                                                if(lineCopy > 0)
                                                                        sizeL++;
                                                                else
                                                                        break;
                                                        }
							write(1,Line, sizeL);
							write(1," ", 1);
							//break;
						}
						count = 0;
						ansCount = 0;

					}//imple 2 endl
					else if(imple == 3){ // word*word
						
					}
					else if(imple == 4){ // double quotation and word

					}
					//printf("korea\n");	
					k = 0;
					wordIndex = 0;
					lineNumber++;
					break;
				}
				
			}//for end
		} // while nbytes check end

		inp_size = 0;
		//printf("\n");
		write(1, "\n", 1);
	}//while 1 end
	
	close(infd);

	return 0;
}
