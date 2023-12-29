#include <stdio.h>

int main() {

	while (1)
	{
		int Sn;
		float Es, Ks, Ms, x;
		int CoS;

		printf("Enter the student number, eng, korean, math: ");
		scanf("%d %f %f %f", &Sn, &Es, &Ks, &Ms);

		printf("Student number is %d\n", Sn);
		printf("English score is %.2f\n", Es);
		printf("Korean score is %.2f\n", Ks);
		printf("Math score is %.2f\n", Ms);

		x = (Es + Ks + Ms) / 3;
		printf("Your average is %.2f\n", x);

		if (x <= 100 && x >= 90)
		{
			printf("Your grade is A\n");
		}
		else if (x < 90 && x >= 80)
		{
			printf("Your grade is B\n");
		}
		else if (x < 80 && x >= 70)
		{
			printf("Your grade is C\n");
		}
		else if (x < 70 && x >= 60)
		{
			printf("Your grade is D\n");
		}
		else if (x < 60 && x >= 0)
		{
			printf("Your grade is F\n");
		}
		else
		{
			break;
		}

		printf("Do you want to continue?");
		scanf("%d", &CoS);

		if (CoS == 0)
		{
			printf("GoodBye");
			break;
		}
		else if (CoS == 1)
		{
			printf("Continue\n\n");
			continue;
		}
		else
		{
			break;
		}
	}

	return 0;
}