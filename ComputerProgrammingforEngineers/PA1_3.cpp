#include <iostream>
#include <string>
using namespace std;

// implement 5 types of add function -- function name [add]
// Note that the first parameter will contain a return value.

/* Your code here */
int add(int& output)
{
	getchar();
	int finput, sinput;
	
	cout << "First input : ";
	cin >> finput;
	cout << "Second input : ";
	cin >> sinput;
	
	return output = finput + sinput;
}

double add(double& output)
{
	getchar();
	double finput, sinput;
	
	cout << "First input : ";
	cin >> finput;
	cout << "Second input : ";
	cin >> sinput;
	
	return output = finput + sinput;
}

string add(string& output)
{
	getchar();
	string finput, sinput;
	
	cout << "First input : ";
	getline(cin, finput);
	cout << "Second input : ";
	getline(cin, sinput);
	
	output = finput + " " + sinput;
	
	return output;
}

int add(int output[], int len)
{
	getchar();
	int finput[len], sinput[len];
	
	cout << "First input : ";
	for(int i = 0; i < len; i++)
	{
		cin >> finput[i];
	}
	cout << "Second input : ";
	for(int i = 0; i < len; i++)
	{
		cin >> sinput[i];
	}
	
	for(int i = 0; i < len; i++)
	{
		output[i] = finput[i] + sinput[i];
	}
	
	return output[len];
}

double add(double output[], int len)
{
	getchar();
	double finput[len];
	double sinput[len];
	
	cout << "First input : ";
	for(int i = 0; i < len; i++)
	{
		cin >> finput[i];
	}
	cout << "Second input : ";
	for(int i = 0; i < len; i++)
	{
		cin >> sinput[i];
	}
	
	for(int i = 0; i < len; i++)
	{
		output[i] = finput[i] + sinput[i];
	}
	
	return output[len];
}

int main() {
    char n;
    cout << "Input type (i/d/s/I/D) : ";
    cin >> n;
    switch(n) {
        case 'i':
        {
            int output;
            add(output); cout << "Output : " << output << endl;
            break;
        }
        case 'd':
        {
            double output;
            add(output); cout << "Output : " << output << endl;
            break;
        }
        case 's':
        {
            string output;
            add(output); cout << "Output : " << output << endl;
            break;
        }
        case 'I':
        {
            int len; cout << "Array size : "; cin >> len;
            int output[len];
            add(output, len);
            cout << "Output : ";
            for (int i=0; i<len; i++) {
                cout << output[i] << " ";
            }
            cout << endl;
            break;
        }
        case 'D':
        {
            int len; cout << "Array size : "; cin >> len;
            double output[len];
            add(output, len);
            cout << "Output : ";
            for (int i=0; i<len; i++)
                cout << output[i] << " ";
            cout << endl;
            break;
        }
        default:
            break;
    }
    return 0;
}