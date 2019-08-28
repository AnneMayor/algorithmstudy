#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 105;

long long d[MAX];

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int n;
        scanf("%d", &n);

        memset(d, 0, sizeof(d));

        d[1] = 1;
        d[2] = 1;
        d[3] = 1;

        for(int i = 4; i <= n; i++) {
            d[i] = d[i-3] + d[i-2];
        }

        printf("%lld\n", d[n]);
        
    }

    return 0;
}