#include <iostream>

using namespace std;
const int MAX = 105;

int nums[MAX];

int GCD(int a, int b) {
    if(b==0) return a;
    return GCD(b, a%b);
}

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {

        int n;
        scanf("%d", &n);

        for(int i = 0; i < n; i++) {
            scanf("%d", &nums[i]);
        }

        long long sum = 0;
        for(int i = 0; i < n-1; i++) {
            for(int j = i+1; j < n; j++) {
                sum += GCD(nums[i], nums[j]);
            }
        }

        printf("%lld\n", sum);

    }

    return 0;
}