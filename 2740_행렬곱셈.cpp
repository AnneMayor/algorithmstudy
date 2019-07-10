#include <iostream>

using namespace std;

int main() {

    int n, m;
    scanf("%d %d", &n, &m);
    int a[n][m];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int l, k;
    scanf("%d %d", &l, &k);
    int b[l][k];

    for(int i = 0; i < l; i++) {
        for(int j = 0; j < k; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    int c[n][k];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            int val = 0;
            for(int p = 0; p < m; p++) {
                val += a[i][p] * b[p][j];
            }
            c[i][j] = val;
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < k; j++) {
    //         printf("%d ", c[i][j]);
    //     }
    //     printf("\n");
    // }

    return 0;
}