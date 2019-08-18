#include <iostream>
#include <string.h>
#define MAX 100

using namespace std;

int day[MAX];
int profit[MAX];
bool isVisited[MAX];
int n;
int ans = -100;

void dfs(int idx, int cnt, int total)
{

    if (cnt >= n)
    {
        if (ans == -100)
            ans = total;
        else
        {
            if (ans < total)
            {
                ans = total;
            }
        }
        return;
    }

    // 현재 idx 위치 day, profit 포함 유무에 따라 길이 나뉨.
    // 여기 부분에서 헤맴. 여기 잘 기억해두자!
    dfs(idx+1, cnt + 1, total);
    if(cnt + day[idx] <= n) {
        dfs(idx+day[idx], cnt +day[idx], total+profit[idx]);
    }
}

int main()
{

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &day[i], &profit[i]);
    }

    dfs(0, 0, 0);

    printf("%d\n", ans);

    return 0;
}