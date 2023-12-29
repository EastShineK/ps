#include <stdio.h>
#include <stdlib.h>

int main() {

	int seed, wid, num;
	int i, k;

	printf("Enter a seed value : ");
	scanf("%d", &seed);

	while (1)
	{
		printf("Type the width of the figure from 1 to 5 or type 0 if you want to quit\n");
		scanf("%d", &wid);
		if (wid == 0)
		{
			break;
		}
		else if (wid > 5 || wid < 1)
		{	do {
				printf("Type the proper width from 1 to 5!\n");
				scanf("%d", &wid);
				} while (wid > 5 || wid < 1);
		}
		
		num = rand() % 10 + 1;

		for (i = 1; i <= wid; i++) 
		{
			for (k = 0; k <= wid-i; k++)
			{				
				printf("  %d", num);
			}
			printf("\n");
		}

	}
	
	return 0;
}