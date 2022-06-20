#include <iostream>
#include <string>
using namespace std;

int main() {

	string inp;
	int loca[26];
	int len;
	int k;
	
	cin >> inp;
	len = inp.size();
	fill_n(loca, 26, -1); //배열 초기화

	
	for(int i = 0; i < len; i++){
	    k = inp[i] - 97;
	    if(loca[k] == -1)
	        loca[k] = i;
	}
	
	for(int i = 0; i < 26; i++){
	    cout << loca[i] << " ";
	}
	
	return 0;
}
