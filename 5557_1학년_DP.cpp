#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 102;

long long d[MAX][MAX];
int num[MAX];

int main() {

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    memset(d, 0, sizeof(d));
    d[0][num[0]] = 1;
    for(int i = 1; i < n-1; i++) {
        for(int j = 0; j <= 20; j++) {
            if(j - num[i] >= 0) {
                d[i][j] += d[i-1][j-num[i]];
            }
            if(j + num[i] <= 20) {
                d[i][j] += d[i-1][j+num[i]];
            }
        }
    }

    printf("%lld\n", d[n-2][num[n-1]]);

    return 0;
}