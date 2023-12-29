#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	
	double R;
	double w1, w2;
	double pi = M_PI;
	double r;
	
	cin >> R;
	
	w1 = R * R * pi;
	
	r = sqrt(R*R+R*R);
	w2 = r*r;
	
	cout<<fixed;
    cout.precision(6);
	
	cout << w1 << "\n";
	cout << w2 << "\n";
	
	return 0;
}
