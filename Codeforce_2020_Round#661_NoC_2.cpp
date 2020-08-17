#include <bits/stdc++.h>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int n;
        scanf("%d", &n);

        vector<int> nums;

        for(int i = 0; i < n; i++) {
            int num;
            scanf("%d", &num);
            nums.push_back(num);
        }

        sort(nums.begin(), nums.end());
        int ans = -1e5;

        for(int s = 2; s <= 2*n; s++) {
            int start = 0, end = n-1;
            int cnt = 0;
            while (start < end)
            {
                if(nums[start] + nums[end] == s) {
                    cnt++;
                    start++;
                    end--;
                } else if(nums[start] + nums[end] > s) {
                    end--;
                } else {
                    start++;
                }
            }
             ans = max(ans, cnt);
        }

        printf("%d\n", ans);
    }

    return 0;
}