//#include<stdio.h>
//
//int main()
//{
//	int num[10];
//	int cnt = 0;
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
//				cnt++;
//				break;
//			}
//		}
//		if (cnt > 0)
//			break;
//	}
//
//
//
//
//	if (cnt == 0)
//		printf("Sorted\n");
//	else
//		printf("Not Sort\n");
//
//	return 0;
//}