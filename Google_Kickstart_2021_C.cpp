#include <iostream>
#include <cstring>

using namespace std;
const int MAXN = 5005;
const int INF = 5e5;
const int MAX = 1e6+5;
long long preSum[MAXN][MAXN];
int nums[MAXN];

int main(void) {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int n, k;
        scanf("%d %d", &n, &k);

        int ans = INF;
        int isMakable[MAX];
        int cnt[MAX];

        // 부분합 배열 만들기
        for(int i = 1; i <= n; i++) {
            scanf("%d", &nums[i]);
        }

        memset(isMakable, 0, sizeof(isMakable));
        memset(cnt, INF, sizeof(cnt));

        for(int i = 1; i <= n; i++) {
            preSum[i][i-1] = 0;
            for(int j = i; j <= n; j++) {
                preSum[i][j] = preSum[i][j-1] + nums[j];
            }
        }

        for(int i = 1; i <= n; i++) {
            for(int j = i; j <= n; j++) {
                long long pSum = preSum[i][j];
                if(pSum > k) continue;
                if(pSum == k) 
                {
                    ans = min(ans, j - i + 1);
                }
                else {
                    if(isMakable[k-pSum]) {
                        ans = min(ans, j - i + 1 + cnt[k-pSum]);
                    }
                }
            }

            for(int j = i; j >= 1; j--) {
                long long pSum = preSum[j][i];
                if(pSum > k) continue;
                if(!isMakable[pSum]) {
                    isMakable[pSum] = 1;
                }
                cnt[pSum] = min(cnt[pSum], i - j + 1);
            }
        }

        if(ans == INF) printf("Case #%d: %d\n", tc, -1);
        else printf("Case #%d: %d\n", tc, ans);
    }

    return 0;
}