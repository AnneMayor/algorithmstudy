#include <iostream>
#include <queue>

using namespace std;

priority_queue<long long, vector<long long>, greater<long long> > pq;

int main() {

    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++) {
        int numOfCard;
        scanf("%d", &numOfCard);
        pq.push(numOfCard);
    }

    for(int i = 0; i < m; i++) {
        long long c1 = pq.top();
        pq.pop();
        long long c2 = pq.top();
        pq.pop();
        pq.push(c1+c2);
        pq.push(c1+c2);
    }

    long long ans = 0;
    for(int i = 0; i < n; i++) {
        ans += pq.top();
        pq.pop();
    }

    printf("%lld\n", ans);

    return 0;
}