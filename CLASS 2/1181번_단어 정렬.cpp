#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
bool compare(string ch1, string ch2){
    if(ch1.length() != ch2.length())
        return ch1.length() < ch2.length();
    else
        return ch1 < ch2;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int N, check = 0;
	string arr[20000];
	cin >> N;
	for(int i = 0; i < N; i++){
	    cin >> arr[i];
	}
    sort(arr, arr+N, compare);
	for(int i = 0; i < N; i++){
	    if(arr[i] == arr[check] && i != 0){
	        
	    }
	    else{
	        cout << arr[i] << endl;
	        check = i;
	    }
	}
	return 0;
}
