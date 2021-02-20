#include <vector>

using namespace std;
const int MAX = 1e4;

// first: 연결된 정점 번호, second: 간선 가중치
vector<vector< pair<int, int> > > adj(MAX);

vector<int> dijkstra_without_pq(int src) {

    vector<int> isVisited(MAX, 0);
    vector<int> dist(MAX);

    dist[src] = 0;

    while (true)
    {
        int closest = INT_MAX, here;
        for(int i = 0; i < MAX; i++) {
            if(dist[i] < closest && !isVisited[i]) {
                here = i;
                closest = dist[i];
            }
        }

        if(closest == INT_MAX) break;
        isVisited[here] = 1;

        for(int i = 0; i < adj[here].size(); i++) {
            int there = adj[here][i].first;
            if(isVisited[there]) continue;
            int nextDist = dist[here] + adj[here][i].second;
            dist[there] = min(dist[there], nextDist);
        }

    }
    
    return dist;
}