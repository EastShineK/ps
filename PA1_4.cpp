#include <iostream>
#include <cstring>

using namespace std;

/**
 * Translate English to Arablish.
 *
 * @param text is a 100 sized char array that contains English sentense.
 */
void translate(char* text) {

	/* Your code here */
	int k;
	k = strlen(text);
	int i;
	char temp;
	char num[100];
	int o = 0, t=0;
	//printf("%d", k);
	
	for(i = 0; i < k; i++)
	{
		if(text[i] >= 48 && text[i] <= 57)
		{
			num[o] = text[i];
			//printf("%c\n", text[i]);
			o++;
		}
	}
	
	for(i = 0; i < k/2; i++)
	{
		temp = text[i];
		text[i] = text[k-1-i];
		text[k-1-i] = temp;
	}
	
	for(i = 0; i < k; i++)
	{
		if(text[i] >= 48 && text[i] <= 57)
		{
			text[i] = num[t];
			t++;
		}
	}
	
}



int main() {
	char text[100];

	cin.getline(text, 100);

	translate(text);
	
	cout << text << endl;
}