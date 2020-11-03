#include <iostream>
#include <cstring>
#include <string>

using namespace std;
const int MAX = 100005;

int pi[MAX];

void getPartialMatch(const string & s) {
    memset(pi, 0, sizeof(pi));

    int n = s.length();
    int begin = 1, matched = 0;

    while (begin + matched < n)
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

int maxOverlap(const string & s1, const string & s2) {
    int n = s1.length(), m = s2.length();

    int begin = 0, matched = 0;
    while (begin < n)
    {
        if(matched < m && s1[begin+matched] == s2[matched]) {
            ++matched;
            if(begin+matched == n) return matched;
        } else {
            if(matched == 0) ++begin;
            else {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    
    return 0;
}


int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for(int tc = 1; tc <= T; tc++) {
        string s;
        cin >> s;
        
        string rev = "";
        for(int i = s.length()-1; i >= 0; i--) {
            rev += s[i];
        }
        getPartialMatch(rev);

        int numOfOverlap = maxOverlap(s, rev);
        int ans = s.length() + s.length() - numOfOverlap;
        printf("%d\n", ans);
    } 

    return 0;
}