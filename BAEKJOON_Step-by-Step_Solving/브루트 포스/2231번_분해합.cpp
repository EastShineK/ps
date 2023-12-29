#include <iostream>
using namespace std;

int main() {
	int N;
	int num = 1;
	int t;
	int copyNum;
	
	cin >> N;
	//if(N>100)
	    //num = N - 30;
	while(1){
	    if(num < 10){
	        if(num+num == N)
	            break;
	    }
	    else if(num < 100){
	        if(num+(num/10)+(num%10)==N){
	            break;
	        }
	    }
	    else{
	        t = num;
	        copyNum = num;
	        while(copyNum/10!=0){
	            t = t + (copyNum%10);
	            copyNum = copyNum / 10;
	        }
	        t = t + copyNum;
	        if(t==N)
	            break;
	    }
	    if(num == N){
	        num = 0;
	        break;
	    }
	    
	    num++;
	}
	
	cout << num << "\n";
	
	return 0;
}
