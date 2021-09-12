#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	int count = 0;
	int maxCount = 0;
	int max = -1;
	int num;
	
    for(int i = 0; i < 9; i++){
        
        count++;
        cin >> num;
        //cout << count << " " << num << " " << max << " " << maxCount << "\n";
        
        if(max < num){
            max = num;
            maxCount = count;
        }
    }
	
	cout << max << "\n" << maxCount << "\n";

	return 0;
}