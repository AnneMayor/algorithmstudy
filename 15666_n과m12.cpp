#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;
const int MAX = 10;

int n, m;
vector<int> nums;
vector<int> numList;
set<string> group;

bool duplicate() {
    int len = numList.size();
    string tmp = "";
    for(int i = 0; i < len; i++) {
        tmp += numList[i] + '0';
    }

    if(group.find(tmp) == group.end()) {
        group.insert(tmp);
        return false;
    } else return true;
}

void recursive(int idx, int cnt) {
    if(cnt > m) return;
    if(cnt == m) {

        if(!duplicate()) {
            int len = numList.size();
                for(int i = 0; i < len; i++) {
                    printf("%d ", numList[i]);
                }
            printf("\n");
        }
        
        return ;
    }

    for(int i = idx; i < n; i++) {
        numList.push_back(nums[i]);
        recursive(i, cnt+1);
        numList.pop_back();
    }
}

int main() {
    
    scanf("%d %d", &n, &m);
    
    for(int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        nums.push_back(num);
    }

    sort(nums.begin(), nums.end());

    // nums.erase(unique(nums.begin(), nums.end()));

    for(int i = 0; i < n; i++) {
        numList.push_back(nums[i]);
        recursive(i, 1);
        numList.pop_back();
    }

    return 0;
}