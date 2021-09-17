#include <iostream>
using namespace std;

int main() {
	
	int N;
	int count = 0;
	int c = 1;
	
	cin >> N;
	
	while(1){
	    if(c+6*count>=N)
	        break;
	    else{
	        c = c + 6*count;
	        count++;
	    }
	}
	
	cout << count + 1 << "\n";
	
	return 0;
}
