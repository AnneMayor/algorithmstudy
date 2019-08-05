#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int n, a, b;
        scanf("%d %d %d", &n, &a, &b);

        long long ans = 1e10;
        for(long long i = 1; i <= n; i++) {
            for(long long j = 1; i*j <= n; j++) {
                long long tmp = a*abs(i-j) + b*(n-i*j);
                ans = min(ans, tmp);
            }
        }

        printf("#%d %lld\n", tc, ans);

    }

    return 0;
}