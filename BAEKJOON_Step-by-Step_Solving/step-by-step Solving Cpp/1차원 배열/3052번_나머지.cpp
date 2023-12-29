#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
    int A;
    int num;
    int count = 0;
    int arr[42] = {0,};
    
    for(int i = 0; i < 10; i++){
        cin >> A;
        num = A % 42;
        if(arr[num] == 0){
            arr[num]++;
            count++;
        }
        else{
            arr[num]++;
        }    
    }
    cout << count << "\n";

	return 0;
}