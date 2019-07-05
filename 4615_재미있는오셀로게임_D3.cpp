#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 8;

int map[MAX][MAX];
int n, m;

void horizontal(int mark, int x, int y)
{

    bool flag = false;
    // 오른쪽
    for (int i = y + 1; i < n; i++)
    {
        if (map[x][i] == 0)
            break;
        if (map[x][i] == mark)
        {
            flag = true;
            break;
        }
    }
    // 바꾸기
    if (flag)
    {
        for (int i = y + 1; i < n; i++)
        {
            if (map[x][i] == mark || map[x][i] == 0)
                break;
            map[x][i] = mark;
        }
    }

    flag = false;
    // 왼쪽
    for (int i = y - 1; i >= 0; i--)
    {
        if (map[x][i] == 0)
            break;
        if (map[x][i] == mark)
        {
            flag = true;
            break;
        }
    }
    // 바꾸기
    if (flag)
    {
        for (int i = y - 1; i >= 0; i--)
        {
            if (map[x][i] == mark || map[x][i] == 0)
                break;
            map[x][i] = mark;
        }
    }
}

void vertical(int mark, int x, int y)
{
    bool flag = false;
    // 위
    for (int i = x - 1; i >= 0; i--)
    {
        if (map[i][y] == 0)
            break;
        if (map[i][y] == mark)
        {
            flag = true;
            break;
        }
    }
    // 바꾸기
    if (flag)
    {
        for (int i = x - 1; i >= 0; i--)
        {
            if (map[i][y] == mark || map[i][y] == 0)
                break;
            map[i][y] = mark;
        }
    }

    flag = false;
    // 아래
    for (int i = x + 1; i < n; i++)
    {
        if (map[i][y] == 0)
            break;
        if (map[i][y] == mark)
        {
            flag = true;
            break;
        }
    }
    // 바꾸기
    if (flag)
    {
        for (int i = x + 1; i < n; i++)
        {
            if (map[i][y] == mark || map[i][y] == 0)
                break;
            map[i][y] = mark;
        }
    }
}

void cross(int mark, int x, int y)
{
    bool flag = false;
    // 오른쪽 아래 점검
    for (int i = x + 1, j = y + 1; i < n && j < n; i++, j++)
    {
        if (map[i][j] == 0)
            break;
        if (map[i][j] == mark)
        {
            flag = true;
            break;
        }
    }

    if (flag)
    {
        for (int i = x + 1, j = y + 1; i < n && j < n; i++, j++)
        {
            if (map[i][j] == mark || map[i][j] == 0)
                break;
            map[i][j] = mark;
        }
    }
    flag = false;

    // 오른쪽 위 점검
    for (int i = x - 1, j = y + 1; i >= 0 && j < n; i--, j++)
    {
        if (map[i][j] == 0)
            break;
        if (map[i][j] == mark)
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        for (int i = x - 1, j = y + 1; i >= 0 && j < n; i--, j++)
        {
            if (map[i][j] == mark || map[i][j] == 0)
                break;
            map[i][j] = mark;
        }
    }

    flag = false;
    // 왼쪽 아래 점검
    for (int i = x + 1, j = y - 1; i < n && j >= 0; i++, j--)
    {
        if (map[i][j] == 0)
            break;
        if (map[i][j] == mark)
        {
            flag = true;
            break;
        }
    }

    if (flag)
    {
        for (int i = x + 1, j = y - 1; i < n && j >= 0; i++, j--)
        {
            if (map[i][j] == mark || map[i][j] == 0)
                break;
            map[i][j] = mark;
        }
    }

    flag = false;
    // 왼쪽 위 점검
    for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (map[i][j] == 0)
            break;
        if (map[i][j] == mark)
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (map[i][j] == mark || map[i][j] == 0)
                break;
            map[i][j] = mark;
        }
        return;
    }
    flag = false;
}

int main()
{

    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++)
    {

        scanf("%d %d", &n, &m);
        memset(map, 0, sizeof(map));

        // 1: Black, 2: White

        map[n / 2 - 1][n / 2 - 1] = 2;
        map[n / 2 - 1][n / 2] = 1;
        map[n / 2][n / 2 - 1] = 1;
        map[n / 2][n / 2] = 2;

        for (int i = 0; i < m; i++)
        {
            int x, y, mark;
            scanf("%d %d %d", &x, &y, &mark);
            map[y - 1][x - 1] = mark;

            horizontal(mark, y - 1, x - 1);
            vertical(mark, y - 1, x - 1);
            cross(mark, y - 1, x - 1);
            // cout << "-----------------------------" << endl;
            // for(int i = 0; i < n; i++) {
            //     for(int j = 0; j < n; j++) {
            //         printf("%d ", map[i][j]);
            //     }
            //     printf("\n");
            // }
        }

        int cntOfB = 0;
        int cntOfW = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (map[i][j] == 1)
                    cntOfB += 1;
                else if (map[i][j] == 2)
                    cntOfW += 1;
            }
        }

        printf("#%d %d %d\n", tc, cntOfB, cntOfW);
    }

    return 0;
}