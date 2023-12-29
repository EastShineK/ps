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
//	printf("1000원 : %d개\n", thoun);
//	printf("500원 : %d개\n", fiveh);
//	printf("100원 : %d개\n", oneh);
//	printf("50원 : %d개\n", fif);
//	printf("10원 : %d개\n", ten);
//
//	return 0;
//}