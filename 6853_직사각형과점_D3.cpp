#include <iostream>
#include <string.h>

using namespace std;
int ans[3];

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        memset(ans, 0, sizeof(ans));

        int n;
        scanf("%d", &n);

        for(int i = 0; i < n; i++) {
            int x, y;
            scanf("%d %d", &x, &y);

            // cout << "x1: " << x1 << "/ x2: " << x2 << "/ y1: " << y1 << "/ y2: " << y2 << endl;

            if((x > x1 && x < x2) && (y > y1 && y < y2)) {
                ans[0]++;
            } else if(x == x1 || x == x2 || y == y1 || y == y2) {
                if(x == x1 || x == x2) {
                    if(y >= y1 && y <= y2) {
                        ans[1]++;
                    } else {
                        ans[2]++;
                    }
                } else if(y == y1 || y == y2) {
                    if(x >= x1 && x <= x2) {
                        ans[1]++;
                    } else {
                        ans[2]++;
                    }
                }
            } else {
                ans[2]++;
            }
        }

        printf("#%d ", tc);
        for(int i = 0; i < 3; i++) {
            printf("%d ", ans[i]);
        }
        printf("\n");
    }

    return 0;
}