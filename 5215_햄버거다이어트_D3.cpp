#include <iostream>
#include <string.h>

using namespace std;

int d[25][10005];

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {

        memset(d, 0, sizeof(d));

        int n, l;
        scanf("%d %d", &n, &l);

        int flavor[n+1];
        int kalories[n+1];

        for(int i = 1; i <= n; i++) {
            scanf("%d %d", &flavor[i], &kalories[i]);
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= l; j++) {
                if(j < kalories[i]) {
                    d[i][j] = d[i-1][j];
                } else if(d[i-1][j-kalories[i]]+flavor[i] > d[i-1][j]) {
                    d[i][j] = d[i-1][j-kalories[i]]+flavor[i];
                } else {
                    d[i][j] = d[i-1][j];
                }
            }
        }

        int ans = 0;

        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= l; j++) {
                if(ans < d[i][j]) ans = d[i][j];
            }
        }

        printf("#%d %d\n", tc, ans);

    }

    return 0;
}