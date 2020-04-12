#include <bits/stdc++.h>

#define pii pair<int, int>
#define x first
#define y second

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for(int tc = 1; tc <= T; tc++) {
        int n;
        cin >> n;

        vector<pii> points;
        int zigzagDirection = 0;
        for(int i = 0; ;i++) {
            if(n >= (1LL << i)) continue;
            n -= i;
            for(int j = i; j >= 1; j--) {
                if(n >= (1LL << (j-1)) - 1) {
                    if(zigzagDirection) {
                        for(int k = j; k >= 1; k--) points.push_back(make_pair(j, k));
                    } else {
                        for(int k = 1; k <= j; k++) points.push_back(make_pair(j, k));
                    }
                    zigzagDirection = !zigzagDirection;
                    n -= (1LL << (j-1)) - 1;
                } else {
                    points.push_back(make_pair(j, zigzagDirection? j: 1));
                }
            }
            reverse(points.begin(), points.end());
            // * killing point!! * //
            while (n--) points.push_back(make_pair(++i, 1));
            break;
        }
        
        cout << "Case #" << tc << ": " << endl;
        for(auto & point : points) {
            cout << point.x << " " << point.y << endl;
        }
    }

    return 0;
}