#include<iostream>
#include<list>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N, M, L;
		list<int> sequence;

        cin >> N >> M >> L;

        for(int i = 1; i <= N; i++)
        {
            int sequence_el;
            cin >> sequence_el;

            sequence.push_back(sequence_el);
        }

        for(int j = 1; j <= M; j++)
        {
            char cmd;
            int x, y;

            cin >> cmd;

            if(cmd == 'I') //I 2 7 -> 2번 인덱스 앞에 7을 추가하고, 한 칸 씩 뒤로 이동
            {
                int count = 1;
                cin >> x >> y;
                
                list<int>::iterator iter;
                for(iter = sequence.begin(); count <= x; iter++)
                {
                    count++;
                }
                sequence.insert(iter, y);
            }
            else if(cmd == 'D') //D 4 -> 4번 인덱스 자리를 지우고, 한 칸 씩 앞으로 이동
            {
                int count = 1;
                cin >> x;
                
                list<int>::iterator iter = sequence.begin();
                for(count; count <= x; count++)
                {
                    iter++;
                }
                sequence.erase(iter);
            }
            else //cmd == 'C' //C 3 8 -> 3번 인덱스 자리를 8로 바꾼
            {
                cin >> x >> y;
                
                list<int>::iterator iter = sequence.begin();
                for(int count = 1; count <= x; count++)
                {
                    iter++;
                }
                sequence.insert(iter, y);
                //iter++;
                sequence.erase(iter);
            }
            /*list<int>::iterator iter;
            for(iter = sequence.begin(); iter != sequence.end(); iter++){
                cout << *iter << " ";
            }
            cout << endl;*/
        }

        list<int>::iterator iter = sequence.begin();
    
        int count = 1;

        cout << "#" << test_case << " ";
        if(sequence.size() < L)
        {
            cout << -1 << endl;
        }
        else
        {
            for(count; count <= L; count++)
            {
                iter++;
            }
            cout << *iter << endl;
        }
	}
	return 0;
}