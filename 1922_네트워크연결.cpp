#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
const int MAX = 1005;
const int INF = 987654321;

vector<pair<int, int> > adj[MAX];
bool isChecked[MAX];
int parent[MAX];

int prim(int n) {
    int ret = 0;
    vector<int> minWeight(n+1, INF);

    minWeight[1] = parent[1] = 0;
    for(int i = 1; i <= n; i++) {
        int u = -1;
        for(int v = 1; v <= n; v++) {
            if(!isChecked[v] && (u == -1 || minWeight[u] > minWeight[v])) {
                u = v;
            }
        }

        ret += minWeight[u];
        isChecked[u] = true;
        
        for(int j = 0; j < adj[u].size(); j++) {
            int v = adj[u][j].first, weight = adj[u][j].second;
            if(!isChecked[v] && minWeight[v] > weight) {
                parent[v] = u;
                minWeight[v] = weight;
            }
        }
    }

    return ret;
}

int main() {

    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
    }

    memset(isChecked, false, sizeof(isChecked));
    memset(parent, -1, sizeof(parent));
    int ans = prim(n);
    printf("%d\n", ans);

    return 0;
}