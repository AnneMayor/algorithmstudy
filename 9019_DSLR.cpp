#include <iostream>
#include <cstring>
#include <string>
#include <queue>

using namespace std;
const int MAX = 1e5+5;

pair<int, int> before[MAX];
bool isVisited[MAX];
string ans;

int convertToLeft(int n) {

    int r1 = n%10;
    n /= 10;

    int r2 = n%10;
    n /= 10;

    int r3 = n%10;
    n /= 10;

    int r4 = n%10;
    n /= 10;

    int ret = (((r3*10) + r2)*10 + r1)*10 + r4;
    // cout << "ret: " << ret << endl;
    return ret;

}

int convertToRight(int n) {


    int r1 = n%10;
    n /= 10;

    int r2 = n%10;
    n /= 10;

    int r3 = n%10;
    n /= 10;

    int r4 = n%10;
    n /= 10;

    int ret = (((r1*10) + r4)*10 + r3)*10 + r2;
    // cout << "retR: " << ret << endl;
    return ret;

}

void traceNum(int start, int end) {

    while (before[start].second != -1)
    {
        switch (before[start].first)
        {
            case 0:
            ans = 'D' + ans;
            break;
            case 1:
            ans = 'S' + ans;
            break;
            case 2:
            ans = 'L' + ans;
            break;
            case 3:
            ans = 'R' + ans;
            break;
        }

        start = before[start].second;
    }
}

void bfs(int start, int end) {

    queue<int> q;
    before[start] = make_pair(-1, -1);
    isVisited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        start = q.front();
        q.pop();

        if(start == end) {
            traceNum(start, end);
            return ;
        }

        int to[4];
        to[0] = start*2 > 9999? (start*2)%10000 : start*2;
        to[1] = start == 0 ? 9999 : start-1;
        to[2] = convertToLeft(start);
        to[3] = convertToRight(start);

        for(int i = 0; i < 4; i++) {
            if(!isVisited[to[i]]) {
                isVisited[to[i]] = true;
                before[to[i]] = make_pair(i, start);
                q.push(to[i]);
            }
        }
    }

    return ;

}

int main() {

    int T;
    scanf("%d", &T);
    cout.tie(NULL);

    for(int tc = 1; tc <= T; tc++) {
        int a, b;
        scanf("%d %d", &a, &b);
        memset(isVisited, false, sizeof(isVisited));
        ans = "";

        bfs(a, b);

        cout << ans << endl;
    }

    return 0;
}