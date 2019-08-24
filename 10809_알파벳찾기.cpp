#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 105;

int cntOfAlpha[MAX];
char str[MAX];

int main() {

    memset(cntOfAlpha, -1, sizeof(cntOfAlpha));

    scanf("%s", str);

    int len = strlen(str);

    for(int i = 0; i < len; i++) {
        if(cntOfAlpha[str[i]-'a'] != -1) continue;
        cntOfAlpha[str[i]-'a'] = i;
    }

    for(int i = 0; i < 26; i++) {
        printf("%d ", cntOfAlpha[i]);
    }
    printf("\n");

    return 0;
}