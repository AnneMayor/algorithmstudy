#include <bits/stdc++.h>

using namespace std;
const int MAX = 20005;

// first: dest 정점 번호, second: weight 간선 가중치
vector<pair<int, int> > maps[MAX];
int n, m;

int dijkstra(int src) {
    vector<int> dist(n+1, INT_MAX);
    int isVisited[MAX];
    memset(isVisited, 0, sizeof(isVisited));

    priority_queue<pair<int, int> > pq;
    for(pair<int, int> v : maps[src]) {
        dist[v.first] = v.second;
        pq.push(make_pair(-v.second, v.first));
    }

    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if(isVisited[here]) continue;
        isVisited[here] = 1;
        dist[here] = min(dist[here], cost);
        if(here == src) break;
        for(int i = 0; i < maps[here].size(); i++) {
            int there = maps[here][i].first;
            int nextDist = maps[here][i].second;

            if(isVisited[there]) continue;            
            if(dist[there] > dist[here] + nextDist) {
                dist[there] = dist[here] + nextDist;
                pq.push(make_pair(-dist[there], there));
            }
        }
    }

    return dist[src];
}

int main(void) {

    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        maps[src].push_back(make_pair(dest, weight));
    }

    for(int i = 1; i <= n; i++) {
        int ans = dijkstra(i);
        if(ans == INT_MAX) {
            printf("-1\n");
        } else printf("%d\n", ans);
    }

    return 0;
}