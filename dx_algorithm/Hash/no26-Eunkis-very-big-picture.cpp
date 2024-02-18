#include <bits/stdc++.h>

using namespace std;

constexpr int base = 31;
int pows[2002 * 2002] = {1};
int t_hash_arr[2002][2002];
char student[2002];
string teacher[2002];

int rabin_karp()
{
    int ans = 0;
    int shash = 0;
    int H, W, N, M;
	cin >> H >> W >> N >> M;
    
    for(int j = 0; j < H; j++)//stduent 해시값 부여
    {
        //long long x = 1;
        /*for(int i = W - 1; i >= 0; i--) 
        {
            //cout << s_hash_arr[j] << " " << student[j][i] * x << endl;
            //s_hash_arr[j] = s_hash_arr[j] + student[j][i] * x;
            //if (i > 0)
            //    x *= 719;
        }*/
        cin >> student;
        for(int i = 0; i < W; i++) 
        {
            shash = shash * base + student[i];
        }
    }
    
    for(int j = 0; j < N; j++)//stduent 해시값 부여
    {
        cin >> teacher[j];
        t_hash_arr[j][0] = 0;
        for(int i = 0; i < M; i++) 
        {
            t_hash_arr[j][i+1] = t_hash_arr[j][i] * base + teacher[j][i];
        }
    }
    
    for(int i = 0; i < M - W + 1; i++)
    {
        int thash = 0;
        for(int j = 0; j < H; j++)
        {
            thash = thash * pows[W] + t_hash_arr[j][i + W] - t_hash_arr[j][i] * pows[W]; // 줄 안 값 삭제
        }
        if(thash == shash)
            ans++;
        for(int j = H; j < N; j++)
        {
            thash = thash - (t_hash_arr[j-H][i+W] - t_hash_arr[j-H][i] * pows[W]) * pows[W * (H - 1)]; //삭제
            thash = thash * pows[W] + t_hash_arr[j][i + W] - t_hash_arr[j][i] * pows[W]; // 추가
            if(thash == shash)
                ans++;
        }
    }
    
    
    return ans;
}

int main(int argc, char** argv)
{
    //ios::sync_with_stdio(false);
	//cin.tie(NULL);
	cin.tie(0)->sync_with_stdio(false);
	int test_case;
	int T;
	
	for (int i = 1; i < 2002 * 2002; ++i) {
		pows[i] = pows[i - 1] * base;
	}
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cout << "#" << test_case << " " << rabin_karp() << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
