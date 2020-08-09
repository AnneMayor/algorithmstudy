#include <bits/stdc++.h>

using namespace std;

const int MAX = 2*1e5+5;

long long a[MAX];
long long b[MAX];

int main() {

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    set<long long> s;
    for(int i = 0; i < n; i++) {
        s.insert(i);
    }

    vector<long long> sCnt(n);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
        b[i]--;
        if(b[i] == -2) continue;
        sCnt[b[i]]++;
        if(sCnt[b[i]] == 1) s.erase(b[i]);
    }

    long long sum = 0;
    vector<int> ans[2];
    while (!s.empty())
    {
        int v = *s.begin();
        s.erase(s.begin());
        int w = b[v];
        sum += a[v];

        if(a[v] > 0) {
            if(w >= 0) {
                a[w] += a[v];
            }
            ans[0].push_back(v);
        } else ans[1].push_back(v);

        if(w >= 0) {
            sCnt[w]--;
            if(sCnt[w] == 0) s.insert(w);
        }
    }
    
    printf("%lld\n", sum);
    for (int to : ans[0]) printf("%d ", to+1);
    
    reverse(ans[1].begin(), ans[1].end());
    
    for (int to : ans[1]) printf("%d ", to+1);
    printf("\n");

    return 0;
}