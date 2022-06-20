#include <iostream>
#include <cmath>
using namespace std;

int main() {
	
	int M, N;
	int check = 0;
	int p = 2;
	
	cin >> M >> N;

	
	for(int i = M; i < N + 1; i++){
	    if(i == 1)
	        continue;
	    for(int j = 2; j <= sqrt(i); j++){
	        if(i % j == 0){
	            check = 1;
	            break;
	        }
	    }
	    if(check == 0){
	        cout << i << "\n";
	    }
	    else{
	        check = 0;
	    }
	}

	
	
	return 0;
}
