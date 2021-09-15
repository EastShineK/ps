#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	
    string inp;
    int ans = 0;
    
    cin >> inp;
    
    for(int i = 0; i < inp.size(); i++){
        if(inp[i] > 86)
            ans = ans + 10;
        else if(inp[i] > 83)
            ans = ans + 9;
        else if(inp[i] > 79)
            ans = ans + 8;
        else if(inp[i] > 76)
            ans = ans + 7;
        else if(inp[i] > 73)
            ans = ans + 6;
        else if(inp[i] > 70)
            ans = ans + 5;
        else if(inp[i] > 67)
            ans = ans + 4;
        else
            ans = ans + 3;
    }
    
    cout << ans << "\n";
	
	return 0;
}