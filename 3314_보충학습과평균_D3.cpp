#include <iostream>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {

        int total = 0;

        for(int i = 0; i < 5; i++) {
            int num;
            scanf("%d", &num);

            if(num < 40) total += 40;
            else total += num;
        }

        printf("#%d %d\n", tc, total/5);

    }

    return 0;
}