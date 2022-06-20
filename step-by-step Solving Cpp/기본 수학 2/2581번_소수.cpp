#include <iostream>
using namespace std;

int main() {
	
	int M, N;
	int check = 0;
	int sum = 0;
	int min = 10000;
	int p = 2;
	
	cin >> M;
	cin >> N;
	
	for(int i = M; i < N + 1; i++){
	    if(i == 1)
	        continue;
	    for(int j = 2; j <= i / 2; j++){
	        if(i % j == 0){
	            check = 1;
	            break;
	        }
	    }
	    if(check == 0){
	        //cout << i << " ";
	        sum = sum + i;
	        if(i < min){
	            min = i;
	        }
	    }
	    else{
	        check = 0;
	    }
	}
	//cout << endl;
	if(sum == 0)
	    cout << "-1" << "\n";
	else{
	    cout << sum << "\n";
	    cout << min << "\n";
	}
	
	
	return 0;
}
