#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int MAX = 5005;

bool isChecked[MAX];

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int n;
        scanf("%d", &n);

        memset(isChecked, false, sizeof(isChecked));

        int nums[n];

        for(int i = 0; i < n; i++) {
            scanf("%d", &nums[i]);
        }

        int ans = 0;
        for(int i = 1; i < n; i++) {
            int *idx;
            if(!isChecked[i]) {
                isChecked[i] = true;
                ans += 1;
                int tmpDiff = nums[i] - nums[0];

                int tmp = nums[i] + tmpDiff;
                while(tmp <= nums[n-1]) {
                    idx = find(nums, nums+n, tmp);
                    if(idx != nums+n) {
                        isChecked[idx-nums] = true;
                    }
                    tmp += tmpDiff;
                }
            }
            
        }
        
        printf("#%d %d\n", tc, ans);
    }


    return 0;
}