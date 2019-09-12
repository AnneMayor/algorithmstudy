#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 205;

int d[MAX][MAX];

int main()
{

    memset(d, 0, sizeof(d));

    int n, k;
    scanf("%d %d", &n, &k);

    // d[n][k] = d[m][l] + d[n-m][k-l] => 점화식

    for (int i = 0; i <= n; i++)
    {
        d[i][1] = 1;
    }

    for (int idx = 1; idx <= k; idx++)
    {
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                d[i][idx] += d[i-j][idx-1];
                d[i][idx] %= 1000000000;
            }
        }
    }

    printf("%d\n", d[n][k]);

    return 0;
}