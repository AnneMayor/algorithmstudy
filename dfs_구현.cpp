#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
const int MAX = 1005;

int n, m;
vector<int> vertex[MAX];
bool isVisited[MAX];

void dfs(int x) {
    isVisited[x] = true;

    printf("%d ", x);

    for(int i = 0; i < vertex[x].size(); i++) {
        int y = vertex[x][i];
        if(!isVisited[y]) {
            dfs(y);
        }
    }

}

int main() {

    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        vertex[a].push_back(b);
        vertex[b].push_back(a);
    }

    memset(isVisited, false, sizeof(isVisited));

    // 0번 정점을 시작으로 할 때
    dfs(0);

    printf("\n");
    return 0;
}