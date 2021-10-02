#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int main(void) {

    int n, m;
    scanf("%d %d", &n, &m);
    int ans = 0;
    int maxValue = -1;

    vector<vector<pair<int, int> > > graphs(n+1);
    int isVisited[n+1];

    memset(isVisited, 0, sizeof(isVisited));

    for(int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        graphs[a].push_back(make_pair(b, c));
        graphs[b].push_back(make_pair(a, c));
    }

    priority_queue<pair<int, int> > pq;

    // 시작점: 1
    for(auto p : graphs[1]) {
        int next = p.first, weight = p.second;
        pq.push(make_pair(-weight, next));
    }

    isVisited[1] = 1;
    while (!pq.empty())
    {
        pair<int, int> current = pq.top();
        pq.pop();

        int currentPoint = current.second;
        int dist = -current.first;

        if(!isVisited[currentPoint]) {
            isVisited[currentPoint] = 1;
            ans += dist;
            maxValue = max(maxValue, dist);

            for(int i = 0; i < graphs[currentPoint].size(); i++) {
                int next = graphs[currentPoint][i].first, nextDist = -graphs[currentPoint][i].second;
                if(!isVisited[next]) {
                    pq.push(make_pair(nextDist, next));
                }
            }

        }
    }

    printf("%d\n", ans-maxValue);

    return 0;
}