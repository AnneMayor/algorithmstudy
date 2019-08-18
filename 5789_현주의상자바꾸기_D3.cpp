#include <iostream>
#include <string.h>

using namespace std;
const int MAX = 2000;

int nums[MAX];

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int n, q;
        scanf("%d %d", &n, &q);

        memset(nums, 0, sizeof(nums));
        
        for(int i = 1; i <= q; i++) {
            int s, e;
            scanf("%d %d", &s, &e);

            for(int j = s-1; j < e; j++) {
                nums[j] = i;
            }
        }

        printf("#%d ", tc);
        for(int i = 0; i < n; i++) {
            printf("%d ", nums[i]);
        }
        printf("\n");
    }

    return 0;
}