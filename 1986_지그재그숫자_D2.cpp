#include <iostream>

using namespace std;

int main() {

    int T;
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    for(int t = 1; t <= T; t++) {
        int n;
        cin >> n;

        int ans = 0;

        for(int num = 1; num <= n; num++) {
            if(num % 2 == 0) {
                ans -= num;
            } else {
                ans += num;
            }
        }

        cout << "#" << t << " " << ans << endl;
    }

    return 0;
}