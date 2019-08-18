#include <iostream>

using namespace std;

int n;
int nums[12];
int sign[4];
long long int Max = -3000000000, Min = 3000000000;

void solve(int num, int len) {
    
    if(len >= n) {

        if(Min > num) {
            Min = num;
        }

        if(Max < num) {
            Max = num;
        }

        return;
    }


        int nNum;

        // 덧셈
        if(sign[0] > 0) {
            nNum = num + nums[len];
            sign[0] -= 1;
            solve(nNum, len+1);
            sign[0] += 1;
        }

        // 뺄셈
        if(sign[1] > 0) {
            nNum = num - nums[len];
            sign[1] -= 1;
            solve(nNum, len+1);
            sign[1] += 1;
        }

        // 곱셈
        if(sign[2] > 0) {
            nNum = num * nums[len];
            sign[2] -= 1;
            solve(nNum, len+1);
            sign[2] += 1;
        }

        // 나눗셈
        if(sign[3] > 0) {
            if(num < 0) {
                // 여기 체크!
                nNum = -(abs(num) / nums[len]);
            } else {
                nNum = num / nums[len];
            }
            sign[3] -= 1;
            solve(nNum, len+1);
            sign[3] += 1;
        }

}

int main() {

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    for(int i = 0; i < 4; i++) {
        scanf("%d", &sign[i]);
    }

    solve(nums[0], 1);

    printf("%lld\n", Max);
    printf("%lld\n", Min);

    return 0;
}