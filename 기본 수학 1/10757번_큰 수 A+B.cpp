#include <iostream>
#include <string>
using namespace std;

int main() {
	
    string A, B;
    int a, b;
    int lenA, lenB, len;
    int locA, locB;
    int pl = 0;
    int sum;
    string ans;
    
	cin >> A >> B;
	
	lenA = A.size();
	lenB = B.size();
	if(lenA > lenB)
	    len = lenA;
	else
	    len = lenB;
	  
	locA = lenA - 1;
	locB = lenB - 1;
	//cout << lenA << " " << lenB << endl;
	    
	for(int i = len; i > 0; i--){
	    if(locA >= 0)
	        a = A[locA]-48;
	    else
	        a = 0;
	    if(locB >= 0)
	        b = B[locB]-48;
	    else
	        b = 0;
	    sum = a + b + pl;
	    //cout << sum << endl;
	    pl = 0;
	    if(sum > 9){
	        while(sum>9){
	            sum = sum - 10;
	            pl++;    
	        }
	    }
	    
	    //cout << "sum2 : " << sum << endl;
	    if(i == len){
	        ans = to_string(sum);
	    }
	    else if(i == 1){
	        //cout << "hi" << endl;
	        sum = sum + 10 * pl;
	        //cout << sum << endl;
	        string k = to_string(sum);
	        //cout << "k : " << k << endl;
	        for(int c = 0; c < k.size()/2; c++){
	            //cout << "hihihi" << endl;
	            //cout << k[c] << endl;
	            //cout << k[k.size()-1-c] << endl;
	            char temp;
	            temp = k[c];
	            k[c] = k[k.size()-1-c];
	            k[k.size()-1-c] = temp;
	        }
	        //cout << "k : " << k << endl;
	        ans = ans + k;
	    }
	    else{
	        ans = ans + to_string(sum);
	    }
	    locA--;
	    locB--;
	}
	
	for(int i = 0; i < ans.size()/2; i++){
	    char temp;
	    int lenTemp = ans.size() - 1;
	    temp = ans[i];
	    ans[i] = ans[lenTemp-i];
	    ans[lenTemp-i] = temp;
	}
	
	
	cout << ans << "\n";
	
	return 0;
}
