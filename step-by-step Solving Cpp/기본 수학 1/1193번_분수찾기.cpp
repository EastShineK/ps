#include <iostream>
#include <string>
using namespace std;

int main() {
	
	int N;
	int t;
	int b, c;
	int count = 0;
	int o = 0;
	string S1, S2;
	
	cin >> N;
	
	while(1){
	    if(o + count + 1 >= N){
	        o = o + count + 1;
	        break;
	    }
	    else{
	        o = o + count + 1;
	        count++;
	    }
	}
	t = count + 1;
	//cout << o << endl;
	//cout << t << endl;
	
	if(t % 2 == 0){
	    c = t;
	    c = c - (t - o + N -1);
	}
	else{
	    c = 1;
	    c = c + t - (o-N)-1;
	}
	b = t + 1 - c;
	
	S1 = to_string(b);
	S2 = to_string(c);
    
	
	cout << S1 << "/" << S2 << "\n";
	
	return 0;
}
