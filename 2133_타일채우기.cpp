#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 50;

int d[MAX];

int main() {

    int N;
    scanf("%d", &N);

    memset(d, 0, sizeof(0));

    if(N%2 == 1) {
        printf("0\n");
    } else {
        d[2] = 3;
        
        for(int i = 4; i <= N; i+=2) {
            d[i] += d[2]*d[i-2];
            for(int j = 4; j <= i; j+=2) {
                d[i] += 2*d[i-j];
            }
            d[i] += 2;
        }

        printf("%d\n", d[N]);
    }

    return 0;
}