#include <iostream>
#include <queue>
#include <string.h>
#define MAX 1005

using namespace std;

class Point {
    public:
    int x;
    int y;
    int cnt;
    int cntOfBlock;
};
int map[MAX][MAX];
// 방문여부 체크 배열(bool대신 int타입으로 시작!)
int ans[MAX][MAX][15];
queue<Point> q;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m, k;
long long int cnt = 0;

void bfs(int x1, int y1, int cnt1, int cntOfBlock1) {
   
    Point p;
    p.x = x1;
    p.y = y1;
    p.cnt = cnt1;
    p.cntOfBlock = cntOfBlock1;

    ans[x1][y1][cntOfBlock1] = cnt1;

    q.push(p);

    while(!q.empty()) {
        x1 = q.front().x;
        y1 = q.front().y;
        cnt1 = q.front().cnt;
        cntOfBlock1 = q.front().cntOfBlock;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x1 + dx[i];
            int ny = y1 + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

            if(nx == n-1 && ny == m-1) {
                cnt = cnt1+1;
                return;
            }

            if(map[nx][ny] == 0 && ans[nx][ny][cntOfBlock1] == 0) {
                p.x = nx;
                p.y = ny;
                p.cnt = cnt1+1;
                p.cntOfBlock = cntOfBlock1;
                ans[nx][ny][cntOfBlock1] = cnt1 + 1;
                q.push(p);
            }

            if(map[nx][ny] == 1 && cntOfBlock1 > 0 && ans[nx][ny][cntOfBlock1] == 0) {
                p.x = nx;
                p.y = ny;
                p.cnt = cnt1 + 1;
                p.cntOfBlock = cntOfBlock1-1;
                ans[nx][ny][cntOfBlock1-1] = cnt1 + 1;
                q.push(p);
            }
        }
    }
}

int main() {

    scanf("%d %d %d", &n, &m, &k);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            
            scanf("%1d", &map[i][j]);
        }
    }

    while(!q.empty()) {
        q.pop();
    }

    memset(ans, 0, sizeof(ans));

    if(n == 1 && m == 1) {
        printf("%d\n", 1);
        return 0;
    }

    bfs(0, 0, 1, k);

    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         printf("%d ", ans[i][j][1]);
    //     }
    //     printf("\n");
    // }

    if(cnt == 0) {
        printf("%d\n", -1);
    } else {
        printf("%lld\n", cnt);
    }

    return 0;
}