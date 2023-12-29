#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int main() {
	
	int M, N;
	int MAX = 1000000;
	bool check[MAX+1];
	
	memset(check, true, sizeof(check));
	check[0] = false;
	check[1] = false;	
	cin >> M >> N;
	
	for(int i = 2; i < sqrt(N + 1); i++){
	    if(check[i]){
	        for(int j = i*i; j < N + 1; j = j + i){
	            check[j] = false;
	        }
	    }
	}

	for(int i = M; i < N + 1; i++){
	    if(check[i])
	        cout << i << "\n";
	}
	
	return 0;
}
