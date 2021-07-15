#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 30;

vector<vector<int> > maps(MAX);
bool isChecked[MAX];

int recursiveSearch(int u, int cnt, int n) {
    if(u >= n) return cnt;
    if(isChecked[u]) return recursiveSearch(u+1, cnt, n);
    int result = 0;
    for(int i = 0; i < maps[u].size(); i++) {
        int v = maps[u][i];
        if(!isChecked[v]) {
            isChecked[v] = 1;
            result = max(result, recursiveSearch(u+1, cnt+1, n));
            isChecked[v] = 0;
        }
    }

    return max(result, recursiveSearch(u+1, cnt, n));
}

int main(void) {

    int n, m;
    scanf("%d %d", &n, &m);
    fill(isChecked, isChecked+MAX, 0);

    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--, b--;
        if(a > b) maps[b].push_back(a);
        else maps[a].push_back(b);
    }

    int ans = recursiveSearch(0, 0, n);
    ans *= 2;
    ans = (n > ans ? (ans+1) : ans);
    printf("%d\n", ans);

    return 0;
}