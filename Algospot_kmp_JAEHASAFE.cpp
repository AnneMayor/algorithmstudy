#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

const int MAX = 10005;

int pi[MAX];

void getPartialMatch(const string & s) {
    memset(pi, 0, sizeof(pi));
    int m = s.length();
    int begin = 1, matched = 0;
    while (begin+matched < m)
    {
        if(s[begin+matched] == s[matched]) {
            ++matched;
            pi[begin+matched-1] = matched;
        } else {
            if(matched == 0) begin++;
            else {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }

    return ;
}

vector<int> kmpSearch(const string &s1, const string &s2) {
    int n = s1.length(), m = s2.length();

    vector<int> result;
    getPartialMatch(s2);
    
    int begin = 0, matched = 0;
    while (begin <= n - m)
    {
        if(matched < m && s1[begin+matched] == s2[matched]) {
            matched++;
            if(matched == m) result.push_back(begin);
        } else {
            if(matched == 0) ++begin;
            else {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }

    return result;
}

int shift(const string & s1, const string & s2) {
    return kmpSearch(s1+s1, s2)[0];
}


int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for(int tc = 1; tc <= T; tc++) {
        int ans = 0;
        int cnt;
        cin >> cnt;
        string st;
        vector<string> dial;
        for(int i = 0; i <= cnt; i++) {
            cin >> st;
            dial.push_back(st);
        }

        for(int i = 0; i < cnt; i++) {
            int clockwise = i % 2;
            if(clockwise) {
                // 시계방향
                ans += shift(dial[i], dial[i+1]);
            } else {
                // 반시계방향
                ans += shift(dial[i+1], dial[i]);
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}