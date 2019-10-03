#include <iostream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;
const int MAX = 60;

int cntOfAlpha[MAX];

bool equalsWhenOneCharRemoved(string x, string y) {
    bool ret = true;

    int xLen = x.length();
    for(int i = 0; i < xLen; i++) {
        cntOfAlpha[x[i]-'A']++;
    }

    int yLen = y.length();
    for(int i = 0; i < yLen; i++) {
        cntOfAlpha[y[i]-'A']--;  
    }

    int cnt = 0;
    for(int i = 0; i < MAX; i++) {
        cnt += abs(cntOfAlpha[i]);
    }

    if(cnt > 1) ret = false;

    return ret;
}

int main() {

    memset(cntOfAlpha, 0, sizeof(cntOfAlpha));

    cin.tie(NULL);
    string s1, s2;
    cin >> s1 >> s2;

    printf("%d\n", equalsWhenOneCharRemoved(s1, s2));

    return 0;
}