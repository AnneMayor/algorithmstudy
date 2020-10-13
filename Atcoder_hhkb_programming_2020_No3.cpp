#include <bits/stdc++.h>

using namespace std;

int main(void) {

    int n;
    scanf("%d", &n);

    int nums[n+5];
    int isChecked[200005];
    memset(isChecked, 0, sizeof(isChecked));

    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int start = 0;
    for(int i = 0; i < n; i++) {
        isChecked[nums[i]] = 1;
        while (isChecked[start]) start++;
        printf("%d\n", start);
    }

    return 0;
}