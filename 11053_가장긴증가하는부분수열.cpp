#include <iostream>
#include <string.h>

using namespace std;

int main() {

    int n;
    scanf("%d", &n);

    int nums[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int d[n];

    memset(d, 0, sizeof(d));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(nums[i] > nums[j]) {
                d[i] = max(d[i], d[j]);
            }
        }
        d[i]++;
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(ans < d[i]) {
            ans = d[i];
        }
    }

    printf("%d\n", ans);
    

    return 0;
}