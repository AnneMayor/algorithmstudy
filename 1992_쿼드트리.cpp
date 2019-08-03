#include <iostream>

using namespace std;
const int MAX = 65;

int map[MAX][MAX];

void recursive(int cnt, int x, int y) {

    if(cnt == 1) {
        printf("%d", map[x][y]);
        return ;
    }

    bool isOne = true, isZero = true;
    for(int i = x; i < x + cnt; i++) {
        for(int j = y; j < y + cnt; j++) {
            if(map[i][j]) isZero = false;
            else isOne = false;
        }
    }

    if(isOne) {
        printf("1");
    } else if(isZero) {
        printf("0");
    } else {
        printf("(");
        // 왼쪽 위
        recursive(cnt/2, x, y);
        // 오른쪽 위
        recursive(cnt/2, x, y + cnt/2);
        // 왼쪽 아래
        recursive(cnt/2, x + cnt/2, y);
        // 오른쪽 아래
        recursive(cnt/2, x + cnt/2, y + cnt/2);
        printf(")");
    }

}

int main() {

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    recursive(n, 0, 0);
    printf("\n");

    return 0;
}