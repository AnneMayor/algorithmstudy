#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 1e6;
bool isSqure[MAX];

int main() {

    long long min, max;
    scanf("%lld %lld", &min, &max);

    int cnt = 0;

    for(long long i = 2; i <= sqrt(max); i++) {
        long long start = min / (i*i);
        if(min % (i*i) != 0) start++;
        while (start*i*i <= max)
        {
            isSqure[start*i*i-min] = true;
            start++;
        }
    }

    long long ans = 0;
    for(int i = 0; i <= max-min; i++) {
        if(!isSqure[i]) ans++;
    }

    printf("%lld\n", ans);

    return 0;
}