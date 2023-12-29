#include <iostream>
using namespace std;

int main() {
	
	int N;
	int a, b;
	double A, B, n;
	int t, min;
	int count = 0;
	
	cin >> N;
	
	b = N / 5;
	n = N;
	//cout << b << " " << B << endl;
	
	while(b >= 0){
	    B = b;
	    a = (N-5*b)/3;
	    A = (n-5*B)/3;
	    //cout << "A, a : "  <<A << " " << a << endl;
	    //cout << "b : "  << b << endl;
	    if(count == 0 && b == 0){
	        if(A-a!=0){
	        b--;
	        min = -1;
	        continue;
	    }
	    }
	    if(A-a!=0){
	        b--;
	        //min = -1;
	        continue;
	    }
	    t = a + b;
	    //cout << "t = " << t << endl;
	    if(count == 0)
	        min = t;
	    if(t < min){
	        min = t;
	    }
	    count++;
	    b--;
	}
	if(a == 0 && b == 0)
	    min = -1;
	
	cout << min << "\n";
	
	return 0;
}
