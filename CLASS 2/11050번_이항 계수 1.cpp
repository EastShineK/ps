#include <iostream>
using namespace std;

int main() {
	int N, K; 
	double ans = 1;
	cin >> N >> K;
	if(N - K < K){
	    for(int i = 0; i < N - K; i++){
	        ans = ans * (N -i) / (N - K -i);
	    }
	}
	else{
	    for(int i = 0; i < K; i++){
	        ans = ans * (N -i) / (K - i);
	    }
	}
	cout << ans << "\n";
	return 0;
}
