#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <functional>

using namespace std;
const int MAX = 30;

set<string, greater<string> > keys;
char str[MAX];
int n, k;

int convertToNum(string s) {
    int ret = 0;
    int len = s.length();
    int start = 1;
    for(int i = len-1; i >= 0; i--) {
        if(s[i] >= '0' && s[i] <= '9') {
            ret += (s[i]-'0') * start;
        } else {
            ret += (s[i]-'A'+10) * start;
        }
        start *= 16;
    }

    return ret;
}

void getNums(string s) {

    int len = s.length();
    int cnt = n / 4;

    for(int i = 0; i <= len-cnt; i+=cnt) {
        string tmp = s.substr(i, cnt);
        keys.insert(tmp);
    }

    return ;
}

int main()
{
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++)
    {
        scanf("%d %d", &n, &k);

        scanf("%s", str);
        keys.clear();

        string s = "";
        int len = strlen(str);
        for(int i = 0; i < len; i++) {
            s += str[i];
        }

        getNums(s);

        for(int i = 1; i < n/4; i++) {
            char c = s[0];
            s = s.substr(1);
            s += c;
            getNums(s);
        }

        int idx = 1;
        string ans = "";
        set<string>::iterator it;
        for(auto it = keys.begin(); it != keys.end(); it++) {
            if(idx == k) {
                ans = *it;
                break;
            }
            idx++;
        }

        int ansNum = convertToNum(ans);

        printf("#%d %d\n", tc, ansNum);
    }

    return 0;
}