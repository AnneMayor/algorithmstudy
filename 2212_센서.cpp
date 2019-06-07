#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 10005;

int nums[MAX];
vector<int> distance1;

int main() {

    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);

    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    sort(nums, nums+n);

    distance1.clear();
    long long ans = 0;

    for(int i = 0; i < n-1; i++) {
        int d = nums[i+1] - nums[i];
        distance1.push_back(d);
    }

    sort(distance1.begin(), distance1.end());

    // for(int i = 0; i < distance1.size(); i++) {
    //     cout << distance1[i] << " ";
    // }

    for(int i = 1; i < k; i++) {
        if(!distance1.empty()) {
            distance1.pop_back();
        }
    }

    for(int i = 0; i < distance1.size(); i++) {
        ans += distance1[i];
    }

    printf("%lld\n", ans);

    return 0;
}