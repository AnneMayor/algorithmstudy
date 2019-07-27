// 꼭 다시 풀어봐야하는 문제(규칙찾기 연습문제)

#include <iostream>
#include <cstring>
#define ll long long

using namespace std;
const int MAX = 10;

ll cnt[MAX];
ll start, tmp;

void helpDigit(ll num) {

    while (num > 0)
    {
        cnt[num%10] += tmp;
        num /= 10;
    }

}

int main() {

    ll n;
    scanf("%lld", &n);

    memset(cnt, 0, sizeof(cnt));

    start = 1;
    tmp = 1;

    while(start <= n) {

        // 끝을 0으로 맞추기
        while(start % 10 != 0 && start <= n) {
            helpDigit(start);
            start++;
        }

        if(start > n) break;

        // 끝을 9로 맞추기
        while (n % 10 != 9 && start <= n)
        {
            helpDigit(n);
            n--;
        }

        ll ans = (n/10) - (start/10) +1;

        for(int i = 0; i < 10; i++) {
            cnt[i] += ans*tmp;
        }

        start /= 10;
        n /=10;
        tmp *= 10LL;
        
    }

    for(int i = 0; i < 10; i++) {
        printf("%lld ", cnt[i]);
    }
    printf("\n");

    return 0;
}