#include <iostream>
using namespace std;


int solution(int *hills, int len);
/* You can declare more functions here if needed */

int main() {
    int n; cin >> n; 
    int hills[n];
    for (int i=0; i<n; i++) {
        cin >> hills[i];
    }
    cout << solution(hills, n) << endl;
}
/* You can implement newly added functions here */


/* solution function. You must implement it */
int solution(int *hills, int len) {
		/* Your code */
	int distance1 = 0, distance2 = 0, distance, longdistance = 0;
	int distance0 = 0;
	int o = 0, i = 0, k1;
	
	for(int k = 0; k < len; k++)
	{
		k1 = k;
		if(k != 0 && hills[k] >= hills[k-1])
		{
			while(hills[k-o-1] <= hills[k-o])
			{
				distance0++;
				o++;
			}
		}
		o = 0;
		
		while(k != len-1 && hills[k] >= hills[k+1])
		{
			distance1++;
			k++;
		}
		/*if(k != len-1)
		{
			while(hills[k] >= hills[k+1])
			{
				distance2++;
				k++;
			}
		}*/
		distance = distance0 + distance1 + distance2;
		k = k1;
		//printf("%d = %d\n", k, distance0);
		//printf("%d = %d\n", k, distance1);
		//printf("%d = %d\n", k, distance2);
		//printf("%d = %d\n", k, distance);
		if(distance > longdistance)
			longdistance = distance;
		
		distance = 0;
		distance0 = 0;
		distance1 = 0;
		distance2 = 0;
		//i = 0;
	}
	
	return longdistance;
}