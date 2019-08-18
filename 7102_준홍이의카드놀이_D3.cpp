#include <iostream>
#include <string.h>
#define MAX 50

using namespace std;
int cnt[MAX];

int main() {

    int T;
    scanf("%d", &T);

    for(int t = 1; t <= T; t++) {
        int n,m;
        scanf("%d %d", &n, &m);

        memset(cnt, 0, sizeof(cnt));

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cnt[i+j] += 1;
            }
        }

        int temp = 0;
        // 가장 큰 값 찾기
        for(int i = 1; i <= n+m; i++) {
            if(temp < cnt[i]) {
                temp = cnt[i];
            }
        }

        printf("#%d ", t);
        for(int i = 1; i <= n+m; i++) {
            if(temp == cnt[i]) {
                printf("%d ", i);
            }
        }

        printf("\n");

    }

    return 0;
}