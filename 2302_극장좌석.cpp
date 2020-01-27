#include <iostream>

using namespace std;
const int MAX = 45;

int main() {

    int n;
    scanf("%d", &n);

    int *arrNum;
    arrNum = (int *) calloc(MAX, sizeof(int));

    int m;
    scanf("%d", &m);

    for(int i = 0; i < m; i++) {
        int val;
        scanf("%d", &val);
        *(arrNum+val) = 1;
    }

    int *cntOfCase;
    cntOfCase = (int *) calloc(n+1, sizeof(int));
    *(cntOfCase) = 1;
    *(cntOfCase+1) = 1;
    *(cntOfCase+2) = 2;
    for(int i = 3; i <= n; i++) {
        *(cntOfCase+i) = *(cntOfCase+(i-1)) + *(cntOfCase+(i-2));
    }

    long long ret = 1;
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(*(arrNum+i) == 1) {
            ret *= *(cntOfCase+cnt);
            cnt = 0;
        } else {
            cnt++;
        }
    }
    
    ret *= *(cntOfCase+cnt);

    printf("%lld\n", ret);

    return 0;
}