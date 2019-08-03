#include <iostream>
#include <cmath>

using namespace std;

int n, r, c;
long long ans;

void recursive(int cnt, int x, int y) {

    if(x == r && y == c) {
        printf("%lld\n", ans);
        return ;
    }

    if(r < x+cnt && r >= x && c < y+cnt && c >= y) {
        // 왼쪽 위
        recursive(cnt/2, x, y);
        // 오른쪽 위
        recursive(cnt/2, x, y + cnt/2);
        // 왼쪽 아래
        recursive(cnt/2, x+cnt/2, y);
        // 오른쪽 아래
        recursive(cnt/2, x+cnt/2, y+cnt/2);
    } else {
        ans += cnt*cnt;
    }

}

int main() {
    scanf("%d %d %d", &n, &r, &c);
    ans = 0;
    int size = (int) pow(2, n);
    recursive(size, 0, 0);
    return 0;
}