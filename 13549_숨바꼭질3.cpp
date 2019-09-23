#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
const int MAX = 1e5+5;

int isVisited[MAX];
int ansTime;
queue<int> q;

void bfs(int start, int end) {
    isVisited[start] = 0;
    q.push(start);

    while (!q.empty())
    {
        start = q.front();
        q.pop();

        if(start == end) {
            ansTime = isVisited[start];
            return ;
        }

        if(start-1 >= 0) {
            if(isVisited[start-1] == -1) {
                isVisited[start-1] = isVisited[start]+1;
                q.push(start-1);
            } else {
                isVisited[start-1] = min(isVisited[start-1], isVisited[start]+1);
            }
        }

        if(start+1 <= 1e5 && isVisited[start+1] == -1) {
            if(isVisited[start+1] == -1) {
                isVisited[start+1] = isVisited[start]+1;
                q.push(start+1);
            } else {
                isVisited[start+1] = min(isVisited[start+1], isVisited[start]+1);
            }
        }

        if(start*2 <= 1e5) {
            if(isVisited[start*2] == -1) {
                isVisited[start*2] = isVisited[start];
                q.push(start*2);
            } else {
                isVisited[start*2] = min(isVisited[start*2], isVisited[start]);
            }
        }
    }
    
    return ;
}

int main() {

    int n, k;
    scanf("%d %d", &n, &k);
    memset(isVisited, -1, sizeof(isVisited));

    ansTime = 0;
    bfs(n, k);

    printf("%d\n", ansTime);
    
    return 0;
}