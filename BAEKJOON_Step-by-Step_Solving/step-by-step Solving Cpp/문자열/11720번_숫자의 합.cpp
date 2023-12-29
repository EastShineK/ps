#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	string inp;
	int num;
	int sum = 0;
	
	cin >> N;
	cin >> inp;
	
	for(int i = 0; i < N; i++){
	    num = inp[i] - 48;
	    sum = sum + num;
	}
	
	cout << sum << "\n";
}
