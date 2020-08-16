#include <bits/stdc++.h>

using namespace std;
const int MAX = 105;

int cntOfNum[MAX];

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int n;
        scanf("%d", &n);

        memset(cntOfNum, 0, sizeof(cntOfNum));

        for(int i = 0; i < n; i++) {
            int num;
            scanf("%d", & num);
            if(cntOfNum[num] == 0) {
                cntOfNum[num]++;
            }
        }

        bool flag = true;
        int startIdx = -1;
        for(int i = 1; i <= 100; i++) {
            if(cntOfNum[i]) {
                startIdx = i;
                break;
            }
        }

        int stopPoint = 0;
        for(int i = startIdx; i <= 100; i++) {
            if(!cntOfNum[i]) stopPoint++;
            else {
                if(stopPoint >= 1) {
                    flag = false;
                    break;
                }
            }
        }

        if(flag) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
        
    }

    return 0;
}