#include <bits/stdc++.h>

using namespace std;
const int MAX = 30;

char result[MAX];

// ****************************************************************** //
// **************이렇게 선언하고 사용하면 Codejam 시스템에서 TLE************** //
// void Query(int x, int y)
// {
//     printf("%d %d\n", x, y);
//     fflush(stdout);
//     scanf("%s", result);
// }
// ****************************************************************** //

void solve(int &a, int &b)
{
    // a, b 무시하고 진행(Test Set #3에 맞춰서 풀이)
    // x, y 경계값 비교
    int x = 0, y = 0;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            a = i * 500000000;
            b = j * 500000000;
            printf("%d %d\n", a, b);
            fflush(stdout);
            scanf("%s", result);
            if (result[0] == 'C')
                return;
            else if (result[0] == 'H')
            {
                x = a;
                y = b;
            }
        }
    }

    int xs = x, xe = x;
    int ys = y, ye = y;

    // y값 고정 후 찾기
    int rs = -1000000000, re = x;
    while (rs < re)
    {
        int diff = re - rs;
        int mid = rs + diff / 2;

        printf("%d %d\n", mid, y);
        fflush(stdout);
        scanf("%s", result);
        if (result[0] == 'C')
            return;
        else if (result[0] == 'H')
            re = mid;
        else
            rs = mid + 1;
    }
    xs = rs;

    rs = x, re = 1000000000;
    while (rs < re)
    {
        int diff = re - rs;
        int mid = rs + (diff+1) / 2;

        printf("%d %d\n", mid, y);
        fflush(stdout);
        scanf("%s", result);
        if (result[0] == 'C')
            return;
        else if (result[0] == 'H')
            rs = mid;
        else
            re = mid - 1;
    }
    xe = re;

    // x값 고정 후 찾기
    rs = -1000000000, re = y;
    while (rs < re)
    {
        int diff = re - rs;
        int mid = rs + diff / 2;

        printf("%d %d\n", x, mid);
        fflush(stdout);
        scanf("%s", result);
        if (result[0] == 'C')
            return;
        else if (result[0] == 'H')
            re = mid;
        else
            rs = mid + 1;
    }
    ys = rs;

    rs = y, re = 1000000000;
    while (rs < re)
    {
        int diff = re - rs;
        int mid = rs + (diff+1) / 2;
        printf("%d %d\n", x, mid);
        fflush(stdout);
        scanf("%s", result);
        if (result[0] == 'C')
            return;
        else if (result[0] == 'H')
            rs = mid;
        else
            re = mid - 1;
    }
    ye = re;

    printf("%d %d\n", (xs + xe) / 2, (ys + ye) / 2);
    fflush(stdout);

    scanf("%*s");

    return;
}

int main()
{

    int t, a, b;

    scanf("%d%d%d", &t, &a, &b);
    while (t--)
    {
        solve(a, b);
    }

    return 0;
}