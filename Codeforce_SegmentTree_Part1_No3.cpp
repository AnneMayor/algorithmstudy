#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct item {
    int minNum;
    int cntOfMinNum;
};

struct segmentTree
{
    int size;
    vector<item> tree;

    item merge(item i1, item i2) {
        if(i1.minNum > i2.minNum) return i2;
        if(i1.minNum < i2.minNum) return i1;
        return {i1.minNum, i1.cntOfMinNum + i2.cntOfMinNum};
    }

    item single(int val) {
        return {val, 1};
    }

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.resize(2*size);
        return ;
    }

    void build(const vector<int> & nums, int node, int start, int end) {
        if(end - start == 1) {
            if(start < (int) nums.size()) tree[node] = single(nums[start]);
            return ;
        }

        int mid = (start+end) / 2;
        build(nums, node*2+1, start, mid);
        build(nums, node*2+2, mid, end);
        tree[node] = merge(tree[node*2+1], tree[node*2+2]);
        return ;
    }

    void build(const vector<int> & nums) {
        build(nums, 0, 0, size);
        return ;
    }

    void set(int i, int val, int node, int start, int end) {
        if(end - start == 1) {
            tree[node] = single(val);
            return ;
        }

        int mid = (start+end) / 2;
        if(i < mid) {
            set(i, val, node*2+1, start, mid);
        } else {
            set(i, val, node*2+2, mid, end);
        }
        tree[node] = merge(tree[node*2+1], tree[node*2+2]);

        return ;
    }

    void set(int i, int val) {
        set(i, val, 0, 0, size);
        return ;
    }

    item calc(int start, int end, int node, int left, int right) {
        if(start >= right || end <= left) {
            return {INT_MAX, 0};
        }
        if(start <= left && right <= end) {
            return tree[node];
        }

        int mid = (left+right) / 2;
        item tempAns1 = calc(start, end, node*2+1, left, mid);
        item tempAns2 = calc(start, end, node*2+2, mid, right);
        return merge(tempAns1, tempAns2);
    }

    item calc(int start, int end) {
        return calc(start, end, 0, 0, size);
    }
    
};


int main(void) {

    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> nums(n+1);

    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    segmentTree tree;
    tree.init(n);
    tree.build(nums);

    for(int i = 0; i < m; i++) {
        int op, num1, num2;
        scanf("%d %d %d", &op, &num1, &num2);
        switch (op)
        {
        case 1:
        tree.set(num1, num2);
        break;
        case 2:
        item ans = tree.calc(num1, num2);
        printf("%d %d\n", ans.minNum, ans.cntOfMinNum);
            break;
        }
    }

    return 0;
} 