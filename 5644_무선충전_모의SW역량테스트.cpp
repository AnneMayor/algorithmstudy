#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;
const int MAX = 105;

struct Battery {
    int x, y;
    int c;
    int p;
    int used;
};

int dx[] = {0, -1, 0, 1, 0};
int dy[] = {0, 0, 1, 0, -1};

int routeA[MAX];
int routeB[MAX];
vector<Battery> bcList;
int userABattery , userBBattery;
int curAX, curAY;
int curBX, curBY;
int ret;

int input() {
    int m, a;
    scanf("%d %d", &m, &a);

    for(int i = 0; i < m; i++) {
        scanf("%d", &routeA[i]);
    }

    for(int i = 0; i < m; i++) {
        scanf("%d", &routeB[i]);
    }

    bcList.clear();
    for(int i = 0; i < a; i++) {
        int x, y, c, p;
        scanf("%d %d %d %d", &x, &y, &c, &p);
        Battery b;
        b.x = y-1;
        b.y = x-1;
        b.c = c;
        b.p = p;
        b.used = 0;
        bcList.push_back(b);
    }

    return m;
}

void move(int dirA, int dirB) {

    curAX += dx[dirA];
    curAY += dy[dirA];

    curBX += dx[dirB];
    curBY += dy[dirB];

    return ;
}

bool checkDistance(int user, int numOfBattery) {
    bool ret;

    int dA = abs(bcList[numOfBattery].x-curAX) + abs(bcList[numOfBattery].y-curAY);
    int dB = abs(bcList[numOfBattery].x-curBX) + abs(bcList[numOfBattery].y-curBY);
    switch (user)
    {
    case 0:
    if(dA <= bcList[numOfBattery].c) ret = true;
    else ret = false;
        break;

    case 1:
    if(dB <= bcList[numOfBattery].c) ret = true;
    else ret = false;
        break;
    }

    return ret;
}

void checkAndDecide(int cntOfUser, int total) {

    if(cntOfUser >= 2) {
        ret = max(ret, total);
        return ;
    }

    for(int i = 0; i < bcList.size(); i++) {
        if(!bcList[i].used && checkDistance(cntOfUser, i)) {
            bcList[i].used = 1;
            checkAndDecide(cntOfUser+1, total+bcList[i].p);
            bcList[i].used = 0;
        }
    }

    checkAndDecide(cntOfUser+1, total);
    
    return ;
}

int count() {
    ret = 0;
    checkAndDecide(0, 0);
    return ret;
}

int main() {

    int T;
    scanf("%d", &T);
    for(int tc = 1; tc <= T; tc++) {
        
        int m = input();

        userABattery = 0, userBBattery = 0;
        curAX = 0, curAY = 0;
        curBX = 9, curBY = 9;

        int time = -1;
        int ans = 0;
        while (time < m)
        {
            if(time >= 0) move(routeA[time], routeB[time]);
            ans += count();
            time++;
        }
        
        printf("#%d %d\n", tc, ans);

    }

    return 0;
}