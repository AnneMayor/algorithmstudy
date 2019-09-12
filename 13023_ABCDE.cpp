#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX = 2005;

vector<vector<int> > friendsList;
bool isFriends[MAX];
int n, m;
int ans;

void dfs(int idx, int cnt)
{

    isFriends[idx] = true;

    if (cnt >= 5)
    {
        ans = 1;
        return;
    }

    for (int i = 0; i < friendsList[idx].size(); i++)
    {
        if (!isFriends[friendsList[idx][i]])
        {
            dfs(friendsList[idx][i], cnt + 1);   
        }
        
    }

    isFriends[idx] = false;

    return;
}

int main()
{

    scanf("%d %d", &n, &m);
    ans = 0;

    friendsList.clear();
    friendsList.resize(n);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        friendsList[a].push_back(b);
        friendsList[b].push_back(a);
    }

    for(int i = 0; i < n; i++) {
        if(friendsList[i].size() > 0) {
            sort(friendsList[i].begin(), friendsList[i].end());
        }
    }

    for (int i = 0; i < n; i++)
    {
        memset(isFriends, false, sizeof(isFriends));
        dfs(i, 1);
    }

    if (ans)
    {
        printf("1\n");
    }
    else
    {
        printf("0\n");
    }

    return 0;
}