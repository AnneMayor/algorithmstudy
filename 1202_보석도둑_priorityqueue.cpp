#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
const int MAX = 300005;

priority_queue<int , vector<int> > pq;
vector<pair<int, int> > jewelry;
vector<int> bags;

int main() {

    int n, k;
    scanf("%d %d", &n, &k);

    jewelry.clear();
    bags.clear();

    for(int i = 0; i < n; i++) {
        int height, value;
        scanf("%d %d", &height, &value);

        pair<int, int> p;
        p.first = height;
        p.second = value;

        jewelry.push_back(p);
    }

    for(int i = 0; i < k; i++) {
        int height;
        scanf("%d", &height);

        bags.push_back(height);
    }

    sort(jewelry.begin(), jewelry.end());
    sort(bags.begin(), bags.end());

    long long ans = 0;
    for(int i = 0, j = 0; i < k; i++) {
        while (j < n && jewelry[j].first <= bags[i])
        {
            pq.push(jewelry[j++].second);
        }

        if(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        
    }

    printf("%lld\n", ans);

    return 0;
}