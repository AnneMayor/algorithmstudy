#include <bits/stdc++.h>

using namespace std;
const int MAX = 505;

int dp[MAX][MAX];
vector<pair<int, int> > possibleJugglings;

int main()
{
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= 33; i++)
    {
        for (int j = 0; j <= 33; j++)
        {
            if (i || j)
            {
                possibleJugglings.push_back(make_pair(i, j));
            }
        }
    }

    sort(possibleJugglings.begin(), possibleJugglings.end());

    for (auto &p : possibleJugglings)
    {
        int n = 500, m = 500;
        for (int i = n - p.first; i >= 0; i--)
        {
            for (int j = m - p.second; j >= 0; j--)
            {
                dp[i + p.first][j + p.second] = max(dp[i + p.first][j + p.second], dp[i][j] + 1);
            }
        }
    }


    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++)
    {
        int r, b;
        scanf("%d %d", &r, &b);

        printf("Case #%d: %d\n", tc, dp[r][b]);
    }

    return 0;
}