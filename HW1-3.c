#include <stdio.h>

int main(void)
{
	int Number, s;
	int not = 0;
	
	
	while ( 1 )
	{
		scanf("%d", &Number);
		
		if (Number < 2) {
			printf("Invalid Input\n");
			continue;
		}
		else{
			for (s = 2; Number >= s; s++) {
				while (Number % s == 0) {
					not = not + 1;
					Number = Number / s;

				}
				if (not != 0)
					printf("%d^%d ", s, not);

				not = 0;
			}

		}
		break;
	}

	return 0;
}