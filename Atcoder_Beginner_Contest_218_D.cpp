#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    scanf("%d", &n);

    vector<pair<int, int> > points;
    for(int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        points.push_back(make_pair(x, y));
    }

    sort(points.begin(), points.end());

    // for(auto p : points) {
    //     cout << p.first << " / " << p.second << endl;
    // }

    int ans = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(points[i].first < points[j].first && points[i].second < points[j].second) {
                if(binary_search(points.begin(), points.end(), make_pair(points[i].first, points[j].second)) && 
                binary_search(points.begin(), points.end(), make_pair(points[j].first, points[i].second)))
                    ans++;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}