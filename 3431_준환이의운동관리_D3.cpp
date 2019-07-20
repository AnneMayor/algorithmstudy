#include <iostream>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int l, u, x;
        scanf("%d %d %d", &l, &u, &x);

        printf("#%d ",tc);
        if(x < l) {
            printf("%d\n", l-x);
        } else if(x >= l && x <= u) {
            printf("0\n");
        } else {
            printf("-1\n");
        }
    }

    return 0;
}