#include <iostream>
#include <string.h>

using namespace std;
const int MAX = 104;

char num[MAX];

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        scanf("%s", num);

        int lastDigit = strlen(num)-1;

        int n = num[lastDigit] - '0';
        printf("#%d ", tc);
        if(n % 2 == 0) {
            printf("Even\n");
        } else {
            printf("Odd\n");
        }
    }

    return 0;
}