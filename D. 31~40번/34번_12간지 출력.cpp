//#include<stdio.h>
//
//int main()
//{
//	int year;
//
//	scanf_s("%d", &year);
//
//	//char sg[10] = { '��', '��', '��', '��', '��', '��', '��', '��', '��', '��' };
//	//char sg[20] = { '��', '��', '��', '��', '��', '��', '��', '��', '��', '��' };
//	char sg[21] = "���������������Ӱ�";
//	//char seg[12] = { '��', '��', '��', '��', '��', '��', '��', '��', '��', '��', '��', '��' };
//	char seg[25] = "�����ι�������̽�������";
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
//	//printf("%c%c��", sg[year % 9], seg[year % 11]);
//	printf("��");
//
//	return 0;
//}