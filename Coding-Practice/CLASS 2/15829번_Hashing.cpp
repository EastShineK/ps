#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
	long long L, H = 0, M = 1234567891, r = 1;
	string inp;
	cin >> L >> inp;
	for(int i = 0; i < L; i++){
	    H = (H + long(long(inp[i] - 'a' + 1) * r)) % M;
	    r = r * 31 % M;
	}
	printf("%lld", H);
	return 0;
}
