#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#include<bits/stdc++.h>
using namespace std;

struct Result {
    int top;
    int count;
};

int Col;
long long total;
long long node_sum[1000010 * 3];
long long min_h[1000010 * 3];
long long max_h[1000010 * 3];

void init(int C)
{
    total = 0;
    Col = C;
    memset(node_sum, 0, sizeof(node_sum));
    memset(min_h, 0, sizeof(min_h));
    memset(max_h, 0, sizeof(max_h));
}

void update(int node, int start, int end, int l, int r, int height) {
    if (r < start || end < l) {
        return ;
    }
    if (l <= start && end <= r) {
        node_sum[node] += height;
        min_h[node] += height;
        max_h[node] += height;
    }
    else {
        int mid = (start + end) / 2;
        update(2 * node, start, mid, l, r, height);
        update(2 * node + 1, mid+1, end, l, r, height);
        min_h[node] = min(min_h[node * 2], min_h[node * 2 + 1]) + node_sum[node];
        max_h[node] = max(max_h[node * 2], max_h[node * 2 + 1]) + node_sum[node];
    }
}

Result dropBlocks(int mCol, int mHeight, int mLength)
{
    Result ret;
    ret.top = 0;
    ret.count = 0;

    total = total + mHeight * mLength;

    update(1, 0, Col-1, mCol, mCol+mLength-1, mHeight);

    ret.top = max_h[1] - min_h[1];
    long long rmv_b = min_h[1] * Col;
    ret.count = (total - rmv_b) % 1000000;

    return ret;
}


#define CMD_INIT 100
#define CMD_DROP 200

static bool run()
{
    int query_num;
    scanf("%d", &query_num);

    int ans_top, ans_count;
    bool ok = false;

    for (int q = 0; q < query_num; q++)
    {
        int query;
        scanf("%d", &query);
        if (query == CMD_INIT)
        {
            int C;
            scanf("%d", &C);
            init(C);
            ok = true;
        }
        else if (query == CMD_DROP)
        {
            int mCol, mHeight, mLength;
            scanf("%d %d %d", &mCol, &mHeight, &mLength);
            Result ret = dropBlocks(mCol, mHeight, mLength);
            scanf("%d %d", &ans_top, &ans_count);
            if (ans_top != ret.top || ans_count != ret.count)
            {
                ok = false;
            }
        }
    }
    return ok;
}

int main()
{
    setbuf(stdout, NULL);
    // freopen("sample_input.txt", "r", stdin);
    int T, MARK;
    scanf("%d %d", &T, &MARK);

    for (int tc = 1; tc <= T; tc++)
    {
        int score = run() ? MARK : 0;
        printf("#%d %d\n", tc, score);
    }
    return 0;
}
