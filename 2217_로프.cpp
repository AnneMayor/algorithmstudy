#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
const int MAX = 100005;

int nums[MAX];

int main() {

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    sort(nums, nums+n);

    int ans = -1000;
    for(int i = 0; i < n; i++) {
        ans = max(ans, (n-i)*nums[i]);
    }

    printf("%d\n", ans);


    return 0;
}