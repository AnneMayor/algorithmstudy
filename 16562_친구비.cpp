#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 1e4+5;

int parent[MAX];
vector<pair<int, int> > expenses;
int ans;

// union-find 문제

int find(int u) {
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

bool merge(int u, int v) {
    u = find(u);
    v = find(v);
    if(u == v) return false;
    parent[u] = v;
    return true;
}

int main() {

    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    for(int i = 1; i <= n; i++) {
        int exp;
        scanf("%d", &exp);
        expenses.push_back(make_pair(exp, i));
        parent[i] = i;
    }

    sort(expenses.begin(), expenses.end());

    // parent 세팅
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        merge(a, b);
    }

    ans = 0;

    for(int u = 0; u < n; u++) {
        if(merge(0, expenses[u].second)) {
            ans += expenses[u].first;
        }
    }

    if(k < ans) printf("Oh no\n");
    else printf("%d\n", ans);

    return 0;
}