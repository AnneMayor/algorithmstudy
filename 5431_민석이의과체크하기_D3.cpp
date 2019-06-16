#include <iostream>
#include <string.h>

using namespace std;
const int MAX = 200;

bool isChecked[MAX];

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {

        memset(isChecked, false, sizeof(isChecked));

        int n, k;
        scanf("%d %d", &n, &k);

        for(int i = 0; i < k; i++) {
            int idx;
            scanf("%d", &idx);
            isChecked[idx] = true;
        }

        printf("#%d ", tc);

        for(int i = 1; i <= n; i++) {
            if(!isChecked[i]) {
                printf("%d ", i);
            }
        }

        printf("\n");

    }

    return 0;
}