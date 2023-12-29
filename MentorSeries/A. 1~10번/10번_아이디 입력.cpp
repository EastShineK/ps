//#include<stdio.h>
//
//int main()
//{
//	char id[10];
//	int alp = 0, num = 0, sword = 0;
//
//	printf("¾ÆÀÌµð : ");
//	scanf_s("%s", id, 10);
//
//	for (int i = 0; i < 10; i++)
//	{
//		if (id[i] >= 65 && id[i] <= 90)
//			alp++;
//		else if (id[i] >= 97 && id[i] <= 122)
//			alp++;
//		else if (id[i] >= 48 && id[i] <= 57)
//			num++;
//		else if (id[i] >= 33 && id[i] <= 47)
//			sword++;
//	}
//
//	if (alp != 0 && num != 0 && sword != 0)
//	{
//		printf("%s", id);
//	}
//	else
//	{
//		printf("Error");
//	}
//
//	return 0;
//}