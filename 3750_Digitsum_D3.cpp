#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 20;

char nums[MAX];
int ans;

void solve(int len, char str[]) {

    if(len < 2) {
        ans = str[0]-'0';
        return ;
    }

    int sum = 0;
    for(int i = 0; i < len; i++) {
        sum += str[i]-'0';
    }

    int idx = 0;
    while(sum != 0) {
        str[idx++] = sum%10 + '0';
        sum /= 10;
    }

    solve(idx, str);
    
}

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {

        scanf("%s", nums);
        int len = strlen(nums);

        ans = -1;
        solve(len, nums);

        printf("#%d %d\n", tc, ans);

    }

    return 0;
}