#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 60;

char str[MAX];

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        scanf("%s", str);

        int len = strlen(str);

        printf("#%d ", tc);

        for(int i = 0; i < len; i++) {
            if(str[i] == 'a' || str[i] == 'i' || str[i] == 'e' || str[i] == 'o' || str[i] == 'u') continue;

            printf("%c", str[i]);
        }

        printf("\n");

    }

    return 0;
}