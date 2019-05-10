#include <iostream>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);

    for(int t = 1; t <= T; t++) {
        int p, q, r, s, w;
        scanf("%d %d %d %d %d", &p, &q, &r, &s, &w);
        int num1 = w*p;
        int num2 = q+ (w-r <= 0? 0 : w-r) * s;
        
        if(num1 > num2) {
            printf("#%d %d\n", t, num2);
        } else {
            printf("#%d %d\n", t, num1);
        }
    }
    return 0;
}