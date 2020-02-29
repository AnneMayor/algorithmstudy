#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 255;

int m, n;
int map[MAX][MAX];
bool checkMap[MAX][MAX];

queue<pair<int, int> > q;
int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[] = {1, -1, 0, -1, 1, 0, -1, 1};

void checkCharacter(int x, int y) {
    checkMap[x][y] = true;
    q.push(make_pair(x, y));

    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;

            if(map[nx][ny] == 1 && !checkMap[nx][ny]) {
                checkMap[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }
    
}

int main() {

    scanf("%d %d", &m, &n);

    for(int i = 0; i < m; i++) {
        for(int j = 0; j <n; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    memset(checkMap, false, sizeof(checkMap));
    int ans = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(map[i][j] == 1 && !checkMap[i][j]) {
                ans++;
                checkCharacter(i, j);
            }
        }
    }

    printf("%d\n", ans);
    
    return 0;
}