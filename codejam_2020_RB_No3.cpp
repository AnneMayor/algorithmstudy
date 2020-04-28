#include <bits/stdc++.h>

using namespace std;
const int MAX = 1605;

int now[MAX];
int goal[MAX];

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        memset(now, 0, sizeof(now));
        memset(goal, 0, sizeof(goal));

        vector<pair<int, int> > ans;

        int r, s;
        scanf("%d %d", &r, &s);

        if(r == 2) {
            printf("Case #%d: %d\n", tc, s-1);
            for(int i = 1; i <= s-1; i++) printf("%d 1\n", i*2);
            continue;
        }

        // 현재 s기준 정렬 순서
        for(int i = 1, c = 1; i <= r; i++) {
            for(int j = 1; j <= s; j++) now[c++] = i;
        }

        // 목표 s기준 정렬 순서
        for(int j = 1, c = 1; j <= s; j++) {
            for(int i = 1; i <= r; i++) goal[c++] = i;
        }

        int current = r*s;
        while (true)
        {
            while (current > 0 && now[current] == goal[current]) current--;
            if(current == 0) break;

            int prev = goal[current-1], next = goal[current];
            int x = current;

            while (prev != now[x-1] || next != now[x]) x--;
            ans.push_back(make_pair(current-x, x));

            rotate(now+1, now+x+1, now+current+1);
        }

        int cnt = ans.size();
        printf("Case #%d: %d\n", tc, cnt);
        for(int i = cnt-1; i >= 0; i--) {
            printf("%d %d\n", ans[i].first, ans[i].second);
        }
    }

    return 0;
}