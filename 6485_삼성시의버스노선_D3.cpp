#include <iostream>
#include <string.h>

using namespace std;
const int MAX = 5005;

int cntOfBusStop[MAX];

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {

        memset(cntOfBusStop, 0, sizeof(cntOfBusStop));

        int n;
        scanf("%d", &n);

        for(int i = 0; i < n; i++) {
            int s, e;
            scanf("%d %d", &s, &e);

            while(s <= e) {
                cntOfBusStop[s++] += 1;
            }
        }

        int p;
        scanf("%d", &p);

        printf("#%d ", tc);
        for(int i = 0; i < p; i++) {
            int bus;
            scanf("%d", &bus);
            printf("%d ", cntOfBusStop[bus]);
        }
        printf("\n");
        
    }

    return 0;
}