#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <map>

using namespace std;
const int MAX = 105;

int cntOfTeam[MAX];
int cntOfDistance[MAX];

vector<vector<int> > candidate;
map<int, vector<int> > ans;
vector<int> ansList;
queue<int> q;

void dfs(int idx, int cnt) {
    for(int next : candidate[idx]) {
        if(cntOfTeam[next] == 0) {
            cntOfTeam[next] = cnt;
            dfs(next, cnt);
        }
    }

    return ;
}

void bfs(int start) {

    cntOfDistance[start] = 0;

    q.push(start);

    while (!q.empty())
    {
        start = q.front();
        q.pop();

        for(int n : candidate[start]) {
            if(cntOfDistance[n] == -1) {
                cntOfDistance[n] = cntOfDistance[start] + 1;
                q.push(n);
            }
        }
    }
    
}

int main() {

    int n, m;
    scanf("%d %d", &n, &m);

    candidate.resize(n+5);

    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        candidate[a].push_back(b);
        candidate[b].push_back(a);
    }

    memset(cntOfTeam, 0, sizeof(cntOfTeam));

    int numOfTeam = 0;
    for(int i = 1; i <= n; i++) {
        if(cntOfTeam[i] == 0) {
            numOfTeam++;
            cntOfTeam[i] = numOfTeam;
            dfs(i, numOfTeam);
        }
    }

    for(int i = 1; i <= n; i++) {
        ans[cntOfTeam[i]].push_back(i);
    }

    printf("%d\n", numOfTeam);

    for(int i = 1; i <= numOfTeam; i++) {
        int miVal = 1e9;
        int ansIdx = -1;
        for(int p : ans[i]) {
            memset(cntOfDistance, -1, sizeof(cntOfDistance));

            bfs(p);

            int tmp = 0;
            for(int i = 1; i <= n; i++) {
                tmp = max(tmp, cntOfDistance[i]);
            }

            if(miVal > tmp) {
                miVal = tmp;
                ansIdx = p;
            }
        }

        ansList.push_back(ansIdx);
    }

    sort(ansList.begin(), ansList.end());

    for(int a : ansList) {
        printf("%d\n", a);
    }

    return 0;
}