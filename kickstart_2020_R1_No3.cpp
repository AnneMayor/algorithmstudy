#include <iostream>
#include <queue>

using namespace std;
const int MAX = 1e5+5;

// Only passed in Test set 1

priority_queue<int, vector<int>, less<int> > pq;

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int n, k;
        scanf("%d %d", &n, &k);
        while (!pq.empty())
        {
            pq.pop();
        }
        
        int minOfExcercise[MAX];
        for(int i = 0; i < n; i++) {
            int min;
            scanf("%d", &min);
            minOfExcercise[i] = min;
        }

        for(int i = 0; i < n-1; i++) {
            int diff = minOfExcercise[i+1] - minOfExcercise[i];
            pq.push(diff);
        }

        int cntOfAdded = 0;
        int ans = 0;
        while (cntOfAdded < k && pq.top() > 1)
        {
            int greaterDifficulty = pq.top();
            pq.pop();
            int divide1 = greaterDifficulty / 2;
            int divide2 = greaterDifficulty - divide1;
            pq.push(divide1);
            pq.push(divide2);
            cntOfAdded++;
        }

        ans = pq.top();

        printf("Case #%d: %d\n", tc, ans);

    }

    return 0;
}