#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int MAX = 1e6 + 5;

int blocks[MAX];

int main()
{

    int x;
    while (scanf("%d", &x) == 1)
    {
        int n;
        scanf("%d", &n);
        memset(blocks, 0, sizeof(blocks));

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &blocks[i]);
        }

        x *= 1e7;
        sort(blocks, blocks + n);

        int start = 0, end = n - 1;
        bool resultFlag = false;
        int ansStart = -1, ansEnd = -1;
        while (start < end)
        {
            long long length = blocks[start] + blocks[end];
            if (length == x)
            {
                resultFlag = true;
                ansStart = blocks[start], ansEnd = blocks[end];
                break;
            }
            else if (length > x)
            {
                end--;
            }
            else
            {
                start++;
            }
        }

        if (!resultFlag)
        {
            printf("danger\n");
        }
        else
        {
            printf("yes %d %d\n", ansStart, ansEnd);
        }
    }

    return 0;
}