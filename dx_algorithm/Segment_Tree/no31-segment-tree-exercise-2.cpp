#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
int a[MAX];

struct SegmentTree {
    vector<long long> tree_odd;
    vector<long long> tree_even;

    SegmentTree(long long n) {
        tree_odd.resize(4 * n);
        tree_even.resize(4 * n);
    }

    void build(int node, int start, int end) {
        if (start == end) {
            if((start+1) % 2 == 0){
                tree_even[node] = a[start];
                tree_odd[node] = -a[start];
            }
            else{
                tree_even[node] = -a[start];
                tree_odd[node] = a[start];
            }
            
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);
            tree_even[node] = tree_even[2 * node] + tree_even[2 * node + 1];
            tree_odd[node] = tree_odd[2 * node] + tree_odd[2 * node + 1];
        }
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            a[idx] = val;
            if((idx+1) % 2 == 0){
                tree_even[node] = val;
                tree_odd[node] = -val;
            }
            else{
                tree_even[node] = -val;
                tree_odd[node] = val;
            }
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                update(2 * node, start, mid, idx, val);
            } 
            else {
                update(2 * node + 1, mid + 1, end, idx, val);
            }
            tree_odd[node] = tree_odd[2 * node] + tree_odd[2 * node + 1];
            tree_even[node] = tree_even[2 * node] + tree_even[2 * node + 1];
        }
    }

    long long query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return 0; // Return impossible values for this segment
        }
        if (l <= start && end <= r) {
            if(l % 2 == 1)
                return tree_even[node];
            else
                return tree_odd[node];
        }
        int mid = (start + end) / 2;
        long long p1 = query(2 * node, start, mid, l, r);
        long long p2 = query(2 * node + 1, mid + 1, end, l, r);
        
        return p1 + p2;

    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_case;
    int T;
    cin>>T;
   
    for(test_case = 1; test_case <= T; ++test_case){
        int n, q;
        cin >> n >> q;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        SegmentTree st(n);
        st.build(1, 0, n - 1);
      
        cout << "#" << test_case << " ";
    
        while (q--) {
            int type, x, y;
            cin >> type >> x >> y;
            if (type == 0) {
                st.update(1, 0, n - 1, x, y);
            } 
            else {
                long long res = st.query(1, 0, n - 1, x, y - 1);
                cout << res << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}
