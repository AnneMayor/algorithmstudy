#include <iostream>
#include <string.h>

using namespace std;

const int MAX = 20;

int main() {

    int T;
    scanf("%d", &T);

    for(int t = 1; t <= T; t++) {
        char str1[MAX], str2[MAX];
        scanf("%s %s", str1, str2);

        bool flag = true;

        int lenStr1 = strlen(str1);
        int lenStr2 = strlen(str2);

        if(lenStr1 != lenStr2) {
            printf("#%d DIFF\n", t);
        } else {
            for(int i = 0; i < lenStr1; i++) {
                int cntOfOne1 = 0;
                int cntOfOne2 = 0;

                // 첫번째 문자열 검사
                if(str1[i] == 'A' || str1[i] == 'D' || str1[i] == 'O' || str1[i] == 'P' || str1[i] == 'Q' || str1[i] == 'R') {
                    cntOfOne1 += 1;
                }
                if(str1[i] == 'B') {
                    cntOfOne1 += 2;
                }

                // 두번째 문자열 검사
                if(str2[i] == 'A' || str2[i] == 'D' || str2[i] == 'O' || str2[i] == 'P' || str2[i] == 'Q' || str2[i] == 'R') {
                    cntOfOne2 += 1;
                }
                if(str2[i] == 'B') {
                    cntOfOne2 += 2;
                }

                if(cntOfOne1 != cntOfOne2) {
                    flag = false;
                    printf("#%d DIFF\n", t);
                    break;
                }
            }

            if(flag) {
                printf("#%d SAME\n", t);
            }

        }

    }

    return 0;
}