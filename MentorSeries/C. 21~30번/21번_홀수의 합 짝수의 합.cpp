//#include<stdio.h>
//
//int main()
//{
//	int n, sum = 0;
//
//	printf("���� �Է� : ");
//	scanf_s("%d", &n);
//	printf("ó������(A : Ȧ���� ��, B : ¦���� ��, C : ��ü�� ��) : ");
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
//	printf("\n�� : %d", sum);
//
//	return 0;
//}