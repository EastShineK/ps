#include <iostream>
#include <string>
using namespace std;

int main() {
	string inp;
	int count = 0;
	
	cin >> inp;
	
	for(int i = 0; i < inp.size(); i++){
	    if(inp[i] == 99 || inp[i] == 100 || inp[i] == 108 || inp[i] == 110 || inp[i] == 115 || inp[i] == 122){
	        if(inp[i] == 99){
	            if(inp[i+1]==61){
	                count++;
	                i++;
	            }
	            else if(inp[i+1]==45){
	                count++;
	                i++;
	            }
	            else
	                count++;
	        }
	        else if(inp[i] == 100){
	            if(inp[i+1] == 122 && inp[i+2] == 61){
	                count++;
	                i = i + 2;
	            }
	            else if(inp[i+1] == 45){
	                count++;
	                i++;
	            }
	            else
	                count++;
	        }
	        else if(inp[i] == 108){
	            if(inp[i+1] == 106){
	                count++;
	                i++;
	            }
	            else
	                count++;
	        }
	        else if(inp[i] == 110){
	            if(inp[i+1] == 106){
	                count++;
	                i++;
	            }
	            else
	                count++;
	        }
	        else if(inp[i] == 115){
	            if(inp[i+1]==61){
	                count++;
	                i++;
	            }
	            else
	                count++;
	        }
	        else{ //122
	            if(inp[i+1]==61){
	                count++;
	                i++;
	            }
	            else
	                count++;
	        }
	    }
	    else
	        count++;
	}
	
	cout << count << "\n";
	
	return 0;
}
