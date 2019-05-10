#include <iostream>
#include <string.h>

using namespace std;

const int MAX = 100005;

int main() {

    int T;
    scanf("%d", &T);

    for(int t = 1; t <= T; t++) {
        char str[MAX];
        scanf("%s", str);

        int len = strlen(str);
        for(int i = 0; i < len; i++) {
            if(str[i] >= 48 && str[i] <= 57) {
                str[i] += 4;
            } else if(str[i] >= 65 && str[i] <= 90) {
                str[i] -= 65;
            } else if(str[i] == '+') {
                str[i] += 19;
            } else if(str[i] == '/') {
                str[i] += 16;
            } else {
                str[i] -= 71;
            }
        }

        printf("#%d ", t);
        for(int i = 0; i < len; i += 4) {

            char temp = str[i];
            temp = (str[i] << 2) + (str[i+1] >> 4); // 최상위 비트 2개 자르기
            printf("%c", temp);
            temp = (str[i+1] << 4) + (str[i+2] >> 2); // 최상위 비트 4개 자르기
            printf("%c", temp);
            temp = (str[i+2] << 6) + str[i+3];
            printf("%c", temp); 
        }

        printf("\n");
        
    }



    return 0;

}