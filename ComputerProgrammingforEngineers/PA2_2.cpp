#include <iostream>
#include<string>

using namespace std;

class Coder {
public:
	virtual string translate(string input) {
		return "";
	}
};

// TODO: Implement Encoder class
class Encoder : public Coder {
public:
	virtual string translate(string input) 
	{
		string hex;
		string hex3;
		string hex4;
		int len = input.length();
		for (int i = 0; i < len; i++)
		{
			int a = input[i];
			//printf("a %d : %d\n", i, a);
			int mod = a % 16;
			int grass = a / 16;;
			if (mod < 10)
			{
				//printf("1pos : %d\n", i);
				hex4 = hex4 + to_string(grass) + to_string(mod);
			}
			else
			{
				string k;
				if (mod == 10)
					k = "a";
				else if (mod == 11)
					k = "b";
				else if (mod == 12)
					k = "c";
				else if (mod == 13)
					k = "d";
				else if (mod == 14)
					k = "e";
				else if (mod == 15)
					k = "f";
				//mod = 65 + (mod - 10);
				//printf("2pos : %d\n", i);
				//hex4 = hex4 + to_string(grass) + to_string(mod);
				//hex4 = hex4 + to_string(grass) + to_string(_putch(mod));
				hex4 = hex4 + to_string(grass) + k;
			}
			//cout <<"hex4 : " << hex4 << endl;
			//num = num / 16;
			//hex.insert(i, to_string(a));
			//hex3 += to_string(a);
		}
		return hex4;
	}

};

//16진수->문자 2개씩 끊어서 확인하기 a->61, b->62
class Decoder : public Coder {
public:
	virtual string translate(string input) {
		int len = input.length();
		string str1;
		int num;
		char b[500];
		//cout << "length : " << len << endl;
		for (int j = 0; j < len; j =j+2)
		{
			//str1 = input[j] * 16;
			//cout << input[j] << endl;
			num = (input[j] - 48) * 16;
			if (input[j + 1] < 58 && input[j+1] > 48)
			{
				//str1 += input[j + 1];
				num += input[j + 1] - 48;
			}
			else
			{
				if (input[j + 1] == 'a')
					num += 10;
				if (input[j + 1] == 'b')
					num += 11;
				if (input[j + 1] == 'c')
					num += 12;
				if (input[j + 1] == 'd')
					num += 13;
				if (input[j + 1] == 'e')
					num += 14;
				if (input[j + 1] == 'f')
					num += 15;
			}
			//cout << "2:" << num << endl;
			b[j/2] = num;
		//	cout << b[j/2] << endl;
		}
		//for (int c = 0; c < len / 2; c++)
		//	cout << b[c];
		//printf("\n");
		for (int c = 0; c < len/2; c++)
			str1 += b[c];
		return str1;
	}
};
int main() {
	Coder* encoder = new Encoder();
	Coder* decoder = new Decoder();

	string word;

	cout << "Please enter a word: ";
	cin >> word;

	string encoded = encoder->translate(word);
	cout << "Encoded: " << encoded << endl;

	string decoded = decoder->translate(encoded);
	cout << "Decoded: " << decoded << endl;

	return 0;
}