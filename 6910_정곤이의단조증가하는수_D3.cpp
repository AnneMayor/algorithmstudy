#include <iostream>

using namespace std;
const int MAX = 1005;

int numList[MAX];
int n;
int ans;

bool isIncrementedNum(int num) {

    int flag = true;

    int lastDigit = num % 10;
    num /= 10;

    while (num > 0)
    {
        int tempDigit = num % 10;
        if(tempDigit > lastDigit) {
            flag = false;
            break;
        }
        lastDigit = tempDigit;
        num /= 10;
    }

    return flag;

}

void findAns(int idx, int total, int cntOfNums) {
    if(cntOfNums >= 2) {
        if(isIncrementedNum(total)) {
            if(ans < total) ans = total;
        }
        return ;
    }


    for(int i = idx+1; i < n; i++) {
        findAns(i, total*numList[i], cntOfNums+1);
    }
}

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        scanf("%d", &n);

        ans = -1;

        for(int i = 0; i < n; i++) {
            scanf("%d", &numList[i]);
        }

        for(int i = 0; i < n; i++) {
            findAns(i, numList[i], 1);
        }

        printf("#%d %d\n", tc, ans);
        
    }

    return 0;
}