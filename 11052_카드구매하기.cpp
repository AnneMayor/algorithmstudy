#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 1005;

int nums[MAX];
int d[MAX];

int main() {

    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        scanf("%d", &nums[i]);
        d[i] = nums[i];
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            d[i] = max(d[i], d[i-j]+d[j]);
        }
    }

    // for(int i = 1; i <= n; i++) {
    //     cout << "d: " << d[i] << endl;
    // }

    printf("%d\n", d[n]);

    return 0;
}