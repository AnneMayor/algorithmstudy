#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 27;

bool isCheckedAlpha[MAX];
char alphaMap[MAX][MAX];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int ans;
int ck = 0;

void dfs(int r, int c, int step, int maxR, int maxC) {

    ck++;
    if(ans < step) ans = step;

    if(ans == 26 || ck > 1e5) return ;

    for(int i = 0; i < 4; i++) {
        int nr = r + dx[i];
        int nc = c + dy[i];

        if(nr < 0 || nc < 0 || nr >= maxR || nc >= maxC) continue;
        
        char alphabet = alphaMap[nr][nc];
        if(!isCheckedAlpha[alphabet-'A']) {
            isCheckedAlpha[alphabet-'A'] = true;
            dfs(nr, nc, step+1, maxR, maxC);
            isCheckedAlpha[alphabet-'A'] = false;
        }
    }

    return ;
}

int main() {

    int r, c;
    scanf("%d %d", &r, &c);
    ans = 0;

    memset(isCheckedAlpha, false, sizeof(isCheckedAlpha));
    
    for(int i = 0; i < r; i++) {
        scanf("%s", alphaMap[i]);
    }

    isCheckedAlpha[alphaMap[0][0]-'A'] = true;
    dfs(0, 0, 1, r, c);

    printf("%d\n", ans);

    return 0;
}