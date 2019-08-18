#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 305;

int map[MAX][MAX];
int tmp[MAX][MAX];
bool isChecked[MAX][MAX];
int value;
int n, m, r;

bool check(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < m)
        return true;
    else
        return false;
}

void move(int x, int y, int dir)
{

    isChecked[x][y] = true;

    switch (dir)
    {
        // 아래
    case 1:
        if (check(x + 1, y) && !isChecked[x + 1][y])
        {
            tmp[x + 1][y] = map[x][y];
            move(x + 1, y, 1);
        }
        else
        {
            if (check(x, y + 1))
            {
                if (!isChecked[x][y + 1])
                {
                    tmp[x][y + 1] = map[x][y];
                    move(x, y + 1, 2);
                }
                else
                {
                    tmp[x][y + 1] = value;
                    return;
                }
            }
        }
        break;

        // 오른쪽
    case 2:
        if (check(x, y + 1) && !isChecked[x][y + 1])
        {
            tmp[x][y + 1] = map[x][y];
            move(x, y + 1, 2);
        }
        else
        {
            if (check(x - 1, y))
            {
                if (!isChecked[x - 1][y])
                {
                    tmp[x - 1][y] = map[x][y];
                    move(x - 1, y, 3);
                }
                else
                {
                    tmp[x - 1][y] = value;
                    return;
                }
            }
        }
        break;

        // 위
    case 3:
        if (check(x - 1, y) && !isChecked[x - 1][y])
        {
            tmp[x - 1][y] = map[x][y];
            move(x - 1, y, 3);
        }
        else
        {
            if (check(x, y - 1))
            {
                if (!isChecked[x][y - 1])
                {
                    tmp[x][y - 1] = map[x][y];
                    move(x, y - 1, 4);
                }
                else
                {
                    tmp[x][y - 1] = value;
                    return;
                }
            }
        }

        break;

        // 왼쪽
    case 4:
        if (check(x, y - 1))
        {
            if (!isChecked[x][y - 1])
            {
                tmp[x][y - 1] = map[x][y];
                move(x, y - 1, 4);
            }
            else
            {
                tmp[x][y - 1] = value;
                return;
            }
        }

        break;
    }

    return;
}

int main()
{
    scanf("%d %d %d", &n, &m, &r);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }

    memset(isChecked, false, sizeof(isChecked));

    for (int i = 0; i < r; i++)
    {

        // 시작점 찾기 & DFS 탐색
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == j && !isChecked[i][j])
                {
                    value = map[i][j + 1];
                    // 아래
                    move(i, j, 1);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                map[i][j] = tmp[i][j];
            }
        }

        memset(isChecked, false, sizeof(isChecked));
    }

    // 출력
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}