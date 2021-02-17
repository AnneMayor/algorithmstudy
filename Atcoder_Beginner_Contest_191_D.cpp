#include <bits/stdc++.h>

using namespace std;

int main(void) {

    long double x, y, r;
    scanf("%Lf %Lf %Lf", &x, &y, &r);

    long long x_up = floor(x+r);
    long long x_down = ceil(x-r);
    r += 1e-14;

    // cout << "r: " << r << endl;

    long long ans = 0;

    for(long long i = x_down; i <= x_up; i++) {

        long double yDiff = sqrt(r*r - (x-i)*(x-i));
        long long y_up = floor(y+yDiff);
        long long y_down = ceil(y-yDiff);
        ans += (y_up - y_down) + 1;
    }

    printf("%lld\n", ans);

    return 0;
}