#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 105;

char str[MAX];
int cntOfCharacter[4];

int main() {

    while (fgets(str, MAX, stdin) != NULL)
    {
        memset(cntOfCharacter, 0, sizeof(cntOfCharacter));

        int len = strlen(str);
        for(int i = 0; i < len; i++) {
            int tmp = str[i];
            if(tmp >= 'A' && tmp <= 'Z') {
                cntOfCharacter[1]++;
            } else if(tmp >= 'a' && tmp <= 'z') {
                cntOfCharacter[0]++;
            } else if(tmp == 0x20) {
                cntOfCharacter[3]++;
            } else if(tmp != '\n'){
                cntOfCharacter[2]++;
            }
        }

        for(int i = 0; i < 4; i++) {
            printf("%d ", cntOfCharacter[i]);
        }
        printf("\n");
    }
    



    return 0;
}