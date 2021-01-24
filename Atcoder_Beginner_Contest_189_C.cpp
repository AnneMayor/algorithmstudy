#include <bits/stdc++.h>

using namespace std;

int main(void) {

    int n;
    scanf("%d", &n);

    int a[n+5];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // O(N^2) 시간복잡도로 해결하는 방법 활용
    // Segment Tree를 활용한 풀이도 가능하나 시간초과(O(N^2logN))

    int ans = 0;
    for(int l = 0; l < n; l++) {
        int x = a[l];
        for(int r = l; r < n; r++) {
            x = min(x, a[r]);
            ans = max(ans, x*(r-l+1));
        }
    }

    printf("%d\n", ans);

    return 0;
}