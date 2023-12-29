#include <iostream>
using namespace std;

int main() {
	int N;
	int sum = 0;
	
	cin >> N;
	
	for(int i = 0; i < N; i++){
	    sum = sum + (i + 1);
	}
	
	cout << sum << endl;
	
	return 0;
}
