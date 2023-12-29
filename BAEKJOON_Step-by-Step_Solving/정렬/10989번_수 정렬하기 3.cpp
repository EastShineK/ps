#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	int N;
	int numCnt[10001] = { 0, };
	int num;
	int max = 0;
	
	//int *result = nullptr;
	
	cin >> N;
	
	//int *numArr = new int[N];
	
	for(int i = 0; i < N; i++){
	    cin >> num;
	    //numArr[i] = num;
	    if(max < num)
	        max = num;
	    numCnt[num]++;
	    //cout << "numCnt" << num << " " << numCnt[num] << endl;
	}
	for(int i = 0; i < max + 1; i++){
	    for(int j = 0; j < numCnt[i]; j++){
	        cout << i << "\n";
	    }
	} 
	
	/*for(int i = 1; i < max + 1; i++){
	    numCnt[i] = numCnt[i-1] + numCnt[i];
	    //cout << "numCnt" << i << " " << numCnt[i] << endl;
	}
	
	int *result = new int[N];
	
	for(int i = N; i > 0; i--){
	    result[numCnt[numArr[i-1]]-1] = numArr[i-1];
	    numCnt[numArr[i-1]]--;
	}
	
	for(int i = 0; i < N; i++){
	    cout << result[i] << "\n";
	}
	
	delete[] numArr;
	delete[] result;*/
	
	return 0;
}
