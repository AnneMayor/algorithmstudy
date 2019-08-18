#include <iostream>
#include <queue>
#define MAX 1015

using namespace std;

int map[MAX][MAX];
int cnt[MAX][MAX][2]; // 벽 통과 가능 여부도 동시 체크
queue<pair<pair<int, int>, int> > q;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int bfs(int x, int y, int value, bool one, int sizeX, int sizeY) {

    pair<pair<int, int>, int> p;
    p.first.first = x;
    p.first.second = y;
    p.second = one;
    
    cnt[x][y][one] = value;
    q.push(p);

    if(sizeX == 1 && sizeY == 1) {
        return cnt[x][y][one];
    }

    while(!q.empty()) {
        x = q.front().first.first;
        y = q.front().first.second;
        one = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx == sizeX-1 && ny == sizeY-1) {
                return cnt[x][y][one] + 1;
            }

            if(nx < 0 || ny < 0 || nx >= sizeX || ny >= sizeY) continue;

            if(map[nx][ny] == 0 && cnt[nx][ny][one] == 0) {
                cnt[nx][ny][one] = cnt[x][y][one] + 1;
                p.first.first = nx;
                p.first.second = ny;
                p.second = one;
                q.push(p);
            } 
            
            if(map[nx][ny] == 1 && one == 1) {
                cnt[nx][ny][one-1] = cnt[x][y][one] + 1;
                p.first.first = nx;
                p.first.second = ny;
                p.second = one-1;
                q.push(p);
            }
        }
    }

    return -1;
}

int main() {

    int n,m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%1d", &map[i][j]);
            cnt[i][j][0] = 0;
            cnt[i][j][1] = 0;
        }
    }

    long long int ans = bfs(0, 0, 1, 1, n, m);

    printf("%lld\n", ans);

    return 0;
}