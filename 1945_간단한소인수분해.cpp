#include <iostream>

using namespace std;

int prime[] = {2, 3, 5, 7, 11};

int main() {

    int T;
    scanf("%d", &T);

    for(int t = 1; t <= T; t++) {
        int n;
        scanf("%d", &n);

        printf("#%d ", t);
        for(int i = 0; i < 5; i++) {
            
            int cnt = 0;
            while(n % prime[i] == 0) {
                cnt += 1;
                n /= prime[i];
            }

            printf("%d ", cnt);

        }

        printf("\n");

    }

    return 0;
}