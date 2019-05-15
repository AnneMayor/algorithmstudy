#include <iostream>
#include <string>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);

    for(int t = 1; t <= T; t++) {

        int n;
        string num;
        cin.tie(NULL);
        cin >> n >> num;

        long long int total = 0;
        int len = num.length();
        for(int i = 0; i < len; i++) {
            total += num.at(i) - '0';
        }

        int ans = total % (n-1);

        printf("#%d %d\n", t, ans);

    }

    return 0;
}