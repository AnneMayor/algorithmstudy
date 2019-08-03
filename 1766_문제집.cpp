#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <functional>

using namespace std;
const int MAX = 32100;

// 위상정렬 연습하는 문제!
// 위상정렬방식에 대해서도 잘 알고 있도록 하자!

vector<int> map[MAX];
priority_queue<int, vector<int>, greater<int> > pq;
int checkNums[MAX];

int main() {

    memset(checkNums, 0, sizeof(checkNums));

    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        map[a].push_back(b);
        checkNums[b]++;
    }

    for(int i = 1; i <= n; i++) {
        if(checkNums[i] == 0) {
            pq.push(i);
        }
    }

    while (!pq.empty())
    {
        int num = pq.top();
        printf("%d ", num);
        pq.pop();
        for(int i = 0; i < map[num].size(); i++) {
            int there = map[num][i];
            // cout << "there: " << there << endl;
            checkNums[there]--;
            if(checkNums[there] == 0) {
                pq.push(there);
            }
        }
    }
    

    return 0;
}