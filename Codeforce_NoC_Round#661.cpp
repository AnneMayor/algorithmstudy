#include <bits/stdc++.h>

using namespace std;
const int MAX = 100;

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int n;
        scanf("%d", &n);

        int nums[MAX];
        memset(nums, 0, sizeof(nums));

        for(int i = 0; i < n; i++) {
            int num;
            scanf("%d", &num);
            nums[num]++;
        }

        int ans = 0;
        for(int s = 2; s <= 2*n; s++) {
            int curCnt = 0;
            for(int i = 1; i < (s+1)/2; i++) {
                if(s-i > n) continue;
                curCnt += min(nums[i], nums[s-i]);
            }
            if(s%2 == 0) curCnt += nums[s/2]/2;
            ans = max(curCnt, ans);
        }

        printf("%d\n", ans);
    }


    return 0;
}