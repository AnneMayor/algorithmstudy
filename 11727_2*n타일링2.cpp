#include <iostream>

using namespace std;
const int MAX = 1005;

int d[MAX];

int main() {

    int n;
    scanf("%d", &n);

    d[1] = 1;
    d[2] = 3;
    for(int i = 3; i <= n; i++) {
        d[i] = d[i-1]+2*d[i-2];
        d[i] %= 10007;
    }

    printf("%d\n", d[n]);

    return 0;
}