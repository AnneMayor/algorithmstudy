#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
const int MAX = 55;

int map[MAX][MAX];
int check[MAX][MAX];
bool isChecked[MAX];
int n, m;
int ans;

vector<pair<int, int> > virusList;
vector<pair<int, int> > virus;
queue<pair<int, int> > q;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs()
{

    memset(check, -1, sizeof(check));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == 1)
            {
                check[i][j] = -2;
            }
        }
    }

    for (int i = 0; i < virus.size(); i++)
    {
        q.push(make_pair(virus[i].first, virus[i].second));
        check[virus[i].first][virus[i].second] += 1;
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

            if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;

            if (check[nx][ny] == -1)
            {
                check[nx][ny] = check[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

void dfs(int idx, int cnt)
{
    if (cnt >= m)
    {
        bfs();

        // 최소 시간 확인
        int tmp = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (tmp < check[i][j])
                    tmp = check[i][j];
                else if (check[i][j] == -1)
                    return;
            }
        }

        if (ans == -1)
            ans = tmp;
        else if (ans > tmp)
            ans = tmp;
        else
            return;

        // cout << "////////////////////////////////////" << endl;

        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < n; j++) {
        //         cout << check[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        return;
    }

    for (int i = idx+1; i < virusList.size(); i++)
    {
        virus.push_back(virusList[i]);
        dfs(i, cnt + 1);
        virus.pop_back();
    }
}

int main()
{

    scanf("%d %d", &n, &m);

    virus.clear();
    virusList.clear();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 2)
            {
                virusList.push_back(make_pair(i, j));
            }
        }
    }

    ans = -1;
    memset(isChecked, false, sizeof(isChecked));

    for (int i = 0; i < virusList.size(); i++)
    {
        virus.push_back(virusList[i]);
        dfs(i, 1);
        virus.pop_back();
    }

    printf("%d\n", ans);

    return 0;
}