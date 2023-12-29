#include <stdio.h>
int main() {

	int GM = 0;
	int bn, in=1, kn=1, cn=1;
	
	
	while (1) 
	{
		scanf("%d", &GM);

		if (GM < 3000) {
			printf("You must enter more than 3,000.\n");
			continue;
		}
		else if (GM % 100 != 0) {
			printf("The monetary unit should be 100 won.\n");
			continue;
		}
		else {
			for (bn = 1; 500 * bn + 700 * in + 400 * kn + 100 * cn <= GM; bn++) {
				for (in = 1; 500 * bn + 700 * in + 400 * kn + 100 * cn <= GM; in++) {
					for (kn = 1; 500 * bn + 700 * in + 400 * kn + 100 * cn <= GM; kn++) {
						for (cn = 1; 500 * bn + 700 * in + 400 * kn + 100 * cn <= GM ; cn++) {
							if (500 * bn + 700 * in + 400 * kn + 100 * cn == GM) {
								printf("Bread(%d), Icecream(%d), Coke(%d), Coffee(%d)\n", bn, in, kn, cn);
							}														
						}
						cn = 1;
					}
					kn = 1;
				}
				in = 1;
			}
			
		}
		break;
	}
	return 0;
}