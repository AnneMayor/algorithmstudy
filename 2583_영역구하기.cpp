#include <iostream>
#include <queue>
#include <algorithm>

#define MAX 105

using namespace std;

int map[MAX][MAX];
bool isVisited[MAX][MAX];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
queue<pair<int, int> > q;

int bfs(int x, int y, int num, int sizeX, int sizeY) {
    pair<int, int> p;
    p.first = x;
    p.second = y;
    
    num++;

    isVisited[x][y] = true;
    q.push(p);

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= sizeX || ny >= sizeY) continue;

            if(map[nx][ny] == 0) {
                if(!isVisited[nx][ny]) {
                    isVisited[nx][ny] = true;
                    num++;
                    p.first = nx;
                    p.second = ny;
                    q.push(p);
                }
            }

        }
    }

    return num;

}

int main() {

    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            map[i][j] = 0;
        }
    }

    for(int i = 0; i < k; i++) {
        int y1, x1, y2, x2;
        scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
        for(int x = x1; x < x2; x++) {
            for(int y = y1; y < y2; y++) {
                map[x][y] = 1;
            }
        }
    }

    // for(int i = 0; i < m; i++) {
    //     for(int j = 0; j < n; j++) {
    //         cout << map[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int ans[k];
    for(int i = 0; i < k; i++) {
        ans[i] = 0;
    }
    int cntOfArea = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(map[i][j] == 0) {
                if(!isVisited[i][j]) {
                    isVisited[i][j] = true;
                    ans[cntOfArea++] = bfs(i, j, 0, m, n);
                }
            }
        }
    }

    printf("%d\n", cntOfArea);

    sort(ans, ans+cntOfArea);

    for(int i = 0; i < cntOfArea; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    return 0;
}