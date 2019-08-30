#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 1e6 + 5;

char num[MAX];
int ans[MAX];

int pow(int base, int exp)
{
    int ret = 1;
    while (exp)
    {
        if (exp & 1)
        {
            ret *= base;
        }
        base *= base;
        exp >>= 1;
    }

    return ret;
}

int main()
{

    scanf("%s", num);

    int len = strlen(num);

    int cnt = 0;
    int tmp = 0;
    int idxAns = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        tmp += (num[i] - '0') * pow(2, cnt);
        cnt += 1;
        if (cnt >= 3)
        {
            cnt = 0;
            ans[idxAns++] = tmp;
            tmp = 0;
        }
    }

    if (cnt > 0)
    {
        ans[idxAns++] = tmp;
    }

    for (int i = idxAns - 1; i >= 0; i--)
    {
        printf("%d", ans[i]);
    }
    printf("\n");

    return 0;
}