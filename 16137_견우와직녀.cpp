#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>

using namespace std;
const int MAX = 15;

int map[MAX][MAX];
int cntOfStep[MAX][MAX][2]; // 0: 오작교 건설, 1: 오작교 미건설
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct Point
{
    int x;
    int y;
    bool buildBridge; // 오작교 건설 유무
    bool crossBridge; // 이전 오작교 건넜는지 유무
};

int n, m;
queue<Point> q;

bool isOk(int x, int y)
{
    bool ret = true;
    int cnt = 0;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= n || ny >= n)
            continue;

        if (map[nx][ny] == 0)
        {
            if (cnt > 1)
            {
                ret = false;
                break;
            }
            else
                cnt++;
        }
    }

    return ret;
}

int getTmpTime(int time, int period)
{
    int ret = time;

    while (1)
    {
        if (ret % period == 0)
            break;
        ret++;
    }

    return ret;
}

void bfs(int x, int y, bool flagBridge, bool flagCross)
{

    Point p;
    p.x = x;
    p.y = y;
    p.buildBridge = flagBridge;
    p.crossBridge = flagCross;
    cntOfStep[x][y][0] = 0;
    q.push(p);

    while (!q.empty())
    {
        x = q.front().x;
        y = q.front().y;
        flagBridge = q.front().buildBridge;
        flagCross = q.front().crossBridge;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;

            if (map[nx][ny] == 1)
            {
                if (cntOfStep[nx][ny][flagBridge] > cntOfStep[x][y][flagBridge] + 1)
                {
                    cntOfStep[nx][ny][flagBridge] = cntOfStep[x][y][flagBridge] + 1;
                    p.x = nx;
                    p.y = ny;
                    p.buildBridge = flagBridge;
                    p.crossBridge = false;
                    q.push(p);
                }
            }
            else if (map[nx][ny] == 0)
            {
                if (flagBridge == false && flagCross == false)
                {
                    if (isOk(nx, ny))
                    {
                        int tmpTime = getTmpTime(cntOfStep[x][y][flagBridge] + 1, m);
                        if (cntOfStep[nx][ny][1] > tmpTime)
                        {
                            cntOfStep[nx][ny][1] = tmpTime;
                            p.x = nx;
                            p.y = ny;
                            p.buildBridge = true;
                            p.crossBridge = true;
                            q.push(p);
                        }
                    }
                }
            }
            else
            {
                if (flagCross == false)
                {
                    int tmpTime = getTmpTime(cntOfStep[x][y][flagBridge] + 1, map[nx][ny]);
                    if (cntOfStep[nx][ny][flagBridge] > tmpTime)
                    {
                        cntOfStep[nx][ny][flagBridge] = tmpTime;
                        p.x = nx;
                        p.y = ny;
                        p.buildBridge = flagBridge;
                        p.crossBridge = true;
                        q.push(p);
                    }
                }
            }
        }
    }

    return;
}

int main()
{

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }

    memset(cntOfStep, 9999999, sizeof(cntOfStep));

    bfs(0, 0, false, false);
    
    printf("%d\n", min(cntOfStep[n - 1][n - 1][0], cntOfStep[n - 1][n - 1][1]));

    return 0;
}