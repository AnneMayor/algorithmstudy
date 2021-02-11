#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int getMaxOverlapping(vector<pair<int, int> > ranges) {
    vector<pair<int, char> > data;
    for(auto range : ranges) {
        data.push_back(make_pair(range.first, 'x'));
        data.push_back(make_pair(range.second, 'y'));
    }

    sort(data.begin(), data.end());
    
    int cnt = 0;
    int ans = 0;
    for(auto d : data) {
        if(d.second == 'x') cnt++;
        if(d.second == 'y') cnt--;

        ans = max(ans, cnt);
    }

    return ans;
}

int main(void) {

    vector<pair<int, int> > v;
    v.clear();
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        v.push_back(make_pair(x, y));
    }
    
    printf("%d\n", getMaxOverlapping(v));

    return 0;
}