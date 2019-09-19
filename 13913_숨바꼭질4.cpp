#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;
const int MAX = 1e5+5;

int isChecked[MAX];
bool isVisited[MAX];
queue<int> q;
int ans;
vector<int> ansList;
vector<int> tmp;

void dfs(int start, int step, int end) {

    tmp.push_back(start);
    isVisited[start] = true;

    if(step > ans) return;

    if(start == end) {
        if(ansList.size() > 0) return ;
        for(int i = 0; i < tmp.size(); i++) {
            ansList.push_back(tmp[i]);
        }
        return ;
    }

    if(start-1 >= 0 && !isVisited[start-1] && isChecked[start-1] == step+1) {
        dfs(start-1, step+1, end);
        tmp.pop_back();
    }

    if(start+1 <= 100000 && !isVisited[start+1] && isChecked[start+1] == step+1) {
        dfs(start+1, step+1, end);
        tmp.pop_back();
    }

    if(start*2 <= 100000 && !isVisited[start*2] && isChecked[start*2] == step+1) {
        dfs(start*2, step+1, end);
        tmp.pop_back();
    }

    return ;
}

void bfs(int start, int cnt, int end) {
    isChecked[start] = cnt;
    q.push(start);

    while (!q.empty())
    {
        start = q.front();
        cnt = isChecked[start];
        q.pop();

        if(start == end) {
            if(ans > cnt) ans = cnt;
            return ;
        }

        if(start+1 <= 100000 && isChecked[start+1] == -1) {
            isChecked[start+1] = cnt+1;
            q.push(start+1);
        }

        if(start-1 >= 0 && isChecked[start-1] == -1) {
            isChecked[start-1] = cnt+1;
            q.push(start-1);
        }

        if(start*2 <= 100000 && isChecked[start*2] == -1) {
            isChecked[start*2] = cnt+1;
            q.push(start*2);
        }
    }
    
    return ;
}

int main() {

    int n, m;
    scanf("%d %d", &n, &m);
    memset(isChecked, -1, sizeof(isChecked));
    memset(isVisited, false, sizeof(isVisited));
    tmp.clear();
    ansList.clear();

    ans = 1e9;
    bfs(n, 0, m);

    printf("%d\n", ans);

    dfs(n, 0, m);

    for(int i = 0; i < ansList.size(); i++) {
        printf("%d ", ansList[i]);
    }
    printf("\n");

    return 0;
}