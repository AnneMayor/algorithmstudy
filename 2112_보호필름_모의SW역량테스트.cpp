#include <iostream>

using namespace std;
const int MAX = 25;

int film[MAX][MAX];
int minChemicalCnt;
int chemical[MAX];

int d, w, k;

void dfs(int cur, int cntOfChemical, int prevConCnt[MAX], int prevMaxConCnt[MAX]) {

    if(cntOfChemical >= minChemicalCnt) return ;

    if(cur == d) {

        bool flag = true;
        for(int i = 0; i < w; i++) {
            if(prevMaxConCnt[i] < k) {
                flag = false;
                break;
            }
        }

        if(flag && cntOfChemical < minChemicalCnt) {
            minChemicalCnt = cntOfChemical;
        }

        return ;
    }

    int cntConFilm[MAX], cntConMax[MAX];
    int prevD, curD;
    
    for(int i = 2; i >= 0; i--) {
        chemical[cur] = i;

        for(int j = 0; j < w; j++) {
            curD = chemical[cur] == 2 ? film[cur][j] : chemical[cur];
            prevD = chemical[cur-1] == 2 ? film[cur-1][j] : chemical[cur-1];
            cntConFilm[j] = curD == prevD ? prevConCnt[j] + 1 : 1;
            if(cntConFilm[j] > prevMaxConCnt[j]) cntConMax[j] = cntConFilm[j];
            else cntConMax[j] = prevMaxConCnt[j];
        }

        dfs(cur+1, cntOfChemical + (i != 2? 1: 0), cntConFilm, cntConMax);
    }

    return ;

}

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        scanf("%d %d %d", &d, &w, &k);

        for(int i = 0; i < d; i++) {
            for(int j = 0; j < w; j++) {
                scanf("%d", &film[i][j]);
            }
        }

        minChemicalCnt = k;

        int conCntofFilm[MAX], maxConCntOfFilm[MAX];
        for(int i = 0; i < w; i++) {
            conCntofFilm[i] = maxConCntOfFilm[i] = 1;
        }

        chemical[0] = 2;
        dfs(1, 0, conCntofFilm, maxConCntOfFilm);

        chemical[0] = 1;
        dfs(1, 1, conCntofFilm, maxConCntOfFilm);

        chemical[0] = 0;
        dfs(1, 1, conCntofFilm, maxConCntOfFilm);

        printf("#%d %d\n", tc, minChemicalCnt);

    }

    return 0;
}