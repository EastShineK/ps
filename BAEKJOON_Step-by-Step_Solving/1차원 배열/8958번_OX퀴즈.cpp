#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	int N;
	int count = 0;
	int score = 0;
	int k = 0;
	int size;
	string input;
	
	cin >> N;
	cin.ignore();
	
	for(int i = 0; i < N; i++){
	    getline(cin, input);
	    //cout << input << "\n";
	    size = input.size();
	    for(int j = 0; j < size; j++){
	        if(input[k] == 'O'){
	            count++;
	            score = score + count;
	        }
	        else{
	            count = 0;
	        }
	        k++;
	    }
	    cout << score << "\n";
	    count = 0;
	    score = 0;
	    k = 0;
	}
	
	return 0;
}

