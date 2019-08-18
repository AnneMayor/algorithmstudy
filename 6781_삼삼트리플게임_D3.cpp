#include <iostream>
#include <string.h>

using namespace std;
const int MAX = 10;
int cntOfNumsAndCol[MAX][MAX]; // 세로열: 숫자(1-9), 가로열: 색상(R,G,B)
int nums[MAX];
char col[MAX];

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {

        int checkCase = 0;

        memset(cntOfNumsAndCol, 0, sizeof(cntOfNumsAndCol));

        for(int i = 0; i < 9; i++) {
            scanf("%1d", &nums[i]);
        }
        scanf("%s", col);

        for(int i = 0; i < 9; i++) {
            int row;
            int Col = nums[i];
            switch (col[i])
            {
            case 'R':
                row = 0;
                break;

            case 'G':
                row = 1;
                break;

            case 'B':
                row = 2;
                break;
            }

            cntOfNumsAndCol[row][Col] += 1;
        }

        // for(int i = 0; i < 3; i++) {
        //     for(int j = 1; j <= 9; j++) {
        //         cout << cntOfNumsAndCol[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        // 연속 숫자 체크 && 같은 숫자 체크
        for(int i = 0; i < 3; i++) {
            for(int j = 1; j <= 9; j++) {
                if(cntOfNumsAndCol[i][j] >= 3) {
                    checkCase += 1;
                    cntOfNumsAndCol[i][j] -= 3;
                }
                while(cntOfNumsAndCol[i][j]) {
                    if(cntOfNumsAndCol[i][j+1] >= 1 && cntOfNumsAndCol[i][j+2] >= 1) {
                        checkCase += 1;
                        cntOfNumsAndCol[i][j+1] -= 1;
                        cntOfNumsAndCol[i][j+2] -= 1;
                    }
                    cntOfNumsAndCol[i][j] -= 1;
                }
                cntOfNumsAndCol[i][j] = 0;
            }
        }

        printf("#%d ", tc);
        if(checkCase >= 3) {
            printf("Win\n");
        } else {
            printf("Continue\n");
        }

    }

    return 0;
}