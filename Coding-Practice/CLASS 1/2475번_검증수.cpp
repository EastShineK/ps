#include <iostream>
using namespace std;

int main() {
	int result[5];
	int identNum = 0;
	
	for(int i = 0; i < 5; i++){
	    cin >> result[i];
	}
	
	for(int i = 0; i < 5; i++){
	    identNum = identNum + result[i]*result[i]; 
	}
	
	identNum = identNum % 10;
	
	cout << identNum << endl;
	
	return 0;
}