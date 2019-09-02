#include <iostream>
#include <queue>

using namespace std;
const int MAX = 15;

int n, m;
int map[MAX][MAX];
int tmpMap[MAX][MAX];
int afterVirus[MAX][MAX];
int ans;
queue<pair<int, int> > q;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void virusSearch()
{
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            afterVirus[i][j] = tmpMap[i][j];
            if(afterVirus[i][j] == 2) {
                q.push(make_pair(i,j));
            }
        }
    }

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;

            if (afterVirus[nx][ny] == 0)
            {
                afterVirus[nx][ny] = 2;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

void dfs(int cntOfWall)
{

    if (cntOfWall >= 3)
    {
        // BFS 탐색
        virusSearch();

        // 안전영역 확인
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (afterVirus[i][j] == 0)
                {
                    cnt++;
                }
            }
        }

        if (ans < cnt) {
            ans = cnt;
        }

        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (tmpMap[i][j] == 0)
            {
                tmpMap[i][j] = 1;
                dfs(cntOfWall + 1);
                tmpMap[i][j] = 0;
            }
        }
    }
}

int main()
{

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }

    ans = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 0)
            {
                for(int x = 0; x < n; x++) {
                    for(int y = 0; y < m; y++) {
                        tmpMap[x][y] = map[x][y];
                    }
                }
                tmpMap[i][j] = 1;
                dfs(1);
                tmpMap[i][j] = 0;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}