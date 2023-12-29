#include <stdio.h>

int main(void)
{
	int mm, mf, em, ef;
	int sm, se;
	float am, ae;

	scanf("%d %d %d %d", &mm, &mf, &em, &ef);
	sm = mm + mf;
	se = em + ef;
	am = sm / 2;
	ae = se / 2;


	printf("Subject	Sum Avg\n");
	printf("Math	%d %.2f\n", sm, am );
	printf("English	%d %.2f\n", se, ae );
	return 0;
}
