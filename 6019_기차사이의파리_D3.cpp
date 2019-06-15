#include <iostream>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int d;
        double a, b, f;
        scanf("%d %f %f %f", &d, &a, &b, &f);

        double time = d / (a+b);
        double ans = time * f;
        printf("#%d %f\n", tc, ans);
    }

    return 0;
}