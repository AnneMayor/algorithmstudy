#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;
const int MAX = 105;

int pi[MAX];

void getPi(string b) {
    memset(pi, 0, sizeof(pi));

    int j = 0;
    for(int i = 1; i < b.length(); i++) {
        while (j > 0 && b[i] != b[j]) // a[i] != b[i] : a문자열, b문자열 i번째 위치에서 불일치
        {
            j = pi[j-1];
        }
        if(b[i] == b[j]) pi[i] = ++j;
    }

    return ;
}

void kmp(string a, string b, vector<int> & answer) {
    int aLen = a.length();
    for(int i = 0; i < aLen; i++) {
        int j = 0;
        while (j > 0 && a[i] != b[j])
        {
            j = pi[j-1];
        }
        if(a[i] == b[j]) {
            if(j == aLen-1) {
                answer.push_back(j);
                j = pi[j];
            } else j++;
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    cin >> a >> b;

    getPi(b);
    
    vector<int> startPoints;
    kmp(a, b, startPoints);

    return 0;
}