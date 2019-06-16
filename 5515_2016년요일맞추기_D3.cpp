#include <iostream>

using namespace std;

int monthDay[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int m, d;
        int ans = 4;
        scanf("%d %d", &m, &d);

        int day = 0;
        for(int i = 0; i < m-1; i++) {
            day += monthDay[i];
        }

        day += d-1;

        ans += (day%7);

        printf("#%d %d\n", tc, ans%7);
        
    } 

    return 0;
}