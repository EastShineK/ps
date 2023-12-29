#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	int N;
	int max, min;
	int arr[1000000];
	int n1;
	
	cin >> N;
	
	for(int i = 0; i < N; i++){
	    cin >> arr[i];
	}

	max = -1000001; 
	min = 1000001;
	
	for(int i = 0; i < N; i++){
	    if(max < arr[i])
	        max = arr[i];
	}
	for(int i = 0; i < N; i++){
	    if(min > arr[i])
	        min = arr[i];
	}
	cout << min << " " << max << "\n";

	return 0;
}