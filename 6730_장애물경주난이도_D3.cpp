#include <iostream>
#include <string.h>

using namespace std;
const int MAX = 200;

int nums[MAX];

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++ ) {

        memset(nums, 0, sizeof(nums));

        int n;
        scanf("%d", &n);

        for(int i = 0; i < n; i++) {
            scanf("%d", &nums[i]);
        }

        int upLevel = 0;
        int downLevel = 0;
        for(int i = 0; i < n-1; i++) {
            if(nums[i] > nums[i+1]) {
                downLevel = max(downLevel, nums[i]-nums[i+1]);
            } else {
                upLevel = max(upLevel, nums[i+1]-nums[i]);
            }
        }

        printf("#%d %d %d\n", tc, upLevel, downLevel);

    }

    return 0;
}