#include <iostream>
#define ll long long

using namespace std;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

pair<ll, ll> ext_gcd(int a, int b) {
    if(b) {
        pair<ll, ll > tmp = ext_gcd(b, a%b);
        return make_pair(tmp.second, tmp.first - (a/b)*tmp.second);
    } else return make_pair(1, 0);
}

ll mod_inv(int a, int M) {
    cout << "first: " << ext_gcd(a, M).first << endl;
    return (ext_gcd(a, M).first+M) % M;
}

int main() {

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; tc++) {
        int k, c;
        scanf("%d %d", &k, &c);
        if(gcd(k, c) != 1) {
            printf("IMPOSSIBLE\n");
            continue;
        }

        ll ans = mod_inv(c, k);
        while (c*ans <= k)
        {
            ans += k;
        }
        
        if(ans > 1e9) printf("IMPOSSIBLE\n");
        else printf("%lld\n", ans);

    }

    
    return 0;
}