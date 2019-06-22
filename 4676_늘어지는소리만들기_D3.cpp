#include <iostream>
#include <string.h>

using namespace std;
const int MAX = 25;

char str[MAX];
int cntOfhypen[MAX];

int main()
{

    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++)
    {

        scanf("%s", str);
        memset(cntOfhypen, 0, sizeof(cntOfhypen));

        int k;
        scanf("%d", &k);

        int cnt = 0;

        for (int i = 0; i < k; i++)
        {
            int idx;
            scanf("%d", &idx);

            cntOfhypen[idx] += 1;

        }

        int len = strlen(str);

        printf("#%d ", tc);
        for(int i = 0; i <= len; i++) {
            for(int j = 0; j < cntOfhypen[i]; j++) {
                printf("-");
            }

            if(i == len) continue;

            printf("%c", str[i]);
        }

        printf("\n");
    }

    return 0;
}