#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> numOfThree;
    while (n/3 > 0)
    {
        numOfThree.push_back(n%3);
        n /= 3;
    }
    numOfThree.push_back(n);

    int len = (int) numOfThree.size();
    int cnt = 0;
    for(int i = len-1; i >= 0; i--) {
        answer += numOfThree[i] * pow(3, cnt++);
    }
    
    return answer;
}