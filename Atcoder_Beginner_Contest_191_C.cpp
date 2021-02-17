#include <iostream>

using namespace std;

const int MAX = 15;
const char BLACK = '#';

int main(void) {

    char map[MAX][MAX];
    int h, w;
    scanf("%d %d", &h, &w);

    int c = 0, ans = 0;
    for(int i = 0; i < h; i++) {
        scanf("%s", map[i]);
    }

    for(int i = 0; i < h-1; i++) {
        for(int j = 0; j < w-1; j++) {
            c = 0;
            if(map[i][j] == BLACK) c++;
            if(map[i][j+1] == BLACK) c++;
            if(map[i+1][j] == BLACK) c++;
            if(map[i+1][j+1] == BLACK) c++;
            if(c == 1 || c == 3) ans++;
        }
    }

    printf("%d\n", ans);


    return 0;
}