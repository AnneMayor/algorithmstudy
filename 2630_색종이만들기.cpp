#include <iostream>

using namespace std;
const int MAX = 130;

int map[MAX][MAX];
int white, blue;

void findWBSquare(int cnt, int x, int y) {
    if(cnt == 0) return ;

    bool isWhite = false, isBlue = false;
    map[x][y] == 1 ? isBlue = true : isWhite = true;
    for(int i = x; i < x + cnt; i++) {
        for(int j = y; j < y + cnt; j++) {
            if(isWhite) {
                if(map[i][j] != 0) isWhite = false;
            } else {
                if(map[i][j] != 1) isBlue = false;
            }
            if(!isWhite && !isBlue) break;
        }
        if(!isWhite && !isBlue) break;
    }

    if(isWhite || isBlue) {
        if(isWhite) white++;
        else blue++;
    } else {
        findWBSquare(cnt/2, x, y);
        findWBSquare(cnt/2, x+cnt/2, y);
        findWBSquare(cnt/2, x, y+cnt/2);
        findWBSquare(cnt/2, x+cnt/2, y+cnt/2);
    }

    return ;
}

int main() {

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    white = 0, blue = 0;

    findWBSquare(n, 0, 0);
    
    printf("%d\n", white);
    printf("%d\n", blue);

    return 0;

}