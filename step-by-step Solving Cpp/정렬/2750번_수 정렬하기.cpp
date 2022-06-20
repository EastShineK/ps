#include <iostream>
using namespace std;

int main() {
	int num;
	int result[1000];
	
	cin >> num;
	
	for(int i = 0; i < num; i++){
	    cin >> result[i];
	}
	
	for(int i = 0; i < num - 1; i++){
	    for(int j = i; j < num; j++){
    	    int temp;
    	    if(result[i] > result[j]){
    	        temp = result[i];
    	        result[i] = result[j];
    	        result[j] = temp;
    	    }
	    }
	}
	
	for(int i = 0; i < num; i++){
	    cout << result[i] << endl;
	}
	return 0;
}
