#include <iostream>
#include <queue>
#define MAX 350

using namespace std;

int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

class Point {
    public:
    int x;
    int y;
    int cnt;
};

int map[MAX][MAX];
bool isVisited[MAX][MAX];
queue<Point> q;
int n;
int ans;

void bfs(int x1, int y1, int fx1, int fy1, int cnt) {

    if(x1 == fx1 && y1 == fy1) {
        return ;
    }

    Point p;
    p.x = x1;
    p.y = y1;
    p.cnt = cnt;

    isVisited[x1][y1] = true;

    q.push(p);

    while(!q.empty()) {
        x1 = q.front().x;
        y1 = q.front().y;
        cnt = q.front().cnt;
        q.pop();

        for(int i = 0; i < 8; i++) {
            int nx = x1 + dx[i];
            int ny = y1 + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

            if(nx == fx1 && ny == fy1) {
                ans = cnt;
                return ;
            }

            if(!isVisited[nx][ny]) {
                isVisited[nx][ny] = true;
                p.x = nx;
                p.y = ny;
                p.cnt = cnt + 1;
                q.push(p);
            }
        }

    }
}

int main() {

    int T;
    scanf("%d", &T);

    for(int t = 0; t < T; t++) {

        memset(isVisited, false, sizeof(isVisited));
        while(!q.empty()) {
            q.pop();
        }

        scanf("%d", &n);
        int x, y;
        int fx, fy;
        scanf("%d %d", &x, &y);
        scanf("%d %d", &fx, &fy);
        ans = 0;
        bfs(x, y, fx, fy, 1);

        printf("%d\n", ans);
    }
    
    return 0;
}