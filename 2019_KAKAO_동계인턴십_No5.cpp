#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>

// 이분탐색(파라메트릭 서치)

using namespace std;

priority_queue<int, vector<int>, less<int> > pq;
priority_queue<int, vector<int>, greater<int> > ansList;

void clearPq() {
    while (!pq.empty())
    {
        pq.pop();
    }
}

int solution(vector<int> stones, int k) {
    int answer = 0;

    for(int i = 0; i <= stones.size()-k; i++) {

        clearPq();
        for(int j = i; j < i+k; j++) {
            pq.push(stones[j]);
        }

        // cout << "pq.top: " << pq.top() << endl;
        ansList.push(pq.top());
    }

    answer = ansList.top();

    return answer;
}
