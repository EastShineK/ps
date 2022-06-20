#include <iostream>
#include <string>
using namespace std;


int f(int k, int n){
    if(k == 0)
        return n;
    else if(n == 1)
        return 1;
    else
        return f(k, n-1) + f(k-1, n);
}

int main() {
	
	int T;
	int k, n;
	int i;
	
	cin >> T;
	
	for(int j = 0; j < T; j++){
	    cin >> k;
	    cin >> n;
	    
	    i = f(k, n);
	    cout << i << "\n";
	}
	
	return 0;
}