#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

struct segmenTree {
    int size;
    vector<long long> tree;

    void init(int n) {
        size = 1;
        while (size < n) {size *= 2;}

        tree.assign(2*size, 0LL);
        return ;
    }

    void build(const vector<int> & nums, int node, int start, int end) {
        if(end - start == 1) {
            if(start < (int) nums.size()) {
                tree[node] = nums[start];
            }

            return ;
        }

        int mid = (start+end) / 2;
        build(nums, node*2+1, start, mid);
        build(nums, node*2+2, mid, end);
        tree[node] = tree[node*2+1] + tree[node*2+2];
        return ;
    }

    void build(const vector<int> & nums) {
        build(nums, 0, 0, size);
    }

    void set(int i, int v, int node, int left, int right) {
        if(right - left == 1) {
            tree[node] = v;
            return ;
        }

        int mid = (left+right) / 2;
        if(i < mid) {
            set(i, v, node*2+1, left, mid);       
        } else {
            set(i, v, node*2+2, mid, right);
        }
        tree[node] = tree[node*2+1] + tree[node*2+2];

        return ;
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
        return ;
    }

    long long sum(int start, int end, int node, int left, int right) {
        if(left >= end || start >= right) return 0;
        if(start <= left && right <= end) return tree[node];
        int mid = (left+right) / 2;
        return sum(start, end, node*2+1, left, mid) + sum(start, end, node*2+2, mid, right);
    }

    long long sum(int left, int right) {
        return sum(left, right, 0, 0, size);
    }
};

int main(void) {

    int n, m;
    scanf("%d %d", &n, &m);

    segmenTree tree;
    tree.init(n);

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    tree.build(nums);

    while (m != 0)
    {
        int op, num1, num2;
        scanf("%d %d %d", &op, &num1, &num2);

        if(op == 1) {
            tree.set(num1, num2);
        } else {
            printf("%lld\n", tree.sum(num1, num2));
        }

        m--;
    }
    

    return 0;
}