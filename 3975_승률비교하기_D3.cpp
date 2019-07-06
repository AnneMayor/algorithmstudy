#include <iostream>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        double a, b, c, d;
        scanf("%lf %lf %lf %lf", &a, &b, &c, &d);

        double alice = a/b;
        double bob = c/d;

        printf("#%d ", tc);
        if(alice > bob) {
            printf("ALICE\n");
        } else if(alice == bob) {
            printf("DRAW\n");
        } else {
            printf("BOB\n");
        }
    }

    return 0;
}