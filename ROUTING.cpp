#include <bits/stdc++.h>

using namespace std;
const int MAX = 20001;

// first: 연결된 컴퓨터 번호, second: 노이즈 증폭 가중치
vector<pair< int, long double> > adj[MAX];
long double dist[10001];
int isVisited[10001];

long double dijkstra(int V, int start) {
    
    dist[start] = 1;
    priority_queue<pair<long double, int> > pq;
    pq.push(make_pair(-1, start));
    
    while (!pq.empty())
    {
        long double cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        // 1. 방문한 정점 체크
        // if(isVisited[here]) continue;
        // isVisited[here] = 1;

        // 2. 각 정점의 현재 최단거리 비교
        if(dist[here] < cost) continue;

        for(int i = 0; i < adj[here].size(); i++) {
            int there  = adj[here][i].first;
            long double nextDist = adj[here][i].second*cost;
            if(dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }

    }

    return dist[V-1];
}

int main(void)
{

    int t;
    scanf("%d", &t);

    for (int tc = 1; tc <= t; tc++)
    {
        int n, m;
        scanf("%d %d", &n, &m);

        for (int i = 0; i < n; i++) {
            dist[i] = DBL_MAX;
            adj[i].clear();
            isVisited[i] = 0;
        }

        for (int i = 0; i < m; i++)
        {
            int n1, n2;
            long double noiseWeight;
            scanf("%d %d %Lf", &n1, &n2, &noiseWeight);

            adj[n1].push_back(make_pair(n2, noiseWeight));
            adj[n2].push_back(make_pair(n1, noiseWeight));
        }

        long double ans = dijkstra(n, 0);
        printf("%.10Lf\n", ans);

    }

    return 0;
}