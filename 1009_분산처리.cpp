#include <iostream>

using namespace std;

int main()
{

    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        long long total = 1;
        for (int cnt = 1; cnt <= b; cnt++)
        {
            total = (total * a) % 10;
        }

        if (total == 0)
        {
            printf("10\n");
        }
        else
        {
            printf("%lld\n", total);
        }
    }

    return 0;
}