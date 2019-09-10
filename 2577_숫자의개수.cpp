#include <iostream>
#include <cstring>

using namespace std;

int cntOfNums[10];

int main() {

    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);
    memset(cntOfNums, 0, sizeof(cntOfNums));

    long long total = a * b * c;

    while (total)
    {
        cntOfNums[total%10]++;
        total /= 10;
    }
    
    for(int i = 0; i < 10; i++) {
        printf("%d\n", cntOfNums[i]);
    }

    return 0;
}