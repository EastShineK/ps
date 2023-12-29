#include <iostream>
#include <cmath>
using namespace std;

int main() {
	
	int T;
	double x1, x2, y1, y2, r1, r2;
	double len;
	int ans;
	
	cin >> T;
	
	for(int i = 0; i < T; i++){
	    cin >> x1 >> y1 >> r1 >> x2 >> y2 >>r2;
	    
	    if(x1==x2&&y1==y2&&r1==r2){
	        ans = -1;
	        cout << ans << "\n";
	        continue;
	    }
	        
	    len = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
	    if(len == r1+r2)
	        ans = 1;
	    else if(len > r1+r2)
	        ans = 0;
	    else if(len == 0 && r1!=r2)
	        ans = 0;
	    else if(len < r1 || len < r2){
	        if(len+r1==r2 || len+r2==r1){
	            ans = 1;
	        }
	        else if(r1-len>0||r2-len>0){
	            if(r1>len+r2 || r2>len+r1)
	                ans = 0;
	            else
	                ans = 2;
	        }
	        else
	            ans = 0;
	    }
	    else
	        ans = 2;
	    
	    cout << ans << "\n";
	    
	}
	
	return 0;
}
