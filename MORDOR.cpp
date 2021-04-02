#include <bits/stdc++.h>

using namespace std;

const int MAX = numeric_limits<int>::max();

struct segmentTree {
    int arrarySize;
    vector<int> tree;

    segmentTree(const vector<int> & num) {
        arrarySize = num.size();
        tree.resize(arrarySize*4);
        build(num, 1, 0, arrarySize-1);
    }

    int build(const vector<int> & num, int node, int left, int right) {
        if (left == right) {
            return tree[node] = num[left];
        }

        int mid = (left + right) / 2;
        int leftMin = build(num, node*2, left, mid);
        int rightMin = build(num, node*2+1, mid + 1, right);
        return tree[node] = min(leftMin, rightMin);
    }

    int query(int left, int right, int node, int nodeLeft, int nodeRight) {
        if(right < nodeLeft || left > nodeRight) return MAX;
        if(left <= nodeLeft && right  >= nodeRight) return tree[node];
        int mid = (nodeLeft + nodeRight) / 2;
        return min(query(left, right, node*2, nodeLeft, mid), query(left, right, node*2+1, mid+1, nodeRight));
    }

    int query(int left, int right) {
        return query(left, right, 1, 0, arrarySize-1);
    }
};

int main(void) {

    int T;
    scanf("%d", &T);

    vector<int> plusNums;
    vector<int> minusNums;

    for(int tc = 1; tc <= T; tc++) {
        int n, q;
        scanf("%d %d", &n, &q);

        plusNums.clear();
        minusNums.clear();

        for(int i = 0; i < n; i++) {
            int num;
            scanf("%d", &num);
            plusNums.push_back(num);
            minusNums.push_back(-num);
        }

        segmentTree minTree(plusNums);
        segmentTree maxTree(minusNums);

        for(int i = 0; i < q; i++) {
            int start, end;
            scanf("%d %d", &start, &end);
            int rangeMinVal = minTree.query(start, end);
            int rangeMaxVal = -maxTree.query(start, end);
            printf("%d\n", rangeMaxVal - rangeMinVal);
        }

    }

    return 0;