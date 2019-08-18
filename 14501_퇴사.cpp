#include <iostream>

using namespace std;

int main() {

    int n;
    scanf("%d", &n);

    int day[n+5];
    int profit[n+5];
    int d[n+5];
    int maxAns = 0;

    for(int i = 1; i <= n; i++) {
        scanf("%d %d", &day[i], &profit[i]);
        d[i] = profit[i];
    }

    for(int i = 2; i <= n; i++) {
        for(int j = 1; j < i; j++) {
            if(i-j >= day[j]) {
                d[i] = max(d[i], d[j]+profit[i]);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        if(i+day[i] <= n+1) {
            if(maxAns < d[i]) {
                maxAns = d[i];
            }
        }
    }

    printf("%d", maxAns);

    return 0;
}