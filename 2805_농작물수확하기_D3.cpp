#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 50;

int map[MAX][MAX];
bool isVisited[MAX][MAX];

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int n;
        scanf("%d", &n);

        memset(map, 0, sizeof(map));
        memset(isVisited, false, sizeof(isVisited));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                scanf("%1d", &map[i][j]);
            }
        }

        // 위
        for(int i = 0; i < n/2; i++) {
            int cnt = 0;
            while(cnt < 2*i+1) {
                isVisited[i][n/2-i+cnt] = true;
                cnt++;
            }
        }
        // 중간
        for(int i = 0 ; i < n; i++) {
            isVisited[n/2][i] = true;
        }

        // 아래
        for(int i = 1; i <= n/2; i++) {
            int last = 2*(n/2-i+1)-1;
            for(int j = 0; j < last; j++) {
                isVisited[n/2+i][i+j] = true;
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isVisited[i][j]) ans += map[i][j];
            }
        }

        printf("#%d %d\n", tc, ans);

    }

    return 0;
}