#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;
const int MAX = 1000005;

bool isPrime[MAX];

int main() {

    memset(isPrime, true, sizeof(isPrime));

    for(int i = 2; i <= sqrt(1000000); i++) {
        if(!isPrime[i]) continue;
        for(int j = i+i; j <= 1000000; j+=i) {
            isPrime[j] = false;
        } 
    }

    for(int i = 2; i <= 1000000; i++) {
        if(isPrime[i]) printf("%d ", i);
    }
    printf("\n");

    return 0;
}