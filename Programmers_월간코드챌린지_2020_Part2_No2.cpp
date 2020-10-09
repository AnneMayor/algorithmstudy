#include <bits/stdc++.h>

using namespace std;

const int MAX = 70;

int nums[MAX][MAX];

int ans[2];

void quadTree(int x, int y, int size) {

    if(size == 1) {
        ans[nums[x][y]]++;
        return ;
    }

    bool isAllOne = true, isAllZero = true;
    for(int i = x; i < x + size; i++) {
        for(int j = y; j < y + size; j++) {
            if(nums[i][j]) isAllZero = false;
            else isAllOne = false;
        }
    }

    if(isAllOne) ans[1]++;
    else if(isAllZero) ans[0]++;
    else {
        size /= 2;
        // left up
        quadTree(x, y, size);
        // right up
        quadTree(x, y+size, size);
        // left down
        quadTree(x+size, y, size);
        // right down
        quadTree(x+size, y+size, size);
    }

    return ;
}

int main(void) {

    int n;
    scanf("%d", &n);

    memset(ans, 0, sizeof(ans));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%1d", &nums[i][j]);
        }
    }

    quadTree(0, 0, n);

    printf("%d %d\n", ans[0], ans[1]);

    return 0;
}