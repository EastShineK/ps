#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
    
    int n;
    int n1, n2;
    int count = 0;
    
    int MAX = 2*123456;
	bool check[MAX+1];
	
	memset(check, true, sizeof(check));
	check[0] = false;
	check[1] = false;
	
	cin >> n;
	
	
    
	
	while(n != 0){
	    n1 = n;
	    n2 = 2*n;
	    
	    for(int i = 2; i < sqrt(n2+1); i++){
	        if(check[i]){
	            for(int j = i*i; j < n2 + 1; j = j + i){
	                check[j] = false;
	            }
	        }
	    }
	    
	    for(int i = n + 1; i <= n2; i++){
	        if(check[i])
	            count++;
	    }
	    
	    cout << count << "\n";
	    
	    count = 0;
	    //cout << "hi222\n";
	    cin >> n;
	    //cout << "hi\n";
	}
	
	return 0;
}
