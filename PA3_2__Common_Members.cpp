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
	map<string, int> names1;
	map<string, int> names2;
  int num_names1 = 0;
  int num_names2 = 0;
	int c = 0;
	string name;
	
	
  cin >> num_names1;
  cin >> num_names2;
	
	for (int i = 0; i < num_names1; i++)
	{
		cin >> name;

		if (names1.find(name) != names1.end())
			names1[name]++;
		else
		{
			names1.insert({ name , c });
			names1[name]++;
			c++;
		}
		c = 0;
	}
	
	for (int i = 0; i < num_names2; i++)
	{
		cin >> name;

		if (names2.find(name) != names2.end())
			names2[name]++;
		else
		{
			names2.insert({ name , c });
			names2[name]++;
			c++;
		}
		c = 0;
	}

	
	map<string, int>::const_iterator iter;
	map<string, int>::const_iterator iter2;

	for (iter = names1.begin(); iter != names1.end(); iter++)
	{
		for(iter2 = names2.begin(); iter2 != names2.end(); iter2++)
		{
			if(iter->first == iter2->first)
				cout << iter->first << endl;
		}
	}
	
	
  return 0;
}