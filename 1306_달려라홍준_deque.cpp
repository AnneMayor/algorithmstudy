#include <bits/stdc++.h>

using namespace std;

deque<pair<int, int> > dq;

int main(void) {

    int n, m;
    scanf("%d %d", &n, &m);

    int lightValue[n+5];
    for(int i = 0; i < n; i++) {
        scanf("%d", &lightValue[i]);
    }

    for(int i = 0; i < 2*m-1; i++) {
        while (!dq.empty() && dq.back().first <= lightValue[i])
        {
            dq.pop_back();
        }
        dq.push_back(make_pair(lightValue[i], i));
    }

    for(int i = m-1; i <= n-m; i++) {
        if (dq.front().second < i-(m-1)) {
            dq.pop_front();
        }
        
        printf("%d ", dq.front().first);

        while (!dq.empty() && dq.back().first <= lightValue[i+m])
        {
            dq.pop_back();
        }
        dq.push_back(make_pair(lightValue[i+m], i+m));
    }

    printf("\n");

    return 0;
}