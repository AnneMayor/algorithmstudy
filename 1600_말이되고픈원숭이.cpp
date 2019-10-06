#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
const int MAX = 205;

int map[MAX][MAX];
int cntOfStep[MAX][MAX][35];
int w, h;

int dxK[] = {-2, 2, -2, 2, -1, 1, -1, 1};
int dyK[] = {-1, 1, 1, -1, -2, 2, 2, -2};
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1}; 

struct Point {
    int x;
    int y;
    int k;
};

queue<Point> q;

void bfs(int x, int y, int cntOfK) {
    Point p;
    p.x = x;
    p.y = y;
    p.k = cntOfK;
    cntOfStep[x][y][cntOfK] = 0;
    q.push(p);

    while (!q.empty())
    {
        x = q.front().x;
        y = q.front().y;
        cntOfK = q.front().k;
        q.pop();

        if(x == h-1 && y == w-1) {
            return ;
        }

        if(cntOfK > 0) {
            for(int i = 0; i < 8; i++) {
                int nx = x + dxK[i];
                int ny = y + dyK[i];

                if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;

                if(map[nx][ny] == 0) {
                    if(cntOfStep[nx][ny][cntOfK-1] > cntOfStep[x][y][cntOfK] + 1) {
                        cntOfStep[nx][ny][cntOfK-1] = cntOfStep[x][y][cntOfK] + 1;
                        p.x = nx;
                        p.y = ny;
                        p.k = cntOfK-1;
                        q.push(p);
                    }
                }
            }
        }

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;

            if(map[nx][ny] == 0) {
                if(cntOfStep[nx][ny][cntOfK] > cntOfStep[x][y][cntOfK] + 1 ) {
                    cntOfStep[nx][ny][cntOfK] = cntOfStep[x][y][cntOfK] + 1;
                    p.x = nx;
                    p.y = ny;
                    p.k = cntOfK;
                    q.push(p);
                }
            }
        }

    }

    return ;
    
}

int main() {

    int k;
    scanf("%d", &k);
    scanf("%d %d", &w, &h);
    memset(cntOfStep, 9999999, sizeof(cntOfStep));

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    bfs(0, 0, k);
    int ans = 1e9;
    for(int i = 0; i <= k; i++) {
        if(ans > cntOfStep[h-1][w-1][i]) ans = cntOfStep[h-1][w-1][i];
    }

    if(ans >= 9999999) printf("-1\n");
    else printf("%d\n", ans);

    return 0;
}