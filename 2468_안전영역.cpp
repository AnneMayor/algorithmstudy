#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;

int Map[MAX][MAX];
bool isChecked[MAX][MAX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int cntOfSafe;
queue<pair<int, int> > q;

void checkMap(int height, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(height >= Map[i][j]) isChecked[i][j] = true;
        }
    }
}

void bfs(int x, int y, int n) {
    isChecked[x][y] = true;
    q.push(make_pair(x, y));

    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

            if(!isChecked[nx][ny]) {
                isChecked[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }

    }

    return ;
}

int main() {

    int n;
    scanf("%d", &n);

    int min = 1e4, max = -1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &Map[i][j]);
            if(min > Map[i][j]) min = Map[i][j];
            if(max < Map[i][j]) max = Map[i][j];
        }
    }

    int ans = -1;

    for(int i = min-1; i <= max; i++) {
        memset(isChecked, false, sizeof(isChecked));
        checkMap(i, n);
        cntOfSafe = 0;
        for(int x = 0; x < n; x++) {
            for(int y = 0; y < n; y++) {
                if(!isChecked[x][y]) {
                    cntOfSafe++;
                    bfs(x, y, n);
                }
            }
        }
        if(ans < cntOfSafe) ans = cntOfSafe;
    }

    printf("%d\n", ans);

    return 0;
}