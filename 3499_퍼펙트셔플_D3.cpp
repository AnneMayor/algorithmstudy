#include <iostream>

using namespace std;
const int MAX = 1005;

char str[MAX][MAX];

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int n;
        scanf("%d", &n);

        for(int i = 0; i < n; i++) {
            scanf("%s", str[i]);
        }

        printf("#%d ", tc);
        if(n % 2 == 0) {
            for(int i = 0; i < n/2; i++) {
                printf("%s %s ", str[i], str[i+n/2]);
            }

            printf("\n");
        } else {
            for(int i = 0; i < n/2; i++) {
                printf("%s %s ", str[i], str[i+n/2+1]);
            }

            printf("%s\n", str[n/2]);
        }
    }

    return 0;
}