//#include<stdio.h>
//
//int main()
//{
//	int n, m, remain, thoun = 0, fiveh = 0, oneh = 0, fif = 0, ten = 0;
//
//	do {
//		scanf_s("%d", &n);
//		scanf_s("%d", &m);
//	} while (n > m);
//
//	remain = m - n;
//
//	while (remain - 1000 >= 0)
//	{
//		remain = remain - 1000;
//		thoun++;
//	}
//	while (remain - 500 >= 0)
//	{
//		remain = remain - 500;
//		fiveh++;
//	}
//	while (remain - 100 >= 0)
//	{
//		remain = remain - 100;
//		oneh++;
//	}
//	while (remain - 50 >= 0)
//	{
//		remain = remain - 50;
//		fif++;
//	}
//	while (remain - 10 >= 0)
//	{
//		remain = remain - 10;
//		ten++;
//	}
//
//	printf("1000�� : %d��\n", thoun);
//	printf("500�� : %d��\n", fiveh);
//	printf("100�� : %d��\n", oneh);
//	printf("50�� : %d��\n", fif);
//	printf("10�� : %d��\n", ten);
//
//	return 0;
//}