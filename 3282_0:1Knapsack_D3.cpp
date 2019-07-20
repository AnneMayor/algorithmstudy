#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;
const int MAX = 1005;

int v[MAX];
int c[MAX];

int d[MAX][MAX];

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int n, k;
        scanf("%d %d", &n, &k);

        for(int i = 1; i <= n; i++) {
            scanf("%d %d", &v[i], &c[i]);
        }

        memset(d, 0, sizeof(d));

        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= k; j++) {
                if(j < v[i]) {
                    d[i][j] = d[i-1][j];
                } else {
                    d[i][j] = max(d[i-1][j], d[i-1][j-v[i]]+c[i]);
                }
            }
        }

        int ans = 0;
        for(int i = 0; i <= k; i++) {
            ans = max(ans, d[n][i]);
        }

        printf("#%d %d\n", tc, ans);
    }

    return 0;
}