#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 15;

bool isVisited[MAX];
int map[MAX][MAX];
int n, m;
int dist;

void dfs(int idx, int cnt) {

    if(cnt > dist) dist = cnt;

    for(int i = 1; i <= n; i++) {
        if(!isVisited[i] && map[idx][i] == 1) {
            isVisited[i] = true;
            dfs(i, cnt+1);
            isVisited[i] = false;
        }
    }
}

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        
        scanf("%d %d", &n, &m);
        dist = 0;

        memset(isVisited, false, sizeof(isVisited));
        memset(map, 0, sizeof(map));

        for(int i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            map[a][b] = 1;
            map[b][a] = 1;
        }

        int ans = 1;
        for(int i = 1; i <= n; i++) {
            isVisited[i] = true;
            dfs(i, ans);
            isVisited[i] = false;
        }
        printf("#%d %d\n", tc, dist);

    }

    return 0;
}