#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
const int MAX = 55;

int cntOfRoute[MAX][MAX];
char map[MAX][MAX];
queue<pair<int, int> > q;

int n, m;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int x, int y)
{

    pair<int, int> p;
    p.first = x;
    p.second = y;
    q.push(p);

    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // cout << "nx: " << nx << " / ny: " << ny << endl;

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;

            if (map[x][y] != '*' && map[nx][ny] == 'D')
            {
                cntOfRoute[nx][ny] = cntOfRoute[x][y] + 1;
                return;
            }

            // 물일 경우
            if (map[x][y] == '*')
            {
                if (map[nx][ny] == '.')
                {
                    map[nx][ny] = '*';
                    p.first = nx;
                    p.second = ny;
                    q.push(p);
                }
            }
            // 고슴도치일 경우
            else
            {
                if (map[nx][ny] == '.')
                {
                    map[nx][ny] = 'S';
                    cntOfRoute[nx][ny] = cntOfRoute[x][y] + 1;
                    p.first = nx;
                    p.second = ny;
                    q.push(p);
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
        scanf("%s", map[i]);
    }

    memset(cntOfRoute, 0, sizeof(cntOfRoute));

    pair<int, int> p;
    int idxX = -1, idxY = -1;
    int ansX = -1, ansY = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 'S')
            {
                idxX = i;
                idxY = j;
            }
            else if (map[i][j] == '*')
            {
                p.first = i;
                p.second = j;
                q.push(p);
            }
            else if (map[i][j] == 'D')
            {
                ansX = i;
                ansY = j;
            }
        }
    }

    bfs(idxX, idxY);

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << map[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // cout << "---------------------------------------------------" << endl;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << cntOfRoute[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    if (cntOfRoute[ansX][ansY] == 0)
    {
        printf("KAKTUS\n");
    }
    else
    {
        printf("%d\n", cntOfRoute[ansX][ansY]);
    }

    return 0;
}