#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 1e6+5;

int d[MAX];

int main() {

    int n;
    scanf("%d", &n);

    d[1] = 0;
    d[2] = 1, d[3] = 1;
    for(int i = 4; i <= n; i++) {
        if(i % 2 == 0 && i % 3 == 0) {
            d[i] = min(d[i/3], min(d[i/2], d[i-1])) + 1;
        } else if(i % 2 == 0) {
            d[i] = min(d[i/2], d[i-1]) + 1;
        } else if(i % 3 == 0) {
            d[i] = min(d[i/3], d[i-1]) + 1;
        } else {
            d[i] = d[i-1] + 1;
        }
    }

    printf("%d\n", d[n]);

    return 0;
}