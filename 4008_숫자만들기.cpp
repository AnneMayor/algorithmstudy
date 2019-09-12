#include <iostream>

using namespace std;
const int MAX = 25;

int cntOfSign[MAX];
int nums[MAX];

int n;
int ansMx, ansMi;

void dfs(int val, int idx) {

    if(idx >= n) {
        if(ansMx < val) ansMx = val;
        if(ansMi > val) ansMi = val;

        return;
    }

    if(cntOfSign[0] > 0) {
        cntOfSign[0]--;
        val += nums[idx];
        dfs(val, idx+1);
        val -= nums[idx];
        cntOfSign[0]++;
    }
    
    if(cntOfSign[1] > 0) {
        cntOfSign[1]--;
        val -= nums[idx];
        dfs(val, idx+1);
        val += nums[idx];
        cntOfSign[1]++;
    }
    
    if(cntOfSign[2] > 0) {
        cntOfSign[2]--;
        val *= nums[idx];
        dfs(val, idx+1);
        val /= nums[idx];
        cntOfSign[2]++;
    }
    
    if(cntOfSign[3] > 0) {
        cntOfSign[3]--;
        val /= nums[idx];
        dfs(val, idx+1);
        val *= nums[idx];
        cntOfSign[3]++;
    }

    return;

}

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        
        scanf("%d", &n);
        ansMx = -1e9;
        ansMi = 1e9;

        for(int i = 0; i < 4; i++) {
            scanf("%d", &cntOfSign[i]);
        }

        for(int i = 0; i < n; i++) {
            scanf("%d", &nums[i]);
        }

        dfs(nums[0], 1);

        printf("#%d %d\n", tc, ansMx-ansMi);
    }


    return 0;
}