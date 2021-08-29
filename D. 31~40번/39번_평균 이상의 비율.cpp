//#include<stdio.h>
//
//int main()
//{
//	int num, sum = 0, avg;
//	int score[30];
//	float cnt = 0, per;
//
//	scanf_s("%d", &num);
//
//	for (int i = 0; i < num; i++)
//	{
//		scanf_s("%d", &score[i]);
//		sum = sum + score[i];
//	}
//	avg = sum / num;
//
//	for (int i = 0; i < num; i++)
//	{
//		if (score[i] >= avg)
//			cnt++;
//	}
//
//	per = cnt / (float)num * 100;
//
//	printf("%d\n", avg);
//	printf("%.2f%%", per);
//
//	return 0;
//}