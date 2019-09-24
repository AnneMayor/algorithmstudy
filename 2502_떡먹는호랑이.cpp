#include <iostream>
#include <vector>

using namespace std;
const int MAX = 35;

int fiboDay(int day) {
    if(day <= 2) return 1;
    return fiboDay(day-2) + fiboDay(day-1);
}

int main() {

    int d, k;
    scanf("%d %d", &d, &k);

    int multA = fiboDay(d-2);
    int multB = fiboDay(d-1);

    int ansA = -1, ansB = -1;
    for(int i = 1; i <= k/2; i++) {
        int total = k;
        total -= multA*i;
        if(total%multB == 0) {
            ansA = i;
            ansB = total/multB;
            break;
        }
    }

    printf("%d\n%d\n", ansA, ansB);

    return 0;
}