#include <bits/stdc++.h>

using namespace std;

const int MAX = 20000;

bool checked[MAX];

long long gcd(long long a, long long b)
{
    while (a && b)
        if (a > b) a %= b; else b %= a;
    return a + b;
}

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int n, d;
        scanf("%d %d", &n, &d);

        vector<long long> numList;
        for(int i = 0; i < n; i++) {
            long long num; scanf("%lld", &num);
            numList.push_back(num);
        }

        sort(numList.begin(), numList.end());
        map<pair<long long, long long>, vector<pair<int, int> > > cnt;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= d; ++j) {
                long long g = gcd(numList[i], j);
                cnt[make_pair(numList[i]/g, j/g)].push_back(make_pair(j, i));
            }
        }

        int ans = 1e9;

        for(auto & q: cnt) {
            auto & s = q.first;
            auto & cur = q.second;
            sort(begin(cur), end(cur));

            int res = 0, left = d;
            for(auto & r : cur) {
                checked[r.second] = true;
                if(left >= r.first) {
                    res += r.first-1;
                    left -= r.first;
                } else {
                    res += left;
                    left = 0;
                    break;
                }
            }

            // 여기 로직부분은 좀 더 이해가 필요한 것으로 보임,,,
            if(left > 0) {
                for(int i = n-1; i >= 0; i--) {
                    if(!checked[i]) {
                        long long tmp = (s.second*numList[i]) / s.first;
                        if(tmp == 0) break;
                        res += min(tmp, (long long)left);
                        left -= min(tmp, (long long)left);
                        if(left == 0) break;
                    }
                }
            }

            for(auto & r : cur) {
                checked[r.second] = false;
            }

            if(left == 0) {
                ans = min(ans, res);
            }
        }

        printf("Case #%d: %d\n", tc, ans);
    }

    return 0;
}