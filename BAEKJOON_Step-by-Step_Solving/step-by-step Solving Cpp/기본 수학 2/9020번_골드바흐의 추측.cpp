#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
    
    int T;
    int num1, num2;
    int n;
    int min = 999999999;
    int anum1, anum2;
    
    int MAX = 100000;
	bool check[MAX+1];
	
	memset(check, true, sizeof(check));
	check[0] = false;
	check[1] = false;	
	
	for(int i = 2; i < sqrt(MAX + 1); i++){
	    if(check[i]){
	        for(int j = i*i; j < MAX + 1; j = j + i){
	            check[j] = false;
	        }
	    }
	}	    
    
    cin >> T;
    
    for(int i = 0; i < T; i++){
        cin >> n;
        for(int num1 = 2; num1 <= n / 2; ){
            num2 = n - num1;
            if(check[num1] && check[num2]){
                if(num2-num1 < min){
                    min = num2 - num1;
                    anum1 = num1;
                    anum2 = num2;
                    //cout << "1: " << anum1 << " " << "2: " << anum2 << "\n";
                }
                num1++;
            }
            else{
                num1 = num1 + 1;
                while(1){
                    if(check[num1]){
                        break;
                    }
                    else{
                        num1++;
                    }
                }
            }
        }
        
        cout << anum1 << " " << anum2 << "\n";
        min = 999999999;
    }
	
	return 0;
}
