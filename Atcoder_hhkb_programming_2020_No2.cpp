#include <bits/stdc++.h>

using namespace std;
const int MAX = 105;

char board[MAX][MAX];

int main(void) {

    int r, c;
    scanf("%d %d", &r, &c);

    for(int i = 0; i < r; i++) {
        scanf("%s", board[i]);
    }

    int ans = 0;
    // 1. horizontal 검사
    for(int i = 0; i < r; i++) {
        int space = 0;
        for(int j = 0; j < c; j++) {
            if(board[i][j] == '.') {
                space++;
            } else {
                if(space >= 2) ans += space-1;
                space = 0;
            }
        }
        if(space >= 2) ans += space-1;
    }

    // 2. vertical 검사
    for(int i = 0; i < c; i++) {
        int space = 0;
        for(int j = 0; j < r; j++) {
            if(board[j][i] == '.') {
                space++;
            } else {
                if(space >= 2) ans += space-1;
                space = 0;
            }
        }
        if(space >= 2) ans += space-1;
    }
    
    printf("%d\n", ans);
    
    return 0;
}