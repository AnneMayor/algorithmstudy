#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int k;
        scanf("%d", &k);

        int x1, y1, x2, y2;
        vector<int> xs;
        vector<int> ys;
        for(int i = 0; i < k; i++) {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            xs.push_back(x1);
            xs.push_back(x2);
            ys.push_back(y1);
            ys.push_back(y2);
        }

        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end()); 

        printf("Case #%d: %d %d\n", tc, xs[k-1], ys[k-1]);
    }

    return 0;
}