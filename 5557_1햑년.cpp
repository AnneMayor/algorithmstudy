#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 102;

int num[MAX];
long long d[MAX][MAX];

long long recursiveDp(int pos, int val, int n) {
        if (val < 0 || val >20)
               return 0;

        if (pos >= n - 2)
               return (val == num[n - 1]);

        long long &result = d[val][pos];
        if (result != -1)
               return result;

        result = 0;
        return result += (recursiveDp(pos + 1, val + num[pos + 1], n) + recursiveDp(pos + 1, val - num[pos + 1], n));
}

int main() {

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    memset(d, -1, sizeof(d));

    printf("%lld\n", recursiveDp(0, num[0], n));

    return 0;
}