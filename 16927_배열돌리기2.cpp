#include <iostream>
#include <cmath>

using namespace std;
const int MAX = 305;

int map[MAX][MAX];
int ansMap[MAX][MAX];
int n, m, r;

pair<int, int> findPoint(int x, int y) {
    pair<int, int> result;

    // 1. 사이클 찾기
    const int in = min(x, min(y, min(n-1-x, m-1-y)));

    // 2. 회전한 후 위치 찾기
    int xMove = n-in*2-1;
    int yMove = m-in*2-1;
    int rot = (xMove + yMove) * 2;
    int cnt = r % rot;
    int xMin = in;
    int xMax = n-in-1;
    int yMin = in;
    int yMax = m-in-1;

    while (cnt > 0)
    {
        if(x == xMin && y > yMin) {
            int diff = min(cnt, y-yMin);
            y -= diff;
            cnt -= diff;
        } else if(x == xMax && y < yMax) {
            int diff = min(cnt, yMax-y);
            y += diff;
            cnt -= diff;
        } else if(y == yMin && x < xMax) {
            int diff = min(cnt, xMax - x);
            x += diff;
            cnt -= diff;
        } else if(y == yMax && x > xMin) {
            int diff = min(cnt, x-xMin);
            x -= diff;
            cnt -= diff;
        }
    }

    result.first = x;
    result.second = y;

    return result;
}

int main() {

    scanf("%d %d %d", &n, &m, &r);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j < m; j++) {
            pair<int, int> p = findPoint(i, j);
            ansMap[p.first][p.second] = map[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d ", ansMap[i][j]);
        }
        printf("\n");
    }

    return 0;
}