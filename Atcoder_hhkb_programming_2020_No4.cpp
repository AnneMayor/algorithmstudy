#include <bits/stdc++.h>

#define ll long long
using namespace std;

int modNum = 1e9+7;

int main(void) {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int n, a, b;
        scanf("%d %d %d", &n, &a, &b);

        if(n < (a+b)) printf("0\n");
        else {
            ll alpha = (n-a+1) % modNum;
            ll beta = (n-b+1) % modNum;
            ll lmbda = (n-a-b+1) % modNum;
            ll x = (((alpha*beta) % modNum) - ((lmbda*(lmbda+1))%modNum) + modNum)%modNum;
            ll all = (((alpha*alpha) % modNum) * ((beta*beta) % modNum)) % modNum;
            ll ans = ((all - (x*x)%modNum) + modNum)%modNum;
            printf("%lld\n", ans);
        }

    }

    return 0;
}