#include <iostream>
#include <vector>

using namespace std;
vector<int> nums;

int main() {

    int n, k;
    scanf("%d %d", &n, &k);
    int ans = 0;

    for(int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        nums.push_back(num);
    }

    int len = nums.size();
    for(int i = len-1; i >=0; i--) {
        ans += k / nums[i];
        k %= nums[i];
    }

    printf("%d\n", ans);

    return 0;
}