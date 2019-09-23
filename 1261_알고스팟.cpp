#include <iostream>
#include <cstring>
#include <queue>
#include <functional>

using namespace std;
const int MAX = 105;

priority_queue<pair<int, pair<int, int> > , vector<pair<int , pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;
int map[MAX][MAX];
int cntOfStep[MAX][MAX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m;
int ans;

void dijkstra(int x, int y) {
    
    cntOfStep[x][y] = 0;
    pq.push(make_pair(0, make_pair(x, y)));

    while (!pq.empty())
    {
        x = pq.top().second.first;
        y = pq.top().second.second;
        int step = pq.top().first;
        pq.pop();

        if(x == m-1 && y == n-1) {
            ans = step;
            return ;
        }

        if(step > cntOfStep[x][y]) continue;
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nextStep = step;

            if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

            if(map[nx][ny] == 1) {
                nextStep += 1;
            }

            if(cntOfStep[nx][ny] == -1 || cntOfStep[nx][ny] > nextStep) {
                cntOfStep[nx][ny] = nextStep;
                pq.push(make_pair(nextStep, make_pair(nx, ny)));
            }
        }
    }
    
    return ;
}

int main() {

    scanf("%d %d", &n, &m);
    memset(cntOfStep, -1, sizeof(cntOfStep));

    for (int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    ans = 0;
    dijkstra(0, 0);

    // for(int i = 0; i < m; i++) {
    //     for(int j = 0; j < n; j++) {
    //         cout << cntOfStep[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    printf("%d\n", ans);

    return 0;
}