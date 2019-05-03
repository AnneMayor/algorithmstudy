#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 300

using namespace std;

int n;
int map[MAX][MAX];
bool isVisited[MAX][MAX];
queue<pair<int, int> > q;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int bfs(int x, int y) {
    pair<int, int> p;
    p.first = x;
    p.second = y;

    int cnt = 1;

    q.push(p);

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

            if(map[nx][ny] == 1) {
                if(!isVisited[nx][ny]) {
                    cnt += 1;
                    isVisited[nx][ny] = true;
                    p.first = nx;
                    p.second = ny;
                    q.push(p);
                }
            }
        }

    }

    return cnt;

}

int main() {

    scanf("%d\n", &n);

    int ans = 0;
    int count[300];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(map[i][j] == 1) {
                if(!isVisited[i][j]) {
                    isVisited[i][j] = true;
                    count[ans++] = bfs(i, j);
                 }
            }
        }
    }

    printf("%d\n", ans);
    sort(count, count+ans);
    for(int i = 0; i < ans; i++) {
        printf("%d\n", count[i]);
    }

    return 0;
}