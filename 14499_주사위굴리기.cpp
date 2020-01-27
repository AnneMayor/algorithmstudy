#include <iostream>

using namespace std;

const int MAX = 25;
int map[MAX][MAX];

int n, m, k;
int dx, dy;
struct Dice {
    int top;
    int bottom;
    int left;
    int right;
    int front;
    int back;

    Dice() : top(0), bottom(0), left(0), right(0), front(0), back(0) {}

};

void move(Dice &d, int x, int y, int command) {

    Dice newDice;
    // 1: 오른쪽 / 2: 왼쪽 / 3: 위 / 4: 아래
    switch (command)
    {
        case 1:
        if(map[x][y] == 0) {
            map[x][y] = d.right;
            newDice.right = d.top;
            newDice.bottom = d.right;
            newDice.top = d.left;
            newDice.left = d.bottom;
            newDice.front = d.front;
            newDice.back = d.back;
        } else {
            newDice.bottom = map[x][y];
            map[x][y] = 0;
            newDice.right = d.top;
            newDice.top = d.left;
            newDice.left = d.bottom;
            newDice.front = d.front;
            newDice.back = d.back;
        }
        break;

        case 2:
        if(map[x][y] == 0) {
            map[x][y] = d.left;
            newDice.left = d.top;
            newDice.bottom = d.left;
            newDice.top = d.right;
            newDice.right = d.bottom;
            newDice.front = d.front;
            newDice.back = d.back;
        } else {
            newDice.bottom = map[x][y];
            map[x][y] = 0;
            newDice.left = d.top;
            newDice.top = d.right;
            newDice.right = d.bottom;
            newDice.front = d.front;
            newDice.back = d.back;
        }
        break;

        case 3:
        if(map[x][y] == 0) {
            map[x][y] = d.back;
            newDice.top = d.front;
            newDice.back = d.top;
            newDice.bottom = d.back;
            newDice.front = d.bottom;
            newDice.left = d.left;
            newDice.right = d.right;
        } else {
            newDice.bottom = map[x][y];
            map[x][y] = 0;
            newDice.top = d.front;
            newDice.back = d.top;
            newDice.front = d.bottom;
            newDice.left = d.left;
            newDice.right = d.right;
        }
        break;

        case 4:
        if(map[x][y] == 0) {
            map[x][y] = d.front;
            newDice.top = d.back;
            newDice.back = d.bottom;
            newDice.bottom = d.front;
            newDice.front = d.top;
            newDice.left = d.left;
            newDice.right = d.right;
        } else {
            newDice.bottom = map[x][y];
            map[x][y] = 0;
            newDice.top = d.back;
            newDice.back = d.bottom;
            newDice.front = d.top;
            newDice.left = d.left;
            newDice.right = d.right;
        }
        break;
    }

    // dice reset
    d.top = newDice.top;
    d.bottom = newDice.bottom;
    d.left = newDice.left;
    d.right = newDice.right;
    d.front = newDice.front;
    d.back = newDice.back;
}

void moveDice(Dice & d, int command) {

    int nx, ny;
    bool flag = false;

    // 1: 오른쪽 / 2: 왼쪽 / 3: 위 / 4: 아래
    switch (command)
    {
    case 1:
    nx = dx;
    ny = dy+1;
    if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
        flag = true;
        break;
    }
    move(d, nx, ny, command);
        break;
    case 2:
    nx = dx;
    ny = dy-1;
    if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
        flag = true;
        break;
    }
    move(d, nx, ny, command);
        break;

    case 3:
    nx = dx-1;
    ny = dy;
    if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
        flag = true;
        break;
    }
    move(d, nx, ny, command);
        break;

    case 4:
    nx = dx+1;
    ny = dy;
    if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
        flag = true;
        break;
    }
    move(d, nx, ny, command);
        break;
    }

    if(!flag) {
        dx = nx;
        dy = ny;
        printf("%d\n", d.top);
    }

    return;
}

int main() {

    scanf("%d %d %d %d %d", &n, &m, &dx, &dy, &k);

    for(int x = 0; x < n; x++) {
        for(int y = 0; y < m; y++) {
            scanf("%d", &map[x][y]);
        }
    }

    Dice d;
    for(int i = 0 ; i < k; i++) {
        int command;
        scanf("%d", &command);
        moveDice(d, command);
    }

    return 0;
}