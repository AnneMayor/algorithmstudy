#include <iostream>

using namespace std;
const int MAX = 1e6 + 5;
const int INF = 1000000007;

long long d[MAX];

int pow(const int &k)
{

    long long ret = 1;
    long long fac = k;
    int exp = k;
    while (exp)
    {
        if (exp & 1)
        {
            ret *= fac;
        }

        exp >>= 1;
        fac *= fac;
        fac %= INF;
        ret %= INF;
    }

    return ret;
}

int main()
{

    int T;
    scanf("%d", &T);

    d[1] = 1;
    for (int i = 2; i <= 1000000; i++)
    {
        d[i] = (d[i - 1] + pow(i)) % INF;
    }

    for (int tc = 1; tc <= T; tc++)
    {
        int n;
        scanf("%d", &n);

        printf("#%d %lld\n", tc, d[n]);
    }

    return 0;
}