#include<iostream>
#include<climits>
#include<cmath>
#include <vector>
#include <algorithm>

using namespace std;

long long M_z[500005]; 

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N, M;
        long long c1, c2;
        long long min = INT_MAX;
        long long idx_zero = INT_MIN;
        long long cnt = 0;
        cin >> N >> M;
        cin >> c1 >> c2;

        vector<long long> N_z;
        //int N_z[500005]; 
        //vector<int> M_z;
        //int M_z[5000]; 
 
        for(int i = 0; i < N; i++)
        {
            long long z;
            cin >> z;
            N_z.push_back(z);
        }

        M_z[0] = idx_zero;
        for(int i = 1; i <= M; i++)
        {
            long long z;
            cin >> z;
            M_z[i] = z;
        }
        //M_z.push_back(min);
        M_z[M+1] = min;
        sort(M_z, M_z+(M+1));

        for(int i = 0; i < N; i++)
        {
            int start = 1;
            int end = M;
            auto k = lower_bound(M_z, M_z+(M+1), N_z[i]);
            if(*k == N_z[i]) {                
                if(min == 0) 
                {
                    cnt += 1;
                }                                 
                else                 
                {
                    min = 0;
                    cnt = 1;
                }   
                continue;          
            }
            else{
                auto left = prev(k);
                long long right_v = *k;
                long long left_v = *left;
                if(abs(right_v-N_z[i]) > abs(left_v-N_z[i]))
                {
                    int tmp = abs(left_v-N_z[i]);
                    if(min > tmp)
                    {
                        min = tmp;
                        cnt = 1;
                    }
                    else if(min == tmp)
                    {
                        cnt += 1;
                    }
                }
                else if(abs(right_v-N_z[i]) < abs(left_v-N_z[i]))
                {
                    long long tmp = abs(right_v-N_z[i]);
                    if(min > tmp)
                    {
                        min = tmp;
                        cnt = 1;
                    }
                    else if(min == tmp)
                    {
                        cnt += 1;
                    }
                }
                else{
                    int tmp = abs(right_v-N_z[i]);
                    if(min > tmp)
                    {
                        min = tmp;
                        cnt = 2;
                    }
                    else if(min == tmp)
                    {
                        cnt += 2;
                    }
                }
            }
        }

		cout << "#" << test_case << " ";
    cout << abs(c1-c2) + min << " " << cnt << "\n";
	}
	return 0;
}
