#include <iostream>
using namespace std;

int main() {
	int N, M;
	char check1[8][8] = { 
	    {'W', 'B', 'W', 'B', 'W', 'B' ,'W', 'B'}, 
	    {'B', 'W', 'B', 'W', 'B' ,'W', 'B', 'W'}, 
	    {'W', 'B', 'W', 'B', 'W', 'B' ,'W', 'B'}, 
	    {'B', 'W', 'B', 'W', 'B' ,'W', 'B', 'W'}, 
	    {'W', 'B', 'W', 'B', 'W', 'B' ,'W', 'B'}, 
	    {'B', 'W', 'B', 'W', 'B' ,'W', 'B', 'W'}, 
	    {'W', 'B', 'W', 'B', 'W', 'B' ,'W', 'B'}, 
	    {'B', 'W', 'B', 'W', 'B' ,'W', 'B', 'W'} };
	    
	char check2[8][8] = { 
	    {'B', 'W', 'B', 'W', 'B' ,'W', 'B', 'W'},
	    {'W', 'B', 'W', 'B', 'W', 'B' ,'W', 'B'}, 
	    {'B', 'W', 'B', 'W', 'B' ,'W', 'B', 'W'}, 
	    {'W', 'B', 'W', 'B', 'W', 'B' ,'W', 'B'}, 
	    {'B', 'W', 'B', 'W', 'B' ,'W', 'B', 'W'}, 
	    {'W', 'B', 'W', 'B', 'W', 'B' ,'W', 'B'}, 
	    {'B', 'W', 'B', 'W', 'B' ,'W', 'B', 'W'}, 
	    {'W', 'B', 'W', 'B', 'W', 'B' ,'W', 'B'}, };
	    
	char input[50][50];
	int count[3000];
	int count1 = 0, count2 = 0;

	cin >> N >> M;
	
	for(int i = 0; i < N; i++){
	    for(int j = 0; j < M; j++){
	        cin >> input[i][j];
	    }
	}
	
	int n = 0;
	
	for(int i = 0; i <= N - 8; i++){
	    for(int j = 0; j <= M - 8; j++){
	        int x = 0, y = 0;
	        for(int t = i; t <= i + 7; t++){
	            for(int k = j; k <= j + 7; k++){
	                if(input[t][k] != check1[x][y])
	                    count1++;
	                if(input[t][k] != check2[x][y]){ 
	                    //cout <<"(" << t <<", "<<k<<") "  << input[t][k] << " " << check2[x][y] << " ";
	                    count2++;
	                
	                }
	                //cout << k;
	                y++;
	            }
	            y = 0;
	            x++;
	        }
	        //cout << "\n";
	        if(count1>count2)
	            count[n] = count2;
	        else
	            count[n] = count1;
	        //cout << i << " " << j << " "  << count1 <<" " <<count2 <<" "  << count[n] << endl;
	        n++;
	        count1 = 0;
	        count2 = 0;
	    }
	}
	//cout << "hi\n";
	int min = 70;
	
	for(int q = 0; q < n; q++){
	    //cout << count[q] << endl;
	    if(count[q] < min)
	        min = count[q];
	}
	
	cout << min << "\n";
	
	return 0;
}
