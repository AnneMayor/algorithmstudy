#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 105;

queue<pair<int, int> > q;
int sizeOfTrash[MAX][MAX];
int map[MAX][MAX];
int ans;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int n, m, k;

int findTrash(int r, int c) {

    int result = 1;
    sizeOfTrash[r][c] = 1;
    q.push(make_pair(r, c));

    pair<int, int> point;

    while (!q.empty())
    {
        point = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = point.first + dx[i];
            int ny = point.second + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

            if(map[nx][ny] == 1 && sizeOfTrash[nx][ny] == 0) {
                result += 1;
                sizeOfTrash[nx][ny] = 1;
                q.push(make_pair(nx, ny));
            }
        }

    }
    
    return result;
}

int main() {

    scanf("%d %d %d", &n, &m, &k);

    memset(sizeOfTrash, 0, sizeof(sizeOfTrash));
    memset(map, 0, sizeof(map));
    ans = -1e4;

    for(int i = 0; i < k; i++) {
        int r, c;
        scanf("%d %d", &r, &c);

        map[r-1][c-1] = 1;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j] && !sizeOfTrash[i][j]) {
                int tmp = findTrash(i, j);
                if(ans < tmp) ans = tmp;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}