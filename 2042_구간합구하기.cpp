#include <iostream>

using namespace std;
const int MAX = 1e7;

long long nums[MAX];

int main() {

    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    long long sum = 0;
    for(int i = 0; i < n; i++) {
        scanf("%lld", &nums[i]);
        sum += nums[i];
    }

    for(int i = 0; i < m+k; i++) {
        long long a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);

        if(a == 1) {
            sum -= nums[b-1];
            nums[b-1] = c;
            sum += c;
        } else {
            
            long long ans = sum;
            for(int j = 0; j < b-1; j++) {
                ans -= nums[j];
            }

            for(int j = c; j < n; j++) {
                ans -= nums[j];
            }

            printf("%lld\n", ans);
        }
    }

    return 0;
}