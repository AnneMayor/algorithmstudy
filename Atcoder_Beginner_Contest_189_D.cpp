#include <bits/stdc++.h>

using namespace std;

long long pow(int base, int n) {
    long long result = 1;
    for(int i = 0; i < n; i++) {
        result *= base;
    }

    return result;
}

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    long long ans = 1;
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        if(s == "OR") ans += pow(2, i);
    }
    
    printf("%lld\n", ans);

    return 0;
}