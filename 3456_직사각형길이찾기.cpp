#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 105;

int isChecked[MAX];

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        
        memset(isChecked, 0, sizeof(isChecked));

        int nums[3];
        for(int i = 0; i < 3; i++) {
            scanf("%d", &nums[i]);

            isChecked[nums[i]] += 1;
        }

        int ans = 0;
        for(int i = 0; i < 3; i++) {
            if(isChecked[nums[i]] == 1) {
                ans = nums[i];
                break;
            }
        }

        if(ans == 0) ans = nums[0];

        printf("#%d %d\n", tc, ans);
    }

    return 0;
}