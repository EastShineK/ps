#include <iostream>
using namespace std;

int main() {
	
	int T;
	int x, y;
	int l;
	double s, n = 1;
	int C;
	double c;
	int ans;
	
	cin >> T;
	
	for(int i = 0; i < T; i++){
	    cin >> x >> y;
	    l = y - x;
	    while(n*n <= l){
	        n++;
	    }
	    n = n - 1;
	    //cout << " n : "  << n << endl;
	    
	    s = l - n*n;
	    C = s / n;
	    c = s / n;
	    if(c-C != 0)
	        c = c + 1;
	    
	    ans = (n - 1)*2 + 1 + c;
	    
	    
	    n = 1;
	    cout << ans << "\n";
	}
	
	
	return 0;
}
