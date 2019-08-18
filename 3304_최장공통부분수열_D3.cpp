#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 1005;

char a[MAX];
char b[MAX];

int lcs[MAX][MAX];

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {

        scanf("%s %s", a, b);
        memset(lcs, 0, sizeof(lcs));

        int lenA = strlen(a);
        int lenB = strlen(b);

        for(int i = 1; i <= lenA; i++) {
            for(int j = 1; j <= lenB; j++) {
                if(a[i-1] == b[j-1]) {
                    lcs[i][j] = lcs[i-1][j-1] + 1;
                } else {
                    if(lcs[i-1][j] < lcs[i][j-1]) {
                        lcs[i][j] = lcs[i][j-1];
                    } else {
                        lcs[i][j] = lcs[i-1][j];
                    }
                }
            }
        }

        // int ans = 0;
        // for(int i = 1; i <= lenA; i++) {
        //     for(int j = 1; j <= lenB; j++) {
        //         ans = max(ans, lcs[i][j]);
        //     }
        // }

        printf("#%d %d\n", tc, lcs[lenA][lenB]);

    }

    return 0;
}