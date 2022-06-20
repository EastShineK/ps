#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	
    string num1, num2;
    int inum1, inum2;
    int large;
    
    cin >> num1 >> num2;

    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    
    inum1 = stoi(num1);
    inum2 = stoi(num2);
    
    if(inum1 > inum2)
        large = inum1;
    else
        large = inum2;
    
    cout << large << "\n";
	
	return 0;
}