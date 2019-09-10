#include <iostream>

using namespace std;

int main() {


    int nums[7];

    for(int i = 0; i < 7; i++) {
        scanf("%d", &nums[i]);
    }

    int total = 0, mi = 1000;

    for(int i = 0 ; i < 7; i++) {
        if(nums[i] & 1) {
            total += nums[i];
            if(mi > nums[i]) mi = nums[i];
        }
    }

    if(mi == 1000) {
        printf("%d\n", -1);
    } else {
        printf("%d\n", total);
        printf("%d\n", mi);
    }


    return 0;
}