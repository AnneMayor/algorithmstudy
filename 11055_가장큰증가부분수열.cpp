#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 1005;

int nums[MAX];
int d[MAX];

int main() {

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    memset(d, 0, sizeof(d));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(nums[j] < nums[i]) {
                if(d[i] < d[j]) {
                    d[i] = d[j];
                }
            }
        }
        d[i] += nums[i];
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(ans < d[i]) ans = d[i];
    }

    printf("%d\n", ans);

    return 0;
}