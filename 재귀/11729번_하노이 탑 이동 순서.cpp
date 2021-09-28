#include <iostream>
#include <cmath>
using namespace std;

void Hanoi(int N, int start, int end, int middle){
    if(N == 1){
        cout << start << " " << end << "\n";
    }
    else{
        Hanoi(N-1,start,middle,end);
        cout << start << " " << end << "\n";
        Hanoi(N-1, middle, end, start);
    }
}

int main() {
	int N;
	int k;
	
	cin >> N;
	
	k = pow(2, N) - 1;
	cout << k << "\n";

	Hanoi(N, 1, 3, 2);

	return 0;
}
