#include <stdio.h>
#include <stdlib.h>

int main() {

	int seed;
	int arr[10][10] = { {0,}, {0,}, {0,}, {0,}, {0,}, {0,}, {0,}, {0,}, {0,}, {0,} };
	int k, temp;
	int n = 0;

	printf("Enter a seed : ");
	scanf("%d", &seed);

	srand(seed);

	printf("Created matrix: \n");

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			k = (rand() % 11) + 10;
			arr[i][j] = k;
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	printf("Sorted matrix: \n");
	for (int s = 0; s < 10; s++)
	{
		for (int k = 0; k - s - 1 < 10 ; k++) 
		{
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 9 ; j++)
				{
					if (arr[i][j] > arr[i][j + 1])
					{
						temp = arr[i][j];
						arr[i][j] = arr[i][j + 1];
						arr[i][j + 1] = temp;
					}
				}
			}
		}
	}
	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	printf("Unique value count: \n");
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				if (arr[j][k] == i + 10)
				{
					n = n + 1;
				}
			}
		}
		printf("%d : %d\n", i + 10, n);
		n = 0;
	}


	return 0;
}