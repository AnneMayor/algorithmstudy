#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
const int MAX = 205;

int n, m;
bool checkComb[MAX][MAX];
int ans;
vector<int> numList;

bool findComb(int idx, int cnt) {

    for(int i = idx+1; i < 3; i++) {
        if(!checkComb[numList[idx]][numList[i]]) return false;
        else findComb(i, cnt+1);
    }

    return true;

}

bool isOk() {
    bool ret = true;

    for(int i = 0; i < 3; i++) {
        ret = findComb(i, 0);
        if(!ret) break;
    }

    return ret;
}

void dfs(int idx, int cnt) {
    if(cnt >= 3) {
        if(isOk()) {
            ans++;
        }
        return ;
    }

    for(int i = idx+1; i <= n; i++) {
        numList.push_back(i);
        dfs(i, cnt+1);
        numList.pop_back();
    }
}

int main() {

    scanf("%d %d", &n, &m);

    memset(checkComb, true, sizeof(checkComb));

    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        checkComb[a][b] = false;
        checkComb[b][a] = false;
    }

    ans = 0;
    for(int i = 1; i <= n; i++) {
        numList.push_back(i);
        dfs(i, 1);
        numList.pop_back();
    }

    printf("%d\n", ans);
    
    return 0;
}