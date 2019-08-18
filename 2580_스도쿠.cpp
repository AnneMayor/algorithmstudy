// backtracking 활용문제
#include <iostream>
#include <vector>

using namespace std;
const int MAX = 10;

int map[MAX][MAX];
vector<pair<int, int> > points;

bool checkHorizontal(int x, int num)
{

    bool flag = true;
    for (int y = 0; y < 9; y++)
    {
        if (map[x][y] == num)
        {
            flag = false;
            break;
        }
    }

    return flag;
}

bool checkVertical(int y, int num)
{

    bool flag = true;
    for (int x = 0; x < 9; x++)
    {
        if (map[x][y] == num)
        {
            flag = false;
            break;
        }
    }

    return flag;
}

bool checkSquare(int x, int y, int num)
{

    x /= 3;
    y /= 3;

    int startX = 3 * x;
    int endX = startX + 2;
    int startY = 3 * y;
    int endY = startY + 2;

    bool flag = true;
    for (int i = startX; i <= endX; i++)
    {
        for (int j = startY; j <= endY; j++)
        {
            if (map[i][j] == num)
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

void backtracking(int idx)
{

    if (idx >= points.size())
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }

        exit(0);
    }

    int x = points[idx].first;
    int y = points[idx].second;

    for (int num = 1; num < 10; num++)
    {
        if (checkVertical(y, num) && checkHorizontal(x, num) && checkSquare(x, y, num))
        {
            map[x][y] = num;
            backtracking(idx + 1);
            map[x][y] = 0;
        }
    }
}

int main()
{

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 0)
                points.push_back(make_pair(i, j));
        }
    }

    int x = points[0].first;
    int y = points[0].second;
    for (int n = 1; n < 10; n++)
    {
        if (checkVertical(y, n) && checkHorizontal(x, n) && checkSquare(x, y, n))
        {
            map[x][y] = n;
            backtracking(1);
            map[x][y] = 0;
        }

    }

    return 0;
}

// 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0