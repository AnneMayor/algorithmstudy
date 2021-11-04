#include <iostream>

using namespace std;

int main(void) {

    int n, m;
    scanf("%d %d", &n, &m);

    int map[n+1][m+1];

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int val;
            scanf("%d", &val);
            map[i][j] = val;
        }
    }

    int isPartOfA = true;

    // 열검사
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < m; j++) {
            int diff = map[i][j+1] - map[i][j];
            if(diff != 1) {
                isPartOfA = false;
                break;
            }
        }

        if(!isPartOfA) break;
    }

    // 행검사
    for(int j = 1; j <= m; j++) {
        for(int i = 1; i < n; i++) {
            int diff = map[i+1][j] - map[i][j];
            if(diff != 7) {
                isPartOfA = false;
                break;
            }
        }

        if(!isPartOfA) break;
    }

    if(m > 1) {
        int supR = 8 - m;
        int r = map[1][1] % 7;
        if(!(1 <= r && r <= supR)) isPartOfA = false; 
    }

    if(isPartOfA) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    
    return 0;
}