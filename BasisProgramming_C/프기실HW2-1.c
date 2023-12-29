#include <stdio.h>


int main() {

	int base, num;
	int count = 0;

	while (1)
	{
		
		printf("Please enter the base of the log (It is terminated if the input is below 1)\n");
		scanf("%d", &base);
		if (base < 1)
		{
			break;
		}
		else
		{
			printf("Please enter the logarithm of a given number\n");
			scanf("%d", &num);
			do
			{
				num = num / base;
				count++;
				
				
			} while (num / base > 0);
			
			printf("The integer number of the given logarithm is %d.\n\n", count);
			count = 0;
		}
	}
	
	return 0;
}
