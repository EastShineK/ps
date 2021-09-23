#include <iostream>
using namespace std;

int main() {
	
	int x, y, w, h;
	int wx, hy;
	int len1, len2;
	int ans;
	
	cin >> x >> y >> w >> h;
	
	wx = w - x;
	hy = h - y;
	
	if(wx > hy)
	    len1 = hy;
	else
	    len1 = wx;
	
	if(x<y)
	    len2 = x;
	else
	    len2 = y;
	    
	if(len1<len2)
	    ans = len1;
	else
	    ans = len2;
	    
	cout << ans << "\n";
	
	return 0;
}
