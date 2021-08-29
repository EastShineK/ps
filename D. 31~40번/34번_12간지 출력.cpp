//#include<stdio.h>
//
//int main()
//{
//	int year;
//
//	scanf_s("%d", &year);
//
//	//char sg[10] = { '갑', '을', '병', '정', '무', '기', '경', '신', '임', '계' };
//	//char sg[20] = { '갑', '을', '병', '정', '무', '기', '경', '신', '임', '계' };
//	char sg[21] = "갑을병정무기경신임계";
//	//char seg[12] = { '자', '축', '인', '묘', '진', '사', '오', '미', '신', '유', '술', '해' };
//	char seg[25] = "자축인묘진사오미신유술해";
//	
//	/*for (int i = 0; i < 20; i++)
//	{
//		//printf("%c%c", sg[i],sg[i+1]);
//		putchar(sg[i]);
//	}*/
//	putchar(sg[((year+6) % 10) * 2]);
//	putchar(sg[((year + 6) % 10) * 2 + 1]);
//
//	putchar(seg[((year + 8) % 12) * 2]);
//	putchar(seg[((year + 8) % 12) * 2 + 1]);
//	//printf("%c%c", sg[year % 9], sg[year % 9 + 1]);
//	//printf("%c%c", seg[year % 11], seg[year % 11 + 1]);
//	//printf("%c%c년", sg[year % 9], seg[year % 11]);
//	printf("년");
//
//	return 0;
//}