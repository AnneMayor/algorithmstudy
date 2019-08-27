#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;
const int MAX = 1e6;

int nums[MAX];

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {

        int n;
        scanf("%d", &n);

        for(int i = 0; i < n; i++) {
            scanf("%d", &nums[i]);
        }

        sort(nums, nums+n, greater<int>());
        
        int start = nums[0];
        
        int idx = 0;
        int cnt = 0;
        while(start >= 0) {

            for(int i = idx; i < n; i++) {
                if(start <= nums[i]) {
                    cnt++;
                } else {
                    idx = i;
                    break;
                }
            }

            if(start <= cnt) {
                break;
            }

            start--;
        }

        if(cnt > n) start = n;

        printf("#%d %d\n", tc, start);
    }

    return 0;
}