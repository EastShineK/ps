#include <iostream>
using namespace std;

int main() {
	int N, M;
	int num[100];
	int min = 999999999;
	int ans;
	int k;
	int sum;
	
	cin >> N >> M;
	
	for(int i = 0; i < N; i++){
	    cin >> num[i];
	}
	
	k = N*(N-1)*(N-2)/6;
	int count = 1;
	
	for(int i = 0; i < N - 2; i++){
	    for(int j = i+1; j < N - 1; j++){
	        for(int h = j+1; h < N; h++){
	            sum = num[i] + num[j] + num[h];
	            if(M-sum < min && M-sum >= 0){
	                min = M - sum;
	                ans = sum;
	                //cout << min << endl;
	            }
	        }
	    }
	}
	
	cout << ans << "\n";
	
	return 0;
}
