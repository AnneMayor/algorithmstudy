#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e7;

int left_minimum[MAX];
int right_minimum[MAX];

int solution(vector<int> a) {
    int answer = 0;
    // 1. 좌에서 우로 각 배열 index별 최소값 구하기
    int mn = INT_MAX;
    int idx = 0;
    for(auto num : a) {
        if(mn > num) mn = num;
        left_minimum[idx++] = mn;
    }

    // 2. 우에서 좌로 각 배열 index별 최소값 구하기
    idx = (int)a.size()-1;
    mn = INT_MAX;
    for(int i = (int)a.size()-1; i >= 0; i--) {
        if(mn > a[i]) mn = a[i];
        right_minimum[i] = mn;
    }

    // 3. 각 배열별 풍선 터지는지 유무 판단
    idx = 0;
    for(auto num : a) {
        int mx = max(left_minimum[idx], right_minimum[idx]);
        if(num <= mx) answer++;
        idx++;
    }

    return answer;
}