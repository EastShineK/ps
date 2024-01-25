#include<iostream>
#include<list>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
    int N, M;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        list<int> cryptogram_bundle;

        cin >> N;

        for(int cryptogram_count = 1; cryptogram_count <= N; ++cryptogram_count)
        {
            int cryptogram;
            cin >> cryptogram;

            cryptogram_bundle.push_back(cryptogram); 
        }

        /*for(iter = cryptogram_bundle.begin(); iter != cryptogram_bundle.end(); iter++){
            cout << *iter << " ";
        }*/

        cin >> M;

        for(int cmd_count = 1; cmd_count <= M; ++cmd_count)
        {
            char cmd;
            cin >> cmd;
            int x, y, s;

            if(cmd == 'I')
            {
                cin >> x;
                cin >> y;
                
                list<int>::iterator iter;
                iter = cryptogram_bundle.begin();
                for(int i = 1; i <= x; i++)
                {
                    iter++;
                }
                for(int i = 1; i <= y; i++)
                {
                    cin >> s;
                    cryptogram_bundle.insert(iter, s);
                }
            }
            else if(cmd == 'D')
            {
                cin >> x;
                cin >> y;

                list<int>::iterator iter;
                iter = cryptogram_bundle.begin();
                for(int i = 1; i <= x; i++)
                {
                    iter++;
                }
                for(int i = 1; i <= y; i++)
                {
                    iter = cryptogram_bundle.erase(iter);
                }
            }
            else // cmd == 'A'
            {
                cin >> y;
                for(int i = 1; i <= y; i++)
                {
                    cin >> s;
                    cryptogram_bundle.push_back(s);
                }
            }

            /*list<int>::iterator iter;
            for(iter = cryptogram_bundle.begin(); iter != cryptogram_bundle.end(); iter++){
                cout << *iter << " ";
            }*/
           
        }

        list<int>::iterator iter;
        iter = cryptogram_bundle.begin();
        int count = 1;

        cout << "#" << test_case << " ";
        for(iter = cryptogram_bundle.begin(); count <= 10; iter++){
            cout << *iter << " ";
            count++;
        }
        cout << endl;
	}
	return 0;
}
