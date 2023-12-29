#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
    int A, B, C;
    int num, k;
    int arr[10] = {0,};
    
    cin >> A;
    cin >> B;
    cin >> C;
    
    num = A*B*C;
    
    while(1){
        k = num % 10;
        arr[k]++;
        num = num / 10;
        if(num < 10){
            arr[num]++;
            break;
        }
    }
    
    for(int i = 0; i < 10; i++){
        cout << arr[i] << "\n";
    }

	return 0;
}