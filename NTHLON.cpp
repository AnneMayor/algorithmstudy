#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int START = 401;
const int MAX = 405;
const int INF = 987654321;

int dist[MAX];

void dijstra(int src, vector<vector<pair<int, int> > > & map);

int vertex(int delta);

int main(void) {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {

        vector<int> a, b;
        int m;
        scanf("%d", &m);

        for(int i = 0; i <= MAX; i++) {
            dist[i] = INF;
        }

        for(int i = 0; i < m; i++) {
            int at, bt;
            scanf("%d %d", &at, &bt);
            a.push_back(at);
            b.push_back(bt);
        }

        vector<vector<pair<int, int> > > convertV(MAX);
        for(int i = 0; i < m; i++) {
            int delta = a[i] - b[i];
            convertV[START].push_back(make_pair(vertex(delta), a[i]));
        }

        for(int delta = -200; delta <= 200; delta++) {
            for(int i = 0; i < m; i++) {
                int next = delta + a[i] - b[i];
                if(abs(next) > 200) continue;
                convertV[vertex(delta)].push_back(make_pair(vertex(next), a[i]));
            }
        }

        dijstra(START, convertV);

        int ans = dist[vertex(0)];

        if(ans == INF) printf("IMPOSSIBLE\n");
        else printf("%d\n", ans);
    }

    return 0;
}

void dijstra(int src, vector<vector<pair<int, int> > > & map) {
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> > >  pq;
    pq.push(make_pair(0, src));

    while (!pq.empty())
    {
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if(dist[here] < cost) continue;

        for(int i = 0; i < map[here].size(); i++) {
            int there = map[here][i].first;
            int nextDist = cost + map[here][i].second;
            if(dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }
    
}

int vertex(int delta) {
    return delta + 200;
}