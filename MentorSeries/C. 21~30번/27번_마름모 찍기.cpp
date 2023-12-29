//#include<stdio.h>
//
//int main()
//{
//	int n;
//	int i, j;
//
//	scanf_s("%d", &n);
//
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j <= n + i; j++)
//		{
//			if (j >= n - i)
//				printf("*");
//			else
//				printf(" ");
//		}
//		printf("\n");
//	}
//
//	for (i = i - 1; i > 0; i--)
//	{
//		for (j = 0; j < n + i; j++)
//		{
//			if (j <= n - i)
//				printf(" ");
//			else
//				printf("*");
//		}
//		printf("\n");
//	}
//
//	return 0;
//}