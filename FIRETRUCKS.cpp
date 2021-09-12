#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int MAX = 1002;

vector<vector<pair<int, int> > > map;

void dijstra(int src, vector<int> & dist, vector<int> & fireStation);

int main(void) {

    int T;
    scanf("%d", &T);
     
    for(int tc = 1; tc <= T; tc++) {
        vector<int> firePlace;
        vector<int> fireStation;
        int v, e, n, m;
        scanf("%d %d %d %d", &v, &e, &n, &m);
        map = vector<vector<pair<int, int> > >(e, vector<pair<int, int> >());
        vector<int> dist(v+1, 987654321);

        for(int i = 0; i < e; i++) {
            int a, b, t;
            scanf("%d %d %d", &a, &b, &t);

            map[a].push_back(make_pair(b, t));
            map[b].push_back(make_pair(a, t));
        }

        for(int i = 0; i < n; i++) {
            int fp;
            scanf("%d", &fp);
            firePlace.push_back(fp);
        }

        for(int i = 0; i < m; i++) {
            int fs;
            scanf("%d", &fs);
            fireStation.push_back(fs);
        }

        dijstra(0, dist, fireStation);

        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += dist[firePlace[i]];
        }

        printf("%d\n", ans);
    }

    return 0;
}

void dijstra(int src, vector<int> & dist, vector<int> & fireStation) {
    
    priority_queue<pair<int, int>, vector<pair<int, int> > > pq;

    for(int src : fireStation) {
        dist[src] = 0;
        pq.push(make_pair(0, src));
    }

    while (!pq.empty())
    {
        int current = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if(dist[current] < cost) continue;

        for(int i = 0; i < map[current].size(); i++) {
            int there = map[current][i].first;
            int nextDist = cost + map[current][i].second;
            if(dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }

        }
    }
    
    return ;
}