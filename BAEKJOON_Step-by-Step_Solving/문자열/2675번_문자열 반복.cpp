#include <iostream>
#include <string>
using namespace std;

int main() {

	int T;
	int R;
	string inp;
	string s;
	
	cin >> T;
	
	for(int i = 0; i < T; i++){
	    cin >> R;
	    cin >> inp;
	    int len = inp.size();
	    for(int j = 0; j < len; j++){
	        s = inp[j+(R-1)*j];
	        if(R == 1)
	            break;
	        for(int c = 0; c < R - 2; c++){
	            s = s + inp[j+(R-1)*j];
	        }
	        inp.insert(j+1+(R-1)*j, s);
	    }
	    cout << inp << "\n";
	}
	
	
	return 0;
}
