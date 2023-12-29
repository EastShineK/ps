#include <iostream>
#include <string.h>
using namespace std;

int main() {
	int N;
	int ans;
	int cnt = 1;
	int num = 666;
	
	cin >> N;
	
	// 666 1666 2666 3666 4666 5666 
	//6661 6662 6663 6664 6665 6666 6667 6668 6669 
	//7666 8666 9666 10666 
	//11666 12666 13666 14666 15666 
	//16661 16662 16663 16664 61666 65666 66601 16661 
	
	while(1){
	    string str = to_string(num);
	    if (str.find("666") != string::npos) {
    	    if(cnt == N){
    	        ans = num;
    	        break;
    	    }
    	    cnt++;
    	    num++;
	    }
	    else
	        num++;
	}
	
	cout << ans << "\n";
	
	return 0;
}
