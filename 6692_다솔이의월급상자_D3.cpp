#include <iostream>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int n;
        scanf("%d", &n);

        double ans = 0.0f;
        for(int i = 0; i < n; i++) {
            double p; int m;
            scanf("%lf %d", &p, &m);

            ans += (p*m);
        }

        printf("#%d %lf\n", tc, ans);

    }

    return 0;
}