#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	string s;
	string snum1, snum2;
	string rightside, leftside;
	char oper;
	double num1, num2;
	double Alpha[26] = { 0, };
	int j = 0;
	int s1 = 0, i;
	char* ch;
	char* ch1;
	char* ch2;

	while (1)
	{
		bool isOperator = false;
		getline(cin, s);
		int n = s.length();

		if (s == "exit")
			break;
		else if (n == 1)
		{
			ch = (char*)s.c_str();
			if (*ch >= 97 && *ch <= 122)
			{
				cout << Alpha[*ch - 97] << endl;;
			}
		}
		else
		{
			for (i = 0; i < n; i++)
			{
				if (i != 0 && s.at(i) == '=')
				{
					rightside = s.substr(0, i);
					leftside = s.substr(i + 1, n - i);

					rightside.erase(remove(rightside.begin(), rightside.end(), ' '), rightside.end()); // 공백제거
		
					int ln = leftside.length();

					for (s1 = 0; s1 < ln; s1++)
					{
						if (leftside.at(s1) == '+' || leftside.at(s1) == '*' || leftside.at(s1) == '-' || leftside.at(s1) == '/' || leftside.at(s1) == '%' || leftside.at(s1) == '^')
						{
							oper = leftside.at(s1);
							snum1 = leftside.substr(0, s1);
							snum2 = leftside.substr(s1 + 1, ln - s1);
							snum1.erase(remove(snum1.begin(), snum1.end(), ' '), snum1.end());
							snum2.erase(remove(snum2.begin(), snum2.end(), ' '), snum2.end());
							isOperator = true;
						}
					}

					ch = (char*)rightside.c_str();
					ch1 = (char*)snum1.c_str();
					ch2 = (char*)snum2.c_str();

					if (*ch1 >= 97 && *ch1 <= 122 && *ch2 >= 97 && *ch2 <= 122)
					{
						if (oper == '+')
							Alpha[*ch - 97] = Alpha[*ch1 - 97] + Alpha[*ch2 - 97];
						else if (oper == '*')
							Alpha[*ch - 97] = Alpha[*ch1 - 97] * Alpha[*ch2 - 97];
						else if (oper == '-')
							Alpha[*ch - 97] = Alpha[*ch1 - 97] - Alpha[*ch2 - 97];
						else if (oper == '/')
							Alpha[*ch - 97] = Alpha[*ch1 - 97] / Alpha[*ch2 - 97];
						else if (oper == '%')
						{
							int renum3 = Alpha[*ch1 - 97];
							int renum4 = Alpha[*ch2 - 97];
							Alpha[*ch - 97] = renum3 % renum4;
						}
						else if (oper == '^')
							Alpha[*ch - 97] = pow(Alpha[*ch1 - 97], Alpha[*ch2 - 97]);
						cout << Alpha[*ch - 97] << endl;
					}
					else if (*ch1 >= 97 && *ch1 <= 122 && *ch2 >= 48 && *ch2 <= 57)
					{
						num2 = stod(snum2);
						if (oper == '+')
							Alpha[*ch - 97] = Alpha[*ch1 - 97] + num2;
						else if (oper == '*')
							Alpha[*ch - 97] = Alpha[*ch1 - 97] * num2;
						else if (oper == '-')
							Alpha[*ch - 97] = Alpha[*ch1 - 97] - num2;
						else if (oper == '/')
							Alpha[*ch - 97] = Alpha[*ch1 - 97] / num2;
						else if (oper == '%')
						{
							int renum3 = Alpha[*ch1 - 97];
							int renum4 = num2;
							Alpha[*ch - 97] = renum3 % renum4;
						}
						else if (oper == '^')
							Alpha[*ch - 97] = pow(Alpha[*ch1 - 97], num2);
						cout << Alpha[*ch - 97] << endl;
					}
					else if (*ch1 >= 48 && *ch1 <= 57 && *ch2 >= 97 && *ch2 <= 122)
					{
						num1 = stod(snum1);
						if (oper == '+')
							Alpha[*ch - 97] = num1 + Alpha[*ch2 - 97];
						else if (oper == '*')
							Alpha[*ch - 97] = num1 * Alpha[*ch2 - 97];
						else if (oper == '-')
							Alpha[*ch - 97] = num1 - Alpha[*ch2 - 97];
						else if (oper == '/')
							Alpha[*ch - 97] = num1 / Alpha[*ch2 - 97];
						else if (oper == '%')
						{
							int renum3 = num1;
							int renum4 = Alpha[*ch2 - 97];
							Alpha[*ch - 97] = renum3 % renum4;
						}
						else if (oper == '^')
							Alpha[*ch - 97] = pow(num1, Alpha[*ch2 - 97]);
						cout << Alpha[*ch - 97] << endl;
					}
					else if (*ch1 >= 48 && *ch1 <= 57 && *ch2 >= 48 && *ch2 <= 57)
					{
						num1 = stod(snum1);
						num2 = stod(snum2);
						if (oper == '+')
							Alpha[*ch - 97] = num1 + num2;
						else if (oper == '*')
							Alpha[*ch - 97] = num1 * num2;
						else if (oper == '-')
							Alpha[*ch - 97] = num1 - num2;
						else if (oper == '/')
							Alpha[*ch - 97] = num1 / num2;
						else if (oper == '%')
						{
							int renum3 = num1;
							int renum4 = num2;
							Alpha[*ch - 97] = renum3 % renum4;
						}
						else if (oper == '^')
							Alpha[*ch - 97] = pow(num1, num2);
						cout << Alpha[*ch - 97] << endl;
					}
				}//if '=' end
			}
		
			if (s1 > 0)
			{
				s1 = 0;
				continue;
			}

			for (int i = 0; i < n; i++)
			{
				for (int b = 0; b < n; b++)
				{
					if (s.at(b) == ' ')
						continue;

					if (s.at(b) == '+' || s.at(b) == '*' || s.at(b) == '-' || s.at(b) == '/' || s.at(b) == '%' || s.at(b) == '^')
					{
						oper = s.at(b);
						snum1 = s.substr(0, b);
						snum2 = s.substr(b + 1, n - b);
						snum1.erase(remove(snum1.begin(), snum1.end(), ' '), snum1.end());
						snum2.erase(remove(snum2.begin(), snum2.end(), ' '), snum2.end());
						isOperator = true;
					}
					ch = (char*)rightside.c_str();
					ch1 = (char*)snum1.c_str();
					ch2 = (char*)snum2.c_str();

					if (*ch1 >= 97 && *ch1 <= 122 && *ch2 >= 97 && *ch2 <= 122)
					{
						num1 = Alpha[*ch1 - 97];
						num2 = Alpha[*ch2 - 97];
					}
					else if (*ch1 >= 97 && *ch1 <= 122 && *ch2 >= 48 && *ch2 <= 57)
					{
						num1 = Alpha[*ch1 - 97];
						num2 = stod(snum2);
						
					}
					else if (*ch1 >= 48 && *ch1 <= 57 && *ch2 >= 97 && *ch2 <= 122)
					{
						num1 = stod(snum1);
						num2 = Alpha[*ch2 - 97];
						
					}
					else if (*ch1 >= 48 && *ch1 <= 57 && *ch2 >= 48 && *ch2 <= 57)
					{
						num1 = stod(snum1);
						num2 = stod(snum2);
					
					}

					if (isOperator == true)
						break;
				} // for end

				if (oper == '+')
				{
					cout << num1 + num2 << endl;
					break;
				}
				else if (oper == '*')
				{
					cout << num1 * num2 << endl;
					break;
				}
				else if (oper == '-')
				{
					cout << num1 - num2 << endl;
					break;
				}
				else if (oper == '/')
				{
					cout << num1 / num2 << endl;
					break;
				}
				else if (oper == '%')
				{
					int renum1 = num1;
					int renum2 = num2;
					cout << renum1 % renum2 << endl;
					break;
				}
				else if (oper == '^')
				{
					cout << pow(num1, num2) << endl;
					break;
				}
				else
				{
					break;
				}
			}// for end
		} //else end
	} // first while end

	return 0;
}