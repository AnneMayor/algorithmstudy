#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int MAX = 2*1e5;

int a[MAX];
int g[MAX];
int p[MAX];
int h[MAX];
vector<int> graph[MAX];

bool access;

void dfs(int start, int ancestor = -1) {

    a[start] = p[start];
    int sum_g = 0;
    for(int s : graph[start]) {
        if(s == ancestor) continue;
        dfs(s, start);
        sum_g += g[s];
        a[start] += a[s];
    }

    if((a[start] + h[start]) %2 != 0) {access = false;}
    g[start] = (a[start] + h[start]) / 2;
    if(g[start] < 0 || g[start] > a[start]) {access = false;}
    if(sum_g > g[start]) {access = false;}
    
    // if ((a[start] + h[start]) % 2 == 0) {} // first
    // else access = false;
    // g[start] = (a[start] + h[start]) / 2;
    // if (g[start] >= 0 && g[start] <= a[start]) {} // second
    // else access = false;
    // if (sum_g <= g[start]) {} // third
    // else access = false;

    return ;

}

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int n, m;
        scanf("%d %d", &n, &m);

        memset(g, 0, sizeof(g));
        memset(a, 0, sizeof(a));

        access = true;
        for(int i = 0; i < n; i++) {
            graph[i].clear();
        }

        for(int i = 0; i < n; i++) {
            scanf("%d", &p[i]);
        }

        for(int i = 0; i < n; i++) {
            scanf("%d", &h[i]);
        }

        for(int i = 1; i < n; i++) {
            int p1, p2;
            scanf("%d %d", &p1, &p2);
            p1--, p2--;
            graph[p1].push_back(p2);
            graph[p2].push_back(p1);
        }

        dfs(0);

        if(access) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
        
    }

    return 0;
}