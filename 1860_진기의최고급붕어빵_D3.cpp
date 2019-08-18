#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);

        int nums[n];
        for(int i = 0; i < n; i++) {
            scanf("%d", &nums[i]);
        }

        sort(nums, nums+n);

        bool flag = true;
        int start = m;
        int numOfCount = k;
        for(int i = 0; i < n; i++) {
            if(numOfCount <= 0) {
                start += m;
                numOfCount += k;
            }

            if(start <= nums[i]) numOfCount--;
            else {
                flag = false;
                break;
            }
        }

        printf("#%d ", tc);
        if(flag) {
            printf("Possible\n");
        } else {
            printf("Impossible\n");
        }

    }

    return 0;
}