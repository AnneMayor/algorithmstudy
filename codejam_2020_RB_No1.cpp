#include <bits/stdc++.h>

using namespace std;

string getDeterministicAns() {
    int x, y;
    scanf("%d %d", &x, &y);

    string ret = "";
    while (x || y)
    {
        if((x^y)&1) {
            if(x == 1 && y == 0) {ret += 'E'; x = 0;}
            else if(x == -1 && y == 0) {ret += 'W'; x = 0;}
            else if(y == 1 && x == 0) {ret += 'N'; y = 0;}
            else if(y == -1 && x == 0) {ret += 'S'; y = 0;}
            else if(x&1) {
                if(((x-1)^y)&2) {ret += 'E'; --x;}
                else {ret += 'W'; ++x;}
            } else {
                if((x^(y-1))&2) {ret += 'N'; --y;}
                else {ret += 'S'; ++y;}
            }
            x >>= 1;
            y >>= 1;
        } else
        {
            return "IMPOSSIBLE";
        }
    }

    return ret;
}

int main() {

    ios_base::sync_with_stdio(false);
    cout.tie(NULL);

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        cout << "Case #" << tc << ": " << getDeterministicAns() << endl;
    }

    return 0;
}