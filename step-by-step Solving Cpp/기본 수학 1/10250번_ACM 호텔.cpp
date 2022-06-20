#include <iostream>
#include <string>
using namespace std;

int main() {
	
	int T;
	int H, W, N;
	int y, x;
	string yStr, xStr;
	
	cin >> T;
	
	for(int i = 0; i < T; i++){
	    cin >> H >> W >> N;
	    if(N % H == 0)
	        x = N / H;
	    else
	        x = N / H + 1;
	    y = N;
	    while(y > H){
	        y = y - H;
	    }
	    yStr = to_string(y);
	    if(x > 9)
	        xStr = to_string(x);
	    else
	        xStr = '0' + to_string(x);
	
	
	    cout << yStr + xStr << "\n";
	}
	
	return 0;
}