#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int C;
	double N;
	int count;
	int sum;
	int arr[1000];
	int avg;
    double ratio;
	
	cin >> C;
	
	for(int i = 0; i < C; i++){
	    cin >> N;
	    count = 0, sum = 0;
	    for(int j = 0; j < N; j++){
	        cin >> arr[j];
	        sum = sum + arr[j];
	    }
	    avg = sum / N;
	    for(int j = 0; j < N; j++){
	        if(arr[j] > avg)
	            count++;
	    }
	    ratio = (count / N) * 100;
	    
	    cout<<fixed;
        cout.precision(3);
        
        cout << ratio << "%\n";
	}
	
	return 0;
}

