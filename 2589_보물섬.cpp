#include <bits/stdc++.h>

using namespace std;
const int MAX = 55;

char M[MAX][MAX];
int timeOfBlock[MAX][MAX];
int convertMap[MAX][MAX];
int ans;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
queue<pair<int, int> > q;

void setDefault(int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            timeOfBlock[i][j] = convertMap[i][j];
        }
    }
}

void bfs(int x, int y, int n, int m) {
    // 첫 시작점 set
    timeOfBlock[x][y] = -1;
    q.push(make_pair(x, y));

    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

            if(timeOfBlock[nx][ny] == 0) {
                timeOfBlock[nx][ny] = timeOfBlock[x][y] + 1;
                if(ans < timeOfBlock[nx][ny]) ans = timeOfBlock[nx][ny];
                q.push(make_pair(nx, ny));
            }
        }
    }
    
    return ;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    ans = 0;

    for(int i = 0; i < n; i++) {
        scanf("%s", M[i]);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(M[i][j] == 'L') {
                convertMap[i][j] = 0;
            } else {
                convertMap[i][j] = -1;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(M[i][j] == 'L') {
                setDefault(n, m);
                bfs(i, j, n, m);
            }
        }
    }

    printf("%d\n", ans+1);


    return 0;
}