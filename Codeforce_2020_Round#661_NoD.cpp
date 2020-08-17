#include <bits/stdc++.h>

using namespace std;
const int MAX = 2*1e6;

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int n;
        scanf("%d", &n);
        char nums[MAX];
        scanf("%s", nums);

        vector<int> pos0;
        vector<int> pos1;
        vector<int> ans(n);

        for(int i = 0; i < n; i++) {
            int newPos = pos0.size() + pos1.size();
            if(nums[i] == '0') {
                if(pos1.empty()) {
                    pos0.push_back(newPos);
                } else {
                    newPos = pos1.back();
                    pos1.pop_back();
                    pos0.push_back(newPos);
                }
            } else {
                if(pos0.empty()) {
                    pos1.push_back(newPos);
                } else {
                    newPos = pos0.back();
                    pos0.pop_back();
                    pos1.push_back(newPos);
                }
            }
            ans[i] = newPos;
        }

        printf("%d\n", pos0.size() + pos1.size());
        for(int i = 0; i < n; i++) {
            printf("%d ", ans[i]+1);
        }
        printf("\n");
    }

    return 0;
}