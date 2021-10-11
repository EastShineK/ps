#include<sys/types.h>
#include<stdlib.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>  // 나중에 지워야함 오류확인용

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
	int infd;
	char buf[1];
	char buf2[150][100];
	char saveLine[1024];
	char ch;
	int Idx = 0;
	int len, nbytes = 1;
	int number = 1;

//단어 형식:한 단어 위치 찾기 라인넘버&인덱스 출력  clear
//단어 단어 형식: 2개 이상의 단어가 포함되어 있는 라인넘버 출력 순서상관없음
//"단어 단어"형식: 라인넘버&start인덱스
//단어*단어형식: 두 단어 사이에 하나 이상의 단어가 포함되어 있는 라인출력
//대문자 소문자 구분안함

	while(1){
	
		int lineNumber = 1;
		int wordNumber = 0, wordIndex = 0;
		int k = 0;
		int imple = 1, check = 0, NumW;
		for(int i = 0; i < 150; i++){
			for(int j = 0; j < 100; j++){
				buf2[i][j] = 0;
			}
		}

		if((infd = open(argv[1], O_RDONLY)) < 0){
                        perror("open");
                        exit(1);
        	}


		while(read(0, &ch, 1)){ //implementation 입력 받기
			if(ch == '\n'){
				buf2[wordNumber][Idx++] = '\0';
				if(wordNumber > 0)
					NumW = wordNumber + 1;
				Idx = 0;
				wordNumber = 0;
				break;
			}
			else{
				if(ch == 42){//* 
					//printf("hi1\n");
					buf2[wordNumber][Idx++] = '\0';
					Idx = 0;
					wordNumber++;
					imple = 4;
				}
				else if(ch == 32){//' '
					buf2[wordNumber][Idx++] = '\0';
					Idx = 0;
					wordNumber++;
					if(buf2[0][0] != 34)
						imple = 2;
					else
						imple = 3;
					//printf("hi3\n");
				}
				else{
					buf2[wordNumber][Idx++] = ch;
				}				
			}
		}
		//printf("%d ", imple);
		//printf("%s\n", buf2); 
		// check OK
		
		if(wordNumber == 0){
			for(int v = 0; v < 100; v++){
				if(buf2[0][v] == 0){
					len = v;
					break;
				}
			}
		}


		nbytes = 1;

		while(nbytes != 0){		
			//printf("kakakaka\n");
			for(int i = 0; ;i++){
				//printf("jajaj\n");
				nbytes = read(infd, buf, sizeof(buf));
				saveLine[k] = buf[0];			
				k++;
				//printf("qiqiqiqiq\n");
				if(buf[0] == '\n'){
					//printf("vavavav\n");
					saveLine[k-1] = '\0';
					//printf("%d %d %d\n", lineNumber, imple, nbytes);
					if(imple == 1){ // word
						int ans = 0;
						int j = 0;
						for(j ; j < k; j++){
							if(disting(buf2[0][0], saveLine[j])){
								wordIndex = j;
								
								if(j > 0 && saveLine[j-1] != 32  /*saveLine[j-1] != 0*/)
									continue;
								for(int c = 0; c < len; c++){
									if(disting(buf2[0][c], saveLine[j])){
										j++;
										ans = 1;
										//if(lineNumber = 106)
										//	printf("%d %d hi\n", lineNumber, j);
										 if(buf2[0][c+1] == '\0'){
                                                                                             
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
						if(saveLine[0] == '\0'){
							k = 0;
                                        		wordIndex = 0;
                                		        lineNumber++;
                 	   	                    	break;
						}
		
						//printf("%d come\n", lineNumber);
						int x = 0;
						int ans = 0;
						int count = 0, ansCount = 0;
						int startIdx = 0, endIdx;
						int t, saveNull = 0;
						//printf("%d\n", lineNumber);
						//printf("%d come in\n", lineNumber);
						while(1){
							//printf("jale\n");
							count++;
							for(t = startIdx; buf2[t] != '\0'; t++){
								if(buf2[t] == 32){
									//printf("hi22\n");
									break;
								}
							}//단어 길이 찾기
							endIdx = t;
							//printf("%s\n", saveLine);
							//printf("sI eI : %d %d\n", startIdx, endIdx);
							for(int s = startIdx; s < endIdx; s++){
								//while(saveLine[x] != '\0')
									//if(lineNumber == 50 || lineNumber == 60)
										//printf("ans : %d %d %d\n", lineNumber, startIdx, endIdx);
								
									if(disting(buf2[s], saveLine[x])){
										x++;
										//printf("helloworld\n");
										if(s == endIdx - 1){

											if(lineNumber == 50 || lineNumber == 60)
                                                                                		printf("ans : %d %d %d %c %c\n", lineNumber, startIdx, endIdx, buf2[s], saveLine[x-1]);
											if(saveLine[x] == 32 || saveLine[x] == '\0'){
												//printf("ans : %d %d %d\n", lineNumber, startIdx, endIdx);
												ans = 1;
												x++;
												break;
											}
											else{
												ans = 0;
												s = startIdx;
												while(saveLine[x-1] != 32){
                                                                                        		x++;
                                                                                        		if(saveLine[x] == '\0'){
                                                                                                		saveNull = 1;
                                                                                                		break;
                                                                                        		}
                                                                                		}

												break;
											}
										}

									}
									else{
										//printf("%c\n", buf2[s]);
										//printf("%c\n", saveLine[x]);
										s = startIdx;
										
										do{
											//printf("come here\n");
											x++;
											if(saveLine[x] == '\0'){
												saveNull = 1;
												break;
											}
										}while(saveLine[x-1] != 32);
									}
								//}//while saveLine != null
								/*if(ans == 1)
									break;*/
								//printf("saveNull : %d\n", saveNull);
								if(saveNull == 1){
									saveNull = 0;
									break;
								}
							}//saveLine 처음부터 훑어보면서 단어 찾기
							if(ans == 1){
								//printf("ansC: %d\n", lineNumber);
								ansCount++;
							}
							startIdx = t + 1;
							//printf("%d, %d\n", startIdx, endIdx);
							/*if(saveNull==1){
								saveNull = 0;
								break;
							}*/
							//printf("hi\n");
							if(buf2[startIdx] == '\0')
								break;
							if(buf2[endIdx] == '\0'){
                                                        	//printf("hi\n");
								break;
							}
						}//while(1) end
						if(lineNumber == 60 || lineNumber == 50)
							printf("%d %d\n", count, ansCount);
						//printf("%d come in 474\n", lineNumber);	
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
						}//단어의 갯수와 실제 있는 단어의 갯수 비교
						count = 0;
						ansCount = 0;		
						//printf("%d come in 84645\n", lineNumber);
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
				}//if buf[n] == '\n'
				//printf("h2222i\n");
				
			}//for end
			//printf("cocococo\n");
		} // while nbytes check end
		//printf("lalalal\n");
		//inp_size = 0;
		//printf("\n");
		write(1, "\n", 1);
	}//while 1 end
	
	close(infd);

	return 0;
}
