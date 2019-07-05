#include <iostream>

using namespace std;

int main() {

    int n;
    scanf("%d", &n);

    int nums[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int maxValue = -10000000;
    int minValue = 10000000;

    for(int i = 0; i < n; i++) {
        if(maxValue < nums[i]) maxValue = nums[i];
        if(minValue > nums[i]) minValue = nums[i];
    }

    printf("%d %d\n", minValue, maxValue);

    return 0;
}