#include <iostream>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        int num = a > b? b : a;

        printf("#%d %d\n", tc, c / num);
    }

    return 0;
}