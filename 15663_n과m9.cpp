#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <string.h>
#include <algorithm>
#define MAX 100

using namespace std;

int nums[MAX];
int n, m;
vector<int> ans;
bool isChecked[MAX];
set<string> Set;

void dfs(int cnt)
{

    if (cnt >= m)
    {
        string temp;
        for (int i = 0; i < m; i++)
        {
            temp += to_string(ans[i]);
        }
        if(*Set.find(temp) == "") {
            Set.insert(temp);
            for(int i = 0; i < ans.size(); i++) {
                printf("%d ", ans[i]);
            }
            printf("\n");
        }
        
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (isChecked[i])
            continue;
        ans.push_back(nums[i]);
        isChecked[i] = true;
        dfs(cnt + 1);
        ans.pop_back();
        isChecked[i] = false;
    }
}

int main()
{

    scanf("%d %d", &n, &m);
    memset(isChecked, false, sizeof(isChecked));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    sort(nums, nums + n);
    ans.clear();
    Set.clear();

    dfs(0);

    return 0;
}