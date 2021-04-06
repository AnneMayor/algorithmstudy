#include <bits/stdc++.h>

using namespace std;

struct segmentTree {

    int n;
    vector<int> tree;

    segmentTree(vector<int> & arr) {
        n = arr.size();
        tree.resize(4*n);
        init(arr, 1, 0, n-1);
    }

    int init(const vector<int> & arr, int node, int left, int right) {
        if(left == right) return tree[node] = arr[left];

        int mid = (left + right) / 2;
        int leftValue = init(arr, 2*node, left, mid);
        int rightValue = init(arr, 2*node+1, mid+1, right);
        return tree[node] = max(leftValue, rightValue);
    }
        
    int query(int left, int right, int node, int nodeLeft, int nodeRight) {
        if (nodeRight < left || right < nodeLeft) return 0;
        if (left <= nodeLeft && nodeRight <= right) return tree[node];
        int mid = (nodeLeft + nodeRight) / 2;
        return max(query(left, right, node * 2, nodeLeft, mid), (query(left, right, node * 2 + 1, mid + 1, nodeRight)));
    }
};

int main(void) {

    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> lightValue;
    for(int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        lightValue.push_back(val);
    }

    segmentTree st(lightValue);

    for(int i = m-1; i <= n-m+1-1; i++) {
        int left = i-(m-1);
        int right = i+(m-1);
        printf("%d ", st.query(left, right, 1, 0, n-1));
    }
    printf("\n");

    return 0;
}