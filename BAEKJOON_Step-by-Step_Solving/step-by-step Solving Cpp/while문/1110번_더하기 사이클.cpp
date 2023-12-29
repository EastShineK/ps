#include <iostream>
using namespace std;

int main() {
	
	int N;
	int copyN = 0;
	int cycle = 0;
	int tN, oN, sum;
	
	cin >> N;
	
	tN = N / 10;
	oN = N % 10;
	
	while(copyN != N){
	    sum = tN + oN;
	    if(sum >= 10)
	        sum = sum - 10;
	    copyN = sum + oN * 10;
	    tN = copyN / 10;
	    oN = copyN % 10;
	    cycle++;
	}
	if(N == 0)
	    cycle++;
	
	cout << cycle << "\n";
	
	return 0;
}
