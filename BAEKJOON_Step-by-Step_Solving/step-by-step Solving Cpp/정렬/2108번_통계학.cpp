#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int N, num, min = 4001, max = -4001, cnt[8001] = {0,}, mode, check = 0;
	double sum = 0;
	
	cin >> N;
	int *numArr = new int[N];
	
	for(int i = 0; i < N; i++){
	    cin >> num;
	    sum = sum + num;
	    if(num > max)
	        max = num;
	    if(num < min)
	        min = num;
        numArr[i] = num;
	    cnt[num+4000]++;
	}
	sort(numArr, numArr+N);
	mode = min + 4000;
	for(int i = min + 4001; i < max + 4001; i++){
	    if(cnt[i] > cnt[mode]){
	        mode = i;
	        check = 0;
	    }
	    else if(cnt[i] == cnt[mode]  && check < 1){
	        mode = i;
	        check++;
	    }
	}
	cout << fixed;
	cout.precision(0);
	cout << sum / N << "\n";
	cout << numArr[N/2] << "\n";
	cout << mode - 4000 << "\n";
	cout << max - min << "\n";
	delete[] numArr;
	return 0;
}
