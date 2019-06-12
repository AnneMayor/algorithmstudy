#include <iostream>
#include <string.h>

using namespace std;
const int MAX = 100;

int isConnected[MAX][MAX];
int vertex[MAX];
int n, m;
int ans;

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {

        memset(isConnected, 0, sizeof(isConnected));

        scanf("%d %d", &n, &m);

        int cnt = 1;
        for(int i = 0; i < n; i++) {
            vertex[i] = cnt;
            cnt += 1;
        }

        for(int i = 0; i < m; i++) {
            int s,e;
            scanf("%d %d", &s, &e);

            isConnected[s][e] = 1;
            isConnected[e][s] = 1;
        }

        ans = 0;

        for(int i = 1; i <= n; i++) {
            for(int j = i; j <= n; j++) {
                if(isConnected[i][j] == 1) {
                    for(int k = j; k <= n; k++) {
                        if(isConnected[j][k] == 1 && isConnected[i][k] == 1) {
                            ans += 1;
                        }
                    }
                }
            }
        }

        printf("#%d %d\n", tc, ans);
        
    }

    return 0;
}