#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
const int MAX = 11;

char map[MAX][MAX];
int d[MAX][1<<MAX];

bool check(int current, int prev, int m) {

    for(int i = 1; i < (1<<m); i <<= 1) {
        if(current&i) {
            if((prev & (i*2)) || (prev & (i/2))) return false;
        }
    }

    return true;
}

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int n, m;
        scanf("%d %d", &n, &m);

        for(int i = 1; i <= n; i++) {
            scanf("%s", map[i]);
        }

        memset(d, 0, sizeof(d));

        int ans = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < (1<<m); j++) {
                int mMax = 0, bit = 0;
                bool isPossible = true;
                int idx = m-1;
                for(int k = 1; k < (1<<m); k <<= 1) {
                    if((j&k)&&map[i][idx] == '.') bit++;
                    if(j&k&&j & (k<<1)) {
                        isPossible = false;
                        break;
                    }
                    idx--;
                }
                if(!isPossible) continue;

                for(int k = 0; k < (1<<m); k++) {
                    if(check(j, k, m)) {
                        if(mMax < d[i-1][k]) {
                            mMax = d[i-1][k];
                        }
                    }
                }

                d[i][j] = mMax + bit;
                ans = max(ans, d[i][j]);
            }
        }

        printf("%d\n", ans);

    }

    return 0;
}