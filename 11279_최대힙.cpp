#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, less<int> > pq;

int main() {

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int cmd;
        scanf("%d", &cmd);

        if(!cmd) {
            if(pq.empty()) {
                printf("0\n");
            } else {
                printf("%d\n", pq.top());
                pq.pop();
            }
        } else {
            pq.push(cmd);
        }
    }


    return 0;
}