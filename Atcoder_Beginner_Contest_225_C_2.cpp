#include <iostream>
#include <deque>

using namespace std;

int main(void) {

    int n, m;
    scanf("%d %d", &n, &m);

    int x[n+1][m+1];
    int y[n+1][m+1];

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int val;
            scanf("%d", &val);
            
            x[i][j] = (val+6)/7;
            y[i][j] = (val-1)%7 + 1;
        }
    }

    bool isPartA = true;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(i < n && x[i+1][j] != x[i][j] + 1) isPartA = false;
            if(j < m && x[i][j+1] != x[i][j]) isPartA = false;
            if(i < n && y[i+1][j] != y[i][j]) isPartA = false;
            if(j < m && y[i][j+1] != y[i][j]+1) isPartA = false;
        }
    }

    if(isPartA) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}