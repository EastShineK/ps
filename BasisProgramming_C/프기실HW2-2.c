#include <stdio.h>

int gcd(int x, int y);

int main() {

	int num1, num2;

	printf("Input two numbers: ");
	scanf("%d %d", &num1, &num2);

	printf("GCD of these two number: %d", gcd(num1, num2));

	return 0;
}

int gcd(int x, int y)
{
	if (y == 0)
	{
		return x;
	}
	else
	{
		return gcd(y, x % y);
	}
}