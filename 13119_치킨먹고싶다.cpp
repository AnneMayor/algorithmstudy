#include <iostream>

using namespace std;

int p,m,f,c;

int main() {

    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d %d %d", &p, &m, &f, &c);

        int sangon, doyoung;
        doyoung = sangon = m/p*c/f;
        int tmp = m/p*c;
        if(tmp - f > 0) sangon = ((tmp-f) / (f-c))+1;
        printf("%d\n", sangon - doyoung);
    }

    return 0;
}