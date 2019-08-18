#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 1005;

int nums[MAX];
int d[MAX];

int main()
{

    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++)
    {

        int n;
        scanf("%d", &n);

        memset(d, 0, sizeof(d));

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &nums[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    if (d[i] < d[j])
                    {
                        d[i] = d[j];
                    }
                }
            }
            d[i]++;
        }

        for (int i = 0; i < n; i++)
        {
            ans = max(ans, d[i]);
        }

        printf("#%d %d\n", tc, ans);
    }

    return 0;
}