#include <iostream>

using namespace std;
const int MAX = 1e5+5;

int d[MAX][3];
int sticker[2][MAX];

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int n;
        scanf("%d", &n);

        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < n; j++) {
                scanf("%d", &sticker[i][j]);
            }
        }

        // d[i][j]: i열에서 스티커를 뗀 상태(j = 0: 둘 다 안뜯음 , 1: 위 한 개만 뜯음, 2: 아래 한 개만 뜯음)
        d[0][0] = 0;
        d[0][1] = sticker[0][0];
        d[0][2] = sticker[1][0];

        for(int i = 1; i < n; i++) {
            d[i][0] = max(d[i-1][0], max(d[i-1][1], d[i-1][2]));
            d[i][1] = max(d[i-1][0], d[i-1][2])+sticker[0][i];
            d[i][2] = max(d[i-1][0], d[i-1][1])+sticker[1][i];
        }

        int ans = max(d[n-1][0], max(d[n-1][1], d[n-1][2]));
        printf("%d\n", ans);

    }

    return 0;
}