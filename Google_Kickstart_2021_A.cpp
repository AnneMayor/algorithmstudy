#include <iostream>

using namespace std;

int main(void) {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        long long n, d, c, m;
        scanf("%lld %lld %lld %lld", &n, &d, &c, &m);
        char s[n+1];
        scanf("%s", s);

        int numOfDogs = 0, numOfCats = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'D') {
                numOfDogs++;
            } else if(s[i] == 'C') {
                numOfCats++;
            }
        }

        for(int i = 0; i < n; i++) {
            if(s[i] == 'D') {
                if(d <= 0) break;
                c += m;
                numOfDogs--;
                d--;
            } else if(s[i] == 'C') {
                if(c <= 0) break;
                numOfCats--;
                c--;
            }
        }

        if(numOfDogs <= 0) {
            printf("Case #%d: YES\n", tc);
        } else {
            printf("Case #%d: NO\n", tc);
        }
    }

    return 0;
}