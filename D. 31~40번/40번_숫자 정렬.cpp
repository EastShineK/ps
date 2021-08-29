//#include<stdio.h>
//
//int main()
//{
//	int num[10], temp;
//
//	for (int i = 0; i < 10; i++)
//	{
//		scanf_s("%d", &num[i]);
//	}
//
//	for (int i = 0; i < 9; i++)
//	{
//		for (int j = i + 1; j < 10; j++)
//		{
//			if (num[i] > num[j])
//			{
//				temp = num[i];
//				num[i] = num[j];
//				num[j] = temp;
//			}
//		}
//	}
//	
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d\n", num[i]);
//	}
//
//
//
//	return 0;
//}