#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>

using namespace std;
const int MAX = 12;

vector<int> numList;
int n, m;
int nums[MAX];
bool isChecked[MAX];
set<string> ans;

bool duplicate() {
    string tmp = "";
    int len = numList.size();
    for(int i = 0; i < len; i++) {
        tmp += numList[i] + '0';
    }

    if(ans.find(tmp) == ans.end()) {
        ans.insert(tmp);
        return false;
    } else return true;
}

void backtracking(int cnt, int idx) {
    if(idx > m) return ;
    if(idx == m) {
        if(!duplicate()) {
            int len = numList.size();
            for(int i = 0; i < len; i++) {
                printf("%d ", numList[i]);
            }
            printf("\n");
        }
        return ;
    }

    for(int i = cnt; i < n; i++) {
        if(!isChecked[i]) {
            isChecked[i] = true;
            numList.push_back(nums[i]);
            backtracking(i, idx+1);
            numList.pop_back();
            isChecked[i] = false;
        }
    }

}

// Backtracking문제!
int main() {
    
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    memset(isChecked, false, sizeof(isChecked));

    sort(nums, nums+n);

    backtracking(0, 0);
    
    return 0;
}