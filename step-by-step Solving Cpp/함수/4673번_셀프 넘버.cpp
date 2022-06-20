#include <iostream>
using namespace std;

int d(int n){
    int dn = n;
    int count = 1;
    while(n >= 10){
        n = n / 10;
        count++;
    }
    
    n = dn;
    
    for(int i = 0; i < count; i++){
        dn = dn + (n%10);
        n = n / 10;
    }
    
    return dn;
}

void detectSelfNumber(){
    bool arr[10001] = {false};
    int t;
    
    for(int i = 1; i < 10001; i++){
        
        t = d(i);
        if(t <= 10000 )
            arr[t] = true;
        
        if(!arr[i])
            cout << i << "\n";
    }
    
}

int main() {
	
	detectSelfNumber();
	
	return 0;
}
