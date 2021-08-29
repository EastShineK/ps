//#include<stdio.h>
//
//int main()
//{
//	int num, score[30], rank[30], temp;
//
//	scanf_s("%d", &num);
//
//	for (int i = 0; i < num; i++)
//	{
//		scanf_s("%d", &score[i]);
//		//rank[i] = score[i];
//		rank[i] = 1;
//	}
//
//	for (int i = 0; i < num ; i++)
//	{
//		for (int j = 0; j < num; j++)
//		{
//			if (score[i] < score[j])
//			{
//				rank[i]++;
//			}
//		}
//	}
//
//	for (int i = 0; i < num; i++)
//	{
//		printf("%d	%d\n", score[i], rank[i]);
//	}
//	
//
//	return 0;
//}