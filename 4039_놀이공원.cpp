#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;
const int MAX = 1005;

int map[MAX][MAX];
int cntOfStep[MAX][MAX];
queue<pair<int, int> > q;
int n, m;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void bfs(int x, int y, int step) {
    pair<int, int> p;
    p.first = x;
    p.second = y;
    cntOfStep[x][y] = step;

    q.push(p);

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        step = cntOfStep[x][y];
        q.pop();

        for(int i = 0; i < 4; i++) {

            int nx = x + dx[i];
            int ny = y + dy[i];

            // cout << "x: " << x << "/ y: " << y << endl;

            if(nx == n-1 && ny == m-1 && abs(map[x][y] - map[nx][ny]) <= 1) {
                // cout << "cntOfStep[n-1][m-1]: " <<  cntOfStep[nx][ny] << endl;
                if(cntOfStep[nx][ny] != 0) {
                    cntOfStep[nx][ny] = min(cntOfStep[nx][ny], step+1);
                } else {
                    cntOfStep[nx][ny] = step+1;
                }
                break;
            }

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

            if(cntOfStep[nx][ny] == 0 && abs(map[x][y]-map[nx][ny]) <= 1) {
                // cout << "nx: " << nx << "/ ny: " << ny << endl;
                // cout << cntOfStep[nx][ny] << endl;
                cntOfStep[nx][ny] += step+1;
                p.first = nx;
                p.second = ny;
                q.push(p);
            }

        }

    }

}

int main() {

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
        }
    } 

    memset(cntOfStep, 0, sizeof(cntOfStep));

    bfs(0, 0, 1);

    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         cout << cntOfStep[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    printf("%d\n", cntOfStep[n-1][m-1]);

    return 0;
}