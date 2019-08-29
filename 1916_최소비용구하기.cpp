#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
const int MAX = 1005;

int buses[MAX][MAX];
int dist[MAX];
int n, m, idxStart, idxEnd;

priority_queue<pair<int, int> > pq; // first : 위치 인덱스 , second: 거리

void dijkstra(int start) {
    dist[start] = 0;
    pq.push(make_pair(-dist[start], start));

    while (!pq.empty())
    {
        int here = pq.top().second;
        int hereDist = -pq.top().first;
        pq.pop();

        if(hereDist > dist[here]) continue;

        for(int i = 1; i <= n; i++) {
            int there, thereDist;
            if(buses[here][i] != -1) {
                there = i;
                thereDist = buses[here][i]+hereDist;
                if(dist[there] == -1 || dist[there] > thereDist) {
                    dist[there] = thereDist;
                    pq.push(make_pair(-thereDist, there));
                }
            }
        }
    }
    
}

int main() {

    scanf("%d", &n);
    scanf("%d", &m);

    memset(buses, -1, sizeof(buses));
    memset(dist, -1, sizeof(dist));

    for(int i = 1; i <= m; i++) {
        int start, end, value;
        scanf("%d %d %d", &start, &end, &value);
        if(buses[start][end] > -1) {
            buses[start][end] = min(buses[start][end], value);
        } else {
            buses[start][end] = value;
        }
    }

    scanf("%d %d", &idxStart, &idxEnd);

    dijkstra(idxStart);

    printf("%d\n", dist[idxEnd]);

    return 0;
}