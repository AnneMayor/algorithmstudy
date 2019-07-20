#include <iostream>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {

        int a, b;
        scanf("%d %d", &a, &b);

        int cnt = a/b;
        long long ans = 0;
        for(int i = 1; i <= cnt; i++) {
            ans += (long long) 2*i - 1;
        }

        printf("#%d %lld\n", tc, ans);

    }

    return 0;
}