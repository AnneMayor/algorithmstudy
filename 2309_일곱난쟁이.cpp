#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 10;

int heightOfDwarf[MAX];
vector<int> heightList;
vector<int> ans;

void dfs(int idx, int cnt) {

    if(cnt >= 7) {

        int total = 0;
        for(int i = 0; i < heightList.size(); i++) {
            total += heightList[i];
        }

        if(total == 100) {
            ans.clear();
            for(int i = 0; i < heightList.size(); i++) {
                ans.push_back(heightList[i]);
            }
        }

        return ;    
    }

    for(int i = idx+1; i < 9; i++) {
        heightList.push_back(heightOfDwarf[i]);
        dfs(i, cnt+1);
        heightList.pop_back();
    }

    return;

}

int main() {

    for(int i = 0; i < 9; i++) {
        scanf("%d", &heightOfDwarf[i]);
    }

    sort(heightOfDwarf, heightOfDwarf+9);

    for(int i = 0; i < 9; i++) {
        heightList.push_back(heightOfDwarf[i]);
        dfs(i, 1);
        heightList.pop_back();
    }

    for(int i = 0; i < ans.size(); i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}