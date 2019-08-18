#include <iostream>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);

    for(int t = 1; t <= T; t++) {
        int n,m;
        scanf("%d %d", &n, &m);
        int dataN[n];
        int dataM[m];

        for(int i = 0; i < n; i++) {
            scanf("%d", &dataN[i]);
        }

        for(int i = 0; i < m; i++) {
            scanf("%d", &dataM[i]);
        }

        int diff = max(n ,m) - min(n, m);

        int max = -9999999;
        for(int i = 0; i <= diff; i++) {
            int sum = 0;

            if(min(n,m) == n) {
                for(int j = 0; j < min(n,m); j++) {
                    sum += dataN[j] * dataM[j+i];
                }
            } else {
                for(int j = 0; j < min(n,m); j++) {
                    sum += dataN[j+i] * dataM[j];
                }
            }
    
            if(max < sum) {
                max = sum;
            }
        }

        printf("#%d %d\n", t, max);
    }

    return 0;
}