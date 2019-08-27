#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> numList;

int main()
{

    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++)
    {
        int n;
        scanf("%d", &n);

        numList.clear();

        for (int i = 0; i < n; i++)
        {
            int num;
            scanf("%d", &num);
            numList.push_back(num);
        }

        sort(numList.begin(), numList.end());

        int ans = numList[0] * numList[numList.size() - 1];

        printf("#%d %d\n", tc, ans);
    }

    return 0;
}