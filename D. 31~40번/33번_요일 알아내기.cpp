//#include<stdio.h>
//
//int main()
//{
//	int month, day;
//
//	scanf_s("%d", &month);
//	scanf_s("%d", &day);
//
//	printf("2018-%d-%d\n", month, day);
//
//	if (month > 1)
//	{
//		for (int i = 1; i < month; i++)
//		{
//			if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
//				day = day + 31;
//			else if (i == 2)
//				day = day + 28;
//			else
//				day = day + 30;
//		}
//	}
//	
//	if (day % 7 == 0)
//		printf("SUN");
//	else if (day % 7 == 1)
//		printf("MON");
//	else if (day % 7 == 2)
//		printf("TUE");
//	else if (day % 7 == 3)
//		printf("WED");
//	else if (day % 7 == 4)
//		printf("THU");
//	else if (day % 7 == 5)
//		printf("FRI");
//	else if (day % 7 == 6)
//		printf("SAT");
//	return 0;
//}