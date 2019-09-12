#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;
const int MAX = 1005;

int map[MAX][MAX];
bool isVisited[MAX];
vector<vector<int> > points;
queue<int> q;

void bfs(int start) {
    
    q.push(start);
    isVisited[start] = true;

    while (!q.empty())
    {
        start = q.front();
        q.pop();

        for(int next : points[start]) {
            if(!isVisited[next]) {
                isVisited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {

    int n, m;
    scanf("%d %d", &n, &m);

    memset(isVisited, false, sizeof(isVisited));
    int ans = 0;
    points.resize(n+1);

    for(int i = 0; i < m; i++) {
        int s, e;
        scanf("%d %d", &s, &e);

        points[s].push_back(e);
        points[e].push_back(s);
    }

    for(int i = 1; i <= n; i++) {
        if(!isVisited[i]) {
            ans++;
            bfs(i);
        }
    }

    printf("%d\n", ans);

    return 0;
}