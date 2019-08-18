#include <iostream>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        long long n;
        scanf("%lld", &n);

        long long ans = -1;

        for(long long i = 1; i <= 1000000LL; i++) {
            long long temp = i*i*i;
            if(n == temp) {
                ans = i;
                break;
            }
            if(n < temp) break;
        }

        printf("#%d %lld\n", tc, ans);
    }

    return 0;
}