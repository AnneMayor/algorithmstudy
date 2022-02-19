#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

bool check(long long d, int n, int a[], int k) {
    vector<int> r(n);

    long long pos = 0l;
    for(int i = 0; i < n; i++) {
        r[i] = a[i] % d;
        pos += d - r[i];
    }

    long long rSum = 0l;
    sort(r.begin(), r.end());
    for(int i = 0; i < n; i++) {
        if(pos == rSum) return pos <= k;
        pos -= d - r[i];
        rSum += r[i];
    }

    return 0;
}

int main(void) {

    int n, k;
    long long ans = 1;
    scanf("%d %d", &n, &k);
    int a[n];
    memset(a, 0, sizeof(a));
    long long sum = 0l;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    for(long long d = 1; d * d <= sum; d++) {
        if(sum % d) continue;
        // cout << "d: " << d << endl; 
       if(check(d, n, a, k)) {
           ans = max(ans, d);
       }

       if(check(sum/d, n, a, k)) {
           ans = max(ans, sum/d);
       }
    }

    printf("%lld\n", ans);

    return 0;
}