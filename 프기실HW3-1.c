#include <stdio.h>
#include <stdlib.h>

int max_sum(int number[], int size);

int main() {

    int arr[10];
    int seed;

    printf("Enter a seed : ");
    scanf("%d", &seed);
    srand(seed);

    for (int i = 0; i < 10; i++)
    {
        int k;
        k = (rand() % 41) - 20;
        arr[i] = k;
        printf("%d ", arr[i]);
    }
    printf("\n");

    max_sum(arr, 10);

    return 0;
}

int max_sum(int number[], int size)
{
    int startX = 0, maxsum = 0, lastS = 0, lastE = 0, i;
    int lastMax = 0;
    int m;

    maxsum = number[0];
    lastMax = number[0];

    for (i = 1; i < 10; i++)
    {
        if (number[i] > maxsum + number[i])
        {
            startX = i;
            maxsum = number[i];

        }
        else
        {
            maxsum = number[i] + maxsum;


        }
        if (lastMax < maxsum)
        {
            lastS = startX;
            lastE = i;
            lastMax = maxsum;
        }

    }

    for (i = lastS; i <= lastE; i++)
    {
        printf("%d ", number[i]);

    }
    printf("\n");
    printf("%d", lastMax);

    return 0;
}
