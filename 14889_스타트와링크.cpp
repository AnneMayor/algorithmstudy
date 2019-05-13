#include <iostream>
#include <string.h>
#define MAX 30

using namespace std;

int n;
int team[MAX][MAX];
bool isVisited[MAX];
int ans = -1;

void dfs(int num, int cnt)
{

    if (cnt >= n / 2)
    {

        int sumS = 0;
        int sumL = 0;

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (isVisited[i])
                {
                    if (isVisited[j])
                    {
                        sumS += team[i][j];
                        sumS += team[j][i];
                    }
                }
                else
                {
                    if (!isVisited[j])
                    {
                        sumL += team[i][j];
                        sumL += team[j][i];
                    }
                }
            }
        }

        int temp = abs(sumS - sumL);
        if (ans == -1)
            ans = temp;
        else
        {
            if (ans > temp)
            {
                ans = temp;
            }
        }

        return;
    }

    for (int i = num + 1; i < n; i++)
    {
        if (!isVisited[i])
        {
            isVisited[i] = true;
            dfs(i, cnt + 1);
            isVisited[i] = false;
        }
    }
}

int main()
{

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &team[i][j]);
        }
    }

    memset(isVisited, false, sizeof(isVisited));

    for (int i = 0; i < n; i++)
    {
        if (!isVisited[i])
        {
            isVisited[i] = true;
            dfs(i, 1);
            isVisited[i] = false;
        }
    }

    printf("%d\n", ans);

    return 0;
}