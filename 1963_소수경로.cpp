#include <iostream>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;
const int MAX = 10000;
int ans;
bool isPrime[MAX];
bool isChecked[MAX];
// 소수, step 기준
queue<pair<int, int> > q;

//n의 i번째 자리 수를 j로 바꾼다 (1234,1,2) -> 2234
int change_prime(int n, int i, int j)
{

    int k = n;
    if (i == 1)
    {
        k -= (n / 1000) * 1000;
        k += j * 1000;
    }
    else if (i == 2)
    {
        k -= ((n / 100) % 10) * 100;
        k += j * 100;
    }
    else if (i == 3)
    {
        k -= ((n % 100) / 10) * 10;
        k += j * 10;
    }
    else if (i == 4)
    {
        k -= n % 10;
        k += j;
    }

    return k;
}

void solve(int step, int num1, int num2)
{

    pair<int, int> p;
    p.first = num1;
    p.second = step;
    q.push(p);
    isChecked[num1] = true;

    while (!q.empty())
    {
        num1 = q.front().first;
        step = q.front().second;
        q.pop();

        if (num1 == num2)
        {
            if (ans > step)
                ans = step;
            return;
        }

        for (int i = 1; i <= 4; i++)
        {
            for (int j = 0; j <= 9; j++)
            {
                int num = change_prime(num1, i, j);
                if (isChecked[num] || num <= 1000 || !isPrime[num])
                    continue;

                isChecked[num] = true;
                p.first = num;
                p.second = step+1;
                q.push(p);
            }
        }
    }
}

int main()
{

    int T;
    scanf("%d", &T);

    memset(isPrime, true, sizeof(isPrime));

    // 소수 찾기
    for (int i = 1000; i < 10000; i++)
    {
        for (int j = 2; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                isPrime[i] = false;
                break;
            }
        }
    }

    for (int tc = 1; tc <= T; tc++)
    {

        int num1, num2;
        scanf("%d %d", &num1, &num2);
        while (!q.empty())
        {
            q.pop();
        }

        memset(isChecked, false, sizeof(isChecked));
        ans = 999999999;

        solve(0, num1, num2);

        if (ans == 999999999)
        {
            printf("Impossible\n");
        }
        else
        {
            printf("%d\n", ans);
        }
    }

    return 0;
}