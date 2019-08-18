#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> numList;

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int ans = 0;
        int n, k;
        scanf("%d %d", &n, &k);

        numList.clear();

        for(int i = 0; i < n; i++) {
            int tmp;
            scanf("%d", &tmp);
            numList.push_back(tmp);
        }

        sort(numList.begin(), numList.end());

        for(int j = 0; j < k; j++) {
            ans += numList[n-1-j];
        }

        printf("#%d %d\n", tc, ans);
    }

    return 0;
}