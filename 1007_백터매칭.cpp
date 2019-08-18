#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;
const int MAX = 25;

double ans;
vector<int> vList;
bool isChecked[MAX];

void solve(pair<int, int> nums[], int cnt, int idx ,int total) {

    if(cnt == total/2) {
        
        double sum = 0;
        double nx = 0, ny = 0;

        for(int i = 0; i < total; i++) {
            if(isChecked[i]) {
                nx += nums[i].first;
                ny += nums[i].second;
            } else {
                nx -= nums[i].first;
                ny -= nums[i].second;
            }
        }

        sum = sqrt(abs(nx*nx) + abs(ny*ny));

        if(ans > sum) ans = sum;

        return;
    }

    if(idx == total) return;

    solve(nums, cnt, idx+1, total);
    isChecked[idx] = true;
    solve(nums, cnt+1, idx+1, total);
    isChecked[idx] = false;

}

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int n;
        scanf("%d", &n);

        ans = 1000000000;

        memset(isChecked, false, sizeof(isChecked));

        pair<int, int> nums[n];

        for(int i = 0; i < n; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            nums[i].first = x;
            nums[i].second = y;
        }

        solve(nums, 0, 0, n);

        printf("%.12lf\n", ans);

    }

    return 0;

}