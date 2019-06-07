#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX = 10005;

vector<pair<int, int> > assignment;
bool isChecked[MAX];

int main() {

    int n;
    scanf("%d", &n);

    int lastDay = 0;
    int ans = 0;

    memset(isChecked, false, sizeof(isChecked));

    for(int i = 0; i < n; i++) {
        int d, w;
        scanf("%d %d", &d, &w);
        assignment.push_back(make_pair(w, d));
        lastDay = max(lastDay, d);
    }

    sort(assignment.begin(), assignment.end(), greater<pair<int, int> >());

    while(lastDay >= 1) {
        for(int j = 0; j < n; j++) {
            if(!isChecked[j] && assignment[j].second >= lastDay) {
                isChecked[j] = true;
                ans += assignment[j].first;
                break;
            }
        }
        lastDay--;
    }

    printf("%d\n", ans);

    return 0;
}