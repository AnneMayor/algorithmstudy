#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 5005;

char tmpNum[MAX];
int nums[MAX];
int d[MAX];

int main() {

    scanf("%s", tmpNum);

    int len = strlen(tmpNum);

    for(int i = 1; i <= len; i++) {
        nums[i] = tmpNum[i-1] - '0';
    }

    if(len == 1 && tmpNum[0] == '0') {
        printf("0\n");
        return 0;
    }

    d[0] = 1;
    for(int i = 1; i <= len; i++) {

        if(nums[i] != 0) {
            d[i] = (d[i-1] + d[i]) % 1000000;
        }

        int num = nums[i-1]*10 + nums[i];

        if(num >= 10 && num <= 26) {
            d[i] = (d[i-2] + d[i]) % 1000000;
        }

    }

    printf("%d\n", d[len]);

    return 0;
}