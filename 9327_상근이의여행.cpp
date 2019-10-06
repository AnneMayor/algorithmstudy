#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct DisjointSet {

    vector<int> parent, rank;
    DisjointSet(int n) : parent(n+1), rank(n+1, 1) {
        for(int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int v) {
        if(v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }

    void merge(int u, int v) {
        u = find(u), v = find(v);
        if(u == v) return ;
        if(rank[u] > rank[v]) swap(u, v);
        parent[u] = v;
        if(rank[u] == rank[v]) rank[v]++;
    }

};

int kruskal(vector<pair<int, pair<int, int> > > & edges, int numOfAirplane) {
    int ret = 0;

    sort(edges.begin(), edges.end());
    DisjointSet sets(numOfAirplane);

    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i].second.first, v = edges[i].second.second;
        if(sets.find(u) == sets.find(v)) continue;
        sets.merge(u, v);
        ret += edges[i].first;
    }

    return ret;
}

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {

        int n, m;
        scanf("%d %d", &n, &m);

        vector<pair<int, pair<int, int> > > edges;
        edges.clear();
        for(int i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            edges.push_back(make_pair(1, make_pair(a, b)));
        }

        int ans = kruskal(edges, n);
        printf("%d\n", ans);
 
    }

    return 0;
}