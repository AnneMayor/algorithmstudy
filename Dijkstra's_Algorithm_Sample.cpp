#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 1e4;

// first: 연결된 정점 번호, second: 간선 가중치
vector<pair<int, int> > adj[MAX];

int* dijkstra(int src) {
    int dist[MAX];
    memset(dist, INFINITY, sizeof(dist));
    dist[src] = 0;
    
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, src));

    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if(dist[here] < cost) continue;
        for(int i =0; i < adj[here].size(); i++) {
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;
            
            if(dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }
    
    return dist;
}