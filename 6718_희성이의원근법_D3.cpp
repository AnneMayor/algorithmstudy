#include <iostream>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int ans = -1;

        double d;
        scanf("%lf", &d);

        d /= 1000;

        if(d < 0.1) {
            ans = 0;
        } else if(d >= 0.1 && d < 1) {
            ans = 1;
        } else if(d >= 1 && d < 10) {
            ans = 2;
        } else if(d >= 10 && d < 100) {
            ans = 3;
        } else if(d >= 100 && d < 1000) {
            ans = 4;
        } else {
            ans = 5;
        }

        printf("#%d %d\n", tc, ans);
    }

    return 0;
}