#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
const int MAX = 305;

int map[MAX][MAX];
int checkLand[MAX][MAX];
queue<pair<int, int> > q;
queue<pair<int, int> > numOfLandQ;
int ans;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void countLand(int n, int m, int x, int y, int numOfLand)
{

    pair<int, int> p;
    p.first = x;
    p.second = y;
    numOfLandQ.push(p);

    while (!numOfLandQ.empty())
    {
        x = numOfLandQ.front().first;
        y = numOfLandQ.front().second;
        numOfLandQ.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;

            if (checkLand[nx][ny] == 0 && map[nx][ny] != 0)
            {
                checkLand[nx][ny] = numOfLand;
                p.first = nx;
                p.second = ny;
                numOfLandQ.push(p);
            }
        }
    }
}

int checkNumOfLand(int n, int m)
{

    int numOfLand = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] != 0 && checkLand[i][j] == 0)
            {
                numOfLand += 1;
                checkLand[i][j] = numOfLand;
                countLand(n, m, i, j, numOfLand);
            }
        }
    }

    return numOfLand;
}

void bfsLand(int n, int m)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] != 0)
            {
                pair<int, int> p;
                p.first = i;
                p.second = j;
                checkLand[i][j] = 1;
                q.push(p);
            }
        }
    }

    while (!q.empty())
    {

        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        int cntOfWater = 0;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;

            if (checkLand[nx][ny] == 0 && map[nx][ny] == 0)
            {
                cntOfWater += 1;
            }
        }

        map[x][y] -= cntOfWater;
        if (map[x][y] < 0)
            map[x][y] = 0;
    }
}

int main()
{

    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(i == 0 || j == 0 || i == n-1 || j == m-1) map[i][j] = 0;
            scanf("%d", &map[i][j]);
        }
    }

    ans = 0;

    memset(checkLand, 0, sizeof(checkLand));

    int check = checkNumOfLand(n, m);
    while (check < 2)
    {
        if (check == 0) {
            ans = 0;
            break;
        }
            
        memset(checkLand, 0, sizeof(checkLand));

        ans += 1;
        bfsLand(n, m);

        // cout << "-------------------------------------" << endl;
        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < m; j++) {
        //         cout << map[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        memset(checkLand, 0, sizeof(checkLand));
        check = checkNumOfLand(n, m);
    }

    printf("%d\n", ans);

    return 0;
}