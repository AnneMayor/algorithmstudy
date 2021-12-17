#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 2005;
int dp[MAX][MAX];

int main(void) {

    ios::sync_with_stdio(false);
    memset(dp, 0, sizeof(dp));

    int n;
    scanf("%d", &n);

    int nums[n+1];

    for(int i = 1; i <= n; i++) {
        int num;
        scanf("%d", &num);
        nums[i] = num;
    }

    // dist = 1
    for(int i = 1; i <= n; i++) {
        dp[i][i] = 1;
    }

    // dist = 2
    for(int i = 1; i < n; i++) {
        if(nums[i] == nums[i+1]) dp[i][i+1] = 1;
    }

    // dist = 3
    for(int d = 2; d < n; d++) {
        for(int i = 1; i <= n-d; i++) {
            dp[i][i+d] = dp[i+1][i+d-1] ? nums[i] == nums[i+d] : 0;
        }
    }

    // for(int i = 1; i <= n; i++) {
    //     for(int j = 1; j <= n; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int m;
    scanf("%d", &m);
    for(int tc = 1; tc <= m; tc++) {
        int s, e;
        scanf("%d %d", &s, &e);
        printf("%d\n", dp[s][e]);
    }


    return 0;
}