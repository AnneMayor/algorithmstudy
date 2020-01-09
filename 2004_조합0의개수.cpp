#include <iostream>
#include <cmath>

using namespace std;

int getFive(int num) {

    int ret = 0;

    for(long i = 5; num / i >= 1; i *= 5) {
        ret += num / i;
    }

    return ret;
}

int getTwo(int num) {

    int ret = 0;

    for(long i = 2; num / i >= 1; i *= 2) {
        ret += num / i;
    }

    return ret;
}

int main() {

    int n, m;
    scanf("%d %d", &n, &m);

    int fiveAns = 0, twoAns = 0;

    int fiveN = getFive(n);
    int fiveM = getFive(m);
    int fiveNM = getFive(n-m);

    int twoN = getTwo(n);
    int twoM = getTwo(m);
    int twoNM = getTwo(n-m);

    fiveAns = fiveN - (fiveM + fiveNM);
    twoAns = twoN - (twoM + twoNM);

    if(fiveAns < 0 || twoAns < 0) {
        printf("0\n");
    } else {
        printf("%d\n", min(fiveAns, twoAns));
    }

    return 0;
}