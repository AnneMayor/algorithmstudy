#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        int ans = 0;
        int possibleGroup = (a+b) / 4;
        ans = min(possibleGroup, min(a, b));

        printf("%d\n", ans);
    }

    return 0;
}