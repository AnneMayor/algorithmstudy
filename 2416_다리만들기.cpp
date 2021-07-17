#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 105;

int map[MAX][MAX];
int isVisited[MAX][MAX];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void search(int x, int y, int num, int n);
void findMinPath(int x, int y, int path, int n);
int ans;

struct Point {
    int x, y, path;
};

int main(void) {

    ios::sync_with_stdio(0);

    int n;
    scanf("%d", &n);
    ans = 1e9;

    memset(isVisited, 0, sizeof(isVisited));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    int numOfLand = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(map[i][j] == 1) {
                if(!isVisited[i][j]) {
                    search(i, j, numOfLand, n);
                    numOfLand++;
                }
            }
        }
    }

    memset(isVisited, 0, sizeof(isVisited));

    // cout << "------------------------" << endl;
    // for(int i = 0 ; i < n; i++) {
    //     for(int j = 0; j < n; j++) {
    //         cout << map[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(map[i][j] > 0) {
                findMinPath(i, j, 0, n);
                memset(isVisited, 0, sizeof(isVisited));
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}

void search(int x, int y, int cnt, int n) {
    isVisited[x][y] = 1;
    map[x][y] = cnt;

    queue<pair<int, int> > q;
    q.push(make_pair(x, y));

    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        cnt = map[x][y];
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

            if(map[nx][ny] == 1 && !isVisited[nx][ny]) {
                isVisited[nx][ny] = 1;
                map[nx][ny] = cnt;
                q.push(make_pair(nx, ny));
            }
        }
    }

    return ;
}

void findMinPath(int x, int y, int path, int n) {
    isVisited[x][y] = 1;
    int numOfLand = map[x][y];
    queue<Point> q;
    Point p;
    p.x = x, p.y = y, p.path = path;
    q.push(p);

    while (!q.empty())
    {
        p = q.front();
        q.pop();
        x = p.x, y = p.y, path = p.path;

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

            if(map[nx][ny] > 0) {
                if(map[nx][ny] != numOfLand) {
                    ans = min(ans, path);
                }
            } else {
                if(!isVisited[nx][ny]) {
                    isVisited[nx][ny] = 1;
                    p.x = nx, p.y = ny, p.path = path+1;
                    q.push(p);
                }
            }
        }
    }
    
    return ;
}