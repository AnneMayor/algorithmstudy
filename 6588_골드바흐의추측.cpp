#include <iostream>
#include <cmath>

using namespace std;
const int MAX = 1000005;

int primes[MAX];

bool isPrime(int num) {

    bool flag = true;

    for(int i = 2; i <= sqrt(num); i++) {
        if(num % i == 0) {
            flag = false;
            break;
        }
    }

    return flag;
}

int main() {

    // 소수 찾기(2~1000000)
    int idx = 0;
    for(int i = 2; i <= 1000000; i++) {
        bool flag = true;
        for(int j = 2; j <= sqrt(i); j++) {
            if(i % j == 0) {
                flag = false;
                break;
            }
        }
        if(flag) {
            primes[idx++] = i;
        }
    }

    while (true)
    {
        int n;
        scanf("%d", &n);

        if(n == 0) break;

        int idx = 0;
        int ans = 0;
        while(primes[idx] < n) {

            if(isPrime(n-primes[idx])) {
                ans = n-primes[idx];
                break;
            }

            idx++;
        }

        if(ans != 0) {
            printf("%d = %d + %d\n", n, primes[idx], ans);
        } else {
            printf("Goldbach's conjecture is wrong.\n");
        }
    }
    

    return 0;
}