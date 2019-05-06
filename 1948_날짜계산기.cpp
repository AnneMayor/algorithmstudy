#include <iostream>

using namespace std;

int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {

    int T;
    scanf("%d", &T);

    for(int t = 1; t <= T; t++) {
        int m1, d1, m2, d2;
        scanf("%d %d %d %d", &m1, &d1, &m2, &d2);

        int ans = 0;

        if(m1 == m2) {
            ans = (d2-d1) + 1;
            printf("#%d %d\n", t, ans);
            continue;
        }

        ans += (month[m1] - d1) + 1;
        m1++;
        cout << ans << endl;
        while(m1 < m2) {
            ans += month[m1++];
            cout << ans << endl;
        }
        ans += d2;
        cout << ans << endl;

        printf("#%d %d\n", t, ans);
    }

    return 0;
}