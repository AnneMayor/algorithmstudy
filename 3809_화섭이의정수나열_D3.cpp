#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 1005;

bool isChecked[MAX];
int ans;

int isAllChecked(int flag) {
    switch (flag)
    {
    case 1:
    for(int i = 0 ; i < 10; i++) {
        if(!isChecked[i]) {
            flag = -1;
            ans = i;
            break;
        }
    }

    if(flag != -1) flag = 2;
        break;
    
    case 2:
    for(int i = 10; i < 100; i++) {
        if(!isChecked[i]) {
            flag = -1;
            ans = i;
            break;
        }
    }

    if(flag != -1) flag = 3;
        break;

    case 3:
    for(int i = 100; i < 1000; i++) {
        if(!isChecked[i]) {
            flag = -1;
            ans = i;
            break;
        }
    }

    if(flag != -1) flag = -1;
        break;
    }

    return flag;
}

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int n;
        scanf("%d", &n);

        ans = -1;

        memset(isChecked, false, sizeof(isChecked));

        int nums[n];
        for(int i = 0; i < n; i++) {
            scanf("%d", &nums[i]);
        }

        int flag = 1;
        while(flag != -1) {

            switch (flag)
            {
            case 1:
            for(int i = 0; i < n; i++) {
                if(!isChecked[nums[i]]) isChecked[nums[i]] = true;
            }
                break;

            case 2:
            for(int i = 0; i < n-1; i++) {
                int num = nums[i]*10 + nums[i+1];
                if(!isChecked[num]) isChecked[num] = true;
            }
                break;

            case 3:
            for(int i = 0; i < n-2; i++) {
                int num = nums[i]*100 + nums[i+1]*10 + nums[i+2];
                if(!isChecked[num]) isChecked[num] = true;
            }
                break;
            }

            flag = isAllChecked(flag);

            if(flag == -1) break;

        }

        // 3자리수일 적에 혹시나 답이 없는 케이스 있을 수 있음.
        printf("#%d %d\n", tc, ans);

    }


    return 0;
}