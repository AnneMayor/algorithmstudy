#include <iostream>

using namespace std;
const int MAX = 105;

long long dp[MAX] = {0, 1, 1, 1, 2, 2};

int main()
{

    int T;
    scanf("%d", &T);

    for (int i = 6; i <= 100; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 5];
    }
    for (int tc = 1; tc <= T; tc++)
    {
        int n;
        scanf("%d", &n);

        printf("#%d %d\n", tc, dp[n]);
    }

    return 0;
}