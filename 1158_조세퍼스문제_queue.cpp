#include <iostream>
#include <queue>

using namespace std;
queue<int> q;

int main() {

    int n, k;
    scanf("%d %d", &n, &k);

    for(int i = 1; i <= n; i++) {
        q.push(i);
    }

    printf("<");
    for(int i = 0; i < n-1; i++) {
        for(int i = 0; i < k-1; i++) {
            int tmp = q.front();
            q.push(tmp);
            q.pop();
        }

        printf("%d, ", q.front());
        q.pop();
    }
    printf("%d>", q.front());
    q.pop();
    

    return 0;
}