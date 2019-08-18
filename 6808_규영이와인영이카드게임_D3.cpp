#include <iostream>
#include <string.h>

using namespace std;

int nums[9];
bool isChecked[20];
int exp[9];
int win;

void findAns(int cnt, int totalI, int totalG) {
    if(cnt >= 9) {
        // cout << "규영: " << totalG << "/ 인영: " << totalI << endl;
        if(totalG > totalI) win++;
        totalG = 0;
        totalI = 0;
        return;
    }

    for(int i = 0; i < 9; i++) {
        if(!isChecked[nums[i]]) {
            isChecked[nums[i]] = true;
            if(exp[cnt] > nums[i]) totalG += exp[cnt] + nums[i];
            else totalI += exp[cnt] + nums[i];
            findAns(cnt+1, totalI, totalG);
            isChecked[nums[i]] = false;
            if(exp[cnt] > nums[i]) totalG -= exp[cnt] + nums[i];
            else totalI -= exp[cnt] + nums[i];
        }
    }
}

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {

        memset(isChecked, false, sizeof(isChecked));

        for(int i = 0; i < 9; i++) {
            scanf("%d", &exp[i]);
            isChecked[exp[i]] = true;
        }

        int idx = 0;
        for(int i = 1; i <= 18; i++) {
            if(!isChecked[i]) nums[idx++] = i;
        }

        // for(int i = 0; i < 9; i++) {
        //     cout << exp[i] << " " << nums[i] << endl;
        // }

        win = 0;
        int totalI = 0;
        int totalG = 0;

        findAns(0, totalI, totalG);

        int total = 9*8*7*6*5*4*3*2*1;

        printf("#%d %d %d\n", tc, win, total-win);
    }


    return 0;
}