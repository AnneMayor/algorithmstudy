#include <iostream>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int n, m;
        scanf("%d %d", &n, &m);

        int numOfUnicon = 0;
        for(int i = 0; i <= m; i++) {
            int tmp = n;
            tmp -= i;
            int numOfTwin = tmp/2;
            if(numOfTwin + i == m) {
                numOfUnicon = i;
                break;
            }
        }

        printf("#%d %d %d\n", tc, numOfUnicon, m-numOfUnicon);

    }

    return 0;
}