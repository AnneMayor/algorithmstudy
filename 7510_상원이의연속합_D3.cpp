#include <iostream>

using namespace std;

int cnt;

void recursive(int num, int end, int total) {

    if(total > end) return;

    if(total == end) {
        cnt += 1;
        return;
    }

    num += 1;
    total += num;

    recursive(num, end, total);

}

int main() {

    int T;
    scanf("%d", &T);

    for(int t = 1; t <= T; t++) {
        int n;
        scanf("%d", &n);
        cnt = 1;

        int range =  n / 2;
        for(int i = 1; i <= range; i++) {
            recursive(i, n, i);
        }

        printf("#%d %d\n", t, cnt);
    }

    return 0;
}