#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
	string inp;
    int check[26] = {0,};
    int k;
    int o = 1;
	int count = 0;
	
	cin >> N;
	
	for(int i = 0; i < N; i++){
	    cin >> inp;
	    for(int j = 0; j < inp.size(); j++){
	       k = inp[j] - 97;
	       
	       if(check[k] != 1 /*&& k == inp[j-1] - 97*/){
	           if(k != inp[j+1] - 97){
	                check[k] = 1;
	           }
	       }
	       else{
	           o = 0;
	           break;
	       }
	    }

	    if(o == 1){
	        count++;    
	    }
	    else{
	        o = 1;
	    }
	    
	    for(int c = 0; c < 26; c++){
	        check[c] = 0;
	    }
	}
	
	cout << count << "\n";
	
	return 0;
}
