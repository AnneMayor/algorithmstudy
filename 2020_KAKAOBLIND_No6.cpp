#include <bits/stdc++.h>

using namespace std;
int answer;
vector<int> injected_idx;
bool isVisited[20];

bool isAllChecked(int len) {
    bool result = true;
    for(int i = 0; i < len; i++) {
        if(!isVisited[i]) {
            result = false;
            break;
        }
    }
    return result;
}

void findAns(int cur, int n, vector<int> & weak, vector<int> & dist) {

    if(isAllChecked(weak.size())) {
        answer = min(answer, cur);
        return ;
    }

    if(cur == dist.size()) return ;

    for(int i = 0; i < (int) weak.size(); i++) {
        if(!isVisited[i]) {
            int cnt = 0;
            for(int j = 0; j < weak.size(); j++) {
                if(isVisited[j]) continue;
                int distance = weak[j] - weak[i];
                if(distance < 0) distance += n;
                if(dist[cur] >= distance) {
                    cnt++;
                    isVisited[j] = true;
                    injected_idx.push_back(j);
                }
            }
            findAns(cur+1, n, weak, dist);
            while(cnt--)
            {
                isVisited[injected_idx.back()] = false;
                injected_idx.pop_back();
            }
        }
    }

    return ;
}

int solution(int n, vector<int> weak, vector<int> dist) {
    answer = 1e9;

    sort(dist.begin(), dist.end(), greater<>());
    memset(isVisited, false, sizeof(isVisited));

    findAns(0, n, weak, dist);

    if(answer == 1e9) answer = -1;

    return answer;
}