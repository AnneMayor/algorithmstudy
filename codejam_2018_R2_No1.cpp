#include <bits/stdc++.h>

using namespace std;
const int MAX = 105;

int pos[MAX];

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int n;
        scanf("%d", &n);

        int goal[MAX];
        for(int i = 1; i <= n; i++) scanf("%d", &goal[i]);
        for(int i = 1, j = 1; i <= n; i++) {
            for(int k = 0; k < goal[i]; k++) pos[j++] = i;
        }

        printf("Case #%d: ", tc);
        if(goal[1] == 0 || goal[n] == 0) {printf("IMPOSSIBLE\n"); continue;}

        int cnt = 0;
        for(int i = 1; i <= n; i++) cnt = max(cnt, abs(i-pos[i]));
        printf("%d\n", cnt+1);

        int now[MAX];
        for(int i = 1; i <= n; i++) now[i] = i;
        for(int i = 1; i <= cnt; i++) {
            char chMap[MAX] = {};
            for(int j = 1; j <= n; j++) chMap[j] = '.';
            for(int j = 1; j <= n; j++) {
                if(now[j] > pos[j]) {
                    chMap[now[j]] = '/';
                    now[j]--;
                } else if(now[j] < pos[j]) {
                    chMap[now[j]] = '\\';
                    now[j]++;
                }
            }
            for(int j=1;j<=n;j++) printf("%c", chMap[j]); printf("\n");
        }
        for(int i = 1; i <= n; i++) printf(".");
        printf("\n");

    }

    return 0;
}