#include <iostream>
#include <string>
using namespace std;

int main() {
	
    string inp;
    int arr[26] = {0,};
    int len;
    int k, max = 0;
    char t;
    int count = 0;
    int maxIdx;
    
    cin >> inp;
    len = inp.size();
    
    for(int i = 0; i < len; i++){
        if(inp[i] < 91){
            k = inp[i] - 65;
        }
        else{
            k = inp[i] - 97;
        }
        arr[k]++;
        if(arr[k] > max){
            max = arr[k];
            maxIdx = k;
            //overlap[k]++;
            count = 0;
        }
        else if(arr[k] == max){
            count = 1;
        }
    }
    
    if(count == 1)
        cout << "?\n";
    else{
        t = maxIdx + 65;
        cout << t << "\n";
    }
	
	return 0;
}