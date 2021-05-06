#include <stdio.h>

int main() {

	int arr1[2][2] = { { 0, }, { 0, } };
	int arr2[2][2] = { { 0, }, { 0, } };
	int arr3[2][2] = { { 0, }, { 0, } };

	printf("Enter First Matrix : ");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			scanf(" %d", &arr1[i][j]);
		}
	}

	printf("Enter Second Matrix : ");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			scanf("%d", &arr2[i][j]);
		}
	}

	printf("The first Matrix is :\n");
	printf("  %d    %d  \n", arr1[0][0], arr1[0][1]);
	printf("  %d    %d  \n", arr1[1][0], arr1[1][1]);

	printf("The Second Matrix is :\n");
	printf("  %d    %d  \n", arr2[0][0], arr2[0][1]);
	printf("  %d    %d  \n", arr2[1][0], arr2[1][1]);
	printf("\n");

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			arr3[i][j] = arr1[i][0] * arr2[0][j] + arr1[i][1] * arr2[1][j];
		}
	}

	printf("Multiplication Of Two Matrices :\n");
	printf("  %d    %d  \n", arr3[0][0], arr3[0][1]);
	printf("  %d    %d  \n", arr3[1][0], arr3[1][1]);


	return 0;
}