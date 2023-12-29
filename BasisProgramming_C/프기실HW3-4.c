#include <stdio.h>
#include <math.h>

float getsdv(int* source, int size);

int main() {

	int size;
	int arr[10] = { 0, };
	

	printf("Enter array size : ");
	scanf("%d", &size);

	printf("Enter %d elements : ", size);
	for (int i = 0; i < size; i++)
	{
		scanf("%d", arr + i);
	}
	
	printf("Standard Deviation = %.2lf", getsdv(arr, size));

	return 0;
}

float getsdv(int* source, int size)
{
	float sum = 0;
	float avg, var = 0, dev;

	for (int i = 0; i < size; i++)
	{	
		sum = sum + *(source + i);
	}
	
	avg = sum / size;

	for (int i = 0; i < size; i++)
	{
		var = var + (*(source + i) - avg) * (*(source + i) - avg);
	}
	var = var / size;

	dev = sqrt(var);

	return dev;
}