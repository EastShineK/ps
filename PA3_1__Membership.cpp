#include <iostream>
#include <map>
#include <string>
using namespace std;
using std::cout;
using std::endl;
using std::map;
using std::string;


int main()
{
	map<string, int> names;
	int num_names = 0;
	int c = 0;
	string name;

	cin >> num_names;

	for (int i = 0; i < num_names; i++)
	{
		cin >> name;

		if (names.find(name) != names.end())
			names[name]++;
		else
		{
			names.insert({ name , c });
			names[name]++;
			c++;
		}
		c = 0;
	}

	map<string, int>::const_iterator iter;

	for (iter = names.begin(); iter != names.end(); iter++)
	{
		cout << iter->first << " : " << iter->second << endl;
	}


	return 0;
}