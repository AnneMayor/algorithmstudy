#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 100;

bool isVisited[MAX][MAX];
double ans;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int dir[4];

void backtraking(int x, int y, int step, double percentage, int n) {

    if(step >= n) {
        ans += percentage;
        return ;
    }

    if(n > 14) return ;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= 100 || ny >= 100) continue;

        if(!isVisited[nx][ny]) {
            isVisited[nx][ny] = true;
            double p = dir[i]*1.0 / 100.0;
            backtraking(nx, ny, step+1, percentage*p, n);
            isVisited[nx][ny] = false;
        }
    }

    return ;

}

int main() {

    int n;
    scanf("%d", &n);

    for(int i = 0; i < 4; i++) {
        scanf("%d", &dir[i]);
    }

    memset(isVisited, false, sizeof(isVisited));

    // 로봇의 시작점: isVisited[50][50]
    isVisited[50][50] = true;

    ans = 0;
    backtraking(50, 50, 0, 1.0, n);

    printf("%.9lf\n", ans);

    return 0;
}