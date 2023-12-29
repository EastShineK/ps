#include <iostream>
#include <string>
using namespace std;

int main() {
	
    string inp;
    int count = 0;
    int point = 0;
    
    getline(cin, inp);
    //cout << inp << endl;
    
    for(int i = 0; i < inp.size(); i++){
        if(inp[i] == 32){
            point = 0;
        }
        else{
            if(i != 0 && point == 0){
                //cout << i << endl;
                count++;
                point = 1;
            }
            else if(i == 0){
                count++;
                point = 1;
            }
        }
    }
    
    cout << count << "\n";
	
	return 0;
}