//#include<stdio.h>
//
//int main()
//{
//	float num[7];
//	float max, min, avg, sum = 0;
//	
//	for (int i = 0; i < 7; i++)
//	{
//		scanf_s("%f", &num[i]);
//	}
//	
//	max = 0;
//	min = num[0];
//	
//	for (int i = 0; i < 7; i++)
//	{
//		if (num[i] > max)
//		{
//			max = num[i];
//		}
//		else if (num[i] < min)
//		{
//			min = num[i];
//		}
//		else
//			sum = sum + num[i];
//	}
//
//	if (min != num[0] && max != num[0])
//		sum = sum + num[0];
//	
//	avg = sum / 5;
//
//	printf("MAX : %.1f\n", max);
//	printf("MIN : %.1f\n", min);
//	printf("AVG : %.2f", avg);
//
//	return 0;
//}