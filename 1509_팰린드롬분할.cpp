#include <iostream>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;
const int MAX = 2505;

int dp[MAX][MAX];
int dist[MAX];

int main(void) {

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    string s;
    cin >> s;

    int n = s.length();

    // dist = 1
    for(int i = 0; i < n; i++) dp[i][i] = 1;

    // dist = 2
    for(int i = 0; i < n-1; i++) {
        dp[i][i+1] = s[i] == s[i+1];
    }

    // dist = 3
    for(int d = 2; d < n; d++) {
        for(int i = 0; i < n; i++) {
            dp[i][d+i] = dp[i+1][d+i-1] ? s[i] == s[i+d] : 0;
        }
    }

    // 분할 개수 최소 판별하는 문제
    for(int i = 0; i < n; i++) {
        dist[i] = 2147483647;
        for(int j = 0; j <= i; j++) {
            if(dp[j][i]) dist[i] = min(dist[i], dist[j-1] + 1);
        }
    }

    printf("%d\n", dist[n-1]);

    return 0;
}