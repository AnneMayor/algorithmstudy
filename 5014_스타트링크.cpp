#include <iostream>
#define MAX 3000000

using namespace std;

bool isChecked[MAX];
int ans = -1;
int f, s, g, u, d;

void dfs(int cnt, int floor) {

    if(floor == g) {
        if(ans == -1) {
            ans = cnt;
        } else {
            if(ans > cnt) {
                ans = cnt;
            }
        }
        return ;
    }

    if(floor <= 0 || floor > f) {
        return ;
    }

    isChecked[s] = true;

    // U층 위
    if(!isChecked[floor+u]) {
        isChecked[floor+u] = true;
        dfs(cnt+1, floor+u);
        isChecked[floor+u] = false;
    }

    // D층 아래
    if(!isChecked[floor-d]) {
        isChecked[floor-d] = true;
        dfs(cnt+1, floor-d);
        isChecked[floor+u] = false;
    }
    
}

int main() {

    scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);

    for(int i = 0; i <= f; i++) {
        isChecked[i] = false;
    }

    dfs(0, s);

    if(ans == -1) {
        printf("use the stairs\n");
    } else {
        printf("%d\n", ans);
    }

    return 0;
}