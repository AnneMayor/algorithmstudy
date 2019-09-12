#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX = 1005;

vector<vector<int> > pointList;
vector<int> ansList;
queue<int> q;
int n, m, v;
bool isVisited[MAX];

void dfs(int start, int cnt) {

    isVisited[start] = true;
    ansList.push_back(start);

    if(cnt >= n) {
        return ;
    }

    for(int next : pointList[start]) {
        if(!isVisited[next]) {
            isVisited[next] = true;
            dfs(next, cnt+1);
        }
    }

    return ;
}

void bfs(int start) {
    
    isVisited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        start = q.front();
        ansList.push_back(start);
        q.pop();
        isVisited[start] = true;

        for(int next : pointList[start]) {
            if(!isVisited[next]) {
                isVisited[next] = true;
                q.push(next);
            }
        }
    }

    return ;
    
}

int main() {

    scanf("%d %d %d", &n, &m, &v);

    pointList.resize(n+1);

    for(int i = 0; i < m; i++) {
        int s, e;
        scanf("%d %d", &s, &e);
        pointList[s].push_back(e);
        pointList[e].push_back(s);
    }

    for(int i = 0; i < n+1; i++) {
        if(pointList[i].size()) {
            sort(pointList[i].begin(), pointList[i].end());
        }
    }

    ansList.clear();
    memset(isVisited, false, sizeof(isVisited));
    dfs(v, 1);
    for(int i = 0; i < ansList.size(); i++) {
        printf("%d ", ansList[i]);
    }
    printf("\n");
    
    ansList.clear();
    memset(isVisited, false, sizeof(isVisited));
    bfs(v);
    for(int i = 0; i < ansList.size(); i++) {
        printf("%d ", ansList[i]);
    }
    printf("\n");

    return 0;
}