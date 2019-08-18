#include <iostream>
#include <cmath>

using namespace std;
const int MAX = 1000;

int primes[MAX];
int n;
int ans;

int getPrimes() {
    int idx = 0;
    for(int i = 2; i <= 999; i++) {
        bool flag = true;
        for(int j = 1; j <= sqrt(i); j++) {
            if(j != 1 && i % j == 0) {
                flag = false;
                break;
            }
        }
        if(flag) primes[idx++] = i;
    }

    return idx;
}

void findAns(int idx, int pLen, int total, int cntOfPrimes) {
    if(cntOfPrimes >= 3) {
        if(total == n) {
            ans += 1;
        }
        return;
    }

    for(int i = idx; i < pLen; i++) {
        if(total+primes[i] > n) break;
        // cout << total << " / " << primes[i] << endl;
        findAns(i, pLen, total+primes[i], cntOfPrimes+1); 
    }
}

int main() {

    int T;
    scanf("%d", &T);

    // 범위 내에 해당하는 소수 구하기
    int pLen = getPrimes();
 
    for(int tc = 1; tc <= T; tc++) {
        scanf("%d", &n);

        ans = 0;

        for(int i = 0; i < pLen; i++) {
            if(primes[i] >= n) break;
            findAns(i, pLen, primes[i], 1);
        }

        printf("#%d %d\n", tc, ans);

    }

    return 0;
}