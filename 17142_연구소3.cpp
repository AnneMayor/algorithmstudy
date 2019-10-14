#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
const int MAX = 55;

int n, m;
int map[MAX][MAX];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct Virus
{
    int x, y;
};

vector<pair<int, int> > virus;
bool isChecked[15];
int ans, ret;
vector<pair<int, int> > ready;
queue<Virus> q;

bool isAllVisited(int checkMap[MAX][MAX])
{
    bool flag = true;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (checkMap[i][j] == -1)
            {
                flag = false;
                break;
            }
        }
        if (!flag)
            break;
    }

    return flag;
}

void bfs()
{

    int tempMap[MAX][MAX];
    int timeOfMap[MAX][MAX];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tempMap[i][j] = map[i][j];
            if (map[i][j] == 1)
                timeOfMap[i][j] = -2;
            else
                timeOfMap[i][j] = -1;
        }
    }

    Virus v;
    for (int i = 0; i < m; i++)
    {
        v.x = ready[i].first;
        v.y = ready[i].second;
        timeOfMap[v.x][v.y] = 0;
        q.push(v);
    }

    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;

            if(timeOfMap[nx][ny] == -1) {
                if(tempMap[nx][ny] == 0 || tempMap[nx][ny] == 2) {
                    timeOfMap[nx][ny] = timeOfMap[x][y] + 1;
                    v.x = nx;
                    v.y = ny;
                    q.push(v);
                }
            }
        }
    }

    // 모든 맵 다 방문했는지 체크
    if (isAllVisited(timeOfMap))
    {
        ret = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(tempMap[i][j] == 0) {
                    ret = max(ret, timeOfMap[i][j]);
                }
            }
        }

        if (ans == -1)
        {
            ans = ret;
        }
        else
            ans = min(ans, ret);
    }

    return;
}

void dfs(int idx, int cnt)
{

    if (cnt >= m)
    {
        bfs();
        return;
    }

    for (int i = idx; i < virus.size(); i++)
    {
        if (!isChecked[i])
        {
            isChecked[i] = true;
            ready.push_back(make_pair(virus[i].first, virus[i].second));
            dfs(i, cnt + 1);
            isChecked[i] = false;
            ready.pop_back();
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
            if (map[i][j] == 2)
                virus.push_back(make_pair(i, j));
        }
    }

    ans = -1;
    memset(isChecked, false, sizeof(isChecked));
    for (int i = 0; i < virus.size(); i++)
    {
        isChecked[i] = true;
        ready.push_back(make_pair(virus[i].first, virus[i].second));
        dfs(i, 1);
        isChecked[i] = false;
        ready.pop_back();
    }

    printf("%d\n", ans);

    return 0;
}