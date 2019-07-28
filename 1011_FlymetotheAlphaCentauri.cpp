#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {

        long long start, end;
        scanf("%lld %lld", &start, &end);

        long long jump = 1;
        while(jump*jump < end-start) {
            jump++;
        }

        // cout << "jump: " << jump << endl;

        long long remain = (end-start) - (jump*jump);
        long long ans = (long long) ceil(remain/jump);
        ans += 2*jump - 1;
        // cout << "ans: " << ans << endl;

        printf("%lld\n", ans);
        
    }

    return 0;
}