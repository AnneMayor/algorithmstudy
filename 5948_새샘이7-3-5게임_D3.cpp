#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> numList;
int nums[7];
vector<int> ans;

void findAns(int cnt, int idx) {

    if(cnt >= 3) {
        int total = 0;
        for(int i = 0; i < numList.size(); i++) {
            total += numList[i];
        }
        ans.push_back(total);
        return;
    }

    for(int i = idx+1; i < 7; i++) {
        numList.push_back(nums[i]);
        findAns(cnt+1, i);
        numList.pop_back();
    }

}

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {

        for(int i = 0; i < 7; i++) {
            scanf("%d", &nums[i]);
        }

        numList.clear();
        ans.clear();

        for(int i = 0; i < 7; i++) {
            numList.push_back(nums[i]);
            findAns(1, i);
            numList.pop_back();
        }

        sort(ans.begin(), ans.end(), greater<int>());

        // for(int i = 0; i < ans.size(); i++) {
        //     cout << ans[i] << " ";
        // }
        // cout << endl;

        int count = 0;
        int max = -1;
        for(int i = 0; i < ans.size(); i++) {
            if(count >= 5) {
                break;
            }
            if(max != ans[i]) {
                max = ans[i];
                count += 1;
            }
        }

        printf("#%d %d\n", tc, max);

    }

    return 0;
}