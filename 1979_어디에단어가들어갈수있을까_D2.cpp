#include <iostream>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);

    for(int t = 1; t <= T; t++) {

        int n, k;
        int ans = 0;
        scanf("%d %d", &n, &k);
        int map[n][n];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                scanf("%d", &map[i][j]);
            }
        }

        // 행 검사
        for(int y = 0; y < n; y++) {
            int cnt = 0;
            for(int x = 0; x < n; x++) {
                if(map[x][y] == 1) {
                    cnt++;
                } else {
                    if(cnt == k) {
                        ans++;
                    }
                    cnt = 0;
                }
            }
            if(cnt == k) ans++;
        }

        // 열 검사
        for(int x = 0; x < n; x++) {
            int cnt = 0;
            for(int y = 0; y < n; y++) {
                if(map[x][y] == 1) {
                    cnt++;
                } else {
                    if(cnt == k) {
                        ans++;
                    }
                    cnt = 0;
                }
            }
            if(cnt == k) ans++;
        }

        printf("#%d %d\n", t, ans);

    }

    return 0;
}