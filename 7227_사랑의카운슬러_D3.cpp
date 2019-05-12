// 핵심포인트: 벡터는 두 좌표 사이에서 구하는 값을 의미한다!
// 벡터에 대한 개념 파악이 선행되어야할 문제.

#include <iostream>

using namespace std;

const int MAX = 25;

bool haveTeam[MAX];
int mx[MAX], my[MAX];
long long int ans;

void dfs(int pos, int cnt, int size) {

    if(cnt == size/2) {
        long long int x = 0;
        long long int y = 0;
        long long int sum = 0;
        for(int i = 0; i < size; i++) {
            if(haveTeam[i]) {
                x += mx[i];
                y += my[i];
            } else {
                x -= mx[i];
                y -= my[i];
            }
        }

        sum = x*x + y*y;
        if(ans == -1) ans = sum;
        else if(ans > sum) {
            ans = sum;
        }
        return;
    }

    for(int i = pos+1; i < size; i++) {
        if(!haveTeam[i]) {
            haveTeam[i] = true;
            dfs(i, cnt+1, size);
            haveTeam[i] = false;
        }
    }

}

int main() {

    int T;
    scanf("%d", &T);
    
    for(int t = 1; t <= T; t++) {
        int n;
        scanf("%d", &n);

        ans = -1;

        for(int i = 0; i < n; i++) {
            scanf("%d %d", &mx[i], &my[i]);
        }

        dfs(-1, 0, n);

        printf("#%d %lld\n", t, ans);
        
    }

    return 0;
}