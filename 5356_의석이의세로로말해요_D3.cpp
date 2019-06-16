#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 20;

char letterMap[MAX][MAX];

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {

        int maxLength = 0;

        memset(letterMap, 0, sizeof(letterMap));

        for(int i = 0; i < 5; i++) {
            scanf("%s", letterMap[i]);
            if(maxLength < strlen(letterMap[i])) {
                maxLength = strlen(letterMap[i]);
            }
        }

        printf("#%d ", tc);

        for(int y = 0; y < maxLength; y++) {
            for(int x = 0; x < 5; x++) {
                if(!letterMap[x][y]) continue;
                printf("%c", letterMap[x][y]);
            }
        }

        printf("\n");

    }

    return 0;
}