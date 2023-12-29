#include <iostream>
using namespace std;

int detect(int N){
    int ans = 0;
    
    for(int i = 1; i <= N; i++){
        int count = 1;
        int num = i;
        int num2 = i;
        int arr[1000];
        int check = 0;
        while(num >= 10){
            num = num / 10;
            count++;
        }
        if(count < 3){
            ans++;
            continue;
        }
        for(int j = 0; j < count - 1; j++){
            int n1, n2;
            n1 = num2 % 10;
            num2 = num2 / 10;
            n2 = num2 % 10;
            arr[j] = n1 - n2;
        }
        for(int c = 0; c < count - 2; c++){
            if(arr[c] == arr[c+1])
                check = 1;
            else
                check = 0;
        }
        if(check == 1)
          ans++;  
    }
    
    return ans;
}

int main() {
	int count;
	int N;
	
	cin >> N;
	
	count = detect(N);
	
	cout << count << "\n";
	
	return 0;
}