//#include<stdio.h>
//
//int main()
//{
//	int n, bas = 0;
//
//	scanf_s("%d", &n);
//
//	for (int i = n; i < 2*n; i++)
//	{
//		for (int j = 2; j < i; j++)
//		{
//			if (i % j == 0)
//			{
//				bas = 1;
//				break;
//			}
//		}
//		if (i == 2 || i == 3)
//		{
//			printf("%d\n", i);
//		}
//		else if (bas == 0)
//			printf("%d\n", i);
//		bas = 0;
//	}
//
//	return 0;
//}