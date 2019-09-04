#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
const int MAX = 101;

bool isVisited[MAX];
int ans;

void dfs(int idx, const vector<vector<int> > & map) {

    if(map[idx].size() <= 0) return;

    isVisited[idx] = true;

    for(int i = 0; i < map[idx].size(); i++) {
        if(!isVisited[map[idx][i]]) {
            ans++;
            dfs(map[idx][i], map);
        }
    }

    return ;
}

int main() {

    int n;
    scanf("%d", &n);
    int m;
    scanf("%d", &m);

    vector<vector<int> > map;
    map.resize(n+1);

    memset(isVisited, false, sizeof(isVisited));

    ans = 0;
    for(int i = 0; i < m; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        map[start].push_back(end);
        map[end].push_back(start);
    }

    dfs(1, map);

    printf("%d\n", ans);

    return 0;
}