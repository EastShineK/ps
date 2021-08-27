//#include<stdio.h>
//
//int main()
//{
//	int N, M, bN;
//	int bin[100];
//	int k = 0;
//	
//	scanf_s("%d %d", &N, &M);
//	bN = N;
//
//	while (N != 0)
//	{
//		bin[k] = N % M;
//		N = N / M;
//		if (10 <= bin[k])
//			bin[k] = bin[k] + 55;
//		k++;
//	}
//
//	printf("DEC : %d\n", bN);
//
//	printf("Base %d : ", M);
//	for (int i = k - 1; i >= 0; i--)
//	{
//		printf("%d", bin[i]);
//	}
//
//	return 0;
//}