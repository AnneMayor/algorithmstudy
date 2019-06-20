#include <iostream>
#include <string.h>

using namespace std;
const int MAX = 1005;

char numOfPeople[MAX];

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        scanf("%s", numOfPeople);

        int len = strlen(numOfPeople);

        int cnt = numOfPeople[0]-'0';
        int ans = 0;
        for(int i = 1; i < len; i++) {
            // cout << "i: " << i <<  " / cnt: " << cnt << " / ans: " << ans << endl;
            if(cnt + ans >= i) {
                cnt += numOfPeople[i]-'0';
            } else {
                // cout << "here" << endl;
                ans += 1;
                cnt += numOfPeople[i]-'0';
            }
        }

        printf("#%d %d\n", tc, ans);
    }

    return 0;
}