#include <bits/stdc++.h>

using namespace std;
const int MAX = 100;

int candy[MAX];
int orange[MAX];

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int n;
        scanf("%d", &n);

        // input candy
        for(int i = 0; i < n; i++) {
            scanf("%d", &candy[i]);
        }

        // input orange
        for(int i = 0; i < n; i++) {
            scanf("%d", &orange[i]);
        }

        int minCandy = 1e9+5;
        int minOrange = 1e9+5;

        for(int i = 0; i < n; i++) {
            if(minCandy > candy[i]) minCandy = candy[i];
        }

        for(int i = 0; i < n; i++) {
            if(minOrange > orange[i]) minOrange = orange[i];
        }

        long long ans = 0;
        for(int i = 0; i < n; i++) {
            int diffCandy = candy[i] - minCandy;
            int diffOrange = orange[i] - minOrange;
            ans += (diffCandy > diffOrange ? diffCandy : diffOrange);
        }

        printf("%lld\n", ans);
    }

    return 0;
}