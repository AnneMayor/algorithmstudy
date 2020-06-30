#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e4;

int nums[MAX];

int main() {

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    sort(nums, nums+n);

    long long sum = 1;
    for(int i = 0; i < n; i++) {
        if(sum < nums[i]) break;    
        sum += nums[i];
    }

    printf("%lld\n", sum);

    return 0;
}