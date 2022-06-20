#include <iostream>
using namespace std;

int main() {
	
	int A, B;
	
	cin >> A >> B;
	
	while(A != NULL && B != NULL){
	    cout << A+B << "\n";
	    A, B = NULL;
	    cin >> A >> B;
	}
	
	return 0;
}
