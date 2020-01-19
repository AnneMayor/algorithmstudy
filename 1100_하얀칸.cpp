#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

// 0: White , 1: Black

struct BoardColor {
    int x;
    int y;
    int color;
};

const int MAX = 10;

queue<BoardColor> q;
bool isChecked[MAX][MAX];
int colorFlag[MAX][MAX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfsSearch(int x, int y, int color) {
    colorFlag[x][y] = color;
    isChecked[x][y] = 0;

    BoardColor bc;
    bc.x = x;
    bc.y = y;
    bc.color = color;

    q.push(bc);

    while (!q.empty())
    {
        bc = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = bc.x + dx[i];
            int ny = bc.y + dy[i];

            if(nx < 0 || ny < 0 || nx >= 8 || ny >= 8) continue;

            if(!isChecked[nx][ny]) {
                isChecked[nx][ny] = true;
                if(colorFlag[bc.x][bc.y] == 0) {
                    colorFlag[nx][ny] = 1;
                } else {
                    colorFlag[nx][ny] = 0;
                }

                bc.x = nx;
                bc.y = ny;
                bc.color = colorFlag[nx][ny];
                q.push(bc);
            }
        }
    }

    return ;
}

int main() {

    char board[MAX][MAX];

    for(int i = 0; i < 8; i++) {
        scanf("%s", board[i]);
    }

    memset(isChecked, false, sizeof(isChecked));

    bfsSearch(0, 0, 0);

    int ret = 0;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(board[i][j] == 'F' && colorFlag[i][j] == 0) ret++;
        }
    }

    printf("%d\n", ret);

    return 0;
}