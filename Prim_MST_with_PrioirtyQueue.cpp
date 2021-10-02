#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 100;

vector<pair<int, int> > cost[MAX];
int isVisited[MAX];

int main(void) {

    priority_queue<pair<int, int> > pq;

    memset(isVisited, 0, sizeof(isVisited));
    int ans = 0;

    // 시작점: 1
    for(int i = 0; i < cost[1].size(); i++) {
        int next = cost[1][i].first;
        int distance = cost[1][i].second;

        pq.push(make_pair(-distance, next));
    }

    isVisited[1] = 1;
    while (!pq.empty())
    {
        pair<int, int> current = pq.top();
        pq.pop();

        int v = current.second;
        int e = -current.first;

        if(!isVisited[v]) {
            isVisited[v] = 1;
            ans += e;

            for(int i = 0; i < cost[v].size(); i++) {
                pair<int, int> next = cost[v][i];
                int nv = next.second;
                int ne = -next.first;

                if(!isVisited[nv]) {
                    pq.push(make_pair(ne, nv));
                }
            }
        }
    }

    return 0;
}