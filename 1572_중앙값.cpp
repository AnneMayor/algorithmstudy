#include <bits/stdc++.h>

using namespace std;

const int SIZE = 65536;

struct segmentTree {

    int n;
    vector<int> tree;

    segmentTree() {
        tree.resize(4*SIZE);
    }

    int query_update(int cur, int start, int end, int target, int val) {

        if(target < start || target > end) {
            return tree[cur];
        }

        if(start == end) {
            return tree[cur] += val;
        }

        int mid = (start + end) / 2;
        return tree[cur] = query_update(2*cur, start, mid, target, val) + query_update(2*cur+1, mid+1, end, target, val);
    }

    int query_find(int cur, int start, int end, int index) {
        if(start == end) return start;

        int mid = (start + end) / 2;
        if(tree[2*cur] >= index) {
            return query_find(2*cur, start, mid, index);
        } else {
            index -= tree[2*cur];
            return query_find(2*cur+1, mid+1, end, index);
        }
    }

};

int main(void) {

    int n, k;
    scanf("%d %d", &n, &k);

    vector<int> nums(n+1);
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int left = 0, right = 0;
    int middle  = (k+1) / 2;
    long long ans = 0;

    segmentTree st;

    while (right < k-1)
    {
        st.query_update(1, 0, SIZE-1, nums[right++], 1);
    }

    // for(int i = 0; i < n; i++) {
    //     cout << st.tree[i] << " ";
    // }
    // cout << endl;

    while (right < n)
    {
        st.query_update(1, 0, SIZE-1, nums[right++], 1);
        ans += st.query_find(1, 0, SIZE-1, middle);
        st.query_update(1, 0, SIZE-1, nums[left++], -1);
    }
    
    printf("%lld\n", ans);

    return 0;
}