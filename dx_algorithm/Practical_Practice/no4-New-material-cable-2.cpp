#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define CMD_INIT			(100)
#define CMD_CONNECT			(200)
#define CMD_MEASURE			(300)
#define CMD_TEST			(400)

#include<bits/stdc++.h>
#include<unordered_map>
#include <stack>
#include<vector>

using namespace std;

int root;
int id;
vector<pair<int, int>> adj[10010];
unordered_map<int, int> imap;

void init(int mDevice)
{
	for (int i = 0; i <= id; i++) {
		adj[i].clear();
	}
	root = 1;
	id = 1;
	imap.clear();
	imap[mDevice] = id;
}

void connect(int mOldDevice, int mNewDevice, int mLatency)
{
	int old_i, new_i;
	old_i = imap[mOldDevice];
	id++;
	new_i = id;

	adj[new_i].push_back({ old_i, mLatency });
	adj[old_i].push_back({ new_i, mLatency });

	imap[mNewDevice] = new_i;
}

int getL(int s, int e) {

	int adj_size = id+1;
	vector<bool> visited(adj_size, false);
	stack<pair<int, int>> stk;

	stk.push({ s, 0 });

	while (!stk.empty()) {
		int cur = stk.top().first;
		int dist = stk.top().second;
		stk.pop();

		if (cur == e) {
			return dist;
		}
			

		if (visited[cur]) 
			continue;
		visited[cur] = true;
		for (auto& a : adj[cur]) {
			if (!visited[a.first]) {
				stk.push({ a.first, dist + a.second });
			}
		}
	}

	return 0;
}

int measure(int mDevice1, int mDevice2)
{
	int s, e;
	s = imap[mDevice1];
	e = imap[mDevice2];
	return getL(s, e);
}

int getML(int pid, int dest) {

	int adj_size = id + 1;
	vector<bool> visited(adj_size, false);
	stack<pair<int, int>> stk;
	int max_len = 0;
	visited[pid] = true;
	stk.push({ dest, 0 });

	while (!stk.empty()) {
		int cur = stk.top().first;
		int dist = stk.top().second;

		stk.pop();
		if (visited[cur])
			continue;
		visited[cur] = true;
		for (auto& a : adj[cur]) {
			if (!visited[a.first]) {
				stk.push({ a.first, dist + a.second });
				if (dist + a.second > max_len)
					max_len = dist + a.second;
			}
		}
	}
	return max_len;
}

int test(int mDevice) {
	int pid = imap[mDevice];
	vector<int> latencies;

	for (auto& a : adj[pid]) {
		latencies.push_back(getML(pid, a.first) + a.second);
	}

	sort(latencies.rbegin(), latencies.rend());

	if (latencies.size() >= 2) {
		return latencies[0] + latencies[1]; 
	}
	else if (!latencies.empty()) {
		return latencies[0];
	}
	return 0;
}

static bool run()
{
	int Q;
	int mDevice, mOldDevice, mNewDevice, mDevice1, mDevice2;
	int mLatency;

	int ret = -1, ans;
	scanf("%d", &Q);

	bool okay = false;

	for (int q = 0; q < Q; ++q)
	{
		int cmd;
		scanf("%d", &cmd);
		switch (cmd)
		{
		case CMD_INIT:
			scanf("%d", &mDevice);
			init(mDevice);
			okay = true;
			break;
		case CMD_CONNECT:
			scanf("%d %d %d", &mOldDevice, &mNewDevice, &mLatency);
			connect(mOldDevice, mNewDevice, mLatency);
			break;
		case CMD_MEASURE:
			scanf("%d %d", &mDevice1, &mDevice2);
			ret = measure(mDevice1, mDevice2);
			scanf("%d", &ans);
			printf("measure ans, ret: %d %d\n", ans, ret);
			if (ret != ans)
				okay = false;
			break;
		case CMD_TEST:
			scanf("%d", &mDevice);
			ret = test(mDevice);
			scanf("%d", &ans);
			printf("test ans, ret: %d %d\n", ans, ret);
			if (ret != ans)
				okay = false;
			break;
		default:
			okay = false;
			break;
		}
	}

	return okay;
}

int main()
{
	setbuf(stdout, NULL);
	//freopen("sample_input.txt", "r", stdin);

	int TC, MARK;

	scanf("%d %d", &TC, &MARK);
	for (int tc = 1; tc <= TC; ++tc)
	{
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}
