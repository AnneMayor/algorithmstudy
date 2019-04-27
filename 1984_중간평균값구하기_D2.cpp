#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int T;
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for(int t = 1; t <= T; t++) {

        int nums[10];
        double ans = 0;

        for(int i = 0; i < 10; i++) {
            cin >> nums[i];
        }

        int max = -1;
        int min = 10001;

        for(int i = 0; i < 10; i++) {
            if(max < nums[i]) {
                max = nums[i];
            }
            if(min > nums[i]) {
                min = nums[i];
            }
        }

        double total = 0.0;
        for(int i = 0; i < 10; i++) {
            if(max == nums[i]) continue;
            if(min == nums[i]) continue;
            total += nums[i];
        }

        ans = total / 8.0;

        cout << "#" << t << " " << round(ans) << endl;

    }

    return 0;
}