#include <iostream>

using namespace std;

int money[8] = {50000, 10000, 5000, 1000, 500, 100, 50, 10};

int main() {

    int T;
    scanf("%d", &T);

    for(int t = 1; t <= T; t++) {
        int n;
        scanf("%d", &n);

        printf("#%d\n", t);
        for(int i = 0; i < 8; i++) {
            if(n / money[i] > 0) {
                printf("%d ", n / money[i]);
                n %= money[i];
            } else {
                printf("%d ", 0);
            }
        }
        printf("\n");
    }



    return 0;
}