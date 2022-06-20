#include <iostream>
using namespace std;

int main() {
	
	int N;
	int num;
	int count = 0;
	int check = 0;
	
	cin >> N;
	
	for(int i = 0; i < N; i++){
	    cin >> num;
	    
	    if(num == 1)
	        continue;
	    if(num == 2 || num == 3){
	        count++;
	        continue;
	    }
	        
	    for(int j = 2; j <= num / 2; j++){
	        if(num % j == 0){
	            check = 1;
	            break;
	        }
	    }
	    if(check == 1){
	        check = 0;
	    }
	    else{
	        count++;
	    }
	        
	}
	
	cout << count << "\n";
	
	return 0;
}
