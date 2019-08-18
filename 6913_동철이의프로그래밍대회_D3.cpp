    #include <iostream>

    using namespace std;

    int main() {

        int T;
        scanf("%d", &T);

        for(int t = 1; t <= T; t++) {
            int n, m;
            scanf("%d %d", &n, &m);

            int map[n][m];
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    scanf("%d", &map[i][j]);
                }
            }

            // 1등의 푼 문제 수 찾기
            int cntOfSolve = 0;
            for(int i = 0; i < n; i++) {
                int solve = 0;
                for(int j = 0; j < m; j++) {
                    if(map[i][j] == 1) {
                        solve += 1;
                    }
                }

                if(cntOfSolve < solve) {
                    cntOfSolve = solve;
                }
            }

            // 1등인 참가자 수 찾기
            int cntOfWinner = 0;
            for(int i = 0; i < n; i++) {
                int solve = 0;
                for(int j = 0; j < m; j++) {
                    if(map[i][j] == 1) {
                        solve += 1;
                    }
                }

                if(cntOfSolve == solve) {
                    cntOfWinner += 1;
                }
            }

            printf("#%d %d %d\n", t, cntOfWinner, cntOfSolve);
        }

        return 0;
    }