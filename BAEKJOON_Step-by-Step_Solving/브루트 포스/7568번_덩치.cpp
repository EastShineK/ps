#include <iostream>
using namespace std;

int main() {
	int N;
	int x, y;
	int hX[51];
	int hY[51];
	int rank[51];
	
	cin >> N;
	
	for(int i = 0; i < N; i++){
	    cin >> x >> y;
	    hX[i] = x;
	    hY[i] = y;
	}
	
	for(int i = 0; i < N; i++){
	    rank[i] = N;
	}
	
	for(int i = 0; i < N; i++){
	    for(int j = 0; j < N; j++){
	        if(hX[i] > hX[j] || hY[i] > hY[j]){
	            rank[i]--;
	            //if(hX[i] < hX[j] || hY[i] < hY[j])
	                //rank[j]--;
	            if(hX[i] == hX[j] || hY[i] == hY[j])
	                rank[j]--;
	        }
	        else if(hX[i] == hX[j] && hY[i] == hY[j]){
	            rank[i]--;
	        }
	        //else
	            //rank[j]--;
	    }
	}
	
	
	for(int i = 0; i < N; i++){
	    cout << rank[i]+1 << " ";
	}
	cout << "\n";
	
	return 0;
}
