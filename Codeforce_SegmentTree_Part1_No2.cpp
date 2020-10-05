#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

struct segmenTree {
    int size;
    vector<int> tree;

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
        tree[node] = min(tree[node*2+1], tree[node*2+2]);
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
        tree[node] = min(tree[node*2+1], tree[node*2+2]);

        return ;
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
        return ;
    }

    long long calc(int start, int end, int node, int left, int right) {
        if(left >= end || start >= right) return INT_MAX;
        if(start <= left && right <= end) return tree[node];
        int mid = (left+right) / 2;
        return min(calc(start, end, node*2+1, left, mid), calc(start, end, node*2+2, mid, right));
    }   

    long long calc(int left, int right) {
        return calc(left, right, 0, 0, size);
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
            printf("%lld\n", tree.calc(num1, num2));
        }

        m--;
    }
    

    return 0;
}