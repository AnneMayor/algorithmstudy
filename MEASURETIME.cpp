#include <bits/stdc++.h>

using namespace std;

struct FenWickTree {
    vector<int> tree;

    FenWickTree(int n) : tree(n+1) {

    }

    int sum(int pos) {
        pos++;
        int result = 0;
        while (pos > 0)
        {
            result += tree[pos];
            pos &= (pos-1);
        }

        return result;
    }

    void add(int pos, int val) {
        pos++;
        while(pos < tree.size()) {
            tree[pos] += val;
            pos += (pos&-pos);
        }
    }

};

long long getCount(const vector<int> & nums) {

    FenWickTree fw(1000000);
    long long result = 0;

    for(int i = 0; i < nums.size(); i++) {
        result += fw.sum(999999) - fw.sum(nums[i]);
        fw.add(nums[i], 1);
    }

    return result;
}

int main(void) {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int n;
        scanf("%d", &n);

        vector<int> nums(n, 0);

        for(int i = 0; i < n; i++) {
            int num;
            scanf("%d", &num);
            nums.push_back(num);
        }

        printf("%lld\n", getCount(nums));
    }

    return 0;
}