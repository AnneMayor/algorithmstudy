#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, pair<int, int> > > edges;

struct DisjointSet {
    vector<int> parent, rank;
    DisjointSet(int n) : parent(n+1), rank(n+1, 1) {
        for(int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    void merge(int u, int v) {
        u = find(u), v = find(v);
        if(u == v) return ;
        if(rank[u] > rank[v]) swap(u, v);
        parent[u] = v;
        if(rank[u] == rank[v]) rank[v]++;
    }

};

int kruskal(vector<pair<int, pair<int, int> > > & edges, int vertex) {
    int ret = 0;

    sort(edges.begin(), edges.end());
    DisjointSet set(vertex);

    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i].second.first, v = edges[i].second.second;
        if(set.find(u) == set.find(v)) continue;
        set.merge(u, v);
        ret += edges[i].first;
    }

    return ret;
}

int main() {

    int V, E;
    scanf("%d %d", &V, &E);

    edges.clear();
    for(int i = 0; i < E; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        edges.push_back(make_pair(c, make_pair(a, b)));
    }

    int ans = kruskal(edges, V);
    printf("%d\n", ans);

    return 0;
}