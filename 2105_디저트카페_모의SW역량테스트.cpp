#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 105;

struct Pos
{
    int x, y;
    int dist;
    int direction;
};

int dessertMap[MAX][MAX];
int checkVisited[MAX][MAX];
bool isEaten[MAX];

int n;
int ans;

// 방향 전환 자체를 사각형 이동방향으로 결정하기
int dx[] = {1, 1, -1, -1};
int dy[] = {-1, 1, 1, -1};

void dfs(Pos p)
{
    int x = p.x, y = p.y;
    int dist = p.dist;
    int direction = p.direction;

    if(checkVisited[x][y] == 2 && dist >= 4) {
        if(ans < dist) ans = dist;
        return ;
    }

    for(int i = 0; i < 2; i++) {
        int nx = x + dx[direction+i >= 4 ? 0: direction+i];
        int ny = y + dy[direction+i >= 4 ? 0: direction+i];

        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

        if(!checkVisited[nx][ny] && !isEaten[dessertMap[nx][ny]]) {
            checkVisited[nx][ny] = 1;
            isEaten[dessertMap[nx][ny]] = true;
            p.x = nx, p.y = ny, p.dist = dist + 1, p.direction = direction+i;
            dfs(p);
            checkVisited[nx][ny] = 0;
            isEaten[dessertMap[nx][ny]] = false;
        } else if(checkVisited[nx][ny] == 2) {
            p.x = nx, p.y = ny, p.dist = dist + 1, p.direction = direction+i;
            dfs(p);
        }
    }


    return;
}

int main()
{

    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++)
    {
        scanf("%d", &n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &dessertMap[i][j]);
            }
        }

        ans = -1;
        memset(checkVisited, 0, sizeof(checkVisited));
        memset(isEaten, false, sizeof(isEaten));

        // 탐색 시작
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                checkVisited[i][j] = 2;
                isEaten[dessertMap[i][j]] = true;
                Pos p;
                p.x = i;
                p.y = j;
                p.dist = 0;
                p.direction = 0;
                dfs(p);
                checkVisited[i][j] = 0;
                isEaten[dessertMap[i][j]] = false;
            }
        }

        printf("#%d %d\n", tc, ans);
    }

    return 0;
}