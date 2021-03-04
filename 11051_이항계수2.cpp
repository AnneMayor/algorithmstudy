#include <bits/stdc++.h>

using namespace std;

const int MODULO = 10007;

int main(void) {

    int n, k;
    scanf("%d %d", &n, &k);

    vector<vector<long long> > nCr(n+5, vector<long long>(k+5, 0));

    nCr[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            if(j == 0 || i == j) nCr[i][j] = 1;
            else nCr[i][j] = (nCr[i-1][j] + nCr[i-1][j-1]) % MODULO;
        }
    }

    printf("%lld\n", nCr[n][k]);

    return 0;
}