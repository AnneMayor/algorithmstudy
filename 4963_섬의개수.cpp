#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
const int MAX = 55;

int map[MAX][MAX];
int numOfLand[MAX][MAX];
int w, h;
queue<pair<int, int> > q;

int dx[] = {-1, 1, 0, 0, -1, 1, 1, -1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

void bfs(int x, int y, int num) {

    pair<int, int> p;
    p.first = x;
    p.second = y;
    numOfLand[x][y] = num;
    q.push(p);

    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;

            if(map[nx][ny]) {
                if(numOfLand[nx][ny] == 0) {
                    numOfLand[nx][ny] = num;
                    p.first = nx;
                    p.second = ny;
                    q.push(p);
                }
            }

        }
    }
    

}

int main() {

    
    do {

        scanf("%d %d", &w, &h);
        memset(numOfLand, 0, sizeof(numOfLand));
        while (!q.empty())
        {
            q.pop();
        }

        if(w == 0 && h == 0) break;
        

        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                scanf("%d", &map[i][j]);
            }
        }

        int cntOfLand = 0;
        for(int i = 0 ; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(map[i][j] && numOfLand[i][j] == 0) {
                    cntOfLand++;
                    bfs(i, j, cntOfLand);
                }
            }
        }

        printf("%d\n", cntOfLand);

    } while (w != 0 && h != 0);

    return 0;
}