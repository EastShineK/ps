#include <iostream>
using namespace std;

int main() {
	
	double A, B, V;
	double day = 0;
	int a, b, v, dayInt;
	double rem;
	
	cin >> A >> B >> V;
	
	a = A;
	b = B;
	v = V;
	
	day = (V - B) / (A - B);
	dayInt = (v - b) / (a - b);
	rem = day - dayInt;
	
	if(rem !=0)
	    day = day - rem + 1;
	    
	dayInt = day;
	
	cout << dayInt << "\n";
	
	return 0;
}