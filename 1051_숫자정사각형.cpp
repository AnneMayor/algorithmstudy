#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 55;

int main() {

    int map[MAX][MAX];

    int N, M;
    scanf("%d %d", &N, &M);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    int len = min(N, M);
    int ans = 1;

    for(int x = 0; x < N; x++) {
        for(int y = 0; y < M; y++) {
            for(int diff = 0; diff <= len; diff++) {
                if(x+diff < N && y+diff < M) {
                    int s1 = map[x][y];
                    int s2 = map[x+diff][y];
                    int s3 = map[x][y+diff];
                    int s4 = map[x+diff][y+diff];

                    // cout << "s1: " << s1 << " / s2: " << s2 << " / s3: " << s3 << " / s4: " << s4 << endl;
                    // cout << "x: " << x << " / x+diff: " << x+diff << " / y: " << y << " / y+diff: " << y+diff << endl;

                    if(s1 == s2 && s2 == s3 && s3 == s4) {

                        ans = max(ans, (diff+1)*(diff+1));
                    }
                }
            }
        }
    }

    printf("%d\n", ans);


    return 0;
}