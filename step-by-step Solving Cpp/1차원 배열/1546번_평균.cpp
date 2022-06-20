#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
    int N;
    double arr[1000];
    double max;
    double sum = 0;
    
    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        if(i == 0)
            max = arr[0];
        else{
            if(max < arr[i])
                max = arr[i];
        }
    }
    
    cout<<fixed;
    cout.precision(6);
    
    for(int i = 0; i < N; i++){
        arr[i] = (arr[i] / max) * 100;
        sum = arr[i] + sum;
    }
    
    cout << sum / N << "\n";

	return 0;
}