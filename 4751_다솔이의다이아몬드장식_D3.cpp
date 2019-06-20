#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 60;

char alph[MAX];

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {

        scanf("%s", alph);
        int len = strlen(alph);

        printf("..");
        for(int i = 1; i <= len; i++) {
            printf("#");
            if(i == len) break;
            printf("...");
        }
        printf("..\n");

        for(int i = 0; i < 2*(2*len) + 1; i++) {
            if(i%2 == 0) {
                printf(".");
            } else {
                printf("#");
            }
        }
        printf("\n");

        for(int i = 0; i < len; i++) {
            printf("#.%c.", alph[i]);
        }
        printf("#\n");

        for(int i = 0; i < 2*(2*len) + 1; i++) {
            if(i%2 == 0) {
                printf(".");
            } else {
                printf("#");
            }
        }
        printf("\n");

        printf("..");
        for(int i = 1; i <= len; i++) {
            printf("#");
            if(i == len) break;
            printf("...");
        }
        printf("..\n");

    }

    return 0;
}