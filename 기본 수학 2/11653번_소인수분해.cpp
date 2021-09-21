#include <iostream>
using namespace std;

int main() {
	
	int N;
	int k = 2;
	
	cin >> N;
	
	while(N > 1){
	    if(N%k == 0){
	        cout << k << "\n";
	        N = N / k;
	    }
	    else{
	        k++;
	    }
	}
	
	
	return 0;
}
