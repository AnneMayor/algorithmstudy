#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 1e4+1;

char map[MAX][501];
bool isVisited[MAX][501];
int dx[] = {-1, 0, 1};
int dy[] = {1, 1, 1};

bool backtracking(int x, int y, int r, int c) {

    isVisited[x][y] = true;

    if(y == c-1) {
        return true;
    }

    for(int i = 0; i < 3; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
        if(!isVisited[nx][ny] && map[nx][ny] == '.') {
            if(backtracking(nx, ny, r, c)) return true;
        }
    }

    return false;
}

int main() {

    int r, c;
    scanf("%d %d", &r, &c);

    for(int i = 0; i < r; i++) {
        scanf("%s", map[i]);
    }

    memset(isVisited, false, sizeof(isVisited));
    int ans = 0;

    for(int i = 0; i < r; i++) {
        isVisited[i][0] = true;
        bool result = backtracking(i, 0, r, c);
        if(result) ans++;
    }

    printf("%d\n",ans);

    return 0;
}