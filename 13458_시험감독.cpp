#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 1e6 + 5;

int main()
{

    int N;
    scanf("%d", &N);

    long long ans = 0;
    int cntOfStudent[MAX];

    for (int tc = 1; tc <= N; tc++)
        scanf("%d", &cntOfStudent[tc]);

    int b, c;
    scanf("%d %d", &b, &c);

    for (int i = 1; i <= N; i++)
    {
        ans++;
        int tmp = cntOfStudent[i] - b;

        if (tmp > 0)
        {
            ans += (tmp / c);
            if (tmp % c > 0)
                ans++;
        }
    }

    printf("%lld\n", ans);

    return 0;
}