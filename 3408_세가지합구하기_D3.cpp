#include <iostream>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        long long n;
        scanf("%lld", &n);

        long long s1 = n*(n+1) / 2;
        long long s3 = 2*s1;
        long long s2 = n*n;

        printf("#%d %lld %lld %lld\n", tc, s1, s2, s3);
    }

    return 0;
}