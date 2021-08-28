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
//		for (j = 0; j < n - i; j++)
//		{
//			if (j == 0 || j == n - i - 1)
//				printf("*");
//			else
//				printf(" ");
//		}
//		printf("\n");
//	}
//	printf("\n");
//	printf("\n");
//
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < 2*n - 1 - i; j++)
//		{
//			if (j < i)
//				printf(" ");
//			else if(j == i || j == 2 * n - 2 - i)
//				printf("*");
//			else
//				printf(" ");
//		}
//		printf("\n");
//	}
//	printf("\n");
//	printf("\n");
//
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n + i; j++)
//		{
//			if (j < n -1 - i)
//				printf(" ");
//			else if (j == n - 1 - i || j == n - 1 + i )
//				printf("*");
//			else
//				printf(" ");
//		}
//		printf("\n");
//	}
//	printf("\n");
//	printf("\n");
//
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < 2 * n - 1 - i; j++)
//		{
//			if (j < i)
//				printf(" ");
//			else if (j == i || j == 2 * n - 2 - i || j == n -1)
//				printf("*");
//			else
//				printf(" ");
//		}
//		printf("\n");
//	}
//	printf("\n");
//	printf("\n");
//
//
//
//	return 0;
//}