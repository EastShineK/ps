//#include<stdio.h>
//
//int main()
//{
//	int n, sum = 0;
//
//	printf("수를 입력 : ");
//	scanf_s("%d", &n);
//	printf("처리조건(A : 홀수의 합, B : 짝수의 합, C : 전체의 합) : ");
//	getchar();
//	char con = getchar();
//
//	printf("1");
//	if (con == 'A')
//	{
//		for (int i = 1; i <= n; i=i+2)
//		{
//			sum = sum + i;
//			if(i != 1)
//				printf(", %d", i);
//		}
//	}
//	else if (con == 'B')
//	{
//		for (int i = 2; i <= n; i = i + 2)
//		{
//			sum = sum + i;
//			if (i != 1)
//				printf(", %d", i);
//		}
//	}
//	else if (con == 'C')
//	{
//		for (int i = 1; i <= n; i++)
//		{
//			sum = sum + i;
//			if (i != 1)
//				printf(", %d", i);
//		}
//	}
//	else
//		printf("Error\n");
//
//	printf("\n합 : %d", sum);
//
//	return 0;
//}