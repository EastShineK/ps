#include <iostream>
using namespace std;

int main() {
	
	int s1, s2, s3;
	int a, b, c;
	bool check = false;
	
	cin >> s1 >> s2 >> s3;
	
	while(s1 != 0 && s2 != 0 && s3 != 0){
	    
	    a = s1*s1;
	    b = s2*s2;
	    c = s3*s3;
	    
	    if(a+b==c || b+c == a || a+c == b)
	        check = true;
	    
	    
	    if(check)
	        cout << "right" << "\n";
	    else
	        cout << "wrong" << "\n";
	    
	    check = false;
	    
	    cin >> s1 >> s2 >> s3;
	}
	
	return 0;
}
