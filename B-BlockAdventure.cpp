#include <iostream>

using namespace std;
const int MAX = 101;

int height[MAX];

int main() {

    int T;
    for(scanf("%d", &T); T--; ) {
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);

        for(int i = 0; i < n; i++) {
            scanf("%d", &height[i]);
        }

        bool flag = true;
        for(int i = 0; i < n-1; i++) {
            int low = max(0, height[i+1] - k);
            if(low < height[i]) {
                m += height[i] - low;
            } else if(low > height[i]) {
                m -= low - height[i];
                if(m < 0) {
                    flag = false;
                    break;
                }
            }
        }

        if(flag) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    


    return 0;
}