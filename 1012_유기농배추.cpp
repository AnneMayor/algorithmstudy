#include <iostream>
#include <queue>
#define MAX 3000

using namespace std;

int m, n, k;
int map[MAX][MAX];
bool isVisited[MAX][MAX];
int dx[] = {0, 0,-1, 1};
int dy[] = {-1, 1, 0, 0};
queue<pair<int, int> > q;

void bfs(int x, int y) {

    pair<int, int> p;
    p.first = x;
    p.second = y;
    q.push(p);

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

            if(map[nx][ny] == 1) {
                if(!isVisited[nx][ny]) {
                    isVisited[nx][ny] = true;
                    p.first = nx;
                    p.second = ny;
                    q.push(p);
                }
            }
        }

    }
    
}


void setMap() {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            map[i][j] = 0;
        }
    }
}

void setVisited() {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            isVisited[i][j] = false;
        }
    }
}

int main() {

    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        m = 0;
        n = 0;
        k = 0;
        scanf("%d %d %d", &m, &n, &k);

        setMap();
        setVisited();

        for(int i = 0; i < k; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            map[x][y] = 1;
        }

        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(map[i][j] == 1) {
                    if(!isVisited[i][j]) {
                        ans += 1;
                        isVisited[i][j] = true;
                        bfs(i, j);
                    }
                }
            }
        }

        cout << ans << endl;
    }

    return 0;

}