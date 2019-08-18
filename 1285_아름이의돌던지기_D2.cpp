#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);

    for(int t = 1; t <= T; t++) {
        
        int n;
        scanf("%d", &n);

        int min[n];
        int people[n];

        for(int i = 0; i < n; i++) {
            scanf("%d", &people[i]);
        }

        int diff = 200000;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            int temp = abs(people[i] - 0);
            if(diff > temp) {
                cnt = 1;
                diff = temp;
            } else if(diff == temp) {
                cnt += 1;
            }
        }

        printf("#%d %d %d\n", t, diff, cnt);

    }
    return 0;
}