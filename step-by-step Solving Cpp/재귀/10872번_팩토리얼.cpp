#include <iostream>
using namespace std;

int Factorial(int N){
    if(N == 1 || N == 0)
        return 1;
    else
        return N*Factorial(N-1);
        
}

int main() {
	
	int N;
	
	cin >> N;
	
	cout << Factorial(N) << endl;
	
	return 0;
}
