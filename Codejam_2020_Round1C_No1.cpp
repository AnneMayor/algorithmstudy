#include <bits/stdc++.h>

using namespace std;
const int MAX = 10005;

string directions;

int main() {

    ios::sync_with_stdio(false);

    cin.tie(NULL);
    int T;
    cin >> T;

    for(int tc = 1; tc <= T; tc++) {
        int x, y;
        cin >> x >> y >> directions;

        int len = directions.length();

        int ans = 0;
        int time = 0;
        int dist = 0;
        for(int i = 0; i < len; i++) {
            time++;
            switch (directions[i])
            {
            case 'E':
            x += 1;
                break;

            case 'W':
            x -= 1;
                break;

            case 'S':
            y -= 1;
                break;

            case 'N':
            y += 1;
                break;
            }

            dist = abs(x) + abs(y);
            if(time >= dist) {
                ans = time;
                break;
            }
        }

        if(time >= dist) {
            ans = time;
            printf("Case #%d: %d\n", tc, ans);
        } else {
            printf("Case #%d: IMPOSSIBLE\n", tc);
        }
    }


    return 0;
}