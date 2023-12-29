#include <iostream>
using namespace std;

int main() {
	int x, y;
	
	cin >> x;
	cin >> y;
	
	if(x > 0)
	    if(y > 0)
	        cout << "1" << endl;
	    else if(y < 0)
	        cout << "4" << endl;
	    else
	        cout << "Not suitable for input conditions" << endl;
	else if(x < 0)
	    if(y > 0)
	        cout << "2" << endl;
	    else if(y < 0)
	        cout << "3" << endl;
	    else
	        cout << "Not suitable for input conditions" << endl;
	else
	    cout << "Not suitable for input conditions" << endl;
	    
	return 0;
}
