#include <iostream>
using namespace std;

int main() {
	
	double A, B, C;
	long long BEP, t;
	
	cin >> A >> B >> C;
	
	t = A / (C - B);
	t = t + 1;
	
	if(t+1 < 0)
	    BEP = -1;
	else
	    BEP = t;
	
	cout << BEP << "\n";
	
	return 0;
}
