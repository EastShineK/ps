#include <iostream>

using namespace std;

int Pascal(int a, int b) {
	
	/* Your code here */
	if(a==0 || b == a || b==0)
	{
		return 1;
	}
	
	return Pascal(
  /* Your code here */	
	a-1, b-1) + Pascal(a-1, b
  );
}
void printTriangle(int n) {

	
	/* Your code here */
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= i; j++)
		{		
			cout << Pascal(i,j) << " ";
		}
		cout << endl;
	}

}

int main() {
    int n;
    cin >> n;
    printTriangle(n);
    return 0;
}
