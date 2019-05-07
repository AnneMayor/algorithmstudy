#include <iostream>
#define MAX 10

using namespace std;

int map[MAX][MAX];

int main() {

    int T;
    scanf("%d", &T);
    
    for(int t = 1; t <= T; t++) {

        int n;
        scanf("%d", &n);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                map[i][j] = -1;
            }
        }

        int endX = n-1;
        int endY = n-1;
        int startX = 0;
        int startY = 0;
        int num = 1;

        while(1) {

            // 오른쪽
            for(int y = startY; y <= endY; y++) {
                if(map[startX][y] != -1) continue;
                map[startX][y] = num++;
            }
            
            startX++;

            if(startX >= n) break;

            // 아래
            for(int x = startX; x <= endX; x++) {
                if(map[x][endY] != -1) continue;
                map[x][endY] = num++;
            }

            endY--;

            if(endY < 0) break;

            // 왼쪽
            for(int y = endY; y >= startY; y--) {
                if(map[endX][y] != -1) continue;
                map[endX][y] = num++;
            }

            endX--;

            if(endX < 0) break;

            // 위

            for(int x = endX; x >= startX; x--) {
                if(map[x][startY] != -1) continue;
                map[x][startY] = num++;
            }

            startY++;

            if(startY >= n) break;

        }

        printf("#%d\n", t);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }

    }

    return 0;
}