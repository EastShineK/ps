#include<iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        long long n, p;
        long long max = 0; // 연속한 날의 최대 값
        cin >> n >> p;
        vector<long long> study_day(n+5); // 공부한 날짜
        for(long long i = 0; i < n; i++)
        {
            long long day;
            cin >> day;
            study_day[i] = day; // 앞에서부터 차례대로 공부한 날짜를 저장해줌
        }
        
        for(long long i = 0; i < n; i++) // i부터 시작해서 이분탐색하여 최대 연속으로 공부한 날 구하기
        {
            long long start = i, end = n - 1;
            while(start <= end)
            {
                long long mid = (start + end) / 2;
                long long sub_day = study_day[mid] - study_day[i];
                long long do_study = mid - i;
                long long not_study = sub_day - do_study;
                if(not_study > p) // 두 날짜 사이에 공부하지 않은 날짜가 p보다 크다면 그 이상의 날짜에서는 당연히 안되므로 범위 줄여 주기  
                {
                    end = mid - 1;
                }
                else
                {
                    long long max_length;
                    start = mid + 1;
                    if(sub_day == 0) // 만약 자기 자신일 경우
                        max_length = p + 1;
                    else // 두 날짜의 차이 + p만큼 추가 체크 - 공부하지 않은 날짜
                        max_length = (sub_day + 1) + p - not_study;
                        
                    if(max_length > max)
                    {
                        max = max_length;
                    }
                }
            }
        }

        cout << "#" << test_case << " " << max << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
