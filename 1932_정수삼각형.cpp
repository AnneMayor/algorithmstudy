#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
const int MAX = 505;

int nums[MAX][MAX];
int d[MAX][MAX];

int main() {

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            scanf("%d", &nums[i][j]);
        }
    }

    memset(d, 0, sizeof(d));
    d[0][0] = nums[0][0];

    for(int i = 1; i < n; i++) {
        d[i][0] = d[i-1][0] + nums[i][0];
        for(int j = 1; j < i; j++) {
            d[i][j] = max(d[i-1][j-1], d[i-1][j]) + nums[i][j];
        }
        d[i][i] = d[i-1][i-1] + nums[i][i];
    }
    
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < n; j++) {
    //         cout << d[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int ans = -1;
    for(int i = 0; i < n; i++) {
        if(ans < d[n-1][i]) ans = d[n-1][i];
    }

    printf("%d\n", ans);

    return 0;
}