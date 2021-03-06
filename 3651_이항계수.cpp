#include <bits/stdc++.h>

using namespace std;

long long nCk(long long n, int k) {
    double res = n - k + 1;
    for(int i = 2; i <= k; i++) {
        res = res * (n - k + i) / i;
    }
    if(res > pow(10, 16)) return (long long) pow(10, 16);
    return (long long) res;
}

int main(void) {

    long long m;
    scanf("%lld", &m);

    long long right = m;
    vector<pair<long long, long long> > answer;

    for(int k = 1; ; k++) {
        long long left = 2 * k;

        while (left <= right)
        {
            long long mid = (left + right) >> 1;
            long long res = nCk(mid, k);

            if(res == m) {
                if(mid == 2 * k) answer.push_back(make_pair(mid, k));
                else {
                    answer.push_back(make_pair(mid, k));
                    answer.push_back(make_pair(mid, mid-k));
                }
                right = mid;
                break;
            }

            if(res > m) right = mid - 1;
            else left = mid + 1;
        }
        if(right < 2 * k) break;
    }

    sort(answer.begin(), answer.end());
    cout << answer.size() << endl;
    for(auto p : answer) {
        cout << p.first << " " << p.second << endl;
    }

	return 0;
}