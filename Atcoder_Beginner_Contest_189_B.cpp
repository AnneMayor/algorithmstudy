#include <bits/stdc++.h>

using namespace std;

int main(void) {

    int n, x;
    int curAlcohol = 0;
    int ans = -1;
    scanf("%d %d", &n, &x);

    for(int i = 1; i <= n; i++) {
        int v, p;
        scanf("%d %d", &v, &p);
        int alcol = v * p;
        curAlcohol += alcol;
        if(curAlcohol > x*100) {
            if(ans == -1) ans = i;
        }
    }

    printf("%d\n", ans);
    return 0;
}