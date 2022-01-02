#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
	int end, len, ans = 0;
	string palindrome;
	
	do{
	    cin >> palindrome;
	    if(palindrome == "0") 
	        break;
	    else
	        end = 0;
	    len = palindrome.length();
	    if(len == 1)
	        ans = 1;
	    else{
	        int t = 0;
	        for(int i = 0; i < len/2; i++){
	            if(palindrome[i] == palindrome[len - 1 - i])
	                t++;
	        }
	        if(t == len/2)
	            ans = 1;
	        else
	            ans = 0;
	    }
	    if(ans == 1)
	        cout << "yes" << "\n";
	    else
	        cout << "no" << "\n";
	}while(end == 0);
	return 0;
}
