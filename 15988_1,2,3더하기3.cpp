#include <iostream>

using namespace std;

const int MAX = 1e6+5;

long long numOfCases[MAX];

int main() {

    int T;
    scanf("%d", &T);

    numOfCases[1] = 1;
    numOfCases[2] = 2;
    numOfCases[3] = 4;

    for(int tc = 1; tc <= T; tc++) {
        int n;
        scanf("%d", &n);
        for(int i = 4; i <= n; i++) {
            numOfCases[i] = (numOfCases[i-1] + numOfCases[i-2] + numOfCases[i-3])%1000000009;
        }

        printf("%lld\n", numOfCases[n]);
    }

    return 0;
}