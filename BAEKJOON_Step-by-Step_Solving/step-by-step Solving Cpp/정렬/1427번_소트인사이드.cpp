#include <iostream>
using namespace std;

int main() {
	int N;
	int num[10];
	int cnt = 0;
	
	cin >> N;
	
	while( N % 10 != 0 || N != 0){
	    num[cnt] = N % 10;
	    cnt++;
	    N = N / 10;
	}
	
	for(int i = 0; i < cnt - 1; i++){
	    for(int j = i; j < cnt; j++){
	        int temp;
	        if(num[i] < num[j]){
	            temp = num[i];
	            num[i] = num[j];
	            num[j] = temp;
	        }
	    }
	}
	
	for(int i = 0; i < cnt; i++){
	    cout << num[i];
	}
	
	cout << endl;
	
	return 0;
}
