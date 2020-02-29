#include <iostream>

using namespace std;
const int MAX = 1e3+5;

int ansX, ansY;
int robotX, robotY;
int map[MAX][MAX];
int curDir = 0;
bool flag;
int dir[] = {0, 1, 2, 3}; // 동 , 북, 서, 남

void moveStraight(int dist, int limit) {
    int tmpX, tmpY;
    switch (curDir)
    {
    case 0:
        // 동
        tmpX = robotX;
        tmpY = robotY + dist;
        if(tmpY > limit) {
            flag = true;
        }
        break;
    case 1:
        // 북
        tmpX = robotX - dist;
        tmpY = robotY;
        if(tmpX < 0) {
            flag = true;
        }
        break;
    case 2:
        // 서
        tmpX = robotX;
        tmpY = robotY - dist;
        if(tmpY < 0) {
            flag = true;
        }
        break;
    case 3:
        // 남
        tmpX = robotX + dist;
        tmpY = robotY;
        if(tmpX > limit) {
            flag = true;
        }
        break;
    }

    if(!flag) {
        robotX = tmpX;
        robotY = tmpY;
    }
}

void moveRobot(char command[4], int dist, int limit) {
    switch (command[0])
    {
    case 'M':
        moveStraight(dist, limit);
        break;
    case 'T':
        if(dist == 0) {
            // 왼쪽
            curDir = (curDir+1) % 4;
        } else {
            // 오른쪽
            curDir = (curDir+3) % 4;
        }
        break;
    }
}

int main() {

    int M, n;
    scanf("%d %d", &M, &n);
    robotX = M, robotY = 0;
    flag = false;

    for(int tc = 0; tc < n; tc++) {
        char command[6]; int distance;
        scanf("%s", command);
        scanf("%d", &distance);
        moveRobot(command, distance, M);
    }

    if(!flag) {
        ansX = robotX;
        ansY = robotY;
        printf("%d %d\n", ansY, M-ansX);
    } else {
        printf("-1\n");
    }

    return 0;
}