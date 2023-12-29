#include <iostream>
using namespace std;

int main() {
	int scale[8];
	int checking = 0; // 1: ascending, 2: descending, 3: mixed
	
	for(int i = 0; i < 8; i++){
	    cin >> scale[i];
	}
	
	for(int i = 0; i < 7; i++){
	    if(scale[i] > scale[i+1]){
	        if(checking == 0 || checking == 2)
	            checking = 2;
	        else if(checking == 1){
	            checking = 3;
	            break;
	        }
	    }
	    else if(scale[i] < scale[i+1]){
	        if(checking == 0 || checking == 1){
	            checking = 1;
	        }
	        else if(checking == 2){
	            checking = 3;
	            break;
	        }
	    }
	}
	
	if(checking == 1)
	    cout << "ascending" << endl;
	else if(checking == 2)
	    cout << "descending" << endl;
    else if(checking == 3)
	    cout << "mixed" << endl;
	
	return 0;
}