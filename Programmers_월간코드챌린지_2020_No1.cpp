#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e4+5;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    bool isChecked[MAX];
    memset(isChecked, false, sizeof(isChecked));
    
    int n = (int) numbers.size();
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            int total = numbers[i] + numbers[j];
            if(!isChecked[total]) {
                isChecked[total] = true;
                answer.push_back(total);
            }
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}