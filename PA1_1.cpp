#include <iostream>

using namespace std;

/**
 * @param array is an fixed size integer array. 
 *        It can be used as an input and also output.
 *        array contains 0 to 10.
 * @return size of output array
 */
int unique(int* array) {
	int size = 10;

	// TODO: make a unique array
	// TODO: pack the array to left the left side (rearrange the array)
	// TODO: changed size must be returned

	
	
	/* Your code here */
	int uniqueArr[10];
	int i, j, k = 0;
	
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < i; j++)
		{
			if(array[i] == array[j])
			{
				break;
			}
		}
		if(j == i)
		{
			uniqueArr[k] = array[i];
			//printf("uniqueArr[%d] = %d\n",k, uniqueArr[k]);
			k++;
			//printf("k = %d\n", k);
		}
	}

	size = k;
	
	for(i = 0; i < size; i++)
	{
		array[i] = uniqueArr[i];
		//printf("array = %d\n", array[i]);
	}
	
	return size;
}

int main() {
	int array[10];
	for(int i = 0; i < 10; i++)
		cin >> array[i];

	int size = unique(array);

	if(size < 0 || size > 10)
		return -1;

	for(int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;

	return 0;
}
