#include <iostream>

using namespace std;

int main() {

    int v,p,l;

    int tc_idx = 1;

    while(1) {

        int ans = 0;

        scanf("%d %d %d", &l, &p, &v);

        if(l == 0 && p == 0 && v == 0) break;

        int temp = v/p;

        ans += l*temp;

        int v1 = v - (p*temp);

        if(v1 > l) {
            ans += l;
        } else {
            ans += v1;
        }

        printf("Case %d: %d\n", tc_idx, ans);

        tc_idx += 1;

    }

    return 0;
}